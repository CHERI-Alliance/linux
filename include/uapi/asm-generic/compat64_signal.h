#pragma once


#include <linux/compat.h>


typedef struct __c64_sigaltstack {
	__c64_uptr ss_sp;
	int ss_flags;
	__kernel_size_t ss_size;
} __c64_stack_t;

static __always_inline __maybe_unused void
__from_c64_sigaltstack(struct sigaltstack *p)
{
	union {
		struct sigaltstack native;
		const struct __c64_sigaltstack compat;
	} *u = (void *)p;

	u->native.ss_size = u->compat.ss_size;
	u->native.ss_flags = u->compat.ss_flags;
	u->native.ss_sp =  compat_ptr(u->compat.ss_sp);
}
static __always_inline __maybe_unused void
__to_c64_sigaltstack(struct sigaltstack *p)
{
	union {
		struct __c64_sigaltstack compat;
		const struct sigaltstack native;
	} *u = (void *)p;

	u->compat.ss_sp =  (__c64_uptr __force)(user_uintptr_t)u->native.ss_sp;
	u->compat.ss_flags = u->native.ss_flags;
	u->compat.ss_size = u->native.ss_size;
}
static __always_inline __maybe_unused void
__from_c64_sigaltstack_2(struct sigaltstack *native, const struct __c64_sigaltstack *compat)
{

	native->ss_sp =  compat_ptr(compat->ss_sp);
	native->ss_flags = compat->ss_flags;
	native->ss_size = compat->ss_size;
}
static __always_inline __maybe_unused void
__to_c64_sigaltstack_2(struct __c64_sigaltstack *compat, const struct sigaltstack *native)
{

	compat->ss_sp =  (__c64_uptr __force)(user_uintptr_t)native->ss_sp;
	compat->ss_flags = native->ss_flags;
	compat->ss_size = native->ss_size;
}
