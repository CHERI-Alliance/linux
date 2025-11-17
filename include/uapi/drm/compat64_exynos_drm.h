#pragma once


#include <linux/compat.h>


struct __c64_drm_exynos_g2d_set_cmdlist {
	__c64_ptr64				cmd;
	__c64_ptr64				cmd_buf;
	__u32					cmd_nr;
	__u32					cmd_buf_nr;

	/* for g2d event */
	__u64					event_type;
	__u64					user_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_exynos_g2d_set_cmdlist(struct drm_exynos_g2d_set_cmdlist *p)
{
	union {
		struct drm_exynos_g2d_set_cmdlist native;
		const struct __c64_drm_exynos_g2d_set_cmdlist compat;
	} *u = (void *)p;

	u->native.user_data = u->compat.user_data;
	u->native.event_type = u->compat.event_type;
	u->native.cmd_buf_nr = u->compat.cmd_buf_nr;
	u->native.cmd_nr = u->compat.cmd_nr;
	u->native.cmd_buf = (user_uintptr_t)compat_ptr(u->compat.cmd_buf);
	u->native.cmd = (user_uintptr_t)compat_ptr(u->compat.cmd);
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_g2d_set_cmdlist(struct drm_exynos_g2d_set_cmdlist *p)
{
	union {
		struct __c64_drm_exynos_g2d_set_cmdlist compat;
		const struct drm_exynos_g2d_set_cmdlist native;
	} *u = (void *)p;

	u->compat.cmd = (__c64_ptr64 __force)u->native.cmd;
	u->compat.cmd_buf = (__c64_ptr64 __force)u->native.cmd_buf;
	u->compat.cmd_nr = u->native.cmd_nr;
	u->compat.cmd_buf_nr = u->native.cmd_buf_nr;
	u->compat.event_type = u->native.event_type;
	u->compat.user_data = u->native.user_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_exynos_g2d_set_cmdlist_2(struct drm_exynos_g2d_set_cmdlist *native, const struct __c64_drm_exynos_g2d_set_cmdlist *compat)
{

	native->cmd = (user_uintptr_t)compat_ptr(compat->cmd);
	native->cmd_buf = (user_uintptr_t)compat_ptr(compat->cmd_buf);
	native->cmd_nr = compat->cmd_nr;
	native->cmd_buf_nr = compat->cmd_buf_nr;
	native->event_type = compat->event_type;
	native->user_data = compat->user_data;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_g2d_set_cmdlist_2(struct __c64_drm_exynos_g2d_set_cmdlist *compat, const struct drm_exynos_g2d_set_cmdlist *native)
{

	compat->cmd = (__c64_ptr64 __force)native->cmd;
	compat->cmd_buf = (__c64_ptr64 __force)native->cmd_buf;
	compat->cmd_nr = native->cmd_nr;
	compat->cmd_buf_nr = native->cmd_buf_nr;
	compat->event_type = native->event_type;
	compat->user_data = native->user_data;
}
struct __c64_drm_exynos_ioctl_ipp_get_res {
	__u32 count_ipps;
	__u32 reserved;
	__c64_ptr64 ipp_id_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_res(struct drm_exynos_ioctl_ipp_get_res *p)
{
	union {
		struct drm_exynos_ioctl_ipp_get_res native;
		const struct __c64_drm_exynos_ioctl_ipp_get_res compat;
	} *u = (void *)p;

	u->native.ipp_id_ptr = (user_uintptr_t)compat_ptr(u->compat.ipp_id_ptr);
	u->native.reserved = u->compat.reserved;
	u->native.count_ipps = u->compat.count_ipps;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_res(struct drm_exynos_ioctl_ipp_get_res *p)
{
	union {
		struct __c64_drm_exynos_ioctl_ipp_get_res compat;
		const struct drm_exynos_ioctl_ipp_get_res native;
	} *u = (void *)p;

	u->compat.count_ipps = u->native.count_ipps;
	u->compat.reserved = u->native.reserved;
	u->compat.ipp_id_ptr = (__c64_ptr64 __force)u->native.ipp_id_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_res_2(struct drm_exynos_ioctl_ipp_get_res *native, const struct __c64_drm_exynos_ioctl_ipp_get_res *compat)
{

	native->count_ipps = compat->count_ipps;
	native->reserved = compat->reserved;
	native->ipp_id_ptr = (user_uintptr_t)compat_ptr(compat->ipp_id_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_res_2(struct __c64_drm_exynos_ioctl_ipp_get_res *compat, const struct drm_exynos_ioctl_ipp_get_res *native)
{

	compat->count_ipps = native->count_ipps;
	compat->reserved = native->reserved;
	compat->ipp_id_ptr = (__c64_ptr64 __force)native->ipp_id_ptr;
}
struct __c64_drm_exynos_ioctl_ipp_get_caps {
	__u32 ipp_id;
	__u32 capabilities;
	__u32 reserved;
	__u32 formats_count;
	__c64_ptr64 formats_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_caps(struct drm_exynos_ioctl_ipp_get_caps *p)
{
	union {
		struct drm_exynos_ioctl_ipp_get_caps native;
		const struct __c64_drm_exynos_ioctl_ipp_get_caps compat;
	} *u = (void *)p;

	u->native.formats_ptr = (user_uintptr_t)compat_ptr(u->compat.formats_ptr);
	u->native.formats_count = u->compat.formats_count;
	u->native.reserved = u->compat.reserved;
	u->native.capabilities = u->compat.capabilities;
	u->native.ipp_id = u->compat.ipp_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_caps(struct drm_exynos_ioctl_ipp_get_caps *p)
{
	union {
		struct __c64_drm_exynos_ioctl_ipp_get_caps compat;
		const struct drm_exynos_ioctl_ipp_get_caps native;
	} *u = (void *)p;

	u->compat.ipp_id = u->native.ipp_id;
	u->compat.capabilities = u->native.capabilities;
	u->compat.reserved = u->native.reserved;
	u->compat.formats_count = u->native.formats_count;
	u->compat.formats_ptr = (__c64_ptr64 __force)u->native.formats_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_caps_2(struct drm_exynos_ioctl_ipp_get_caps *native, const struct __c64_drm_exynos_ioctl_ipp_get_caps *compat)
{

	native->ipp_id = compat->ipp_id;
	native->capabilities = compat->capabilities;
	native->reserved = compat->reserved;
	native->formats_count = compat->formats_count;
	native->formats_ptr = (user_uintptr_t)compat_ptr(compat->formats_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_caps_2(struct __c64_drm_exynos_ioctl_ipp_get_caps *compat, const struct drm_exynos_ioctl_ipp_get_caps *native)
{

	compat->ipp_id = native->ipp_id;
	compat->capabilities = native->capabilities;
	compat->reserved = native->reserved;
	compat->formats_count = native->formats_count;
	compat->formats_ptr = (__c64_ptr64 __force)native->formats_ptr;
}
struct __c64_drm_exynos_ioctl_ipp_get_limits {
	__u32 ipp_id;
	__u32 fourcc;
	__u64 modifier;
	__u32 type;
	__u32 limits_count;
	__c64_ptr64 limits_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_limits(struct drm_exynos_ioctl_ipp_get_limits *p)
{
	union {
		struct drm_exynos_ioctl_ipp_get_limits native;
		const struct __c64_drm_exynos_ioctl_ipp_get_limits compat;
	} *u = (void *)p;

	u->native.limits_ptr = (user_uintptr_t)compat_ptr(u->compat.limits_ptr);
	u->native.limits_count = u->compat.limits_count;
	u->native.type = u->compat.type;
	u->native.modifier = u->compat.modifier;
	u->native.fourcc = u->compat.fourcc;
	u->native.ipp_id = u->compat.ipp_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_limits(struct drm_exynos_ioctl_ipp_get_limits *p)
{
	union {
		struct __c64_drm_exynos_ioctl_ipp_get_limits compat;
		const struct drm_exynos_ioctl_ipp_get_limits native;
	} *u = (void *)p;

	u->compat.ipp_id = u->native.ipp_id;
	u->compat.fourcc = u->native.fourcc;
	u->compat.modifier = u->native.modifier;
	u->compat.type = u->native.type;
	u->compat.limits_count = u->native.limits_count;
	u->compat.limits_ptr = (__c64_ptr64 __force)u->native.limits_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_get_limits_2(struct drm_exynos_ioctl_ipp_get_limits *native, const struct __c64_drm_exynos_ioctl_ipp_get_limits *compat)
{

	native->ipp_id = compat->ipp_id;
	native->fourcc = compat->fourcc;
	native->modifier = compat->modifier;
	native->type = compat->type;
	native->limits_count = compat->limits_count;
	native->limits_ptr = (user_uintptr_t)compat_ptr(compat->limits_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_get_limits_2(struct __c64_drm_exynos_ioctl_ipp_get_limits *compat, const struct drm_exynos_ioctl_ipp_get_limits *native)
{

	compat->ipp_id = native->ipp_id;
	compat->fourcc = native->fourcc;
	compat->modifier = native->modifier;
	compat->type = native->type;
	compat->limits_count = native->limits_count;
	compat->limits_ptr = (__c64_ptr64 __force)native->limits_ptr;
}
struct __c64_drm_exynos_ioctl_ipp_commit {
	__u32 ipp_id;
	__u32 flags;
	__u32 reserved;
	__u32 params_size;
	__c64_ptr64 params_ptr;
	__u64 user_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_commit(struct drm_exynos_ioctl_ipp_commit *p)
{
	union {
		struct drm_exynos_ioctl_ipp_commit native;
		const struct __c64_drm_exynos_ioctl_ipp_commit compat;
	} *u = (void *)p;

	u->native.user_data = u->compat.user_data;
	u->native.params_ptr = (user_uintptr_t)compat_ptr(u->compat.params_ptr);
	u->native.params_size = u->compat.params_size;
	u->native.reserved = u->compat.reserved;
	u->native.flags = u->compat.flags;
	u->native.ipp_id = u->compat.ipp_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_commit(struct drm_exynos_ioctl_ipp_commit *p)
{
	union {
		struct __c64_drm_exynos_ioctl_ipp_commit compat;
		const struct drm_exynos_ioctl_ipp_commit native;
	} *u = (void *)p;

	u->compat.ipp_id = u->native.ipp_id;
	u->compat.flags = u->native.flags;
	u->compat.reserved = u->native.reserved;
	u->compat.params_size = u->native.params_size;
	u->compat.params_ptr = (__c64_ptr64 __force)u->native.params_ptr;
	u->compat.user_data = u->native.user_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_exynos_ioctl_ipp_commit_2(struct drm_exynos_ioctl_ipp_commit *native, const struct __c64_drm_exynos_ioctl_ipp_commit *compat)
{

	native->ipp_id = compat->ipp_id;
	native->flags = compat->flags;
	native->reserved = compat->reserved;
	native->params_size = compat->params_size;
	native->params_ptr = (user_uintptr_t)compat_ptr(compat->params_ptr);
	native->user_data = compat->user_data;
}
static __always_inline __maybe_unused void
__to_c64_drm_exynos_ioctl_ipp_commit_2(struct __c64_drm_exynos_ioctl_ipp_commit *compat, const struct drm_exynos_ioctl_ipp_commit *native)
{

	compat->ipp_id = native->ipp_id;
	compat->flags = native->flags;
	compat->reserved = native->reserved;
	compat->params_size = native->params_size;
	compat->params_ptr = (__c64_ptr64 __force)native->params_ptr;
	compat->user_data = native->user_data;
}
