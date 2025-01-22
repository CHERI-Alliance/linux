/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

/* int strlen(const char *s) */
SYM_FUNC_START(strlen)

#ifndef CONFIG_CHERI_KERNEL
	/* ZBB implementation contains out of bounds accesses. */
	ALTERNATIVE("nop", "j strlen_zbb", 0, RISCV_ISA_EXT_ZBB, CONFIG_RISCV_ISA_ZBB)
#endif

	/*
	 * Returns
	 *   a0 - string length
	 *
	 * Parameters
	 *   a0 - String to measure
	 *
	 * Clobbers:
	 *   t0, t1
	 */
	mv	CREG(t1), CREG(a0)
1:
	lbu	t0, 0(CREG(t1))
	beqz	t0, 2f
	CREG(addi)	CREG(t1), CREG(t1), 1
	j	1b
2:
	sub	a0, t1, a0
	ret

/*
 * Variant of strlen using the ZBB extension if available
 */
#ifdef CONFIG_RISCV_ISA_ZBB
strlen_zbb:

#ifdef CONFIG_CPU_BIG_ENDIAN
# define CZ	clz
# define SHIFT	sll
#else
# define CZ	ctz
# define SHIFT	srl
#endif

.option push
.option arch,+zbb

	/*
	 * Returns
	 *   a0 - string length
	 *
	 * Parameters
	 *   a0 - String to measure
	 *
	 * Clobbers
	 *   t0, t1, t2, t3
	 */

	/* Number of irrelevant bytes in the first word. */
	andi	t2, a0, SZREG-1

	/* Align pointer. */
#ifdef CONFIG_CHERI_KERNEL
	andi	t3, a0, -SZREG
	scaddr	ct0, ca0, t3
#else
	andi	t0, a0, -SZREG
#endif

	li	t3, SZREG
	sub	t3, t3, t2
	slli	t2, t2, 3

	/* Get the first word.  */
	REG_L	t1, 0(CREG(t0))

	/*
	 * Shift away the partial data we loaded to remove the irrelevant bytes
	 * preceding the string with the effect of adding NUL bytes at the
	 * end of the string's first word.
	 */
	SHIFT	t1, t1, t2

	/* Convert non-NUL into 0xff and NUL into 0x00. */
	orc.b	t1, t1

	/* Convert non-NUL into 0x00 and NUL into 0xff. */
	not	t1, t1

	/*
	 * Search for the first set bit (corresponding to a NUL byte in the
	 * original chunk).
	 */
	CZ	t1, t1

	/*
	 * The first chunk is special: compare against the number
	 * of valid bytes in this chunk.
	 */
	srli	a0, t1, 3
	bgtu	t3, a0, 2f

	/* Prepare for the word comparison loop. */
	addi	t2, t0, SZREG
	li	t3, -1

	/*
	 * Our critical loop is 4 instructions and processes data in
	 * 4 byte or 8 byte chunks.
	 */
	.p2align 3
1:
	REG_L	t1, SZREG(CREG(t0))
	addi	t0, t0, SZREG
	orc.b	t1, t1
	beq	t1, t3, 1b

	not	t1, t1
	CZ	t1, t1
	srli	t1, t1, 3

	/* Get number of processed bytes. */
	sub	t2, t0, t2

	/* Add number of characters in the first word.  */
	add	a0, a0, t2

	/* Add number of characters in the last word.  */
	add	a0, a0, t1
2:
	ret

.option pop
#endif
SYM_FUNC_END(strlen)
SYM_FUNC_ALIAS(__pi_strlen, strlen)
