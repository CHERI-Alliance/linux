/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <linux/args.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

/*
 * Template for the efficient ZBB based implementation
 * of string copy functions:
 * strcpy(), strncpy()
 *
 * Template arguments:
 * - FUNCNAME: The name of the function to implement.
 * - LIMITREG: If defined the register that contains the maximum
 *       number of bytes to look at. If not defined only the NUL
 *       byte terminates the loop.
 *
 * Result:
 * The template implements the entire function. If a limit is given
 * you will get strncpy semantics, i.e. there is no forced NUL byte
 * at the end.
 *
 * Registers:
 * All temporary and all argument registers may be clobbered.
 */

#if defined(CONFIG_CHERI_KERNEL) || defined(LIMITREG)
#define HAS_WORDLOOP_LIMIT	1
#else
#define HAS_WORDLOOP_LIMIT	0
#endif

#ifdef LIMITREG
#define HAS_BYTELOOP_LIMIT	1
#else
#define HAS_BYTELOOP_LIMIT	0
#endif

#ifdef CONFIG_CHERI_KERNEL
/*
 * Calculate the number of bytes accessible by the capability
 * \cap starting from its current address. If the capability
 * address is beyond the end of the capability range jump to
 * .Lpost_loop.
 * Note that for capabilities where the bounds wrap around
 * zero the byte at the current address may still be accessible.
 */
.macro capsize target cap tmp
	gcbase		\target, c\cap
	gclen		\tmp, c\cap
	add		\target, \target, \tmp
	bltu		\target, \cap, .Lpost_loop
	sub		\target, \target, \cap
.endm
#endif	/* CONFIG_CHERI_KERNEL */

/*
 * Calculate the number of bytes that can be accessed
 * without crossing capability boundaries or (if given)
 * the user provided limit. If LIMITREG is defined target
 * should initially contain the number of remaining bytes
 * according to the user limit.
 */
.macro limit target tmp0 tmp1 tmp2
#ifdef CONFIG_CHERI_KERNEL
	capsize		\tmp0, t0, \tmp2
	capsize		\tmp1, a1, \tmp2
#ifndef LIMITREG
	minu		\target, \tmp0, \tmp1
#else
	minu		\tmp0, \tmp0, \tmp1
	minu		\target, \target, \tmp0
#endif
#endif
.endm

/*
 * Copy one byte at a time until one of at most two
 * conditions are met:
 * - The address of the pointer in t0 reaches the address limit
 *   in \limit (only if \haslimit is true).
 * - The copied byte is NUL.
 * If the limit is reached execution continues after the loop.
 * Otherwise execution continues at .Ldone.
 */
.macro byte_loop haslimit limit
.align 3
100:
.if \haslimit
	beq		t0, \limit, 101f
.endif
	lbu		t6, (CREG(a1))
	CINSN(addi)	CREG(t0), CREG(t0), 1
	CINSN(addi)	CREG(a1), CREG(a1), 1
	sb		t6, -1(CREG(t0))
	bnez		t6, 100b
#ifdef RETEND
	CINSN(addi)	CREG(t0), CREG(t0), -1
#endif
	j		.Ldone
101:
.endm


/* Actual function implementation. */
.align 3
SYM_FUNC_START(FUNCNAME)
	/*
	 * Use t0 for the destination pointer. We must return the
	 * original value of a0 when done.
	 */
	mv		CREG(t0), CREG(a0)

#ifdef LIMITREG
	/*
	 * Calculate user provided limit address for the destination
	 * in t2. If the addtion overflows use the byte wise loop.
	 */
	add		t2, t0, LIMITREG
	bltu		t2, t0, .Lpost_loop
#endif	/* LIMITREG */

#if defined(CONFIG_RISCV_ISA_ZBB) && defined(CONFIG_TOOLCHAIN_HAS_ZBB)

	/* Jump directly to the post loop if ZBB is not supported. */
	__ALTERNATIVE_CFG("j .Lpost_loop", "nop", 0, RISCV_ISA_EXT_ZBB,
		IS_ENABLED(CONFIG_RISCV_ISA_ZBB) && IS_ENABLED(CONFIG_TOOLCHAIN_HAS_ZBB))

.option push
.option arch,+zbb
	/* Align t0 to a machine word boundary. */
	add		t1, t0, SZREG-1
	andi		t1, t1, -SZREG
	beqz		t1, .Lpost_loop
#ifdef LIMITREG
	bleu		t2, t1, .Lpost_loop
#endif	/* LIMITREG */
	byte_loop	1, t1

	/* Check if the strings are aligned. */
	addi		t1, a1, SZREG-1
	andi		t1, t1, -SZREG
	bne		t1, a1, .Lunaligned

	/* Calculate end address for word sized aligned loop. */
#ifdef LIMITREG
	sub		t1, t2, t0
#endif
	limit		t1, t3, t4, t5
