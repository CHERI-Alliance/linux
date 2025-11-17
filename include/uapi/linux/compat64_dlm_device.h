#pragma once


#include <linux/compat.h>
#include <linux/compat64_dlm.h>


struct __c64_dlm_lock_params {
	__u8 mode;
	__u8 namelen;
	__u16 unused;
	__u32 flags;
	__u32 lkid;
	__u32 parent;
	__u64 xid;
	__u64 timeout;
	__c64_uptr castparam;
	__c64_uptr castaddr;
	__c64_uptr bastparam;
	__c64_uptr bastaddr;
	__c64_uptr lksb;
	char lvb[DLM_USER_LVB_LEN];
	char name[];
};

struct __c64_dlm_write_request {
	__u32 version[3];
	__u8 cmd;
	__u8 is64bit;
	__u8 unused[2];

	union  {
		struct __c64_dlm_lock_params   lock;
		struct dlm_lspace_params lspace;
		struct dlm_purge_params  purge;
	} i;
};

struct __c64_dlm_lock_result {
	__u32 version[3];
	__u32 length;
	__c64_uptr user_astaddr;
	__c64_uptr user_astparam;
	__c64_uptr user_lksb;
	struct __c64_dlm_lksb lksb;
	__u8 bast_mode;
	__u8 unused[3];
	/* Offsets may be zero if no data is present */
	__u32 lvb_offset;
};

static __always_inline __maybe_unused void
__from_c64_dlm_lock_result(struct dlm_lock_result *p)
{
	union {
		struct dlm_lock_result native;
		const struct __c64_dlm_lock_result compat;
	} *u = (void *)p;

	u->native.lvb_offset = u->compat.lvb_offset;
	BUILD_BUG_ON(sizeof(u->compat.unused) != sizeof(u->native.unused));
	memmove(&u->native.unused, &u->compat.unused, sizeof(u->native.unused));
	u->native.bast_mode = u->compat.bast_mode;
	u->native.lksb.sb_lvbptr =  compat_ptr(u->compat.lksb.sb_lvbptr);
	u->native.lksb.sb_flags = u->compat.lksb.sb_flags;
	u->native.lksb.sb_lkid = u->compat.lksb.sb_lkid;
	u->native.lksb.sb_status = u->compat.lksb.sb_status;
	u->native.user_lksb =  compat_ptr(u->compat.user_lksb);
	u->native.user_astparam =  compat_ptr(u->compat.user_astparam);
	u->native.user_astaddr =  compat_ptr(u->compat.user_astaddr);
	u->native.length = u->compat.length;
	BUILD_BUG_ON(sizeof(u->compat.version) != sizeof(u->native.version));
	memmove(&u->native.version, &u->compat.version, sizeof(u->native.version));
}
static __always_inline __maybe_unused void
__to_c64_dlm_lock_result(struct dlm_lock_result *p)
{
	union {
		struct __c64_dlm_lock_result compat;
		const struct dlm_lock_result native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.version) != sizeof(u->compat.version));
	memmove(&u->compat.version, &u->native.version, sizeof(u->compat.version));
	u->compat.length = u->native.length;
	u->compat.user_astaddr =  (__c64_uptr __force)(user_uintptr_t)u->native.user_astaddr;
	u->compat.user_astparam =  (__c64_uptr __force)(user_uintptr_t)u->native.user_astparam;
	u->compat.user_lksb =  (__c64_uptr __force)(user_uintptr_t)u->native.user_lksb;
	u->compat.lksb.sb_status = u->native.lksb.sb_status;
	u->compat.lksb.sb_lkid = u->native.lksb.sb_lkid;
	u->compat.lksb.sb_flags = u->native.lksb.sb_flags;
	u->compat.lksb.sb_lvbptr =  (__c64_uptr __force)(user_uintptr_t)u->native.lksb.sb_lvbptr;
	u->compat.bast_mode = u->native.bast_mode;
	BUILD_BUG_ON(sizeof(u->native.unused) != sizeof(u->compat.unused));
	memmove(&u->compat.unused, &u->native.unused, sizeof(u->compat.unused));
	u->compat.lvb_offset = u->native.lvb_offset;
}
static __always_inline __maybe_unused void
__from_c64_dlm_lock_result_2(struct dlm_lock_result *native, const struct __c64_dlm_lock_result *compat)
{

	BUILD_BUG_ON(sizeof(compat->version) != sizeof(native->version));
	memcpy(&native->version, &compat->version, sizeof(native->version));
	native->length = compat->length;
	native->user_astaddr =  compat_ptr(compat->user_astaddr);
	native->user_astparam =  compat_ptr(compat->user_astparam);
	native->user_lksb =  compat_ptr(compat->user_lksb);
	native->lksb.sb_status = compat->lksb.sb_status;
	native->lksb.sb_lkid = compat->lksb.sb_lkid;
	native->lksb.sb_flags = compat->lksb.sb_flags;
	native->lksb.sb_lvbptr =  compat_ptr(compat->lksb.sb_lvbptr);
	native->bast_mode = compat->bast_mode;
	BUILD_BUG_ON(sizeof(compat->unused) != sizeof(native->unused));
	memcpy(&native->unused, &compat->unused, sizeof(native->unused));
	native->lvb_offset = compat->lvb_offset;
}
static __always_inline __maybe_unused void
__to_c64_dlm_lock_result_2(struct __c64_dlm_lock_result *compat, const struct dlm_lock_result *native)
{

	BUILD_BUG_ON(sizeof(native->version) != sizeof(compat->version));
	memcpy(&compat->version, &native->version, sizeof(compat->version));
	compat->length = native->length;
	compat->user_astaddr =  (__c64_uptr __force)(user_uintptr_t)native->user_astaddr;
	compat->user_astparam =  (__c64_uptr __force)(user_uintptr_t)native->user_astparam;
	compat->user_lksb =  (__c64_uptr __force)(user_uintptr_t)native->user_lksb;
	compat->lksb.sb_status = native->lksb.sb_status;
	compat->lksb.sb_lkid = native->lksb.sb_lkid;
	compat->lksb.sb_flags = native->lksb.sb_flags;
	compat->lksb.sb_lvbptr =  (__c64_uptr __force)(user_uintptr_t)native->lksb.sb_lvbptr;
	compat->bast_mode = native->bast_mode;
	BUILD_BUG_ON(sizeof(native->unused) != sizeof(compat->unused));
	memcpy(&compat->unused, &native->unused, sizeof(compat->unused));
	compat->lvb_offset = native->lvb_offset;
}
