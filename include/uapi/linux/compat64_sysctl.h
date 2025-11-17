#pragma once


#include <linux/compat.h>


struct __c64___sysctl_args {
	__c64_uptr name;
	int nlen;
	__c64_uptr oldval;
	__c64_uptr oldlenp;
	__c64_uptr newval;
	size_t newlen;
	unsigned long __unused[4];
};

static __always_inline __maybe_unused void
__from_c64___sysctl_args(struct __sysctl_args *p)
{
	union {
		struct __sysctl_args native;
		const struct __c64___sysctl_args compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__unused) != sizeof(u->native.__unused));
	memmove(&u->native.__unused, &u->compat.__unused, sizeof(u->native.__unused));
	u->native.newlen = u->compat.newlen;
	u->native.newval =  compat_ptr(u->compat.newval);
	u->native.oldlenp =  compat_ptr(u->compat.oldlenp);
	u->native.oldval =  compat_ptr(u->compat.oldval);
	u->native.nlen = u->compat.nlen;
	u->native.name =  compat_ptr(u->compat.name);
}
static __always_inline __maybe_unused void
__to_c64___sysctl_args(struct __sysctl_args *p)
{
	union {
		struct __c64___sysctl_args compat;
		const struct __sysctl_args native;
	} *u = (void *)p;

	u->compat.name =  (__c64_uptr __force)(user_uintptr_t)u->native.name;
	u->compat.nlen = u->native.nlen;
	u->compat.oldval =  (__c64_uptr __force)(user_uintptr_t)u->native.oldval;
	u->compat.oldlenp =  (__c64_uptr __force)(user_uintptr_t)u->native.oldlenp;
	u->compat.newval =  (__c64_uptr __force)(user_uintptr_t)u->native.newval;
	u->compat.newlen = u->native.newlen;
	BUILD_BUG_ON(sizeof(u->native.__unused) != sizeof(u->compat.__unused));
	memmove(&u->compat.__unused, &u->native.__unused, sizeof(u->compat.__unused));
}
static __always_inline __maybe_unused void
__from_c64___sysctl_args_2(struct __sysctl_args *native, const struct __c64___sysctl_args *compat)
{

	native->name =  compat_ptr(compat->name);
	native->nlen = compat->nlen;
	native->oldval =  compat_ptr(compat->oldval);
	native->oldlenp =  compat_ptr(compat->oldlenp);
	native->newval =  compat_ptr(compat->newval);
	native->newlen = compat->newlen;
	BUILD_BUG_ON(sizeof(compat->__unused) != sizeof(native->__unused));
	memcpy(&native->__unused, &compat->__unused, sizeof(native->__unused));
}
static __always_inline __maybe_unused void
__to_c64___sysctl_args_2(struct __c64___sysctl_args *compat, const struct __sysctl_args *native)
{

	compat->name =  (__c64_uptr __force)(user_uintptr_t)native->name;
	compat->nlen = native->nlen;
	compat->oldval =  (__c64_uptr __force)(user_uintptr_t)native->oldval;
	compat->oldlenp =  (__c64_uptr __force)(user_uintptr_t)native->oldlenp;
	compat->newval =  (__c64_uptr __force)(user_uintptr_t)native->newval;
	compat->newlen = native->newlen;
	BUILD_BUG_ON(sizeof(native->__unused) != sizeof(compat->__unused));
	memcpy(&compat->__unused, &native->__unused, sizeof(compat->__unused));
}
