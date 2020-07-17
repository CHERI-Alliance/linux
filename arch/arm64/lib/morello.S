/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */

#include <linux/linkage.h>

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

SYM_FUNC_START(__morello_get_ddc)
	mrs	c1, ddc
	str	c1, [x0]
	ret
SYM_FUNC_END(__morello_get_ddc)
