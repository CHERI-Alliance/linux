#pragma once


#include <linux/compat.h>


struct __c64_io_uring_query_hdr {
	__c64_ptr64 next_entry;
	__c64_ptr64 query_data;
	__u32 query_op;
	__u32 size;
	__s32 result;
	__u32 __resv[3];
};

static __always_inline __maybe_unused void
__from_c64_io_uring_query_hdr(struct io_uring_query_hdr *p)
{
	union {
		struct io_uring_query_hdr native;
		const struct __c64_io_uring_query_hdr compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__resv) != sizeof(u->native.__resv));
	memmove(&u->native.__resv, &u->compat.__resv, sizeof(u->native.__resv));
	u->native.result = u->compat.result;
	u->native.size = u->compat.size;
	u->native.query_op = u->compat.query_op;
	u->native.query_data = (user_uintptr_t)compat_ptr(u->compat.query_data);
	u->native.next_entry = (user_uintptr_t)compat_ptr(u->compat.next_entry);
}
static __always_inline __maybe_unused void
__to_c64_io_uring_query_hdr(struct io_uring_query_hdr *p)
{
	union {
		struct __c64_io_uring_query_hdr compat;
		const struct io_uring_query_hdr native;
	} *u = (void *)p;

	u->compat.next_entry = (__c64_ptr64 __force)u->native.next_entry;
	u->compat.query_data = (__c64_ptr64 __force)u->native.query_data;
	u->compat.query_op = u->native.query_op;
	u->compat.size = u->native.size;
	u->compat.result = u->native.result;
	BUILD_BUG_ON(sizeof(u->native.__resv) != sizeof(u->compat.__resv));
	memmove(&u->compat.__resv, &u->native.__resv, sizeof(u->compat.__resv));
}
static __always_inline __maybe_unused void
__from_c64_io_uring_query_hdr_2(struct io_uring_query_hdr *native, const struct __c64_io_uring_query_hdr *compat)
{

	native->next_entry = (user_uintptr_t)compat_ptr(compat->next_entry);
	native->query_data = (user_uintptr_t)compat_ptr(compat->query_data);
	native->query_op = compat->query_op;
	native->size = compat->size;
	native->result = compat->result;
	BUILD_BUG_ON(sizeof(compat->__resv) != sizeof(native->__resv));
	memcpy(&native->__resv, &compat->__resv, sizeof(native->__resv));
}
static __always_inline __maybe_unused void
__to_c64_io_uring_query_hdr_2(struct __c64_io_uring_query_hdr *compat, const struct io_uring_query_hdr *native)
{

	compat->next_entry = (__c64_ptr64 __force)native->next_entry;
	compat->query_data = (__c64_ptr64 __force)native->query_data;
	compat->query_op = native->query_op;
	compat->size = native->size;
	compat->result = native->result;
	BUILD_BUG_ON(sizeof(native->__resv) != sizeof(compat->__resv));
	memcpy(&compat->__resv, &native->__resv, sizeof(compat->__resv));
}
