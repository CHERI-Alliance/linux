/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2017 Andes Technology Corporation */

#include <linux/init.h>
#include <linux/linkage.h>
#include <linux/export.h>
#include <asm/asm.h>
#include <asm/csr.h>
#include <asm/unistd.h>
#include <asm/thread_info.h>
#include <asm/asm-offsets.h>
#include <asm/ftrace.h>

	.text

#define ABI_SIZE_ON_STACK	80
#define ABI_A0			0
#define ABI_A1			8
#define ABI_A2			16
#define ABI_A3			24
#define ABI_A4			32
#define ABI_A5			40
#define ABI_A6			48
#define ABI_A7			56
#define ABI_T0			64
#define ABI_RA			72

	.macro SAVE_ABI
	addi	sp, sp, -ABI_SIZE_ON_STACK

	REG_S	a0, ABI_A0(sp)
	REG_S	a1, ABI_A1(sp)
	REG_S	a2, ABI_A2(sp)
	REG_S	a3, ABI_A3(sp)
	REG_S	a4, ABI_A4(sp)
	REG_S	a5, ABI_A5(sp)
	REG_S	a6, ABI_A6(sp)
	REG_S	a7, ABI_A7(sp)
	REG_S	t0, ABI_T0(sp)
	REG_S	ra, ABI_RA(sp)
	.endm

	.macro RESTORE_ABI
	REG_L	a0, ABI_A0(sp)
	REG_L	a1, ABI_A1(sp)
	REG_L	a2, ABI_A2(sp)
	REG_L	a3, ABI_A3(sp)
	REG_L	a4, ABI_A4(sp)
	REG_L	a5, ABI_A5(sp)
	REG_L	a6, ABI_A6(sp)
	REG_L	a7, ABI_A7(sp)
	REG_L	t0, ABI_T0(sp)
	REG_L	ra, ABI_RA(sp)

	addi	sp, sp, ABI_SIZE_ON_STACK
	.endm

/**
* SAVE_ABI_REGS - save regs against the ftrace_regs struct
*
* After the stack is established,
*
* 0(sp) stores the PC of the traced function which can be accessed
* by &(fregs)->epc in tracing function.
*
* 8(sp) (or 16(sp) for cheri) stores the function return address (i.e. parent
* IP) that can be accessed by &(fregs)->ra in tracing function.
*
* The other regs are saved at the respective localtion and accessed
* by the respective ftrace_regs member.
*
* Here is the layout of stack for your reference.
*
* PT_SIZE_ON_STACK  ->  +++++++++
*                       + ..... +
*                       + a0-a7 + --++++-> ftrace_caller saved
*                       + t1    + --++++-> direct tramp address
*                       + s0    + --+ // frame pointer
*                       + sp    +   +
*                       + ra    + --+ // parent IP
*               sp  ->  + epc   + --+ // PC
*                       +++++++++
**/
	.macro SAVE_ABI_REGS
	CINSN(addi)	CREG(sp), CREG(sp), -FREGS_SIZE_ON_STACK
	CREG_S	CREG(t0),  FREGS_EPC(CREG(sp))
	CREG_S	CREG(x1),  FREGS_RA(CREG(sp))
#ifdef HAVE_FUNCTION_GRAPH_FP_TEST
	CREG_S	CREG(x8),  FREGS_S0(CREG(sp))
#endif
	CREG_S	CREG(x6),  FREGS_T1(CREG(sp))
#ifdef CONFIG_CC_IS_CLANG
	CREG_S	CREG(x7),  FREGS_T2(CREG(sp))
	CREG_S	CREG(x28), FREGS_T3(CREG(sp))
	CREG_S	CREG(x29), FREGS_T4(CREG(sp))
	CREG_S	CREG(x30), FREGS_T5(CREG(sp))
	CREG_S	CREG(x31), FREGS_T6(CREG(sp))
#endif
	// save the arguments
	CREG_S	CREG(x10), FREGS_A0(CREG(sp))
	CREG_S	CREG(x11), FREGS_A1(CREG(sp))
	CREG_S	CREG(x12), FREGS_A2(CREG(sp))
	CREG_S	CREG(x13), FREGS_A3(CREG(sp))
	CREG_S	CREG(x14), FREGS_A4(CREG(sp))
	CREG_S	CREG(x15), FREGS_A5(CREG(sp))
	CREG_S	CREG(x16), FREGS_A6(CREG(sp))
	CREG_S	CREG(x17), FREGS_A7(CREG(sp))
	mv	CREG(a0), CREG(sp)
	CINSN(addi)	CREG(a0), CREG(a0), FREGS_SIZE_ON_STACK
	CREG_S	CREG(a0), FREGS_SP(CREG(sp))	// Put original SP on stack
	.endm

	.macro RESTORE_ABI_REGS
	CREG_L	CREG(t0), FREGS_EPC(CREG(sp))
	CREG_L	CREG(x1), FREGS_RA(CREG(sp))
