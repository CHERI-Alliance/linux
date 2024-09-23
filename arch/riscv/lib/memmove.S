/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2022 Michael T. Kloos <michael@michaelkloos.com>
 */

#include <linux/linkage.h>
#include <asm/asm.h>

SYM_FUNC_START(__memmove)
	/*
	 * Returns
	 *   a0 - dest
	 *
	 * Parameters
	 *   a0 - Inclusive first byte of dest
	 *   a1 - Inclusive first byte of src
	 *   a2 - Length of copy n
	 *
	 * Because the return matches the parameter register a0,
	 * we will not clobber or modify that register.
	 *
	 * Note: This currently only works on little-endian.
	 * To port to big-endian, reverse the direction of shifts
	 * in the 2 misaligned fixup copy loops.
	 */

	/* Return if nothing to do */
	beq a0, a1, .Lreturn_from_memmove
	beqz a2, .Lreturn_from_memmove

#ifdef CONFIG_CHERI_KERNEL
	andi t0, a0, CSZREG-1
	andi t1, a1, CSZREG-1
	bne t0, t1, .Lnormal

	bleu a0, a1, .Lcapfwd

	cadd ca0, ca0, a2
	cadd ca1, ca1, a2

.Lcapback:
	beqz a2, .Lreturn_from_memmove
	andi t0, a0, CSZREG-1
	beqz t0, .Lcapback_aligned
	caddi ca0, ca0, -1
	caddi ca1, ca1, -1
	addi a2, a2, -1
	lbu t0, (ca1)
	sb t0, (ca0)
	j .Lcapback

.Lcapback_aligned:
	andi t1, a2, -CSZREG
	beqz t1, .Lcapback_tail
	caddi ca0, ca0, -CSZREG
	caddi ca1, ca1,  -CSZREG
	addi a2, a2, -CSZREG
	lc ct0, (ca1)
	sc ct0, (ca0)
	j .Lcapback_aligned

.Lcapback_tail:
	beqz a2, .Lreturn_from_memmove
	caddi ca0, ca0, -1
	caddi ca1, ca1, -1
	addi a2, a2, -1
	lbu t0, (ca1)
	sb t0, (ca0)
	j .Lcapback_tail

.Lcapfwd:
	beqz a2, .Lreturn_from_memmove
	andi t0, a0, CSZREG-1
	beqz t0, .Lcapfwd_aligned
	lbu t0, (ca1)
	sb t0, (ca0)
	caddi ca0, ca0, 1
	caddi ca1, ca1, 1
	addi a2, a2, -1
	j .Lcapfwd

.Lcapfwd_aligned:
	andi t1, a2, -CSZREG
	beqz t1, .Lcapfwd_tail
	lc ct0, (ca1)
	sc ct0, (ca0)
	caddi ca0, ca0, CSZREG
	caddi ca1, ca1, CSZREG
	addi a2, a2, -CSZREG
	j .Lcapfwd_aligned

.Lcapfwd_tail:
	beqz a2, .Lreturn_from_memmove
	lbu t0, (ca1)
	sb t0, (ca0)
	caddi ca0, ca0, 1
	caddi ca1, ca1, 1
	addi a2, a2, -1
	j .Lcapfwd_tail

.Lnormal:
#endif /* CONFIG_CHERI_KERNEL */
	/*
	 * Register Uses
	 *      Forward Copy: a1 - Index counter of src
	 *      Reverse Copy: a4 - Index counter of src
	 *      Forward Copy: t3 - Index counter of dest
	 *      Reverse Copy: t4 - Index counter of dest
	 *   Both Copy Modes: t5 - Inclusive first multibyte/aligned of dest
	 *   Both Copy Modes: t6 - Non-Inclusive last multibyte/aligned of dest
	 *   Both Copy Modes: t0 - Link / Temporary for load-store
	 *   Both Copy Modes: t1 - Temporary for load-store
	 *   Both Copy Modes: t2 - Temporary for load-store
	 *   Both Copy Modes: a5 - dest to src alignment offset
	 *   Both Copy Modes: a6 - Shift ammount
	 *   Both Copy Modes: a7 - Inverse Shift ammount
	 *   Both Copy Modes: a2 - Alternate breakpoint for unrolled loops
	 */

	/*
	 * Solve for some register values now.
	 * Byte copy does not need t5 or t6.
	 */
	CREG(mv)  CREG(t3), CREG(a0)
	CREG(add) CREG(t4), CREG(a0), a2
	CREG(add) CREG(a4), CREG(a1), a2

	/*
	 * Byte copy if copying less than (2 * SZREG) bytes. This can
	 * cause problems with the bulk copy implementation and is
	 * small enough not to bother.
	 */
	andi t0, a2, -(2 * SZREG)
	beqz t0, .Lbyte_copy

	/*
	 * Now solve for t5 and t6.
	 */
