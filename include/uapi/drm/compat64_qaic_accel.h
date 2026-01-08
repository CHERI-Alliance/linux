#pragma once


#include <linux/compat.h>


struct __c64_qaic_manage_msg {
	__u32 len;
	__u32 count;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_qaic_manage_msg(struct qaic_manage_msg *p)
{
	union {
		struct qaic_manage_msg native;
		const struct __c64_qaic_manage_msg compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.count = u->compat.count;
	u->native.len = u->compat.len;
}
static __always_inline __maybe_unused void
__to_c64_qaic_manage_msg(struct qaic_manage_msg *p)
{
	union {
		struct __c64_qaic_manage_msg compat;
		const struct qaic_manage_msg native;
	} *u = (void *)p;

	u->compat.len = u->native.len;
	u->compat.count = u->native.count;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_qaic_manage_msg_2(struct qaic_manage_msg *native, const struct __c64_qaic_manage_msg *compat)
{

	native->len = compat->len;
	native->count = compat->count;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_qaic_manage_msg_2(struct __c64_qaic_manage_msg *compat, const struct qaic_manage_msg *native)
{

	compat->len = native->len;
	compat->count = native->count;
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_qaic_attach_slice {
	struct qaic_attach_slice_hdr hdr;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_qaic_attach_slice(struct qaic_attach_slice *p)
{
	union {
		struct qaic_attach_slice native;
		const struct __c64_qaic_attach_slice compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.hdr) != sizeof(u->native.hdr));
	memmove(&u->native.hdr, &u->compat.hdr, sizeof(u->native.hdr));
}
static __always_inline __maybe_unused void
__to_c64_qaic_attach_slice(struct qaic_attach_slice *p)
{
	union {
		struct __c64_qaic_attach_slice compat;
		const struct qaic_attach_slice native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.hdr) != sizeof(u->compat.hdr));
	memmove(&u->compat.hdr, &u->native.hdr, sizeof(u->compat.hdr));
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_qaic_attach_slice_2(struct qaic_attach_slice *native, const struct __c64_qaic_attach_slice *compat)
{

	BUILD_BUG_ON(sizeof(compat->hdr) != sizeof(native->hdr));
	memcpy(&native->hdr, &compat->hdr, sizeof(native->hdr));
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_qaic_attach_slice_2(struct __c64_qaic_attach_slice *compat, const struct qaic_attach_slice *native)
{

	BUILD_BUG_ON(sizeof(native->hdr) != sizeof(compat->hdr));
	memcpy(&compat->hdr, &native->hdr, sizeof(compat->hdr));
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_qaic_execute {
	struct qaic_execute_hdr hdr;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_qaic_execute(struct qaic_execute *p)
{
	union {
		struct qaic_execute native;
		const struct __c64_qaic_execute compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.hdr) != sizeof(u->native.hdr));
	memmove(&u->native.hdr, &u->compat.hdr, sizeof(u->native.hdr));
}
static __always_inline __maybe_unused void
__to_c64_qaic_execute(struct qaic_execute *p)
{
	union {
		struct __c64_qaic_execute compat;
		const struct qaic_execute native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.hdr) != sizeof(u->compat.hdr));
	memmove(&u->compat.hdr, &u->native.hdr, sizeof(u->compat.hdr));
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_qaic_execute_2(struct qaic_execute *native, const struct __c64_qaic_execute *compat)
{

	BUILD_BUG_ON(sizeof(compat->hdr) != sizeof(native->hdr));
	memcpy(&native->hdr, &compat->hdr, sizeof(native->hdr));
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_qaic_execute_2(struct __c64_qaic_execute *compat, const struct qaic_execute *native)
{

	BUILD_BUG_ON(sizeof(native->hdr) != sizeof(compat->hdr));
	memcpy(&compat->hdr, &native->hdr, sizeof(compat->hdr));
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_qaic_perf_stats {
	struct qaic_perf_stats_hdr hdr;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_qaic_perf_stats(struct qaic_perf_stats *p)
{
	union {
		struct qaic_perf_stats native;
		const struct __c64_qaic_perf_stats compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	BUILD_BUG_ON(sizeof(u->compat.hdr) != sizeof(u->native.hdr));
	memmove(&u->native.hdr, &u->compat.hdr, sizeof(u->native.hdr));
}
static __always_inline __maybe_unused void
__to_c64_qaic_perf_stats(struct qaic_perf_stats *p)
{
	union {
		struct __c64_qaic_perf_stats compat;
		const struct qaic_perf_stats native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.hdr) != sizeof(u->compat.hdr));
	memmove(&u->compat.hdr, &u->native.hdr, sizeof(u->compat.hdr));
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_qaic_perf_stats_2(struct qaic_perf_stats *native, const struct __c64_qaic_perf_stats *compat)
{

	BUILD_BUG_ON(sizeof(compat->hdr) != sizeof(native->hdr));
	memcpy(&native->hdr, &compat->hdr, sizeof(native->hdr));
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_qaic_perf_stats_2(struct __c64_qaic_perf_stats *compat, const struct qaic_perf_stats *native)
{

	BUILD_BUG_ON(sizeof(native->hdr) != sizeof(compat->hdr));
	memcpy(&compat->hdr, &native->hdr, sizeof(compat->hdr));
	compat->data = (__c64_ptr64 __force)native->data;
}
