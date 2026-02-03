/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <linux/args.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

/*
 * Template for the efficient ZBB based implementation
 * of string compare functions:
 * strcmp(), strncmp()
 *
 * Template arguments:
 * - FUNCNAME: The name of the function to implement.
 * - LIMITREG: If defined the register that contains the maximum
 *       number of bytes to look at. If not defined only the NUL
 *       byte terminates the loop.
 *
 * Result:
 * The template implements the entire function.
 *
 * Registers:
 * - All temporary and all argument registers may be clobbered.
 * - Argument registers a0 and a1 are advanced as we move
 *   through the string.
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

/*
 * Calculate the number of bytes that can be accessed
 * without crossing capability boundaries or (if given)
 * the user provided limit. If LIMITREG is defined target
 * should initially contain the number of remaining bytes
 * according to the user limit.
 */
.macro limit target tmp1 tmp2 tmp3 tmp4
#ifdef CONFIG_CHERI_KERNEL
	gcbase		\tmp1, ca0
	gclen		\tmp3, ca0
	gcbase		\tmp2, ca1
	gclen		\tmp4, ca1
	add		\tmp1, \tmp1, \tmp3
	add		\tmp2, \tmp2, \tmp4
	bltu		\tmp1, a0, .Lpost_loop
	bltu		\tmp2, a1, .Lpost_loop
	sub		\tmp1, \tmp1, a0
	sub		\tmp2, \tmp2, a1
#ifndef LIMITREG
	minu		\target, \tmp1, \tmp2
#else
	minu		\tmp1, \tmp1, \tmp2
	minu		\target, \target, \tmp1
#endif
#endif
.endm

/*
 * Compare one byte at a time until one of at most three
 * conditions are met:
 * - The address of the pointer in a0 reaches the address limit
 *   in \limit (only if \haslimit is true).
 * - The first byte is NUL.
 * - The bytes differ (which catches the case where the second
 *   byte is NUL.
 * If the limit is reached execution continues after the loop.
 * Otherwise execution continues at .Ldo_cmp. With the first
 * byte in t5 and the second byte in t6.
 */
.macro byte_loop haslimit limit
.align 3
100:
.if \haslimit
	beq		a0, \limit, 101f
.endif
	lbu		t5, (CREG(a0))
	lbu		t6, (CREG(a1))
	beqz		t5, .Ldo_cmp
	CINSN(addi)	CREG(a0), CREG(a0), 1
	CINSN(addi)	CREG(a1), CREG(a1), 1
	beq		t5, t6, 100b
	j		.Ldo_cmp
101:
.endm


/* Actual function implementation. */
.align 3
SYM_FUNC_START(FUNCNAME)
#ifdef LIMITREG
	/*
	 * Calculate user provided limit address for the destination
	 * in t2. If the addtion overflows use the byte wise loop.
	 */
	add		t2, a0, LIMITREG
	bltu		t2, a0, .Lpost_loop
#endif	/* LIMITREG */

#if defined(CONFIG_RISCV_ISA_ZBB) && defined(CONFIG_TOOLCHAIN_HAS_ZBB)

	/* Jump directly to the post loop if ZBB is not supported. */
	__ALTERNATIVE_CFG("j .Lpost_loop", "nop", 0, RISCV_ISA_EXT_ZBB,
		IS_ENABLED(CONFIG_RISCV_ISA_ZBB) && IS_ENABLED(CONFIG_TOOLCHAIN_HAS_ZBB))

.option push
.option arch,+zbb
	/* Align a0 to a machine word boundary. */
	add		t1, a0, SZREG-1
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
	sub		t1, t2, a0
#endif
	limit		t1, t3, t4, t5, t6
#if HAS_WORDLOOP_LIMIT
	andi		t1, t1, -SZREG
	add		t1, t1, a0
#endif

	li		t3, -1
.align 3
.Lword_loop:
#ifdef HAS_WORDLOOP_LIMIT
	beq		a0, t1, .Lpost_loop
#endif
	REG_L		t5, (CREG(a0))
	REG_L		t6, (CREG(a1))
	orc.b		t4, t5
	bne		t4, t3, .Ldo_mask
	CINSN(addi)	CREG(a0), CREG(a0), SZREG
	CINSN(addi)	CREG(a1), CREG(a1), SZREG
	beq		t5, t6, .Lword_loop
	j		.Ldo_word_cmp

