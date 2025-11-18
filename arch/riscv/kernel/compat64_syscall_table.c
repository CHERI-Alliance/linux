// SPDX-License-Identifier: GPL-2.0-only

#define __SYSCALL_COMPAT

#include <linux/compat.h>
#include <linux/syscalls.h>
#include <asm-generic/mman-common.h>
#include <asm-generic/syscalls.h>
#include <asm/syscall.h>

#define __riscv_compatentry_compat_sys_fallocate	__riscv_compatentry_sys_fallocate

/*
 * The following compat handlers are not defined in generic code, but the
 * native handlers work for 64-bit compat.
 */
#define __riscv_compatentry_compat_sys_fallocate	__riscv_compatentry_sys_fallocate
#define __riscv_compatentry_compat_sys_pread64		__riscv_compatentry_sys_pread64
#define __riscv_compatentry_compat_sys_pwrite64		__riscv_compatentry_sys_pwrite64
#define __riscv_compatentry_compat_sys_sync_file_range	__riscv_compatentry_sys_sync_file_range
#define __riscv_compatentry_compat_sys_readahead	__riscv_compatentry_sys_readahead

/*
 * The compat_sys_{preadv,pwritev}{,2} handlers are not appropriate for 64-bit
 * tasks, as they expect the offset to be split in two 32-bit integers. The
 * native handlers work fine in 64-bit compat too so just use those instead.
 */
#define __riscv_compatentry_compat_sys_preadv		__riscv_compatentry_sys_preadv
#define __riscv_compatentry_compat_sys_preadv2		__riscv_compatentry_sys_preadv2
#define __riscv_compatentry_compat_sys_pwritev		__riscv_compatentry_sys_pwritev
#define __riscv_compatentry_compat_sys_pwritev2		__riscv_compatentry_sys_pwritev2

/*
 * 64-bit tasks pass 64-bit time values (not 32-bit).
 */
#define __riscv_compatentry_compat_sys_getitimer	__riscv_compatentry_sys_getitimer
#define __riscv_compatentry_compat_sys_setitimer	__riscv_compatentry_sys_setitimer
#define __riscv_compatentry_compat_sys_getrusage	__riscv_compatentry_sys_getrusage

asmlinkage long sys_ni_syscall(void);

asmlinkage long __riscv_compatentry_sys_ni_syscall(const struct pt_regs *__unused);
asmlinkage long __riscv_compatentry_sys_ni_syscall(const struct pt_regs *__unused)
{
	return sys_ni_syscall();
}

#define __SYSCALL_WITH_COMPAT(nr, native, compat) __SYSCALL(nr, compat)

#undef __SYSCALL
#define __SYSCALL(nr, call)	asmlinkage long __riscv_compatentry_##call(const struct pt_regs *);
#include <asm/syscall_table_64.h>

#undef __SYSCALL
#define __SYSCALL(nr, call)      [nr] = __riscv_compatentry_##call,

asmlinkage long compat_sys_rt_sigreturn(void);

void * const compat_sys_call_table[__NR_syscalls] = {
	[0 ... __NR_syscalls - 1] = __riscv_sys_ni_syscall,
#include <asm/syscall_table_64.h>
};
