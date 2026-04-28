/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2025 Codasip GmbH.
 */

#include <linux/linkage.h>
#include <linux/export.h>
#include <asm/asm.h>
#include <asm/asm-extable.h>
#include <asm/csr.h>
#include <asm/hwcap.h>
#include <asm/alternative-macros.h>
#include <asm/cheri.h>

	.macro fixup op reg addr lbl
100:
	\op \reg, \addr
	_asm_extable	100b, \lbl
	.endm

#ifdef CONFIG_RISCV_CHERI_DEBUG_USER_COPY
/*
 * Special calling conventions:
 * - CSR_SSTATUS.SUM is already enabled.
 * - Preserve ca0, ca1 and ca2
 * - Additionally preserv ct6 as this is used by the caller
 *   to store its return address.
 * Avoid use of the stack unless we have to issue a warning.
 */
SYM_FUNC_START(__cheri_check_tags)
	/* Calculate limit */
	add t2, a1, a2
	addi t2, t2, -CSZREG

	/* Align address to capability boundary*/
	addi t1, a1, CSZREG-1
	andi t1, t1, ~(CSZREG-1)
	scaddr ct1, ca1, t1

	/* Loop */
.Lcheck_tags_loop:
	bgt t1, t2, .Lcheck_tags_loop_done
	fixup lc ct0, (ct1), .Lcheck_tags_loop_done
	gctag t0, ct0
	bnez t0, .Lwarn_tags
	caddi ct1, ct1, CSZREG
	j .Lcheck_tags_loop
.Lcheck_tags_loop_done:

	/* Success */
	ret

.Lwarn_tags:
	caddi csp, csp, -4*CSZREG
	sc ca0, (csp)
	sc ca1, CSZREG(csp)
	sc ca2, 2*CSZREG(csp)
	sc cra, 3*CSZREG(csp)
	sc ct6, 4*CSZREG(csp)
	mv ca3, ct1
	call do_warn_tags
	lc ca0, (csp)
	lc ca1, CSZREG(csp)
	lc ca2, 2*CSZREG(csp)
	lc cra, 3*CSZREG(csp)
	lc ct6, 4*CSZREG(csp)
	caddi csp, csp, 4*CSZREG
	ret
SYM_FUNC_END(__cheri_check_tags)
#endif

/*
 * NOTE: Must preserve ct6 because fallback_scalar_usercopy saves its
 * return address there.
 */
SYM_FUNC_START(__cheri_usercopy_sum_enabled)
	beqz	a2, .Lexit_copy_user
	add	a4, a0, a2

	/*
	 * Clear the C permission on ca1 (*from). The data loaded via ca1 will
	 * have its tag bit unset, preventing tagged capability
	 * from inadvertently propagating into user space, which could lead to
	 * security vulnerabilities.
	 */
	li	a2, ~CHERI_PERM_CAP_RW
	acperm	ca1, ca1, a2

.Lbyte_copy_until_dest_aligned_forward:
	andi	t0, a0, CSZREG-1
	beqz	t0, 2f
1:
	fixup lbu	t0, 0(ca1), .Lexception_fixup
	fixup sb	t0, 0(ca0), .Lexception_fixup
	add	ca1, ca1, 1
	add	ca0, ca0, 1
	beq	a0, a4, .Lexit_copy_user
	andi	t0, a0, CSZREG-1
	bnez	t0, 1b
2:
	addi	a5, a4, -(CSZREG-1)
	bgeu	a0, a5, .Ltail_byte_copy_forward

	andi	t0, a1, CSZREG-1
	bnez	t0, .Lmisaligned_fixup_copy_forward

.Lcap_aligned_bulk_copy_forward:
	addi	a5, a4, -(8*CSZREG-1)
	bgeu	a0, a5, .Lcap_aligned_copy_forward
