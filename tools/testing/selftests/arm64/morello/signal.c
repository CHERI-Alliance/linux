// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021  Arm Limited
 */

#include <stdbool.h>

#include <linux/signal.h>
#include <linux/time.h>
#include <asm/fcntl.h>
#include <asm/sigcontext.h>
#include <asm/siginfo.h>
#include <asm/ucontext.h>
#include <cheriintrin.h>
#include "freestanding.h"
#include "signal_common.h"

#define DELAY		1 /* 1 micro sec */
#define MQUEUE_FILENAME	"check_mqueue"

static volatile unsigned int signal_status;

struct siginfo_data {
	bool cap;
	union {
		int val;
		void *ptr;
	};
};
static struct siginfo_data siginfo_params;

static int sched_yield(void)
{
	return syscall(__NR_sched_yield, 0);
}

static void basic_handler(int n, siginfo_t *si, void *data)
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

static void sigusr1_handler(int n, siginfo_t *si,
			    __attribute__((__unused__)) void *data)
{
	ASSERT_EQ(n, SIGUSR1)
	ASSERT_EQ(si->si_signo, SIGUSR1);
	ASSERT_EQ(si->si_code, SI_MESGQ);
	if (siginfo_params.cap) {
		ASSERT_TRUE(cheri_is_equal_exact(si->si_value.sival_ptr,
						 siginfo_params.ptr));
	} else {
		ASSERT_EQ(si->si_value.sival_int, siginfo_params.val);
	}
	signal_status = true;
}

static void setup_sigusr1_handler(struct sigaction *sa)
{
	ASSERT_EQ(sigemptyset(&sa->sa_mask), 0);
	sa->sa_handler = (sighandler_t)sigusr1_handler;
	sa->sa_flags = SA_SIGINFO;
	ASSERT_EQ(sigaction(SIGUSR1, sa, NULL), 0);
	ASSERT_EQ(sigaddset(&sa->sa_mask, SIGUSR1), 0);
	ASSERT_EQ(sigprocmask(SIG_UNBLOCK, &sa->sa_mask, NULL), 0);
}

static void test_mq_notify_signal(bool param_cap_type)
{
	struct sigevent ev;
	char mqueue_msg[16];
	mqd_t mqdes;

	signal_status = false;
	ev.sigev_notify = SIGEV_SIGNAL;
	ev.sigev_signo = SIGUSR1;
	if (param_cap_type) {
		siginfo_params.ptr = &ev;
		ASSERT_TRUE(cheri_tag_get(siginfo_params.ptr)) {
			__TH_LOG_ERROR("Check if application in purecap");
		}
		siginfo_params.cap = true;
		ev.sigev_value.sival_ptr = siginfo_params.ptr;
	} else {
		siginfo_params.val = 0x12345678;
		siginfo_params.cap = false;
		ev.sigev_value.sival_int = siginfo_params.val;
	}
	mqdes = mq_open(MQUEUE_FILENAME, O_CREAT | O_RDWR);
	ASSERT_NE(mqdes, -1) {
		__TH_LOG_ERROR("test_mq_notify: Failed on mq_open");
	}
	ASSERT_EQ(mq_notify(mqdes, &ev), 0) {
		__TH_LOG_ERROR("test_mq_notify: Failed on mq_notify");
	}
	ASSERT_EQ(mq_timedsend(mqdes, mqueue_msg, 16, 0, NULL), 0) {
		__TH_LOG_ERROR("test_mq_notify: Failed on mq_timedsend");
	}
	wait(DELAY * 1000);
	close(mqdes);
	ASSERT_EQ(mq_unlink(MQUEUE_FILENAME), 0);
}

TEST(test_signal_basic)
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
	sa.sa_handler = (sighandler_t)basic_handler;
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

TEST(test_mq_notify)
{
	struct sigaction sa;

	setup_sigusr1_handler(&sa);
	TH_LOG("test_mq_notify: Send sigevent with pointer data");
	test_mq_notify_signal(true);
	ASSERT_TRUE(signal_status);

	TH_LOG("test_mq_notify: Send sigevent with integer data");
	test_mq_notify_signal(false);
	ASSERT_TRUE(signal_status);
}

int main(void)
{
	test_signal_basic();
	test_mq_notify();
	return 0;
}
