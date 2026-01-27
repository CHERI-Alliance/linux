/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <linux/args.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

#define BYTEREG a1

/*
 * Helper macro: Count the number of leading/trailing zero bits
 * in a register. Counting starts at the end of the word that
 * would be stored at higher address in memory.
 */
.macro countz target src
#ifdef CONFIG_CPU_BIG_ENDIAN
        ctz \target, \src
#else
        clz \target, \src
#endif
.endm


/*
 * Read one byte at a time until one of these conditions is met:
 * - The pointer's addess reaches the address limit in \limit.
 *   Execution continues after the loop if the limit is reached
 *   and no data is read from the address at \limit.
 * - The byte is equal to NUL. Execution continues at the
 *   label .Ldone.
 */
.macro byte_loop haslimit limit
.align 3
100:
.if \haslimit
	beq		a0, \limit, 102f
.endif
	lbu		t5, (CREG(a0))
	CINSN(addi)	CREG(a0), CREG(a0), 1
	bne		t5, BYTEREG, 101f
	CINSN(addi)	CREG(t0), CREG(a0), -1
101:
	bnez		t5, 100b
	j		.Ldone
102:
.endm


/*
 * Like byte_loop but reads one machine word at a time from memory
 * and uses the ZBB extension to extract the position of the first
 * interesting byte (NUL or BYTEREG). If BYTEREG contains zero the
 * jump goes to .Lfound at the end of the string to match the
 * behaviour required by strchr().
 * Clobbers:
 * 	t3, t4, t5, t6
 */
.macro word_loop haslimit limit
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

.if \haslimit
	beq		a0, \limit, 102f
.endif
	REG_L		t3, (CREG(a0))
	orc.b		t4, t3

	/*
	 * If we found NUL somewhere handle the rest with the bytewise loop.
	 */
	bne		t4, t6, .Lpost_loop
	xor		t3, t3, t5
	CINSN(addi)	CREG(a0), CREG(a0), SZREG
	orc.b		t3, t3
	beq		t3, t6, 100b

	/*
	 * We found no NUL byte but at least one instance of
	 * BYTEREG. Set CREG(t0) accordingly. CREG(a0) is already incremented
	 * by SZREG bytes.
	 */

	not		t3, t3
	countz		t3, t3
	srli		t3, t3, 3
	not		t3, t3		/* ~t3 = -t3 - 1 */
	add		CREG(t0), CREG(a0), t3
	j		100b

102:
.endm

/* Actual function implementation. */
.align 3
SYM_FUNC_START(strrchr)
	/*
	 * Normalize the compare byte. Don't use sext.b because ZBB might
	 * not be available.
	 */
	andi		BYTEREG, BYTEREG, 0xff

	/* Initialize return value. */
	li		t0, 0

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

	byte_loop	1, t1

	/* Calculate end address for word sized loop. */
#ifdef CONFIG_CHERI_KERNEL
	gcbase		t3, CREG(a0)
	gclen		t1, CREG(a0)
	add		t1, t1, t3
	bltu		t1, a0, .Lpost_loop
	andi		t1, t1, -SZREG
	word_loop	1, t1
#else
	word_loop	0, nolimit
#endif

.option pop

#endif

.align 3
.Lpost_loop:
	/* For the rest do a bytewise search. */
	byte_loop	0, nolimit

.Ldone:
	mv		CREG(a0), CREG(t0)
	ret

SYM_FUNC_END(strrchr)
SYM_FUNC_ALIAS(__pi_strrchr, strrchr)
EXPORT_SYMBOL(strrchr)
