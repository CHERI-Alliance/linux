/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2015 Regents of the University of California
 */

#ifndef _ASM_RISCV_ASM_H
#define _ASM_RISCV_ASM_H

#include "asm/cherimap.h"

#ifdef __ASSEMBLY__
#define __ASM_STR(x)	x
#else
#define __ASM_STR(x)	#x
#endif

#if __riscv_xlen == 64
#define __REG_SEL(a, b)	__ASM_STR(a)
#elif __riscv_xlen == 32
#define __REG_SEL(a, b)	__ASM_STR(b)
#else
#error "Unexpected __riscv_xlen"
#endif

#define REG_L		__REG_SEL(ld, lw)
#define REG_S		__REG_SEL(sd, sw)
#define REG_SC		__REG_SEL(sc.d, sc.w)
#define REG_AMOSWAP_AQ	__REG_SEL(amoswap.d.aq, amoswap.w.aq)
#define REG_ASM		__REG_SEL(.dword, .word)
#define SZREG		__REG_SEL(8, 4)
#define LGREG		__REG_SEL(3, 2)
#define SRLI		__REG_SEL(srliw, srli)

#ifdef CONFIG_CHERI_KERNEL

#define CREG_L		__ASM_STR(lc)
#define CREG_S		__ASM_STR(sc)
#define CREG_ASM	__REG_SEL(.chericap, .dword)
#define CSZREG		__REG_SEL(16, 8)
#define CLGREG		__REG_SEL(4, 3)
#define PTRC		"C"

#else

#define CREG_L		REG_L
#define CREG_S		REG_S
#define CREG_ASM	REG_ASM
#define CSZREG		SZREG
#define CLGREG		LGREG
#define PTRC		"r"

#endif

#if __SIZEOF_POINTER__ == 16
#ifdef __ASSEMBLY__
#define RISCV_PTR		.chericap
#define RISCV_SZPTR		16
#define RISCV_LGPTR		4
#else
#define RISCV_PTR		".chericap"
#define RISCV_SZPTR		"16"
#define RISCV_LGPTR		"4"
#endif
#elif __SIZEOF_POINTER__ == 8
#ifdef __ASSEMBLY__
#define RISCV_PTR		.dword
#define RISCV_SZPTR		8
#define RISCV_LGPTR		3
#else
#define RISCV_PTR		".dword"
#define RISCV_SZPTR		"8"
#define RISCV_LGPTR		"3"
#endif
#elif __SIZEOF_POINTER__ == 4
#ifdef __ASSEMBLY__
#define RISCV_PTR		.word
#define RISCV_SZPTR		4
#define RISCV_LGPTR		2
#else
#define RISCV_PTR		".word"
#define RISCV_SZPTR		"4"
#define RISCV_LGPTR		"2"
#endif
#else
#error "Unexpected __SIZEOF_POINTER__"
#endif

#if (__SIZEOF_INT__ == 4)
#define RISCV_INT		__ASM_STR(.word)
#define RISCV_SZINT		__ASM_STR(4)
#define RISCV_LGINT		__ASM_STR(2)
#else
#error "Unexpected __SIZEOF_INT__"
#endif

#if (__SIZEOF_SHORT__ == 2)
#define RISCV_SHORT		__ASM_STR(.half)
#define RISCV_SZSHORT		__ASM_STR(2)
#define RISCV_LGSHORT		__ASM_STR(1)
#else
#error "Unexpected __SIZEOF_SHORT__"
#endif

#ifdef __ASSEMBLY__
#include <asm/asm-offsets.h>

/* Common assembly source macros */

/*
 * NOP sequence
 */
.macro	nops, num
	.rept	\num
	nop
	.endr
.endm

#ifdef CONFIG_SMP
#ifdef CONFIG_32BIT
#define PER_CPU_OFFSET_SHIFT 2
#else
#define PER_CPU_OFFSET_SHIFT 3
#endif

.macro asm_per_cpu dst sym tmp
	REG_L \tmp, TASK_TI_CPU_NUM(CREG(tp))
	slli  \tmp, \tmp, PER_CPU_OFFSET_SHIFT
#ifdef CONFIG_CHERI_KERNEL
	lgc   \dst, __per_cpu_offset
#else
	la    \dst, __per_cpu_offset
#endif
	add   \dst, \dst, \tmp
	/* tmp = __per_cpu_offset[our cpu] */
	REG_L \tmp, 0(\dst)
#ifdef CONFIG_CHERI_KERNEL
	/*
	 * Build the following result capability
	 *     address = address(sym) + __per_cpu_offset[our cpu]
	 *     permissions = permissions(sym)
	 *     len of valid range = len(sym)
	 *     base = address(result)
	 *
	 * Please note that the C implementation of this_cpu_ptr sets base =
	 * base(sym) + __per_cpu_offset[our cpu]. Doing this in assembler would
	 * require a second tmp register.
	 *
	 * For cheri, sym must be a capability. We have to use lgc to load
	 * sym's address and metadata. lgc is translated into auipcc + lc.
	 * llc CREG(\dst), \sym would be translated into auipcc + cadd,
	 * we'd get a capability with sym's address and pcc's metadata.
	 */
	lgc    \dst, \sym

	/*
	 * address(dst) = address(sym) + __per_cpu_offset[our cpu]
	 * This may clear the tag if the address is unrepresentable.
	 */
	cadd   \dst, \dst, \tmp

	/* set base and length of valid range */
	lgc    c\tmp, \sym
	gclen  \tmp, c\tmp
	scbnds \dst, \dst, \tmp

	/* Set the tag again, authorized by kernel_data_cap */
	llc    c\tmp, kernel_data_cap
	lc     c\tmp, 0(c\tmp)
	cbld   \dst, c\tmp, \dst
