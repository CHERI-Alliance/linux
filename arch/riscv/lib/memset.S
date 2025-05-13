/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2013 Regents of the University of California
 */


#include <linux/linkage.h>
#include <asm/asm.h>

/* void *memset(void *, int, size_t) */
SYM_FUNC_START(__memset)
	mv CREG(t0), CREG(a0)  /* Preserve return value */

	/* Defer to byte-oriented fill for small sizes */
#ifndef CONFIG_CHERI_KERNEL
	sltiu a3, a2, 16
#else
	sltiu a3, a2, 2*CSZREG
#endif
	bnez a3, 4f

	/*
	 * Round to nearest CSZREG-aligned address
	 * greater than or equal to start address

	 * CSZREG is equal to XLEN on Non-CHERI system
	 * CSZREG is equal to CLEN on CHERI system
	 */
	addi a3, t0, CSZREG-1
	andi a3, a3, ~(CSZREG-1)
	beq a3, t0, 2f  /* Skip if already aligned */
	/* Handle initial misalignment */
	sub a4, a3, t0
1:
	sb a1, 0(CREG(t0))
	CINSN(addi) CREG(t0), CREG(t0), 1
	bltu t0, a3, 1b
	sub a2, a2, a4  /* Update count */

2: /* Duff's device with 32 CSZREG stores per iteration */
	/* Broadcast value into all bytes */
	andi a1, a1, 0xff
	slli a3, a1, 8
	or a1, a3, a1
	slli a3, a1, 16
	or a1, a3, a1
#ifdef CONFIG_64BIT
	slli a3, a1, 32
	or a1, a3, a1
#endif
#ifdef CONFIG_CHERI_KERNEL
	schi ca1, ca1, a1
#endif

	/* Calculate end address */
	andi a4, a2, ~(CSZREG-1)
	add a3, t0, a4

	andi a4, a4, 31*CSZREG  /* Calculate remainder */
	beqz a4, 3f            /* Shortcut if no remainder */
	neg a4, a4
	addi a4, a4, 32*CSZREG  /* Calculate initial offset */

	/* Adjust start address with offset */
#ifndef CONFIG_CHERI_KERNEL
	sub t0, t0, a4
#else
	neg a5, a4
	add ct0, ct0, a5
#endif

	/* Jump into loop body */
	/* Assumes 32-bit instruction lengths */
#ifndef CONFIG_CHERI_KERNEL
	la a5, 3f
#else
	llc ca5, 3f
#endif

#ifndef CONFIG_CHERI_KERNEL
#ifdef CONFIG_64BIT
	srli a4, a4, 1
#endif
#else
#ifdef CONFIG_64BIT
	srli a4, a4, 2
#else
	srli a4, a4, 1
#endif
#endif
	add CREG(a5), CREG(a5), a4
	jr CREG(a5)
3:
	CREG_S CREG(a1),        0(CREG(t0))
	CREG_S CREG(a1),    CSZREG(CREG(t0))
	CREG_S CREG(a1),  2*CSZREG(CREG(t0))
	CREG_S CREG(a1),  3*CSZREG(CREG(t0))
	CREG_S CREG(a1),  4*CSZREG(CREG(t0))
	CREG_S CREG(a1),  5*CSZREG(CREG(t0))
	CREG_S CREG(a1),  6*CSZREG(CREG(t0))
	CREG_S CREG(a1),  7*CSZREG(CREG(t0))
	CREG_S CREG(a1),  8*CSZREG(CREG(t0))
	CREG_S CREG(a1),  9*CSZREG(CREG(t0))
	CREG_S CREG(a1), 10*CSZREG(CREG(t0))
	CREG_S CREG(a1), 11*CSZREG(CREG(t0))
	CREG_S CREG(a1), 12*CSZREG(CREG(t0))
	CREG_S CREG(a1), 13*CSZREG(CREG(t0))
	CREG_S CREG(a1), 14*CSZREG(CREG(t0))
	CREG_S CREG(a1), 15*CSZREG(CREG(t0))
	CREG_S CREG(a1), 16*CSZREG(CREG(t0))
	CREG_S CREG(a1), 17*CSZREG(CREG(t0))
	CREG_S CREG(a1), 18*CSZREG(CREG(t0))
	CREG_S CREG(a1), 19*CSZREG(CREG(t0))
	CREG_S CREG(a1), 20*CSZREG(CREG(t0))
	CREG_S CREG(a1), 21*CSZREG(CREG(t0))
	CREG_S CREG(a1), 22*CSZREG(CREG(t0))
	CREG_S CREG(a1), 23*CSZREG(CREG(t0))
	CREG_S CREG(a1), 24*CSZREG(CREG(t0))
	CREG_S CREG(a1), 25*CSZREG(CREG(t0))
	CREG_S CREG(a1), 26*CSZREG(CREG(t0))
	CREG_S CREG(a1), 27*CSZREG(CREG(t0))
	CREG_S CREG(a1), 28*CSZREG(CREG(t0))
	CREG_S CREG(a1), 29*CSZREG(CREG(t0))
	CREG_S CREG(a1), 30*CSZREG(CREG(t0))
	CREG_S CREG(a1), 31*CSZREG(CREG(t0))
	CINSN(addi) CREG(t0), CREG(t0), 32*CSZREG
	bltu t0, a3, 3b
	andi a2, a2, CSZREG-1  /* Update count */

4:
	/* Handle trailing misalignment */
	beqz a2, 6f
	add a3, t0, a2
5:
	sb a1, 0(CREG(t0))
	CINSN(addi) CREG(t0), CREG(t0), 1
	bltu t0, a3, 5b
6:
	ret
SYM_FUNC_END(__memset)
SYM_FUNC_ALIAS_WEAK(memset, __memset)
SYM_FUNC_ALIAS(__pi_memset, __memset)
SYM_FUNC_ALIAS(__pi___memset, __memset)
