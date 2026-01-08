#pragma once


#include <linux/compat.h>


struct __c64_sync_file_info {
	char	name[32];
	__s32	status;
	__u32	flags;
	__u32	num_fences;
	__u32	pad;

	__c64_ptr64	sync_fence_info;
};

static __always_inline __maybe_unused void
__from_c64_sync_file_info(struct sync_file_info *p)
{
	union {
		struct sync_file_info native;
		const struct __c64_sync_file_info compat;
	} *u = (void *)p;

	u->native.sync_fence_info = (user_uintptr_t)compat_ptr(u->compat.sync_fence_info);
	u->native.pad = u->compat.pad;
	u->native.num_fences = u->compat.num_fences;
	u->native.flags = u->compat.flags;
	u->native.status = u->compat.status;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_sync_file_info(struct sync_file_info *p)
{
	union {
		struct __c64_sync_file_info compat;
		const struct sync_file_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.status = u->native.status;
	u->compat.flags = u->native.flags;
	u->compat.num_fences = u->native.num_fences;
	u->compat.pad = u->native.pad;
	u->compat.sync_fence_info = (__c64_ptr64 __force)u->native.sync_fence_info;
}
static __always_inline __maybe_unused void
__from_c64_sync_file_info_2(struct sync_file_info *native, const struct __c64_sync_file_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->status = compat->status;
	native->flags = compat->flags;
	native->num_fences = compat->num_fences;
	native->pad = compat->pad;
	native->sync_fence_info = (user_uintptr_t)compat_ptr(compat->sync_fence_info);
}
static __always_inline __maybe_unused void
__to_c64_sync_file_info_2(struct __c64_sync_file_info *compat, const struct sync_file_info *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->status = native->status;
	compat->flags = native->flags;
	compat->num_fences = native->num_fences;
	compat->pad = native->pad;
	compat->sync_fence_info = (__c64_ptr64 __force)native->sync_fence_info;
}
