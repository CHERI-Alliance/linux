// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited
#include <linux/mman.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <linux/sched.h>
#include <errno.h>
#include <cheriintrin.h>
#include "freestanding.h"

#define STACK_SIZE	1024*1024

#define in_restricted()	\
	(!(cheri_perms_get(cheri_pcc_get()) & ARM_CAP_PERMISSION_EXECUTIVE))


#define MAGIC_NR	0x3562 /* whatever really ..... */

/* Cloned thread result */
#define CTR_SUCCESS  	 1
#define CTR_FAILED	-1

#define BIT(nr) ((1U) << (nr))
/* Test flags */
#define CLONE_TH_RESTRICTED	BIT(1)
#define CLONE_TH_TLS		BIT(2)
#define CLONE_TH_RUSAGE		BIT(3)

struct test_fixture {
	int status;
	int flags;
	void *sp;
	int result;
};

#define PROBE_INTERVAL (1 << 12)

static void probe_addr_range(uintcap_t start_addr, size_t size, int interval)
{
	size_t i;

	for (i = interval; i < size; i+= interval)
	{
		asm("str xzr,[%[addr]]"	: : [addr] "C" (start_addr):);
		start_addr += interval;
	}
}

static int clone_base_fn(void *data)
{
	struct test_fixture *__data = (struct test_fixture *)data;
	void *addr = __builtin_frame_address(0);
	size_t size = STACK_SIZE;

	/*
	 * Probing stack with the interval of 4096
	 * As this point has been reached, it seems that
	 * the (R)CSP register has been properly set.
	 */
	addr = __builtin_align_down(addr, PROBE_INTERVAL);
	size -=  __data->sp - addr;

	probe_addr_range((uintcap_t)addr - size, size, PROBE_INTERVAL);

	if (__data->flags & CLONE_TH_TLS) {
		uintcap_t tls;

		asm("mrs %0, ctpidr_el0" : "=C" (tls));

		if (!tls) {
			__data->result = CTR_FAILED;
			goto done;
		}

		probe_addr_range(tls, STACK_SIZE >> 10, 64);
	}

	/* If things didn't explode by now .... */
	__data->result =
		!!(__data->flags & CLONE_TH_RESTRICTED) != in_restricted() ?
		 CTR_FAILED : CTR_SUCCESS;
done:
	__data->status = MAGIC_NR;
	return 0;
}

static inline __attribute__((always_inline))
void clone_single(struct test_fixture *data)
{
	int ppid = 0, cpid = 0;
	int result = -EINVAL;

	void *new_stack = mmap_verified(NULL, STACK_SIZE, PROT_READ | PROT_WRITE,
		  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0, STACK_REQ_PERMS);
	void *tls = data->flags & CLONE_TH_TLS ?
		  mmap_verified(NULL, STACK_SIZE >> 10, PROT_READ | PROT_WRITE,
			 MAP_ANONYMOUS | MAP_PRIVATE, -1, 0,
			 CAP_LOAD_PERMS | CAP_STORE_PERMS) :
		  NULL;

	int clone_flags = CLONE_VM | CLONE_PARENT_SETTID | CLONE_CHILD_SETTID;

	ASSERT_NE(new_stack, NULL);
	/* For stack probing .... */
	data->sp = new_stack + STACK_SIZE;

	ASSERT_TRUE(!(data->flags & CLONE_TH_TLS) || tls);

	if (data->flags & CLONE_TH_TLS) clone_flags |= CLONE_SETTLS;

	EXPECT_TRUE(!(data->flags & CLONE_TH_RESTRICTED) || in_restricted());

	result = __clone(clone_base_fn, (uintcap_t)new_stack + STACK_SIZE,
			 clone_flags, data, &ppid, tls, &cpid);

	EXPECT_GT(result, 0) {
		TH_LOG("Clone syscall failed");
		goto leave;
	}

	/* Wait substitute ... */
	while (data->status != MAGIC_NR) {
		asm("");
	}
	/*
	 * CLONE_CHILD_SETTID sets child's thread ID to provided child's
	 * memory but as VM is being shared, it's all good at this point.
	 * Also, the thread id is being set when the child is scheduled.
	 * Either way if this point has been reached - all went 'supposedly'
	 * well.
	 */
	ASSERT_EQ(data->result, CTR_SUCCESS);
leave:
	munmap(new_stack, STACK_SIZE);
	if (tls)
		munmap(tls, STACK_SIZE >> 10);
}

static int sleep_cycles(void *n_cycle)
{
	int __n_cycle = *((int *) n_cycle);

	for (int i = 0; i < __n_cycle; i += 1)
		asm("mov xzr, #1");
	return 0;
}

