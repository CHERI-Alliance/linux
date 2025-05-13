/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2025 Codasip GmbH.
 */

#include <linux/linkage.h>
#include <asm/asm.h>

/* void *memcpy(void *, const void *, size_t) */
SYM_FUNC_START(__memcpy)
	beqz	a2, .Lreturn_from_memcpy
	beq	a0, a1, .Lreturn_from_memcpy

	add	a4, a0, a2
	mv	ca3, ca0

.Lbyte_copy_until_dest_aligned_forward:
	andi	t0, a3, CSZREG-1
	beqz	t0, 2f
1:
	lbu	t1, 0(ca1)
	sb	t1, 0(ca3)
	add	ca1, ca1, 1
	add	ca3, ca3, 1
	beq	a3, a4, .Lreturn_from_memcpy
	andi	t0, a3, CSZREG-1
	bnez	t0, 1b
2:
	addi	a5, a4, -(CSZREG-1)
	bgeu	a3, a5, .Ltail_byte_copy_forward

	andi	t0, a1, CSZREG-1
	bnez	t0, .Lmisaligned_fixup_copy_forward

.Lcap_aligned_bulk_copy_forward:
	addi	a5, a4, -((8*CSZREG)-1)
	bgeu	a3, a5, .Lcap_aligned_copy_forward
1:
	lc	ct0, 0*CSZREG(ca1)
	lc	ct1, 1*CSZREG(ca1)
	lc	ct2, 2*CSZREG(ca1)
	lc	ct3, 3*CSZREG(ca1)
	lc	ct4, 4*CSZREG(ca1)
	lc	ct5, 5*CSZREG(ca1)
	lc	ct6, 6*CSZREG(ca1)
	lc	ca6, 7*CSZREG(ca1)
	sc	ct0, 0*CSZREG(ca3)
	sc	ct1, 1*CSZREG(ca3)
	sc	ct2, 2*CSZREG(ca3)
	sc	ct3, 3*CSZREG(ca3)
	sc	ct4, 4*CSZREG(ca3)
	sc	ct5, 5*CSZREG(ca3)
	sc	ct6, 6*CSZREG(ca3)
	sc	ca6, 7*CSZREG(ca3)
	add	ca1, ca1, 8*CSZREG
	add	ca3, ca3, 8*CSZREG
	bltu	a3, a5, 1b

	beq	a3, a4, .Lreturn_from_memcpy

.Lcap_aligned_copy_forward:
	addi	a5, a4, -(CSZREG-1)
#ifdef	CONFIG_64BIT
	bgeu	a3, a5, .Ltail_double_word_aligned_copy_forward
#else
	bgeu	a3, a5, .Ltail_word_aligned_copy_forward
#endif
1:
	lc	ct0, 0(ca1)
	sc	ct0, 0(ca3)
	add	ca1, ca1, CSZREG
	add	ca3, ca3, CSZREG
	bltu	a3, a5, 1b

	beq	a3, a4, .Lreturn_from_memcpy

#ifdef	CONFIG_64BIT
.Ltail_double_word_aligned_copy_forward:
	addi	a5, a4, -(8-1)
	bgeu	a3, a5, .Ltail_word_aligned_copy_forward

	ld	t0, 0(ca1)
	sd	t0, 0(ca3)
	add	ca1, ca1, 8
	add	ca3, ca3, 8

	beq	a3, a4, .Lreturn_from_memcpy
#endif

.Ltail_word_aligned_copy_forward:
	addi	a5, a4, -(4-1)
	bgeu	a3, a5, .Ltail_half_word_aligned_copy_forward

	lw	t0, 0(ca1)
	sw	t0, 0(ca3)
	add	ca1, ca1, 4
	add	ca3, ca3, 4

	beq	a3, a4, .Lreturn_from_memcpy

.Ltail_half_word_aligned_copy_forward:
	addi	a5, a4, -(2-1)
	bgeu	a3, a5, .Ltail_byte_copy_forward

	lhu	t0, 0(ca1)
	sh	t0, 0(ca3)
	add	ca1, ca1, 2
	add	ca3, ca3, 2

	beq	a3, a4, .Lreturn_from_memcpy

.Ltail_byte_copy_forward:
	lbu	t0, 0(ca1)
	sb	t0, 0(ca3)
	add	ca1, ca1, 1
	add	ca3, ca3, 1
	bne	a3, a4, .Ltail_byte_copy_forward

.Lreturn_from_memcpy:
	ret

	/*
	 * Optimize misaligned memory copies by using aligned CLEN read/write
	 * instructions. This technique avoids slower unaligned access by
	 * effectively shifting the read data based on the source-destination
	 * address offset to enable aligned CLEN operations.
	 */
.Lmisaligned_fixup_copy_forward:
	andi	t0, a1, SZREG-1
	beqz	t0, .Lcap_misaligned_word_aligned_copy_forward

	addi	a5, a4, -(2*CSZREG-1)
	bgeu	a3, a5, .Ltail_byte_copy_forward

	andi	t2, a1, SZREG-1
	slli	t2, t2, 3
	andi	t4, a1, CSZREG-1
	srli	t4, t4, LGREG

	mv	ca6, ca1
	andi	t5, a6, ~(CSZREG-1)
	gcbase	t1, ca6
	bgeu	t5, t1, 2f

	/*
	 * Copy data byte by byte up to the next CLEN-aligned address to
	 * prevent CHERI violations from out-of-bounds accesses on shifted
	 * source capabilities.
	 */
	li	t0, 0
	mv	t3, t2
