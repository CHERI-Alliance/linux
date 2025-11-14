// SPDX-License-Identifier: GPL-2.0-only
/*
 * System calls implementation for 64-bit COMPAT tasks
 *
 * Copyright (C) 2021 Arm Ltd.
 */

#define __SYSCALL_COMPAT

#include <linux/compat.h>
#include <linux/compiler.h>
#include <linux/syscalls.h>

#include <asm/syscall.h>

#define __arm64_compatentry_sys_personality			__arm64_compatentry_sys_arm64_personality

/*
 * The following compat handlers are not defined in generic code, but the
 * native handlers work for 64-bit compat.
 */
#define __arm64_compatentry_compat_sys_fallocate		__arm64_compatentry_sys_fallocate
#define __arm64_compatentry_compat_sys_pread64			__arm64_compatentry_sys_pread64
#define __arm64_compatentry_compat_sys_pwrite64			__arm64_compatentry_sys_pwrite64
#define __arm64_compatentry_compat_sys_sync_file_range		__arm64_compatentry_sys_sync_file_range
#define __arm64_compatentry_compat_sys_readahead		__arm64_compatentry_sys_readahead

/*
 * The compat_sys_{preadv,pwritev}{,2} handlers are not appropriate for 64-bit
 * tasks, as they expect the offset to be split in two 32-bit integers. The
 * native handlers work fine in 64-bit compat too so just use those instead.
 */
#define __arm64_compatentry_compat_sys_preadv			__arm64_compatentry_sys_preadv
#define __arm64_compatentry_compat_sys_preadv2			__arm64_compatentry_sys_preadv2
#define __arm64_compatentry_compat_sys_pwritev			__arm64_compatentry_sys_pwritev
#define __arm64_compatentry_compat_sys_pwritev2			__arm64_compatentry_sys_pwritev2

/*
 * 64-bit tasks pass 64-bit time values (not 32-bit).
 */
#define __arm64_compatentry_compat_sys_getitimer		__arm64_compatentry_sys_getitimer
#define __arm64_compatentry_compat_sys_setitimer		__arm64_compatentry_sys_setitimer
#define __arm64_compatentry_compat_sys_getrusage		__arm64_compatentry_sys_getrusage

asmlinkage long sys_ni_syscall(void);

asmlinkage long __arm64_compatentry_sys_ni_syscall(const struct pt_regs *__unused);
asmlinkage long __arm64_compatentry_sys_ni_syscall(const struct pt_regs *__unused)
{
	return sys_ni_syscall();
}

#define __SYSCALL_RETPTR __SYSCALL
#define __SYSCALL_WITH_COMPAT_RETPTR __SYSCALL_WITH_COMPAT
#define __SYSCALL_WITH_COMPAT(nr, native, compat)  __SYSCALL(nr, compat)

#undef __SYSCALL
#define __SYSCALL(nr, sym)	asmlinkage long __arm64_compatentry_##sym(const struct pt_regs *);
#include <asm/syscall_table_64.h>

#undef __SYSCALL
#define __SYSCALL(nr, sym)	[nr] = { .syscall_fn = __arm64_compatentry_##sym, },

const syscall_entry_t compat_sys_call_table[__NR_syscalls] = {
	[0 ... __NR_syscalls - 1] = {
		.syscall_fn = __arm64_compatentry_sys_ni_syscall,
		.__retptr   = 0,
	},
#include <asm/syscall_table_64.h>
};