#ifndef CONFIG_CHERI_KERNEL
	andi t5, t3, -SZREG
	andi t6, t4, -SZREG
#else
	andi t5, t3, SZREG-1
	neg t5, t5
	cadd ct5, ct3, t5
	andi t6, t4, SZREG-1
	neg t6, t6
	cadd ct6, ct4, t6
#endif

	/*
	 * If dest(Register t3) rounded down to the nearest naturally
	 * aligned SZREG address, does not equal dest, then add SZREG
	 * to find the low-bound of SZREG alignment in the dest memory
	 * region.  Note that this could overshoot the dest memory
	 * region if n is less than SZREG.  This is one reason why
	 * we always byte copy if n is less than SZREG.
	 * Otherwise, dest is already naturally aligned to SZREG.
	 */
	beq  t5, t3, 1f
		CREG(addi) CREG(t5), CREG(t5), SZREG
	1:

	/*
	 * If the dest and src are co-aligned to SZREG, then there is
	 * no need for the full rigmarole of a full misaligned fixup copy.
	 * Instead, do a simpler co-aligned copy.
	 */
	xor  t0, a0, a1
	andi t1, t0, (SZREG - 1)
	beqz t1, .Lcoaligned_copy
	/* Fall through to misaligned fixup copy */

#ifdef CONFIG_CHERI_KERNEL
	/*
	 * FIXCHERI: The code for misaligned copy reads data before
	 * the start of the copy region. Disable it for now.
	 */
	j .Lbyte_copy
#endif

.Lmisaligned_fixup_copy:
	bltu a1, a0, .Lmisaligned_fixup_copy_reverse

.Lmisaligned_fixup_copy_forward:
	jal  CREG(t0), .Lbyte_copy_until_aligned_forward

	andi a5, a1, (SZREG - 1) /* Find the alignment offset of src (a1) */
	slli a6, a5, 3 /* Multiply by 8 to convert that to bits to shift */
	sub  a5, a1, t3 /* Find the difference between src and dest */
#ifndef CONFIG_CHERI_KERNEL
	andi a1, a1, -SZREG /* Align the src pointer */
	addi a2, t6, SZREG /* The other breakpoint for the unrolled loop*/
#else
	andi a7, a1, SZREG-1
	neg a7, a7
	cadd ca1, ca1, a7 /* Align the src pointer */
	caddi ca2, ct6, SZREG /* The other breakpoint for the unrolled loop*/
