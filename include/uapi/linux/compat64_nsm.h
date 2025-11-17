#pragma once


#include <linux/compat.h>


struct __c64_nsm_iovec {
	__c64_ptr64 addr; /* Virtual address of target buffer */
	__u64 len;  /* Length of target buffer */
};

static __always_inline __maybe_unused void
__from_c64_nsm_iovec(struct nsm_iovec *p)
{
	union {
		struct nsm_iovec native;
		const struct __c64_nsm_iovec compat;
	} *u = (void *)p;

	u->native.len = u->compat.len;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
}
static __always_inline __maybe_unused void
__to_c64_nsm_iovec(struct nsm_iovec *p)
{
	union {
		struct __c64_nsm_iovec compat;
		const struct nsm_iovec native;
	} *u = (void *)p;

	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.len = u->native.len;
}
static __always_inline __maybe_unused void
__from_c64_nsm_iovec_2(struct nsm_iovec *native, const struct __c64_nsm_iovec *compat)
{

	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->len = compat->len;
}
static __always_inline __maybe_unused void
__to_c64_nsm_iovec_2(struct __c64_nsm_iovec *compat, const struct nsm_iovec *native)
{

	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->len = native->len;
}
struct __c64_nsm_raw {
	/* Request from user */
	struct __c64_nsm_iovec request;
	/* Response to user */
	struct __c64_nsm_iovec response;
};

static __always_inline __maybe_unused void
__from_c64_nsm_raw(struct nsm_raw *p)
{
	union {
		struct nsm_raw native;
		const struct __c64_nsm_raw compat;
	} *u = (void *)p;

	u->native.response.len = u->compat.response.len;
	u->native.response.addr = (user_uintptr_t)compat_ptr(u->compat.response.addr);
	u->native.request.len = u->compat.request.len;
	u->native.request.addr = (user_uintptr_t)compat_ptr(u->compat.request.addr);
}
static __always_inline __maybe_unused void
__to_c64_nsm_raw(struct nsm_raw *p)
{
	union {
		struct __c64_nsm_raw compat;
		const struct nsm_raw native;
	} *u = (void *)p;

	u->compat.request.addr = (__c64_ptr64 __force)u->native.request.addr;
	u->compat.request.len = u->native.request.len;
	u->compat.response.addr = (__c64_ptr64 __force)u->native.response.addr;
	u->compat.response.len = u->native.response.len;
}
static __always_inline __maybe_unused void
__from_c64_nsm_raw_2(struct nsm_raw *native, const struct __c64_nsm_raw *compat)
{

	native->request.addr = (user_uintptr_t)compat_ptr(compat->request.addr);
	native->request.len = compat->request.len;
	native->response.addr = (user_uintptr_t)compat_ptr(compat->response.addr);
	native->response.len = compat->response.len;
}
static __always_inline __maybe_unused void
__to_c64_nsm_raw_2(struct __c64_nsm_raw *compat, const struct nsm_raw *native)
{

	compat->request.addr = (__c64_ptr64 __force)native->request.addr;
	compat->request.len = native->request.len;
	compat->response.addr = (__c64_ptr64 __force)native->response.addr;
	compat->response.len = native->response.len;
}
