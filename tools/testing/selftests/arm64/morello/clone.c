// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited
#include "freestanding.h"
#include <linux/mman.h>
#include <linux/resource.h>
#include <linux/wait.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/signal.h>
#include <linux/types.h>
#include <cheriintrin.h>
#include "signal_common.h"

#define STACK_SIZE	1024*1024
#define TLS_SIZE	4096

#define in_restricted()	\
	(!(cheri_perms_get(cheri_pcc_get()) & ARM_CAP_PERMISSION_EXECUTIVE))


#define MAGIC_NR	0x3562 /* whatever really ..... */

#ifndef MAX_PID_NS_LEVEL
#define MAX_PID_NS_LEVEL 32
#endif

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

	result = waitid(P_PID, cpid, wait_si, WEXITED, wait_ru);

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

#define GET_ERRNO(err) (((err) + MAX_ERRNO) ^ MAX_ERRNO)

#define CUSTOM_CLONE_STACK_INV BIT(1)

static struct clone3_fixture {
	size_t args_size;
	struct clone_args args;
	int test_flags;
	int e_result;
} clone3_data[] = {
	/* BEGIN_SECTION: expected failure */
	/* size of clone_args smaller than CLONE_ARGS_SIZE_VER0 */
	{
		.args_size = offsetof(struct clone_args, tls),
		.e_result = -EINVAL
	}, /* @{0} */
	/* invalid set_tid array size */
	{
		.args.set_tid_size = MAX_PID_NS_LEVEL + 1,
		.e_result = -EINVAL
	}, /* @{1} */
	/* Invalid combination of set_tid & set_tid_size */
	{
		.args.set_tid_size = 1,
		.e_result = -EINVAL
	}, /* @{2} */
	/* Invalid exit_signal */
	{
		.args.exit_signal = _NSIG + 1,
		.e_result = -EINVAL
	}, /* @{3} */
	/* Invalid cgroup number */
	{
		.args.flags = CLONE_INTO_CGROUP,
		.args.cgroup = (__u64)INT_MAX + 1,
		.e_result = -EINVAL
	}, /* @{4} */
	/* Invalid size for clone_args with cgroup */
	{
		.args_size = offsetof(struct clone_args, cgroup),
		.args.flags = CLONE_INTO_CGROUP,
		.args.cgroup = 1,
		.e_result = -EINVAL
	}, /* @{5} */
	/* Invalid stack & stack_size combination */
	{
		.args.stack_size = STACK_SIZE,
		.test_flags = CUSTOM_CLONE_STACK_INV,
		.e_result = -EINVAL
	}, /* @{6} */
	{
		.test_flags = CUSTOM_CLONE_STACK_INV,
		.e_result = -EINVAL
	}, /* @{7} */
	/* Invalid set_tid entry */
	{
		.args.set_tid = (uintptr_t)&(pid_t){1},
		.args.set_tid_size = 1,
		.e_result = -EEXIST
	}, /* @{8} */

	/* END_SECTION: expected failure */
	{
		.args.flags = CLONE_PIDFD | CLONE_CHILD_SETTID |
			      CLONE_CHILD_CLEARTID,
		.e_result = 0
	}, /* @{9} */
	{
		.args.flags = CLONE_PARENT_SETTID | CLONE_CHILD_SETTID,
		.e_result = 0
	}, /* @{10} */
	{
		.args.flags = CLONE_SETTLS,
		.e_result = 0
	}, /* @{11} */
};

static __attribute__((noinline)) void run_child(struct clone_args *args)
{
	static __thread int tls_data;

	if (args->flags & CLONE_CHILD_SETTID) {
		pid_t current_pid = getpid();

		ASSERT_EQ(current_pid, *(pid_t *)args->child_tid);
	}

	if (args->flags & CLONE_SETTLS && args->tls) {
		ptraddr_t base_addr = cheri_address_get(args->tls);
		ptraddr_t ref_addr = cheri_address_get(&tls_data);
		size_t length = cheri_length_get(args->tls);

		ASSERT_TRUE(cheri_tag_get(&tls_data));
		ASSERT_TRUE(ref_addr >= base_addr && ref_addr < base_addr + length);
	}

	if (args->flags & CLONE_PIDFD) {
		sigset_t set;

		ASSERT_EQ(sigemptyset(&set), 0);
		ASSERT_EQ(sigaddset(&set, SIGUSR1), 0);
		ASSERT_EQ(sigprocmask(SIG_BLOCK, &set, NULL), 0);

		/* Suspend utill parent kicks things back in */
		ASSERT_EQ(syscall(__NR_kill, getpid(), SIGSTOP), 0);

		/* Wait for a signal */
		ASSERT_EQ(rt_sigtimedwait(&set, NULL, 0, sizeof(set)),
			  SIGUSR1);
	}
	syscall(__NR_exit, 0);
}

