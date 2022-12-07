/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 *
 * TODO: most of the functions in this file should be reimplemented in C to
 * improve readability.
 */

#include <linux/linkage.h>

#include <asm/asm-uaccess.h>
#include <asm/assembler.h>
#include <asm/morello.h>
#include <asm/sysreg.h>

SYM_FUNC_START(morello_cap_get_val_tag)
	gctag	x3, c0
	clrtag	c0, c0			// Store the 128-bit value without the tag
	str	c0, [x1]
	strb	w3, [x2]

	ret
SYM_FUNC_END(morello_cap_get_val_tag)

SYM_FUNC_START(morello_build_any_user_cap)
	ldr	c0, [x0]
	cbz	w1, 1f
	/*
	 * The tag should be set, build a valid capability from the root
	 * capability.
	 * In case c0 is sealed (non-zero object type), we need to extract the
	 * object type first to be able to reseal it after BUILD. The CSEAL
	 * instruction is used to cover the case where c0 was not sealed.
	 */
	adr_l	x3, cheri_user_root_allperms_cap
	ldr	c3, [x3]

	cpytype	c4, c3, c0
	build	c0, c0, c3
	cseal	c0, c0, c4
	b	2f
1:
	/* The tag should be cleared, make sure it is. */
	clrtag	c0, c0
2:
	ret
SYM_FUNC_END(morello_build_any_user_cap)

SYM_FUNC_START(morello_capcpy)
	mov	x3, x0
	and	x4, x2, #0x10		// Bytes to reach 32-byte alignment (0 or 16)
	subs	x5, x2, x4		// 32-byte aligned length
	b.eq	2f
1:
	ldp	c6, c7, [x1], #32	// 32-byte loop
	stp	c6, c7, [x3], #32
	subs	x5, x5, #32
	b.ne	1b
2:
	cbz	x4, 3f			// 16-byte leftover (if any)
	ldr	c6, [x1], #16
	str	c6, [x3], #16
3:
	ret
SYM_FUNC_END(morello_capcpy)

