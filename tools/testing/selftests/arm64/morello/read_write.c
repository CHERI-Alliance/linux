// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <stdint.h>
#include <stddef.h>

#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/uio.h>
#include <asm/fcntl.h>
#include <asm/unistd.h>

#include "freestanding.h"


#define MSG_LEN 16
#define VEC_MSG_NUM 2
#define VEC_MSG_LEN 12
#define VEC_MSG_TOTAL (VEC_MSG_LEN * VEC_MSG_NUM)

static const char msg_write[MSG_LEN] = "Pure cap binary\n";
static char msg_read[MSG_LEN];

static const char w_vec_msg1[VEC_MSG_LEN] = "This message";
static const char w_vec_msg2[VEC_MSG_LEN] = " is vector\n";
static char r_vec_msg1[VEC_MSG_LEN];
static char r_vec_msg2[VEC_MSG_LEN];

static const char file[] = "/check_cap.txt";

static const struct iovec w_iovec[VEC_MSG_NUM] = {
	{.iov_base = (char *) w_vec_msg1, .iov_len = VEC_MSG_LEN},
	{.iov_base = (char *) w_vec_msg2, .iov_len = VEC_MSG_LEN},
};

static struct iovec r_iovec[VEC_MSG_NUM] = {
	{.iov_base = r_vec_msg1, .iov_len = VEC_MSG_LEN},
	{.iov_base = r_vec_msg2, .iov_len = VEC_MSG_LEN},
};

static int fd;

TEST(test_getpid)
{
	syscall(__NR_getpid, 0);
}

TEST(test_write)
{
	write(1, msg_write, MSG_LEN);
}

TEST(test_writev)
{
	ssize_t ret = syscall(__NR_writev, 1, w_iovec, VEC_MSG_NUM);
	ASSERT_EQ(VEC_MSG_TOTAL, ret) TH_LOG("writev failed");
}

TEST(test_open)
{
	fd = syscall(__NR_openat, 0, file, O_RDWR | O_CREAT, 0666);
	ASSERT_LE(1, fd) TH_LOG("open failed");
}

TEST(test_read)
{
	ssize_t ret;

	/* write some data to be read again */
	ret = write(fd, msg_write, MSG_LEN);
	ASSERT_EQ(MSG_LEN, ret) TH_LOG("write failed");

	syscall(__NR_lseek, fd, 0, SEEK_SET);
	ret = syscall(__NR_read, fd, msg_read, MSG_LEN);
	ASSERT_EQ(MSG_LEN, ret) TH_LOG("read failed");

	ASSERT_EQ(0, memcmp(msg_read, msg_write, MSG_LEN));
}

TEST(test_readv)
{
	ssize_t ret;

	syscall(__NR_lseek, fd, 0, SEEK_SET);
	ret = syscall(__NR_writev, fd, w_iovec, VEC_MSG_NUM);
	ASSERT_EQ(VEC_MSG_TOTAL, ret) TH_LOG("writev failed");

	syscall(__NR_lseek, fd, 0, SEEK_SET);
	ret = syscall(__NR_readv, fd, r_iovec, VEC_MSG_NUM);
	ASSERT_EQ(VEC_MSG_TOTAL, ret) TH_LOG("readv failed");

	ASSERT_EQ(0, memcmp(w_vec_msg1, r_vec_msg1, VEC_MSG_LEN));
	ASSERT_EQ(0, memcmp(w_vec_msg2, r_vec_msg2, VEC_MSG_LEN));
}

TEST(test_close)
{
	int ret = syscall(__NR_close, fd);
	ASSERT_EQ(0, ret) TH_LOG("close failed");
}

int main(void)
{
	test_getpid();
	test_write();
	test_writev();
	test_open();
	test_read();
	test_readv();
	test_close();

	TH_LOG("all tests passed");

	return 0;
}
