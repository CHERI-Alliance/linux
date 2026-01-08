#pragma once


#include <linux/compat.h>


struct __c64_dlm_lksb {
	int 	 sb_status;
	__u32	 sb_lkid;
	char 	 sb_flags;
	__c64_uptr	 sb_lvbptr;
};

static __always_inline __maybe_unused void
__from_c64_dlm_lksb(struct dlm_lksb *p)
{
	union {
		struct dlm_lksb native;
		const struct __c64_dlm_lksb compat;
	} *u = (void *)p;

	u->native.sb_lvbptr =  compat_ptr(u->compat.sb_lvbptr);
	u->native.sb_flags = u->compat.sb_flags;
	u->native.sb_lkid = u->compat.sb_lkid;
	u->native.sb_status = u->compat.sb_status;
}
static __always_inline __maybe_unused void
__to_c64_dlm_lksb(struct dlm_lksb *p)
{
	union {
		struct __c64_dlm_lksb compat;
		const struct dlm_lksb native;
	} *u = (void *)p;

	u->compat.sb_status = u->native.sb_status;
	u->compat.sb_lkid = u->native.sb_lkid;
	u->compat.sb_flags = u->native.sb_flags;
	u->compat.sb_lvbptr =  (__c64_uptr __force)(user_uintptr_t)u->native.sb_lvbptr;
}
static __always_inline __maybe_unused void
__from_c64_dlm_lksb_2(struct dlm_lksb *native, const struct __c64_dlm_lksb *compat)
{

	native->sb_status = compat->sb_status;
	native->sb_lkid = compat->sb_lkid;
	native->sb_flags = compat->sb_flags;
	native->sb_lvbptr =  compat_ptr(compat->sb_lvbptr);
}
static __always_inline __maybe_unused void
__to_c64_dlm_lksb_2(struct __c64_dlm_lksb *compat, const struct dlm_lksb *native)
{

	compat->sb_status = native->sb_status;
	compat->sb_lkid = native->sb_lkid;
	compat->sb_flags = native->sb_flags;
	compat->sb_lvbptr =  (__c64_uptr __force)(user_uintptr_t)native->sb_lvbptr;
}
