#pragma once


#include <linux/compat.h>


struct __c64_iovec
{
	__c64_uptr iov_base;	/* BSD uses caddr_t (1003.1g requires void *) */
	__kernel_size_t iov_len; /* Must be size_t (1003.1g) */
};

static __always_inline __maybe_unused void
__from_c64_iovec(struct iovec *p)
{
	union {
		struct iovec native;
		const struct __c64_iovec compat;
	} *u = (void *)p;

	u->native.iov_len = u->compat.iov_len;
	u->native.iov_base =  compat_ptr(u->compat.iov_base);
}
static __always_inline __maybe_unused void
__to_c64_iovec(struct iovec *p)
{
	union {
		struct __c64_iovec compat;
		const struct iovec native;
	} *u = (void *)p;

	u->compat.iov_base =  (__c64_uptr __force)(user_uintptr_t)u->native.iov_base;
	u->compat.iov_len = u->native.iov_len;
}
static __always_inline __maybe_unused void
__from_c64_iovec_2(struct iovec *native, const struct __c64_iovec *compat)
{

	native->iov_base =  compat_ptr(compat->iov_base);
	native->iov_len = compat->iov_len;
}
static __always_inline __maybe_unused void
__to_c64_iovec_2(struct __c64_iovec *compat, const struct iovec *native)
{

	compat->iov_base =  (__c64_uptr __force)(user_uintptr_t)native->iov_base;
	compat->iov_len = native->iov_len;
}
