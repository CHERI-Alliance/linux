/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_ASMCHERI_H
#define _ASM_RISCV_ASMCHERI_H

#include <asm/asm.h>
#include <asm/csr.h>

#ifdef CONFIG_CHERI_KERNEL

/* Replacement macro for la */
.macro la dst sym
llc c\dst, \sym
.endm

/*
 * Replacement macros for csrr and csrw.
 * The macro translates non-cheri register constants back to CHERI
 * register names for selected capability register and replaces the
 * GPR argument with a suitable capabillity register.
 */

.macro declare_cap_csr csr
.equ .Lis_cap_csr_\csr, 1
.endm
#define DECLARE_CAP_CSR(REG) declare_cap_csr REG

DECLARE_CAP_CSR(CSR_MTVEC)
DECLARE_CAP_CSR(CSR_STVEC)
DECLARE_CAP_CSR(CSR_MSCRATCH)
DECLARE_CAP_CSR(CSR_SSCRATCH)
DECLARE_CAP_CSR(CSR_MEPC)
DECLARE_CAP_CSR(CSR_SEPC)
DECLARE_CAP_CSR(CSR_DDC)
DECLARE_CAP_CSR(CSR_SSP)

.macro ccsrr gpr csr
.ifeqs "\gpr","zero"
	csrrs cnull, \csr, x0
.else
.ifeqs "\gpr","x0"
	csrrs cnull, \csr, x0
.else
	csrrs c\gpr, \csr, x0
.endif
.endif
.endm

.macro csrr gpr csr
.ifndef .Lis_cap_csr_\csr
	csrrs \gpr, \csr, x0
.else
	ccsrr \gpr \csr
.endif
.endm

.macro ccsrw csr gpr
.ifeqs "\gpr","zero"
	csrrw cnull, \csr, c0
.else
.ifeqs "\gpr","x0"
	csrrw cnull, \csr, c0
.else
	csrrw cnull, \csr, c\gpr
.endif
.endif
.endm

.macro csrw csr gpr
.ifndef .Lis_cap_csr_\csr
	csrrw x0, \csr, \gpr
.else
	ccsrw \csr, \gpr
.endif
.endm

/*
 * Enter capability mode.
 * @param reg: A scratch register
 */
.macro enter_capmode reg
	auipc c\reg, 0
	gctag \reg, c\reg
	bnez \reg, 1f
	modesw.CAP
1:
.endm

/*
 * Detect support for cheri levels.
 * Pre-requisites: Operating in capability mode
 * @param res Set to true if cheri levels are supported, false otherwise
 * @param scratchmem A scratch memory location
 * @param tmp A temporary register
 */
.macro detect_cheri_levels res, scratchmem, tmp
	/*
	 * Create a capbility that is local itself and does not have
	 * the store local permission set by clearing SL and the level
	 * (aka the global bit). We clear the EL bit for symmetry
	 * reasons only.
	 */
	la \tmp, \scratchmem
	li \res, ~0x001c	/* Clear: Level, EL, SL */
	acperm c\tmp, c\tmp, \res

	/*
	 * Store the capability to the scratch memory location and
	 * read it back. With zcherilevels this will clear the tag.
	 */
	sc c\tmp, (c\tmp)
	lc c\tmp, (c\tmp)

	/* Check the tag and calculate the result value. */
	li \res, 1
	gctag \tmp, c\tmp
	sub \res, \res, \tmp
.endm

/*
 * Reset all general purpose registers except sp and tp to zero.
 */
.macro reset_gprs
	li x1, 0
	/* Skip sp */
	li x3, 0
	/* Skip tp */
	li x5, 0
	li x6, 0
	li x7, 0
	li x8, 0
	li x9, 0
	li x10, 0
	li x11, 0
	li x12, 0
	li x13, 0
	li x14, 0
	li x15, 0
	li x16, 0
	li x17, 0
	li x18, 0
	li x19, 0
	li x20, 0
	li x21, 0
	li x22, 0
	li x23, 0
	li x24, 0
	li x25, 0
	li x26, 0
	li x27, 0
	li x28, 0
	li x29, 0
	li x30, 0
	li x31, 0
.endm

/*
 * Derive the current pcc from the given capability in memory.
 * @param cap The name of the code capability.
 * @param tmp1 Temporary.
 * @param tmp2 Temporary.
 */
.macro setup_pcc cap tmp1 tmp2
	la \tmp1, \cap
	lc c\tmp1, (c\tmp1)
	la \tmp2, 1f
	scaddr c\tmp1, c\tmp1, \tmp2
	jr c\tmp1
1:
.endm

#else /* CONFIG_CHERI_KERNEL */

.macro enter_capmode reg
.endm

#endif /* CONFIG_CHERI_KERNEL */

#endif /* _ASM_RISCV_ASMCHERI_H */
