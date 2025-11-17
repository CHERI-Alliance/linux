#pragma once


#include <linux/compat.h>


struct __c64_drm_msm_param {
	__u32 pipe;           /* in, MSM_PIPE_x */
	__u32 param;          /* in, MSM_PARAM_x */
	__c64_ptr64 value;          /* out (get_param) or in (set_param) */
	__u32 len;            /* zero for non-pointer params */
	__u32 pad;            /* must be zero */
};

static __always_inline __maybe_unused void
__from_c64_drm_msm_param(struct drm_msm_param *p)
{
	union {
		struct drm_msm_param native;
		const struct __c64_drm_msm_param compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.len = u->compat.len;
	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.param = u->compat.param;
	u->native.pipe = u->compat.pipe;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_param(struct drm_msm_param *p)
{
	union {
		struct __c64_drm_msm_param compat;
		const struct drm_msm_param native;
	} *u = (void *)p;

	u->compat.pipe = u->native.pipe;
	u->compat.param = u->native.param;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
	u->compat.len = u->native.len;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_msm_param_2(struct drm_msm_param *native, const struct __c64_drm_msm_param *compat)
{

	native->pipe = compat->pipe;
	native->param = compat->param;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
	native->len = compat->len;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_param_2(struct __c64_drm_msm_param *compat, const struct drm_msm_param *native)
{

	compat->pipe = native->pipe;
	compat->param = native->param;
	compat->value = (__c64_ptr64 __force)native->value;
	compat->len = native->len;
	compat->pad = native->pad;
}
struct __c64_drm_msm_gem_info {
	__u32 handle;         /* in */
	__u32 info;           /* in - one of MSM_INFO_* */
	__c64_ptr64 value;          /* in or out */
	__u32 len;            /* in or out */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_info(struct drm_msm_gem_info *p)
{
	union {
		struct drm_msm_gem_info native;
		const struct __c64_drm_msm_gem_info compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.len = u->compat.len;
	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.info = u->compat.info;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_info(struct drm_msm_gem_info *p)
{
	union {
		struct __c64_drm_msm_gem_info compat;
		const struct drm_msm_gem_info native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat.info = u->native.info;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
	u->compat.len = u->native.len;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_info_2(struct drm_msm_gem_info *native, const struct __c64_drm_msm_gem_info *compat)
{

	native->handle = compat->handle;
	native->info = compat->info;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
	native->len = compat->len;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_info_2(struct __c64_drm_msm_gem_info *compat, const struct drm_msm_gem_info *native)
{

	compat->handle = native->handle;
	compat->info = native->info;
	compat->value = (__c64_ptr64 __force)native->value;
	compat->len = native->len;
	compat->pad = native->pad;
}
struct __c64_drm_msm_gem_submit_cmd {
	__u32 type;           /* in, one of MSM_SUBMIT_CMD_x */
	__u32 submit_idx;     /* in, index of submit_bo cmdstream buffer */
	__u32 submit_offset;  /* in, offset into submit_bo */
	__u32 size;           /* in, cmdstream size */
	__u32 pad;
	__u32 nr_relocs;      /* in, number of submit_reloc's */
	__c64_ptr64 relocs;         /* in, ptr to array of submit_reloc's */
};

static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_submit_cmd(struct drm_msm_gem_submit_cmd *p)
{
	union {
		struct drm_msm_gem_submit_cmd native;
		const struct __c64_drm_msm_gem_submit_cmd compat;
	} *u = (void *)p;

	u->native.relocs = (user_uintptr_t)compat_ptr(u->compat.relocs);
	u->native.nr_relocs = u->compat.nr_relocs;
	u->native.pad = u->compat.pad;
	u->native.size = u->compat.size;
	u->native.submit_offset = u->compat.submit_offset;
	u->native.submit_idx = u->compat.submit_idx;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_submit_cmd(struct drm_msm_gem_submit_cmd *p)
{
	union {
		struct __c64_drm_msm_gem_submit_cmd compat;
		const struct drm_msm_gem_submit_cmd native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.submit_idx = u->native.submit_idx;
	u->compat.submit_offset = u->native.submit_offset;
	u->compat.size = u->native.size;
	u->compat.pad = u->native.pad;
	u->compat.nr_relocs = u->native.nr_relocs;
	u->compat.relocs = (__c64_ptr64 __force)u->native.relocs;
}
static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_submit_cmd_2(struct drm_msm_gem_submit_cmd *native, const struct __c64_drm_msm_gem_submit_cmd *compat)
{

	native->type = compat->type;
	native->submit_idx = compat->submit_idx;
	native->submit_offset = compat->submit_offset;
	native->size = compat->size;
	native->pad = compat->pad;
	native->nr_relocs = compat->nr_relocs;
	native->relocs = (user_uintptr_t)compat_ptr(compat->relocs);
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_submit_cmd_2(struct __c64_drm_msm_gem_submit_cmd *compat, const struct drm_msm_gem_submit_cmd *native)
{

	compat->type = native->type;
	compat->submit_idx = native->submit_idx;
	compat->submit_offset = native->submit_offset;
	compat->size = native->size;
	compat->pad = native->pad;
	compat->nr_relocs = native->nr_relocs;
	compat->relocs = (__c64_ptr64 __force)native->relocs;
}
struct __c64_drm_msm_gem_submit {
	__u32 flags;          /* MSM_PIPE_x | MSM_SUBMIT_x */
	__u32 fence;          /* out (or in with MSM_SUBMIT_FENCE_SN_IN flag) */
	__u32 nr_bos;         /* in, number of submit_bo's */
	__u32 nr_cmds;        /* in, number of submit_cmd's */
	__c64_ptr64 bos;            /* in, ptr to array of submit_bo's */
	__c64_ptr64 cmds;           /* in, ptr to array of submit_cmd's */
	__s32 fence_fd;       /* in/out fence fd (see MSM_SUBMIT_FENCE_FD_IN/OUT) */
	__u32 queueid;        /* in, submitqueue id */
	__c64_ptr64 in_syncobjs;    /* in, ptr to array of drm_msm_gem_submit_syncobj */
	__c64_ptr64 out_syncobjs;   /* in, ptr to array of drm_msm_gem_submit_syncobj */
	__u32 nr_in_syncobjs; /* in, number of entries in in_syncobj */
	__u32 nr_out_syncobjs; /* in, number of entries in out_syncobj. */
	__u32 syncobj_stride; /* in, stride of syncobj arrays. */
	__u32 pad;            /*in, reserved for future use, always 0. */

};

static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_submit(struct drm_msm_gem_submit *p)
{
	union {
		struct drm_msm_gem_submit native;
		const struct __c64_drm_msm_gem_submit compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.syncobj_stride = u->compat.syncobj_stride;
	u->native.nr_out_syncobjs = u->compat.nr_out_syncobjs;
	u->native.nr_in_syncobjs = u->compat.nr_in_syncobjs;
	u->native.out_syncobjs = (user_uintptr_t)compat_ptr(u->compat.out_syncobjs);
	u->native.in_syncobjs = (user_uintptr_t)compat_ptr(u->compat.in_syncobjs);
	u->native.queueid = u->compat.queueid;
	u->native.fence_fd = u->compat.fence_fd;
	u->native.cmds = (user_uintptr_t)compat_ptr(u->compat.cmds);
	u->native.bos = (user_uintptr_t)compat_ptr(u->compat.bos);
	u->native.nr_cmds = u->compat.nr_cmds;
	u->native.nr_bos = u->compat.nr_bos;
	u->native.fence = u->compat.fence;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_submit(struct drm_msm_gem_submit *p)
{
	union {
		struct __c64_drm_msm_gem_submit compat;
		const struct drm_msm_gem_submit native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.fence = u->native.fence;
	u->compat.nr_bos = u->native.nr_bos;
	u->compat.nr_cmds = u->native.nr_cmds;
	u->compat.bos = (__c64_ptr64 __force)u->native.bos;
	u->compat.cmds = (__c64_ptr64 __force)u->native.cmds;
	u->compat.fence_fd = u->native.fence_fd;
	u->compat.queueid = u->native.queueid;
	u->compat.in_syncobjs = (__c64_ptr64 __force)u->native.in_syncobjs;
	u->compat.out_syncobjs = (__c64_ptr64 __force)u->native.out_syncobjs;
	u->compat.nr_in_syncobjs = u->native.nr_in_syncobjs;
	u->compat.nr_out_syncobjs = u->native.nr_out_syncobjs;
	u->compat.syncobj_stride = u->native.syncobj_stride;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_msm_gem_submit_2(struct drm_msm_gem_submit *native, const struct __c64_drm_msm_gem_submit *compat)
{

	native->flags = compat->flags;
	native->fence = compat->fence;
	native->nr_bos = compat->nr_bos;
	native->nr_cmds = compat->nr_cmds;
	native->bos = (user_uintptr_t)compat_ptr(compat->bos);
	native->cmds = (user_uintptr_t)compat_ptr(compat->cmds);
	native->fence_fd = compat->fence_fd;
	native->queueid = compat->queueid;
	native->in_syncobjs = (user_uintptr_t)compat_ptr(compat->in_syncobjs);
	native->out_syncobjs = (user_uintptr_t)compat_ptr(compat->out_syncobjs);
	native->nr_in_syncobjs = compat->nr_in_syncobjs;
	native->nr_out_syncobjs = compat->nr_out_syncobjs;
	native->syncobj_stride = compat->syncobj_stride;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_gem_submit_2(struct __c64_drm_msm_gem_submit *compat, const struct drm_msm_gem_submit *native)
{

	compat->flags = native->flags;
	compat->fence = native->fence;
	compat->nr_bos = native->nr_bos;
	compat->nr_cmds = native->nr_cmds;
	compat->bos = (__c64_ptr64 __force)native->bos;
	compat->cmds = (__c64_ptr64 __force)native->cmds;
	compat->fence_fd = native->fence_fd;
	compat->queueid = native->queueid;
	compat->in_syncobjs = (__c64_ptr64 __force)native->in_syncobjs;
	compat->out_syncobjs = (__c64_ptr64 __force)native->out_syncobjs;
	compat->nr_in_syncobjs = native->nr_in_syncobjs;
	compat->nr_out_syncobjs = native->nr_out_syncobjs;
	compat->syncobj_stride = native->syncobj_stride;
	compat->pad = native->pad;
}
struct __c64_drm_msm_submitqueue_query {
	__c64_ptr64 data;
	__u32 id;
	__u32 param;
	__u32 len;
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_msm_submitqueue_query(struct drm_msm_submitqueue_query *p)
{
	union {
		struct drm_msm_submitqueue_query native;
		const struct __c64_drm_msm_submitqueue_query compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.len = u->compat.len;
	u->native.param = u->compat.param;
	u->native.id = u->compat.id;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_submitqueue_query(struct drm_msm_submitqueue_query *p)
{
	union {
		struct __c64_drm_msm_submitqueue_query compat;
		const struct drm_msm_submitqueue_query native;
	} *u = (void *)p;

	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.id = u->native.id;
	u->compat.param = u->native.param;
	u->compat.len = u->native.len;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_msm_submitqueue_query_2(struct drm_msm_submitqueue_query *native, const struct __c64_drm_msm_submitqueue_query *compat)
{

	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->id = compat->id;
	native->param = compat->param;
	native->len = compat->len;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_msm_submitqueue_query_2(struct __c64_drm_msm_submitqueue_query *compat, const struct drm_msm_submitqueue_query *native)
{

	compat->data = (__c64_ptr64 __force)native->data;
	compat->id = native->id;
	compat->param = native->param;
	compat->len = native->len;
	compat->pad = native->pad;
}