1:
	fixup lc	ct0, 0*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ct1, 1*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ct2, 2*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ct3, 3*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ct4, 4*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ct5, 5*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ca3, 6*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup lc	ca6, 7*CSZREG(ca1), .Ltail_byte_copy_forward
	fixup sc	ct0, 0*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ct1, 1*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ct2, 2*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ct3, 3*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ct4, 4*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ct5, 5*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ca3, 6*CSZREG(ca0), .Ltail_byte_copy_forward
	fixup sc	ca6, 7*CSZREG(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, 8*CSZREG
	add	ca0, ca0, 8*CSZREG
	bltu	a0, a5, 1b

	beq	a0, a4, .Lexit_copy_user

.Lcap_aligned_copy_forward:

	addi	a5, a4, -(CSZREG-1)
#ifdef	CONFIG_64BIT
	bgeu	a0, a5, .Ltail_double_word_aligned_copy_forward
#else
	bgeu	a0, a5, .Ltail_word_aligned_copy_forward
#endif
1:
	fixup lc	ct0, 0(ca1), .Ltail_byte_copy_forward
	fixup sc	ct0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, CSZREG
	add	ca0, ca0, CSZREG
	bltu	a0, a5, 1b

	beq	a0, a4, .Lexit_copy_user

#ifdef	CONFIG_64BIT
.Ltail_double_word_aligned_copy_forward:
	addi	a5, a4, -(8-1)
	bgeu	a0, a5, .Ltail_word_aligned_copy_forward
1:
	fixup ld	t0, 0(ca1), .Ltail_byte_copy_forward
	fixup sd	t0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, 8
	add	ca0, ca0, 8

	beq	a0, a4, .Lexit_copy_user
#endif

.Ltail_word_aligned_copy_forward:
	addi	a5, a4, -(4-1)
	bgeu	a0, a5, .Ltail_half_word_aligned_copy_forward
1:
	fixup lw	t0, 0(ca1), .Ltail_byte_copy_forward
	fixup sw	t0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, 4
	add	ca0, ca0, 4

	beq	a0, a4, .Lexit_copy_user

.Ltail_half_word_aligned_copy_forward:
	addi	a5, a4, -(2-1)
	bgeu	a0, a5, .Ltail_byte_copy_forward
1:
	fixup lhu	t0, 0(ca1), .Ltail_byte_copy_forward
	fixup sh	t0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, 2
	add	ca0, ca0, 2

	beq	a0, a4, .Lexit_copy_user

.Ltail_byte_copy_forward:
	fixup lbu	t0, 0(ca1), .Lexception_fixup
	fixup sb	t0, 0(ca0), .Lexception_fixup
	add	ca1, ca1, 1
	add	ca0, ca0, 1
	bne	a0, a4, .Ltail_byte_copy_forward

.Lexit_copy_user:
	li	a0, 0
	ret

	/* Exception fixup code */
.Lexception_fixup:
	/* Disable access to user memory */
	sub	a0, a4, a0
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
	bgeu	a0, a5, .Ltail_byte_copy_forward

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
	fixup lbu	t1, 0(ca6), .Ltail_byte_copy_forward
	sll	t1, t1, t3
	or	t0, t0, t1
	add	ca6, ca6, 1
	addi	t3, t3, 8
	andi	a3, a6, SZREG-1
	bnez	a3, 1b

	schi	ct0, ct0, t0
	bnez	t4, .Lmisaligned_fixup_shift_cap_hi

	fixup REG_L	t1, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, SZREG
	schi	ct0, ct0, t1
	j	.Lmisaligned_fixup_shift_cap_low

2:
	scaddr	ca6, ca6, t5
	fixup lc	ct0, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, CSZREG
	bnez	t4, .Lmisaligned_fixup_shift_cap_hi

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
.Lmisaligned_fixup_shift_cap_low:
	neg	t3, t2
1:
	srl	a3, t0, t2
	gchi	t0, ct0
	sll	t1, t0, t3
	or	t1, t1, a3
	srl	a3, t0, t2
	fixup lc	ct0, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, CSZREG
	sll	t5, t0, t3
	or	t5, t5, a3
	schi	ct1, ct1, t5
	fixup sc	ct1, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, CSZREG
	add	ca0, ca0, CSZREG
	bltu	a0, a5, 1b

	bltu	a0, a4, .Ltail_byte_copy_forward
	j	.Lexit_copy_user

.Lmisaligned_fixup_shift_cap_hi:
	neg	t3, t2
	gchi	t0, ct0
1:
	srl	a3, t0, t2
	fixup lc	ct0, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, CSZREG
	sll	t1, t0, t3
	or	t1, t1, a3
	srl	a3, t0, t2
	gchi	t0, ct0
	sll	t5, t0, t3
	or	t5, t5, a3
	schi	ct1, ct1, t5
	fixup sc	ct1, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, CSZREG
	add	ca0, ca0, CSZREG
	bltu	a0, a5, 1b

	bltu	a0, a4, .Ltail_byte_copy_forward
	j	.Lexit_copy_user

	/*
	 * When accessing a memory address that is misaligned to the CLEN but
	 * aligned to the XLEN, XLEN-aligned load/store instructions can
	 * directly access the leading and trailing XLEN-sized chunks
	 * encompassing the misaligned data, thereby avoiding the use of lc and
	 * sc instructions for redundant data access.
	 */
.Lcap_misaligned_word_aligned_copy_forward:
	addi	a5, a4, -(SZREG+CSZREG-1)
	bgeu	a0, a5, .Ltail_byte_copy_forward

	mv	ca6, ca1

	fixup REG_L	t0, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, SZREG
	fixup lc	ct1, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, CSZREG
	schi	ct0, ct0, t1
	fixup sc	ct0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, CSZREG
	add	ca0, ca0, CSZREG
	bgeu	a0, a5, 2f
1:
	gchi	t0, ct1
	fixup lc	ct1, 0(ca6), .Ltail_byte_copy_forward
	add	ca6, ca6, CSZREG
	schi	ct0, ct0, t1
	fixup sc	ct0, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, CSZREG
	add	ca0, ca0, CSZREG
	bltu	a0, a5, 1b
2:
	gchi	t1, ct1
	fixup REG_S	t1, 0(ca0), .Ltail_byte_copy_forward
	add	ca1, ca1, SZREG
	add	ca0, ca0, SZREG

	bltu	a0, a4, .Ltail_byte_copy_forward
	j	.Lexit_copy_user
SYM_FUNC_END(__cheri_usercopy_sum_enabled)
