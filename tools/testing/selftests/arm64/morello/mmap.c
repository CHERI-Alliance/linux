// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited
/*
 * this is a limited test. Once the signal handling is implemented this should
 * be extended to cover invalid accesses to mmaped memory.
 */
#include <linux/mman.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <cheriintrin.h>
#include "freestanding.h"


#define MMAP_SIZE ((1ULL << 16) << 1) /* 64k x 2 */
#define MMAP_SIZE_REDUCED (MMAP_SIZE >> 1)
#define FILE_PERM 0666
#define PROT_ALL (PROT_READ | PROT_WRITE | PROT_EXEC)

#define PROBE_MODE_TOUCH	0x01
#define PROBE_MODE_VERIFY	0x02

/* As the minimum address is configurable, consider the default value of
 * CONFIG_LSM_MMAP_MIN_ADDR which is 65536 (64K) for a fixed address.
 */
#define min_addr (1ULL << 16)

static unsigned long pagesize;

static inline int probe_mem_range(void *ptr, size_t size, int mode)
{
	unsigned int *p = (unsigned int *)ptr;
	size_t probe_size =  size / sizeof(unsigned int);

	if (mode & PROBE_MODE_TOUCH) {
		for (unsigned int i = probe_size; i > 0; i--)
			p[i-1] = i;
	}
	if (mode & PROBE_MODE_VERIFY) {
		for (unsigned int i = probe_size; i > 0; i--)
			if (p[i-1] != i)
				return -1;
	}
	return 0;
}

/* Simple test to check our ability to create a new anonymous mapping
 * in the virtual address space of the calling process
 */
TEST(test_syscall_mmap)
{

	void *ptr = mmap_verified(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0,
				  CAP_LOAD_PERMS | CAP_STORE_PERMS);

	ASSERT_NE(ptr, NULL);

	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY)) {
		TH_LOG("Failed on probing allocated mem range\n");
	}
	EXPECT_EQ(0, munmap(ptr, MMAP_SIZE));
}

/* test mmap providing it with a file descriptor, testing related
 * functionality
 */
TEST(test_syscall_mmap2)
{
	const char msg[] = "foo";
	unsigned int msg_len = sizeof(msg); /* No need for the terminator */
	void *ptr;
	int fd;
	int retval;

	/* create a sample file to map onto with mmap */
	fd = tmpfd();

	ASSERT_GE(fd, 0);

	retval = lseek(fd, MMAP_SIZE, SEEK_SET);
	ASSERT_EQ(retval, MMAP_SIZE);

	/* attempt to write arbitrary data to file */
	retval = write(fd, msg, msg_len);
	ASSERT_EQ(retval, (int)msg_len);

	ptr = mmap_verified(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
			    0, CHERI_PERM_LOAD | CHERI_PERM_STORE);

	EXPECT_NE(ptr, NULL)
		goto clean_up;

	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	/* Attempt to change bounds of memory mapping, shrink by factor of 2 */
	ptr = mremap(ptr, MMAP_SIZE, MMAP_SIZE_REDUCED, 0, 0);

	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	/* advise kernel about how to handle paging of mapped memory.*/
	retval = madvise(ptr, MMAP_SIZE_REDUCED, MADV_WILLNEED);
	ASSERT_EQ(retval, 0);

	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE_REDUCED,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));
	/* An attempt to change permissions to RO */
	retval = mprotect(ptr, MMAP_SIZE_REDUCED, PROT_READ);
	ASSERT_EQ(retval, 0);
	/* Write permission should be revoked - verify mode only */
	/* To be extended when signals are fully supported */
	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE_REDUCED, PROBE_MODE_VERIFY));

clean_up:
	/* do unmap */
	munmap(ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* do file close */
	close(fd);
}

/* test to verify mmap() behaviour when MAP_GROWSDOWN flag is specified */
TEST(test_map_growsdown)
{
	void *ptr;
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_GROWSDOWN;

	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	EXPECT_EQ((unsigned long)ptr, (unsigned long)-EOPNOTSUPP);
}

/* test to verify invalid capability passed to address space management syscalls
 * results in failure of the syscall.
 */
TEST(test_validity_tag_check)
{
	void *ptr, *new_ptr;
	int retval;
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;
	unsigned char vec[MMAP_SIZE / pagesize];

	/* passing invalid capability to mmap() */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	new_ptr = mmap(cheri_tag_clear(ptr), MMAP_SIZE_REDUCED, prot,
		       flags | MAP_FIXED, -1, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-EINVAL);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* passing invalid capability to munmap() */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(cheri_tag_clear(ptr), MMAP_SIZE);
	EXPECT_EQ(retval, -EINVAL);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* passing invalid capability to mremap() */
	ptr = mmap(NULL, MMAP_SIZE_REDUCED, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	new_ptr = mremap(cheri_tag_clear(ptr), MMAP_SIZE_REDUCED, MMAP_SIZE,
			 MREMAP_MAYMOVE, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-EINVAL);

	retval = munmap(ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* passing invalid capability to mprotect() */
	ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(prot) | PROT_READ, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	retval = mprotect(cheri_tag_clear(ptr), MMAP_SIZE, PROT_WRITE);
	EXPECT_EQ(retval, -EINVAL);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* as the remaining syscalls are expected to fail in a similar manner,
	 * have a common mapping.
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	/* passing invalid capability to madvise() */
	retval = madvise(cheri_tag_clear(ptr), MMAP_SIZE, MADV_WILLNEED);
	EXPECT_EQ(retval, -EINVAL);

	/* passing invalid capability to mincore() */
	retval = mincore(cheri_tag_clear(ptr), MMAP_SIZE, vec);
	EXPECT_EQ(retval, -EINVAL);

	/* passing invalid capability to mlock() */
	retval = mlock(cheri_tag_clear(ptr), MMAP_SIZE);
	EXPECT_EQ(retval, -EINVAL);

	/* passing invalid capability to mlock2() */
	retval = mlock2(cheri_tag_clear(ptr), MMAP_SIZE, MLOCK_ONFAULT);
	EXPECT_EQ(retval, -EINVAL);

	/* passing invalid capability to munlock() */
	EXPECT_EQ(0, mlock(ptr, MMAP_SIZE_REDUCED));
	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE_REDUCED,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munlock(cheri_tag_clear(ptr), MMAP_SIZE_REDUCED);
	EXPECT_EQ(retval, -EINVAL);

	retval = munlock(ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* passing invalid capability to msync() */
	retval = msync(cheri_tag_clear(ptr), MMAP_SIZE, MS_SYNC);
	EXPECT_EQ(retval, -EINVAL);

	/* unmap the common mapping */
	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);
}

/* test to verify address space management syscall behaviour when capability
 * range is modified
 */
TEST(test_range_check)
{
	void *ptr, *reduced_bound_ptr, *ret;
	int retval;
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;
	unsigned char vec[MMAP_SIZE / pagesize];

	/* mapping a smaller range at prev mmap ptr in a subsequent mmap()
	 * call without first unmapping
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	ret = mmap(ptr, MMAP_SIZE_REDUCED, prot, flags | MAP_FIXED, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ret));
	EXPECT_EQ(0, probe_mem_range(ret, MMAP_SIZE_REDUCED,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* mapping a larger range at prev mmap ptr in a subsequent mmap()
	 * call without first unmapping
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	ret = mmap(ptr, 2 * MMAP_SIZE, prot, flags | MAP_FIXED, -1, 0);
	EXPECT_EQ((unsigned long)ret, (unsigned long)-EINVAL);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* as the following syscalls are expected to fail in a similar manner,
	 * have a common mapping and reduced bound pointer.
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));
	reduced_bound_ptr = cheri_bounds_set(ptr, MMAP_SIZE_REDUCED);

	/* negative munmap() range test */
	retval = munmap(reduced_bound_ptr, MMAP_SIZE);
	EXPECT_EQ(retval, -EINVAL);

	/* negative mincore() range test */
	retval = mincore(reduced_bound_ptr, MMAP_SIZE, vec);
	EXPECT_EQ(retval, -EINVAL);

	/* negative mlock() range test */
	retval = mlock(reduced_bound_ptr, MMAP_SIZE);
	EXPECT_EQ(retval, -EINVAL);

	/* negative munlock() range test */
	EXPECT_EQ(0, mlock2(ptr, MMAP_SIZE, MLOCK_ONFAULT));
	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munlock(reduced_bound_ptr, MMAP_SIZE);
	EXPECT_EQ(retval, -EINVAL);

	retval = munlock(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* negative msync() range test */
	retval = msync(reduced_bound_ptr, MMAP_SIZE, MS_SYNC);
	EXPECT_EQ(retval, -EINVAL);

	/* negative madvise() range test */
	retval = madvise(reduced_bound_ptr, MMAP_SIZE, MADV_NORMAL);
	EXPECT_EQ(retval, -EINVAL);

	/* release the common mapping */
	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);
}

/* test to verify mmap() reservation semantics */
TEST(test_check_mmap_reservation)
{
	void *ptr, *new_ptr;
	size_t size;
	int retval;
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;

	/* test to verify rest of reservation region is accessible after a partial
	 * unmap
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = munmap(ptr, pagesize);
	ASSERT_EQ(retval, 0);

	ptr = ptr + pagesize;
	size = MMAP_SIZE - pagesize;
	EXPECT_EQ(0, probe_mem_range(ptr, size,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(ptr, size);
	ASSERT_EQ(retval, 0);

	/* test to verify that a subsequent mmap() call to the same region whose
	 * reservation has been destroyed fails. This test is in accordance with
	 * the current implementation.
	 */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	new_ptr = mmap(ptr, MMAP_SIZE_REDUCED, prot, flags | MAP_FIXED, -1, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-ERESERVATION);

	/* null-derived ptr overlaps with an existing reservation */
	ptr = mmap((void *)(uintptr_t)min_addr, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	new_ptr = mmap((void *)(uintptr_t)min_addr + MMAP_SIZE_REDUCED, MMAP_SIZE, prot,
		       flags | MAP_FIXED, -1, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-ERESERVATION);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);
}

/* test to verify mremap() reservation semantics */
TEST(test_check_mremap_reservation)
{
	void *ptr, *new_ptr;
	int retval;
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;

	/* expanding a mapping with MREMAP_MAYMOVE flag specified */
	ptr = mmap(NULL, MMAP_SIZE_REDUCED, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	new_ptr = mremap(ptr, MMAP_SIZE_REDUCED, MMAP_SIZE, MREMAP_MAYMOVE, NULL);
	ASSERT_FALSE(IS_ERR_VALUE(new_ptr));
	ASSERT_NE(ptr, new_ptr);
	EXPECT_EQ(0, probe_mem_range(new_ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(new_ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* expanding a mapping without MREMAP_MAYMOVE flag triggers an ENOMEM error */
	ptr = mmap(NULL, MMAP_SIZE_REDUCED, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	new_ptr = mremap(ptr, MMAP_SIZE_REDUCED, MMAP_SIZE, 0, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-ENOMEM);

	retval = munmap(ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* attempt to resize a mapping range greater than what the capability owns */
	ptr = mmap(NULL, MMAP_SIZE_REDUCED, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	new_ptr = mremap(ptr, MMAP_SIZE, MMAP_SIZE, MREMAP_MAYMOVE, 0);
	EXPECT_EQ((unsigned long)new_ptr, (unsigned long)-EINVAL);

	retval = munmap(ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* attempt to grow mappings in-place */
	ptr = mmap(NULL, MMAP_SIZE, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = munmap(ptr + MMAP_SIZE_REDUCED, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	new_ptr = mremap(ptr, MMAP_SIZE_REDUCED, MMAP_SIZE, 0, 0);
	ASSERT_FALSE(IS_ERR_VALUE(new_ptr));

	retval = munmap(new_ptr, MMAP_SIZE);
	EXPECT_EQ(retval, 0);
}

/* test to verify address space management syscall behaviour when permissions
 * are modified.
 */
TEST(test_permissions)
{
	void *ptr, *old_ptr, *new_ptr, *ret;
	int flags, retval;
	int prot, max_prot;
	size_t perms;

	/* increase permission beyond the maximum prot specified for the mapping */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	max_prot = PROT_READ | PROT_WRITE;
	prot = PROT_READ;

	ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(max_prot) | prot,
		   flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = mprotect(ptr, MMAP_SIZE, PROT_EXEC);
	ASSERT_EQ(retval, -EINVAL);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* max_prot has fewer permissions than prot */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	max_prot = PROT_WRITE | PROT_EXEC;
	prot = PROT_ALL;

	ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(max_prot) | prot, flags, -1, 0);
	EXPECT_EQ((unsigned long)ptr, (unsigned long)-EINVAL);

	/* max_prot has more permissions than prot */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	max_prot = PROT_ALL;
	prot = PROT_READ | PROT_EXEC;

	ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(max_prot) | prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = mprotect(ptr, MMAP_SIZE, PROT_WRITE);
	ASSERT_EQ(retval, 0);

	EXPECT_EQ(0, probe_mem_range(ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* repeat positive max_prot test with fixed address */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	max_prot = PROT_ALL;
	prot = PROT_READ | PROT_EXEC;

	ptr = mmap((void *)(uintptr_t)min_addr, MMAP_SIZE, PROT_MAX(max_prot) | prot,
		   flags | MAP_FIXED, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	retval = mprotect(ptr, MMAP_SIZE, PROT_WRITE);
	ASSERT_EQ(retval, 0);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* LoadCap and StoreCap permissions must not be given to a shared mapping */
	flags = MAP_SHARED | MAP_ANONYMOUS;
	prot = PROT_READ | PROT_WRITE;

	ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(prot) | PROT_READ, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(ptr));

	perms = cheri_perms_get(ptr);
	EXPECT_EQ((perms & (CHERI_PERM_LOAD_CAP | CHERI_PERM_STORE_CAP)), 0);

	retval = munmap(ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* permissions of capability returned by mremap must match the permissions
	 * returned by the original mapping.
	 */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	prot = PROT_READ | PROT_WRITE;

	old_ptr = mmap(NULL, MMAP_SIZE_REDUCED, prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(old_ptr));

	new_ptr = mremap(old_ptr, MMAP_SIZE_REDUCED, MMAP_SIZE,
			 MREMAP_MAYMOVE, 0);
	ASSERT_FALSE(IS_ERR_VALUE(new_ptr));

	ASSERT_EQ(cheri_perms_get(old_ptr), cheri_perms_get(new_ptr));
	EXPECT_EQ(0, probe_mem_range(new_ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(new_ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* remapping to a new_ptr having reduced permissions from old_ptr */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	prot = PROT_READ | PROT_WRITE;

	old_ptr = mmap(NULL, MMAP_SIZE_REDUCED, PROT_MAX(prot | PROT_EXEC) |
		       prot, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(old_ptr));

	new_ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(prot) | PROT_READ, flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(new_ptr));

	ret = mremap(old_ptr, MMAP_SIZE_REDUCED, MMAP_SIZE,
		     MREMAP_MAYMOVE | MREMAP_FIXED, new_ptr);
	ASSERT_FALSE(IS_ERR_VALUE(ret));
	EXPECT_EQ(0, probe_mem_range(new_ptr, MMAP_SIZE,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	retval = munmap(ret, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	/* remapping to new_ptr having increased permissions from old_ptr */
	flags = MAP_PRIVATE | MAP_ANONYMOUS;
	prot = PROT_READ | PROT_WRITE;

	old_ptr = mmap(NULL, MMAP_SIZE_REDUCED, PROT_MAX(prot) | PROT_READ,
		       flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(old_ptr));

	new_ptr = mmap(NULL, MMAP_SIZE, PROT_MAX(prot | PROT_EXEC) | prot,
		       flags, -1, 0);
	ASSERT_FALSE(IS_ERR_VALUE(new_ptr));

	ret = mremap(old_ptr, MMAP_SIZE_REDUCED, MMAP_SIZE,
		     MREMAP_MAYMOVE | MREMAP_FIXED, new_ptr);
	EXPECT_EQ((unsigned long)ret, (unsigned long)-EINVAL);

	retval = munmap(new_ptr, MMAP_SIZE);
	ASSERT_EQ(retval, 0);

	retval = munmap(old_ptr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);
}

/* test to verify that using brk() results syscall failure */
TEST(test_brk_check)
{
	int retval;

	retval = brk(NULL);
	EXPECT_EQ(retval, -ENOSYS);
}

int main(int argc __maybe_unused, char **argv __maybe_unused, char **envp __maybe_unused,
	 struct morello_auxv *auxv)
{
	pagesize = get_pagesize(auxv);

	test_syscall_mmap();
	test_syscall_mmap2();
	test_map_growsdown();
	test_validity_tag_check();
	test_range_check();
	test_check_mmap_reservation();
	test_check_mremap_reservation();
	test_permissions();
	test_brk_check();
	return 0;
}
