/* SPDX-License-Identifier: GPL-2.0
 * Copyright (C) 2021  Arm Limited
 */

#ifndef _FREESTANDING_H
#define _FREESTANDING_H

#include <stdint.h>
#include <stddef.h>
#include <asm/unistd.h>
#include <linux/posix_types.h>

/* this is provided by libc, so roll our own */
typedef __kernel_ssize_t ssize_t;
typedef __kernel_pid_t pid_t;

void install_kernel_stack(void);
uintcap_t __syscall(uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t, uintcap_t);
int __attribute__ ((format(printf, 1, 2))) printf(const char *fmt, ...);

#define __cap(x) ((uintcap_t) (x))
/* make the syscall wrapper a bit more direct and convenient to use */
#define __syscall_fill(sys_no, arg1, arg2, arg3, arg4, arg5, arg6, ...) \
	__syscall(sys_no, __cap(arg1), __cap(arg2), __cap(arg3), __cap(arg4), __cap(arg5), __cap(arg6))
#define syscall(sys_no, ...) __syscall_fill(sys_no, ##__VA_ARGS__, 0, 0, 0, 0, 0, 0)

extern void *stack_from_kernel;

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

#endif
