// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2023  Arm Limited

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <cheriintrin.h>
#include <linux/errno.h>
#include <linux/futex.h>
#include <linux/mman.h>
#include <linux/signal.h>
#include <linux/sysinfo.h>
#include <linux/socket.h>
#include <linux/time.h>
#include <linux/uio.h>

#include "freestanding.h"

#define MSG_LEN 16

static inline int fsopen(const char *string)
{
	return syscall(__NR_fsopen, string);
}

static inline int futex_wake_op(uint32_t *uaddr, uint32_t *uaddr2, uint32_t val3)
{
	return syscall(__NR_futex, uaddr, FUTEX_WAKE_OP, 1, 1,
		       uaddr2, val3);
}

typedef unsigned short sa_family_t;

struct sockaddr {
	sa_family_t sa_family;
	char sa_data[14];
};

static int getsockname(int socket, struct sockaddr *sockaddr, int *socklen)
{
	return syscall(__NR_getsockname, socket, sockaddr, socklen);
}

static inline int preadv(int fd, struct iovec *iov, int iovcnt)
{
	return syscall(__NR_preadv, fd, iov, iovcnt, 0);
}

static inline int writev(int fd, struct iovec *iov, int iovcnt)
{
	return syscall(__NR_writev, fd, iov, iovcnt);
}

static inline int sigaction(int sig, struct sigaction *old, struct sigaction *new)
{
	return syscall(__NR_rt_sigaction, sig, old, new, sizeof(sigset_t));
}

static inline int sysinfo(struct sysinfo *ptr)
{
	return syscall(__NR_sysinfo, ptr);
}

TEST(test_copy_to_user)
{
	struct sysinfo my_sysinfo;

	ASSERT_EQ(sysinfo(&my_sysinfo), 0);

	ASSERT_EQ(sysinfo(&my_sysinfo + 1), -EFAULT);

	ASSERT_EQ(sysinfo(cheri_tag_clear(&my_sysinfo)), -EFAULT);

	ASSERT_EQ(sysinfo(cheri_perms_and(&my_sysinfo, 0)), -EFAULT);
}

/*
 * sigaction() tests both copy_to_user and copy_from_user by copying
 * into and from a pointer to struct sigaction. The resulting action
 * in this case is a no-op, but this does not affect the validity of
 * the test. sigaction attempts to copy the new action from user space
 * and the old action to user space, if the arguments is valid in either
 * case.
 */
TEST(test_copy_user)
{
	struct sigaction act;

	ASSERT_EQ(sigaction(SIGSEGV, NULL, &act), 0);
	ASSERT_EQ(sigaction(SIGSEGV, &act, NULL), 0);

	ASSERT_EQ(sigaction(SIGSEGV, NULL, &act + 1), -EFAULT);
	ASSERT_EQ(sigaction(SIGSEGV, &act + 1, NULL), -EFAULT);

	ASSERT_EQ(sigaction(SIGSEGV, NULL, cheri_tag_clear(&act)), -EFAULT);
	ASSERT_EQ(sigaction(SIGSEGV, cheri_tag_clear(&act), NULL), -EFAULT);

	ASSERT_EQ(sigaction(SIGSEGV, NULL, cheri_perms_and(&act, 0)), -EFAULT);
	ASSERT_EQ(sigaction(SIGSEGV, cheri_perms_and(&act, 0), NULL), -EFAULT);
}

/*
 * getsockname(2) uses both get_user and put_user to copy the addrlen argument
 * from and to user space respectively. getsockname(2) calls move_addr_to_user
 * to copy an address to user space. move_addr_to_user also uses copy_to_user;
 * if copy_to_user is successful, but either of get_user or put_user fail then
 * getsockname(2) will return -EFAULT appropriately.
 */
TEST(test_get_put_user)
{
	struct sockaddr sa;
	int sa_len = sizeof(sa);
	int my_socket;

	// socket(AF_INET, SOCK_STREAM, 0)
	my_socket = syscall(__NR_socket, 2, 1, 0);

	// The socket must be successfully opened before proceeding.
	ASSERT_GE(my_socket, 0);

	ASSERT_EQ(getsockname(my_socket, &sa, &sa_len), 0);
	ASSERT_EQ(getsockname(my_socket, &sa, &sa_len + 1), -EFAULT);
	ASSERT_EQ(getsockname(my_socket, &sa, cheri_tag_clear(&sa_len)), -EFAULT);
	ASSERT_EQ(getsockname(my_socket, &sa, cheri_perms_and(&sa_len, 0)), -EFAULT);
	close(my_socket);
}