#ifdef HAVE_FUNCTION_GRAPH_FP_TEST
	CREG_L	CREG(x8), FREGS_S0(CREG(sp))
#endif
	CREG_L	CREG(x6),  FREGS_T1(CREG(sp))
#ifdef CONFIG_CC_IS_CLANG
	CREG_L	CREG(x7),  FREGS_T2(CREG(sp))
	CREG_L	CREG(x28), FREGS_T3(CREG(sp))
	CREG_L	CREG(x29), FREGS_T4(CREG(sp))
	CREG_L	CREG(x30), FREGS_T5(CREG(sp))
	CREG_L	CREG(x31), FREGS_T6(CREG(sp))
#endif
	// restore the arguments
	CREG_L	CREG(x10), FREGS_A0(CREG(sp))
	CREG_L	CREG(x11), FREGS_A1(CREG(sp))
	CREG_L	CREG(x12), FREGS_A2(CREG(sp))
	CREG_L	CREG(x13), FREGS_A3(CREG(sp))
	CREG_L	CREG(x14), FREGS_A4(CREG(sp))
	CREG_L	CREG(x15), FREGS_A5(CREG(sp))
	CREG_L	CREG(x16), FREGS_A6(CREG(sp))
	CREG_L	CREG(x17), FREGS_A7(CREG(sp))

	CINSN(addi)	CREG(sp), CREG(sp), FREGS_SIZE_ON_STACK
	.endm

	.macro PREPARE_ARGS
	CINSN(addi)	CREG(a0), CREG(t0), -MCOUNT_JALR_SIZE	// ip (callsite's jalr insn)
#ifdef CONFIG_DYNAMIC_FTRACE_WITH_CALL_OPS
	mv	CREG(a1), CREG(ra)			// parent_ip
	CREG_L	CREG(a2), FTRACE_CALLER_OP(CREG(t0))	// op
	CREG_L	CREG(ra), FTRACE_OPS_FUNC(CREG(a2))	// op->func
#else
	la	a1, function_trace_op
	REG_L	a2, 0(a1)			// op
	mv	a1, ra				// parent_ip
#endif
	mv	CREG(a3), CREG(sp)		// regs
	.endm

SYM_FUNC_START(ftrace_caller)
#ifdef CONFIG_DYNAMIC_FTRACE_WITH_CALL_OPS

	/*
	 * When CALL_OPS is enabled (2, 4 or 8) nops [8B or 16B] are placed
	 * before the function entry, these are later overwritten with the
	 * pointer/capability of the associated struct ftrace_ops.
	 *
	 * -8 / -16: &ftrace_ops of the associated tracer function.
	 *<ftrace enable>:
	 *  0: auipc  t0/ra, 0x?
	 *  4: jalr   t0/ra, ?(t0/ra)
	 *
	 * -8 / -16: &ftrace_nop_ops
	 *<ftrace disable>:
	 *  0: nop
	 *  4: nop
	 *
	 * t0 is set to ip+8 after the jalr is executed at the callsite, so we
	 * find the associated op at t0-16 (non-cheri) or t0-24 (cheri).
	 */
#ifdef CONFIG_CHERI_KERNEL
	/*
	 * ct0 is sealed, it can't be used for reading the ops struct.
	 * Create new capability with t0's address and pcc's permissions
	 * (assuming pcc grants read permission and covers the data sections).
	 * Use ct1 as temp register for this "unsealing". llvm may use ct2-ct6
	 * for function parameters, see commit f8693f6dffcd ("riscv: ftrace:
	 * support fastcc in Clang for WITH_ARGS").
	 */
	auipc ct1, 0
	scaddr ct0, ct1, t0
#endif
	CREG_L CREG(t1), FTRACE_CALLER_OP(CREG(t0))

#ifdef CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS
	/*
	 * If the op has a direct call, handle it immediately without
	 * saving/restoring registers.
	 */
	REG_L	t1, FTRACE_OPS_DIRECT_CALL(t1)
	bnez	t1, ftrace_caller_direct
#endif
#endif
	SAVE_ABI_REGS
	PREPARE_ARGS

#ifdef CONFIG_DYNAMIC_FTRACE_WITH_CALL_OPS
	jalr	0(CREG(ra))
#else
SYM_INNER_LABEL(ftrace_call, SYM_L_GLOBAL)
	REG_L	ra, ftrace_call_dest
	jalr	ra, 0(ra)
#endif
	RESTORE_ABI_REGS
#ifdef CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS
	bnez	t1, ftrace_caller_direct
#endif
	jr	CREG(t0)
#ifdef CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS
SYM_INNER_LABEL(ftrace_caller_direct, SYM_L_LOCAL)
	jr	t1
#endif
SYM_FUNC_END(ftrace_caller)

#ifdef CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS
SYM_CODE_START(ftrace_stub_direct_tramp)
	jr	t0
SYM_CODE_END(ftrace_stub_direct_tramp)
#endif /* CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS */
