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

int main(int argc __maybe_unused, char **argv __maybe_unused, char **envp __maybe_unused,
	 struct morello_auxv *auxv)
{
	pagesize = get_pagesize(auxv);

	test_syscall_mmap();
	test_syscall_mmap2();
	test_map_growsdown();
	return 0;
}
