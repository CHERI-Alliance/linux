// SPDX-License-Identifier: GPL-2.0-only

#define __SYSCALL_COMPAT

#include <linux/compat.h>
#include <linux/syscalls.h>
#include <asm-generic/mman-common.h>
#include <asm-generic/syscalls.h>
#include <asm/syscall.h>

asmlinkage long sys_ni_syscall(void);

asmlinkage long __riscv_compatentry_sys_ni_syscall(const struct pt_regs *__unused);
asmlinkage long __riscv_compatentry_sys_ni_syscall(const struct pt_regs *__unused)
{
	return sys_ni_syscall();
}

#define __SYSCALL_WITH_COMPAT(nr, native, compat) __SYSCALL(nr, compat)

#undef __SYSCALL
#define __SYSCALL(nr, call)	asmlinkage long __riscv_compatentry_##call(const struct pt_regs *);
#include <asm/syscall_table_32.h>

#undef __SYSCALL
#define __SYSCALL(nr, call)      [nr] = __riscv_compatentry_##call,

asmlinkage long compat_sys_rt_sigreturn(void);

void * const compat_sys_call_table[__NR_syscalls] = {
	[0 ... __NR_syscalls - 1] = __riscv_sys_ni_syscall,
#include <asm/syscall_table_32.h>
};
