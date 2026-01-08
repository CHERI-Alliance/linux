#pragma once


#include <linux/compat.h>


struct __c64_xt_cgroup_info_v1 {
	__u8		has_path;
	__u8		has_classid;
	__u8		invert_path;
	__u8		invert_classid;
	char		path[PATH_MAX];
	__u32		classid;

	/* kernel internal data */
	__c64_uptr priv __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_cgroup_info_v1(struct xt_cgroup_info_v1 *p)
{
	union {
		struct xt_cgroup_info_v1 native;
		const struct __c64_xt_cgroup_info_v1 compat;
	} *u = (void *)p;

	u->native.priv =  compat_ptr(u->compat.priv);
	u->native.classid = u->compat.classid;
	BUILD_BUG_ON(sizeof(u->compat.path) != sizeof(u->native.path));
	memmove(&u->native.path, &u->compat.path, sizeof(u->native.path));
	u->native.invert_classid = u->compat.invert_classid;
	u->native.invert_path = u->compat.invert_path;
	u->native.has_classid = u->compat.has_classid;
	u->native.has_path = u->compat.has_path;
}
static __always_inline __maybe_unused void
__to_c64_xt_cgroup_info_v1(struct xt_cgroup_info_v1 *p)
{
	union {
		struct __c64_xt_cgroup_info_v1 compat;
		const struct xt_cgroup_info_v1 native;
	} *u = (void *)p;

	u->compat.has_path = u->native.has_path;
	u->compat.has_classid = u->native.has_classid;
	u->compat.invert_path = u->native.invert_path;
	u->compat.invert_classid = u->native.invert_classid;
	BUILD_BUG_ON(sizeof(u->native.path) != sizeof(u->compat.path));
	memmove(&u->compat.path, &u->native.path, sizeof(u->compat.path));
	u->compat.classid = u->native.classid;
	u->compat.priv =  (__c64_uptr __force)(user_uintptr_t)u->native.priv;
}
static __always_inline __maybe_unused void
__from_c64_xt_cgroup_info_v1_2(struct xt_cgroup_info_v1 *native, const struct __c64_xt_cgroup_info_v1 *compat)
{

	native->has_path = compat->has_path;
	native->has_classid = compat->has_classid;
	native->invert_path = compat->invert_path;
	native->invert_classid = compat->invert_classid;
	BUILD_BUG_ON(sizeof(compat->path) != sizeof(native->path));
	memcpy(&native->path, &compat->path, sizeof(native->path));
	native->classid = compat->classid;
	native->priv =  compat_ptr(compat->priv);
}
static __always_inline __maybe_unused void
__to_c64_xt_cgroup_info_v1_2(struct __c64_xt_cgroup_info_v1 *compat, const struct xt_cgroup_info_v1 *native)
{

	compat->has_path = native->has_path;
	compat->has_classid = native->has_classid;
	compat->invert_path = native->invert_path;
	compat->invert_classid = native->invert_classid;
	BUILD_BUG_ON(sizeof(native->path) != sizeof(compat->path));
	memcpy(&compat->path, &native->path, sizeof(compat->path));
	compat->classid = native->classid;
	compat->priv =  (__c64_uptr __force)(user_uintptr_t)native->priv;
}
struct __c64_xt_cgroup_info_v2 {
	__u8		has_path;
	__u8		has_classid;
	__u8		invert_path;
	__u8		invert_classid;
	union {
		char	path[XT_CGROUP_PATH_MAX];
		__u32	classid;
	};

	/* kernel internal data */
	__c64_uptr priv __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_cgroup_info_v2(struct xt_cgroup_info_v2 *p)
{
	union {
		struct xt_cgroup_info_v2 native;
		const struct __c64_xt_cgroup_info_v2 compat;
	} *u = (void *)p;

	u->native.priv =  compat_ptr(u->compat.priv);
	u->native.classid = u->compat.classid;
	BUILD_BUG_ON(sizeof(u->compat.path) != sizeof(u->native.path));
	memmove(&u->native.path, &u->compat.path, sizeof(u->native.path));
	u->native.invert_classid = u->compat.invert_classid;
	u->native.invert_path = u->compat.invert_path;
	u->native.has_classid = u->compat.has_classid;
	u->native.has_path = u->compat.has_path;
}
static __always_inline __maybe_unused void
__to_c64_xt_cgroup_info_v2(struct xt_cgroup_info_v2 *p)
{
	union {
		struct __c64_xt_cgroup_info_v2 compat;
		const struct xt_cgroup_info_v2 native;
	} *u = (void *)p;

	u->compat.has_path = u->native.has_path;
	u->compat.has_classid = u->native.has_classid;
	u->compat.invert_path = u->native.invert_path;
	u->compat.invert_classid = u->native.invert_classid;
	BUILD_BUG_ON(sizeof(u->native.path) != sizeof(u->compat.path));
	memmove(&u->compat.path, &u->native.path, sizeof(u->compat.path));
	u->compat.classid = u->native.classid;
	u->compat.priv =  (__c64_uptr __force)(user_uintptr_t)u->native.priv;
}
static __always_inline __maybe_unused void
__from_c64_xt_cgroup_info_v2_2(struct xt_cgroup_info_v2 *native, const struct __c64_xt_cgroup_info_v2 *compat)
{

	native->has_path = compat->has_path;
	native->has_classid = compat->has_classid;
	native->invert_path = compat->invert_path;
	native->invert_classid = compat->invert_classid;
	BUILD_BUG_ON(sizeof(compat->path) != sizeof(native->path));
	memcpy(&native->path, &compat->path, sizeof(native->path));
	native->classid = compat->classid;
	native->priv =  compat_ptr(compat->priv);
}
static __always_inline __maybe_unused void
__to_c64_xt_cgroup_info_v2_2(struct __c64_xt_cgroup_info_v2 *compat, const struct xt_cgroup_info_v2 *native)
{

	compat->has_path = native->has_path;
	compat->has_classid = native->has_classid;
	compat->invert_path = native->invert_path;
	compat->invert_classid = native->invert_classid;
	BUILD_BUG_ON(sizeof(native->path) != sizeof(compat->path));
	memcpy(&compat->path, &native->path, sizeof(compat->path));
	compat->classid = native->classid;
	compat->priv =  (__c64_uptr __force)(user_uintptr_t)native->priv;
}
