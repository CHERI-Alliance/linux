#pragma once


#include <linux/compat.h>


struct __c64_pr_read_keys {
	__u32	generation;
	__u32	num_keys;
	__c64_ptr64	keys_ptr;
};

static __always_inline __maybe_unused void
__from_c64_pr_read_keys(struct pr_read_keys *p)
{
	union {
		struct pr_read_keys native;
		const struct __c64_pr_read_keys compat;
	} *u = (void *)p;

	u->native.keys_ptr = (user_uintptr_t)compat_ptr(u->compat.keys_ptr);
	u->native.num_keys = u->compat.num_keys;
	u->native.generation = u->compat.generation;
}
static __always_inline __maybe_unused void
__to_c64_pr_read_keys(struct pr_read_keys *p)
{
	union {
		struct __c64_pr_read_keys compat;
		const struct pr_read_keys native;
	} *u = (void *)p;

	u->compat.generation = u->native.generation;
	u->compat.num_keys = u->native.num_keys;
	u->compat.keys_ptr = (__c64_ptr64 __force)u->native.keys_ptr;
}
static __always_inline __maybe_unused void
__from_c64_pr_read_keys_2(struct pr_read_keys *native, const struct __c64_pr_read_keys *compat)
{

	native->generation = compat->generation;
	native->num_keys = compat->num_keys;
	native->keys_ptr = (user_uintptr_t)compat_ptr(compat->keys_ptr);
}
static __always_inline __maybe_unused void
__to_c64_pr_read_keys_2(struct __c64_pr_read_keys *compat, const struct pr_read_keys *native)
{

	compat->generation = native->generation;
	compat->num_keys = native->num_keys;
	compat->keys_ptr = (__c64_ptr64 __force)native->keys_ptr;
}
