/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Ltd.
 */

#include <linux/linkage.h>

#include <asm/asm-uaccess.h>
#include <asm/assembler.h>
#include <asm/cache.h>

#ifndef COPY_FUNC_NAME
#define COPY_FUNC_NAME __arch_copy_from_user
#endif

/*
 * Copy from user space to a kernel buffer (alignment handled by the hardware)
 *
 * Parameters:
 *	x0 - to
 *	x1 - from
 *	x2 - n
 * Returns:
 *	x0 - bytes not copied
 */

	.macro ldrb1 reg, ptr, val
	user_ldst 9998f, ldtrb, \reg, \ptr, \val
	.endm

	.macro strb1 reg, ptr, val
	strb \reg, [\ptr], \val
	.endm

	.macro ldrh1 reg, ptr, val
	user_ldst 9997f, ldtrh, \reg, \ptr, \val
	.endm

	.macro strh1 reg, ptr, val
	strh \reg, [\ptr], \val
	.endm

	.macro ldr1 reg, ptr, val
	user_ldst 9997f, ldtr, \reg, \ptr, \val
	.endm

	.macro str1 reg, ptr, val
	str \reg, [\ptr], \val
	.endm

	.macro ldp1 reg1, reg2, ptr, val
	user_ldp 9997f, \reg1, \reg2, \ptr, \val
	.endm

	.macro stp1 reg1, reg2, ptr, val
	stp \reg1, \reg2, [\ptr], \val
	.endm

	.macro ldpc1 reg1, reg2, ptr, val
	user_ldp 9997f, \reg1, \reg2, \ptr, \val, #16
	.endm

	.macro stpc1 reg1, reg2, ptr, val
	stp \reg1, \reg2, [\ptr], \val
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
	/*
	 * Having switched to C64, argumentless RET is equivalent to RET CLR.
	 * Because we have been called from A64, only LR is set. We therefore
	 * set CLR to a valid capability, derived from PCC (as if we had been
	 * called from C64). Conveniently this will also automatically switch
	 * us back to A64 when returning (as the LSB of LR should be unset).
	 */
	cvtp	clr, lr
	/*
	 * Accessing memory via X registers in C64 requires using
	 * alternate-base loads and stores; unfortunately most loads and stores
	 * used in copy_template.S do not have an alternate-base counterpart.
	 * The most straightforward solution is to access memory via C
	 * registers only. We therefore need to create a valid capability for
	 * the kernel buffer too, which is done by deriving it from DDC. Since
	 * X-based accesses are validated against DDC, this is functionally
	 * equivalent.
	 */
	cvtd	c0, x0
	mov	srcin, c1
#else
	mov	srcin, x1
#endif
#include "copy_template.S"
	mov	x0, #0				// Nothing to copy
	ret

	// Exception fixups
9997:	cmp	dstx, dstin
	b.ne	9998f
	// Before being absolutely sure we couldn't copy anything, try harder
USER(9998f, ldtrb tmp1w, [srcin])
	strb	tmp1w, [dst], #1
9998:	sub	x0, end, dstx			// bytes not copied
	ret
SYM_FUNC_END(COPY_FUNC_NAME)
EXPORT_SYMBOL(COPY_FUNC_NAME)
