// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2026 BayLibre
/*
 * Tests for PROT_CAP and PROT_NO_CAP mmap flags on RISCV CHERI.
 *
 * PROT_CAP enables capability tag preservation for a mapping.
 * PROT_NO_CAP explicitly disables capability tags: per the Zcheripte
 * spec, a capability store to a PROT_NO_CAP page raises a CapStore
 * exception (delivered as SIGSEGV), and capability loads have their
 * tags cleared.
 *
 * The #ifdef __CHERI__ tests verify actual tag behaviour and require a
 * CHERI-capable compiler.  The other tests verify syscall-level error
 * handling and compile with any standard C compiler.
 */

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../../kselftest_harness.h"

#ifdef __CHERI__
#include <cheriintrin.h>
#endif

/* 64 KiB — large enough for any typical page size */
#define MMAP_SIZE	(1UL << 16)

#ifndef PROT_CAP
#define PROT_CAP	0x4000
#endif
#ifndef PROT_NO_CAP
#define PROT_NO_CAP	0x8000
#endif
#ifndef SEGV_STORETAG
#define SEGV_STORETAG	15
#endif

/* --- Syscall validation tests (always compiled) --- */

TEST(test_prot_cap_anon_private)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_CAP,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, ptr);
	EXPECT_EQ(0, munmap(ptr, MMAP_SIZE));
}

TEST(test_prot_no_cap_anon_private)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_NO_CAP,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, ptr);
	EXPECT_EQ(0, munmap(ptr, MMAP_SIZE));
}

/* PROT_CAP and PROT_NO_CAP are mutually exclusive */
TEST(test_prot_cap_no_cap_einval)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE,
		   PROT_READ | PROT_WRITE | PROT_CAP | PROT_NO_CAP,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_EQ(MAP_FAILED, ptr);
	ASSERT_EQ(EINVAL, errno);
}

/* PROT_CAP on a file-backed MAP_SHARED mapping is rejected because ordinary
 * filesystems drop capability tags on writeback. */
TEST(test_prot_cap_file_shared_einval)
{
	char tmppath[] = "/tmp/mmap_prot_cap_XXXXXX";
	void *ptr;
	int fd;

	fd = mkstemp(tmppath);
	ASSERT_GE(fd, 0);
	unlink(tmppath);
	ASSERT_EQ(0, ftruncate(fd, MMAP_SIZE));

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_CAP,
		   MAP_SHARED, fd, 0);
	ASSERT_EQ(MAP_FAILED, ptr);
	ASSERT_EQ(EINVAL, errno);

	close(fd);
}

/* PROT_CAP on anonymous MAP_SHARED is allowed (no filesystem writeback) */
TEST(test_prot_cap_anon_shared)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_CAP,
		   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, ptr);
	EXPECT_EQ(0, munmap(ptr, MMAP_SIZE));
}

/* PROT_CAP is mmap-time only; mprotect() must reject it */
TEST(test_prot_cap_mprotect_einval)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, ptr);

	EXPECT_EQ(-1, mprotect(ptr, MMAP_SIZE, PROT_READ | PROT_CAP));
	EXPECT_EQ(EINVAL, errno);

	munmap(ptr, MMAP_SIZE);
}

/* PROT_NO_CAP is mmap-time only; mprotect() must reject it */
TEST(test_prot_no_cap_mprotect_einval)
{
	void *ptr;

	ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, ptr);

	EXPECT_EQ(-1, mprotect(ptr, MMAP_SIZE, PROT_READ | PROT_NO_CAP));
	EXPECT_EQ(EINVAL, errno);

	munmap(ptr, MMAP_SIZE);
}

/* --- Capability tag behaviour tests (require CHERI compiler) --- */

#ifdef __CHERI__

/* Storing a capability into a PROT_CAP region preserves the tag */
TEST(test_prot_cap_preserves_tags)
{
	int anchor = 0;
	void **region;

	region = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE | PROT_CAP,
		      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, region);

	*region = &anchor;
	EXPECT_EQ(1, cheri_tag_get(*region)) {
		TH_LOG("capability tag was not preserved in PROT_CAP region");
	}

	munmap(region, MMAP_SIZE);
}

static void segv_storetag_handler(int sig, siginfo_t *info, void *uctx)
{
	if (info->si_code == SEGV_STORETAG)
		_exit(0);
	_exit(3);	/* wrong si_code */
}

/*
 * Storing a capability into a PROT_NO_CAP region raises a CapStore exception
 * delivered as SIGSEGV with si_code == SEGV_STORETAG. Per the Zcheripte spec,
 * PTE.CW=0 causes a tagged capability store to trap rather than silently
 * stripping the tag. A forked child installs a SA_SIGINFO handler to assert
 * the si_code; the parent inspects the child's exit status.
 *
 * Child exit codes:
 *   0 — handler saw SEGV_STORETAG (success)
 *   2 — mmap failed
 *   3 — handler saw a different si_code
 *   4 — sc instruction did not trap
 *
 * The test also verifies that ordinary (non-capability) data access to a
 * PROT_NO_CAP region still works — the restriction applies only to
 * capability-tagged operations.
 */
TEST(test_prot_no_cap_store_traps)
{
	int status;
	pid_t pid;

	pid = fork();
	ASSERT_GE(pid, 0);

	if (pid == 0) {
		struct sigaction sa = {
			.sa_sigaction = segv_storetag_handler,
			.sa_flags = SA_SIGINFO,
		};
		int anchor = 0;
		void **region;

		sigemptyset(&sa.sa_mask);
		sigaction(SIGSEGV, &sa, NULL);

		region = mmap(NULL, MMAP_SIZE,
			      PROT_READ | PROT_WRITE | PROT_NO_CAP,
			      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (region == MAP_FAILED)
			_exit(2);

		asm volatile("sc %0, (%1)"
			     :
			     : "C" (&anchor), "C" (region)
			     : "memory");
		_exit(4);	/* sc did not trap */
	}

	ASSERT_EQ(pid, waitpid(pid, &status, 0));
	ASSERT_TRUE(WIFEXITED(status)) {
		TH_LOG("expected clean exit from handler, child killed by signal %d",
		       WIFSIGNALED(status) ? WTERMSIG(status) : -1);
	}
	ASSERT_EQ(0, WEXITSTATUS(status)) {
		TH_LOG("child exit %d (2=mmap fail, 3=wrong si_code, 4=sc did not trap)",
		       WEXITSTATUS(status));
	}

	{
		int *region;

		region = mmap(NULL, MMAP_SIZE,
			      PROT_READ | PROT_WRITE | PROT_NO_CAP,
			      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		ASSERT_NE(MAP_FAILED, region);

		*region = 42;
		EXPECT_EQ(42, *region);

		munmap(region, MMAP_SIZE);
	}
}

/* On RISCV CHERI the default for anonymous/private mappings implicitly
 * enables capability tag support (VM_READ_CAPS | VM_WRITE_CAPS), so no
 * explicit PROT_CAP is needed. */
TEST(test_default_anon_preserves_tags)
{
	int anchor = 0;
	void **region;

	region = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
		      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	ASSERT_NE(MAP_FAILED, region);

	*region = &anchor;
	EXPECT_EQ(1, cheri_tag_get(*region)) {
		TH_LOG("default anonymous mapping did not preserve capability tag");
	}

	munmap(region, MMAP_SIZE);
}

#endif /* __CHERI__ */

TEST_HARNESS_MAIN