#if HAS_WORDLOOP_LIMIT
	andi		t1, t1, -SZREG
	add		t1, t1, t0
#endif

	li		t3, -1
.align 3
.Lword_loop:
#ifdef HAS_WORDLOOP_LIMIT
	beq		t0, t1, .Lpost_loop
#endif
	REG_L		t6, (CREG(a1))
	orc.b		t4, t6
	bne		t4, t3, .Ldo_partial
	REG_S		t6, (CREG(t0))
	CINSN(addi)	CREG(t0), CREG(t0), SZREG
	CINSN(addi)	CREG(a1), CREG(a1), SZREG
	j		.Lword_loop

.Lunaligned:
	/*
	 * On entry t0 is aligned, and the alignment boundary for
	 * a1 is in t1. Calculate the byte difference in a3.
	 */
	sub		a3, t1, a1

	/*
	 * Calculate the number of available bytes in a2. If this
	 * does not allow us to read enough bytes to align a1
	 * use the standard bytewise loop.
	 */
#ifdef LIMITREG
	sub		a2, t2, t0
#endif
#if HAS_WORDLOOP_LIMIT
	limit		a2, t6, t4, t5
	bleu		a2, a3, .Lpost_loop
#endif

	/*
	 * Align _only_ a1 reading bytes into the word in t5.
	 */
	li		t5, 0
	beq		a1, t1, .Lunaligned_main
.align 3
.Lunaligned_pre_loop:
	lbu		t6, (CREG(a1))
	CINSN(addi)	CREG(a1), CREG(a1), 1
#ifdef CONFIG_CPU_BIG_ENDIAN
	sll		t5, t5, 8
	or		t5, t5, t6
#else
	or		t5, t5, t6
	rori		t5, t5, 8
#endif
	bne		a1, t1, .Lunaligned_pre_loop

.Lunaligned_main:
	/*
	 * Adjust available bytes by the alignment then convert
	 * a3 from valid bytes to valid bits and caculate the number
	 * of invalid bits in a4.
	 */
	sub		a2, a2, a3
	sll		a3, a3, 3
	li		a4, 8 * SZREG
	sub		a4, a4, a3

	/*
	 * Calculate limit for the word sized loop.
	 */
#ifdef HAS_WORDLOOP_LIMIT
	andi		a2, a2, -SZREG
	add		a2, t0, a2
#endif

	/*
	 * This is the main word at a time loop for unaligned strings.
	 */
	li		t3, -1
.align 3
.Lunaligned_main_loop:
#ifdef HAS_WORDLOOP_LIMIT
	beq		t0, a2, .Lunaligned_post
#endif
	/*
	 * Construct the next unaligned word in t6 by
	 * combining the leftover high bits in t5 with the low bits
	 * in the next word and store it.
	 */
#ifdef CONFIG_CPU_BIG_ENDIAN
	sll		t6, t5, a4
#else
	srl		t6, t5, a4
#endif
	REG_L		t5, (CREG(a1))
#ifdef CONFIG_CPU_BIG_ENDIAN
	srl		t4, t5, a3
#else
	sll		t4, t5, a3
#endif
	or		t6, t6, t4

	/* Now, store the word in t6 normally including NUL byte checks. */
	orc.b		t4, t6
	bne		t4, t3, .Ldo_partial
	REG_S		t6, (CREG(t0))
	CINSN(addi)	CREG(t0), CREG(t0), SZREG
	CINSN(addi)	CREG(a1), CREG(a1), SZREG
	j		.Lunaligned_main_loop

.Lunaligned_post:
	srli		a3, a3, 3
	neg		a3, a3
	add		CREG(a1), CREG(a1), a3
	j		.Lpost_loop

.Ldo_partial:
	/*
	 * We have a NUL byte somewhere in t6. Store one byte at a time.
	 * We were allowed to read the entire data, i.e. no range checks
	 * are necessary.
	 */
#ifdef CONFIG_CPU_BIG_ENDIAN
	rev8		t5, t5
#endif
	zext.b		t5, t6
	sb		t5, (CREG(t0))
	beqz		t5, .Ldone
.align 3
.Lpartial_loop:
	srli		t6, t6, 8
	CINSN(addi)	CREG(t0), CREG(t0), 1
	zext.b		t5, t6
	sb		t5, (CREG(t0))
	bnez		t5, .Lpartial_loop
	j		.Ldone

.option pop

#endif

.align 3
.Lpost_loop:
	/* For the rest do a bytewise search. */
	byte_loop	HAS_BYTELOOP_LIMIT, t2

.Ldone:
#ifdef RETEND
	mv		CREG(a0), CREG(t0)
#endif
	ret

SYM_FUNC_END(FUNCNAME)
SYM_FUNC_ALIAS(CONCATENATE(__pi_, FUNCNAME), FUNCNAME)
EXPORT_SYMBOL(FUNCNAME)
