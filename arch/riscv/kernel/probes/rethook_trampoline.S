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
	CREG_S CREG(x1),  PT_RA(CREG(sp))
	CREG_S CREG(x3),  PT_GP(CREG(sp))
	CREG_S CREG(x4),  PT_TP(CREG(sp))
	CREG_S CREG(x5),  PT_T0(CREG(sp))
	CREG_S CREG(x6),  PT_T1(CREG(sp))
	CREG_S CREG(x7),  PT_T2(CREG(sp))
	CREG_S CREG(x8),  PT_S0(CREG(sp))
	CREG_S CREG(x9),  PT_S1(CREG(sp))
	CREG_S CREG(x10), PT_A0(CREG(sp))
	CREG_S CREG(x11), PT_A1(CREG(sp))
	CREG_S CREG(x12), PT_A2(CREG(sp))
	CREG_S CREG(x13), PT_A3(CREG(sp))
	CREG_S CREG(x14), PT_A4(CREG(sp))
	CREG_S CREG(x15), PT_A5(CREG(sp))
	CREG_S CREG(x16), PT_A6(CREG(sp))
	CREG_S CREG(x17), PT_A7(CREG(sp))
	CREG_S CREG(x18), PT_S2(CREG(sp))
	CREG_S CREG(x19), PT_S3(CREG(sp))
	CREG_S CREG(x20), PT_S4(CREG(sp))
	CREG_S CREG(x21), PT_S5(CREG(sp))
	CREG_S CREG(x22), PT_S6(CREG(sp))
	CREG_S CREG(x23), PT_S7(CREG(sp))
	CREG_S CREG(x24), PT_S8(CREG(sp))
	CREG_S CREG(x25), PT_S9(CREG(sp))
	CREG_S CREG(x26), PT_S10(CREG(sp))
	CREG_S CREG(x27), PT_S11(CREG(sp))
	CREG_S CREG(x28), PT_T3(CREG(sp))
	CREG_S CREG(x29), PT_T4(CREG(sp))
	CREG_S CREG(x30), PT_T5(CREG(sp))
	CREG_S CREG(x31), PT_T6(CREG(sp))
	.endm

	.macro restore_all_base_regs
	CREG_L CREG(x3),  PT_GP(CREG(sp))
	CREG_L CREG(x4),  PT_TP(CREG(sp))
	CREG_L CREG(x5),  PT_T0(CREG(sp))
	CREG_L CREG(x6),  PT_T1(CREG(sp))
	CREG_L CREG(x7),  PT_T2(CREG(sp))
	CREG_L CREG(x8),  PT_S0(CREG(sp))
	CREG_L CREG(x9),  PT_S1(CREG(sp))
	CREG_L CREG(x10), PT_A0(CREG(sp))
	CREG_L CREG(x11), PT_A1(CREG(sp))
	CREG_L CREG(x12), PT_A2(CREG(sp))
	CREG_L CREG(x13), PT_A3(CREG(sp))
	CREG_L CREG(x14), PT_A4(CREG(sp))
	CREG_L CREG(x15), PT_A5(CREG(sp))
	CREG_L CREG(x16), PT_A6(CREG(sp))
	CREG_L CREG(x17), PT_A7(CREG(sp))
	CREG_L CREG(x18), PT_S2(CREG(sp))
	CREG_L CREG(x19), PT_S3(CREG(sp))
	CREG_L CREG(x20), PT_S4(CREG(sp))
	CREG_L CREG(x21), PT_S5(CREG(sp))
	CREG_L CREG(x22), PT_S6(CREG(sp))
	CREG_L CREG(x23), PT_S7(CREG(sp))
	CREG_L CREG(x24), PT_S8(CREG(sp))
	CREG_L CREG(x25), PT_S9(CREG(sp))
	CREG_L CREG(x26), PT_S10(CREG(sp))
	CREG_L CREG(x27), PT_S11(CREG(sp))
	CREG_L CREG(x28), PT_T3(CREG(sp))
	CREG_L CREG(x29), PT_T4(CREG(sp))
	CREG_L CREG(x30), PT_T5(CREG(sp))
	CREG_L CREG(x31), PT_T6(CREG(sp))
	.endm

SYM_CODE_START(arch_rethook_trampoline)
	CINSN(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)
	save_all_base_regs

	mv CREG(a0), CREG(sp) /* pt_regs */

	call arch_rethook_trampoline_callback

	/* use the result as the return-address */
	mv CREG(ra), CREG(a0)

	restore_all_base_regs
	CINSN(addi) CREG(sp), CREG(sp), PT_SIZE_ON_STACK

	ret
SYM_CODE_END(arch_rethook_trampoline)
