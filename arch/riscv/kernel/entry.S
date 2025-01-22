/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2017 SiFive
 */

#include <linux/init.h>
#include <linux/linkage.h>

#include <asm/asm.h>
#include <asm/csr.h>
#include <asm/scs.h>
#include <asm/unistd.h>
#include <asm/page.h>
#include <asm/thread_info.h>
#include <asm/asm-offsets.h>
#include <asm/errata_list.h>
#include <asm/asmcheri.h>
#include <linux/sizes.h>

#ifdef CONFIG_CHERI_KERNEL
.option capmode
#endif

	.section .irqentry.text, "ax"

SYM_CODE_START(handle_exception)
	/*
	 * If coming from userspace, preserve the user thread pointer and load
	 * the kernel thread pointer.  If we came from the kernel, the scratch
	 * register will contain 0, and we should continue on the current TP.
	 */
#ifndef CONFIG_CHERI_KERNEL
	csrrw tp, CSR_SCRATCH, tp
#else
	csrrw ctp, sscratchc, ctp
#endif
	bnez tp, .Lsave_context

.Lrestore_kernel_tpsp:
	csrr tp, CSR_SCRATCH
	CREG_S CREG(sp), TASK_TI_KERNEL_SP(CREG(tp))

#ifdef CONFIG_VMAP_STACK
	addi sp, sp, -(PT_SIZE_ON_STACK)
	srli sp, sp, THREAD_SHIFT
	andi sp, sp, 0x1
	bnez sp, handle_kernel_stack_overflow
	CREG_L CREG(sp), TASK_TI_KERNEL_SP(CREG(tp))
#endif

.Lsave_context:
	CREG_S CREG(sp), TASK_TI_USER_SP(CREG(tp))
	CREG_L CREG(sp), TASK_TI_KERNEL_SP(CREG(tp))
	CREG(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)
	CREG_S CREGX(1),  PT_RA(CREG(sp))
	CREG_S CREGX(3),  PT_GP(CREG(sp))
	CREG_S CREGX(5),  PT_T0(CREG(sp))
	save_from_x6_to_x31

#ifdef CONFIG_CHERI_KERNEL
	/* store and clear ddc */
	ccsrr t0, ddc
	sc ct0, PT_DDC(csp)
	ccsrw ddc, zero
#endif

	/*
	 * Disable user-mode memory access as it should only be set in the
	 * actual user copy routines.
	 *
	 * Disable the FPU/Vector to detect illegal usage of floating point
	 * or vector in kernel space.
	 */
	li t0, SR_SUM | SR_FS_VS

	CREG_L CREG(s0), TASK_TI_USER_SP(CREG(tp))
	csrrc s1, CSR_STATUS, t0
	csrr s2, CSR_EPC
	csrr s3, CSR_TVAL
	csrr s4, CSR_CAUSE
	csrr s5, CSR_SCRATCH
	CREG_S CREG(s0), PT_SP(CREG(sp))
	REG_S s1, PT_STATUS(CREG(sp))
	CREG_S CREG(s2), PT_EPC(CREG(sp))
	REG_S s3, PT_BADADDR(CREG(sp))
	REG_S s4, PT_CAUSE(CREG(sp))
	CREG_S CREG(s5), PT_TP(CREG(sp))

	/*
	 * Set the scratch register to 0, so that if a recursive exception
	 * occurs, the exception vector knows it came from the kernel
	 */
	csrw CSR_SCRATCH, x0

	/* Load the global pointer */
	load_global_pointer

	/* Load the kernel shadow call stack pointer if coming from userspace */
	scs_load_current_if_task_changed CREG(s5)

#ifdef CONFIG_RISCV_ISA_V_PREEMPTIVE
	mv CREG(a0), CREG(sp)
	call riscv_v_context_nesting_start
#endif
	mv CREG(a0), CREG(sp) /* pt_regs */
	la ra, ret_from_exception

	/*
	 * MSB of cause differentiates between
	 * interrupts and exceptions
	 */
	bge s4, zero, 1f

	/* Handle interrupts */
	tail do_irq
1:
	/* Handle other exceptions */
	slli t0, s4, RISCV_LGPTR
	la t1, excp_vect_table
	la t2, excp_vect_table_end
	add CREG(t0), CREG(t1), t0
	/* Check if exception code lies within bounds */
	bgeu t0, t2, 1f
	CREG_L CREG(t0), 0(CREG(t0))
	jr CREG(t0)
1:
	tail do_trap_unknown
SYM_CODE_END(handle_exception)
ASM_NOKPROBE(handle_exception)

