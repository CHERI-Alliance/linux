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


/*
 * Read/Write CSR register repl which can be either a CHERI CSR name or
 * an (non-cheri) integer constant into a capability GPR.
 * The GPR name is the non-cheri name and will be replaced with the
 * correct capability register, usually be prefixing "c".
 */
.macro ccsrr gpr repl
.ifeqs "\gpr","zero"
	csrrs c\gpr, \repl, x0
.else
.ifeqs "\gpr","x0"
	csrrs c\gpr, \repl, x0
.else
	csrrs c\gpr, \repl, x0
.endif
.endif
.endm

.macro ccsrw repl gpr
.ifeqs "\gpr","zero"
	csrrw cnull, \repl, cnull
.else
.ifeqs "\gpr","x0"
	csrrw cnull, \repl, cnull
.else
	csrrw cnull, \repl, c\gpr
.endif
.endif
.endm


/*
 * Call the ccsrr/ccsrw macro with "repl" as the CHERI register
 * name if the CSR register constant "csr" matches "tval".
 * Additionally define a temporary symbol this was a match.
 */
.macro csrmapr csr gpr tval repl unique
.if !(\csr - \tval)
ccsrr \gpr, \repl
.equ .Lcsrmapr_done_\unique, 1
.endif
.endm

.macro csrmapw csr gpr tval repl unique
.if !(\csr - \tval)
ccsrw \repl, \gpr
.equ .Lcsrmapw_done_\unique, 1
.endif
.endm

/*
 * Replace CSR register and GPR register with CHERI CSR register name
 * and a capability GPR register if in the list of replacement registers.
 * Otherwise output the csrr/csrw instruction unmodified.
 */
#define CSRMAP(TVAL, REPL) csrmapr \csr \gpr TVAL REPL \unique
.macro _csrr csr gpr unique
#include "asmcheri_csrmap.h"
.ifndef .Lcsrmapr_done_\unique
	csrrs \gpr, \csr, x0
.endif
.endm
#undef CSRMAP

#define CSRMAP(TVAL, REPL) csrmapw \csr \gpr TVAL REPL \unique
.macro _csrw csr gpr unique
#include "asmcheri_csrmap.h"
.ifndef .Lcsrmapw_done_\unique
	csrrw x0, \csr, \gpr
.endif
.endm
#undef CSRMAP

/*
 * Actual replacement macros. Pass in a value that is unique per
 * macro invocation for the symbol that indicates a CHERI CSR register
 * match. Note that csrr swaps CSR and GPR register when invoking _csrr.
 */
.macro csrr gpr csr
_csrr \csr \gpr \@
.endm

.macro csrw csr gpr
_csrw \csr \gpr \@
.endm

/*
 * Enter capability mode.
 * @param reg: A scratch register
 * Clobbers: CSR_TVEC
 */
.macro enter_capmode reg
	la \reg, 1f
	csrw CSR_TVEC, \reg
	.byte 0x33, 0x10, 0x00, 0x09	/* New modesw.CAP */
	j 2f
1:	auipc c\reg, 0
	gctag \reg, c\reg
	bnez \reg, 2f
	.byte 0x33, 0x10, 0x00, 0x12	/* Old modesw. */
2:
.endm

/*
 * Detect the CHERI acperm layout
 * @param legacy Set to one if the legacy acperm bitmap layout
 *     is in use.
 * @param infperms Filled with the minimum capabilities requried
 *     for an infinite capability.
 * @param tmp A scratch register
 * Clobbers: CSR_TVEC, cra
 */
.macro detect_acperm_layout legacy, infperms, tmp
	/*
	 * Setup exception vector. The jalr will trap for the new
	 * acperm bitmask due to missing execute permissions.
	 */
	la \tmp, 2f
	csrw CSR_TVEC, \tmp

	/* Setup call to 1f, use \legacy as a second scratch. */
	la \tmp, 1f
	li \legacy, 0xff
	acperm c\tmp, c\tmp, \legacy

	/* Load v0.9 style acperm values. */
	li \legacy, 0
	li \infperms, 0x70063	/* New ACPERM: R, W, X, ASR, LM, C, SDP:1 */

	/*
	 * Try to call 1f. We will return here for new ACPERM and jump to 
	 * the trap vector for legacy. In both cases pcc permissions are
	 * preserved.
	 */
	jalr \tmp

	/* We returned from jalr so we are done. */
	j 3f

	/* Call point for jalr above. */
1:	ret

2:	/* Trap vector: Load legacy values. */
	li \legacy, 1
	li \infperms, 0x1001f

