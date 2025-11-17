#pragma once


#include <linux/compat.h>


struct __c64_drm_panfrost_submit {

	/** Address to GPU mapping of job descriptor */
	__u64 jc;

	/** An optional array of sync objects to wait on before starting this job. */
	__c64_ptr64 in_syncs;

	/** Number of sync objects to wait on before starting this job. */
	__u32 in_sync_count;

	/** An optional sync object to place the completion fence in. */
	__u32 out_sync;

	/** Pointer to a u32 array of the BOs that are referenced by the job. */
	__c64_ptr64 bo_handles;

	/** Number of BO handles passed in (size is that times 4). */
	__u32 bo_handle_count;

	/** A combination of PANFROST_JD_REQ_* */
	__u32 requirements;
};

static __always_inline __maybe_unused void
__from_c64_drm_panfrost_submit(struct drm_panfrost_submit *p)
{
	union {
		struct drm_panfrost_submit native;
		const struct __c64_drm_panfrost_submit compat;
	} *u = (void *)p;

	u->native.requirements = u->compat.requirements;
	u->native.bo_handle_count = u->compat.bo_handle_count;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
	u->native.out_sync = u->compat.out_sync;
	u->native.in_sync_count = u->compat.in_sync_count;
	u->native.in_syncs = (user_uintptr_t)compat_ptr(u->compat.in_syncs);
	u->native.jc = u->compat.jc;
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_submit(struct drm_panfrost_submit *p)
{
	union {
		struct __c64_drm_panfrost_submit compat;
		const struct drm_panfrost_submit native;
	} *u = (void *)p;

	u->compat.jc = u->native.jc;
	u->compat.in_syncs = (__c64_ptr64 __force)u->native.in_syncs;
	u->compat.in_sync_count = u->native.in_sync_count;
	u->compat.out_sync = u->native.out_sync;
	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.bo_handle_count = u->native.bo_handle_count;
	u->compat.requirements = u->native.requirements;
}
static __always_inline __maybe_unused void
__from_c64_drm_panfrost_submit_2(struct drm_panfrost_submit *native, const struct __c64_drm_panfrost_submit *compat)
{

	native->jc = compat->jc;
	native->in_syncs = (user_uintptr_t)compat_ptr(compat->in_syncs);
	native->in_sync_count = compat->in_sync_count;
	native->out_sync = compat->out_sync;
	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->bo_handle_count = compat->bo_handle_count;
	native->requirements = compat->requirements;
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_submit_2(struct __c64_drm_panfrost_submit *compat, const struct drm_panfrost_submit *native)
{

	compat->jc = native->jc;
	compat->in_syncs = (__c64_ptr64 __force)native->in_syncs;
	compat->in_sync_count = native->in_sync_count;
	compat->out_sync = native->out_sync;
	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->bo_handle_count = native->bo_handle_count;
	compat->requirements = native->requirements;
}
struct __c64_drm_panfrost_perfcnt_dump {
	__c64_ptr64 buf_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_panfrost_perfcnt_dump(struct drm_panfrost_perfcnt_dump *p)
{
	union {
		struct drm_panfrost_perfcnt_dump native;
		const struct __c64_drm_panfrost_perfcnt_dump compat;
	} *u = (void *)p;

	u->native.buf_ptr = (user_uintptr_t)compat_ptr(u->compat.buf_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_perfcnt_dump(struct drm_panfrost_perfcnt_dump *p)
{
	union {
		struct __c64_drm_panfrost_perfcnt_dump compat;
		const struct drm_panfrost_perfcnt_dump native;
	} *u = (void *)p;

	u->compat.buf_ptr = (__c64_ptr64 __force)u->native.buf_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_panfrost_perfcnt_dump_2(struct drm_panfrost_perfcnt_dump *native, const struct __c64_drm_panfrost_perfcnt_dump *compat)
{

	native->buf_ptr = (user_uintptr_t)compat_ptr(compat->buf_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_perfcnt_dump_2(struct __c64_drm_panfrost_perfcnt_dump *compat, const struct drm_panfrost_perfcnt_dump *native)
{

	compat->buf_ptr = (__c64_ptr64 __force)native->buf_ptr;
}