#endif

	/*
	 * Compute The Inverse Shift
	 * a7 = XLEN - a6 = XLEN + -a6
	 * 2s complement negation to find the negative: -a6 = ~a6 + 1
	 * Add that to XLEN.  XLEN = SZREG * 8.
	 */
	not  a7, a6
	addi a7, a7, (SZREG * 8 + 1)

	/*
	 * Fix Misalignment Copy Loop - Forward
	 * load_val0 = load_ptr[0];
	 * do {
	 * 	load_val1 = load_ptr[1];
	 * 	store_ptr += 2;
	 * 	store_ptr[0 - 2] = (load_val0 >> {a6}) | (load_val1 << {a7});
	 *
	 * 	if (store_ptr == {a2})
	 * 		break;
	 *
	 * 	load_val0 = load_ptr[2];
	 * 	load_ptr += 2;
	 * 	store_ptr[1 - 2] = (load_val1 >> {a6}) | (load_val0 << {a7});
	 *
	 * } while (store_ptr != store_ptr_end);
	 * store_ptr = store_ptr_end;
	 */

	REG_L t0, (0 * SZREG)(CREG(a1))
	1:
	REG_L t1, (1 * SZREG)(CREG(a1))
	CREG(addi)  CREG(t3), CREG(t3), (2 * SZREG)
	srl   t0, t0, a6
	sll   t2, t1, a7
	or    t2, t0, t2
	REG_S t2, ((0 * SZREG) - (2 * SZREG))(CREG(t3))

	beq   t3, a2, 2f

	REG_L t0, (2 * SZREG)(CREG(a1))
	CREG(addi)  CREG(a1), CREG(a1), (2 * SZREG)
	srl   t1, t1, a6
	sll   t2, t0, a7
	or    t2, t1, t2
	REG_S t2, ((1 * SZREG) - (2 * SZREG))(CREG(t3))

	bne   t3, t6, 1b
	2:
	CREG(mv)   CREG(t3), CREG(t6) /* Fix the dest pointer in case the loop was broken */

	CREG(add)  CREG(a1), CREG(t3), a5 /* Restore the src pointer */
	j .Lbyte_copy_forward /* Copy any remaining bytes */

.Lmisaligned_fixup_copy_reverse:
	jal  CREG(t0), .Lbyte_copy_until_aligned_reverse

	andi a5, a4, (SZREG - 1) /* Find the alignment offset of src (a4) */
	slli a6, a5, 3 /* Multiply by 8 to convert that to bits to shift */
	sub  a5, a4, t4 /* Find the difference between src and dest */
#ifndef CONFIG_CHERI_KERNEL
	andi a4, a4, -SZREG /* Align the src pointer */
	addi a2, t5, -SZREG /* The other breakpoint for the unrolled loop*/
#else
	andi a7, a4, SZREG-1
	neg a7, a7
	cadd ca4, ca4, a7 /* Align the src pointer */
	andi a7, t5, SZREG-1
	neg a7, a7
	cadd ca2, ct5, a7 /* The other breakpoint for the unrolled loop*/
#endif

	/*
	 * Compute The Inverse Shift
	 * a7 = XLEN - a6 = XLEN + -a6
	 * 2s complement negation to find the negative: -a6 = ~a6 + 1
	 * Add that to XLEN.  XLEN = SZREG * 8.
	 */
	not  a7, a6
	addi a7, a7, (SZREG * 8 + 1)

	/*
	 * Fix Misalignment Copy Loop - Reverse
	 * load_val1 = load_ptr[0];
	 * do {
	 * 	load_val0 = load_ptr[-1];
	 * 	store_ptr -= 2;
	 * 	store_ptr[1] = (load_val0 >> {a6}) | (load_val1 << {a7});
	 *
	 * 	if (store_ptr == {a2})
	 * 		break;
	 *
	 * 	load_val1 = load_ptr[-2];
	 * 	load_ptr -= 2;
	 * 	store_ptr[0] = (load_val1 >> {a6}) | (load_val0 << {a7});
	 *
	 * } while (store_ptr != store_ptr_end);
	 * store_ptr = store_ptr_end;
	 */

	REG_L t1, ( 0 * SZREG)(CREG(a4))
	1:
	REG_L t0, (-1 * SZREG)(CREG(a4))
	CREG(addi) CREG(t4), CREG(t4), (-2 * SZREG)
	sll   t1, t1, a7
	srl   t2, t0, a6
	or    t2, t1, t2
	REG_S t2, ( 1 * SZREG)(CREG(t4))

	beq   t4, a2, 2f

	REG_L t1, (-2 * SZREG)(CREG(a4))
	CREG(addi)  CREG(a4), CREG(a4), (-2 * SZREG)
	sll   t0, t0, a7
	srl   t2, t1, a6
	or    t2, t0, t2
	REG_S t2, ( 0 * SZREG)(CREG(t4))

	bne   t4, t5, 1b
	2:
	CREG(mv)    CREG(t4), CREG(t5) /* Fix the dest pointer in case the loop was broken */

	CREG(add)  CREG(a4), CREG(t4), a5 /* Restore the src pointer */
	j .Lbyte_copy_reverse /* Copy any remaining bytes */

