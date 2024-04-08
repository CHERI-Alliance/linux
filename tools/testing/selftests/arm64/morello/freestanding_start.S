/* SPDX-License-Identifier: GPL-2.0
 * Copyright (C) 2021  Arm Limited
 */

#include <asm/unistd.h>

#define FUNCTION_START(name)		\
	.global	name;			\
	.align	4;			\
	.type	name STT_FUNC;		\
	name:

#define FUNCTION_END(name)		\
	.size name, .-name

/*
 * (global) variables are tricky. The PCC is not meant to have write
 * permissions and global bounds. Therefore we can't directly use it (eg a
 * literal load) to get a good capability to read and write our variable.
 *
 * Instead we can construct an intermediary capability from the PCC to a place
 * it _does_ have access to which contains a capability that can access our
 * data. This place is the Global Offset Table (GOT) section. Whenever we refer
 * to a label through the GOT the assembler will output 2 more necessary things
 * besides the .space we specify:
 * - a space for a capability pointing to it (in the .got section)
 * - a capability relocation (in __cap_relocs section) to make the capability
 *   valid (see __morello_process_{cap,dynamic}_relocs() for more details)
 * We use
 *   adrp	c0, :got:name
 *   ldr	c0, [c0, :got_lo12:name]
 * to do that. The :got:/:got_lo12: split is an artefact of arm relocations in
 * general. They represent the higher/lower bits of the offset to the GOT from
 * the PCC respectively.
 */
#define VARIABLE(name, sz)		\
	.global	name;			\
	.size	name, sz;		\
	.align	4;			\
	.type	name STT_OBJECT;	\
	name:				\
	.space	sz, 0

#define TEMP_STACK_SIZE (1<<14)

/* See VARIABLE macro for why we do this */
.macro got_get_ptr name, reg
	adrp	\reg, :got:\name
	ldr	\reg, [\reg, :got_lo12:\name]
.endm

.macro get_temp_stack_base reg
	got_get_ptr temp_stack, \reg
	add	\reg, \reg, #TEMP_STACK_SIZE
	alignd	\reg, \reg, #4
.endm


.data
/* store the initial stack pointer here (with argv, envp, etc) */
VARIABLE(stack_from_kernel, 16)
VARIABLE(temp_stack, TEMP_STACK_SIZE)
/* this allows ASSERTs in nested functions (unlike kselftest) */
VARIABLE(__cur_test, 16)


.text
FUNCTION_START(_start)
	/* save x0, c1-c3 which has argc/argv/envp/auxv */
	mov	x20, x0
	mov	c21, c1
	mov	c22, c2
	mov	c23, c3

	/* call void __morello_process_cap_relocs(char *auxv) */
	mov	c0, c23
	bl	__morello_process_cap_relocs
	/* call void __morello_process_dynamic_relocs(char *auxv) */
	mov	c0, c23
	bl	__morello_process_dynamic_relocs

	/* save the initial kernel stack to a global variable */
	got_get_ptr stack_from_kernel, c0
	mov	c1, csp
	str	c1, [c0]

	/*
	 * use a (temporary) custom stack, until main is comfortable with the
	 * kernel one.  We can get away with this, as the relocation code will
	 * initialize our capability from a RW root one. Hide it behind a
	 * switch in case someone really doesn't want this
	 */
#ifndef NO_TEMP_STACK
	get_temp_stack_base c0
	mov	csp, c0
#endif

	/* call int main(int argc, char **argv, char **envp, char *auxv) */
	mov	x0, x20
	mov	c1, c21
	mov	c2, c22
	mov	c3, c23
	bl	main

	/* exit. Argument is in x0 already */
	mov	x8, #__NR_exit
	svc	#0

	/* and stay here in case nothing above exits */
	b	.
FUNCTION_END(_start)


/*
 * migrate any stack contents on the temporary stack and switch back to the
 * kernel provided one like a "normal" binary would
 */
FUNCTION_START(install_kernel_stack)
/* this is a noop if we skipped the initial swap */
#ifndef NO_TEMP_STACK
	/* r0 - scratch */
	/* r1, r2, r3 - kernel, user current, user base stack address */
	/* r4 - counter */

	/* load our stacks to begin migrating */
	got_get_ptr stack_from_kernel, c0
	ldr	c1, [c0]
	mov	c2, csp
	get_temp_stack_base c3

	/*
	 * capabilities are architecturally guaranteed to start on a 16-byte
	 * boundary, so we copy in 16-byte increments to preserve any set tags
	 * and migrate the stack contents. Pointers shouldn't break as the old
	 * stack will remain in place
	 */
