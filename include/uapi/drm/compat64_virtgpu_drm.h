#pragma once


#include <linux/compat.h>


struct __c64_drm_virtgpu_execbuffer {
	__u32 flags;
	__u32 size;
	__c64_ptr64 command; /* void* */
	__c64_ptr64 bo_handles;
	__u32 num_bo_handles;
	__s32 fence_fd; /* in/out fence fd (see VIRTGPU_EXECBUF_FENCE_FD_IN/OUT) */
	__u32 ring_idx; /* command ring index (see VIRTGPU_EXECBUF_RING_IDX) */
	__u32 syncobj_stride; /* size of @drm_virtgpu_execbuffer_syncobj */
	__u32 num_in_syncobjs;
	__u32 num_out_syncobjs;
	__c64_ptr64 in_syncobjs;
	__c64_ptr64 out_syncobjs;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_execbuffer(struct drm_virtgpu_execbuffer *p)
{
	union {
		struct drm_virtgpu_execbuffer native;
		const struct __c64_drm_virtgpu_execbuffer compat;
	} *u = (void *)p;

	u->native.out_syncobjs = (user_uintptr_t)compat_ptr(u->compat.out_syncobjs);
	u->native.in_syncobjs = (user_uintptr_t)compat_ptr(u->compat.in_syncobjs);
	u->native.num_out_syncobjs = u->compat.num_out_syncobjs;
	u->native.num_in_syncobjs = u->compat.num_in_syncobjs;
	u->native.syncobj_stride = u->compat.syncobj_stride;
	u->native.ring_idx = u->compat.ring_idx;
	u->native.fence_fd = u->compat.fence_fd;
	u->native.num_bo_handles = u->compat.num_bo_handles;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
	u->native.command = (user_uintptr_t)compat_ptr(u->compat.command);
	u->native.size = u->compat.size;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_execbuffer(struct drm_virtgpu_execbuffer *p)
{
	union {
		struct __c64_drm_virtgpu_execbuffer compat;
		const struct drm_virtgpu_execbuffer native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.size = u->native.size;
	u->compat.command = (__c64_ptr64 __force)u->native.command;
	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.num_bo_handles = u->native.num_bo_handles;
	u->compat.fence_fd = u->native.fence_fd;
	u->compat.ring_idx = u->native.ring_idx;
	u->compat.syncobj_stride = u->native.syncobj_stride;
	u->compat.num_in_syncobjs = u->native.num_in_syncobjs;
	u->compat.num_out_syncobjs = u->native.num_out_syncobjs;
	u->compat.in_syncobjs = (__c64_ptr64 __force)u->native.in_syncobjs;
	u->compat.out_syncobjs = (__c64_ptr64 __force)u->native.out_syncobjs;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_execbuffer_2(struct drm_virtgpu_execbuffer *native, const struct __c64_drm_virtgpu_execbuffer *compat)
{

	native->flags = compat->flags;
	native->size = compat->size;
	native->command = (user_uintptr_t)compat_ptr(compat->command);
	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->num_bo_handles = compat->num_bo_handles;
	native->fence_fd = compat->fence_fd;
	native->ring_idx = compat->ring_idx;
	native->syncobj_stride = compat->syncobj_stride;
	native->num_in_syncobjs = compat->num_in_syncobjs;
	native->num_out_syncobjs = compat->num_out_syncobjs;
	native->in_syncobjs = (user_uintptr_t)compat_ptr(compat->in_syncobjs);
	native->out_syncobjs = (user_uintptr_t)compat_ptr(compat->out_syncobjs);
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_execbuffer_2(struct __c64_drm_virtgpu_execbuffer *compat, const struct drm_virtgpu_execbuffer *native)
{

	compat->flags = native->flags;
	compat->size = native->size;
	compat->command = (__c64_ptr64 __force)native->command;
	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->num_bo_handles = native->num_bo_handles;
	compat->fence_fd = native->fence_fd;
	compat->ring_idx = native->ring_idx;
	compat->syncobj_stride = native->syncobj_stride;
	compat->num_in_syncobjs = native->num_in_syncobjs;
	compat->num_out_syncobjs = native->num_out_syncobjs;
	compat->in_syncobjs = (__c64_ptr64 __force)native->in_syncobjs;
	compat->out_syncobjs = (__c64_ptr64 __force)native->out_syncobjs;
}
struct __c64_drm_virtgpu_getparam {
	__u64 param;
	__c64_ptr64 value;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_getparam(struct drm_virtgpu_getparam *p)
{
	union {
		struct drm_virtgpu_getparam native;
		const struct __c64_drm_virtgpu_getparam compat;
	} *u = (void *)p;

	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.param = u->compat.param;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_getparam(struct drm_virtgpu_getparam *p)
{
	union {
		struct __c64_drm_virtgpu_getparam compat;
		const struct drm_virtgpu_getparam native;
	} *u = (void *)p;

	u->compat.param = u->native.param;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_getparam_2(struct drm_virtgpu_getparam *native, const struct __c64_drm_virtgpu_getparam *compat)
{

	native->param = compat->param;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_getparam_2(struct __c64_drm_virtgpu_getparam *compat, const struct drm_virtgpu_getparam *native)
{

	compat->param = native->param;
	compat->value = (__c64_ptr64 __force)native->value;
}
struct __c64_drm_virtgpu_get_caps {
	__u32 cap_set_id;
	__u32 cap_set_ver;
	__c64_ptr64 addr;
	__u32 size;
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_get_caps(struct drm_virtgpu_get_caps *p)
{
	union {
		struct drm_virtgpu_get_caps native;
		const struct __c64_drm_virtgpu_get_caps compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.size = u->compat.size;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.cap_set_ver = u->compat.cap_set_ver;
	u->native.cap_set_id = u->compat.cap_set_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_get_caps(struct drm_virtgpu_get_caps *p)
{
	union {
		struct __c64_drm_virtgpu_get_caps compat;
		const struct drm_virtgpu_get_caps native;
	} *u = (void *)p;

	u->compat.cap_set_id = u->native.cap_set_id;
	u->compat.cap_set_ver = u->native.cap_set_ver;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.size = u->native.size;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_get_caps_2(struct drm_virtgpu_get_caps *native, const struct __c64_drm_virtgpu_get_caps *compat)
{

	native->cap_set_id = compat->cap_set_id;
	native->cap_set_ver = compat->cap_set_ver;
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->size = compat->size;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_get_caps_2(struct __c64_drm_virtgpu_get_caps *compat, const struct drm_virtgpu_get_caps *native)
{

	compat->cap_set_id = native->cap_set_id;
	compat->cap_set_ver = native->cap_set_ver;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->size = native->size;
	compat->pad = native->pad;
}
struct __c64_drm_virtgpu_resource_create_blob {

	/* zero is invalid blob_mem */
	__u32 blob_mem;
	__u32 blob_flags;
	__u32 bo_handle;
	__u32 res_handle;
	__u64 size;

	/*
	 * for 3D contexts with VIRTGPU_BLOB_MEM_HOST3D_GUEST and
	 * VIRTGPU_BLOB_MEM_HOST3D otherwise, must be zero.
	 */
	__u32 pad;
	__u32 cmd_size;
	__c64_ptr64 cmd;
	__u64 blob_id;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_resource_create_blob(struct drm_virtgpu_resource_create_blob *p)
{
	union {
		struct drm_virtgpu_resource_create_blob native;
		const struct __c64_drm_virtgpu_resource_create_blob compat;
	} *u = (void *)p;

	u->native.blob_id = u->compat.blob_id;
	u->native.cmd = (user_uintptr_t)compat_ptr(u->compat.cmd);
	u->native.cmd_size = u->compat.cmd_size;
	u->native.pad = u->compat.pad;
	u->native.size = u->compat.size;
	u->native.res_handle = u->compat.res_handle;
	u->native.bo_handle = u->compat.bo_handle;
	u->native.blob_flags = u->compat.blob_flags;
	u->native.blob_mem = u->compat.blob_mem;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_resource_create_blob(struct drm_virtgpu_resource_create_blob *p)
{
	union {
		struct __c64_drm_virtgpu_resource_create_blob compat;
		const struct drm_virtgpu_resource_create_blob native;
	} *u = (void *)p;

	u->compat.blob_mem = u->native.blob_mem;
	u->compat.blob_flags = u->native.blob_flags;
	u->compat.bo_handle = u->native.bo_handle;
	u->compat.res_handle = u->native.res_handle;
	u->compat.size = u->native.size;
	u->compat.pad = u->native.pad;
	u->compat.cmd_size = u->native.cmd_size;
	u->compat.cmd = (__c64_ptr64 __force)u->native.cmd;
	u->compat.blob_id = u->native.blob_id;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_resource_create_blob_2(struct drm_virtgpu_resource_create_blob *native, const struct __c64_drm_virtgpu_resource_create_blob *compat)
{

	native->blob_mem = compat->blob_mem;
	native->blob_flags = compat->blob_flags;
	native->bo_handle = compat->bo_handle;
	native->res_handle = compat->res_handle;
	native->size = compat->size;
	native->pad = compat->pad;
	native->cmd_size = compat->cmd_size;
	native->cmd = (user_uintptr_t)compat_ptr(compat->cmd);
	native->blob_id = compat->blob_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_resource_create_blob_2(struct __c64_drm_virtgpu_resource_create_blob *compat, const struct drm_virtgpu_resource_create_blob *native)
{

	compat->blob_mem = native->blob_mem;
	compat->blob_flags = native->blob_flags;
	compat->bo_handle = native->bo_handle;
	compat->res_handle = native->res_handle;
	compat->size = native->size;
	compat->pad = native->pad;
	compat->cmd_size = native->cmd_size;
	compat->cmd = (__c64_ptr64 __force)native->cmd;
	compat->blob_id = native->blob_id;
}
struct __c64_drm_virtgpu_context_set_param {
	__u64 param;
	__c64_ptr64 value;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_context_set_param(struct drm_virtgpu_context_set_param *p)
{
	union {
		struct drm_virtgpu_context_set_param native;
		const struct __c64_drm_virtgpu_context_set_param compat;
	} *u = (void *)p;

	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.param = u->compat.param;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_context_set_param(struct drm_virtgpu_context_set_param *p)
{
	union {
		struct __c64_drm_virtgpu_context_set_param compat;
		const struct drm_virtgpu_context_set_param native;
	} *u = (void *)p;

	u->compat.param = u->native.param;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_context_set_param_2(struct drm_virtgpu_context_set_param *native, const struct __c64_drm_virtgpu_context_set_param *compat)
{

	native->param = compat->param;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_context_set_param_2(struct __c64_drm_virtgpu_context_set_param *compat, const struct drm_virtgpu_context_set_param *native)
{

	compat->param = native->param;
	compat->value = (__c64_ptr64 __force)native->value;
}
struct __c64_drm_virtgpu_context_init {
	__u32 num_params;
	__u32 pad;

	/* pointer to drm_virtgpu_context_set_param array */
	__c64_ptr64 ctx_set_params;
};

static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_context_init(struct drm_virtgpu_context_init *p)
{
	union {
		struct drm_virtgpu_context_init native;
		const struct __c64_drm_virtgpu_context_init compat;
	} *u = (void *)p;

	u->native.ctx_set_params = (user_uintptr_t)compat_ptr(u->compat.ctx_set_params);
	u->native.pad = u->compat.pad;
	u->native.num_params = u->compat.num_params;
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_context_init(struct drm_virtgpu_context_init *p)
{
	union {
		struct __c64_drm_virtgpu_context_init compat;
		const struct drm_virtgpu_context_init native;
	} *u = (void *)p;

	u->compat.num_params = u->native.num_params;
	u->compat.pad = u->native.pad;
	u->compat.ctx_set_params = (__c64_ptr64 __force)u->native.ctx_set_params;
}
static __always_inline __maybe_unused void
__from_c64_drm_virtgpu_context_init_2(struct drm_virtgpu_context_init *native, const struct __c64_drm_virtgpu_context_init *compat)
{

	native->num_params = compat->num_params;
	native->pad = compat->pad;
	native->ctx_set_params = (user_uintptr_t)compat_ptr(compat->ctx_set_params);
}
static __always_inline __maybe_unused void
__to_c64_drm_virtgpu_context_init_2(struct __c64_drm_virtgpu_context_init *compat, const struct drm_virtgpu_context_init *native)
{

	compat->num_params = native->num_params;
	compat->pad = native->pad;
	compat->ctx_set_params = (__c64_ptr64 __force)native->ctx_set_params;
}
