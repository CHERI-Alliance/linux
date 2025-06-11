// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021  Arm Limited
 */

#include <stdbool.h>

#include <linux/mman.h>
#include <linux/signal.h>
#include <linux/time.h>
#include <linux/wait.h>
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
	int si_code;
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
	ASSERT_EQ(si->si_code, siginfo_params.si_code);
	if (siginfo_params.cap) {
		ASSERT_TRUE(cheri_is_equal_exact(si->si_value.sival_ptr,
						 siginfo_params.ptr));
	} else {
		ASSERT_EQ(si->si_value.sival_int, siginfo_params.val);
	}
	signal_status = true;
}

static void setup_sigusr1_handler(struct sigaction *sa, int mask_how)
{
	ASSERT_EQ(sigemptyset(&sa->sa_mask), 0);
	sa->sa_handler = (sighandler_t)sigusr1_handler;
	sa->sa_flags = SA_SIGINFO;
	ASSERT_EQ(sigaction(SIGUSR1, sa, NULL), 0);
	ASSERT_EQ(sigaddset(&sa->sa_mask, SIGUSR1), 0);
	ASSERT_EQ(sigprocmask(mask_how, &sa->sa_mask, NULL), 0);
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
	siginfo_params.si_code = SI_MESGQ;
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

static void test_timer_create_signal(void)
{
	struct sigevent ev;
	timer_t timerid;
	struct itimerspec its;
	struct sigaction sa;

	/* register a masked signal handler */
	setup_sigusr1_handler(&sa, SIG_SETMASK);

	/* Create the timer */
	signal_status = false;
	siginfo_params.ptr = &ev;
	ASSERT_TRUE(cheri_tag_get(siginfo_params.ptr)) {
		__TH_LOG_ERROR("Check if application in purecap");
	}
	siginfo_params.cap = true;
	siginfo_params.si_code = SI_TIMER;
	ev.sigev_notify = SIGEV_SIGNAL;
	ev.sigev_signo = SIGUSR1;
	ev.sigev_value.sival_ptr = siginfo_params.ptr;
	ASSERT_EQ(timer_create(CLOCK_REALTIME, &ev, &timerid), 0);

	/* Start the timer */
	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = DELAY * 1000;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;
	ASSERT_EQ(timer_settime(timerid, 0, &its, NULL), 0);
	ASSERT_EQ(sigprocmask(SIG_UNBLOCK, &sa.sa_mask, NULL), 0);
	wait(DELAY * 2000);
	/* Delete the timer */
	ASSERT_EQ(timer_delete(timerid), 0);
}

static void setup_siginfo_same_process(siginfo_t *siginfo)
{
	signal_status = false;
	siginfo_params.ptr = &siginfo_params;
	ASSERT_EQ(1, cheri_tag_get(siginfo_params.ptr)) {
		__TH_LOG_ERROR("Check if application compiled in purecap");
	}
	siginfo_params.cap = true;
	siginfo_params.si_code = SI_QUEUE;
	siginfo->si_signo = SIGUSR1;
	siginfo->si_code = SI_QUEUE;
	siginfo->si_pid = getpid();
	siginfo->si_uid = getuid();
	siginfo->si_ptr = siginfo_params.ptr;
}

static int sigqueueinfo_child(__attribute__((__unused__)) void *data)
{
	struct sigaction sa;

	setup_sigusr1_handler(&sa, SIG_UNBLOCK);
	/* wait for some time till the sigusr1 handler is called */
	wait(DELAY * 1000);
	ASSERT_TRUE(signal_status);
	return 0;
}

static pid_t setup_siginfo_diff_process(siginfo_t *siginfo)
{
	pid_t cpid;

	setup_siginfo_same_process(siginfo);
	siginfo_params.cap = false;
	siginfo_params.ptr = cheri_tag_clear(siginfo_params.ptr);
	siginfo->si_ptr = siginfo_params.ptr;

	cpid = __clone(sigqueueinfo_child, 0, SIGCHLD, NULL, NULL, NULL, NULL);
	ASSERT_GT(cpid, 0) {
		__TH_LOG_ERROR("Failed to clone");
	}
	return cpid;
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

	setup_sigusr1_handler(&sa, SIG_UNBLOCK);
	TH_LOG("test_mq_notify: Send sigevent with pointer data");
	test_mq_notify_signal(true);
	ASSERT_TRUE(signal_status);

	TH_LOG("test_mq_notify: Send sigevent with integer data");
	test_mq_notify_signal(false);
	ASSERT_TRUE(signal_status);
}

TEST(test_timer_create)
{
	TH_LOG("test_timer_create: Set timer with pointer data");
	test_timer_create_signal();
	ASSERT_TRUE(signal_status);
}

TEST(test_rt_sigqueueinfo)
{
	siginfo_t si, wait_si;
	pid_t cpid;
	struct sigaction sa;
	int ret;

	setup_sigusr1_handler(&sa, SIG_UNBLOCK);

	TH_LOG("test_rt_sigqueueinfo: Signal to the same process");
	setup_siginfo_same_process(&si);
	ret = rt_sigqueueinfo(si.si_pid, SIGUSR1, &si);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("rt_sigqueueinfo syscall failed");
	}
	wait(DELAY * 1000);
	ASSERT_TRUE(signal_status);

	TH_LOG("test_rt_sigqueueinfo: Signal to a different process");
	cpid = setup_siginfo_diff_process(&si);
	ret = rt_sigqueueinfo(cpid, SIGUSR1, &si);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("rt_sigqueueinfo syscall failed");
	}
	ret = waitid(P_PID, cpid, &wait_si, WEXITED, NULL);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("test_rt_sigqueueinfo: Failed on wait");
	}
}

