#pragma once


#include <linux/compat.h>


struct __c64_drm_lima_gem_submit {
	__u32 ctx;         /* in, context handle task is submitted to */
	__u32 pipe;        /* in, which pipe to use, GP/PP */
	__u32 nr_bos;      /* in, array length of bos field */
	__u32 frame_size;  /* in, size of frame field */
	__c64_ptr64 bos;         /* in, array of drm_lima_gem_submit_bo */
	__c64_ptr64 frame;       /* in, GP/PP frame */
	__u32 flags;       /* in, submit flags */
	__u32 out_sync;    /* in, drm_syncobj handle used to wait task finish after submission */
	__u32 in_sync[2];  /* in, drm_syncobj handle used to wait before start this task */
};

static __always_inline __maybe_unused void
__from_c64_drm_lima_gem_submit(struct drm_lima_gem_submit *p)
{
	union {
		struct drm_lima_gem_submit native;
		const struct __c64_drm_lima_gem_submit compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.in_sync) != sizeof(u->native.in_sync));
	memmove(&u->native.in_sync, &u->compat.in_sync, sizeof(u->native.in_sync));
	u->native.out_sync = u->compat.out_sync;
	u->native.flags = u->compat.flags;
	u->native.frame = (user_uintptr_t)compat_ptr(u->compat.frame);
	u->native.bos = (user_uintptr_t)compat_ptr(u->compat.bos);
	u->native.frame_size = u->compat.frame_size;
	u->native.nr_bos = u->compat.nr_bos;
	u->native.pipe = u->compat.pipe;
	u->native.ctx = u->compat.ctx;
}
static __always_inline __maybe_unused void
__to_c64_drm_lima_gem_submit(struct drm_lima_gem_submit *p)
{
	union {
		struct __c64_drm_lima_gem_submit compat;
		const struct drm_lima_gem_submit native;
	} *u = (void *)p;

	u->compat.ctx = u->native.ctx;
	u->compat.pipe = u->native.pipe;
	u->compat.nr_bos = u->native.nr_bos;
	u->compat.frame_size = u->native.frame_size;
	u->compat.bos = (__c64_ptr64 __force)u->native.bos;
	u->compat.frame = (__c64_ptr64 __force)u->native.frame;
	u->compat.flags = u->native.flags;
	u->compat.out_sync = u->native.out_sync;
	BUILD_BUG_ON(sizeof(u->native.in_sync) != sizeof(u->compat.in_sync));
	memmove(&u->compat.in_sync, &u->native.in_sync, sizeof(u->compat.in_sync));
}
static __always_inline __maybe_unused void
__from_c64_drm_lima_gem_submit_2(struct drm_lima_gem_submit *native, const struct __c64_drm_lima_gem_submit *compat)
{

	native->ctx = compat->ctx;
	native->pipe = compat->pipe;
	native->nr_bos = compat->nr_bos;
	native->frame_size = compat->frame_size;
	native->bos = (user_uintptr_t)compat_ptr(compat->bos);
	native->frame = (user_uintptr_t)compat_ptr(compat->frame);
	native->flags = compat->flags;
	native->out_sync = compat->out_sync;
	BUILD_BUG_ON(sizeof(compat->in_sync) != sizeof(native->in_sync));
	memcpy(&native->in_sync, &compat->in_sync, sizeof(native->in_sync));
}
static __always_inline __maybe_unused void
__to_c64_drm_lima_gem_submit_2(struct __c64_drm_lima_gem_submit *compat, const struct drm_lima_gem_submit *native)
{

	compat->ctx = native->ctx;
	compat->pipe = native->pipe;
	compat->nr_bos = native->nr_bos;
	compat->frame_size = native->frame_size;
	compat->bos = (__c64_ptr64 __force)native->bos;
	compat->frame = (__c64_ptr64 __force)native->frame;
	compat->flags = native->flags;
	compat->out_sync = native->out_sync;
	BUILD_BUG_ON(sizeof(native->in_sync) != sizeof(compat->in_sync));
	memcpy(&compat->in_sync, &native->in_sync, sizeof(compat->in_sync));
}
