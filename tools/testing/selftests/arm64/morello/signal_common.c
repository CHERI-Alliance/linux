// SPDX-License-Identifier: GPL-2.0
/*
 * Based on mainline tools/testing/selftests/arm64/bti/signal.c
 *
 * Copyright (C) 2019  Arm Limited
 * Original author: Dave Martin <Dave.Martin@arm.com>
 */

#include <linux/errno.h>
#include <linux/time.h>
#include "freestanding.h"
#include "signal_common.h"

int sigemptyset(sigset_t *s)
{
	unsigned int i;

	for (i = 0; i < _NSIG_WORDS; ++i)
		s->sig[i] = 0;

	return 0;
}

int sigaddset(sigset_t *s, int n)
{
	if (n < 1 || n > _NSIG)
		return -EINVAL;

	s->sig[(n - 1) / _NSIG_BPW] |= 1UL << (n - 1) % _NSIG_BPW;
	return 0;
}

int sigaction(int n, struct sigaction *sa, const struct sigaction *old)
{
	return syscall(__NR_rt_sigaction, n, sa, old, sizeof(sa->sa_mask));
}

int sigprocmask(int how, const sigset_t *mask, sigset_t *old)
{
	return syscall(__NR_rt_sigprocmask, how, mask, old, sizeof(*mask));
}

int sigaltstack(const stack_t *ss, stack_t *old_ss)
{
	return syscall(__NR_sigaltstack, ss, old_ss);
}

int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value)
{
	return syscall(__NR_setitimer, which, new_value, old_value);
}
