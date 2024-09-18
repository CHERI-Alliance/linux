// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2009 Sunplus Core Technology Co., Ltd.
 *  Chen Liqin <liqin.chen@sunplusct.com>
 *  Lennox Wu <lennox.wu@sunplusct.com>
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2017 SiFive
 */

#include <linux/cpu.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/debug.h>
#include <linux/sched/task_stack.h>
#include <linux/tick.h>
#include <linux/ptrace.h>
#include <linux/uaccess.h>
#include <linux/binfmts.h>

#include <asm/unistd.h>
#include <asm/processor.h>
#include <asm/csr.h>
#include <asm/stacktrace.h>
#include <asm/string.h>
#include <asm/switch_to.h>
#include <asm/thread_info.h>
#include <asm/cpuidle.h>
#include <asm/vector.h>
#include <asm/cpufeature.h>
#include <asm/bakewell.h>

#include <linux/cheri.h>

#if defined(CONFIG_STACKPROTECTOR) && !defined(CONFIG_STACKPROTECTOR_PER_TASK)
#include <linux/stackprotector.h>
unsigned long __stack_chk_guard __read_mostly;
EXPORT_SYMBOL(__stack_chk_guard);
#endif

extern asmlinkage void ret_from_fork(void);

void noinstr arch_cpu_idle(void)
{
	cpu_do_idle();
}

int set_unalign_ctl(struct task_struct *tsk, unsigned int val)
{
	if (!unaligned_ctl_available())
		return -EINVAL;

	tsk->thread.align_ctl = val;
	return 0;
}

int get_unalign_ctl(struct task_struct *tsk, uintptr_t adr)
{
	if (!unaligned_ctl_available())
		return -EINVAL;

	return put_user(tsk->thread.align_ctl, (unsigned long __user *)adr);
}

void __show_regs(struct pt_regs *regs)
{
	show_regs_print_info(KERN_DEFAULT);

	if (!user_mode(regs)) {
		pr_cont("epc : %pS\n", (void *)regs->epc);
		pr_cont(" ra : %pS\n", (void *)regs->ra);
	}

	pr_cont("epc: " REG_FMT " ra : " REG_FMT " sp : " REG_FMT "\n",
		__c_ua(regs->epc), __c_ua(regs->ra), __c_ua(regs->sp));
	pr_cont(" gp : " REG_FMT " tp : " REG_FMT " t0 : " REG_FMT "\n",
		__c_ua(regs->gp), __c_ua(regs->tp), __c_ua(regs->t0));
	pr_cont(" t1 : " REG_FMT " t2 : " REG_FMT " s0 : " REG_FMT "\n",
		__c_ua(regs->t1), __c_ua(regs->t2), __c_ua(regs->s0));
	pr_cont(" s1 : " REG_FMT " a0 : " REG_FMT " a1 : " REG_FMT "\n",
		__c_ua(regs->s1), __c_ua(regs->a0), __c_ua(regs->a1));
	pr_cont(" a2 : " REG_FMT " a3 : " REG_FMT " a4 : " REG_FMT "\n",
		__c_ua(regs->a2), __c_ua(regs->a3), __c_ua(regs->a4));
	pr_cont(" a5 : " REG_FMT " a6 : " REG_FMT " a7 : " REG_FMT "\n",
		__c_ua(regs->a5), __c_ua(regs->a6), __c_ua(regs->a7));
	pr_cont(" s2 : " REG_FMT " s3 : " REG_FMT " s4 : " REG_FMT "\n",
		__c_ua(regs->s2), __c_ua(regs->s3), __c_ua(regs->s4));
	pr_cont(" s5 : " REG_FMT " s6 : " REG_FMT " s7 : " REG_FMT "\n",
		__c_ua(regs->s5), __c_ua(regs->s6), __c_ua(regs->s7));
	pr_cont(" s8 : " REG_FMT " s9 : " REG_FMT " s10: " REG_FMT "\n",
		__c_ua(regs->s8), __c_ua(regs->s9), __c_ua(regs->s10));
	pr_cont(" s11: " REG_FMT " t3 : " REG_FMT " t4 : " REG_FMT "\n",
		__c_ua(regs->s11), __c_ua(regs->t3), __c_ua(regs->t4));
	pr_cont(" t5 : " REG_FMT " t6 : " REG_FMT "\n",
		__c_ua(regs->t5), __c_ua(regs->t6));

	pr_cont("status: " REG_FMT " badaddr: " REG_FMT " cause: " REG_FMT "\n",
		regs->status, regs->badaddr, regs->cause);
}
void show_regs(struct pt_regs *regs)
{
	__show_regs(regs);
	if (!user_mode(regs))
		dump_backtrace(regs, NULL, KERN_DEFAULT);
}

#ifdef CONFIG_COMPAT
static bool compat_mode_supported __read_mostly;

bool compat_elf_check_arch(Elf32_Ehdr *hdr)
{
	return compat_mode_supported &&
	       hdr->e_machine == EM_RISCV &&
	       hdr->e_ident[EI_CLASS] == ELFCLASS32;
}

