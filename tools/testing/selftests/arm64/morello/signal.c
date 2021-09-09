// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021  Arm Limited
 */

#include <stddef.h>
#include <stdbool.h>

#include <linux/signal.h>
#include <linux/time.h>
#include <asm-generic/siginfo.h>
#include <asm/sigcontext.h>
#include <asm/ucontext.h>
#include <cheriintrin.h>
#include "freestanding.h"
#include "signal_common.h"

#define DELAY		1 /* 1 micro sec */

static volatile unsigned int signal_status;
static int sched_yield(void)
{
	return syscall(__NR_sched_yield, 0);
}

static void handler(int n, siginfo_t *si, void *data)
{
	struct ucontext *uc = (struct ucontext *)data;

	TH_LOG("Signal (%d) occurred\n", n);

	ASSERT_TRUE(n == SIGILL || n == SIGALRM) {
		TH_LOG("Unexpected signal number (%d)", n);
	}
	ASSERT_EQ(si->si_signo, n) TH_LOG("Unexpected signal mismatch");
	ASSERT_EQ(si->si_errno, 0) {
		TH_LOG("Unexpected signal error (%d)", si->si_errno);
	}
	if (n == SIGILL) {
		ASSERT_EQ(cheri_address_get(si->si_addr), uc->uc_mcontext.pc) {
			TH_LOG("Unexpected fault address mismatch");
		}
		ASSERT_EQ(si->si_code, ILL_ILLOPC) {
			TH_LOG("Unexpected signal code (%d)", si->si_code);
		}
		uc->uc_mcontext.pc += 4;
	}
	signal_status = true;
}

static void raise_alarm(void)
{
	struct itimerval it_val = { .it_value.tv_usec = DELAY };

	ASSERT_FALSE(setitimer(ITIMER_REAL, &it_val, NULL)) {
		TH_LOG("setitimer failed");
	}
}

static void wait(int delay)
{
	for (int i = 0; (i < delay) && !signal_status; i++)
		sched_yield();
}

TEST(test_signal)
{
	struct sigaction sa;
	unsigned long temp;
	static char stack[SIGSTKSZ];

	stack_t ss = {
		.ss_size = SIGSTKSZ,
		.ss_sp = stack,
	};
	sigaltstack(&ss, 0);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = (sighandler_t)handler;
	sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
	sigaction(SIGALRM, &sa, NULL);
	sigaction(SIGILL, &sa, NULL);
	sigaddset(&sa.sa_mask, SIGALRM);
	sigaddset(&sa.sa_mask, SIGILL);
	sigprocmask(SIG_UNBLOCK, &sa.sa_mask, NULL);

	TH_LOG("Raise alarm test\n");
	signal_status = false;
	raise_alarm();
	wait(DELAY * 1000);
	ASSERT_TRUE(signal_status);

	TH_LOG("Raise illegal instruction test\n");
	signal_status = false;
	asm volatile("mrs %0, cctlr_el3" : "=r" (temp) : : "memory");
	ASSERT_TRUE(signal_status);
}

int main(void)
{
	test_signal();
	return 0;
}