TEST(test_rt_tgsigqueueinfo)
{
	siginfo_t si, wait_si;
	pid_t cpid;
	struct sigaction sa;
	int ret;

	setup_sigusr1_handler(&sa, SIG_UNBLOCK);

	TH_LOG("test_rt_tgsigqueueinfo: Signal to the same process");
	setup_siginfo_same_process(&si);
	ret = rt_tgsigqueueinfo(si.si_pid, si.si_pid, SIGUSR1, &si);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("rt_tgsigqueueinfo syscall failed");
	}
	wait(DELAY * 1000);
	ASSERT_TRUE(signal_status);

	TH_LOG("test_rt_tgsigqueueinfo: Signal to a different process");
	cpid = setup_siginfo_diff_process(&si);
	ret = rt_tgsigqueueinfo(cpid, cpid, SIGUSR1, &si);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("rt_tgsigqueueinfo syscall failed");
	}
	ret = waitid(P_PID, cpid, &wait_si, WEXITED, NULL);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("test_rt_tgsigqueueinfo: Failed on wait");
	}
}

TEST(test_pidfd_send_signal)
{
	siginfo_t si, wait_si;
	pid_t cpid;
	int pidfd, ret;
	struct sigaction sa;

	setup_sigusr1_handler(&sa, SIG_UNBLOCK);

	TH_LOG("test_pidfd_send_signal: Signal to the same process");
	setup_siginfo_same_process(&si);
	pidfd = pidfd_open(si.si_pid, 0);
	ASSERT_GE(pidfd, 0) {
		__TH_LOG_ERROR("Failed to open process file descriptor");
	}
	ret = pidfd_send_signal(pidfd, SIGUSR1, &si, 0);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("pidfd_send_signal syscall failed");
	}
	wait(DELAY * 1000);
	ASSERT_TRUE(signal_status);
	close(pidfd);

	TH_LOG("test_pidfd_send_signal: Signal to a different process");
	cpid = setup_siginfo_diff_process(&si);

	pidfd = pidfd_open(cpid, 0);
	ASSERT_GE(pidfd, 0) {
		__TH_LOG_ERROR("Failed to open process file descriptor");
	}
	ret = pidfd_send_signal(pidfd, SIGUSR1, &si, 0);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("pidfd_send_signal syscall failed");
	}
	ret = waitid(P_PID, cpid, &wait_si, WEXITED, NULL);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("test_pidfd_send_signal: Failed on wait");
	}
	close(pidfd);
}

TEST(test_rt_sigtimedwait)
{
	siginfo_t si, wait_si = (siginfo_t){0};
	struct sigaction sa;
	int ret;

	setup_sigusr1_handler(&sa, SIG_SETMASK);

	TH_LOG("test_rt_sigtimedwait: Signal to the same process");
	setup_siginfo_same_process(&si);
	ret = rt_sigqueueinfo(si.si_pid, SIGUSR1, &si);
	ASSERT_EQ(ret, 0) {
		__TH_LOG_ERROR("rt_sigqueueinfo syscall failed");
	}
	ret = rt_sigtimedwait(&sa.sa_mask, &wait_si, NULL, sizeof(sa.sa_mask));
	ASSERT_EQ(ret, SIGUSR1);
	ASSERT_TRUE(cheri_is_equal_exact(wait_si.si_value.sival_ptr,
					 siginfo_params.ptr));
}

int main(void)
{
	test_signal_basic();
	test_mq_notify();
	test_timer_create();
	test_rt_sigqueueinfo();
	test_rt_tgsigqueueinfo();
	test_pidfd_send_signal();
	test_rt_sigtimedwait();
	return 0;
}
