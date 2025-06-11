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
mqd_t mq_open(const char *name, int oflag);
int mq_unlink(const char *name);
int mq_notify(mqd_t mqdes, const struct sigevent *sevp);
int mq_timedsend(mqd_t mqdes, const char *msg, size_t len, unsigned int prio,
		 const struct timespec *timeout);
int timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid);
int timer_delete(timer_t timerid);
int timer_settime(timer_t timerid, int flags, const struct itimerspec *new_value,
		  struct itimerspec *old_value);
int rt_sigqueueinfo(pid_t tgid, int sig, siginfo_t *uinfo);
int rt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, siginfo_t *uinfo);
int pidfd_open(pid_t pid, int flags);
int pidfd_send_signal(int pidfd, int sig, siginfo_t *uinfo, unsigned int flags);

#endif /* ! SIGNAL_COMMON_H */