static inline __attribute__((always_inline))
void run_clone3(struct clone3_fixture *data)
{
	struct clone_args *args = &(data->args);
	int pidfd, parent_tid = 0, child_tid = 0;
	siginfo_t wait_si;
	int result;
	pid_t pid;
	void *tls = NULL;

	args->pidfd = (uintcap_t)&pidfd;
	args->parent_tid = (uintcap_t)&parent_tid;
	args->child_tid = (uintcap_t)&child_tid;

	if (!args->exit_signal)
		args->exit_signal = SIGCHLD;

	if (!args->stack_size) {
		args->stack = (uintcap_t) mmap_verified(NULL, STACK_SIZE,
							PROT_READ | PROT_WRITE,
							MAP_ANONYMOUS | MAP_PRIVATE,
							-1, 0, STACK_REQ_PERMS);
		ASSERT_NE(args->stack, 0);
		args->stack_size =
			data->test_flags & CUSTOM_CLONE_STACK_INV ? 0 : STACK_SIZE;
	}

	if (!data->args_size)
		data->args_size = sizeof(struct clone_args);

	if (data->e_result) {
		result = syscall(__NR_clone3, args, data->args_size);
		ASSERT_EQ(result, data->e_result) {
			TH_LOG("Expected: %d while %d was received",
			       GET_ERRNO(data->e_result), GET_ERRNO(result));
		}
		if (args->stack)
			munmap((void *)args->stack, STACK_SIZE);
		return;
	}

	args->flags |= CLONE_VM;

	if (args->flags & CLONE_SETTLS) {
		tls = mmap_verified(NULL, TLS_SIZE, PROT_READ | PROT_WRITE,
				    MAP_ANONYMOUS | MAP_PRIVATE, -1, 0,
				    CAP_LOAD_PERMS | CAP_STORE_PERMS);

		ASSERT_NE(tls, NULL);
		args->tls = (uintcap_t)cheri_bounds_set(tls, TLS_SIZE);
	}

	pid = syscall(__NR_clone3, args, data->args_size);

	ASSERT_GE(pid, 0);
	if (!pid)
		run_child(args);

	if (args->flags & CLONE_PIDFD) {
		/* Make sure the child here gets a chance to block the signal */
		result = waitid(P_PID, pid, &wait_si, WSTOPPED, NULL);
		ASSERT_EQ(result, 0);
		result = syscall(__NR_kill, pid, SIGCONT);
		ASSERT_EQ(result, 0);
		/* Signal handling is not the test target here: valid pidfd is */
		result = syscall(__NR_pidfd_send_signal, pidfd, SIGUSR1, NULL, 0);
		ASSERT_EQ(result, 0);
	}

	result = waitid(P_PID, pid, &wait_si, WEXITED, NULL);
	ASSERT_EQ(result, 0);

	/* child_tid set once the thread gets scheduled */
	if (args->flags & CLONE_PARENT_SETTID && args->flags & CLONE_CHILD_SETTID
	    && !(args->flags & CLONE_CHILD_CLEARTID)) {
		ASSERT_EQ(parent_tid, child_tid);
		ASSERT_NE(parent_tid, 0);
	}

	if (args->flags & CLONE_CHILD_CLEARTID) {
		ASSERT_EQ(child_tid, 0);
	}

	munmap((void *)args->stack, STACK_SIZE);
	if (args->flags & CLONE_SETTLS)
		/* unmap TLS with a capability cached prior to setting the bounds */
		munmap(tls, TLS_SIZE);
}

TEST(test_clone3)
{
	int ncount = sizeof(clone3_data)/sizeof(clone3_data[0]);

	for (int i = 0; i < ncount; ++i) {
		TH_LOG("Validating clone3 @{%d}", i);
		run_clone3(&clone3_data[i]);
	}
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
	test_clone3();
	return 0;
}
