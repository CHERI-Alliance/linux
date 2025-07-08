/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2023 Rivos Inc. */

#include <linux/linkage.h>
#include <asm/asm.h>

	.text

/* void __riscv_copy_words_unaligned(void *, const void *, size_t) */
/* Performs a memcpy without aligning buffers, using word loads and stores. */
/* Note: The size is truncated to a multiple of 8 * SZREG */
SYM_FUNC_START(__riscv_copy_words_unaligned)
	andi  a4, a2, ~((8*SZREG)-1)
	beqz  a4, 2f
	add   a3, a1, a4
1:
	REG_L a4,       0(CREG(a1))
	REG_L a5,   SZREG(CREG(a1))
	REG_L a6, 2*SZREG(CREG(a1))
	REG_L a7, 3*SZREG(CREG(a1))
	REG_L t0, 4*SZREG(CREG(a1))
	REG_L t1, 5*SZREG(CREG(a1))
	REG_L t2, 6*SZREG(CREG(a1))
	REG_L t3, 7*SZREG(CREG(a1))
	REG_S a4,       0(CREG(a0))
	REG_S a5,   SZREG(CREG(a0))
	REG_S a6, 2*SZREG(CREG(a0))
	REG_S a7, 3*SZREG(CREG(a0))
	REG_S t0, 4*SZREG(CREG(a0))
	REG_S t1, 5*SZREG(CREG(a0))
	REG_S t2, 6*SZREG(CREG(a0))
	REG_S t3, 7*SZREG(CREG(a0))
	CINSN(addi)  CREG(a0), CREG(a0), 8*SZREG
	CINSN(addi)  CREG(a1), CREG(a1), 8*SZREG
	bltu  a1, a3, 1b

2:
	ret
SYM_FUNC_END(__riscv_copy_words_unaligned)

/* void __riscv_copy_bytes_unaligned(void *, const void *, size_t) */
/* Performs a memcpy without aligning buffers, using only byte accesses. */
/* Note: The size is truncated to a multiple of 8 */
SYM_FUNC_START(__riscv_copy_bytes_unaligned)
	andi a4, a2, ~(8-1)
	beqz a4, 2f
	add  a3, a1, a4
1:
	lb   a4, 0(CREG(a1))
	lb   a5, 1(CREG(a1))
	lb   a6, 2(CREG(a1))
	lb   a7, 3(CREG(a1))
	lb   t0, 4(CREG(a1))
	lb   t1, 5(CREG(a1))
	lb   t2, 6(CREG(a1))
	lb   t3, 7(CREG(a1))
	sb   a4, 0(CREG(a0))
	sb   a5, 1(CREG(a0))
	sb   a6, 2(CREG(a0))
	sb   a7, 3(CREG(a0))
	sb   t0, 4(CREG(a0))
	sb   t1, 5(CREG(a0))
	sb   t2, 6(CREG(a0))
	sb   t3, 7(CREG(a0))
	CINSN(addi) CREG(a0), CREG(a0), 8
	CINSN(addi) CREG(a1), CREG(a1), 8
	bltu a1, a3, 1b

2:
	ret
SYM_FUNC_END(__riscv_copy_bytes_unaligned)
