#pragma once


#include <linux/compat.h>


struct __c64_xt_string_info {
	__u16 from_offset;
	__u16 to_offset;
	char	  algo[XT_STRING_MAX_ALGO_NAME_SIZE];
	char 	  pattern[XT_STRING_MAX_PATTERN_SIZE];
	__u8  patlen;
	union {
		struct {
			__u8  invert;
		} v0;

		struct {
			__u8  flags;
		} v1;
	} u;

	/* Used internally by the kernel */
	__c64_uptr config;
};

static __always_inline __maybe_unused void
__from_c64_xt_string_info(struct xt_string_info *p)
{
	union {
		struct xt_string_info native;
		const struct __c64_xt_string_info compat;
	} *u = (void *)p;

	u->native.config =  compat_ptr(u->compat.config);
	u->native.u.v1.flags = u->compat.u.v1.flags;
	u->native.u.v0.invert = u->compat.u.v0.invert;
	u->native.patlen = u->compat.patlen;
	BUILD_BUG_ON(sizeof(u->compat.pattern) != sizeof(u->native.pattern));
	memmove(&u->native.pattern, &u->compat.pattern, sizeof(u->native.pattern));
	BUILD_BUG_ON(sizeof(u->compat.algo) != sizeof(u->native.algo));
	memmove(&u->native.algo, &u->compat.algo, sizeof(u->native.algo));
	u->native.to_offset = u->compat.to_offset;
	u->native.from_offset = u->compat.from_offset;
}
static __always_inline __maybe_unused void
__to_c64_xt_string_info(struct xt_string_info *p)
{
	union {
		struct __c64_xt_string_info compat;
		const struct xt_string_info native;
	} *u = (void *)p;

	u->compat.from_offset = u->native.from_offset;
	u->compat.to_offset = u->native.to_offset;
	BUILD_BUG_ON(sizeof(u->native.algo) != sizeof(u->compat.algo));
	memmove(&u->compat.algo, &u->native.algo, sizeof(u->compat.algo));
	BUILD_BUG_ON(sizeof(u->native.pattern) != sizeof(u->compat.pattern));
	memmove(&u->compat.pattern, &u->native.pattern, sizeof(u->compat.pattern));
	u->compat.patlen = u->native.patlen;
	u->compat.u.v0.invert = u->native.u.v0.invert;
	u->compat.u.v1.flags = u->native.u.v1.flags;
	u->compat.config =  (__c64_uptr __force)(user_uintptr_t)u->native.config;
}
static __always_inline __maybe_unused void
__from_c64_xt_string_info_2(struct xt_string_info *native, const struct __c64_xt_string_info *compat)
{

	native->from_offset = compat->from_offset;
	native->to_offset = compat->to_offset;
	BUILD_BUG_ON(sizeof(compat->algo) != sizeof(native->algo));
	memcpy(&native->algo, &compat->algo, sizeof(native->algo));
	BUILD_BUG_ON(sizeof(compat->pattern) != sizeof(native->pattern));
	memcpy(&native->pattern, &compat->pattern, sizeof(native->pattern));
	native->patlen = compat->patlen;
	native->u.v0.invert = compat->u.v0.invert;
	native->u.v1.flags = compat->u.v1.flags;
	native->config =  compat_ptr(compat->config);
}
static __always_inline __maybe_unused void
__to_c64_xt_string_info_2(struct __c64_xt_string_info *compat, const struct xt_string_info *native)
{

	compat->from_offset = native->from_offset;
	compat->to_offset = native->to_offset;
	BUILD_BUG_ON(sizeof(native->algo) != sizeof(compat->algo));
	memcpy(&compat->algo, &native->algo, sizeof(compat->algo));
	BUILD_BUG_ON(sizeof(native->pattern) != sizeof(compat->pattern));
	memcpy(&compat->pattern, &native->pattern, sizeof(compat->pattern));
	compat->patlen = native->patlen;
	compat->u.v0.invert = native->u.v0.invert;
	compat->u.v1.flags = native->u.v1.flags;
	compat->config =  (__c64_uptr __force)(user_uintptr_t)native->config;
}
