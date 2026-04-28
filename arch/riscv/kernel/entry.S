/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2017 SiFive
 */

#include <linux/init.h>
#include <linux/linkage.h>

#include <asm/alternative-macros.h>
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

.macro new_vmalloc_check
	CREG_S 	CREG(a0), TASK_TI_A0(CREG(tp))
	csrr 	a0, CSR_CAUSE
	/* Exclude IRQs */
	blt  	a0, zero, .Lnew_vmalloc_restore_context_a0

	CREG_S 	CREG(a1), TASK_TI_A1(CREG(tp))
	/* Only check new_vmalloc if we are in page/protection fault */
	li   	a1, EXC_LOAD_PAGE_FAULT
	beq  	a0, a1, .Lnew_vmalloc_kernel_address
	li   	a1, EXC_STORE_PAGE_FAULT
	beq  	a0, a1, .Lnew_vmalloc_kernel_address
	li   	a1, EXC_INST_PAGE_FAULT
	bne  	a0, a1, .Lnew_vmalloc_restore_context_a1

.Lnew_vmalloc_kernel_address:
	/* Is it a kernel address? */
	csrr 	a0, CSR_TVAL
	bge 	a0, zero, .Lnew_vmalloc_restore_context_a1

	/* Check if a new vmalloc mapping appeared that could explain the trap */
	CREG_S	CREG(a2), TASK_TI_A2(CREG(tp))
	/*
	 * Computes:
	 * a0 = &new_vmalloc[BIT_WORD(cpu)]
	 * a1 = BIT_MASK(cpu)
	 */
	lw	a2, TASK_TI_CPU(CREG(tp))
	/*
	 * Compute the new_vmalloc element position:
	 * (cpu / 64) * 8 = (cpu >> 6) << 3
	 */
	srli	a1, a2, 6
	slli	a1, a1, 3
#ifdef CONFIG_CHERI_KERNEL
	lgc	ca0, new_vmalloc
#else
	la	a0, new_vmalloc
#endif
	add	CREG(a0), CREG(a0), a1
	/*
	 * Compute the bit position in the new_vmalloc element:
	 * bit_pos = cpu % 64 = cpu - (cpu / 64) * 64 = cpu - (cpu >> 6) << 6
	 * 	   = cpu - ((cpu >> 6) << 3) << 3
	 */
	slli	a1, a1, 3
	sub	a1, a2, a1
	/* Compute the "get mask": 1 << bit_pos */
	li	a2, 1
	sll	a1, a2, a1

	/* Check the value of new_vmalloc for this cpu */
	REG_L	a2, 0(CREG(a0))
	and	a2, a2, a1
	beq	a2, zero, .Lnew_vmalloc_restore_context

	/* Atomically reset the current cpu bit in new_vmalloc */
	amoxor.d	a0, a1, (CREG(a0))

	/* Only emit a sfence.vma if the uarch caches invalid entries */
	ALTERNATIVE("sfence.vma", "nop", 0, RISCV_ISA_EXT_SVVPTC, 1)

	CREG_L	CREG(a0), TASK_TI_A0(CREG(tp))
	CREG_L	CREG(a1), TASK_TI_A1(CREG(tp))
	CREG_L	CREG(a2), TASK_TI_A2(CREG(tp))
	csrw	CSR_SCRATCH, x0
	sret

.Lnew_vmalloc_restore_context:
	CREG_L 	CREG(a2), TASK_TI_A2(CREG(tp))
.Lnew_vmalloc_restore_context_a1:
	CREG_L 	CREG(a1), TASK_TI_A1(CREG(tp))
.Lnew_vmalloc_restore_context_a0:
	CREG_L	CREG(a0), TASK_TI_A0(CREG(tp))
.endm

/*
 * If previous mode was U, capture shadow stack pointer and save it away
 * Zero CSR_SSP at the same time for sanitization.
 */
.macro save_userssp tmp, ctmp, status
	ALTERNATIVE("nops(4)",
		__stringify(				\
		andi \tmp, \status, SR_SPP;		\
		bnez \tmp, skip_ssp_save;		\
		csrrw \ctmp, CSR_SSP, CREG(x0);		\
		CREG_S \ctmp, TASK_TI_USER_SSP(CREG(tp));	\
		skip_ssp_save:),
		0,
		RISCV_ISA_EXT_ZICFISS,
		CONFIG_RISCV_USER_CFI)
.endm

