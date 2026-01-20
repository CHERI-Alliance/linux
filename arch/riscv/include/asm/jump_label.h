/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2020 Emil Renner Berthing
 *
 * Based on arch/arm64/include/asm/jump_label.h
 */
#ifndef __ASM_JUMP_LABEL_H
#define __ASM_JUMP_LABEL_H

#ifndef __ASSEMBLER__

#include <linux/types.h>
#include <asm/asm.h>

#define HAVE_JUMP_LABEL_BATCH

#define JUMP_LABEL_NOP_SIZE 4

#define JUMP_TABLE_ENTRY(base, offset, branch, label)		\
	".pushsection	__jump_table, \"aw\"			\n\t"	\
	".align		" LGREG "				\n\t"	\
	".long		1b - ., " label " - .			\n\t"	\
	RISCV_PTRADDR " " base " + " offset " + " branch " - .	\n\t"	\
	".popsection						\n\t"

/* This macro is also expanded on the Rust side. */
#define ARCH_STATIC_BRANCH_ASM(base, offset, branch, label)	\
	"	.align		2			\n\t"	\
	"	.option push				\n\t"	\
	"	.option norelax				\n\t"	\
	"	.option norvc				\n\t"	\
	"1:	nop					\n\t"	\
	"	.option pop				\n\t"	\
	JUMP_TABLE_ENTRY(base, offset, branch, label)

/* base must be a global symbol, base+offset must point to a struct static_key */
static __always_inline bool arch_static_branch(void * const base,
					       const unsigned long offset,
					       const bool branch)
{
	asm goto(
		ARCH_STATIC_BRANCH_ASM("%0", "%1", "%2", "%l[label]")
		:  :  "S"(base), "i"(offset), "i"(branch) :  : label);

	return false;
label:
	return true;
}

#define ARCH_STATIC_BRANCH_JUMP_ASM(base, offset, branch, label)	\
	"	.align		2			\n\t"	\
	"	.option push				\n\t"	\
	"	.option norelax				\n\t"	\
	"	.option norvc				\n\t"	\
	"1:	j	" label "			\n\t"	\
	"	.option pop				\n\t"	\
	JUMP_TABLE_ENTRY(base, offset, branch, label)

/* see the requirements for parameters in arch_static_branch */
static __always_inline bool arch_static_branch_jump(void * const base,
						    const unsigned long offset,
						    const bool branch)
{
	asm goto(
		ARCH_STATIC_BRANCH_JUMP_ASM("%0", "%1", "%2", "%l[label]")
		:  :  "S"(base), "i"(offset), "i"(branch) :  : label);

	return false;
label:
	return true;
}

#endif  /* __ASSEMBLER__ */
#endif	/* __ASM_JUMP_LABEL_H */
