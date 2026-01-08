#pragma once


#include <linux/compat.h>


struct __c64_drm_tegra_submit {
	/**
	 * @context:
	 *
	 * The application context identifying the channel to use for the
	 * execution of this job.
	 */
	__u64 context;

	/**
	 * @num_syncpts:
	 *
	 * The number of syncpoints operated on by this job. This defines the
	 * length of the array pointed to by @syncpts.
	 */
	__u32 num_syncpts;

	/**
	 * @num_cmdbufs:
	 *
	 * The number of command buffers to execute as part of this job. This
	 * defines the length of the array pointed to by @cmdbufs.
	 */
	__u32 num_cmdbufs;

	/**
	 * @num_relocs:
	 *
	 * The number of relocations to perform before executing this job.
	 * This defines the length of the array pointed to by @relocs.
	 */
	__u32 num_relocs;

	/**
	 * @num_waitchks:
	 *
	 * The number of wait checks to perform as part of this job. This
	 * defines the length of the array pointed to by @waitchks.
	 */
	__u32 num_waitchks;

	/**
	 * @waitchk_mask:
	 *
	 * Bitmask of valid wait checks.
	 */
	__u32 waitchk_mask;

	/**
	 * @timeout:
	 *
	 * Timeout, in milliseconds, before this job is cancelled.
	 */
	__u32 timeout;

	/**
	 * @syncpts:
	 *
	 * A pointer to an array of &struct drm_tegra_syncpt structures that
	 * specify the syncpoint operations performed as part of this job.
	 * The number of elements in the array must be equal to the value
	 * given by @num_syncpts.
	 */
	__c64_ptr64 syncpts;

	/**
	 * @cmdbufs:
	 *
	 * A pointer to an array of &struct drm_tegra_cmdbuf structures that
	 * define the command buffers to execute as part of this job. The
	 * number of elements in the array must be equal to the value given
	 * by @num_syncpts.
	 */
	__c64_ptr64 cmdbufs;

	/**
	 * @relocs:
	 *
	 * A pointer to an array of &struct drm_tegra_reloc structures that
	 * specify the relocations that need to be performed before executing
	 * this job. The number of elements in the array must be equal to the
	 * value given by @num_relocs.
	 */
	__c64_ptr64 relocs;

	/**
	 * @waitchks:
	 *
	 * A pointer to an array of &struct drm_tegra_waitchk structures that
	 * specify the wait checks to be performed while executing this job.
	 * The number of elements in the array must be equal to the value
	 * given by @num_waitchks.
	 */
	__c64_ptr64 waitchks;

	/**
	 * @fence:
	 *
	 * The threshold of the syncpoint associated with this job after it
	 * has been completed. Set by the kernel upon successful completion of
	 * the IOCTL. This can be used with the DRM_TEGRA_SYNCPT_WAIT IOCTL to
	 * wait for this job to be finished.
	 */
	__u32 fence;

	/**
	 * @reserved:
	 *
	 * This field is reserved for future use. Must be 0.
	 */
	__u32 reserved[5];
};

