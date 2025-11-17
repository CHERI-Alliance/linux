#pragma once


#include <linux/compat.h>


struct __c64_vring {
	unsigned int num;

	__c64_uptr desc;

	__c64_uptr avail;

	__c64_uptr used;
};

static __always_inline __maybe_unused void
__from_c64_vring(struct vring *p)
{
	union {
		struct vring native;
		const struct __c64_vring compat;
	} *u = (void *)p;

	u->native.used =  compat_ptr(u->compat.used);
	u->native.avail =  compat_ptr(u->compat.avail);
	u->native.desc =  compat_ptr(u->compat.desc);
	u->native.num = u->compat.num;
}
static __always_inline __maybe_unused void
__to_c64_vring(struct vring *p)
{
	union {
		struct __c64_vring compat;
		const struct vring native;
	} *u = (void *)p;

	u->compat.num = u->native.num;
	u->compat.desc =  (__c64_uptr __force)(user_uintptr_t)u->native.desc;
	u->compat.avail =  (__c64_uptr __force)(user_uintptr_t)u->native.avail;
	u->compat.used =  (__c64_uptr __force)(user_uintptr_t)u->native.used;
}
static __always_inline __maybe_unused void
__from_c64_vring_2(struct vring *native, const struct __c64_vring *compat)
{

	native->num = compat->num;
	native->desc =  compat_ptr(compat->desc);
	native->avail =  compat_ptr(compat->avail);
	native->used =  compat_ptr(compat->used);
}
static __always_inline __maybe_unused void
__to_c64_vring_2(struct __c64_vring *compat, const struct vring *native)
{

	compat->num = native->num;
	compat->desc =  (__c64_uptr __force)(user_uintptr_t)native->desc;
	compat->avail =  (__c64_uptr __force)(user_uintptr_t)native->avail;
	compat->used =  (__c64_uptr __force)(user_uintptr_t)native->used;
}