/*
 * The ret_from_exception must be called with interrupt disabled. Here is the
 * caller list:
 *  - handle_exception
 *  - ret_from_fork
 */
SYM_CODE_START_NOALIGN(ret_from_exception)
	REG_L s0, PT_STATUS(CREG(sp))
#ifdef CONFIG_RISCV_M_MODE
	/* the MPP value is too large to be used as an immediate arg for addi */
	li t0, SR_MPP
	and s0, s0, t0
#else
	andi s0, s0, SR_SPP
#endif
	bnez s0, 1f

	/* Save unwound kernel stack pointer in thread_info */
	CREG(addi) CREG(s0), CREG(sp), PT_SIZE_ON_STACK
	CREG_S CREG(s0), TASK_TI_KERNEL_SP(CREG(tp))

	/* Save the kernel shadow call stack pointer */
	scs_save_current

	/*
	 * Save TP into the scratch register , so we can find the kernel data
	 * structures again.
	 */
	csrw CSR_SCRATCH, tp
1:
#ifdef CONFIG_RISCV_ISA_V_PREEMPTIVE
	mv CREG(a0), CREG(sp)
	call riscv_v_context_nesting_end
#endif
	REG_L a0, PT_STATUS(CREG(sp))
	/*
	 * The current load reservation is effectively part of the processor's
	 * state, in the sense that load reservations cannot be shared between
	 * different hart contexts.  We can't actually save and restore a load
	 * reservation, so instead here we clear any existing reservation --
	 * it's always legal for implementations to clear load reservations at
	 * any point (as long as the forward progress guarantee is kept, but
	 * we'll ignore that here).
	 *
	 * Dangling load reservations can be the result of taking a trap in the
	 * middle of an LR/SC sequence, but can also be the result of a taken
	 * forward branch around an SC -- which is how we implement CAS.  As a
	 * result we need to clear reservations between the last CAS and the
	 * jump back to the new context.  While it is unlikely the store
	 * completes, implementations are allowed to expand reservations to be
	 * arbitrarily large.
	 */
	CREG_L CREG(a2), PT_EPC(CREG(sp))
#ifndef CONFIG_CHERI_KERNEL
	REG_SC x0, a2, PT_EPC(sp)
#else
	sc.c x0, ca2, PT_EPC(csp)
#endif

	csrw CSR_STATUS, a0
	csrw CSR_EPC, a2

#ifdef CONFIG_CHERI_KERNEL
	/* restore ddc */
	lc ct0, PT_DDC(csp)
	ccsrw ddc, t0
#endif

	CREG_L CREGX(1),  PT_RA(CREG(sp))
	CREG_L CREGX(3),  PT_GP(CREG(sp))
	CREG_L CREGX(4),  PT_TP(CREG(sp))
	CREG_L CREGX(5),  PT_T0(CREG(sp))
	restore_from_x6_to_x31

	CREG_L CREGX(2),  PT_SP(CREG(sp))

#ifdef CONFIG_RISCV_M_MODE
	mret
#else
	sret
#endif
SYM_CODE_END(ret_from_exception)
ASM_NOKPROBE(ret_from_exception)

#ifdef CONFIG_VMAP_STACK
SYM_CODE_START_LOCAL(handle_kernel_stack_overflow)
	/* we reach here from kernel context, sscratch must be 0 */
#ifndef CONFIG_CHERI_KERNEL
	csrrw x31, CSR_SCRATCH, x31
#else
	csrrw CREGX(31), scratchc, CREGX(31)
#endif
	asm_per_cpu CREG(sp), overflow_stack, CREGX(31)
	li x31, OVERFLOW_STACK_SIZE
	add CREG(sp), CREG(sp), x31
	/* zero out x31 again and restore x31 */
#ifndef CONFIG_CHERI_KERNEL
	xor x31, x31, x31
	csrrw x31, CSR_SCRATCH, x31
#else
	mv CREGX(31), cnull
	csrrw CREGX(31), sscratchc, CREGX(31)
#endif

	CREG(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)

	//save context to overflow stack
	CREG_S CREGX(1),  PT_RA(CREG(sp))
	CREG_S CREGX(3),  PT_GP(CREG(sp))
	CREG_S CREGX(5),  PT_T0(CREG(sp))
	save_from_x6_to_x31

	CREG_L CREG(s0), TASK_TI_KERNEL_SP(CREG(tp))
	csrr s1, CSR_STATUS
	csrr s2, CSR_EPC
	csrr s3, CSR_TVAL
	csrr s4, CSR_CAUSE
	csrr s5, CSR_SCRATCH
	CREG_S CREG(s0), PT_SP(CREG(sp))
	REG_S s1, PT_STATUS(CREG(sp))
	CREG_S CREG(s2), PT_EPC(CREG(sp))
	REG_S s3, PT_BADADDR(CREG(sp))
	REG_S s4, PT_CAUSE(CREG(sp))
	CREG_S CREG(s5), PT_TP(CREG(sp))
	mv CREG(a0), CREG(sp)
	tail handle_bad_stack