static __always_inline __maybe_unused void
__from_c64_drm_tegra_submit(struct drm_tegra_submit *p)
{
	union {
		struct drm_tegra_submit native;
		const struct __c64_drm_tegra_submit compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.fence = u->compat.fence;
	u->native.waitchks = (user_uintptr_t)compat_ptr(u->compat.waitchks);
	u->native.relocs = (user_uintptr_t)compat_ptr(u->compat.relocs);
	u->native.cmdbufs = (user_uintptr_t)compat_ptr(u->compat.cmdbufs);
	u->native.syncpts = (user_uintptr_t)compat_ptr(u->compat.syncpts);
	u->native.timeout = u->compat.timeout;
	u->native.waitchk_mask = u->compat.waitchk_mask;
	u->native.num_waitchks = u->compat.num_waitchks;
	u->native.num_relocs = u->compat.num_relocs;
	u->native.num_cmdbufs = u->compat.num_cmdbufs;
	u->native.num_syncpts = u->compat.num_syncpts;
	u->native.context = u->compat.context;
}
static __always_inline __maybe_unused void
__to_c64_drm_tegra_submit(struct drm_tegra_submit *p)
{
	union {
		struct __c64_drm_tegra_submit compat;
		const struct drm_tegra_submit native;
	} *u = (void *)p;

	u->compat.context = u->native.context;
	u->compat.num_syncpts = u->native.num_syncpts;
	u->compat.num_cmdbufs = u->native.num_cmdbufs;
	u->compat.num_relocs = u->native.num_relocs;
	u->compat.num_waitchks = u->native.num_waitchks;
	u->compat.waitchk_mask = u->native.waitchk_mask;
	u->compat.timeout = u->native.timeout;
	u->compat.syncpts = (__c64_ptr64 __force)u->native.syncpts;
	u->compat.cmdbufs = (__c64_ptr64 __force)u->native.cmdbufs;
	u->compat.relocs = (__c64_ptr64 __force)u->native.relocs;
	u->compat.waitchks = (__c64_ptr64 __force)u->native.waitchks;
	u->compat.fence = u->native.fence;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_tegra_submit_2(struct drm_tegra_submit *native, const struct __c64_drm_tegra_submit *compat)
{

	native->context = compat->context;
	native->num_syncpts = compat->num_syncpts;
	native->num_cmdbufs = compat->num_cmdbufs;
	native->num_relocs = compat->num_relocs;
	native->num_waitchks = compat->num_waitchks;
	native->waitchk_mask = compat->waitchk_mask;
	native->timeout = compat->timeout;
	native->syncpts = (user_uintptr_t)compat_ptr(compat->syncpts);
	native->cmdbufs = (user_uintptr_t)compat_ptr(compat->cmdbufs);
	native->relocs = (user_uintptr_t)compat_ptr(compat->relocs);
	native->waitchks = (user_uintptr_t)compat_ptr(compat->waitchks);
	native->fence = compat->fence;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_tegra_submit_2(struct __c64_drm_tegra_submit *compat, const struct drm_tegra_submit *native)
{

	compat->context = native->context;
	compat->num_syncpts = native->num_syncpts;
	compat->num_cmdbufs = native->num_cmdbufs;
	compat->num_relocs = native->num_relocs;
	compat->num_waitchks = native->num_waitchks;
	compat->waitchk_mask = native->waitchk_mask;
	compat->timeout = native->timeout;
	compat->syncpts = (__c64_ptr64 __force)native->syncpts;
	compat->cmdbufs = (__c64_ptr64 __force)native->cmdbufs;
	compat->relocs = (__c64_ptr64 __force)native->relocs;
	compat->waitchks = (__c64_ptr64 __force)native->waitchks;
	compat->fence = native->fence;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_tegra_channel_submit {
	/**
	 * @context: [in]
	 *
	 * Identifier of the channel to submit this job to.
	 */
	__u32 context;

	/**
	 * @num_bufs: [in]
	 *
	 * Number of elements in the `bufs_ptr` array.
	 */
	__u32 num_bufs;

	/**
	 * @num_cmds: [in]
	 *
	 * Number of elements in the `cmds_ptr` array.
	 */
	__u32 num_cmds;

	/**
	 * @gather_data_words: [in]
	 *
	 * Number of 32-bit words in the `gather_data_ptr` array.
	 */
	__u32 gather_data_words;

	/**
	 * @bufs_ptr: [in]
	 *
	 * Pointer to an array of drm_tegra_submit_buf structures.
	 */
	__c64_ptr64 bufs_ptr;

	/**
	 * @cmds_ptr: [in]
	 *
	 * Pointer to an array of drm_tegra_submit_cmd structures.
	 */
	__c64_ptr64 cmds_ptr;

	/**
	 * @gather_data_ptr: [in]
	 *
	 * Pointer to an array of Host1x opcodes to be used by GATHER_UPTR
	 * commands.
	 */
	__c64_ptr64 gather_data_ptr;

	/**
	 * @syncobj_in: [in]
	 *
	 * Handle for DRM syncobj that will be waited before submission.
	 * Ignored if zero.
	 */
	__u32 syncobj_in;

	/**
	 * @syncobj_out: [in]
	 *
	 * Handle for DRM syncobj that will have its fence replaced with
	 * the job's completion fence. Ignored if zero.
	 */
	__u32 syncobj_out;

	/**
	 * @syncpt_incr: [in,out]
	 *
	 * Information about the syncpoint the job will increment.
	 */
	struct drm_tegra_submit_syncpt syncpt;
};

static __always_inline __maybe_unused void
__from_c64_drm_tegra_channel_submit(struct drm_tegra_channel_submit *p)
{
	union {
		struct drm_tegra_channel_submit native;
		const struct __c64_drm_tegra_channel_submit compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.syncpt) != sizeof(u->native.syncpt));
	memmove(&u->native.syncpt, &u->compat.syncpt, sizeof(u->native.syncpt));
	u->native.syncobj_out = u->compat.syncobj_out;
	u->native.syncobj_in = u->compat.syncobj_in;
	u->native.gather_data_ptr = (user_uintptr_t)compat_ptr(u->compat.gather_data_ptr);
	u->native.cmds_ptr = (user_uintptr_t)compat_ptr(u->compat.cmds_ptr);
	u->native.bufs_ptr = (user_uintptr_t)compat_ptr(u->compat.bufs_ptr);
	u->native.gather_data_words = u->compat.gather_data_words;
	u->native.num_cmds = u->compat.num_cmds;
	u->native.num_bufs = u->compat.num_bufs;
	u->native.context = u->compat.context;
}
static __always_inline __maybe_unused void
__to_c64_drm_tegra_channel_submit(struct drm_tegra_channel_submit *p)
{
	union {
		struct __c64_drm_tegra_channel_submit compat;
		const struct drm_tegra_channel_submit native;
	} *u = (void *)p;

	u->compat.context = u->native.context;
	u->compat.num_bufs = u->native.num_bufs;
	u->compat.num_cmds = u->native.num_cmds;
	u->compat.gather_data_words = u->native.gather_data_words;
	u->compat.bufs_ptr = (__c64_ptr64 __force)u->native.bufs_ptr;
	u->compat.cmds_ptr = (__c64_ptr64 __force)u->native.cmds_ptr;
	u->compat.gather_data_ptr = (__c64_ptr64 __force)u->native.gather_data_ptr;
	u->compat.syncobj_in = u->native.syncobj_in;
	u->compat.syncobj_out = u->native.syncobj_out;
	BUILD_BUG_ON(sizeof(u->native.syncpt) != sizeof(u->compat.syncpt));
	memmove(&u->compat.syncpt, &u->native.syncpt, sizeof(u->compat.syncpt));
}
static __always_inline __maybe_unused void
__from_c64_drm_tegra_channel_submit_2(struct drm_tegra_channel_submit *native, const struct __c64_drm_tegra_channel_submit *compat)
{

	native->context = compat->context;
	native->num_bufs = compat->num_bufs;
	native->num_cmds = compat->num_cmds;
	native->gather_data_words = compat->gather_data_words;
	native->bufs_ptr = (user_uintptr_t)compat_ptr(compat->bufs_ptr);
	native->cmds_ptr = (user_uintptr_t)compat_ptr(compat->cmds_ptr);
	native->gather_data_ptr = (user_uintptr_t)compat_ptr(compat->gather_data_ptr);
	native->syncobj_in = compat->syncobj_in;
	native->syncobj_out = compat->syncobj_out;
	BUILD_BUG_ON(sizeof(compat->syncpt) != sizeof(native->syncpt));
	memcpy(&native->syncpt, &compat->syncpt, sizeof(native->syncpt));
}
static __always_inline __maybe_unused void
__to_c64_drm_tegra_channel_submit_2(struct __c64_drm_tegra_channel_submit *compat, const struct drm_tegra_channel_submit *native)
{

	compat->context = native->context;
	compat->num_bufs = native->num_bufs;
	compat->num_cmds = native->num_cmds;
	compat->gather_data_words = native->gather_data_words;
	compat->bufs_ptr = (__c64_ptr64 __force)native->bufs_ptr;
	compat->cmds_ptr = (__c64_ptr64 __force)native->cmds_ptr;
	compat->gather_data_ptr = (__c64_ptr64 __force)native->gather_data_ptr;
	compat->syncobj_in = native->syncobj_in;
	compat->syncobj_out = native->syncobj_out;
	BUILD_BUG_ON(sizeof(native->syncpt) != sizeof(compat->syncpt));
	memcpy(&compat->syncpt, &native->syncpt, sizeof(compat->syncpt));
}
