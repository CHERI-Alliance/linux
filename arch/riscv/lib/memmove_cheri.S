/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2025 Codasip GmbH.
 */

#include <linux/linkage.h>
#include <asm/asm.h>

/* void *memmove(void *, const void *, size_t) */
SYM_FUNC_START(__memmove)
	beqz	a2, .Lreturn_from_memmove_reverse
	beq	a0, a1, .Lreturn_from_memmove_reverse

	sub	t0, a0, a1
	bltu	t0, a2, .Lmemmove_reverse
	/*
	 * Handle forward memmove with CHERI version memcpy
	 */
	tail	__memcpy_cheri

.Lmemmove_reverse:
	mv	a4, a0
	add	ca3, ca0, a2
	add	ca1, ca1, a2

.Lbyte_copy_until_dest_aligned_reverse:
	andi	t0, a3, CSZREG-1
	beqz	t0, 2f
1:
	add	ca1, ca1, -1
	add	ca3, ca3, -1
	lbu	t1, 0(ca1)
	sb	t1, 0(ca3)
	beq	a3, a4, .Lreturn_from_memmove_reverse
	andi	t0, a3, CSZREG-1
	bnez	t0, 1b
2:
	addi	a5, a4, CSZREG-1
	bleu	a3, a5, .Ltail_byte_copy_reverse

	andi	t0, a1, CSZREG-1
	bnez	t0, .Lmisaligned_fixup_copy_reverse

.Lcap_aligned_bulk_copy_reverse:
	addi	a5, a4, 8*CSZREG-1
	bleu	a3, a5, .Lcap_aligned_copy_reverse
1:
	add	ca1, ca1, -(8*CSZREG)
	add	ca3, ca3, -(8*CSZREG)
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
	bgtu	a3, a5, 1b

	beq	a3, a4, .Lreturn_from_memmove_reverse

.Lcap_aligned_copy_reverse:

	addi	a5, a4, CSZREG-1
#ifdef	CONFIG_64BIT
	bleu	a3, a5, .Ltail_double_word_aligned_copy_reverse
#else
	bleu	a3, a5, .Ltail_word_aligned_copy_reverse
#endif
1:
	add	ca1, ca1, -CSZREG
	add	ca3, ca3, -CSZREG
	lc	ct0, 0(ca1)
	sc	ct0, 0(ca3)
	bgtu	a3, a5, 1b

	beq	a3, a4, .Lreturn_from_memmove_reverse

#ifdef	CONFIG_64BIT
.Ltail_double_word_aligned_copy_reverse:
	addi	a5, a4, 8-1
	bleu	a3, a5, .Ltail_word_aligned_copy_reverse

	add	ca1, ca1, -8
	add	ca3, ca3, -8
	ld	t0, 0(ca1)
	sd	t0, 0(ca3)

	beq	a3, a4, .Lreturn_from_memmove_reverse
#endif

.Ltail_word_aligned_copy_reverse:
	addi	a5, a4, 4-1
	bleu	a3, a5, .Ltail_half_word_aligned_copy_reverse

	add	ca1, ca1, -4
	add	ca3, ca3, -4
	lw	t0, 0(ca1)
	sw	t0, 0(ca3)

	beq	a3, a4, .Lreturn_from_memmove_reverse

.Ltail_half_word_aligned_copy_reverse:

	addi	a5, a4, 2-1
	bleu	a3, a5, .Ltail_byte_copy_reverse

	add	ca1, ca1, -2
	add	ca3, ca3, -2
	lhu	t0, 0(ca1)
	sh	t0, 0(ca3)

	bleu	a3, a4, .Lreturn_from_memmove_reverse

.Ltail_byte_copy_reverse:
	add	ca1, ca1, -1
	add	ca3, ca3, -1
	lbu	t0, 0(ca1)
	sb	t0, 0(ca3)
	bne	a3, a4, .Ltail_byte_copy_reverse

.Lreturn_from_memmove_reverse:
	ret

	/*
	 * Optimize misaligned memory copies by using aligned CLEN read/write
	 * instructions. This technique avoids slower unaligned access by
	 * effectively shifting the read data based on the source-destination
	 * address offset to enable aligned CLEN operations.
	 */
.Lmisaligned_fixup_copy_reverse:
	andi	t0, a1, SZREG-1
	beqz	t0, .Lcap_misaligned_word_aligned_copy_reverse

	addi	a5, a4, 2*CSZREG-1
	bleu	a3, a5, .Ltail_byte_copy_reverse

	andi	t2, a1, SZREG-1
	slli	t2, t2, 3
	andi	t4, a1, CSZREG-1
	srli	t4, t4, LGREG
	schi	ct4, ct4, t0

	mv	ca6, ca1
	andi	t5, a6, ~(CSZREG-1)
	gcbase	t0, ca6
	gclen	t1, ca6
	add	t6, t0, t1
	addi	t1, t5, CSZREG
	bgeu	t6, t1, 2f

	/*
	 * Copy data byte by byte up to the next CLEN-aligned address to
	 * prevent CHERI violations from out-of-bounds accesses on shifted
	 * source capabilities.
	 */
	li	t0, 0
	mv	t3, t2
1:
	add	ca6, ca6, -1
	addi	t3, t3, -8
	lbu	t1, 0(ca6)
	sll	t1, t1, t3
	or	t0, t0, t1
	andi	t6, a6, SZREG-1
	bnez	t6, 1b

	beqz	t4, .Lmisaligned_fixup_shift_cap_low_reverse

	add	ca6, ca6, -SZREG
	REG_L	t1, 0(ca6)
	schi	ct1, ct1, t0
	mv	ct0, ct1
	j	.Lmisaligned_fixup_shift_cap_hi_reverse