SYM_CODE_END(handle_kernel_stack_overflow)
ASM_NOKPROBE(handle_kernel_stack_overflow)
#endif

SYM_CODE_START(ret_from_fork)
	call schedule_tail
	beqz s0, 1f	/* not from kernel thread */
	/* Call fn(arg) */
	mv CREG(a0), CREG(s1)
	jalr CREG(s0)
1:
	mv CREG(a0), CREG(sp) /* pt_regs */
	la ra, ret_from_exception
	tail syscall_exit_to_user_mode
SYM_CODE_END(ret_from_fork)

#ifdef CONFIG_IRQ_STACKS

/*
 * void call_on_irq_stack(struct pt_regs *regs,
 * 		          void (*func)(struct pt_regs *));
 *
 * Calls func(regs) using the per-CPU IRQ stack.
 */
SYM_FUNC_START(call_on_irq_stack)
	/* Create a frame record to save ra and s0 (fp) */
	CREG(addi)	CREG(sp), CREG(sp), -STACKFRAME_SIZE_ON_STACK
	CREG_S	CREG(ra), STACKFRAME_RA(CREG(sp))
	CREG_S	CREG(s0), STACKFRAME_FP(CREG(sp))
	CREG(addi)	CREG(s0), CREG(sp), STACKFRAME_SIZE_ON_STACK

	/* Switch to the per-CPU shadow call stack */
	scs_save_current
	scs_load_irq_stack t0

	/* Switch to the per-CPU IRQ stack and call the handler */
	load_per_cpu t0, irq_stack_ptr, t1
	li	t1, IRQ_STACK_SIZE
	add	CREG(sp), CREG(t0), t1
	jalr	CREG(a1)

	/* Switch back to the thread shadow call stack */
	scs_load_current

	/* Switch back to the thread stack and restore ra and s0 */
	CREG(addi)	CREG(sp), CREG(s0), -STACKFRAME_SIZE_ON_STACK
	CREG_L	CREG(ra), STACKFRAME_RA(CREG(sp))
	CREG_L	CREG(s0), STACKFRAME_FP(CREG(sp))
	CREG(addi)	CREG(sp), CREG(sp), STACKFRAME_SIZE_ON_STACK

	ret
SYM_FUNC_END(call_on_irq_stack)
#endif /* CONFIG_IRQ_STACKS */

/*
 * Integer register context switch
 * The callee-saved registers must be saved and restored.
 *
 *   a0: previous task_struct (must be preserved across the switch)
 *   a1: next task_struct
 *
 * The value of a0 and a1 must be preserved by this function, as that's how
 * arguments are passed to schedule_tail.
 */
