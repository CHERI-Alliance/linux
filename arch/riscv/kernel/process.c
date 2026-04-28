// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (C) 2009 Sunplus Core Technology Co., Ltd.
 *  Chen Liqin <liqin.chen@sunplusct.com>
 *  Lennox Wu <lennox.wu@sunplusct.com>
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2017 SiFive
 */

#include <linux/bitfield.h>
#include <linux/cpu.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/debug.h>
#include <linux/sched/task_stack.h>
#include <linux/tick.h>
#include <linux/ptrace.h>
#include <linux/uaccess.h>
#include <linux/personality.h>
#include <linux/entry-common.h>
#include <linux/binfmts.h>

#include <asm/asm-prototypes.h>
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
#include <asm/exec.h>
#include <asm/riscvcheri.h>
#include <asm/usercfi.h>

#include <linux/cheri.h>

#if defined(CONFIG_STACKPROTECTOR) && !defined(CONFIG_STACKPROTECTOR_PER_TASK)
#include <linux/stackprotector.h>
unsigned long __stack_chk_guard __read_mostly;
EXPORT_SYMBOL(__stack_chk_guard);
#endif

extern asmlinkage void ret_from_fork_kernel_asm(void);
extern asmlinkage void ret_from_fork_user_asm(void);

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

	return put_user(tsk->thread.align_ctl, (unsigned int __user *)adr);
}

void __show_regs(struct pt_regs *regs)
{
	show_regs_print_info(KERN_DEFAULT);

	if (!user_mode(regs)) {
		pr_cont("epc : %pS\n", (void *)(uintptr_t)regs->epc);
		pr_cont(" ra : %pS\n", (void *)(uintptr_t)regs->ra);
	}

	pr_cont(" epc: " CREG_FMT "\n ra : " CREG_FMT "\n sp : " CREG_FMT "\n",
		(void *)regs->epc, (void *)regs->ra, (void *)regs->sp);
	pr_cont(" gp : " CREG_FMT "\n tp : " CREG_FMT "\n t0 : " CREG_FMT "\n",
		(void *)regs->gp, (void *)regs->tp, (void *)regs->t0);
	pr_cont(" t1 : " CREG_FMT "\n t2 : " CREG_FMT "\n s0 : " CREG_FMT "\n",
		(void *)regs->t1, (void *)regs->t2, (void *)regs->s0);
	pr_cont(" s1 : " CREG_FMT "\n a0 : " CREG_FMT "\n a1 : " CREG_FMT "\n",
		(void *)regs->s1, (void *)regs->a0, (void *)regs->a1);
	pr_cont(" a2 : " CREG_FMT "\n a3 : " CREG_FMT "\n a4 : " CREG_FMT "\n",
		(void *)regs->a2, (void *)regs->a3, (void *)regs->a4);
	pr_cont(" a5 : " CREG_FMT "\n a6 : " CREG_FMT "\n a7 : " CREG_FMT "\n",
		(void *)regs->a5, (void *)regs->a6, (void *)regs->a7);
	pr_cont(" s2 : " CREG_FMT "\n s3 : " CREG_FMT "\n s4 : " CREG_FMT "\n",
		(void *)regs->s2, (void *)regs->s3, (void *)regs->s4);
	pr_cont(" s5 : " CREG_FMT "\n s6 : " CREG_FMT "\n s7 : " CREG_FMT "\n",
		(void *)regs->s5, (void *)regs->s6, (void *)regs->s7);
	pr_cont(" s8 : " CREG_FMT "\n s9 : " CREG_FMT "\n s10: " CREG_FMT "\n",
		(void *)regs->s8, (void *)regs->s9, (void *)regs->s10);
	pr_cont(" s11: " CREG_FMT "\n t3 : " CREG_FMT "\n t4 : " CREG_FMT "\n",
		(void *)regs->s11, (void *)regs->t3, (void *)regs->t4);
	pr_cont(" t5 : " CREG_FMT "\n t6 : " CREG_FMT "\n ssp: " CREG_FMT "\n",
		(void *)regs->t5, (void *)regs->t6, (void *)get_active_shstk(current));

	pr_cont("status:  " REG_FMT " badaddr: " REG_FMT " cause: " REG_FMT "\n",
		regs->status, regs->badaddr, regs->cause);
}
void show_regs(struct pt_regs *regs)
{
	__show_regs(regs);
	if (!user_mode(regs))
		dump_backtrace(regs, NULL, KERN_DEFAULT);
}