/*
 * The FUTEX_WAKE_OP operation in the futex(2) syscall is used to handle more
 * than one futex at the same time. This is an atomic operation that attempts
 * to read, modify and write a value at a second uaddr (uaddr2) and also wake
 * up waiters on the futex words at uaddr1 and uaddr2. uaddr1 and uaddr2 are
 * provided via capabilities, and so this futex tests the case of an atomic
 * uaccess operation.
 *
 * When using FUTEX_WAKE_OP, val3 is an encoding of both the operation as
 * well as the comparison to be performed on the futex word at uaddr2. If val3
 * is set to 0, this represents an operation of FUTEX_OP_SET and a comparison
 * FUTEX_OP_CMP_EQ, where both oparg and comparg are 0.
 */
TEST(test_futex)
{
	uint32_t futex = 0;

	ASSERT_GE(futex_wake_op(&futex, &futex, 0), 0);
	ASSERT_EQ(futex_wake_op(&futex, &futex + 1, 0), -EFAULT);
	ASSERT_EQ(futex_wake_op(&futex, cheri_tag_clear(&futex), 0), -EFAULT);
	ASSERT_EQ(futex_wake_op(&futex, cheri_perms_and(&futex, 0), 0),
		  -EFAULT);
}

/*
 * Test explicit accesses used in iov_iter via preadv and writev. Both
 * syscalls use explicit checking on the iov_base field of struct iovec,
 * so the metadata of the capability provided for iov_base is modified as
 * per the needs of each individual test. preadv is used to ensure that the
 * file is read with a file offset of 0, as the calls to writev modify the file
 * offset.
 */
TEST(test_explicit_iov_iter)
{
	char buf0[2];
	char buf1[4];
	char buf2[6];
	const char *write_buf0 = "Hello I am the first char buffer!\n";
	const char *write_buf1 = "Hello, I am the second char buffer.\n";
	const char *write_buf2 = "Hello, I am the third and final char buffer.\n";
	struct iovec iov[3];
	int iovcnt = sizeof(iov) / sizeof(struct iovec);
	int fd;

	fd = tmpfd();
	ASSERT_NE(fd, -1);

	iov[0].iov_base = (void *)write_buf0;
	iov[0].iov_len = strlen(write_buf0);
	iov[1].iov_base = (void *)write_buf1;
	iov[1].iov_len = strlen(write_buf1);
	iov[2].iov_base = (void *)write_buf2;
	iov[2].iov_len = strlen(write_buf2);

	ASSERT_GE(writev(fd, iov, iovcnt), 0);

	iov[0].iov_base = (void *)write_buf0 + 100;
	ASSERT_EQ(writev(fd, iov, iovcnt), -EFAULT);

	iov[0].iov_base = (void *)cheri_tag_clear(write_buf0);
	ASSERT_EQ(writev(fd, iov, iovcnt), -EFAULT);

	iov[0].iov_base = (void *)cheri_perms_and(write_buf0, 0);
	ASSERT_EQ(writev(fd, iov, iovcnt), -EFAULT);

	iov[0].iov_base = buf0;
	iov[0].iov_len = sizeof(buf0);
	iov[1].iov_base = buf1;
	iov[1].iov_len = sizeof(buf1);
	iov[2].iov_base = buf2;
	iov[2].iov_len = sizeof(buf2);

	ASSERT_GE(preadv(fd, iov, iovcnt), 0);

	iov[0].iov_base = buf0 + 100;
	ASSERT_EQ(preadv(fd, iov, iovcnt), -EFAULT);

	iov[0].iov_base = cheri_tag_clear(buf0);
	ASSERT_EQ(preadv(fd, iov, iovcnt), -EFAULT);

	iov[0].iov_base = cheri_perms_and(buf0, 0);
	ASSERT_EQ(preadv(fd, iov, iovcnt), -EFAULT);

	close(fd);
}

/*
 * strlen_user() explicitly inspects an input capability, the behaviour
 * of which must also be verified within these tests. The fsopen() syscall
 * makes use of strlen_user() by duplicating a string (representing the name
 * of a filesystem) with the strndup_user() function. strlen_user() can
 * therefore be tested with a call to fsopen().
 */
TEST(test_strlen_user)
{
	const char *fsname = "my_nonexistent_filesystem";

	// strndup_user() will still be called, so fsopen() fails after this.
	ASSERT_EQ(fsopen(fsname), -ENODEV);

	ASSERT_EQ(fsopen(fsname + strlen(fsname) * 10), -EFAULT);

	ASSERT_EQ(fsopen(cheri_tag_clear(fsname)), -EFAULT);

	ASSERT_EQ(fsopen(cheri_perms_and(fsname, 0)), -EFAULT);
}

int main(void)
{
	test_copy_to_user();
	test_copy_user();
	test_get_put_user();
	test_futex();
	test_explicit_iov_iter();
	test_strlen_user();
	return 0;
}
