// SPDX-License-Identifier: GPL-2.0-only
/*
 * Based on arch/arm64/kernel/signal.c
 *
 * Copyright (C) 2021 ARM Ltd.
 */

#include <linux/compat.h>

struct compat_ucontext {
	compat_ulong_t			uc_flags;
	compat_uptr_t			uc_link;
	compat_stack_t			uc_stack;
	compat_sigset_t			uc_sigmask;
	/* glibc uses a 1024-bit sigset_t */
	__u8				__unused[1024 / 8 - sizeof(compat_sigset_t)];
	struct sigcontext		uc_mcontext;
};

struct compat_rt_sigframe {
	struct compat_siginfo info;
	struct compat_ucontext uc;
};

struct compat_frame_record {
	u64 fp;
	u64 lr;
};

#define SIGNAL_COMPAT64		1
#define rt_sigframe_user_layout	compat_rt_sigframe_user_layout
#define rt_sigframe		compat_rt_sigframe
#define frame_record		compat_frame_record
#define siginfo_t		compat_siginfo_t
#define __save_altstack		__compat_save_altstack
#define restore_altstack	compat_restore_altstack
#define copy_siginfo_to_user	copy_siginfo_to_user32
#undef SYSCALL_DEFINE0
#define SYSCALL_DEFINE0		COMPAT_SYSCALL_DEFINE0

#include "signal.c"

int compat_setup_rt_frame(int usig, struct ksignal *ksig, sigset_t *set,
			  struct pt_regs *regs)
{
	return setup_rt_frame(usig, ksig, set, regs);
}
