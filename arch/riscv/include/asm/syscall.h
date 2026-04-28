/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2008-2009 Red Hat, Inc.  All rights reserved.
 * Copyright 2010 Tilera Corporation. All Rights Reserved.
 * Copyright 2015 Regents of the University of California, Berkeley
 *
 * See asm-generic/syscall.h for descriptions of what we must do here.
 */

#ifndef _ASM_RISCV_SYSCALL_H
#define _ASM_RISCV_SYSCALL_H

#include <asm/hwprobe.h>
#include <uapi/linux/audit.h>
#include <linux/sched.h>
#include <linux/err.h>

/* The array of function pointers for syscalls. */
extern void * const sys_call_table[];
extern void * const compat_sys_call_table[];

/*
 * Only the low 32 bits of orig_a0 are meaningful, so we return int.
 * This importantly ignores the high bits on 64-bit, so comparisons
 * sign-extend the low 32 bits.
 */
static inline int syscall_get_nr(struct task_struct *task,
				 struct pt_regs *regs)
{
	return regs->a7;
}

static inline void syscall_set_nr(struct task_struct *task,
				  struct pt_regs *regs,
				  int nr)
{
	regs->a7 = nr;
}

static inline void syscall_rollback(struct task_struct *task,
				    struct pt_regs *regs)
{
        regs->a0 = regs->orig_a0;
}

static inline long syscall_get_error(struct task_struct *task,
				     struct pt_regs *regs)
{
	unsigned long error = __c_ua(regs->a0);

	return IS_ERR_VALUE(error) ? error : 0;
}

static inline intptr_t syscall_get_return_value(struct task_struct *task,
					    struct pt_regs *regs)
{
	return regs->a0;
}

static inline void syscall_set_return_value(struct task_struct *task,
					    struct pt_regs *regs,
					    int error, uintptr_t val)
{
	regs->a0 = error ? error : val;
}

static inline void syscall_get_arguments(struct task_struct *task,
					 struct pt_regs *regs,
					 uintptr_t *args)
{
	args[0] = regs->orig_a0;
	args[1] = regs->a1;
	args[2] = regs->a2;
	args[3] = regs->a3;
	args[4] = regs->a4;
	args[5] = regs->a5;
}

static inline void syscall_set_arguments(struct task_struct *task,
					 struct pt_regs *regs,
					 const uintptr_t *args)
{
	/*
	 * FIXCHERI: Handle tagged capabilties here. Currently, tags
	 * are stripped when copying the arguments into the kernel and
	 * we try to do something useful here by just changing the address.
	 */
	regs->orig_a0 = (uintptr_t)cheri_address_set(regs->orig_a0, __c_ua(args[0]));
	regs->a1 = (uintptr_t)cheri_address_set(regs->a1, __c_ua(args[1]));
	regs->a2 = (uintptr_t)cheri_address_set(regs->a2, __c_ua(args[2]));
	regs->a3 = (uintptr_t)cheri_address_set(regs->a3, __c_ua(args[3]));
	regs->a4 = (uintptr_t)cheri_address_set(regs->a4, __c_ua(args[4]));
	regs->a5 = (uintptr_t)cheri_address_set(regs->a5, __c_ua(args[5]));
}

static inline int syscall_get_arch(struct task_struct *task)
{
#ifdef CONFIG_64BIT
	return AUDIT_ARCH_RISCV64;
#else
	return AUDIT_ARCH_RISCV32;
#endif
}

typedef uintptr_t (*syscall_t)(const struct pt_regs *);
static inline void syscall_handler(struct pt_regs *regs, ulong syscall)
{
	syscall_t fn;

#ifdef CONFIG_COMPAT
	if ((regs->status & SR_UXL) == SR_UXL_32)
		fn = compat_sys_call_table[syscall];
	else
#endif
		fn = sys_call_table[syscall];

	regs->a0 = fn(regs);
}

static inline bool arch_syscall_is_vdso_sigreturn(struct pt_regs *regs)
{
	return false;
}

asmlinkage long sys_riscv_flush_icache(uintptr_t, uintptr_t, uintptr_t);

asmlinkage long sys_riscv_hwprobe(struct riscv_hwprobe *, size_t, size_t,
				  unsigned long *, unsigned int);
#endif	/* _ASM_RISCV_SYSCALL_H */