/*
 * Simple copy loops for SZREG co-aligned memory locations.
 * These also make calls to do byte copies for any unaligned
 * data at their terminations.
 */
.Lcoaligned_copy:
	bltu a1, a0, .Lcoaligned_copy_reverse

.Lcoaligned_copy_forward:
	jal CREG(t0), .Lbyte_copy_until_aligned_forward

	1:
	REG_L t1, ( 0 * SZREG)(CREG(a1))
	CREG(addi) CREG(a1), CREG(a1), SZREG
	CREG(addi) CREG(t3), CREG(t3), SZREG
	REG_S t1, (-1 * SZREG)(CREG(t3))
	bne   t3, t6, 1b

	j .Lbyte_copy_forward /* Copy any remaining bytes */

.Lcoaligned_copy_reverse:
	jal CREG(t0), .Lbyte_copy_until_aligned_reverse

	1:
	REG_L t1, (-1 * SZREG)(CREG(a4))
	CREG(addi) CREG(a4), CREG(a4), -SZREG
	CREG(addi) CREG(t4), CREG(t4), -SZREG
	REG_S t1, ( 0 * SZREG)(CREG(t4))
	bne   t4, t5, 1b

	j .Lbyte_copy_reverse /* Copy any remaining bytes */

/*
 * These are basically sub-functions within the function.  They
 * are used to byte copy until the dest pointer is in alignment.
 * At which point, a bulk copy method can be used by the
 * calling code.  These work on the same registers as the bulk
 * copy loops.  Therefore, the register values can be picked
 * up from where they were left and we avoid code duplication
 * without any overhead except the call in and return jumps.
 */
.Lbyte_copy_until_aligned_forward:
	beq  t3, t5, 2f
	1:
	lb   t1,  0(CREG(a1))
	CREG(addi) CREG(a1), CREG(a1), 1
	CREG(addi) CREG(t3), CREG(t3), 1
	sb   t1, -1(CREG(t3))
	bne  t3, t5, 1b
	2:
	jr CREG(t0) /* Return to multibyte copy loop */

.Lbyte_copy_until_aligned_reverse:
	beq  t4, t6, 2f
	1:
	lb   t1, -1(CREG(a4))
	CREG(addi) CREG(a4), CREG(a4), -1
	CREG(addi) CREG(t4), CREG(t4), -1
	sb   t1,  0(CREG(t4))
	bne  t4, t6, 1b
	2:
	jr CREG(t0) /* Return to multibyte copy loop */

/*
 * Simple byte copy loops.
 * These will byte copy until they reach the end of data to copy.
 * At that point, they will call to return from memmove.
 */
.Lbyte_copy:
	bltu a1, a0, .Lbyte_copy_reverse

.Lbyte_copy_forward:
	beq  t3, t4, 2f
	1:
	lb   t1,  0(CREG(a1))
	CREG(addi) CREG(a1), CREG(a1), 1
	CREG(addi) CREG(t3), CREG(t3), 1
	sb   t1, -1(CREG(t3))
	bne  t3, t4, 1b
	2:
	ret

.Lbyte_copy_reverse:
	beq  t4, t3, 2f
	1:
	lb   t1, -1(CREG(a4))
	CREG(addi) CREG(a4), CREG(a4), -1
	CREG(addi) CREG(t4), CREG(t4), -1
	sb   t1,  0(CREG(t4))
	bne  t4, t3, 1b
	2:

.Lreturn_from_memmove:
	ret

SYM_FUNC_END(__memmove)
SYM_FUNC_ALIAS_WEAK(memmove, __memmove)
SYM_FUNC_ALIAS(__pi_memmove, __memmove)
SYM_FUNC_ALIAS(__pi___memmove, __memmove)

#ifdef CONFIG_CHERI_KERNEL
SYM_FUNC_ALIAS_WEAK(memcpy, __memmove)
SYM_FUNC_ALIAS(__pi_memcpy, __memmove)
SYM_FUNC_ALIAS(__pi___memcpy, __memmove)
#endif