.Lunaligned:
	/*
	 * On entry a0 is aligned, and the alignment boundary for
	 * a1 is in t1. Calculate the byte difference in a3.
	 */
	sub		a3, t1, a1

	/*
	 * Calculate the number of available bytes in a2. If this
	 * does not allow us to read enough bytes to align a1
	 * use the standard bytewise loop.
	 */
#ifdef LIMITREG
	sub		a2, t2, a0
#endif
#if HAS_WORDLOOP_LIMIT
	limit		a2, t6, t4, t5, t6
	bleu		a2, a3, .Lpost_loop
#endif

	/*
	 * Align _only_ a1 reading bytes into the word in t0.
	 */
	li		t0, 0
	beq		a1, t1, .Lunaligned_main
.align 3
.Lunaligned_pre_loop:
	lbu		t6, (CREG(a1))
	CINSN(addi)	CREG(a1), CREG(a1), 1
#ifdef CONFIG_CPU_BIG_ENDIAN
	sll		t0, t0, 8
	or		t0, t0, t6
#else
	or		t0, t0, t6
	rori		t0, t0, 8
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
	add		a2, a0, a2
#endif

	/*
	 * This is the main word at a time loop for unaligned strings.
	 */
	li		t3, -1
.align 3
.Lunaligned_main_loop:
#ifdef HAS_WORDLOOP_LIMIT
	beq		a0, a2, .Lunaligned_post
#endif
	/*
	 * Construct the next unaligned word in t6 by
	 * combining the leftover high bits in t0 with the low bits
	 * in the next word and read the next aligned word at the
	 * source into t5.
	 */
#ifdef CONFIG_CPU_BIG_ENDIAN
	sll		t6, t0, a4
#else
	srl		t6, t0, a4
#endif
	REG_L		t0, (CREG(a1))
	REG_L		t5, (CREG(a0))
#ifdef CONFIG_CPU_BIG_ENDIAN
	srl		t4, t0, a3
#else
	sll		t4, t0, a3
#endif
	or		t6, t6, t4

	/* Now, compare the current words normally including NUL byte checks. */
	orc.b		t4, t5
	bne		t4, t3, .Ldo_mask
	CINSN(addi)	CREG(a0), CREG(a0), SZREG
	CINSN(addi)	CREG(a1), CREG(a1), SZREG
	beq		t5, t6, .Lunaligned_main_loop
	j		.Ldo_word_cmp

.Lunaligned_post:
	srli		a3, a3, 3
	neg		a3, a3
	add		CREG(a1), CREG(a1), a3
	j		.Lpost_loop

.Ldo_mask:
	/*
	 * We have a NUL byte somewhere in t5, t4 is the orc.b mask.
	 * Use clz/ctz to calculate the bit position of the NUL byte.
	 * From there use the value of -1 in t3 to calculate a mask
	 * of all _invalid_ bits.
	 */
	not		t4, t4
#ifdef CONFIG_CPU_BIG_ENDIAN
	clz		t4, t4
	srl		t3, t3, t4
	srli		t3, t3, 8
#else	/* CONFIG_CPU_BIG_ENDIAN */
	ctz		t4, t4
	sll		t3, t3, t4
	slli		t3, t3, 8
#endif	/* CONFIG_CPU_BIG_ENDIAN */

	/* Mask invalid bits in t5 and t6. */
	andn		t5, t5, t3
	andn		t6, t6, t3

.Ldo_word_cmp:
#ifndef CONFIG_CPU_BIG_ENDIAN
	rev8		t5, t5
	rev8		t6, t6
#endif /* CONFIG_CPU_BIG_ENDIAN */
	j		.Ldo_cmp

.option pop

#endif

.align 3
.Lpost_loop:
	/* For the rest do a bytewise search. */
	byte_loop	HAS_BYTELOOP_LIMIT, t2
	mv		a0, x0
	ret

.Ldo_cmp:
	/*
	 * Only return -1, 0 or +1. This is not strictly required
	 * for strmp(). Only less then zero, zero or greater than
	 * zero is mandated. However, the result must be an int not
	 * a long!
	 */
	sltu		t1, t6, t5
	sltu		t2, t5, t6
	sub		a0, t1, t2
	ret



SYM_FUNC_END(FUNCNAME)
SYM_FUNC_ALIAS(CONCATENATE(__pi_, FUNCNAME), FUNCNAME)
EXPORT_SYMBOL(FUNCNAME)