SYM_FUNC_START(__morello_thread_init_user)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/*
	 * CTPIDR doesn't need to be initialised explicitly:
	 * - tls_thread_flush() already zeroes tpidr_el0, zeroing ctpidr_el0 as
	 *   well
	 * - The value stored in thread.morello_user_state will be set the next
	 *   time task_save_user_tls() is called, like thread_struct.uw.tp_value.
	 *
	 * tls_thread_flush() does not touch rcsp_el0, so we need to zero it
	 * here, but its value in morello_user_state does not need to be
	 * initialised here either.
	 */
	msr	rctpidr_el0, czr

	/* DDC: initialised to the specified value */
	msr	ddc_el0, c1
	/* RDDC: null capability (processes are always started in Executive) */
	msr	rddc_el0, czr
	stp	c1, czr, [x0, #MORELLO_STATE_DDC]
	/* CID: null capability */
	msr	cid_el0, czr
	str	czr, [x0, #MORELLO_STATE_CID]
	/* CCTLR: all bits cleared */
	msr	cctlr_el0, xzr
	str	xzr, [x0, #MORELLO_STATE_CCTLR]

	ret
SYM_FUNC_END(__morello_thread_init_user)

SYM_FUNC_START(morello_thread_save_user_state)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* (R)CTPIDR is handled by task_save_user_tls */
	mrs	c1, ddc_el0
	mrs	c2, rddc_el0
	stp	c1, c2, [x0, #MORELLO_STATE_DDC]
	mrs	c1, cid_el0
	str	c1, [x0, #MORELLO_STATE_CID]
	mrs	x1, cctlr_el0
	str	x1, [x0, #MORELLO_STATE_CCTLR]

	ret
SYM_FUNC_END(morello_thread_save_user_state)

SYM_FUNC_START(morello_thread_restore_user_state)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* (R)CTPIDR is handled by task_restore_user_tls */
	ldp	c1, c2, [x0, #MORELLO_STATE_DDC]
	msr	ddc_el0, c1
	msr	rddc_el0, c2
	ldr	c1, [x0, #MORELLO_STATE_CID]
	msr	cid_el0, c1
	ldr	x1, [x0, #MORELLO_STATE_CCTLR]
	msr	cctlr_el0, x1

	ret
SYM_FUNC_END(morello_thread_restore_user_state)

SYM_FUNC_START(morello_task_save_user_tls)
	get_task_pt_regs x8, x0
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	mrs	c2, ctpidr_el0
	mrs	c3, rctpidr_el0
	/* Save CTPIDR and RCTPIDR */
	stp	c2, c3, [x0, #MORELLO_STATE_CTPIDR]

	ldr	c5, [x8, #S_PCC]
	/*
	 * If the task is currently running in Restricted, save the lower 64 bits
	 * of RCTPIDR (RTPIDR) in tsk->thread instead of TPIDR.
	 */
	morello_tst_cap_has_executive c5, x6	// Task running in Executive?
#ifdef CONFIG_CHERI_PURECAP_UABI
	csel	c2, c2, c3, ne			// If not, save RTPIDR
	str	c2, [x1]
#else
	csel	x2, x2, x3, ne			// If not, save RTPIDR
	str	x2, [x1]
#endif
	ret
SYM_FUNC_END(morello_task_save_user_tls)

SYM_FUNC_START(morello_task_restore_user_tls)
	get_task_pt_regs x8, x0
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* Load CTPIDR, RCTPIDR and the 64-bit TLS pointer */
	ldp	c2, c3, [x0, #MORELLO_STATE_CTPIDR]
#ifdef CONFIG_CHERI_PURECAP_UABI
	ldr	c4, [x1]
#else
	ldr	x4, [x1]
#endif

	/*
	 * The 64-bit TLS pointer may have been modified from within the kernel
	 * (e.g. through ptrace) since morello_task_save_user_tls was called.
	 * Merge it back into the active capability TLS pointer, that is RCTPIDR
	 * if the task is running in Restricted and CTPIDR otherwise.
	 */
	ldr	c5, [x8, #S_PCC]
	morello_tst_cap_has_executive c5, x6	// Task running in Executive?
	b.eq	1f				// If not, merge into RCTPIDR
#ifdef CONFIG_CHERI_PURECAP_UABI
	mov	c2, c4				// Save the TLS pointer into CTPIDR
#else
	morello_merge_c_x 2, x4			// Merge the TLS pointer into CTPIDR
#endif
	b	2f
1:
#ifdef CONFIG_CHERI_PURECAP_UABI
	mov	c3, c4 				// Save the TLS pointer into RCTPIDR
#else
	morello_merge_c_x 3, x4			// Merge the TLS pointer into RCTPIDR
#endif
2:
	msr	ctpidr_el0, c2
	msr	rctpidr_el0, c3

	ret
SYM_FUNC_END(morello_task_restore_user_tls)

SYM_FUNC_START(__morello_get_user_cap_asm)
	user_ldst 1f, ldtr, c3, x1, 0
	str	c3, [x0]
	ret

	// Exception fixups
1:	mov	w3, #-EFAULT
	str	w3, [x2]
	str	czr, [x0]
	ret
SYM_FUNC_END(__morello_get_user_cap_asm)

SYM_FUNC_START(__morello_put_user_cap_asm)
	ldr	c3, [x0]
	user_ldst 1f, sttr, c3, x1, 0
	ret

	// Exception fixups
1:	mov	w3, #-EFAULT
	str	w3, [x2]
	ret
SYM_FUNC_END(__morello_put_user_cap_asm)


SYM_FUNC_START(__morello_cap_lo_hi_tag)
	str	x0, [x1]
	cfhi	x4, c0			// Extract upper 64 bits
	str	x4, [x2]
	gctag	x4, c0
	strb	w4, [x3]

	ret
SYM_FUNC_END(__morello_cap_lo_hi_tag)

SYM_FUNC_START(__morello_merge_c_x)
	ldr	c2, [x0]
	cmp	x2, x1
	b.eq	1f
	scvalue	c2, c2, x1
	str	c2, [x0]
1:
	ret
SYM_FUNC_END(__morello_merge_c_x)

SYM_FUNC_START(__morello_cap_has_executive)
	gcperm	x0, c0
	ubfx	x0, x0, #MORELLO_CAP_PERM_EXECUTIVE_BIT, #1
	ret
SYM_FUNC_END(__morello_cap_has_executive)
