// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited
#include <linux/errno.h>
#include <linux/sched.h>
#include "freestanding.h"

/* No longer provided in uapi headers, only in libc headers */
struct sched_param {
	int sched_priority;
};

/*
 * /proc/sys/kernel/pid_max substitute
 * @see: PID_MAX_LIMIT
 */

#define UNUSED_PID_MAGIC (4*1024*1024)

/* Ensure expected behaviour when we try to query scheduling information
 * on non-extant thread
 */
static inline __attribute__((always_inline))
void run_fail(void)
{
	long retval;
	long errval = -ESRCH;

	retval = syscall(__NR_sched_getscheduler, UNUSED_PID_MAGIC);
	EXPECT_EQ(retval, errval) {
		TH_LOG("Got policy %ld, expected -ESRCH: %ld",
				retval, errval);
	}
}

/* Ensure we are able to set the scheduling policy & priority pair for a
 * given thread and retrieve these values
 */
static inline __attribute__((always_inline))
void run_setget(int sched_policy)
{
	int pmin = syscall(__NR_sched_get_priority_min, sched_policy);
	int ret;

	struct sched_param sp = { .sched_priority = pmin };

	/*
	 * Might require sufficient permissions - an assumption is being made
	 * currently used ones are sufficient.
	 */
	ret = syscall(__NR_sched_setscheduler, 0,
					sched_policy, &sp);
	EXPECT_EQ(ret, 0) {
		TH_LOG("Failed to set scheduler with policy: %d and priority: %d\n",
		       sched_policy, sp.sched_priority);
		return;
	}

	ret = syscall(__NR_sched_getscheduler, 0);
	EXPECT_EQ(ret, sched_policy) {
		TH_LOG("Got policy %d, expected %d", ret, sched_policy);
	}

}

TEST(test_sched_rr)
{
	run_setget(SCHED_RR);
}

TEST(test_sched_other)
{
	run_setget(SCHED_NORMAL);
}

TEST(test_sched_fifo)
{
	run_setget(SCHED_FIFO);
}

TEST(test_getsched_fail)
{
	run_fail();
}

int main(void)
{
	test_sched_rr();
	test_sched_other();
	test_sched_fifo();
	test_getsched_fail();
	return 0;
}
