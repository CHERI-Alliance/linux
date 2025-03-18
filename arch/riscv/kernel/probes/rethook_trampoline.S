/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Author: Patrick Stählin <me@packi.ch>
 */
#include <linux/linkage.h>

#include <asm/asm.h>
#include <asm/asm-offsets.h>

	.text
	.altmacro

	.macro save_all_base_regs
	CREG_S CREG(1),  PT_RA(CREG(sp))
	CREG_S CREG(3),  PT_GP(CREG(sp))
	CREG_S CREG(4),  PT_TP(CREG(sp))
	CREG_S CREG(5),  PT_T0(CREG(sp))
	CREG_S CREG(6),  PT_T1(CREG(sp))
	CREG_S CREG(7),  PT_T2(CREG(sp))
	CREG_S CREG(8),  PT_S0(CREG(sp))
	CREG_S CREG(9),  PT_S1(CREG(sp))
	CREG_S CREG(10), PT_A0(CREG(sp))
	CREG_S CREG(11), PT_A1(CREG(sp))
	CREG_S CREG(12), PT_A2(CREG(sp))
	CREG_S CREG(13), PT_A3(CREG(sp))
	CREG_S CREG(14), PT_A4(CREG(sp))
	CREG_S CREG(15), PT_A5(CREG(sp))
	CREG_S CREG(16), PT_A6(CREG(sp))
	CREG_S CREG(17), PT_A7(CREG(sp))
	CREG_S CREG(18), PT_S2(CREG(sp))
	CREG_S CREG(19), PT_S3(CREG(sp))
	CREG_S CREG(20), PT_S4(CREG(sp))
	CREG_S CREG(21), PT_S5(CREG(sp))
	CREG_S CREG(22), PT_S6(CREG(sp))
	CREG_S CREG(23), PT_S7(CREG(sp))
	CREG_S CREG(24), PT_S8(CREG(sp))
	CREG_S CREG(25), PT_S9(CREG(sp))
	CREG_S CREG(26), PT_S10(CREG(sp))
	CREG_S CREG(27), PT_S11(CREG(sp))
	CREG_S CREG(28), PT_T3(CREG(sp))
	CREG_S CREG(29), PT_T4(CREG(sp))
	CREG_S CREG(30), PT_T5(CREG(sp))
	CREG_S CREG(31), PT_T6(CREG(sp))
	.endm

	.macro restore_all_base_regs
	CREG_L CREG(3),  PT_GP(CREG(sp))
	CREG_L CREG(4),  PT_TP(CREG(sp))
	CREG_L CREG(5),  PT_T0(CREG(sp))
	CREG_L CREG(6),  PT_T1(CREG(sp))
	CREG_L CREG(7),  PT_T2(CREG(sp))
	CREG_L CREG(8),  PT_S0(CREG(sp))
	CREG_L CREG(9),  PT_S1(CREG(sp))
	CREG_L CREG(10), PT_A0(CREG(sp))
	CREG_L CREG(11), PT_A1(CREG(sp))
	CREG_L CREG(12), PT_A2(CREG(sp))
	CREG_L CREG(13), PT_A3(CREG(sp))
	CREG_L CREG(14), PT_A4(CREG(sp))
	CREG_L CREG(15), PT_A5(CREG(sp))
	CREG_L CREG(16), PT_A6(CREG(sp))
	CREG_L CREG(17), PT_A7(CREG(sp))
	CREG_L CREG(18), PT_S2(CREG(sp))
	CREG_L CREG(19), PT_S3(CREG(sp))
	CREG_L CREG(20), PT_S4(CREG(sp))
	CREG_L CREG(21), PT_S5(CREG(sp))
	CREG_L CREG(22), PT_S6(CREG(sp))
	CREG_L CREG(23), PT_S7(CREG(sp))
	CREG_L CREG(24), PT_S8(CREG(sp))
	CREG_L CREG(25), PT_S9(CREG(sp))
	CREG_L CREG(26), PT_S10(CREG(sp))
	CREG_L CREG(27), PT_S11(CREG(sp))
	CREG_L CREG(28), PT_T3(CREG(sp))
	CREG_L CREG(29), PT_T4(CREG(sp))
	CREG_L CREG(30), PT_T5(CREG(sp))
	CREG_L CREG(31), PT_T6(CREG(sp))
	.endm

SYM_CODE_START(arch_rethook_trampoline)
	CREG(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)
	save_all_base_regs

	mv CREG(a0), CREG(sp) /* pt_regs */

	call arch_rethook_trampoline_callback

	/* use the result as the return-address */
	mv CREG(ra), CREG(a0)

	restore_all_base_regs
	CREG(addi) CREG(sp), CREG(sp), PT_SIZE_ON_STACK

	ret
SYM_CODE_END(arch_rethook_trampoline)
