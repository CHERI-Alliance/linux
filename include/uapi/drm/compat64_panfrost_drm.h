#pragma once


#include <linux/compat.h>


struct __c64_drm_panfrost_submit {
	/**
	 * @jc: Address to GPU mapping of job descriptor
	 */
	__u64 jc;
	/**
	 * @in_syncs: An optional array of sync objects to wait on
	 * before starting this job.
	 */
	__c64_ptr64 in_syncs;
	/**
	 * @in_sync_count: Number of sync objects to wait on before
	 * starting this job.
	 */
	__u32 in_sync_count;
	/**
	 * @out_sync: An optional sync object to place the completion fence in.
	 */
	__u32 out_sync;
	/**
	 * @bo_handles: Pointer to a u32 array of the BOs that are
	 * referenced by the job.
	 */
	__c64_ptr64 bo_handles;
	/**
	 * @bo_handle_count: Number of BO handles passed in (size is
	 * that times 4).
	 */
	__u32 bo_handle_count;
	/**
	 * @requirements: A combination of PANFROST_JD_REQ_*
	 */
	__u32 requirements;
	/**
	 * @jm_ctx_handle: JM context handle. Zero if you want to use the
	 * default context.
	 */
	__u32 jm_ctx_handle;
	/**
	 * @pad: Padding field. Must be zero.
	 */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_panfrost_submit(struct drm_panfrost_submit *p)
{
	union {
		struct drm_panfrost_submit native;
		const struct __c64_drm_panfrost_submit compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.jm_ctx_handle = u->compat.jm_ctx_handle;
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
	u->compat.jm_ctx_handle = u->native.jm_ctx_handle;
	u->compat.pad = u->native.pad;
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
	native->jm_ctx_handle = compat->jm_ctx_handle;
	native->pad = compat->pad;
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
	compat->jm_ctx_handle = native->jm_ctx_handle;
	compat->pad = native->pad;
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
struct __c64_drm_panfrost_set_label_bo {
	/**
	 * @handle: Handle of the buffer object to label.
	 */
	__u32 handle;
	/**
	 * @pad: Must be zero.
	 */
	__u32 pad;
	/**
	 * @label: User pointer to a NUL-terminated string
	 *
	 * Length cannot be greater than 4096.
	 * NULL is permitted and means clear the label.
	 */
	__c64_ptr64 label;
};

static __always_inline __maybe_unused void
__from_c64_drm_panfrost_set_label_bo(struct drm_panfrost_set_label_bo *p)
{
	union {
		struct drm_panfrost_set_label_bo native;
		const struct __c64_drm_panfrost_set_label_bo compat;
	} *u = (void *)p;

	u->native.label = (user_uintptr_t)compat_ptr(u->compat.label);
	u->native.pad = u->compat.pad;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_set_label_bo(struct drm_panfrost_set_label_bo *p)
{
	union {
		struct __c64_drm_panfrost_set_label_bo compat;
		const struct drm_panfrost_set_label_bo native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat.pad = u->native.pad;
	u->compat.label = (__c64_ptr64 __force)u->native.label;
}
static __always_inline __maybe_unused void
__from_c64_drm_panfrost_set_label_bo_2(struct drm_panfrost_set_label_bo *native, const struct __c64_drm_panfrost_set_label_bo *compat)
{

	native->handle = compat->handle;
	native->pad = compat->pad;
	native->label = (user_uintptr_t)compat_ptr(compat->label);
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_set_label_bo_2(struct __c64_drm_panfrost_set_label_bo *compat, const struct drm_panfrost_set_label_bo *native)
{

	compat->handle = native->handle;
	compat->pad = native->pad;
	compat->label = (__c64_ptr64 __force)native->label;
}
struct __c64_drm_panfrost_sync_bo {
	/** Array of struct drm_panfrost_bo_sync_op */
	__c64_ptr64 ops;

	/** Number of BO sync ops */
	__u32 op_count;

	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_panfrost_sync_bo(struct drm_panfrost_sync_bo *p)
{
	union {
		struct drm_panfrost_sync_bo native;
		const struct __c64_drm_panfrost_sync_bo compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.op_count = u->compat.op_count;
	u->native.ops = (user_uintptr_t)compat_ptr(u->compat.ops);
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_sync_bo(struct drm_panfrost_sync_bo *p)
{
	union {
		struct __c64_drm_panfrost_sync_bo compat;
		const struct drm_panfrost_sync_bo native;
	} *u = (void *)p;

	u->compat.ops = (__c64_ptr64 __force)u->native.ops;
	u->compat.op_count = u->native.op_count;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_panfrost_sync_bo_2(struct drm_panfrost_sync_bo *native, const struct __c64_drm_panfrost_sync_bo *compat)
{

	native->ops = (user_uintptr_t)compat_ptr(compat->ops);
	native->op_count = compat->op_count;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_panfrost_sync_bo_2(struct __c64_drm_panfrost_sync_bo *compat, const struct drm_panfrost_sync_bo *native)
{

	compat->ops = (__c64_ptr64 __force)native->ops;
	compat->op_count = native->op_count;
	compat->pad = native->pad;
}
