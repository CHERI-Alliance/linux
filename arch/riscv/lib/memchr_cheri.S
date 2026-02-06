/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <linux/args.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

/* Use defines to make things more readable. */
#define BYTEREG		a1
#define	LIMITREG	a2

/*
 * Helper macro: Count the number of leading/trailing zero bits
 * in a register. Counting starts at the end of the word that
 * would be stored at the lower address in memory.
 */
.macro countz target src
#ifdef CONFIG_CPU_BIG_ENDIAN
        clz \target, \src
#else
        ctz \target, \src
#endif
.endm

/*
 * Scan one byte at a time until we are aligned or the
 * character is found.
 */
.macro byte_loop limit
.align 3
100:
	beq		a0, \limit, 101f
	lbu		t5, (CREG(a0))
	CINSN(addi)	CREG(a0), CREG(a0), 1
	bne		t5, BYTEREG, 100b
	CINSN(addi)	CREG(a0), CREG(a0), -1
	j		.Lfound
101:
.endm


/*
 * Like byte_loop but reads one machine word at a time from memory
 * and uses the ZBB extension to extract the position of the first
 * interesting byte equal to BYTEREG is found.
 * jump goes to .Lfound at the end of the string to match the
 * behaviour required by strchr().
 * Note that in the main loop we do not pre-decrement when
 * scanning backwards.
 */
.macro word_loop limit
	/* Fill t5 with repetitions of BYTEREG. */
	slli		t6, BYTEREG, 8
	or		t5, t6, BYTEREG
	slli		t6, t5, 16
	or		t5, t5, t6
#ifdef CONFIG_64BIT
	slli		t6, t5, 32
	or		t5, t5, t6
#endif
	li		t6, -1
.align 3
100:
	beq		a0, \limit, 102f
	REG_L		t3, (CREG(a0))
	CINSN(addi)	CREG(a0), CREG(a0), SZREG
	xor		t3, t3, t5
	orc.b		t3, t3
	beq		t3, t6, 100b

101:
	/*
	 * The character was found. The countz macro counts
	 * from the correct direction.
	 */
	CINSN(addi)	CREG(a0), CREG(a0), -SZREG
	not		t3, t3
	countz		t3 t3
	srli		t3, t3, 3
	add		CREG(a0), CREG(a0), t3
	j		.Lfound
102:
.endm


/* Actual function implementation. */
.align 3
SYM_FUNC_START(memchr)
	/*
	 * Normalize the compare byte. Don't use sext.b because ZBB might
	 * not be available.
	 */
	andi		BYTEREG, BYTEREG, 0xff

	/*
	 * Calculate user provided limit in t2 and the start address
	 * in a0. If the addtion overflows keep it as is but use the
	 * byte wise loop.
	 */
	add		t2, a0, LIMITREG
	bltu		t2, a0, .Lpost_loop

#if defined(CONFIG_RISCV_ISA_ZBB) && defined(CONFIG_TOOLCHAIN_HAS_ZBB)

	/* Jump directly to the post loop if ZBB is not supported. */
	__ALTERNATIVE_CFG("j .Lpost_loop", "nop", 0, RISCV_ISA_EXT_ZBB,
		IS_ENABLED(CONFIG_RISCV_ISA_ZBB) && IS_ENABLED(CONFIG_TOOLCHAIN_HAS_ZBB))

.option push
.option arch,+zbb

	/*
	 * Calculate the next alignment boundary. If it is at or
	 * beyond the user provided limit use the byte wise loop.
	 */
	add		t1, a0, SZREG-1
	andi		t1, t1, -SZREG
	beqz		t1, .Lpost_loop
	bleu		t2, t1, .Lpost_loop
	byte_loop	t1

	/*
	 * Calculate end address for word sized loop. Be paranoid
	 * on CHERI and assume that the capability bounds may be
	 * smaller then LIMITREG if a matching byte is present.
	 */
#ifdef CONFIG_CHERI_KERNEL
	gcbase		t3, CREG(a0)
	gclen		t1, CREG(a0)
	add		t1, t1, t3
	bltu		t1, a0, .Lpost_loop
	minu		t1, t1, t2
	andi		t1, t1, -SZREG
#else
	andi		t1, t2, -SZREG
#endif
	word_loop	t1

.option pop

#endif

.align 3
.Lpost_loop:
	/* For the rest do a bytewise search. */
	byte_loop	t2
	li		a0, 0
.Lfound:
	ret


SYM_FUNC_END(memchr)
SYM_FUNC_ALIAS(__pi_memchr, memchr)
EXPORT_SYMBOL(memchr)
