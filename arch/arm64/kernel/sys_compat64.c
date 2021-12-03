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
#define __arm64_compatentry_compat_sys_truncate64		__arm64_compatentry_sys_truncate
#define __arm64_compatentry_compat_sys_ftruncate64		__arm64_compatentry_sys_ftruncate
#define __arm64_compatentry_compat_sys_fallocate		__arm64_compatentry_sys_fallocate
#define __arm64_compatentry_compat_sys_pread64			__arm64_compatentry_sys_pread64
#define __arm64_compatentry_compat_sys_pwrite64			__arm64_compatentry_sys_pwrite64
#define __arm64_compatentry_compat_sys_sync_file_range		__arm64_compatentry_sys_sync_file_range
#define __arm64_compatentry_compat_sys_readahead		__arm64_compatentry_sys_readahead
#define __arm64_compatentry_compat_sys_fadvise64_64		__arm64_compatentry_sys_fadvise64_64

/*
 * 64-bit tasks use mmap (not mmap2).
 */
#define __arm64_compatentry_sys_mmap2				__arm64_compatentry_sys_mmap

/*
 * 64-bit tasks use lseek (not llseek).
 */
#define __arm64_compatentry_sys_llseek				__arm64_compatentry_compat_sys_lseek

/*
 * Use the same 'struct stat' as native AArch64.
 */
#define __arm64_compatentry_sys_fstatat64			__arm64_compatentry_sys_newfstatat
#define __arm64_compatentry_sys_fstat64				__arm64_compatentry_sys_newfstat

/*
 * 64-bit tasks use statfs (not statfs64).
 */
#define __arm64_compatentry_compat_sys_statfs64			__arm64_compatentry_compat_sys_statfs
#define __arm64_compatentry_compat_sys_fstatfs64		__arm64_compatentry_compat_sys_fstatfs

asmlinkage long sys_ni_syscall(void);

asmlinkage long __arm64_compatentry_sys_ni_syscall(const struct pt_regs *__unused);
asmlinkage long __arm64_compatentry_sys_ni_syscall(const struct pt_regs *__unused)
{
	return sys_ni_syscall();
}

#undef __SYSCALL
#define __SYSCALL(nr, sym)	asmlinkage long __arm64_compatentry_##sym(const struct pt_regs *);
#include <asm/unistd.h>

#undef __SYSCALL
#define __SYSCALL(nr, sym)	[nr] = { .syscall_fn = __arm64_compatentry_##sym, },

const syscall_entry_t compat_sys_call_table[__NR_syscalls] = {
	[0 ... __NR_syscalls - 1] = {
		.syscall_fn = __arm64_compatentry_sys_ni_syscall,
		.__retptr   = 0,
	},
#include <asm/unistd.h>
};
