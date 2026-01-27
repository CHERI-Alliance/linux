/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/linkage.h>
#include <linux/args.h>
#include <asm/asm.h>
#include <asm/alternative-macros.h>
#include <asm/hwcap.h>

/*
 * Template for the efficient ZBB based implementation
 * of string scanning functions:
 * strlen(), strnlen(), strchr(), strnchr(), strchrnul(), strnchrnul().
 *
 * Template arguments:
 * - FUNCNAME: The name of the function to implement.
 * - EPILOG: The code that processes the result. This should
 *       provide the labels ".Lfound" and ".Lnot_found" as described
 *       below and is used to calculate the result as required
 *       by the particular function.
 * - BYTEREG: If defined, the register that contains the byte
 *       apart from NUL that we are looking for. Defined when
 *       implementing strchr() style function.
 * - LIMITREG: If defined the register that contains the maximum
 *       number of bytes to look at. If not defined only the NUL
 *       byte terminates the loop.
 *
 * Result:
 * The user of this macro must provide two labels
 * - If BYTEREG is given and the byte was found before the end of
 *   the string a0 will point one byte beyond that byte and
 *   execution continues at the label ".Lfound" that must be provided.
 * - If a NUL byte is encountered execution continues at
 *   the label ".Lnot_found" which must be provided. In this case
 *   the pointer is already advanced one byte beyond the NUL byte,
 *   too.
 * - If LIMITREG is given and the limit is reached without finding
 *   anything execution continues after the template. In this
 *   case the pointer will point to the first byte that is no
 *   longer within the limit.
 *
 * Register use:
 * - t0 holds the original value of a0 in case it is needed in
 *   the EPILOG.
 * - t1-t6 may be clobbered
 * - a0 is the pointer and is advanced while iterating through
 *   the string.
 * - LIMITREG is used (if defined) but not modified.
 * - BYTEREG (if defined) will be normalized if the value does
 *   not fit into a char.
 * - All other registers are unused and unmodified. This includes
 *   stack pointer and frame pointer.
 *
 * If capabilties are used (CONFIG_CHERI_KERNEL), the capability
 * bounds are checked and if the naive bytewise implementation
 * would not produce a fault this code will not produce a fault, either.
 * All other faults will happen is normal. This includes capability
 * bounds faults if the string exceeds capability bounds.
 */


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
 * Read one byte at a time until one of at most three
 * conditions are met:
 * - The pointer's addess reaches the address limit in \limit.
 *   Execution continues after the loop if the limit is reached
 *   and no data is read from the address at \limit.
 * - The byte is equal to the value in BYTREG. Execution continues
 *   at the label .Lfound.
 * - The byte is equal to NUL. Execution continues at the
 *   label .Lnot_found.
 * If BYTEREG is zero the jump goes to .Lfound at the end of the
 * string to match the behaviour required by strchr().
 */
.macro byte_loop haslimit limit
.align 3
100:
.if \haslimit
	beq		a0, \limit, 102f
.endif
	lbu		t5, (CREG(a0))
	CINSN(addi)	CREG(a0), CREG(a0), 1
#ifdef BYTEREG
	beq		t5, BYTEREG, .Lfound
#endif
	bnez		t5, 100b
	j		.Lnot_found
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
#ifdef BYTEREG
	/* Fill t5 with repetitions of BYTEREG. */
	slli		t6, BYTEREG, 8
	or		t5, t6, BYTEREG
	slli		t6, t5, 16
	or		t5, t5, t6
#ifdef CONFIG_64BIT
	slli		t6, t5, 32
	or		t5, t5, t6
#endif
#endif
	li		t6, -1
.align 3
100:
.if \haslimit
	beq		a0, \limit, 102f
.endif
	REG_L		t3, (CREG(a0))
	CINSN(addi)	CREG(a0), CREG(a0), SZREG
	orc.b		t4, t3
#ifdef BYTEREG
	xor		t3, t3, t5
	orc.b		t3, t3
	bne		t3, t6, 101f
#endif
	beq		t4, t6, 100b

101:
	/* Process found bytes. */
	CINSN(addi)	CREG(a0), CREG(a0), -(SZREG-1)
	not		t4, t4
	countz		t4 t4
#ifdef BYTEREG
	not		t3, t3
	countz		t3 t3
	minu		t5, t3, t4
	srli		t4, t5, 3
#else
	srli		t4, t4, 3
#endif
	add		CREG(a0), CREG(a0), t4
#ifdef BYTEREG
	beq		t5, t3, .Lfound
#endif
	j		.Lnot_found

102:
.endm


/* Actual function implementation. */
.align 3
SYM_FUNC_START(FUNCNAME)
	mv	t0, a0

#ifdef BYTEREG
	/*
	 * Normalize the compare byte. Don't use sext.b because ZBB might
	 * not be available.
	 */
	andi		BYTEREG, BYTEREG, 0xff
#endif

#ifdef LIMITREG
	/*
	 * Calculate user provided limit in t2. If the addtion
	 * overflows keep it as is but use the byte wise loop.
	 */
	add		t2, a0, LIMITREG
	bltu		t2, a0, .Lpost_loop
#endif

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
#ifdef LIMITREG
	bleu		t2, t1, .Lpost_loop
#endif
	byte_loop	1, t1

	/* Calculate end address for word sized loop. */
#ifdef CONFIG_CHERI_KERNEL
	gcbase		t3, CREG(a0)
	gclen		t1, CREG(a0)
	add		t1, t1, t3
	bltu		t1, a0, .Lpost_loop
#ifdef LIMITREG
	minu		t1, t1, t2
#endif
	andi		t1, t1, -SZREG
#elif defined(LIMITREG)
	andi		t1, t2, -SZREG
#endif
#if defined(CONFIG_CHERI_KERNEL) || defined(LIMITREG)
	word_loop	1, t1
#else
	word_loop	0, nolimit
#endif

.option pop

#endif

.align 3
.Lpost_loop:
	/* For the rest do a bytewise search. */
#ifdef LIMITREG
	byte_loop	1, t2
#else
	byte_loop	0, nolimit
#endif

	EPILOG

SYM_FUNC_END(FUNCNAME)
SYM_FUNC_ALIAS(CONCATENATE(__pi_, FUNCNAME), FUNCNAME)
EXPORT_SYMBOL(FUNCNAME)
