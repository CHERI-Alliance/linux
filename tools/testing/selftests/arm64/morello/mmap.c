// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited
/*
 * this is a limited test. Once the signal handling is implemented this should
 * be extended to cover invalid accesses to mmaped memory.
 */
#include <linux/mman.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <cheriintrin.h>
#include "freestanding.h"


#define MMAP_SIZE ((1ULL << 16) << 1) /* 64k x 2 */
#define MMAP_SIZE_REDUCED (MMAP_SIZE >> 1)
#define FILE_PERM 0666

#define PROBE_MODE_TOUCH	0x01
#define PROBE_MODE_VERIFY	0x02


static inline int probe_mem_range(void *addr, size_t size, int mode)
{
	unsigned int *p = (unsigned int *)addr;
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
static inline __attribute__((always_inline))
void syscall_mmap(void)
{

	void *addr = mmap_verified(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0,
				  CAP_LOAD_PERMS | CAP_STORE_PERMS);

	ASSERT_NE(addr, NULL);

	EXPECT_EQ(0, probe_mem_range(addr, MMAP_SIZE,
				    PROBE_MODE_TOUCH | PROBE_MODE_VERIFY)) {
		TH_LOG("Failed on probing allocated mem range\n");
	}
	EXPECT_EQ(0, munmap(addr, MMAP_SIZE));
}

/* test mmap providing it with a file descriptor, testing related
 * functionality
 */
static inline __attribute__((always_inline))
void syscall_mmap2(void)
{
	const char *msg = "foo";
	unsigned int msg_len = sizeof(msg); /* No need for the terminator */
	const char *sample_file = "/limbo.dat";
	void *addr;
	int fd;
	int retval;

	/* create a sample file to map onto with mmap */
	fd = syscall(__NR_openat, 0, sample_file, O_RDWR | O_CREAT, FILE_PERM);

	ASSERT_GE(fd, 0);

	retval = syscall(__NR_lseek, fd, MMAP_SIZE, SEEK_SET);
	ASSERT_EQ(retval, MMAP_SIZE);

	/* attempt to write arbitrary data to file */
	retval = write(fd, msg, msg_len);
	ASSERT_EQ(retval, (int)msg_len);

	addr = mmap_verified(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
		      0, CAP_LOAD_PERMS | CAP_STORE_PERMS);

	EXPECT_NE(addr, NULL)
		goto clean_up;

	EXPECT_EQ(0, probe_mem_range(addr, MMAP_SIZE,
				      PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));

	/* Attempt to change bounds of memory mapping, shrink by factor of 2 */
	addr = (void *)syscall(__NR_mremap, addr, MMAP_SIZE,
			      MMAP_SIZE_REDUCED, 0, 0);

	ASSERT_FALSE(IS_ERR_VALUE(addr));
	/* advise kernel about how to handle paging of mapped memory.*/
	retval = syscall(__NR_madvise, addr, MMAP_SIZE_REDUCED, MADV_WILLNEED);
	ASSERT_EQ(retval, 0);

	EXPECT_EQ(0, probe_mem_range(addr, MMAP_SIZE_REDUCED,
				     PROBE_MODE_TOUCH | PROBE_MODE_VERIFY));
	/* An attempt to change permissions to RO */
	retval = syscall(__NR_mprotect, addr, MMAP_SIZE_REDUCED, PROT_READ);
	ASSERT_EQ(retval, 0);
	/* Write permission should be revoked - verify mode only */
	/* To be extended when signals are fully supported */
	EXPECT_EQ(0, probe_mem_range(addr, MMAP_SIZE_REDUCED, PROBE_MODE_VERIFY));

clean_up:
	/* do unmap */
	munmap(addr, MMAP_SIZE_REDUCED);
	ASSERT_EQ(retval, 0);

	/* do file close */
	syscall(__NR_close, fd);
}

TEST(test_syscall_mmap)
{
	syscall_mmap();
}

TEST(test_syscall_mmap2)
{
	syscall_mmap2();
}

int main(void)
{
	test_syscall_mmap();
	test_syscall_mmap2();
	return 0;
}
