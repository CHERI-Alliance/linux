#pragma once


#include <linux/compat.h>


struct __c64_video_still_picture {
	__c64_uptr iFrame;        /* pointer to a single iframe in memory */
	__s32 size;
};

static __always_inline __maybe_unused void
__from_c64_video_still_picture(struct video_still_picture *p)
{
	union {
		struct video_still_picture native;
		const struct __c64_video_still_picture compat;
	} *u = (void *)p;

	u->native.size = u->compat.size;
	u->native.iFrame =  compat_ptr(u->compat.iFrame);
}
static __always_inline __maybe_unused void
__to_c64_video_still_picture(struct video_still_picture *p)
{
	union {
		struct __c64_video_still_picture compat;
		const struct video_still_picture native;
	} *u = (void *)p;

	u->compat.iFrame =  (__c64_uptr __force)(user_uintptr_t)u->native.iFrame;
	u->compat.size = u->native.size;
}
static __always_inline __maybe_unused void
__from_c64_video_still_picture_2(struct video_still_picture *native, const struct __c64_video_still_picture *compat)
{

	native->iFrame =  compat_ptr(compat->iFrame);
	native->size = compat->size;
}
static __always_inline __maybe_unused void
__to_c64_video_still_picture_2(struct __c64_video_still_picture *compat, const struct video_still_picture *native)
{

	compat->iFrame =  (__c64_uptr __force)(user_uintptr_t)native->iFrame;
	compat->size = native->size;
}
