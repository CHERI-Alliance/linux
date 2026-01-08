#pragma once


#include <linux/compat.h>


struct __c64_ptrace_sud_config {
	__u64 mode;
	/* Implicit padding if sizeof(__u64ptr) > sizeof(__u64) */
	__c64_ptr64 selector;
	__u64 offset;
	__u64 len;
};

static __always_inline __maybe_unused void
__from_c64_ptrace_sud_config(struct ptrace_sud_config *p)
{
	union {
		struct ptrace_sud_config native;
		const struct __c64_ptrace_sud_config compat;
	} *u = (void *)p;

	u->native.len = u->compat.len;
	u->native.offset = u->compat.offset;
	u->native.selector = (user_uintptr_t)compat_ptr(u->compat.selector);
	u->native.mode = u->compat.mode;
}
static __always_inline __maybe_unused void
__to_c64_ptrace_sud_config(struct ptrace_sud_config *p)
{
	union {
		struct __c64_ptrace_sud_config compat;
		const struct ptrace_sud_config native;
	} *u = (void *)p;

	u->compat.mode = u->native.mode;
	u->compat.selector = (__c64_ptr64 __force)u->native.selector;
	u->compat.offset = u->native.offset;
	u->compat.len = u->native.len;
}
static __always_inline __maybe_unused void
__from_c64_ptrace_sud_config_2(struct ptrace_sud_config *native, const struct __c64_ptrace_sud_config *compat)
{

	native->mode = compat->mode;
	native->selector = (user_uintptr_t)compat_ptr(compat->selector);
	native->offset = compat->offset;
	native->len = compat->len;
}
static __always_inline __maybe_unused void
__to_c64_ptrace_sud_config_2(struct __c64_ptrace_sud_config *compat, const struct ptrace_sud_config *native)
{

	compat->mode = native->mode;
	compat->selector = (__c64_ptr64 __force)native->selector;
	compat->offset = native->offset;
	compat->len = native->len;
}
