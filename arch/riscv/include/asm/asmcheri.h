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
CSRMAP(CSR_TVEC, tvecc)
CSRMAP(CSR_SCRATCH, scratchc)
CSRMAP(CSR_EPC, epcc)
.ifndef .Lcsrmapr_done_\unique
	csrrs \gpr, \csr, x0
.endif
.endm
#undef CSRMAP

#define CSRMAP(TVAL, REPL) csrmapw \csr \gpr TVAL REPL \unique
.macro _csrw csr gpr unique
CSRMAP(CSR_TVEC, tvecc)
CSRMAP(CSR_SCRATCH, scratchc)
CSRMAP(CSR_EPC, epcc)
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
 * Clobbers: t0, stvecc
 */
.macro enter_capmode
	la t0, 1f
	csrw CSR_TVEC, t0
	.byte 0x33, 0x10, 0x00, 0x09	/* New modesw.CAP */
	j 2f
1:	auipc ct0, 0
	gctag t0, ct0
	bnez t0, 2f
	.byte 0x33, 0x10, 0x00, 0x12	/* Old modesw. */
2:
.endm

#else /* CONFIG_CHERI_KERNEL */

.macro enter_capmode
.endm

#endif /* CONFIG_CHERI_KERNEL */

#endif /* _ASM_RISCV_ASMCHERI_H */