3:	/* Continuation point. */
.endm

/*
 * Check a capability and if it is the infinite capability
 * install it into pcc by jumping to @okaddr.
 * @param inf A register with the capability to test.
 * @param perm A register that contains the minimum permission mask
 *     required for the infinite capability (not modified).
 * @param tmp A temporary scratch register
 * @param okaddr The target label where execution will continue in
 *     case of success.
 */
.macro try_install_infcap inf perm tmp okaddr
	/* Need a valid tag */
	gctag \tmp, c\inf
	beqz \tmp, 1f

	/* Base must be zero */
	gcbase \tmp, c\inf
	bnez \tmp, 1f

	/* Length must be infinite. */
	gclen \tmp, c\inf
	addi \tmp, \tmp, 1
	bnez \tmp, 1f

	/* Check permissions. */
	gcperm \tmp, c\inf
	and \tmp, \tmp, \perm
	bne \tmp, \perm, 1f

	/* Ok, uses it. */
	la \tmp, \okaddr
	scaddr c\tmp, c\inf, \tmp
	jr c\tmp

1:	/* Failure. */
.endm

/*
 * Find the infinite capability in ca3 or ddc. If found install it
 * in pcc. Otherwise assume that the capability in pcc is ok.
 * @param perm A register that contains the minimum permission mask
 *     required for the infinite capability (not modified). Try x0
 *     if you don't know.
 * @param tmp1 A temporary scratch register
 * @param tmp2 A temporary scratch register
 */
.macro find_infcap perm tmp1 tmp2
	cmv c\tmp1, ca3
	try_install_infcap \tmp1 \perm \tmp2 100f
	ccsrr \tmp1, ddc
	try_install_infcap \tmp1 \perm \tmp2 100f
100:	enter_capmode \tmp1
.endm

/*
 * Probe for the location and the orientation of the M-bit.
 * @param mask Will be filled with the bit mask of the mbit in the meta
 *     data part of a capbility.
 * @param value Will be filled with the value of the M-bit for capability
 *     mode. This is either zero or equal to mask.
 * @param scmodeval This will be filled with the value that must be passed
 *     to scmode to enable capability mode.
 * @param hybrid Will be set to 1 if the CPU support hybrid mode and to
 *     zero for a purecap CPU.
 * Clobbers: CSR_TVEC
 *
 * Prerequisite: We must already operate in capability mode.
 */
.macro detect_mbit mask, value, scmodeval, hybrid
	/*
	 * If we are not on a hybrid CPU the scmode instruction will trap
	 * and zero values are ok.
	 */
	la \hybrid, 1f
	csrw CSR_TVEC, \hybrid

	/*
	 * We execute in capability mode, thus a capability derived
	 * from ppc has capability mode enabled. Create a capabilities
	 * with scmode(1) and scmode(0) from these and compare the results.
	 * witch scmode(1) and compare the results. Use the output
	 * registers for temporary values.
	 */
	auipc c\value, 0
	li \hybrid, 1
	scmode c\mask, c\value, \hybrid
	scmode c\hybrid, c\value, zero

	/* Determine scmodeval */
	sceq \scmodeval, c\mask, c\value

	/* Get meta data for all three capabilities. */
	gchi \value, c\value
	gchi \mask, c\mask
	gchi \hybrid, c\hybrid

	/* Determine final value of M-bit mask and value. */
	xor \mask, \mask, \hybrid
	and \value, \value, \mask

	/* Hybird supported. */
	li \hybrid, 1

	j 2f

	/* Fallback trap vector target for a purecap CPU. */
1:	li \mask, 0
	li \value, 0
	li \scmodeval, 0
	li \hybrid, 0
2:
.endm

/*
 * Detect the presence of a CSR register by reading from it.
 * @param csr The CSR register
 * @param reg Set to 1 iff the register is supported.
 */
.macro detect_csr csr reg
	la \reg, 1f
	csrw CSR_TVEC, \reg
	csrr \reg, \csr
	li \reg, 1
	j 2f
1:	li \reg, 0
2:
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


/*
 * Clear stale capabilities in CHERI registers and enable CHERI
 * for user mode.
 * @param tmp A scratch register
 */
.macro setup_cheri_regs tmp
	ccsrw ddc, zero
	ccsrw stdc, zero
	li \tmp, 1 << 28
	csrs senvcfg, \tmp
.endm

#else /* CONFIG_CHERI_KERNEL */

.macro enter_capmode reg
.endm

#endif /* CONFIG_CHERI_KERNEL */

#endif /* _ASM_RISCV_ASMCHERI_H */
