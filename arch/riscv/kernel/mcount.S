/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2017 Andes Technology Corporation */

#include <linux/init.h>
#include <linux/linkage.h>
#include <linux/cfi_types.h>
#include <linux/export.h>
#include <asm/asm.h>
#include <asm/asmcheri.h>
#include <asm/csr.h>
#include <asm/unistd.h>
#include <asm/thread_info.h>
#include <asm/asm-offsets.h>
#include <asm/ftrace.h>

	.text

	.macro SAVE_ABI_STATE
	CINSN(addi)	CREG(sp), CREG(sp), -2*CSZREG
	CREG_S		CREG(s0), 0*CSZREG(CREG(sp))
	CREG_S		CREG(ra), 1*CSZREG(CREG(sp))
	CINSN(addi)	CREG(s0), CREG(sp), 2*CSZREG
	.endm

	/*
	 * The call to ftrace_return_to_handler would overwrite the return
	 * register if a0 was not saved.
	 */
	.macro SAVE_RET_ABI_STATE
	CINSN(addi)	CREG(sp), CREG(sp), -FREGS_SIZE_ON_STACK
	CREG_S	CREG(ra), FREGS_RA(CREG(sp))
	CREG_S	CREG(s0), FREGS_S0(CREG(sp))
	CREG_S	CREG(a0), FREGS_A0(CREG(sp))
	CREG_S	CREG(a1), FREGS_A1(CREG(sp))
	CINSN(addi)	CREG(s0), CREG(sp), FREGS_SIZE_ON_STACK
	.endm

	.macro RESTORE_ABI_STATE
	CREG_L		CREG(ra), 1*CSZREG(CREG(sp))
	CREG_L		CREG(s0), 0*CSZREG(CREG(sp))
	CINSN(addi)	CREG(sp), CREG(sp), 2*CSZREG
	.endm

	.macro RESTORE_RET_ABI_STATE
	CREG_L	CREG(ra), FREGS_RA(CREG(sp))
	CREG_L	CREG(s0), FREGS_S0(CREG(sp))
	CREG_L	CREG(a0), FREGS_A0(CREG(sp))
	CREG_L	CREG(a1), FREGS_A1(CREG(sp))
	CINSN(addi)	CREG(sp), CREG(sp), FREGS_SIZE_ON_STACK
	.endm

SYM_TYPED_FUNC_START(ftrace_stub)
#ifdef CONFIG_DYNAMIC_FTRACE
       .global _mcount
       .set    _mcount, ftrace_stub
#endif
	ret
SYM_FUNC_END(ftrace_stub)

#ifdef CONFIG_FUNCTION_GRAPH_TRACER
SYM_TYPED_FUNC_START(ftrace_stub_graph)
	ret
SYM_FUNC_END(ftrace_stub_graph)

SYM_FUNC_START(return_to_handler)
/*
 * On implementing the frame point test, the ideal way is to compare the
 * s0 (frame pointer, if enabled) on entry and the sp (stack pointer) on return.
 * However, the psABI of variable-length-argument functions does not allow this.
 *
 * So alternatively we check the *old* frame pointer position, that is, the
 * value stored in -16(s0) on entry, and the s0 on return.
 */
	SAVE_RET_ABI_STATE
	mv	CREG(a0), CREG(sp)
	call	ftrace_return_to_handler
	mv	CREG(a2), CREG(a0)
	RESTORE_RET_ABI_STATE
	jalr	0(CREG(a2))
SYM_FUNC_END(return_to_handler)
#endif

#ifndef CONFIG_DYNAMIC_FTRACE
SYM_FUNC_START(_mcount)
	CINSN(la)	CREG(t4), ftrace_stub
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
	la	t0, ftrace_graph_return
	REG_L	t1, 0(t0)
	bne	t1, t4, .Ldo_ftrace_graph_caller

	la	t3, ftrace_graph_entry
	REG_L	t2, 0(t3)
	la	t6, ftrace_graph_entry_stub
	bne	t2, t6, .Ldo_ftrace_graph_caller
#endif
	la	t3, ftrace_trace_function
	CREG_L	CREG(t5), 0(CREG(t3))
	bne	t5, t4, .Ldo_trace
	ret

#ifdef CONFIG_FUNCTION_GRAPH_TRACER
/*
 * A pseudo representation for the function graph tracer:
 * prepare_to_return(&ra_to_caller_of_caller, ra_to_caller)
 */
.Ldo_ftrace_graph_caller:
	addi	a0, s0, -SZREG
	mv	a1, ra
#ifdef HAVE_FUNCTION_GRAPH_FP_TEST
	REG_L	a2, -2*SZREG(s0)
#endif
	SAVE_ABI_STATE
	call	prepare_ftrace_return
	RESTORE_ABI_STATE
	ret
#endif

/*
 * A pseudo representation for the function tracer:
 * (*ftrace_trace_function)(ra_to_caller, ra_to_caller_of_caller, ops, fregs)
 */
.Ldo_trace:
	CREG_L	CREG(a1), -CSZREG(CREG(s0))
	mv	CREG(a0), CREG(ra)
	CINSN(la)	CREG(a2), function_trace_op
	CREG_L	CREG(a2), 0(CREG(a2))
	/* fregs = NULL */
	mv	CREG(a3), CREG(null)

	SAVE_ABI_STATE
	jalr	CREG(t5)
	RESTORE_ABI_STATE
	ret
SYM_FUNC_END(_mcount)
#endif
EXPORT_SYMBOL(_mcount)