SYM_FUNC_START(__switch_to)
	/* Save context into prev->thread */
	li    a4,  TASK_THREAD_RA
	add   CREG(a3), CREG(a0), a4
	add   CREG(a4), CREG(a1), a4
	CREG_S CREG(ra),  TASK_THREAD_RA_RA(CREG(a3))
	CREG_S CREG(sp),  TASK_THREAD_SP_RA(CREG(a3))
	CREG_S CREG(s0),  TASK_THREAD_S0_RA(CREG(a3))
	CREG_S CREG(s1),  TASK_THREAD_S1_RA(CREG(a3))
	CREG_S CREG(s2),  TASK_THREAD_S2_RA(CREG(a3))
	CREG_S CREG(s3),  TASK_THREAD_S3_RA(CREG(a3))
	CREG_S CREG(s4),  TASK_THREAD_S4_RA(CREG(a3))
	CREG_S CREG(s5),  TASK_THREAD_S5_RA(CREG(a3))
	CREG_S CREG(s6),  TASK_THREAD_S6_RA(CREG(a3))
	CREG_S CREG(s7),  TASK_THREAD_S7_RA(CREG(a3))
	CREG_S CREG(s8),  TASK_THREAD_S8_RA(CREG(a3))
	CREG_S CREG(s9),  TASK_THREAD_S9_RA(CREG(a3))
	CREG_S CREG(s10), TASK_THREAD_S10_RA(CREG(a3))
	CREG_S CREG(s11), TASK_THREAD_S11_RA(CREG(a3))
	/* Save the kernel shadow call stack pointer */
	scs_save_current
	/* Restore context from next->thread */
	CREG_L CREG(ra),  TASK_THREAD_RA_RA(CREG(a4))
	CREG_L CREG(sp),  TASK_THREAD_SP_RA(CREG(a4))
	CREG_L CREG(s0),  TASK_THREAD_S0_RA(CREG(a4))
	CREG_L CREG(s1),  TASK_THREAD_S1_RA(CREG(a4))
	CREG_L CREG(s2),  TASK_THREAD_S2_RA(CREG(a4))
	CREG_L CREG(s3),  TASK_THREAD_S3_RA(CREG(a4))
	CREG_L CREG(s4),  TASK_THREAD_S4_RA(CREG(a4))
	CREG_L CREG(s5),  TASK_THREAD_S5_RA(CREG(a4))
	CREG_L CREG(s6),  TASK_THREAD_S6_RA(CREG(a4))
	CREG_L CREG(s7),  TASK_THREAD_S7_RA(CREG(a4))
	CREG_L CREG(s8),  TASK_THREAD_S8_RA(CREG(a4))
	CREG_L CREG(s9),  TASK_THREAD_S9_RA(CREG(a4))
	CREG_L CREG(s10), TASK_THREAD_S10_RA(CREG(a4))
	CREG_L CREG(s11), TASK_THREAD_S11_RA(CREG(a4))
	/* The offset of thread_info in task_struct is zero. */
	mv CREG(tp), CREG(a1)
	/* Switch to the next shadow call stack */
	scs_load_current
	ret
SYM_FUNC_END(__switch_to)

#ifndef CONFIG_MMU
#define do_page_fault do_trap_unknown
#endif

#ifndef CONFIG_CHERI_KERNEL
	.section ".rodata"
	.align LGREG
#else
	.section ".data"
	.align CLGREG
#endif
	/* Exception vector table */
SYM_DATA_START_LOCAL(excp_vect_table)
	RISCV_PTR do_trap_insn_misaligned
	ALT_INSN_FAULT(RISCV_PTR do_trap_insn_fault)
	RISCV_PTR do_trap_insn_illegal
	RISCV_PTR do_trap_break
	RISCV_PTR do_trap_load_misaligned
	RISCV_PTR do_trap_load_fault
	RISCV_PTR do_trap_store_misaligned
	RISCV_PTR do_trap_store_fault
	RISCV_PTR do_trap_ecall_u /* system call */
	RISCV_PTR do_trap_ecall_s
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_ecall_m
	/* instruciton page fault */
	ALT_PAGE_FAULT(RISCV_PTR do_page_fault)
	RISCV_PTR do_page_fault   /* load page fault */
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_page_fault   /* store page fault */
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_trap_unknown
#ifndef CONFIG_CHERI_KERNEL
	RISCV_PTR do_trap_unknown
#else
	RISCV_PTR do_trap_cheri
#endif
SYM_DATA_END_LABEL(excp_vect_table, SYM_L_LOCAL, excp_vect_table_end)

#ifdef CONFIG_CHERI_KERNEL
	.align CLGREG
SYM_DATA_START(kernel_code_cap)
	RISCV_PTR 0
SYM_DATA_END(kernel_code_cap)
SYM_DATA_START(kernel_data_cap)
	RISCV_PTR 0
SYM_DATA_END(kernel_data_cap)
SYM_DATA_START(cheri_mbit_mask)
	.dword 0
SYM_DATA_END(cheri_mbit_mask)
SYM_DATA_START(cheri_mbit_value)
	.dword 0
SYM_DATA_END(cheri_mbit_value)
SYM_DATA_START(scmode_capmode_value)
	.byte 0
SYM_DATA_END(scmode_capmode_value)
SYM_DATA_START(cheri_hybrid_support)
	.byte 0
SYM_DATA_END(cheri_hybrid_support)
SYM_DATA_START(acperm_legacy)
	.byte 0
SYM_DATA_END(acperm_legacy)
SYM_DATA_START(has_xtval2)
	.byte 0
SYM_DATA_END(has_xtval2)
SYM_DATA_START(has_cheri_levels)
	.byte 0
SYM_DATA_END(has_cheri_levels)
#endif

#ifndef CONFIG_CHERI_KERNEL
	.section ".rodata"
	.align LGREG
#endif

#ifndef CONFIG_MMU
SYM_DATA_START(__user_rt_sigreturn)
	li a7, __NR_rt_sigreturn
	ecall
SYM_DATA_END(__user_rt_sigreturn)
#endif