2:
	scaddr	ca6, ca6, t5
	lc	ct0, 0(ca6)
	bnez	t4, .Lmisaligned_fixup_shift_cap_hi_reverse

	/*
	 * Since capability width shift and logical instructions are
	 * unavailable, we need two separate approaches to correctly shift data
	 * between capabilities: one for shifting data at lower capability, and
	 * one for shifting data at upper capability.
	 *
	 * Case 1:
	 * Fix Misalignment Copy Loop for shifting from lower capability
	 * load_aligned_val = *cap_aligned_load_ptr;
	 * do {
	 *	tmp = load_aligned_val.lower;
	 *
	 *	load_aligned_val = *--cap_aligned_load_ptr;
	 *
	 * 	store_aligned_val.lower = (tmp << {t3}) |
	 *				(load_aligned_val.upper << {t3});
	 *
	 * 	store_aligned_val.upper = (load_aligned_val.upper >> {t2}) |
	 *				(load_aligned_val.lower << {t3});
	 *
	 *	*--cap_aligned_store_ptr = store_aligned_val;
	 *
	 * } while (cap_aligned_store_ptr > {a5});
	 *
	 * Case 2:
	 * Fix Misalignment Copy Loop for shifting from upper capability
	 * load_aligned_val = *cap_aligned_load_ptr;
	 * do {
	 * 	store_aligned_val.lower = (load_aligned_val.lower << {t3}) |
	 *				(load_aligned_val.upper >> {t2});
	 *
	 *	tmp = load_aligned_val.upper;
	 *
	 *	load_aligned_val = *--cap_aligned_load_ptr;
	 *
	 * 	store_aligned_val.upper = (tmp << {t3}) |
	 *				(load_aligned_val.lower >> {t3});
	 *
	 *	*--cap_aligned_store_ptr = store_aligned_val;
	 *
	 * } while (cap_aligned_store_ptr > {a5});
	 */
.Lmisaligned_fixup_shift_cap_low_reverse:
	neg	t3, t2
	mv	t4, a3
1:
	sll	t6, t0, t3
	add	ca6, ca6, -CSZREG
	lc	ct0, 0(ca6)
	gchi	t1, ct0
	srl	t5, t1, t2
	or	t5, t5, t6
	sll	t6, t1, t3
	srl	t1, t0, t2
	or	t1, t1, t6
	schi	ct1, ct1, t5
	add	ca3, ca3, -CSZREG
	sc	ct1, 0(ca3)
	bgtu	a3, a5, 1b

	sub	t4, a3, t4
	add	ca1, ca1, t4

	bgtu	a3, a4, .Ltail_byte_copy_reverse
	ret

.Lmisaligned_fixup_shift_cap_hi_reverse:
	neg	t3, t2
	mv	t4, a3
1:
	gchi	t1, ct0
	sll	t6, t1, t3
	srl	t5, t0, t2
	or	t5, t5, t6
	mv	t6, t0
	add	ca6, ca6, -CSZREG
	lc	ct0, 0(ca6)
	gchi	t1, ct0
	sll	t6, t6, t3
	srl	t1, t1, t2
	or	t1, t1, t6
	schi	ct1, ct1, t5
	add	ca3, ca3, -CSZREG
	sc	ct1, 0(ca3)
	bgtu	a3, a5, 1b

	sub	t4, a3, t4
	add	ca1, ca1, t4
	bgtu	a3, a4, .Ltail_byte_copy_reverse
	ret

	/*
	 * When accessing a memory address that is misaligned to the CLEN but
	 * aligned to the XLEN, XLEN-aligned load/store instructions can
	 * directly access the leading and trailing XLEN-sized chunks
	 * encompassing the misaligned data, thereby avoiding the use of lc and
	 * sc instructions for redundant data access.
	 */
.Lcap_misaligned_word_aligned_copy_reverse:
	addi	a5, a4, SZREG+CSZREG-1
	bleu	a3, a5, .Ltail_byte_copy_reverse

	mv	ca6, ca1
	mv	t4, a3

	add	ca6, ca6, -SZREG
	REG_L	t2, 0(ca6)
	add	ca6, ca6, -CSZREG
	lc	ct1, 0(ca6)
	gchi	t0, ct1
	schi	ct0, ct0, t2
	add	ca3, ca3, -CSZREG
	sc	ct0, 0(ca3)

	bleu	a3, a5, 2f
1:
	mv	t2, t1
	add	ca6, ca6, -CSZREG
	lc	ct1, 0(ca6)
	gchi	t0, ct1
	schi	ct0, ct0, t2
	add	ca3, ca3, -CSZREG
	sc	ct0, 0(ca3)

	bgtu	a3, a5, 1b
2:
	add	ca3, ca3, -SZREG
	REG_S	t1, 0(ca3)

	sub	t4, a3, t4
	add	ca1, ca1, t4
	bgtu	a3, a4, .Ltail_byte_copy_reverse
	ret

SYM_FUNC_END(__memmove)
SYM_FUNC_ALIAS_WEAK(memmove, __memmove)
SYM_FUNC_ALIAS(__pi_memmove, __memmove)
SYM_FUNC_ALIAS(__pi___memmove, __memmove)

