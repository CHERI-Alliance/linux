#pragma once


#include <linux/compat.h>


struct __c64___sigset_argpack {
	__c64_uptr sigmask;
	size_t sigsetsize;
};

static __always_inline __maybe_unused void
__from_c64___sigset_argpack(struct __sigset_argpack *p)
{
	union {
		struct __sigset_argpack native;
		const struct __c64___sigset_argpack compat;
	} *u = (void *)p;

	u->native.sigsetsize = u->compat.sigsetsize;
	u->native.sigmask =  compat_ptr(u->compat.sigmask);
}
static __always_inline __maybe_unused void
__to_c64___sigset_argpack(struct __sigset_argpack *p)
{
	union {
		struct __c64___sigset_argpack compat;
		const struct __sigset_argpack native;
	} *u = (void *)p;

	u->compat.sigmask =  (__c64_uptr __force)(user_uintptr_t)u->native.sigmask;
	u->compat.sigsetsize = u->native.sigsetsize;
}
static __always_inline __maybe_unused void
__from_c64___sigset_argpack_2(struct __sigset_argpack *native, const struct __c64___sigset_argpack *compat)
{

	native->sigmask =  compat_ptr(compat->sigmask);
	native->sigsetsize = compat->sigsetsize;
}
static __always_inline __maybe_unused void
__to_c64___sigset_argpack_2(struct __c64___sigset_argpack *compat, const struct __sigset_argpack *native)
{

	compat->sigmask =  (__c64_uptr __force)(user_uintptr_t)native->sigmask;
	compat->sigsetsize = native->sigsetsize;
}
