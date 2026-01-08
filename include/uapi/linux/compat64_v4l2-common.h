#pragma once


#include <linux/compat.h>


struct __c64_v4l2_edid {
	__u32 pad;
	__u32 start_block;
	__u32 blocks;
	__u32 reserved[5];
	__c64_uptr edid;
};

static __always_inline __maybe_unused void
__from_c64_v4l2_edid(struct v4l2_edid *p)
{
	union {
		struct v4l2_edid native;
		const struct __c64_v4l2_edid compat;
	} *u = (void *)p;

	u->native.edid =  compat_ptr(u->compat.edid);
	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.blocks = u->compat.blocks;
	u->native.start_block = u->compat.start_block;
	u->native.pad = u->compat.pad;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_edid(struct v4l2_edid *p)
{
	union {
		struct __c64_v4l2_edid compat;
		const struct v4l2_edid native;
	} *u = (void *)p;

	u->compat.pad = u->native.pad;
	u->compat.start_block = u->native.start_block;
	u->compat.blocks = u->native.blocks;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
	u->compat.edid =  (__c64_uptr __force)(user_uintptr_t)u->native.edid;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_edid_2(struct v4l2_edid *native, const struct __c64_v4l2_edid *compat)
{

	native->pad = compat->pad;
	native->start_block = compat->start_block;
	native->blocks = compat->blocks;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
	native->edid =  compat_ptr(compat->edid);
}
static __always_inline __maybe_unused void
__to_c64_v4l2_edid_2(struct __c64_v4l2_edid *compat, const struct v4l2_edid *native)
{

	compat->pad = native->pad;
	compat->start_block = native->start_block;
	compat->blocks = native->blocks;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
	compat->edid =  (__c64_uptr __force)(user_uintptr_t)native->edid;
}