#else
	la    \dst, \sym
	add   \dst, \dst, \tmp
#endif
.endm
#else /* CONFIG_SMP */
.macro asm_per_cpu dst sym tmp
#ifdef CONFIG_CHERI_KERNEL
	lgc   \dst, \sym
#else
	la    \dst, \sym
#endif
.endm
#endif /* CONFIG_SMP */

.macro load_per_cpu dst ptr tmp
	asm_per_cpu \dst \ptr \tmp
#ifdef CONFIG_CHERI_KERNEL
	CREG_L \dst, 0(\dst)
#else
	REG_L \dst, 0(\dst)
#endif
.endm

#ifdef CONFIG_SHADOW_CALL_STACK
/* gp is used as the shadow call stack pointer instead */
.macro load_global_pointer
.endm
#else
/* load __global_pointer to gp */
.macro load_global_pointer
.option push
.option norelax
#ifdef CONFIG_CHERI_KERNEL
	/* CHERI does not use the global pointer. Load it with cnull. */
	mv cgp, cnull
#else
	la gp, __global_pointer$
#endif
.option pop
.endm
#endif /* CONFIG_SHADOW_CALL_STACK */

	/* save all GPs except x1 ~ x5 */
	.macro save_from_x6_to_x31
	CREG_S CREG(x6),  PT_T1(CREG(sp))
	CREG_S CREG(x7),  PT_T2(CREG(sp))
	CREG_S CREG(x8),  PT_S0(CREG(sp))
	CREG_S CREG(x9),  PT_S1(CREG(sp))
	CREG_S CREG(x10), PT_A0(CREG(sp))
	CREG_S CREG(x11), PT_A1(CREG(sp))
	CREG_S CREG(x12), PT_A2(CREG(sp))
	CREG_S CREG(x13), PT_A3(CREG(sp))
	CREG_S CREG(x14), PT_A4(CREG(sp))
	CREG_S CREG(x15), PT_A5(CREG(sp))
	CREG_S CREG(x16), PT_A6(CREG(sp))
	CREG_S CREG(x17), PT_A7(CREG(sp))
	CREG_S CREG(x18), PT_S2(CREG(sp))
	CREG_S CREG(x19), PT_S3(CREG(sp))
	CREG_S CREG(x20), PT_S4(CREG(sp))
	CREG_S CREG(x21), PT_S5(CREG(sp))
	CREG_S CREG(x22), PT_S6(CREG(sp))
	CREG_S CREG(x23), PT_S7(CREG(sp))
	CREG_S CREG(x24), PT_S8(CREG(sp))
	CREG_S CREG(x25), PT_S9(CREG(sp))
	CREG_S CREG(x26), PT_S10(CREG(sp))
	CREG_S CREG(x27), PT_S11(CREG(sp))
	CREG_S CREG(x28), PT_T3(CREG(sp))
	CREG_S CREG(x29), PT_T4(CREG(sp))
	CREG_S CREG(x30), PT_T5(CREG(sp))
	CREG_S CREG(x31), PT_T6(CREG(sp))
	.endm

	/* restore all GPs except x1 ~ x5 */
	.macro restore_from_x6_to_x31
	CREG_L CREG(x6),  PT_T1(CREG(sp))
	CREG_L CREG(x7),  PT_T2(CREG(sp))
	CREG_L CREG(x8),  PT_S0(CREG(sp))
	CREG_L CREG(x9),  PT_S1(CREG(sp))
	CREG_L CREG(x10), PT_A0(CREG(sp))
	CREG_L CREG(x11), PT_A1(CREG(sp))
	CREG_L CREG(x12), PT_A2(CREG(sp))
	CREG_L CREG(x13), PT_A3(CREG(sp))
	CREG_L CREG(x14), PT_A4(CREG(sp))
	CREG_L CREG(x15), PT_A5(CREG(sp))
	CREG_L CREG(x16), PT_A6(CREG(sp))
	CREG_L CREG(x17), PT_A7(CREG(sp))
	CREG_L CREG(x18), PT_S2(CREG(sp))
	CREG_L CREG(x19), PT_S3(CREG(sp))
	CREG_L CREG(x20), PT_S4(CREG(sp))
	CREG_L CREG(x21), PT_S5(CREG(sp))
	CREG_L CREG(x22), PT_S6(CREG(sp))
	CREG_L CREG(x23), PT_S7(CREG(sp))
	CREG_L CREG(x24), PT_S8(CREG(sp))
	CREG_L CREG(x25), PT_S9(CREG(sp))
	CREG_L CREG(x26), PT_S10(CREG(sp))
	CREG_L CREG(x27), PT_S11(CREG(sp))
	CREG_L CREG(x28), PT_T3(CREG(sp))
	CREG_L CREG(x29), PT_T4(CREG(sp))
	CREG_L CREG(x30), PT_T5(CREG(sp))
	CREG_L CREG(x31), PT_T6(CREG(sp))
	.endm

/* Annotate a function as being unsuitable for kprobes. */
#ifdef CONFIG_KPROBES
#define ASM_NOKPROBE(name)				\
	.pushsection "_kprobe_blacklist", "aw";		\
	RISCV_PTR name;					\
	.popsection
#else
#define ASM_NOKPROBE(name)
#endif

#endif /* __ASSEMBLY__ */

#endif /* _ASM_RISCV_ASM_H */
