/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */

#include <linux/linkage.h>

#include <asm/asm-uaccess.h>
#include <asm/assembler.h>
#include <asm/sysreg.h>

SYM_FUNC_START(morello_cpu_setup)
	/* Disable trapping of Morello instructions */
	mrs	x0, cpacr_el1
	orr	x0, x0, CPACR_EL1_CEN
	msr	cpacr_el1, x0
	isb

	/* Disable PCC/DDC base offset and other capability-related features */
	msr	cctlr_el1, xzr
	/*
	 * Now that trapping is disabled, capability exception entry is enabled
	 * and therefore CVBAR_EL1 needs to be set to a valid capability
	 * (derived from PCC).
	 */
	mrs	x0, vbar_el1
	cvtp	c0, x0
	msr	cvbar_el1, c0
	isb

	ret
SYM_FUNC_END(morello_cpu_setup)

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

SYM_FUNC_START(morello_thread_init_user)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state
	adr_l	x1, morello_root_cap
	ldr	c1, [x1]

	/*
	 * CTPIDR doesn't need to be initialised explicitly:
	 * - tls_thread_flush() already zeroes tpidr_el0, zeroing ctpidr_el0 as
	 *   well
	 * - The value stored in thread.morello_user_state will be set the next
	 *   time task_save_user_tls() is called, like thread_struct.uw.tp_value.
	 */

	/* DDC: initialised to the root capability (like PCC) */
	msr	ddc_el0, c1
	str	c1, [x0, #MORELLO_STATE_DDC]
	/* CID: null capability */
	msr	cid_el0, czr
	str	czr, [x0, #MORELLO_STATE_CID]
	/* CCTLR: all bits cleared */
	msr	cctlr_el0, xzr
	str	xzr, [x0, #MORELLO_STATE_CCTLR]

	ret
SYM_FUNC_END(morello_thread_init_user)

SYM_FUNC_START(morello_thread_save_user_state)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* CTPIDR is handled by task_save_user_tls */
	mrs	c1, ddc_el0
	str	c1, [x0, #MORELLO_STATE_DDC]
	mrs	c1, cid_el0
	str	c1, [x0, #MORELLO_STATE_CID]
	mrs	x1, cctlr_el0
	str	x1, [x0, #MORELLO_STATE_CCTLR]

	ret
SYM_FUNC_END(morello_thread_save_user_state)

SYM_FUNC_START(morello_thread_restore_user_state)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* CTPIDR is handled by task_restore_user_tls */
	ldr	c1, [x0, #MORELLO_STATE_DDC]
	msr	ddc_el0, c1
	ldr	c1, [x0, #MORELLO_STATE_CID]
	msr	cid_el0, c1
	ldr	x1, [x0, #MORELLO_STATE_CCTLR]
	msr	cctlr_el0, x1

	ret
SYM_FUNC_END(morello_thread_restore_user_state)

SYM_FUNC_START(morello_task_save_user_tls)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	mrs	c2, ctpidr_el0
	/* Save CTPIDR */
	str	c2, [x0, #MORELLO_STATE_CTPIDR]
	/* Save TPIDR to the appropriate field of tsk->thread */
	str	x2, [x1]

	ret
SYM_FUNC_END(morello_task_save_user_tls)

SYM_FUNC_START(morello_task_restore_user_tls)
	mov	x9, #THREAD_MORELLO_USER_STATE
	add	x0, x0, x9		// x0 = tsk->thread.morello_user_state

	/* Load the capability and 64-bit views of the TLS pointer */
	ldr	c2, [x0, #MORELLO_STATE_CTPIDR]
	ldr	x3, [x1]
	/*
	 * The 64-bit view may have been modified from within the kernel (e.g.
	 * through ptrace) since morello_task_save_user_tls was called.
	 * Merge the two views together.
	 */
	morello_merge_c_x 2, x3
	msr	ctpidr_el0, c2

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
	ldr	c0, [x0]
	str	x0, [x1]
	cfhi	x4, c0			// Extract upper 64 bits
	str	x4, [x2]
	gctag	x4, c0
	strb	w4, [x3]

	ret
SYM_FUNC_END(__morello_cap_lo_hi_tag)

SYM_FUNC_START(__morello_cap_cpy)
	ldr	c2, [x1]
	str	c2, [x0]
	ret
SYM_FUNC_END(__morello_cap_cpy)

SYM_FUNC_START(__morello_merge_c_x)
	ldr	c2, [x0]
	cmp	x2, x1
	b.eq	1f
	scvalue	c2, c2, x1
	str	c2, [x0]
1:
	ret
SYM_FUNC_END(__morello_merge_c_x)

SYM_FUNC_START(__morello_get_ddc)
	mrs	c1, ddc
	str	c1, [x0]
	ret
SYM_FUNC_END(__morello_get_ddc)
