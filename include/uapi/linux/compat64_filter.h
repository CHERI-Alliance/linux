#pragma once


#include <linux/compat.h>


struct __c64_sock_fprog {	/* Required for SO_ATTACH_FILTER. */
	unsigned short		len;	/* Number of filter blocks */
	__c64_uptr filter;
};

static __always_inline __maybe_unused void
__from_c64_sock_fprog(struct sock_fprog *p)
{
	union {
		struct sock_fprog native;
		const struct __c64_sock_fprog compat;
	} *u = (void *)p;

	u->native.filter =  compat_ptr(u->compat.filter);
	u->native.len = u->compat.len;
}
static __always_inline __maybe_unused void
__to_c64_sock_fprog(struct sock_fprog *p)
{
	union {
		struct __c64_sock_fprog compat;
		const struct sock_fprog native;
	} *u = (void *)p;

	u->compat.len = u->native.len;
	u->compat.filter =  (__c64_uptr __force)(user_uintptr_t)u->native.filter;
}
static __always_inline __maybe_unused void
__from_c64_sock_fprog_2(struct sock_fprog *native, const struct __c64_sock_fprog *compat)
{

	native->len = compat->len;
	native->filter =  compat_ptr(compat->filter);
}
static __always_inline __maybe_unused void
__to_c64_sock_fprog_2(struct __c64_sock_fprog *compat, const struct sock_fprog *native)
{

	compat->len = native->len;
	compat->filter =  (__c64_uptr __force)(user_uintptr_t)native->filter;
}