unsigned long arch_align_stack(unsigned long sp)
{
	if (!(current->personality & ADDR_NO_RANDOMIZE) && randomize_va_space)
		sp -= get_random_u32_below(PAGE_SIZE);
	return sp & ~0xf;
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
#ifdef CONFIG_CHERI_KERNEL
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
#ifndef CONFIG_CHERI_KERNEL
	regs->epc = pc;
	regs->sp = bprm->p;
#else
	/* FIXCHERI: compat support missing */
	regs->epc = (uintptr_t)riscv_cheri_set_capmode(bprm->pcuabi.pcc);
	regs->sp = (user_uintptr_t)bprm->pcuabi.csp;
	regs->a0  = __c_fakeu(bprm->argc);
	regs->a1 = (user_uintptr_t)bprm->pcuabi.argv;
	regs->a2 = (user_uintptr_t)bprm->pcuabi.envp;
	regs->a3 = (user_uintptr_t)bprm->pcuabi.auxv;
#endif

	/*
	 * clear shadow stack state on exec.
	 * libc will set it later via prctl.
	 */
	set_shstk_lock(current, false);
	set_shstk_status(current, false);
	set_shstk_base(current, 0, 0);
	set_active_shstk(current, 0);
	/*
	 * disable indirect branch tracking on exec.
	 * libc will enable it later via prctl.
	 */
	set_indir_lp_lock(current, false);
	set_indir_lp_status(current, false);

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
#ifdef CONFIG_RISCV_ISA_SUPM
	if (riscv_has_extension_unlikely(RISCV_ISA_EXT_SUPM))
		envcfg_update_bits(current, ENVCFG_PMM, ENVCFG_PMM_PMLEN_0);
#endif
}

