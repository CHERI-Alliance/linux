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
 *   valid (see __morello_init_globals() for more details)
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

#define TEMP_STACK_SIZE (1<<12)

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


.text
FUNCTION_START(_start)
	bl	__morello_init_globals

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

	/* call int main(void) */
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
