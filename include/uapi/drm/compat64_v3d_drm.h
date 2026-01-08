#pragma once


#include <linux/compat.h>


struct __c64_drm_v3d_extension {
	__c64_ptr64 next;
	__u32 id;
	__u32 flags; /* mbz */
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_extension(struct drm_v3d_extension *p)
{
	union {
		struct drm_v3d_extension native;
		const struct __c64_drm_v3d_extension compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.id = u->compat.id;
	u->native.next = (user_uintptr_t)compat_ptr(u->compat.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_extension(struct drm_v3d_extension *p)
{
	union {
		struct __c64_drm_v3d_extension compat;
		const struct drm_v3d_extension native;
	} *u = (void *)p;

	u->compat.next = (__c64_ptr64 __force)u->native.next;
	u->compat.id = u->native.id;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_extension_2(struct drm_v3d_extension *native, const struct __c64_drm_v3d_extension *compat)
{

	native->next = (user_uintptr_t)compat_ptr(compat->next);
	native->id = compat->id;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_extension_2(struct __c64_drm_v3d_extension *compat, const struct drm_v3d_extension *native)
{

	compat->next = (__c64_ptr64 __force)native->next;
	compat->id = native->id;
	compat->flags = native->flags;
}
struct __c64_drm_v3d_multi_sync {
	struct __c64_drm_v3d_extension base;
	/* Array of wait and signal semaphores */
	__c64_ptr64 in_syncs;
	__c64_ptr64 out_syncs;

	/* Number of entries */
	__u32 in_sync_count;
	__u32 out_sync_count;

	/* set the stage (v3d_queue) to sync */
	__u32 wait_stage;

	__u32 pad; /* mbz */
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_multi_sync(struct drm_v3d_multi_sync *p)
{
	union {
		struct drm_v3d_multi_sync native;
		const struct __c64_drm_v3d_multi_sync compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.wait_stage = u->compat.wait_stage;
	u->native.out_sync_count = u->compat.out_sync_count;
	u->native.in_sync_count = u->compat.in_sync_count;
	u->native.out_syncs = (user_uintptr_t)compat_ptr(u->compat.out_syncs);
	u->native.in_syncs = (user_uintptr_t)compat_ptr(u->compat.in_syncs);
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_multi_sync(struct drm_v3d_multi_sync *p)
{
	union {
		struct __c64_drm_v3d_multi_sync compat;
		const struct drm_v3d_multi_sync native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.in_syncs = (__c64_ptr64 __force)u->native.in_syncs;
	u->compat.out_syncs = (__c64_ptr64 __force)u->native.out_syncs;
	u->compat.in_sync_count = u->native.in_sync_count;
	u->compat.out_sync_count = u->native.out_sync_count;
	u->compat.wait_stage = u->native.wait_stage;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_multi_sync_2(struct drm_v3d_multi_sync *native, const struct __c64_drm_v3d_multi_sync *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->in_syncs = (user_uintptr_t)compat_ptr(compat->in_syncs);
	native->out_syncs = (user_uintptr_t)compat_ptr(compat->out_syncs);
	native->in_sync_count = compat->in_sync_count;
	native->out_sync_count = compat->out_sync_count;
	native->wait_stage = compat->wait_stage;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_multi_sync_2(struct __c64_drm_v3d_multi_sync *compat, const struct drm_v3d_multi_sync *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->in_syncs = (__c64_ptr64 __force)native->in_syncs;
	compat->out_syncs = (__c64_ptr64 __force)native->out_syncs;
	compat->in_sync_count = native->in_sync_count;
	compat->out_sync_count = native->out_sync_count;
	compat->wait_stage = native->wait_stage;
	compat->pad = native->pad;
}
struct __c64_drm_v3d_submit_cl {
	/* Pointer to the binner command list.
	 *
	 * This is the first set of commands executed, which runs the
	 * coordinate shader to determine where primitives land on the screen,
	 * then writes out the state updates and draw calls necessary per tile
	 * to the tile allocation BO.
	 *
	 * This BCL will block on any previous BCL submitted on the
	 * same FD, but not on any RCL or BCLs submitted by other
	 * clients -- that is left up to the submitter to control
	 * using in_sync_bcl if necessary.
	 */
	__u32 bcl_start;

	/** End address of the BCL (first byte after the BCL) */
	__u32 bcl_end;

	/* Offset of the render command list.
	 *
	 * This is the second set of commands executed, which will either
	 * execute the tiles that have been set up by the BCL, or a fixed set
	 * of tiles (in the case of RCL-only blits).
	 *
	 * This RCL will block on this submit's BCL, and any previous
	 * RCL submitted on the same FD, but not on any RCL or BCLs
	 * submitted by other clients -- that is left up to the
	 * submitter to control using in_sync_rcl if necessary.
	 */
	__u32 rcl_start;

	/** End address of the RCL (first byte after the RCL) */
	__u32 rcl_end;

	/** An optional sync object to wait on before starting the BCL. */
	__u32 in_sync_bcl;
	/** An optional sync object to wait on before starting the RCL. */
	__u32 in_sync_rcl;
	/** An optional sync object to place the completion fence in. */
	__u32 out_sync;

	/* Offset of the tile alloc memory
	 *
	 * This is optional on V3D 3.3 (where the CL can set the value) but
	 * required on V3D 4.1.
	 */
	__u32 qma;

	/** Size of the tile alloc memory. */
	__u32 qms;

	/** Offset of the tile state data array. */
	__u32 qts;

	/* Pointer to a u32 array of the BOs that are referenced by the job.
	 */
	__c64_ptr64 bo_handles;

	/* Number of BO handles passed in (size is that times 4). */
	__u32 bo_handle_count;

	/* DRM_V3D_SUBMIT_* properties */
	__u32 flags;

	/* ID of the perfmon to attach to this job. 0 means no perfmon. */
	__u32 perfmon_id;

	__u32 pad;

	/* Pointer to an array of ioctl extensions*/
	__c64_ptr64 extensions;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_cl(struct drm_v3d_submit_cl *p)
{
	union {
		struct drm_v3d_submit_cl native;
		const struct __c64_drm_v3d_submit_cl compat;
	} *u = (void *)p;

	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
	u->native.pad = u->compat.pad;
	u->native.perfmon_id = u->compat.perfmon_id;
	u->native.flags = u->compat.flags;
	u->native.bo_handle_count = u->compat.bo_handle_count;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
	u->native.qts = u->compat.qts;
	u->native.qms = u->compat.qms;
	u->native.qma = u->compat.qma;
	u->native.out_sync = u->compat.out_sync;
	u->native.in_sync_rcl = u->compat.in_sync_rcl;
	u->native.in_sync_bcl = u->compat.in_sync_bcl;
	u->native.rcl_end = u->compat.rcl_end;
	u->native.rcl_start = u->compat.rcl_start;
	u->native.bcl_end = u->compat.bcl_end;
	u->native.bcl_start = u->compat.bcl_start;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_cl(struct drm_v3d_submit_cl *p)
{
	union {
		struct __c64_drm_v3d_submit_cl compat;
		const struct drm_v3d_submit_cl native;
	} *u = (void *)p;

	u->compat.bcl_start = u->native.bcl_start;
	u->compat.bcl_end = u->native.bcl_end;
	u->compat.rcl_start = u->native.rcl_start;
	u->compat.rcl_end = u->native.rcl_end;
	u->compat.in_sync_bcl = u->native.in_sync_bcl;
	u->compat.in_sync_rcl = u->native.in_sync_rcl;
	u->compat.out_sync = u->native.out_sync;
	u->compat.qma = u->native.qma;
	u->compat.qms = u->native.qms;
	u->compat.qts = u->native.qts;
	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.bo_handle_count = u->native.bo_handle_count;
	u->compat.flags = u->native.flags;
	u->compat.perfmon_id = u->native.perfmon_id;
	u->compat.pad = u->native.pad;
	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_cl_2(struct drm_v3d_submit_cl *native, const struct __c64_drm_v3d_submit_cl *compat)
{

	native->bcl_start = compat->bcl_start;
	native->bcl_end = compat->bcl_end;
	native->rcl_start = compat->rcl_start;
	native->rcl_end = compat->rcl_end;
	native->in_sync_bcl = compat->in_sync_bcl;
	native->in_sync_rcl = compat->in_sync_rcl;
	native->out_sync = compat->out_sync;
	native->qma = compat->qma;
	native->qms = compat->qms;
	native->qts = compat->qts;
	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->bo_handle_count = compat->bo_handle_count;
	native->flags = compat->flags;
	native->perfmon_id = compat->perfmon_id;
	native->pad = compat->pad;
	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_cl_2(struct __c64_drm_v3d_submit_cl *compat, const struct drm_v3d_submit_cl *native)
{

	compat->bcl_start = native->bcl_start;
	compat->bcl_end = native->bcl_end;
	compat->rcl_start = native->rcl_start;
	compat->rcl_end = native->rcl_end;
	compat->in_sync_bcl = native->in_sync_bcl;
	compat->in_sync_rcl = native->in_sync_rcl;
	compat->out_sync = native->out_sync;
	compat->qma = native->qma;
	compat->qms = native->qms;
	compat->qts = native->qts;
	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->bo_handle_count = native->bo_handle_count;
	compat->flags = native->flags;
	compat->perfmon_id = native->perfmon_id;
	compat->pad = native->pad;
	compat->extensions = (__c64_ptr64 __force)native->extensions;
}
struct __c64_drm_v3d_submit_tfu {
	__u32 icfg;
	__u32 iia;
	__u32 iis;
	__u32 ica;
	__u32 iua;
	__u32 ioa;
	__u32 ios;
	__u32 coef[4];
	/* First handle is the output BO, following are other inputs.
	 * 0 for unused.
	 */
	__u32 bo_handles[4];
	/* sync object to block on before running the TFU job.  Each TFU
	 * job will execute in the order submitted to its FD.  Synchronization
	 * against rendering jobs requires using sync objects.
	 */
	__u32 in_sync;
	/* Sync object to signal when the TFU job is done. */
	__u32 out_sync;

	__u32 flags;

	/* Pointer to an array of ioctl extensions*/
	__c64_ptr64 extensions;

	struct {
		__u32 ioc;
		__u32 pad;
	} v71;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_tfu(struct drm_v3d_submit_tfu *p)
{
	union {
		struct drm_v3d_submit_tfu native;
		const struct __c64_drm_v3d_submit_tfu compat;
	} *u = (void *)p;

	u->native.v71.pad = u->compat.v71.pad;
	u->native.v71.ioc = u->compat.v71.ioc;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
	u->native.flags = u->compat.flags;
	u->native.out_sync = u->compat.out_sync;
	u->native.in_sync = u->compat.in_sync;
	BUILD_BUG_ON(sizeof(u->compat.bo_handles) != sizeof(u->native.bo_handles));
	memmove(&u->native.bo_handles, &u->compat.bo_handles, sizeof(u->native.bo_handles));
	BUILD_BUG_ON(sizeof(u->compat.coef) != sizeof(u->native.coef));
	memmove(&u->native.coef, &u->compat.coef, sizeof(u->native.coef));
	u->native.ios = u->compat.ios;
	u->native.ioa = u->compat.ioa;
	u->native.iua = u->compat.iua;
	u->native.ica = u->compat.ica;
	u->native.iis = u->compat.iis;
	u->native.iia = u->compat.iia;
	u->native.icfg = u->compat.icfg;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_tfu(struct drm_v3d_submit_tfu *p)
{
	union {
		struct __c64_drm_v3d_submit_tfu compat;
		const struct drm_v3d_submit_tfu native;
	} *u = (void *)p;

	u->compat.icfg = u->native.icfg;
	u->compat.iia = u->native.iia;
	u->compat.iis = u->native.iis;
	u->compat.ica = u->native.ica;
	u->compat.iua = u->native.iua;
	u->compat.ioa = u->native.ioa;
	u->compat.ios = u->native.ios;
	BUILD_BUG_ON(sizeof(u->native.coef) != sizeof(u->compat.coef));
	memmove(&u->compat.coef, &u->native.coef, sizeof(u->compat.coef));
	BUILD_BUG_ON(sizeof(u->native.bo_handles) != sizeof(u->compat.bo_handles));
	memmove(&u->compat.bo_handles, &u->native.bo_handles, sizeof(u->compat.bo_handles));
	u->compat.in_sync = u->native.in_sync;
	u->compat.out_sync = u->native.out_sync;
	u->compat.flags = u->native.flags;
	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.v71.ioc = u->native.v71.ioc;
	u->compat.v71.pad = u->native.v71.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_tfu_2(struct drm_v3d_submit_tfu *native, const struct __c64_drm_v3d_submit_tfu *compat)
{

	native->icfg = compat->icfg;
	native->iia = compat->iia;
	native->iis = compat->iis;
	native->ica = compat->ica;
	native->iua = compat->iua;
	native->ioa = compat->ioa;
	native->ios = compat->ios;
	BUILD_BUG_ON(sizeof(compat->coef) != sizeof(native->coef));
	memcpy(&native->coef, &compat->coef, sizeof(native->coef));
	BUILD_BUG_ON(sizeof(compat->bo_handles) != sizeof(native->bo_handles));
	memcpy(&native->bo_handles, &compat->bo_handles, sizeof(native->bo_handles));
	native->in_sync = compat->in_sync;
	native->out_sync = compat->out_sync;
	native->flags = compat->flags;
	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->v71.ioc = compat->v71.ioc;
	native->v71.pad = compat->v71.pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_tfu_2(struct __c64_drm_v3d_submit_tfu *compat, const struct drm_v3d_submit_tfu *native)
{

	compat->icfg = native->icfg;
	compat->iia = native->iia;
	compat->iis = native->iis;
	compat->ica = native->ica;
	compat->iua = native->iua;
	compat->ioa = native->ioa;
	compat->ios = native->ios;
	BUILD_BUG_ON(sizeof(native->coef) != sizeof(compat->coef));
	memcpy(&compat->coef, &native->coef, sizeof(compat->coef));
	BUILD_BUG_ON(sizeof(native->bo_handles) != sizeof(compat->bo_handles));
	memcpy(&compat->bo_handles, &native->bo_handles, sizeof(compat->bo_handles));
	compat->in_sync = native->in_sync;
	compat->out_sync = native->out_sync;
	compat->flags = native->flags;
	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->v71.ioc = native->v71.ioc;
	compat->v71.pad = native->v71.pad;
}
struct __c64_drm_v3d_submit_csd {
	__u32 cfg[7];
	__u32 coef[4];

	/* Pointer to a u32 array of the BOs that are referenced by the job.
	 */
	__c64_ptr64 bo_handles;

	/* Number of BO handles passed in (size is that times 4). */
	__u32 bo_handle_count;

	/* sync object to block on before running the CSD job.  Each
	 * CSD job will execute in the order submitted to its FD.
	 * Synchronization against rendering/TFU jobs or CSD from
	 * other fds requires using sync objects.
	 */
	__u32 in_sync;
	/* Sync object to signal when the CSD job is done. */
	__u32 out_sync;

	/* ID of the perfmon to attach to this job. 0 means no perfmon. */
	__u32 perfmon_id;

	/* Pointer to an array of ioctl extensions*/
	__c64_ptr64 extensions;

	__u32 flags;

	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_csd(struct drm_v3d_submit_csd *p)
{
	union {
		struct drm_v3d_submit_csd native;
		const struct __c64_drm_v3d_submit_csd compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.flags = u->compat.flags;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
	u->native.perfmon_id = u->compat.perfmon_id;
	u->native.out_sync = u->compat.out_sync;
	u->native.in_sync = u->compat.in_sync;
	u->native.bo_handle_count = u->compat.bo_handle_count;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
	BUILD_BUG_ON(sizeof(u->compat.coef) != sizeof(u->native.coef));
	memmove(&u->native.coef, &u->compat.coef, sizeof(u->native.coef));
	BUILD_BUG_ON(sizeof(u->compat.cfg) != sizeof(u->native.cfg));
	memmove(&u->native.cfg, &u->compat.cfg, sizeof(u->native.cfg));
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_csd(struct drm_v3d_submit_csd *p)
{
	union {
		struct __c64_drm_v3d_submit_csd compat;
		const struct drm_v3d_submit_csd native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.cfg) != sizeof(u->compat.cfg));
	memmove(&u->compat.cfg, &u->native.cfg, sizeof(u->compat.cfg));
	BUILD_BUG_ON(sizeof(u->native.coef) != sizeof(u->compat.coef));
	memmove(&u->compat.coef, &u->native.coef, sizeof(u->compat.coef));
	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.bo_handle_count = u->native.bo_handle_count;
	u->compat.in_sync = u->native.in_sync;
	u->compat.out_sync = u->native.out_sync;
	u->compat.perfmon_id = u->native.perfmon_id;
	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.flags = u->native.flags;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_csd_2(struct drm_v3d_submit_csd *native, const struct __c64_drm_v3d_submit_csd *compat)
{

	BUILD_BUG_ON(sizeof(compat->cfg) != sizeof(native->cfg));
	memcpy(&native->cfg, &compat->cfg, sizeof(native->cfg));
	BUILD_BUG_ON(sizeof(compat->coef) != sizeof(native->coef));
	memcpy(&native->coef, &compat->coef, sizeof(native->coef));
	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->bo_handle_count = compat->bo_handle_count;
	native->in_sync = compat->in_sync;
	native->out_sync = compat->out_sync;
	native->perfmon_id = compat->perfmon_id;
	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->flags = compat->flags;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_csd_2(struct __c64_drm_v3d_submit_csd *compat, const struct drm_v3d_submit_csd *native)
{

	BUILD_BUG_ON(sizeof(native->cfg) != sizeof(compat->cfg));
	memcpy(&compat->cfg, &native->cfg, sizeof(compat->cfg));
	BUILD_BUG_ON(sizeof(native->coef) != sizeof(compat->coef));
	memcpy(&compat->coef, &native->coef, sizeof(compat->coef));
	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->bo_handle_count = native->bo_handle_count;
	compat->in_sync = native->in_sync;
	compat->out_sync = native->out_sync;
	compat->perfmon_id = native->perfmon_id;
	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->flags = native->flags;
	compat->pad = native->pad;
}
struct __c64_drm_v3d_indirect_csd {
	struct __c64_drm_v3d_extension base;

	/* Indirect CSD */
	struct __c64_drm_v3d_submit_csd submit;

	/* Handle of the indirect BO, that should be also attached to the
	 * indirect CSD.
	 */
	__u32 indirect;

	/* Offset within the BO where the workgroup counts are stored */
	__u32 offset;

	/* Workgroups size */
	__u32 wg_size;

	/* Indices of the uniforms with the workgroup dispatch counts
	 * in the uniform stream. If the uniform rewrite is not needed,
	 * the offset must be 0xffffffff.
	 */
	__u32 wg_uniform_offsets[3];
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_indirect_csd(struct drm_v3d_indirect_csd *p)
{
	union {
		struct drm_v3d_indirect_csd native;
		const struct __c64_drm_v3d_indirect_csd compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.wg_uniform_offsets) != sizeof(u->native.wg_uniform_offsets));
	memmove(&u->native.wg_uniform_offsets, &u->compat.wg_uniform_offsets, sizeof(u->native.wg_uniform_offsets));
	u->native.wg_size = u->compat.wg_size;
	u->native.offset = u->compat.offset;
	u->native.indirect = u->compat.indirect;
	u->native.submit.pad = u->compat.submit.pad;
	u->native.submit.flags = u->compat.submit.flags;
	u->native.submit.extensions = (user_uintptr_t)compat_ptr(u->compat.submit.extensions);
	u->native.submit.perfmon_id = u->compat.submit.perfmon_id;
	u->native.submit.out_sync = u->compat.submit.out_sync;
	u->native.submit.in_sync = u->compat.submit.in_sync;
	u->native.submit.bo_handle_count = u->compat.submit.bo_handle_count;
	u->native.submit.bo_handles = (user_uintptr_t)compat_ptr(u->compat.submit.bo_handles);
	BUILD_BUG_ON(sizeof(u->compat.submit.coef) != sizeof(u->native.submit.coef));
	memmove(&u->native.submit.coef, &u->compat.submit.coef, sizeof(u->native.submit.coef));
	BUILD_BUG_ON(sizeof(u->compat.submit.cfg) != sizeof(u->native.submit.cfg));
	memmove(&u->native.submit.cfg, &u->compat.submit.cfg, sizeof(u->native.submit.cfg));
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_indirect_csd(struct drm_v3d_indirect_csd *p)
{
	union {
		struct __c64_drm_v3d_indirect_csd compat;
		const struct drm_v3d_indirect_csd native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	BUILD_BUG_ON(sizeof(u->native.submit.cfg) != sizeof(u->compat.submit.cfg));
	memmove(&u->compat.submit.cfg, &u->native.submit.cfg, sizeof(u->compat.submit.cfg));
	BUILD_BUG_ON(sizeof(u->native.submit.coef) != sizeof(u->compat.submit.coef));
	memmove(&u->compat.submit.coef, &u->native.submit.coef, sizeof(u->compat.submit.coef));
	u->compat.submit.bo_handles = (__c64_ptr64 __force)u->native.submit.bo_handles;
	u->compat.submit.bo_handle_count = u->native.submit.bo_handle_count;
	u->compat.submit.in_sync = u->native.submit.in_sync;
	u->compat.submit.out_sync = u->native.submit.out_sync;
	u->compat.submit.perfmon_id = u->native.submit.perfmon_id;
	u->compat.submit.extensions = (__c64_ptr64 __force)u->native.submit.extensions;
	u->compat.submit.flags = u->native.submit.flags;
	u->compat.submit.pad = u->native.submit.pad;
	u->compat.indirect = u->native.indirect;
	u->compat.offset = u->native.offset;
	u->compat.wg_size = u->native.wg_size;
	BUILD_BUG_ON(sizeof(u->native.wg_uniform_offsets) != sizeof(u->compat.wg_uniform_offsets));
	memmove(&u->compat.wg_uniform_offsets, &u->native.wg_uniform_offsets, sizeof(u->compat.wg_uniform_offsets));
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_indirect_csd_2(struct drm_v3d_indirect_csd *native, const struct __c64_drm_v3d_indirect_csd *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	BUILD_BUG_ON(sizeof(compat->submit.cfg) != sizeof(native->submit.cfg));
	memcpy(&native->submit.cfg, &compat->submit.cfg, sizeof(native->submit.cfg));
	BUILD_BUG_ON(sizeof(compat->submit.coef) != sizeof(native->submit.coef));
	memcpy(&native->submit.coef, &compat->submit.coef, sizeof(native->submit.coef));
	native->submit.bo_handles = (user_uintptr_t)compat_ptr(compat->submit.bo_handles);
	native->submit.bo_handle_count = compat->submit.bo_handle_count;
	native->submit.in_sync = compat->submit.in_sync;
	native->submit.out_sync = compat->submit.out_sync;
	native->submit.perfmon_id = compat->submit.perfmon_id;
	native->submit.extensions = (user_uintptr_t)compat_ptr(compat->submit.extensions);
	native->submit.flags = compat->submit.flags;
	native->submit.pad = compat->submit.pad;
	native->indirect = compat->indirect;
	native->offset = compat->offset;
	native->wg_size = compat->wg_size;
	BUILD_BUG_ON(sizeof(compat->wg_uniform_offsets) != sizeof(native->wg_uniform_offsets));
	memcpy(&native->wg_uniform_offsets, &compat->wg_uniform_offsets, sizeof(native->wg_uniform_offsets));
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_indirect_csd_2(struct __c64_drm_v3d_indirect_csd *compat, const struct drm_v3d_indirect_csd *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	BUILD_BUG_ON(sizeof(native->submit.cfg) != sizeof(compat->submit.cfg));
	memcpy(&compat->submit.cfg, &native->submit.cfg, sizeof(compat->submit.cfg));
	BUILD_BUG_ON(sizeof(native->submit.coef) != sizeof(compat->submit.coef));
	memcpy(&compat->submit.coef, &native->submit.coef, sizeof(compat->submit.coef));
	compat->submit.bo_handles = (__c64_ptr64 __force)native->submit.bo_handles;
	compat->submit.bo_handle_count = native->submit.bo_handle_count;
	compat->submit.in_sync = native->submit.in_sync;
	compat->submit.out_sync = native->submit.out_sync;
	compat->submit.perfmon_id = native->submit.perfmon_id;
	compat->submit.extensions = (__c64_ptr64 __force)native->submit.extensions;
	compat->submit.flags = native->submit.flags;
	compat->submit.pad = native->submit.pad;
	compat->indirect = native->indirect;
	compat->offset = native->offset;
	compat->wg_size = native->wg_size;
	BUILD_BUG_ON(sizeof(native->wg_uniform_offsets) != sizeof(compat->wg_uniform_offsets));
	memcpy(&compat->wg_uniform_offsets, &native->wg_uniform_offsets, sizeof(compat->wg_uniform_offsets));
}
struct __c64_drm_v3d_timestamp_query {
	struct __c64_drm_v3d_extension base;

	/* Array of queries' offsets within the timestamp BO for their value */
	__c64_ptr64 offsets;

	/* Array of timestamp's syncobjs to indicate its availability */
	__c64_ptr64 syncs;

	/* Number of queries */
	__u32 count;

	/* mbz */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_timestamp_query(struct drm_v3d_timestamp_query *p)
{
	union {
		struct drm_v3d_timestamp_query native;
		const struct __c64_drm_v3d_timestamp_query compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.count = u->compat.count;
	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.offsets = (user_uintptr_t)compat_ptr(u->compat.offsets);
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_timestamp_query(struct drm_v3d_timestamp_query *p)
{
	union {
		struct __c64_drm_v3d_timestamp_query compat;
		const struct drm_v3d_timestamp_query native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.offsets = (__c64_ptr64 __force)u->native.offsets;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
	u->compat.count = u->native.count;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_timestamp_query_2(struct drm_v3d_timestamp_query *native, const struct __c64_drm_v3d_timestamp_query *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->offsets = (user_uintptr_t)compat_ptr(compat->offsets);
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
	native->count = compat->count;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_timestamp_query_2(struct __c64_drm_v3d_timestamp_query *compat, const struct drm_v3d_timestamp_query *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->offsets = (__c64_ptr64 __force)native->offsets;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
	compat->count = native->count;
	compat->pad = native->pad;
}
struct __c64_drm_v3d_reset_timestamp_query {
	struct __c64_drm_v3d_extension base;

	/* Array of timestamp's syncobjs to indicate its availability */
	__c64_ptr64 syncs;

	/* Offset of the first query within the timestamp BO for its value */
	__u32 offset;

	/* Number of queries */
	__u32 count;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_reset_timestamp_query(struct drm_v3d_reset_timestamp_query *p)
{
	union {
		struct drm_v3d_reset_timestamp_query native;
		const struct __c64_drm_v3d_reset_timestamp_query compat;
	} *u = (void *)p;

	u->native.count = u->compat.count;
	u->native.offset = u->compat.offset;
	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_reset_timestamp_query(struct drm_v3d_reset_timestamp_query *p)
{
	union {
		struct __c64_drm_v3d_reset_timestamp_query compat;
		const struct drm_v3d_reset_timestamp_query native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
	u->compat.offset = u->native.offset;
	u->compat.count = u->native.count;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_reset_timestamp_query_2(struct drm_v3d_reset_timestamp_query *native, const struct __c64_drm_v3d_reset_timestamp_query *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
	native->offset = compat->offset;
	native->count = compat->count;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_reset_timestamp_query_2(struct __c64_drm_v3d_reset_timestamp_query *compat, const struct drm_v3d_reset_timestamp_query *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
	compat->offset = native->offset;
	compat->count = native->count;
}
struct __c64_drm_v3d_copy_timestamp_query {
	struct __c64_drm_v3d_extension base;

	/* Define if should write to buffer using 64 or 32 bits */
	__u8 do_64bit;

	/* Define if it can write to buffer even if the query is not available */
	__u8 do_partial;

	/* Define if it should write availability bit to buffer */
	__u8 availability_bit;

	/* mbz */
	__u8 pad;

	/* Offset of the buffer in the BO */
	__u32 offset;

	/* Stride of the buffer in the BO */
	__u32 stride;

	/* Number of queries */
	__u32 count;

	/* Array of queries' offsets within the timestamp BO for their value */
	__c64_ptr64 offsets;

	/* Array of timestamp's syncobjs to indicate its availability */
	__c64_ptr64 syncs;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_copy_timestamp_query(struct drm_v3d_copy_timestamp_query *p)
{
	union {
		struct drm_v3d_copy_timestamp_query native;
		const struct __c64_drm_v3d_copy_timestamp_query compat;
	} *u = (void *)p;

	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.offsets = (user_uintptr_t)compat_ptr(u->compat.offsets);
	u->native.count = u->compat.count;
	u->native.stride = u->compat.stride;
	u->native.offset = u->compat.offset;
	u->native.pad = u->compat.pad;
	u->native.availability_bit = u->compat.availability_bit;
	u->native.do_partial = u->compat.do_partial;
	u->native.do_64bit = u->compat.do_64bit;
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_copy_timestamp_query(struct drm_v3d_copy_timestamp_query *p)
{
	union {
		struct __c64_drm_v3d_copy_timestamp_query compat;
		const struct drm_v3d_copy_timestamp_query native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.do_64bit = u->native.do_64bit;
	u->compat.do_partial = u->native.do_partial;
	u->compat.availability_bit = u->native.availability_bit;
	u->compat.pad = u->native.pad;
	u->compat.offset = u->native.offset;
	u->compat.stride = u->native.stride;
	u->compat.count = u->native.count;
	u->compat.offsets = (__c64_ptr64 __force)u->native.offsets;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_copy_timestamp_query_2(struct drm_v3d_copy_timestamp_query *native, const struct __c64_drm_v3d_copy_timestamp_query *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->do_64bit = compat->do_64bit;
	native->do_partial = compat->do_partial;
	native->availability_bit = compat->availability_bit;
	native->pad = compat->pad;
	native->offset = compat->offset;
	native->stride = compat->stride;
	native->count = compat->count;
	native->offsets = (user_uintptr_t)compat_ptr(compat->offsets);
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_copy_timestamp_query_2(struct __c64_drm_v3d_copy_timestamp_query *compat, const struct drm_v3d_copy_timestamp_query *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->do_64bit = native->do_64bit;
	compat->do_partial = native->do_partial;
	compat->availability_bit = native->availability_bit;
	compat->pad = native->pad;
	compat->offset = native->offset;
	compat->stride = native->stride;
	compat->count = native->count;
	compat->offsets = (__c64_ptr64 __force)native->offsets;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
}
struct __c64_drm_v3d_reset_performance_query {
	struct __c64_drm_v3d_extension base;

	/* Array of performance queries's syncobjs to indicate its availability */
	__c64_ptr64 syncs;

	/* Number of queries */
	__u32 count;

	/* Number of performance monitors */
	__u32 nperfmons;

	/* Array of u64 user-pointers that point to an array of kperfmon_ids */
	__c64_ptr64 kperfmon_ids;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_reset_performance_query(struct drm_v3d_reset_performance_query *p)
{
	union {
		struct drm_v3d_reset_performance_query native;
		const struct __c64_drm_v3d_reset_performance_query compat;
	} *u = (void *)p;

	u->native.kperfmon_ids = (user_uintptr_t)compat_ptr(u->compat.kperfmon_ids);
	u->native.nperfmons = u->compat.nperfmons;
	u->native.count = u->compat.count;
	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_reset_performance_query(struct drm_v3d_reset_performance_query *p)
{
	union {
		struct __c64_drm_v3d_reset_performance_query compat;
		const struct drm_v3d_reset_performance_query native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
	u->compat.count = u->native.count;
	u->compat.nperfmons = u->native.nperfmons;
	u->compat.kperfmon_ids = (__c64_ptr64 __force)u->native.kperfmon_ids;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_reset_performance_query_2(struct drm_v3d_reset_performance_query *native, const struct __c64_drm_v3d_reset_performance_query *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
	native->count = compat->count;
	native->nperfmons = compat->nperfmons;
	native->kperfmon_ids = (user_uintptr_t)compat_ptr(compat->kperfmon_ids);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_reset_performance_query_2(struct __c64_drm_v3d_reset_performance_query *compat, const struct drm_v3d_reset_performance_query *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
	compat->count = native->count;
	compat->nperfmons = native->nperfmons;
	compat->kperfmon_ids = (__c64_ptr64 __force)native->kperfmon_ids;
}
struct __c64_drm_v3d_copy_performance_query {
	struct __c64_drm_v3d_extension base;

	/* Define if should write to buffer using 64 or 32 bits */
	__u8 do_64bit;

	/* Define if it can write to buffer even if the query is not available */
	__u8 do_partial;

	/* Define if it should write availability bit to buffer */
	__u8 availability_bit;

	/* mbz */
	__u8 pad;

	/* Offset of the buffer in the BO */
	__u32 offset;

	/* Stride of the buffer in the BO */
	__u32 stride;

	/* Number of performance monitors */
	__u32 nperfmons;

	/* Number of performance counters related to this query pool */
	__u32 ncounters;

	/* Number of queries */
	__u32 count;

	/* Array of performance queries's syncobjs to indicate its availability */
	__c64_ptr64 syncs;

	/* Array of u64 user-pointers that point to an array of kperfmon_ids */
	__c64_ptr64 kperfmon_ids;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_copy_performance_query(struct drm_v3d_copy_performance_query *p)
{
	union {
		struct drm_v3d_copy_performance_query native;
		const struct __c64_drm_v3d_copy_performance_query compat;
	} *u = (void *)p;

	u->native.kperfmon_ids = (user_uintptr_t)compat_ptr(u->compat.kperfmon_ids);
	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.count = u->compat.count;
	u->native.ncounters = u->compat.ncounters;
	u->native.nperfmons = u->compat.nperfmons;
	u->native.stride = u->compat.stride;
	u->native.offset = u->compat.offset;
	u->native.pad = u->compat.pad;
	u->native.availability_bit = u->compat.availability_bit;
	u->native.do_partial = u->compat.do_partial;
	u->native.do_64bit = u->compat.do_64bit;
	u->native.base.flags = u->compat.base.flags;
	u->native.base.id = u->compat.base.id;
	u->native.base.next = (user_uintptr_t)compat_ptr(u->compat.base.next);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_copy_performance_query(struct drm_v3d_copy_performance_query *p)
{
	union {
		struct __c64_drm_v3d_copy_performance_query compat;
		const struct drm_v3d_copy_performance_query native;
	} *u = (void *)p;

	u->compat.base.next = (__c64_ptr64 __force)u->native.base.next;
	u->compat.base.id = u->native.base.id;
	u->compat.base.flags = u->native.base.flags;
	u->compat.do_64bit = u->native.do_64bit;
	u->compat.do_partial = u->native.do_partial;
	u->compat.availability_bit = u->native.availability_bit;
	u->compat.pad = u->native.pad;
	u->compat.offset = u->native.offset;
	u->compat.stride = u->native.stride;
	u->compat.nperfmons = u->native.nperfmons;
	u->compat.ncounters = u->native.ncounters;
	u->compat.count = u->native.count;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
	u->compat.kperfmon_ids = (__c64_ptr64 __force)u->native.kperfmon_ids;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_copy_performance_query_2(struct drm_v3d_copy_performance_query *native, const struct __c64_drm_v3d_copy_performance_query *compat)
{

	native->base.next = (user_uintptr_t)compat_ptr(compat->base.next);
	native->base.id = compat->base.id;
	native->base.flags = compat->base.flags;
	native->do_64bit = compat->do_64bit;
	native->do_partial = compat->do_partial;
	native->availability_bit = compat->availability_bit;
	native->pad = compat->pad;
	native->offset = compat->offset;
	native->stride = compat->stride;
	native->nperfmons = compat->nperfmons;
	native->ncounters = compat->ncounters;
	native->count = compat->count;
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
	native->kperfmon_ids = (user_uintptr_t)compat_ptr(compat->kperfmon_ids);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_copy_performance_query_2(struct __c64_drm_v3d_copy_performance_query *compat, const struct drm_v3d_copy_performance_query *native)
{

	compat->base.next = (__c64_ptr64 __force)native->base.next;
	compat->base.id = native->base.id;
	compat->base.flags = native->base.flags;
	compat->do_64bit = native->do_64bit;
	compat->do_partial = native->do_partial;
	compat->availability_bit = native->availability_bit;
	compat->pad = native->pad;
	compat->offset = native->offset;
	compat->stride = native->stride;
	compat->nperfmons = native->nperfmons;
	compat->ncounters = native->ncounters;
	compat->count = native->count;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
	compat->kperfmon_ids = (__c64_ptr64 __force)native->kperfmon_ids;
}
struct __c64_drm_v3d_submit_cpu {
	/* Pointer to a u32 array of the BOs that are referenced by the job.
	 *
	 * For DRM_V3D_EXT_ID_CPU_INDIRECT_CSD, it must contain only one BO,
	 * that contains the workgroup counts.
	 *
	 * For DRM_V3D_EXT_ID_TIMESTAMP_QUERY, it must contain only one BO,
	 * that will contain the timestamp.
	 *
	 * For DRM_V3D_EXT_ID_CPU_RESET_TIMESTAMP_QUERY, it must contain only
	 * one BO, that contains the timestamp.
	 *
	 * For DRM_V3D_EXT_ID_CPU_COPY_TIMESTAMP_QUERY, it must contain two
	 * BOs. The first is the BO where the timestamp queries will be written
	 * to. The second is the BO that contains the timestamp.
	 *
	 * For DRM_V3D_EXT_ID_CPU_RESET_PERFORMANCE_QUERY, it must contain no
	 * BOs.
	 *
	 * For DRM_V3D_EXT_ID_CPU_COPY_PERFORMANCE_QUERY, it must contain one
	 * BO, where the performance queries will be written.
	 */
	__c64_ptr64 bo_handles;

	/* Number of BO handles passed in (size is that times 4). */
	__u32 bo_handle_count;

	__u32 flags;

	/* Pointer to an array of ioctl extensions*/
	__c64_ptr64 extensions;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_cpu(struct drm_v3d_submit_cpu *p)
{
	union {
		struct drm_v3d_submit_cpu native;
		const struct __c64_drm_v3d_submit_cpu compat;
	} *u = (void *)p;

	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
	u->native.flags = u->compat.flags;
	u->native.bo_handle_count = u->compat.bo_handle_count;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_cpu(struct drm_v3d_submit_cpu *p)
{
	union {
		struct __c64_drm_v3d_submit_cpu compat;
		const struct drm_v3d_submit_cpu native;
	} *u = (void *)p;

	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.bo_handle_count = u->native.bo_handle_count;
	u->compat.flags = u->native.flags;
	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_submit_cpu_2(struct drm_v3d_submit_cpu *native, const struct __c64_drm_v3d_submit_cpu *compat)
{

	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->bo_handle_count = compat->bo_handle_count;
	native->flags = compat->flags;
	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_submit_cpu_2(struct __c64_drm_v3d_submit_cpu *compat, const struct drm_v3d_submit_cpu *native)
{

	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->bo_handle_count = native->bo_handle_count;
	compat->flags = native->flags;
	compat->extensions = (__c64_ptr64 __force)native->extensions;
}
struct __c64_drm_v3d_perfmon_get_values {
	__u32 id;
	__u32 pad;
	__c64_ptr64 values_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_v3d_perfmon_get_values(struct drm_v3d_perfmon_get_values *p)
{
	union {
		struct drm_v3d_perfmon_get_values native;
		const struct __c64_drm_v3d_perfmon_get_values compat;
	} *u = (void *)p;

	u->native.values_ptr = (user_uintptr_t)compat_ptr(u->compat.values_ptr);
	u->native.pad = u->compat.pad;
	u->native.id = u->compat.id;
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_perfmon_get_values(struct drm_v3d_perfmon_get_values *p)
{
	union {
		struct __c64_drm_v3d_perfmon_get_values compat;
		const struct drm_v3d_perfmon_get_values native;
	} *u = (void *)p;

	u->compat.id = u->native.id;
	u->compat.pad = u->native.pad;
	u->compat.values_ptr = (__c64_ptr64 __force)u->native.values_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_v3d_perfmon_get_values_2(struct drm_v3d_perfmon_get_values *native, const struct __c64_drm_v3d_perfmon_get_values *compat)
{

	native->id = compat->id;
	native->pad = compat->pad;
	native->values_ptr = (user_uintptr_t)compat_ptr(compat->values_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_v3d_perfmon_get_values_2(struct __c64_drm_v3d_perfmon_get_values *compat, const struct drm_v3d_perfmon_get_values *native)
{

	compat->id = native->id;
	compat->pad = native->pad;
	compat->values_ptr = (__c64_ptr64 __force)native->values_ptr;
}
