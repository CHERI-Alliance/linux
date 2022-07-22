/* SPDX-License-Identifier: GPL-2.0
 * Copyright (C) 2021  Arm Limited
 */

#ifndef _FREESTANDING_H
#define _FREESTANDING_H

#include <stdint.h>
#include <stddef.h>
#include <asm/unistd.h>
#include <linux/posix_types.h>
#include <cheriintrin.h>

/* this is provided by libc, so roll our own */
typedef __kernel_ssize_t ssize_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_mqd_t mqd_t;
typedef __kernel_timer_t timer_t;
typedef __kernel_clockid_t clockid_t;

struct __test_meta {
	int message;
};

void install_kernel_stack(void);
uintcap_t __syscall(uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t);

void switch_to_restricted(uintcap_t, void *);

int __attribute__ ((format(printf, 1, 2))) printf(const char *fmt, ...);

#define __cap(x) ((uintcap_t) (x))
/* make the syscall wrapper a bit more direct and convenient to use */
#define __syscall_fill(sys_no, arg1, arg2, arg3, arg4, arg5, arg6, ...) \
	__syscall(sys_no, __cap(arg1), __cap(arg2), __cap(arg3), __cap(arg4), __cap(arg5), __cap(arg6))
#define syscall(sys_no, ...) __syscall_fill(sys_no, ##__VA_ARGS__, 0, 0, 0, 0, 0, 0)

#define TH_LOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define __TH_LOG_ERROR(fmt, ...) \
	TH_LOG("ERROR: %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#define MAX_ERRNO       4095
#define IS_ERR_VALUE(x) ((unsigned long)(x) >= (unsigned long)-MAX_ERRNO)

/* mimic the kselftest harness */
#define TEST(test_name) \
	void test_name##_actual(void); \
	void test_name(void) \
	{ \
		struct __test_meta meta = {.message = 0};\
		__cur_test = &meta; \
		test_name##_actual(); \
		TH_LOG("PASSED: %s", #test_name); \
	} \
	void test_name##_actual(void)


#define CAP_LOAD_PERMS					\
	(CHERI_PERM_LOAD | CHERI_PERM_LOAD_CAP |	\
	 ARM_CAP_PERMISSION_MUTABLE_LOAD)
#define CAP_STORE_PERMS					\
	(CHERI_PERM_STORE | CHERI_PERM_STORE_CAP |	\
	 CHERI_PERM_STORE_LOCAL_CAP)

#define STACK_REQ_PERMS	(CAP_LOAD_PERMS | CAP_STORE_PERMS | CHERI_PERM_GLOBAL)

#define allocate_mem_raw(size)						\
	(void *) syscall(__NR_mmap, NULL, size, PROT_READ | PROT_WRITE,	\
				    MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)

/* this macro emulates its harness counterpart but is not API compatible */
#define __EXPECT(exp, seen, op, exit_on_fail) \
	do { \
		if (!((exp) op (seen))) { \
			__TH_LOG_ERROR("'(%s) %s (%s)' was false", #exp, #op, #seen); \
			__cur_test->message = 1; \
		} \
	} while (0); \
	for (; __cur_test->message; __cur_test->message = (exit_on_fail) ? (exit(1), 1) : 0)

/*
 * WARNING: All of the following macros work at any point in the call stack of
 * a TEST context. Their kselftest_harness equivalents DO NOT. If compatibility
 * with the harness is desired, they should only be used in a top-level TEST
 * context
 */
#define EXPECT(exp, seen, op) __EXPECT(exp, seen, op, 0)
#define ASSERT(exp, seen, op) __EXPECT(exp, seen, op, 1)

#define ASSERT_NE(exp, seen) ASSERT(exp, seen, !=)
#define ASSERT_EQ(exp, seen) ASSERT(exp, seen, ==)
#define ASSERT_LT(exp, seen) ASSERT(exp, seen, <)
#define ASSERT_LE(exp, seen) ASSERT(exp, seen, <=)
#define ASSERT_GT(exp, seen) ASSERT(exp, seen, >)
#define ASSERT_GE(exp, seen) ASSERT(exp, seen, >=)
#define ASSERT_TRUE(seen) ASSERT(0, seen, !=)
#define ASSERT_FALSE(seen) ASSERT(0, seen, ==)
#define ASSERT_NULL(seen) ASSERT(NULL, seen, ==)

#define EXPECT_NE(exp, seen) EXPECT(exp, seen, !=)
#define EXPECT_EQ(exp, seen) EXPECT(exp, seen, ==)
#define EXPECT_LT(exp, seen) EXPECT(exp, seen, <)
#define EXPECT_LE(exp, seen) EXPECT(exp, seen, <=)
#define EXPECT_GT(exp, seen) EXPECT(exp, seen, >)
#define EXPECT_GE(exp, seen) EXPECT(exp, seen, >=)
#define EXPECT_TRUE(seen) EXPECT(0, seen, !=)
#define EXPECT_FALSE(seen) EXPECT(0, seen, ==)
#define EXPECT_NULL(seen) EXPECT(NULL, seen, ==)


extern void *stack_from_kernel;
extern struct __test_meta *__cur_test;

static inline size_t strlen(const char *str)
{
	size_t len = 0;
	for (; str[len] != '\0'; len++);
	return len;
}

static inline int memcmp(const char *buf1, const char *buf2, size_t len)
{
	for (; len != 0; len--, buf1++, buf2++) {
		if (*buf1 != *buf2)
			return (*buf1 < *buf2) ? -1 : 1;
	}
	return 0;
}

static inline void __attribute__ ((noreturn)) exit(int status)
{
	/* behave as musl */
	syscall(__NR_exit_group, status);
	syscall(__NR_exit, status);
	for (;;);
}

static inline ssize_t write(int fd, const void *buf, size_t count)
{
	return syscall(__NR_write, fd, buf, count);
}

long __clone(int (*fn)(void *), uintcap_t stack, int flags, void *arg,
	     pid_t *parent_tid, void *tls, pid_t *child_tid);

static inline void *mmap(void *addr, size_t length, int prot, int flags,
			 int fd, int offset)
{
	return (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
}

static inline int munmap(void *addr, size_t length)
{
	return syscall(__NR_munmap, addr, length);
}

static inline void *mmap_verified(void *addr, size_t length, int prot, int flags,
			    int fd,  int offset, unsigned int perms)
{
	void *__addr = mmap(addr, length, prot, flags, fd, offset);

	EXPECT_FALSE(IS_ERR_VALUE(__addr)) {
		TH_LOG("Failed to allocate memory: %p\n", __addr);
		return NULL;
	}

	EXPECT_TRUE(cheri_tag_get(__addr)) {
		TH_LOG("Invalid capability\n");
		goto clean_up;
	}

	EXPECT_EQ(cheri_perms_get(__addr) & perms, perms) {
		TH_LOG("Insufficient permissions for capability\n");
		goto clean_up;
	}

	return __addr;
clean_up:
	munmap(__addr, length);
	return NULL;
}

static inline int close(int fd)
{
	return syscall(__NR_close, fd);
}

#endif
