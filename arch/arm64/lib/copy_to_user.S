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
srcin	.req	x15
SYM_FUNC_START(COPY_FUNC_NAME)
	add	end, x0, x2
	mov	dstin, x0
	mov	srcin, x1
#include "copy_template.S"
	mov	x0, #0
	ret

	// Exception fixups
9997:	cmp	dst, dstin
	b.ne	9998f
	// Before being absolutely sure we couldn't copy anything, try harder
	ldrb	tmp1w, [srcin]
USER(9998f, sttrb tmp1w, [dst])
	add	dst, dst, #1
9998:	sub	x0, end, dst			// bytes not copied
	ret
SYM_FUNC_END(COPY_FUNC_NAME)
EXPORT_SYMBOL(COPY_FUNC_NAME)