static int __init compat_mode_detect(void)
{
	unsigned long tmp = csr_read(CSR_STATUS);

	csr_write(CSR_STATUS, (tmp & ~SR_UXL) | SR_UXL_32);
	compat_mode_supported =
			(csr_read(CSR_STATUS) & SR_UXL) == SR_UXL_32;

	csr_write(CSR_STATUS, tmp);

	pr_info("riscv: ELF compat mode %s",
			compat_mode_supported ? "supported" : "unsupported");

	return 0;
}
early_initcall(compat_mode_detect);
#endif

int start_thread(struct pt_regs *regs, unsigned long pc,
		 struct linux_binprm *bprm)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	/*
	 * Make sure that the register state does not contain stale
	 * capability data.
	 */
	memset(regs, 0, sizeof(*regs));
#endif
	regs->status = SR_PIE;
	if (has_fpu()) {
		regs->status |= SR_FS_INITIAL;
		/*
		 * Restore the initial value to the FP register
		 * before starting the user program.
		 */
		fstate_restore(current, regs);
	}
#ifndef CONFIG_CHERI_PURECAP_UABI
	regs->epc = pc;
	regs->sp = bprm->p;
#else
	regs->epc = (register_t)bprm->pcuabi.pcc;
	regs->sp = (register_t)bprm->pcuabi.csp;
	__asm__ __volatile__("scmode %0, %1, %2" : "=C"(regs->epc) : "C"(regs->epc), "r" (1));
	regs->a0  = __c_fakeu(bprm->argc);
	regs->a1 = (register_t)bprm->pcuabi.argv;
	regs->a2 = (register_t)bprm->pcuabi.envp;
	regs->a3 = (register_t)bprm->pcuabi.auxv;
#endif

#ifdef CONFIG_64BIT
	regs->status &= ~SR_UXL;

	if (is_compat_task())
		regs->status |= SR_UXL_32;
	else
		regs->status |= SR_UXL_64;
#endif

	return bprm->argc;
}

void flush_thread(void)
{
#ifdef CONFIG_FPU
	/*
	 * Reset FPU state and context
	 *	frm: round to nearest, ties to even (IEEE default)
	 *	fflags: accrued exceptions cleared
	 */
	fstate_off(current, task_pt_regs(current));
	memset(&current->thread.fstate, 0, sizeof(current->thread.fstate));
#endif
#ifdef CONFIG_RISCV_ISA_V
	/* Reset vector state */
	riscv_v_vstate_ctrl_init(current);
	riscv_v_vstate_off(task_pt_regs(current));
	kfree(current->thread.vstate.datap);
	memset(&current->thread.vstate, 0, sizeof(struct __riscv_v_ext_state));
	clear_tsk_thread_flag(current, TIF_RISCV_V_DEFER_RESTORE);
#endif
}

void arch_release_task_struct(struct task_struct *tsk)
{
	/* Free the vector context of datap. */
	if (has_vector())
		riscv_v_thread_free(tsk);
}

int arch_dup_task_struct(struct task_struct *dst, struct task_struct *src)
{
	fstate_save(src, task_pt_regs(src));
	*dst = *src;
	/* clear entire V context, including datap for a new task */
	memset(&dst->thread.vstate, 0, sizeof(struct __riscv_v_ext_state));
	memset(&dst->thread.kernel_vstate, 0, sizeof(struct __riscv_v_ext_state));
	clear_tsk_thread_flag(dst, TIF_RISCV_V_DEFER_RESTORE);

	return 0;
}

int copy_thread(struct task_struct *p, const struct kernel_clone_args *args)
{
	unsigned long clone_flags = args->flags;
	uintptr_t usp = args->stack;
	uintptr_t tls = args->tls;
	struct pt_regs *childregs = task_pt_regs(p);
	struct pt_regs *regs = current_pt_regs();

	memset(&p->thread.s, 0, sizeof(p->thread.s));

	/* p->thread holds context to be restored by __switch_to() */
	if (unlikely(args->fn)) {
		/* Kernel thread */
		memset(childregs, 0, sizeof(struct pt_regs));
#ifdef CONFIG_CHERI_PURECAP_UABI
		childregs->ddc = regs->ddc;
#endif
		/* Supervisor/Machine, irqs on: */
		childregs->status = SR_PP | SR_PIE;

		p->thread.s[0] = (uintptr_t)args->fn;
		p->thread.s[1] = (uintptr_t)args->fn_arg;
	} else {
		*childregs = *(current_pt_regs());
		/* Turn off status.VS */
		riscv_v_vstate_off(childregs);
		if (usp) /* User fork */
			childregs->sp = usp;
		if (clone_flags & CLONE_SETTLS)
			childregs->tp = tls;
		childregs->a0 = 0; /* Return value of fork() */
		p->thread.s[0] = 0;
	}
	p->thread.riscv_v_flags = 0;
	if (has_vector())
		riscv_v_thread_alloc(p);
	p->thread.ra = (uintptr_t)cheri_make_kernel_code_cap(__c_pa(&ret_from_fork));
	p->thread.sp = (uintptr_t)childregs; /* kernel sp */
	return 0;
}

void __init arch_task_cache_init(void)
{
	bakewell_init();
	riscv_v_setup_ctx_cache();
}
