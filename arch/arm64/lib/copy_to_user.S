/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Ltd.
 */

#include <linux/linkage.h>

#include <asm/asm-uaccess.h>
#include <asm/assembler.h>
#include <asm/cache.h>

#ifndef COPY_FUNC_NAME
#define COPY_FUNC_NAME __arch_copy_to_user
#endif

/*
 * Copy to user space from a kernel buffer (alignment handled by the hardware)
 *
 * Parameters:
 *	x0 - to
 *	x1 - from
 *	x2 - n
 * Returns:
 *	x0 - bytes not copied
 */
	.macro ldrb1 reg, ptr, val
	ldrb  \reg, [\ptr], \val
	.endm

	.macro strb1 reg, ptr, val
	user_ldst 9998f, sttrb, \reg, \ptr, \val
	.endm

	.macro ldrh1 reg, ptr, val
	ldrh  \reg, [\ptr], \val
	.endm

	.macro strh1 reg, ptr, val
	user_ldst 9997f, sttrh, \reg, \ptr, \val
	.endm

	.macro ldr1 reg, ptr, val
	ldr \reg, [\ptr], \val
	.endm

	.macro str1 reg, ptr, val
	user_ldst 9997f, sttr, \reg, \ptr, \val
	.endm

	.macro ldp1 reg1, reg2, ptr, val
	ldp \reg1, \reg2, [\ptr], \val
	.endm

	.macro stp1 reg1, reg2, ptr, val
	user_stp 9997f, \reg1, \reg2, \ptr, \val
	.endm

	.macro ldpc1 reg1, reg2, ptr, val
	ldp \reg1, \reg2, [\ptr], \val
	.endm

	.macro stpc1 reg1, reg2, ptr, val
	user_stp 9997f, \reg1, \reg2, \ptr, \val, #16
	.endm

end	.req	x5
dstin	.req	x6
req_reg_pcuabi srcin, c15, x15
SYM_FUNC_START(COPY_FUNC_NAME)
	add	end, x0, x2
	mov	dstin, x0
#ifdef CONFIG_CHERI_PURECAP_UABI
.arch morello+c64
	bx	#4
	/* See comments in copy_from_user.S */
	cvtp	clr, lr
	cvtd	c1, x1
	mov	srcin, c1
#else
	mov	srcin, x1
#endif
#include "copy_template.S"
	mov	x0, #0
	ret

	// Exception fixups
9997:	cmp	dstx, dstin
	b.ne	9998f
	// Before being absolutely sure we couldn't copy anything, try harder
	ldrb	tmp1w, [srcin]
USER(9998f, sttrb tmp1w, [dst])
	add	dst, dst, #1
9998:	sub	x0, end, dstx			// bytes not copied
	ret
SYM_FUNC_END(COPY_FUNC_NAME)
EXPORT_SYMBOL(COPY_FUNC_NAME)