1:
	lbu	t1, 0(ca6)
	sll	t1, t1, t3
	or	t0, t0, t1
	add	ca6, ca6, 1
	addi	t3, t3, 8
	andi	t6, a6, SZREG-1
	bnez	t6, 1b

	schi	ct0, ct0, t0
	bnez	t4, .Lmisaligned_fixup_shift_cap_hi_forward

	REG_L	t1, 0(ca6)
	add	ca6, ca6, SZREG
	schi	ct0, ct0, t1
	j	.Lmisaligned_fixup_shift_cap_low_forward

2:
	scaddr	ca6, ca6, t5
	lc	ct0, 0(ca6)
	add	ca6, ca6, CSZREG
	bnez	t4, .Lmisaligned_fixup_shift_cap_hi_forward

	/*
	 * Since capability width shift and logical instructions are
	 * unavailable, we need two separate approaches to correctly shift data
	 * between capabilities: one for shifting data at lower capability, and
	 * one for shifting data at upper capability.
	 *
	 * Case 1:
	 * Fix Misalignment Copy Loop for shifting from lower capability
	 * load_aligned_val = *cap_aligned_load_ptr++;
	 * do {
	 * 	store_aligned_val.lower = (load_aligned_val.lower >> {t2}) |
	 *				(load_aligned_val.upper << {t3});
	 *
	 *	tmp = load_aligned_val.upper;
	 *
	 *	load_aligned_val = *cap_aligned_load_ptr++;
	 *
	 * 	store_aligned_val.upper = (tmp >> {t2}) |
	 *				(load_aligned_val.upper << {t3});
	 *
	 *	*cap_aligned_store_ptr++ = store_aligned_val;
	 *
	 * } while (cap_aligned_store_ptr < {a5});
	 *
	 * Case 2:
	 * Fix Misalignment Copy Loop for shifting from upper capability
	 * load_aligned_val = *cap_aligned_load_ptr++;
	 * do {
	 *	tmp = load_aligned_val.upper;
	 *
	 *	load_aligned_val = *cap_aligned_load_ptr++;
	 *
	 * 	store_aligned_val.lower = (tmp >> {t2}) |
	 *				(load_aligned_val.lower << {t3});
	 *
	 * 	store_aligned_val.upper = (load_aligned_val.lower >> {t2}) |
	 *				(load_aligned_val.upper << {t3});
	 *
	 *	*cap_aligned_store_ptr++ = store_aligned_val;
	 *
	 * } while (cap_aligned_store_ptr < {a5});
	 */
.Lmisaligned_fixup_shift_cap_low_forward:
	neg	t3, t2
	mv	t4, a3
1:
	srl	t6, t0, t2
	gchi	t0, ct0
	sll	t1, t0, t3
	or	t1, t1, t6
	srl	t6, t0, t2
	lc	ct0, 0(ca6)
	add	ca6, ca6, CSZREG
	sll	t5, t0, t3
	or	t5, t5, t6
	schi	ct1, ct1, t5
	sc	ct1, 0(ca3)
	add	ca3, ca3, CSZREG
	bltu	a3, a5, 1b

	sub	t4, a3, t4
	add	ca1, ca1, t4
	bltu	a3, a4, .Ltail_byte_copy_forward
	ret

.Lmisaligned_fixup_shift_cap_hi_forward:
	neg	t3, t2
	mv	t4, a3
	gchi	t0, ct0
1:
	srl	t6, t0, t2
	lc	ct0, 0(ca6)
	add	ca6, ca6, CSZREG
	sll	t1, t0, t3
	or	t1, t1, t6
	srl	t6, t0, t2
	gchi	t0, ct0
	sll	t5, t0, t3
	or	t5, t5, t6
	schi	ct1, ct1, t5
	sc	ct1, 0(ca3)
	add	ca3, ca3, CSZREG
	bltu	a3, a5, 1b

	sub	t4, a3, t4
	add	ca1, ca1, t4
	bltu	a3, a4, .Ltail_byte_copy_forward
	ret

	/*
	 * When accessing a memory address that is misaligned to the CLEN but
	 * aligned to the XLEN, XLEN-aligned load/store instructions can
	 * directly access the leading and trailing XLEN-sized chunks
	 * encompassing the misaligned data, thereby avoiding the use of lc and
	 * sc instructions for redundant data access.
	 */
.Lcap_misaligned_word_aligned_copy_forward:
	addi	a5, a4, -(SZREG+CSZREG-1)
	bgeu	a3, a5, .Ltail_byte_copy_forward

	mv	ca6, ca1
	mv	t4, a3

	REG_L	t0, 0(ca6)
	add	ca6, ca6, SZREG
	lc	ct1, 0(ca6)
	add	ca6, ca6, CSZREG
	schi	ct0, ct0, t1
	sc	ct0, 0(ca3)
	add	ca3, ca3, CSZREG
	bgeu	a3, a5, 2f
1:
	gchi	t0, ct1
	lc	ct1, 0(ca6)
	add	ca6, ca6, CSZREG
	schi	ct0, ct0, t1
	sc	ct0, 0(ca3)
	add	ca3, ca3, CSZREG
	bltu	a3, a5, 1b
2:
	gchi	t1, ct1
	REG_S	t1, 0(ca3)
	add	ca3, ca3, SZREG

	sub	t4, a3, t4
	add	ca1, ca1, t4
	bltu	a3, a4, .Ltail_byte_copy_forward
	ret
SYM_FUNC_END(__memcpy)
SYM_FUNC_ALIAS_WEAK(memcpy, __memcpy)
SYM_FUNC_ALIAS(__pi_memcpy, __memcpy)
SYM_FUNC_ALIAS(__pi___memcpy, __memcpy)
SYM_FUNC_ALIAS(__memcpy_cheri, __memcpy)