.macro restore_userssp tmp, ctmp, status
	ALTERNATIVE("nops(4)",
		__stringify(				\
		andi \tmp, \status, SR_SPP;		\
		bnez \tmp, skip_ssp_restore;		\
		CREG_L \ctmp, TASK_TI_USER_SSP(CREG(tp0));	\
		csrw CSR_SSP, \ctmp;			\
		skip_ssp_restore:),
		0,
		RISCV_ISA_EXT_ZICFISS,
		CONFIG_RISCV_USER_CFI)
.endm

SYM_CODE_START(handle_exception)
	/*
	 * If coming from userspace, preserve the user thread pointer and load
	 * the kernel thread pointer.  If we came from the kernel, the scratch
	 * register will contain 0, and we should continue on the current TP.
	 */
	csrrw CREG(tp), CSR_SCRATCH, CREG(tp)
	bnez tp, .Lsave_context

.Lrestore_kernel_tpsp:
	csrr tp, CSR_SCRATCH

#ifdef CONFIG_64BIT
	/*
	 * The RISC-V kernel does not eagerly emit a sfence.vma after each
	 * new vmalloc mapping, which may result in exceptions:
	 * - if the uarch caches invalid entries, the new mapping would not be
	 *   observed by the page table walker and an invalidation is needed.
	 * - if the uarch does not cache invalid entries, a reordered access
	 *   could "miss" the new mapping and traps: in that case, we only need
	 *   to retry the access, no sfence.vma is required.
	 */
	new_vmalloc_check
#endif

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
	CINSN(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)
	CREG_S CREG(x1),  PT_RA(CREG(sp))
	CREG_S CREG(x3),  PT_GP(CREG(sp))
	CREG_S CREG(x5),  PT_T0(CREG(sp))
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
#ifdef CONFIG_64BIT
	li t1, SR_ELP
	or t0, t0, t1
#endif

	CREG_L CREG(s0), TASK_TI_USER_SP(CREG(tp))
	csrrc s1, CSR_STATUS, t0
	save_userssp s2, CREG(s2), s1
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
	scs_load_current_if_task_changed s5

#ifdef CONFIG_RISCV_ISA_V_PREEMPTIVE
	mv CREG(a0), CREG(sp)
	call riscv_v_context_nesting_start
#endif
	mv CREG(a0), CREG(sp) /* pt_regs */

	/*
	 * MSB of cause differentiates between
	 * interrupts and exceptions
	 */
	bge s4, zero, 1f

	/* Handle interrupts */
	call do_irq
	j ret_from_exception
1:
	/* Handle other exceptions */
	slli t0, s4, RISCV_LGPTR
	la t1, excp_vect_table
	la t2, excp_vect_table_end
	add CREG(t0), CREG(t1), t0
	/* Check if exception code lies within bounds */
	bgeu t0, t2, 3f
	CREG_L CREG(t1), 0(CREG(t0))
2:	jalr CREG(t1)
	j ret_from_exception
3:

	la t1, do_trap_unknown
	j 2b
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

#ifdef CONFIG_KSTACK_ERASE
	call	stackleak_erase_on_task_stack
#endif

	/* Save unwound kernel stack pointer in thread_info */
	CINSN(addi) CREG(s0), CREG(sp), PT_SIZE_ON_STACK
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
	restore_userssp s3, CREG(s3), a0
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

	CREG_L CREG(x1),  PT_RA(CREG(sp))
	CREG_L CREG(x3),  PT_GP(CREG(sp))
	CREG_L CREG(x4),  PT_TP(CREG(sp))
	CREG_L CREG(x5),  PT_T0(CREG(sp))
	restore_from_x6_to_x31

	CREG_L CREG(x2),  PT_SP(CREG(sp))

#ifdef CONFIG_RISCV_M_MODE
	mret
#else
	sret
#endif
SYM_INNER_LABEL(ret_from_exception_end, SYM_L_GLOBAL)
#ifdef CONFIG_CHERI_KERNEL
.size ret_from_exception_end, 1
#endif
SYM_CODE_END(ret_from_exception)
ASM_NOKPROBE(ret_from_exception)

