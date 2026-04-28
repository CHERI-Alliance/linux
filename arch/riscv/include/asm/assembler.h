/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2023 StarFive Technology Co., Ltd.
 *
 * Author: Jee Heng Sia <jeeheng.sia@starfivetech.com>
 */

#ifndef __ASSEMBLER__
#error "Only include this from assembly code"
#endif

#ifndef __ASM_ASSEMBLER_H
#define __ASM_ASSEMBLER_H

#include <asm/asm.h>
#include <asm/asm-offsets.h>
#include <asm/csr.h>
#include <asm/asmcheri.h>

/*
 * suspend_restore_csrs - restore CSRs
 */
	.macro suspend_restore_csrs
		CREG_L	CREG(t0), (SUSPEND_CONTEXT_REGS + PT_EPC)(CREG(a0))
		csrw	CSR_EPC, t0
		REG_L	t0, (SUSPEND_CONTEXT_REGS + PT_STATUS)(CREG(a0))
		csrw	CSR_STATUS, t0
		REG_L	t0, (SUSPEND_CONTEXT_REGS + PT_BADADDR)(CREG(a0))
		csrw	CSR_TVAL, t0
		REG_L	t0, (SUSPEND_CONTEXT_REGS + PT_CAUSE)(CREG(a0))
		csrw	CSR_CAUSE, t0
	.endm

/*
 * suspend_restore_regs - Restore registers (except A0 and T0-T6)
 */
	.macro suspend_restore_regs
		CREG_L	CREG(ra), (SUSPEND_CONTEXT_REGS + PT_RA)(CREG(a0))
		CREG_L	CREG(sp), (SUSPEND_CONTEXT_REGS + PT_SP)(CREG(a0))
		CREG_L	CREG(gp), (SUSPEND_CONTEXT_REGS + PT_GP)(CREG(a0))
		CREG_L	CREG(tp), (SUSPEND_CONTEXT_REGS + PT_TP)(CREG(a0))
		CREG_L	CREG(s0), (SUSPEND_CONTEXT_REGS + PT_S0)(CREG(a0))
		CREG_L	CREG(s1), (SUSPEND_CONTEXT_REGS + PT_S1)(CREG(a0))
		CREG_L	CREG(a1), (SUSPEND_CONTEXT_REGS + PT_A1)(CREG(a0))
		CREG_L	CREG(a2), (SUSPEND_CONTEXT_REGS + PT_A2)(CREG(a0))
		CREG_L	CREG(a3), (SUSPEND_CONTEXT_REGS + PT_A3)(CREG(a0))
		CREG_L	CREG(a4), (SUSPEND_CONTEXT_REGS + PT_A4)(CREG(a0))
		CREG_L	CREG(a5), (SUSPEND_CONTEXT_REGS + PT_A5)(CREG(a0))
		CREG_L	CREG(a6), (SUSPEND_CONTEXT_REGS + PT_A6)(CREG(a0))
		CREG_L	CREG(a7), (SUSPEND_CONTEXT_REGS + PT_A7)(CREG(a0))
		CREG_L	CREG(s2), (SUSPEND_CONTEXT_REGS + PT_S2)(CREG(a0))
		CREG_L	CREG(s3), (SUSPEND_CONTEXT_REGS + PT_S3)(CREG(a0))
		CREG_L	CREG(s4), (SUSPEND_CONTEXT_REGS + PT_S4)(CREG(a0))
		CREG_L	CREG(s5), (SUSPEND_CONTEXT_REGS + PT_S5)(CREG(a0))
		CREG_L	CREG(s6), (SUSPEND_CONTEXT_REGS + PT_S6)(CREG(a0))
		CREG_L	CREG(s7), (SUSPEND_CONTEXT_REGS + PT_S7)(CREG(a0))
		CREG_L	CREG(s8), (SUSPEND_CONTEXT_REGS + PT_S8)(CREG(a0))
		CREG_L	CREG(s9), (SUSPEND_CONTEXT_REGS + PT_S9)(CREG(a0))
		CREG_L	CREG(s10), (SUSPEND_CONTEXT_REGS + PT_S10)(CREG(a0))
		CREG_L	CREG(s11), (SUSPEND_CONTEXT_REGS + PT_S11)(CREG(a0))
	.endm

/*
 * copy_page - copy 1 page (4KB) of data from source to destination
 * @a0 - destination
 * @a1 - source
 */
	.macro	copy_page a0, a1
		lui	a2, 0x1
		add	a2, a2, a0
1 :
		REG_L	t0, 0(a1)
		REG_L	t1, SZREG(a1)

		REG_S	t0, 0(a0)
		REG_S	t1, SZREG(a0)

		addi	a0, a0, 2 * SZREG
		addi	a1, a1, 2 * SZREG
		bne	a2, a0, 1b
	.endm

#endif	/* __ASM_ASSEMBLER_H */

#if defined(VDSO_CFI) && (__riscv_xlen == 64)
.macro vdso_lpad, label = 0
lpad \label
.endm
#else
.macro vdso_lpad, label = 0
.endm
#endif

/*
 * This macro emits a program property note section identifying
 * architecture features which require special handling, mainly for
 * use in assembly files included in the VDSO.
 */
#define NT_GNU_PROPERTY_TYPE_0  5
#define GNU_PROPERTY_RISCV_FEATURE_1_AND 0xc0000000

#define GNU_PROPERTY_RISCV_FEATURE_1_ZICFILP		BIT(0)
#define GNU_PROPERTY_RISCV_FEATURE_1_ZICFISS		BIT(1)

#if defined(VDSO_CFI) && (__riscv_xlen == 64)
#define GNU_PROPERTY_RISCV_FEATURE_1_DEFAULT \
	(GNU_PROPERTY_RISCV_FEATURE_1_ZICFILP | GNU_PROPERTY_RISCV_FEATURE_1_ZICFISS)
#endif

#ifdef GNU_PROPERTY_RISCV_FEATURE_1_DEFAULT
.macro emit_riscv_feature_1_and, feat = GNU_PROPERTY_RISCV_FEATURE_1_DEFAULT
	.pushsection .note.gnu.property, "a"
	.p2align        3
	.word           4
	.word           16
	.word           NT_GNU_PROPERTY_TYPE_0
	.asciz          "GNU"
	.word           GNU_PROPERTY_RISCV_FEATURE_1_AND
	.word           4
	.word           \feat
	.word           0
	.popsection
.endm
#else
.macro emit_riscv_feature_1_and, feat = 0
.endm
#endif
