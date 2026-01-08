#pragma once


#include <linux/compat.h>


struct __c64_drm_etnaviv_gem_submit {
	__u32 fence;          /* out */
	__u32 pipe;           /* in */
	__u32 exec_state;     /* in, initial execution state (ETNA_PIPE_x) */
	__u32 nr_bos;         /* in, number of submit_bo's */
	__u32 nr_relocs;      /* in, number of submit_reloc's */
	__u32 stream_size;    /* in, cmdstream size */
	__c64_ptr64 bos;            /* in, ptr to array of submit_bo's */
	__c64_ptr64 relocs;         /* in, ptr to array of submit_reloc's */
	__c64_ptr64 stream;         /* in, ptr to cmdstream */
	__u32 flags;          /* in, mask of ETNA_SUBMIT_x */
	__s32 fence_fd;       /* in/out, fence fd (see ETNA_SUBMIT_FENCE_FD_x) */
	__c64_ptr64 pmrs;           /* in, ptr to array of submit_pmr's */
	__u32 nr_pmrs;        /* in, number of submit_pmr's */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_etnaviv_gem_submit(struct drm_etnaviv_gem_submit *p)
{
	union {
		struct drm_etnaviv_gem_submit native;
		const struct __c64_drm_etnaviv_gem_submit compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.nr_pmrs = u->compat.nr_pmrs;
	u->native.pmrs = (user_uintptr_t)compat_ptr(u->compat.pmrs);
	u->native.fence_fd = u->compat.fence_fd;
	u->native.flags = u->compat.flags;
	u->native.stream = (user_uintptr_t)compat_ptr(u->compat.stream);
	u->native.relocs = (user_uintptr_t)compat_ptr(u->compat.relocs);
	u->native.bos = (user_uintptr_t)compat_ptr(u->compat.bos);
	u->native.stream_size = u->compat.stream_size;
	u->native.nr_relocs = u->compat.nr_relocs;
	u->native.nr_bos = u->compat.nr_bos;
	u->native.exec_state = u->compat.exec_state;
	u->native.pipe = u->compat.pipe;
	u->native.fence = u->compat.fence;
}
static __always_inline __maybe_unused void
__to_c64_drm_etnaviv_gem_submit(struct drm_etnaviv_gem_submit *p)
{
	union {
		struct __c64_drm_etnaviv_gem_submit compat;
		const struct drm_etnaviv_gem_submit native;
	} *u = (void *)p;

	u->compat.fence = u->native.fence;
	u->compat.pipe = u->native.pipe;
	u->compat.exec_state = u->native.exec_state;
	u->compat.nr_bos = u->native.nr_bos;
	u->compat.nr_relocs = u->native.nr_relocs;
	u->compat.stream_size = u->native.stream_size;
	u->compat.bos = (__c64_ptr64 __force)u->native.bos;
	u->compat.relocs = (__c64_ptr64 __force)u->native.relocs;
	u->compat.stream = (__c64_ptr64 __force)u->native.stream;
	u->compat.flags = u->native.flags;
	u->compat.fence_fd = u->native.fence_fd;
	u->compat.pmrs = (__c64_ptr64 __force)u->native.pmrs;
	u->compat.nr_pmrs = u->native.nr_pmrs;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_etnaviv_gem_submit_2(struct drm_etnaviv_gem_submit *native, const struct __c64_drm_etnaviv_gem_submit *compat)
{

	native->fence = compat->fence;
	native->pipe = compat->pipe;
	native->exec_state = compat->exec_state;
	native->nr_bos = compat->nr_bos;
	native->nr_relocs = compat->nr_relocs;
	native->stream_size = compat->stream_size;
	native->bos = (user_uintptr_t)compat_ptr(compat->bos);
	native->relocs = (user_uintptr_t)compat_ptr(compat->relocs);
	native->stream = (user_uintptr_t)compat_ptr(compat->stream);
	native->flags = compat->flags;
	native->fence_fd = compat->fence_fd;
	native->pmrs = (user_uintptr_t)compat_ptr(compat->pmrs);
	native->nr_pmrs = compat->nr_pmrs;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_etnaviv_gem_submit_2(struct __c64_drm_etnaviv_gem_submit *compat, const struct drm_etnaviv_gem_submit *native)
{

	compat->fence = native->fence;
	compat->pipe = native->pipe;
	compat->exec_state = native->exec_state;
	compat->nr_bos = native->nr_bos;
	compat->nr_relocs = native->nr_relocs;
	compat->stream_size = native->stream_size;
	compat->bos = (__c64_ptr64 __force)native->bos;
	compat->relocs = (__c64_ptr64 __force)native->relocs;
	compat->stream = (__c64_ptr64 __force)native->stream;
	compat->flags = native->flags;
	compat->fence_fd = native->fence_fd;
	compat->pmrs = (__c64_ptr64 __force)native->pmrs;
	compat->nr_pmrs = native->nr_pmrs;
	compat->pad = native->pad;
}
struct __c64_drm_etnaviv_gem_userptr {
	__c64_ptr64 user_ptr;	/* in, page aligned user pointer */
	__u64 user_size;	/* in, page aligned user size */
	__u32 flags;		/* in, flags */
	__u32 handle;	/* out, non-zero handle */
};

static __always_inline __maybe_unused void
__from_c64_drm_etnaviv_gem_userptr(struct drm_etnaviv_gem_userptr *p)
{
	union {
		struct drm_etnaviv_gem_userptr native;
		const struct __c64_drm_etnaviv_gem_userptr compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.flags = u->compat.flags;
	u->native.user_size = u->compat.user_size;
	u->native.user_ptr = (user_uintptr_t)compat_ptr(u->compat.user_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_etnaviv_gem_userptr(struct drm_etnaviv_gem_userptr *p)
{
	union {
		struct __c64_drm_etnaviv_gem_userptr compat;
		const struct drm_etnaviv_gem_userptr native;
	} *u = (void *)p;

	u->compat.user_ptr = (__c64_ptr64 __force)u->native.user_ptr;
	u->compat.user_size = u->native.user_size;
	u->compat.flags = u->native.flags;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_drm_etnaviv_gem_userptr_2(struct drm_etnaviv_gem_userptr *native, const struct __c64_drm_etnaviv_gem_userptr *compat)
{

	native->user_ptr = (user_uintptr_t)compat_ptr(compat->user_ptr);
	native->user_size = compat->user_size;
	native->flags = compat->flags;
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_etnaviv_gem_userptr_2(struct __c64_drm_etnaviv_gem_userptr *compat, const struct drm_etnaviv_gem_userptr *native)
{

	compat->user_ptr = (__c64_ptr64 __force)native->user_ptr;
	compat->user_size = native->user_size;
	compat->flags = native->flags;
	compat->handle = native->handle;
}
