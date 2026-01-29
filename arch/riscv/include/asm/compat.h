/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_COMPAT_H
#define __ASM_COMPAT_H

#define COMPAT_UTS_MACHINE	"riscv\0\0"

/*
 * Architecture specific compatibility types
 */
#include <linux/types.h>
#include <linux/sched/task_stack.h>
#include <linux/sched.h>
#include <asm-generic/compat.h>
#include <asm/processor.h>

#ifdef CONFIG_COMPAT64
#define COMPAT_USE_64BIT_TIME 1
#endif

static inline int is_compat32_task(void)
{
	if (!IS_ENABLED(CONFIG_COMPAT32))
		return 0;

	return test_thread_flag(TIF_32BIT);
}

static inline int is_compat64_task(void)
{
	if (!IS_ENABLED(CONFIG_COMPAT64))
		return 0;

	return test_thread_flag(TIF_64BIT);
}

static inline int is_compat_task(void)
{
	return is_compat32_task() || is_compat64_task();
}

static inline int is_compat_thread(struct thread_info *thread)
{
	if (!IS_ENABLED(CONFIG_COMPAT))
		return 0;

	return test_ti_thread_flag(thread, TIF_32BIT) ||
	       test_ti_thread_flag(thread, TIF_64BIT);
}

static inline void set_compat_task(bool is_compat)
{
#if (IS_ENABLED(CONFIG_COMPAT64))
	if (is_compat)
		set_thread_flag(TIF_64BIT);
	else
		clear_thread_flag(TIF_64BIT);
#else
	if (is_compat)
		set_thread_flag(TIF_32BIT);
	else
		clear_thread_flag(TIF_32BIT);
#endif
}

#ifdef CONFIG_COMPAT64
static inline void __user *compat_ptr(compat_uptr_t uptr)
{
	/*
	 * NOTE: We cannot blindly use current->ddc here. At least in the
	 * context of io_uring, the thread that creates the compat ptr
	 * might not be the user thread that initiated the request.
	 */
	return (void __user *)cheri_address_set(cheri_user_root_allperms_cap,
						uptr);
}
#define compat_ptr compat_ptr
#endif

struct compat_user_regs_struct {
	compat_ulong_t pc;
	compat_ulong_t ra;
	compat_ulong_t sp;
	compat_ulong_t gp;
	compat_ulong_t tp;
	compat_ulong_t t0;
	compat_ulong_t t1;
	compat_ulong_t t2;
	compat_ulong_t s0;
	compat_ulong_t s1;
	compat_ulong_t a0;
	compat_ulong_t a1;
	compat_ulong_t a2;
	compat_ulong_t a3;
	compat_ulong_t a4;
	compat_ulong_t a5;
	compat_ulong_t a6;
	compat_ulong_t a7;
	compat_ulong_t s2;
	compat_ulong_t s3;
	compat_ulong_t s4;
	compat_ulong_t s5;
	compat_ulong_t s6;
	compat_ulong_t s7;
	compat_ulong_t s8;
	compat_ulong_t s9;
	compat_ulong_t s10;
	compat_ulong_t s11;
	compat_ulong_t t3;
	compat_ulong_t t4;
	compat_ulong_t t5;
	compat_ulong_t t6;
};

static inline void regs_to_cregs(struct compat_user_regs_struct *cregs,
				 struct pt_regs *regs)
{
	cregs->pc	= (compat_ulong_t __force) regs->epc;
	cregs->ra	= (compat_ulong_t __force) regs->ra;
	cregs->sp	= (compat_ulong_t __force) regs->sp;
	cregs->gp	= (compat_ulong_t __force) regs->gp;
	cregs->tp	= (compat_ulong_t __force) regs->tp;
	cregs->t0	= (compat_ulong_t __force) regs->t0;
	cregs->t1	= (compat_ulong_t __force) regs->t1;
	cregs->t2	= (compat_ulong_t __force) regs->t2;
	cregs->s0	= (compat_ulong_t __force) regs->s0;
	cregs->s1	= (compat_ulong_t __force) regs->s1;
	cregs->a0	= (compat_ulong_t __force) regs->a0;
	cregs->a1	= (compat_ulong_t __force) regs->a1;
	cregs->a2	= (compat_ulong_t __force) regs->a2;
	cregs->a3	= (compat_ulong_t __force) regs->a3;
	cregs->a4	= (compat_ulong_t __force) regs->a4;
	cregs->a5	= (compat_ulong_t __force) regs->a5;
	cregs->a6	= (compat_ulong_t __force) regs->a6;
	cregs->a7	= (compat_ulong_t __force) regs->a7;
	cregs->s2	= (compat_ulong_t __force) regs->s2;
	cregs->s3	= (compat_ulong_t __force) regs->s3;
	cregs->s4	= (compat_ulong_t __force) regs->s4;
	cregs->s5	= (compat_ulong_t __force) regs->s5;
	cregs->s6	= (compat_ulong_t __force) regs->s6;
	cregs->s7	= (compat_ulong_t __force) regs->s7;
	cregs->s8	= (compat_ulong_t __force) regs->s8;
	cregs->s9	= (compat_ulong_t __force) regs->s9;
	cregs->s10	= (compat_ulong_t __force) regs->s10;
	cregs->s11	= (compat_ulong_t __force) regs->s11;
	cregs->t3	= (compat_ulong_t __force) regs->t3;
	cregs->t4	= (compat_ulong_t __force) regs->t4;
	cregs->t5	= (compat_ulong_t __force) regs->t5;
	cregs->t6	= (compat_ulong_t __force) regs->t6;
};

static inline void cregs_to_regs(struct compat_user_regs_struct *cregs,
				 struct pt_regs *regs)
{
	regs->epc	= __c_fakeu(cregs->pc);
	regs->ra	= __c_fakeu(cregs->ra);
	regs->sp	= __c_fakeu(cregs->sp);
	regs->gp	= __c_fakeu(cregs->gp);
	regs->tp	= __c_fakeu(cregs->tp);
	regs->t0	= __c_fakeu(cregs->t0);
	regs->t1	= __c_fakeu(cregs->t1);
	regs->t2	= __c_fakeu(cregs->t2);
	regs->s0	= __c_fakeu(cregs->s0);
	regs->s1	= __c_fakeu(cregs->s1);
	regs->a0	= __c_fakeu(cregs->a0);
	regs->a1	= __c_fakeu(cregs->a1);
	regs->a2	= __c_fakeu(cregs->a2);
	regs->a3	= __c_fakeu(cregs->a3);
	regs->a4	= __c_fakeu(cregs->a4);
	regs->a5	= __c_fakeu(cregs->a5);
	regs->a6	= __c_fakeu(cregs->a6);
	regs->a7	= __c_fakeu(cregs->a7);
	regs->s2	= __c_fakeu(cregs->s2);
	regs->s3	= __c_fakeu(cregs->s3);
	regs->s4	= __c_fakeu(cregs->s4);
	regs->s5	= __c_fakeu(cregs->s5);
	regs->s6	= __c_fakeu(cregs->s6);
	regs->s7	= __c_fakeu(cregs->s7);
	regs->s8	= __c_fakeu(cregs->s8);
	regs->s9	= __c_fakeu(cregs->s9);
	regs->s10	= __c_fakeu(cregs->s10);
	regs->s11	= __c_fakeu(cregs->s11);
	regs->t3	= __c_fakeu(cregs->t3);
	regs->t4	= __c_fakeu(cregs->t4);
	regs->t5	= __c_fakeu(cregs->t5);
	regs->t6	= __c_fakeu(cregs->t6);
};

#endif /* __ASM_COMPAT_H */