void arch_release_task_struct(struct task_struct *tsk)
{
	/* Free the vector context of datap. */
	if (has_vector() || has_xtheadvector())
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

asmlinkage void ret_from_fork_kernel(void *fn_arg, int (*fn)(void *), struct pt_regs *regs)
{
	fn(fn_arg);

	syscall_exit_to_user_mode(regs);
}

asmlinkage void ret_from_fork_user(struct pt_regs *regs)
{
	syscall_exit_to_user_mode(regs);
}

int copy_thread(struct task_struct *p, const struct kernel_clone_args *args)
{
	u64 clone_flags = args->flags;
	uintptr_t usp = args->stack;
	uintptr_t tls = args->tls;
	uintptr_t ssp = 0;
	struct pt_regs *childregs = task_pt_regs(p);

	/* Ensure all threads in this mm have the same pointer masking mode. */
	if (IS_ENABLED(CONFIG_RISCV_ISA_SUPM) && p->mm && (clone_flags & CLONE_VM))
		set_bit(MM_CONTEXT_LOCK_PMLEN, &p->mm->context.flags);

	memset(&p->thread.s, 0, sizeof(p->thread.s));

	/* p->thread holds context to be restored by __switch_to() */
	if (unlikely(args->fn)) {
		/* Kernel thread */
		memset(childregs, 0, sizeof(struct pt_regs));
		/* Supervisor/Machine, irqs on: */
		childregs->status = SR_PP | SR_PIE;

		p->thread.s[0] = (uintptr_t)args->fn;
		p->thread.s[1] = (uintptr_t)args->fn_arg;
		p->thread.ra = (uintptr_t)cheri_make_kernel_code_cap(__c_pa(&ret_from_fork_kernel_asm));
	} else {
		/* allocate new shadow stack if needed. In case of CLONE_VM we have to */
		ssp = shstk_alloc_thread_stack(p, args);
		if (IS_ERR_VALUE(ssp))
			return PTR_ERR((void *)ssp);

		*childregs = *(current_pt_regs());
		/* Turn off status.VS */
		riscv_v_vstate_off(childregs);
		if (usp) /* User fork */
			childregs->sp = usp;
		/* if needed, set new ssp */
		if (ssp)
			set_active_shstk(p, ssp);
		if (clone_flags & CLONE_SETTLS)
			childregs->tp = tls;
		childregs->a0 = 0; /* Return value of fork() */
		p->thread.ra = (uintptr_t)cheri_make_kernel_code_cap(__c_pa(&ret_from_fork_user_asm));
	}
	p->thread.riscv_v_flags = 0;
	if (has_vector() || has_xtheadvector())
		riscv_v_thread_alloc(p);
	p->thread.sp = (uintptr_t)childregs; /* kernel sp */
	return 0;
}

void __init arch_task_cache_init(void)
{
	riscv_cheri_init();
	riscv_v_setup_ctx_cache();
}

#ifdef CONFIG_RISCV_ISA_SUPM
enum {
	PMLEN_0 = 0,
	PMLEN_7 = 7,
	PMLEN_16 = 16,
};

static bool have_user_pmlen_7;
static bool have_user_pmlen_16;

/*
 * Control the relaxed ABI allowing tagged user addresses into the kernel.
 */
static unsigned int tagged_addr_disabled;

long set_tagged_addr_ctrl(struct task_struct *task, unsigned long arg)
{
	unsigned long valid_mask = PR_PMLEN_MASK | PR_TAGGED_ADDR_ENABLE;
	struct thread_info *ti = task_thread_info(task);
	struct mm_struct *mm = task->mm;
	unsigned long pmm;
	u8 pmlen;

	if (!riscv_has_extension_unlikely(RISCV_ISA_EXT_SUPM))
		return -EINVAL;

	if (is_compat_thread(ti))
		return -EINVAL;

	if (arg & ~valid_mask)
		return -EINVAL;

	/*
	 * Prefer the smallest PMLEN that satisfies the user's request,
	 * in case choosing a larger PMLEN has a performance impact.
	 */
	pmlen = FIELD_GET(PR_PMLEN_MASK, arg);
	if (pmlen == PMLEN_0) {
		pmm = ENVCFG_PMM_PMLEN_0;
	} else if (pmlen <= PMLEN_7 && have_user_pmlen_7) {
		pmlen = PMLEN_7;
		pmm = ENVCFG_PMM_PMLEN_7;
	} else if (pmlen <= PMLEN_16 && have_user_pmlen_16) {
		pmlen = PMLEN_16;
		pmm = ENVCFG_PMM_PMLEN_16;
	} else {
		return -EINVAL;
	}

	/*
	 * Do not allow the enabling of the tagged address ABI if globally
	 * disabled via sysctl abi.tagged_addr_disabled, if pointer masking
	 * is disabled for userspace.
	 */
	if (arg & PR_TAGGED_ADDR_ENABLE && (tagged_addr_disabled || !pmlen))
		return -EINVAL;

	if (!(arg & PR_TAGGED_ADDR_ENABLE)) {
		pmlen = PMLEN_0;
		pmm = ENVCFG_PMM_PMLEN_0;
	}

	if (mmap_write_lock_killable(mm))
		return -EINTR;

	if (test_bit(MM_CONTEXT_LOCK_PMLEN, &mm->context.flags) && mm->context.pmlen != pmlen) {
		mmap_write_unlock(mm);
		return -EBUSY;
	}

	envcfg_update_bits(task, ENVCFG_PMM, pmm);
	mm->context.pmlen = pmlen;

	mmap_write_unlock(mm);

	return 0;
}

long get_tagged_addr_ctrl(struct task_struct *task)
{
	struct thread_info *ti = task_thread_info(task);
	long ret = 0;

	if (!riscv_has_extension_unlikely(RISCV_ISA_EXT_SUPM))
		return -EINVAL;

	if (is_compat_thread(ti))
		return -EINVAL;

	/*
	 * The mm context's pmlen is set only when the tagged address ABI is
	 * enabled, so the effective PMLEN must be extracted from envcfg.PMM.
	 */
	switch (task->thread.envcfg & ENVCFG_PMM) {
	case ENVCFG_PMM_PMLEN_7:
		ret = FIELD_PREP(PR_PMLEN_MASK, PMLEN_7);
		break;
	case ENVCFG_PMM_PMLEN_16:
		ret = FIELD_PREP(PR_PMLEN_MASK, PMLEN_16);
		break;
	}

	if (task->mm->context.pmlen)
		ret |= PR_TAGGED_ADDR_ENABLE;

	return ret;
}

static bool try_to_set_pmm(unsigned long value)
{
	csr_set(CSR_ENVCFG, value);
	return (csr_read_clear(CSR_ENVCFG, ENVCFG_PMM) & ENVCFG_PMM) == value;
}

/*
 * Global sysctl to disable the tagged user addresses support. This control
 * only prevents the tagged address ABI enabling via prctl() and does not
 * disable it for tasks that already opted in to the relaxed ABI.
 */

static const struct ctl_table tagged_addr_sysctl_table[] = {
	{
		.procname	= "tagged_addr_disabled",
		.mode		= 0644,
		.data		= &tagged_addr_disabled,
		.maxlen		= sizeof(int),
		.proc_handler	= proc_dointvec_minmax,
		.extra1		= SYSCTL_ZERO,
		.extra2		= SYSCTL_ONE,
	},
};

static int __init tagged_addr_init(void)
{
	if (!riscv_has_extension_unlikely(RISCV_ISA_EXT_SUPM))
		return 0;

	/*
	 * envcfg.PMM is a WARL field. Detect which values are supported.
	 * Assume the supported PMLEN values are the same on all harts.
	 */
	csr_clear(CSR_ENVCFG, ENVCFG_PMM);
	have_user_pmlen_7 = try_to_set_pmm(ENVCFG_PMM_PMLEN_7);
	have_user_pmlen_16 = try_to_set_pmm(ENVCFG_PMM_PMLEN_16);

	if (!register_sysctl("abi", tagged_addr_sysctl_table))
		return -EINVAL;

	return 0;
}
core_initcall(tagged_addr_init);
#endif	/* CONFIG_RISCV_ISA_SUPM */
