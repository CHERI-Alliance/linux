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

.data
/* store the initial stack pointer here (with argv, envp, etc) */
VARIABLE(stack_from_kernel, 16)


.text
FUNCTION_START(_start)
	bl	__morello_init_globals

	/* get a capability to the variable. See VARIABLE macro for why */
	adrp	c0, :got:stack_from_kernel
	ldr	c0, [c0, :got_lo12:stack_from_kernel]
	/* save the initial kernel stack to a global variable */
	mov	c1, csp
	str	c1, [c0]

	/* call int main(void) */
	bl	main

	/* exit. Argument is in x0 already */
	mov	x8, #__NR_exit
	svc	#0

	/* and stay here in case nothing above exits */
	b	.
FUNCTION_END(_start)


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
