/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Based on mainline tools/testing/selftests/arm64/bti/signal.h
 *
 * Copyright (C) 2019  Arm Limited
 * Original author: Dave Martin <Dave.Martin@arm.com>
 */

#ifndef SIGNAL_COMMON_H
#define SIGNAL_COMMON_H


typedef __kernel_size_t size_t;
typedef __kernel_ssize_t ssize_t;
#include <linux/signal.h>

typedef __sighandler_t sighandler_t;

int sigemptyset(sigset_t *s);
int sigaddset(sigset_t *s, int n);
int sigaction(int n, struct sigaction *sa, const struct sigaction *old);
int sigprocmask(int how, const sigset_t *mask, sigset_t *old);
int sigaltstack(const stack_t *ss, stack_t *old_ss);
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);

#endif /* ! SIGNAL_COMMON_H */