/* The wait_single test makes use of the fact that both wait4 and
 * waitid invoke do_wait(&wait_opts), both returning resource
 * usage for the child in *ru with waitid additionally recording
 * information about the child's change in state.
 * Therefore if waitid works, we can be confident of wait4's
 * correctness.
 */
static inline __attribute__((always_inline))
void wait_single(struct test_fixture *data)
{
	void *new_stack = mmap_verified(NULL, STACK_SIZE, PROT_READ | PROT_WRITE,
				 MAP_ANONYMOUS | MAP_PRIVATE, -1, 0,
				 STACK_REQ_PERMS);

	pid_t cpid = -EINVAL;
	pid_t result = -EINVAL;
	int n_cycle = 1000;
	struct rusage *wait_ru = data->flags & CLONE_TH_RUSAGE ?
			&(struct rusage){0} : NULL;
	siginfo_t *wait_si = &(siginfo_t){0};

	int clone_flags = SIGCHLD;

	ASSERT_NE(new_stack, NULL);

	cpid = __clone(sleep_cycles, (uintcap_t)new_stack + STACK_SIZE, clone_flags,
			&n_cycle, NULL, NULL, NULL);

	ASSERT_GT(cpid, 0) {
		__TH_LOG_ERROR("wait_test: Failed to clone");
	}

	result = syscall(__NR_waitid, P_PID, cpid, wait_si, WEXITED, wait_ru);

	ASSERT_EQ(result, 0) {
		__TH_LOG_ERROR("wait_test: Failed on wait");
	}

	/*
	 * Validate (to a limited extent) both struct rusage and siginfo_t.
	 * Might explode if capability tag gets cleared on the way...
	 */
	if (data->flags & CLONE_TH_RUSAGE) {
		int nonzero_count = 0;

		for (unsigned int i = 0; i < sizeof(*wait_ru); ++i)
			if (!!((unsigned char *)wait_ru)[i])
				++nonzero_count;
		EXPECT_GT(nonzero_count, 0) {
			TH_LOG("Empty struct rusage on return from waitid");
			goto end;
		}
	}

	/*
	 * si_signo is supposed to be always set to SIGCHLD (when successfully
	 * identifying the child process).
	 */
	EXPECT_EQ(wait_si->si_signo, SIGCHLD) {
		TH_LOG("Unexpected si_signo value received: %d, expected SIGCHLD(%d)",
		       wait_si->si_signo, SIGCHLD);
		goto end;
	}

	EXPECT_EQ(wait_si->si_pid, cpid) {
		TH_LOG("Unexpected child's process ID. Got %d, expected %d",
			wait_si->si_pid, cpid);
		goto end;
	}

end:
	munmap(new_stack, STACK_SIZE);
}

#define RUN_WITH_FIXTURE(name, run_flags, fn)		\
	struct test_fixture name = {			\
		.flags = run_flags,			\
	};		 				\
	fn(&name)

TEST(test_clone)
{
	RUN_WITH_FIXTURE(data, 0,  clone_single);
}

TEST(test_clone_tls)
{
	RUN_WITH_FIXTURE(data, CLONE_TH_TLS, clone_single);
}

TEST(test_clone_restricted)
{
	RUN_WITH_FIXTURE(data, CLONE_TH_RESTRICTED, clone_single);
}

TEST(test_clone_tls_restricted)
{
	RUN_WITH_FIXTURE(data, CLONE_TH_TLS | CLONE_TH_RESTRICTED, clone_single);
}

TEST(test_wait_raw)
{
	RUN_WITH_FIXTURE(data, 0, wait_single);
}

TEST(test_wait_rusage)
{
	RUN_WITH_FIXTURE(data, CLONE_TH_RUSAGE, wait_single);
}

void run_restricted(uintcap_t entry_point)
{
	void *new_stack = allocate_mem_raw(STACK_SIZE);

	if (!new_stack) {
		/* Logging outside TEST case should be safe */
		__TH_LOG_ERROR("Failed to allocate memory");
		return;
	}
	if (!cheri_perms_and(new_stack, STACK_REQ_PERMS)) {
		__TH_LOG_ERROR("Insufficient permissions");
		goto leave;
	}

	EXPECT_FALSE(in_restricted());

	/*
	 * Limit the permissions for Restricted mode
	 * Those limitations will get applied for a capability,
	 * the branch (restricted) instruction is targeting
	 */
	switch_to_restricted(entry_point, new_stack + STACK_SIZE);
leave:
	munmap(new_stack, STACK_SIZE);
}

int main(void)
{
	test_clone();
	run_restricted((uintcap_t)test_clone_restricted);
	test_clone_tls();
	run_restricted((uintcap_t)test_clone_tls_restricted);
	test_wait_raw();
	test_wait_rusage();
	return 0;
}
