/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021 Western Digital Corporation or its affiliates.
 * Copyright (c) 2022 Ventana Micro Systems Inc.
 */

#include <linux/linkage.h>
#include <linux/cfi_types.h>
#include <asm/asm.h>
#include <asm/asm-offsets.h>
#include <asm/assembler.h>
#include <asm/csr.h>
#include <asm/xip_fixup.h>
#include <asm/asmcheri.h>

	.text
	.altmacro
	.option norelax

SYM_FUNC_START(__cpu_suspend_enter)
	/* Save registers (except A0 and T0-T6) */
	CREG_S	CREG(ra), (SUSPEND_CONTEXT_REGS + PT_RA)(CREG(a0))
	CREG_S	CREG(sp), (SUSPEND_CONTEXT_REGS + PT_SP)(CREG(a0))
	CREG_S	CREG(gp), (SUSPEND_CONTEXT_REGS + PT_GP)(CREG(a0))
	CREG_S	CREG(tp), (SUSPEND_CONTEXT_REGS + PT_TP)(CREG(a0))
	CREG_S	CREG(s0), (SUSPEND_CONTEXT_REGS + PT_S0)(CREG(a0))
	CREG_S	CREG(s1), (SUSPEND_CONTEXT_REGS + PT_S1)(CREG(a0))
	CREG_S	CREG(a1), (SUSPEND_CONTEXT_REGS + PT_A1)(CREG(a0))
	CREG_S	CREG(a2), (SUSPEND_CONTEXT_REGS + PT_A2)(CREG(a0))
	CREG_S	CREG(a3), (SUSPEND_CONTEXT_REGS + PT_A3)(CREG(a0))
	CREG_S	CREG(a4), (SUSPEND_CONTEXT_REGS + PT_A4)(CREG(a0))
	CREG_S	CREG(a5), (SUSPEND_CONTEXT_REGS + PT_A5)(CREG(a0))
	CREG_S	CREG(a6), (SUSPEND_CONTEXT_REGS + PT_A6)(CREG(a0))
	CREG_S	CREG(a7), (SUSPEND_CONTEXT_REGS + PT_A7)(CREG(a0))
	CREG_S	CREG(s2), (SUSPEND_CONTEXT_REGS + PT_S2)(CREG(a0))
	CREG_S	CREG(s3), (SUSPEND_CONTEXT_REGS + PT_S3)(CREG(a0))
	CREG_S	CREG(s4), (SUSPEND_CONTEXT_REGS + PT_S4)(CREG(a0))
	CREG_S	CREG(s5), (SUSPEND_CONTEXT_REGS + PT_S5)(CREG(a0))
	CREG_S	CREG(s6), (SUSPEND_CONTEXT_REGS + PT_S6)(CREG(a0))
	CREG_S	CREG(s7), (SUSPEND_CONTEXT_REGS + PT_S7)(CREG(a0))
	CREG_S	CREG(s8), (SUSPEND_CONTEXT_REGS + PT_S8)(CREG(a0))
	CREG_S	CREG(s9), (SUSPEND_CONTEXT_REGS + PT_S9)(CREG(a0))
	CREG_S	CREG(s10), (SUSPEND_CONTEXT_REGS + PT_S10)(CREG(a0))
	CREG_S	CREG(s11), (SUSPEND_CONTEXT_REGS + PT_S11)(CREG(a0))

	/* Save CSRs */
	csrr	t0, CSR_EPC
	CREG_S	CREG(t0), (SUSPEND_CONTEXT_REGS + PT_EPC)(CREG(a0))
	csrr	t0, CSR_STATUS
	REG_S	t0, (SUSPEND_CONTEXT_REGS + PT_STATUS)(CREG(a0))
	csrr	t0, CSR_TVAL
	REG_S	t0, (SUSPEND_CONTEXT_REGS + PT_BADADDR)(CREG(a0))
	csrr	t0, CSR_CAUSE
	REG_S	t0, (SUSPEND_CONTEXT_REGS + PT_CAUSE)(CREG(a0))

	/* Return non-zero value */
	li	a0, 1

	/* Return to C code */
	ret
SYM_FUNC_END(__cpu_suspend_enter)

/* FIXCHERI: How do we get our code capability back? */
SYM_TYPED_FUNC_START(__cpu_resume_enter)
	/* Load the global pointer */
	load_global_pointer

#ifdef CONFIG_MMU
	/* Save A0 and A1 */
	mv	CREG(t0), CREG(a0)
	mv	CREG(t1), CREG(a1)

	/* Enable MMU */
	la	a0, swapper_pg_dir
	XIP_FIXUP_OFFSET a0
	call	relocate_enable_mmu

	/* Restore A0 and A1 */
	mv	CREG(a0), CREG(t0)
	mv	CREG(a1), CREG(t1)
#endif

	/* Make A0 point to suspend context */
	mv	CREG(a0), CREG(a1)

	/* Restore CSRs */
	suspend_restore_csrs

	/* Restore registers (except A0 and T0-T6) */
	suspend_restore_regs

	/* Return zero value */
	add	a0, zero, zero

	/* Return to C code */
	ret
SYM_FUNC_END(__cpu_resume_enter)