#ifdef CONFIG_VMAP_STACK
SYM_CODE_START_LOCAL(handle_kernel_stack_overflow)
	/* we reach here from kernel context, sscratch must be 0 */
	csrrw CREG(x31), CSR_SCRATCH, CREG(x31)
	asm_per_cpu CREG(sp), overflow_stack, t6
	li x31, OVERFLOW_STACK_SIZE
	add CREG(sp), CREG(sp), x31
	/* zero out x31 again and restore x31 */
	xor x31, x31, x31
	csrrw CREG(x31), CSR_SCRATCH, CREG(x31)

	CINSN(addi) CREG(sp), CREG(sp), -(PT_SIZE_ON_STACK)

	//save context to overflow stack
	CREG_S CREG(x1),  PT_RA(CREG(sp))
	CREG_S CREG(x3),  PT_GP(CREG(sp))
	CREG_S CREG(x5),  PT_T0(CREG(sp))
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

SYM_CODE_START(ret_from_fork_kernel_asm)
	call schedule_tail
	mv CREG(a0), CREG(s1) /* fn_arg */
	mv CREG(a1), CREG(s0) /* fn */
#ifdef CONFIG_CHERI_KERNEL
	li a2, PT_SIZE_ON_STACK
	scbndsr ca2, csp, a2 /* pt_regs with bounds */
#else
	move a2, sp /* pt_regs */
#endif
	call ret_from_fork_kernel
	j ret_from_exception
SYM_CODE_END(ret_from_fork_kernel_asm)

SYM_CODE_START(ret_from_fork_user_asm)
	call schedule_tail
#ifdef CONFIG_CHERI_KERNEL
	li a0, PT_SIZE_ON_STACK
	scbndsr ca0, csp, a0 /* pt_regs with bounds */
#else
	move a0, sp /* pt_regs */
#endif
	call ret_from_fork_user
	j ret_from_exception
SYM_CODE_END(ret_from_fork_user_asm)

#ifdef CONFIG_IRQ_STACKS
/*
 * void call_on_irq_stack(struct pt_regs *regs,
 * 		          void (*func)(struct pt_regs *));
 *
 * Calls func(regs) using the per-CPU IRQ stack.
 */
SYM_FUNC_START(call_on_irq_stack)
	/* Create a frame record to save ra and s0 (fp) */
	CINSN(addi)	CREG(sp), CREG(sp), -STACKFRAME_SIZE_ON_STACK
	CREG_S	CREG(ra), STACKFRAME_RA(CREG(sp))
	CREG_S	CREG(s0), STACKFRAME_FP(CREG(sp))
	CINSN(addi)	CREG(s0), CREG(sp), STACKFRAME_SIZE_ON_STACK

	/* Switch to the per-CPU shadow call stack */
	scs_save_current
	scs_load_irq_stack t0

	/* Switch to the per-CPU IRQ stack and call the handler */
	load_per_cpu CREG(t0), irq_stack_ptr, t1
	li	t1, IRQ_STACK_SIZE
	add	CREG(sp), CREG(t0), t1
	jalr	CREG(a1)

	/* Switch back to the thread shadow call stack */
	scs_load_current

	/* Switch back to the thread stack and restore ra and s0 */
	CINSN(addi)	CREG(sp), CREG(s0), -STACKFRAME_SIZE_ON_STACK
	CREG_L	CREG(ra), STACKFRAME_RA(CREG(sp))
	CREG_L	CREG(s0), STACKFRAME_FP(CREG(sp))
	CINSN(addi)	CREG(sp), CREG(sp), STACKFRAME_SIZE_ON_STACK

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

	/* save the user space access flag */
	csrr  s0, CSR_STATUS
	REG_S s0, TASK_THREAD_SUM_RA(CREG(a3))

	/* Save the kernel shadow call stack pointer */
	scs_save_current
	/* Restore context from next->thread */
	REG_L s0,  TASK_THREAD_SUM_RA(CREG(a4))
	li    s1,  SR_SUM
	and   s0,  s0, s1
	csrs  CSR_STATUS, s0
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
	/* instruction page fault */
	ALT_PAGE_FAULT(RISCV_PTR do_page_fault)
	RISCV_PTR do_page_fault   /* load page fault */
	RISCV_PTR do_trap_unknown
	RISCV_PTR do_page_fault   /* store page fault */
	RISCV_PTR do_trap_unknown /* cause=16 */
	RISCV_PTR do_trap_unknown /* cause=17 */
	RISCV_PTR do_trap_software_check /* cause=18 is sw check exception */
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
SYM_DATA_START(kernel_ro_cap)
	RISCV_PTR 0
SYM_DATA_END(kernel_ro_cap)
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
