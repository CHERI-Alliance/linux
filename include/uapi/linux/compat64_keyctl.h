#pragma once


#include <linux/compat.h>


struct __c64_keyctl_kdf_params {
	__c64_uptr hashname;
	__c64_uptr otherinfo;
	__u32 otherinfolen;
	__u32 __spare[8];
};

static __always_inline __maybe_unused void
__from_c64_keyctl_kdf_params(struct keyctl_kdf_params *p)
{
	union {
		struct keyctl_kdf_params native;
		const struct __c64_keyctl_kdf_params compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__spare) != sizeof(u->native.__spare));
	memmove(&u->native.__spare, &u->compat.__spare, sizeof(u->native.__spare));
	u->native.otherinfolen = u->compat.otherinfolen;
	u->native.otherinfo =  compat_ptr(u->compat.otherinfo);
	u->native.hashname =  compat_ptr(u->compat.hashname);
}
static __always_inline __maybe_unused void
__to_c64_keyctl_kdf_params(struct keyctl_kdf_params *p)
{
	union {
		struct __c64_keyctl_kdf_params compat;
		const struct keyctl_kdf_params native;
	} *u = (void *)p;

	u->compat.hashname =  (__c64_uptr __force)(user_uintptr_t)u->native.hashname;
	u->compat.otherinfo =  (__c64_uptr __force)(user_uintptr_t)u->native.otherinfo;
	u->compat.otherinfolen = u->native.otherinfolen;
	BUILD_BUG_ON(sizeof(u->native.__spare) != sizeof(u->compat.__spare));
	memmove(&u->compat.__spare, &u->native.__spare, sizeof(u->compat.__spare));
}
static __always_inline __maybe_unused void
__from_c64_keyctl_kdf_params_2(struct keyctl_kdf_params *native, const struct __c64_keyctl_kdf_params *compat)
{

	native->hashname =  compat_ptr(compat->hashname);
	native->otherinfo =  compat_ptr(compat->otherinfo);
	native->otherinfolen = compat->otherinfolen;
	BUILD_BUG_ON(sizeof(compat->__spare) != sizeof(native->__spare));
	memcpy(&native->__spare, &compat->__spare, sizeof(native->__spare));
}
static __always_inline __maybe_unused void
__to_c64_keyctl_kdf_params_2(struct __c64_keyctl_kdf_params *compat, const struct keyctl_kdf_params *native)
{

	compat->hashname =  (__c64_uptr __force)(user_uintptr_t)native->hashname;
	compat->otherinfo =  (__c64_uptr __force)(user_uintptr_t)native->otherinfo;
	compat->otherinfolen = native->otherinfolen;
	BUILD_BUG_ON(sizeof(native->__spare) != sizeof(compat->__spare));
	memcpy(&compat->__spare, &native->__spare, sizeof(compat->__spare));
}