1:
	/* calculate how many bytes we have left */
	subs	x4, x3, x2
	b.eq	2f
	/* 16-byte copy */
	ldr	c0, [c3, #-16]!
	str	c0, [c1, #-16]!
	b	1b
2:
	/* install the new stack */
	mov	csp, c1
#endif
	ret
FUNCTION_END(install_kernel_stack)


/*
 * This is not optimal code on purpose. Its goal is to be universal and to be
 * short. It is to be used only in the freestanding environment for easy
 * debugging. Will be replaced in the hosted environment.
 */
FUNCTION_START(__syscall)
	/*
	 * arrange the arguments as the kernel expects them. All arguments come
	 * in [c0-c8] so they can be used freely. Kernel still looks at x8 for
	 * syscall number
	 */
	mov	x8, x0
	mov	c0, c1
	mov	c1, c2
	mov	c2, c3
	mov	c3, c4
	mov	c4, c5
	mov	c5, c6
	/* zero c6 so we don't confuse debugging */
	mov	x6, #0

	/* return value in c0 */
	svc	#0
	ret
FUNCTION_END(__syscall)

/* Set of syscalls that might require special handling */

/*
 * int clone(int (*fn)(void *), void *stack, int flags, void *arg, ...
 *	     pid_t *parent_tid, void *tls, pid_t *child_tid  );
 */
FUNCTION_START(__clone)
	alignd	c1, c1,#7 /* stack alignment */
	mov	c9, c0
	mov	c10, c3

	/* Shuffle few regs .... */
	mov	c0, c2
	mov	c2, c4
	mov	c3, c5
	mov	c4, c6
	mov	x8, #__NR_clone
	svc	#0

	cbz	x0,1f
	ret
1:
	mov	c0, c10
	mov	c1, c9
	blr	c1
	mov	x8, #__NR_exit
	svc	#0
FUNCTION_END(__clone)

/*
 * Switching to Restrictive mode:
 * Sets the restricted registers (RDDC_EL0 & RCTPIDR_EL0 are initialized
 * based on their executive counterparts, RCSP_EL0 is set with provided
 * stack pointer) and uses branch with link(restricted) instruction to
 * provided entry point (capability) with requested set of permissions
 * being cleared (note: at lease Executive permission needs to be cleared
 * in order to actually switch to restrictive mode
 *
 * Note: This does not intend to provide a secure way of switching the modes
 * so there are no security countermeasures in place.
 *
 * void switch_to_restricted(uintcap_t addr, void * stack);
 * addr:  address to start execution in Restricted from
 * stack: stack pointer for Restricted
 */
FUNCTION_START(switch_to_restricted)
	sub	csp, csp, #80
	stp	c29,c30, [csp]

	/* Save current values for restricted registers */
	mrs	c3, rcsp_el0
	mrs	c4, rddc_el0
	stp	c3, c4, [csp, #32]
	mrs	c3, rctpidr_el0
	str	c3, [csp, #64]

	/* Setup regs for restricted mode */
	msr	rcsp_el0, c1

	mrs	c3, ddc
	msr	rddc_el0, c3
	msr	rctpidr_el0, czr

	/* Create restricted cap */
	mov	x3, #__ARM_CAP_PERMISSION_EXECUTIVE__
	clrperm	c0, c0, x3
	/*
	 * Function pointers are sealed so clrperm untagged c0 - rebuild a valid
	 * capability from PCC
	 */
	adr	c1, #0
	build	c0, c0, c1
	seal	c0, c0, rb
	/* Branch (restricted) */
	blrr	c0

	/* Done - restore restricted registers */
	ldr	c3, [csp, #64]
	msr	rctpidr_el0, c3
	ldp	c3, c4, [csp, #32]
	msr	rcsp_el0, c3
	msr	rddc_el0, c4

	ldp	c29, c30, [csp]
	add	csp, csp, #80

	ret	c30

FUNCTION_END(switch_to_restricted)
