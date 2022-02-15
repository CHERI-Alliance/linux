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

/*
 * 64-bit tasks pass 64-bit time values (not 32-bit).
 */
#define __arm64_compatentry_sys_io_getevents_time32		__arm64_compatentry_sys_io_getevents
#define __arm64_compatentry_compat_sys_pselect6_time32		__arm64_compatentry_compat_sys_pselect6_time64
#define __arm64_compatentry_compat_sys_ppoll_time32		__arm64_compatentry_compat_sys_ppoll_time64
#define __arm64_compatentry_sys_timerfd_settime32		__arm64_compatentry_sys_timerfd_settime
#define __arm64_compatentry_sys_timerfd_gettime32		__arm64_compatentry_sys_timerfd_gettime
#define __arm64_compatentry_sys_utimensat_time32		__arm64_compatentry_sys_utimensat
#define __arm64_compatentry_sys_futex_time32			__arm64_compatentry_sys_futex
#define __arm64_compatentry_sys_nanosleep_time32		__arm64_compatentry_sys_nanosleep
#define __arm64_compatentry_sys_timer_gettime32			__arm64_compatentry_sys_timer_gettime
#define __arm64_compatentry_sys_timer_settime32			__arm64_compatentry_sys_timer_settime
#define __arm64_compatentry_sys_clock_settime32			__arm64_compatentry_sys_clock_settime
#define __arm64_compatentry_sys_clock_gettime32			__arm64_compatentry_sys_clock_gettime
#define __arm64_compatentry_sys_clock_getres_time32		__arm64_compatentry_sys_clock_getres
#define __arm64_compatentry_sys_clock_nanosleep_time32		__arm64_compatentry_sys_clock_nanosleep
#define __arm64_compatentry_sys_sched_rr_get_interval_time32	__arm64_compatentry_sys_sched_rr_get_interval
#define __arm64_compatentry_compat_sys_rt_sigtimedwait_time32	__arm64_compatentry_compat_sys_rt_sigtimedwait_time64
#define __arm64_compatentry_compat_sys_gettimeofday		__arm64_compatentry_sys_gettimeofday
#define __arm64_compatentry_compat_sys_settimeofday		__arm64_compatentry_sys_settimeofday
#define __arm64_compatentry_sys_adjtimex_time32			__arm64_compatentry_sys_adjtimex
#define __arm64_compatentry_sys_mq_timedsend_time32		__arm64_compatentry_sys_mq_timedsend
#define __arm64_compatentry_sys_mq_timedreceive_time32		__arm64_compatentry_sys_mq_timedreceive
#define __arm64_compatentry_sys_semtimedop_time32		__arm64_compatentry_sys_semtimedop
#define __arm64_compatentry_compat_sys_recvmmsg_time32		__arm64_compatentry_compat_sys_recvmmsg_time64
#define __arm64_compatentry_compat_sys_wait4			__arm64_compatentry_sys_wait4
#define __arm64_compatentry_sys_clock_adjtime32			__arm64_compatentry_sys_clock_adjtime
#define __arm64_compatentry_compat_sys_io_pgetevents		__arm64_compatentry_compat_sys_io_pgetevents_time64
#define __arm64_compatentry_compat_sys_getitimer		__arm64_compatentry_sys_getitimer
#define __arm64_compatentry_compat_sys_setitimer		__arm64_compatentry_sys_setitimer

/*
 * Assign native handler to compat rt_sigreturn syscall till the full
 * compat64 signal support is added.
 */
#define __arm64_compatentry_compat_sys_rt_sigreturn		__arm64_compatentry_sys_rt_sigreturn

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
