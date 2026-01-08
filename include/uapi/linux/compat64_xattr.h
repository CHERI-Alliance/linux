#pragma once


#include <linux/compat.h>


struct __c64_xattr_args {
	__c64_ptr64 value;
	__u32 size;
	__u32 flags;
};

static __always_inline __maybe_unused void
__from_c64_xattr_args(struct xattr_args *p)
{
	union {
		struct xattr_args native;
		const struct __c64_xattr_args compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
}
static __always_inline __maybe_unused void
__to_c64_xattr_args(struct xattr_args *p)
{
	union {
		struct __c64_xattr_args compat;
		const struct xattr_args native;
	} *u = (void *)p;

	u->compat.value = (__c64_ptr64 __force)u->native.value;
	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_xattr_args_2(struct xattr_args *native, const struct __c64_xattr_args *compat)
{

	native->value = (user_uintptr_t)compat_ptr(compat->value);
	native->size = compat->size;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_xattr_args_2(struct __c64_xattr_args *compat, const struct xattr_args *native)
{

	compat->value = (__c64_ptr64 __force)native->value;
	compat->size = native->size;
	compat->flags = native->flags;
}
