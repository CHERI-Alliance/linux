#pragma once


#include <linux/compat.h>


struct __c64_drm_vc4_submit_cl {
	/* Pointer to the binner command list.
	 *
	 * This is the first set of commands executed, which runs the
	 * coordinate shader to determine where primitives land on the screen,
	 * then writes out the state updates and draw calls necessary per tile
	 * to the tile allocation BO.
	 */
	__c64_ptr64 bin_cl;

	/* Pointer to the shader records.
	 *
	 * Shader records are the structures read by the hardware that contain
	 * pointers to uniforms, shaders, and vertex attributes.  The
	 * reference to the shader record has enough information to determine
	 * how many pointers are necessary (fixed number for shaders/uniforms,
	 * and an attribute count), so those BO indices into bo_handles are
	 * just stored as __u32s before each shader record passed in.
	 */
	__c64_ptr64 shader_rec;

	/* Pointer to uniform data and texture handles for the textures
	 * referenced by the shader.
	 *
	 * For each shader state record, there is a set of uniform data in the
	 * order referenced by the record (FS, VS, then CS).  Each set of
	 * uniform data has a __u32 index into bo_handles per texture
	 * sample operation, in the order the QPU_W_TMUn_S writes appear in
	 * the program.  Following the texture BO handle indices is the actual
	 * uniform data.
	 *
	 * The individual uniform state blocks don't have sizes passed in,
	 * because the kernel has to determine the sizes anyway during shader
	 * code validation.
	 */
	__c64_ptr64 uniforms;
	__c64_ptr64 bo_handles;

	/* Size in bytes of the binner command list. */
	__u32 bin_cl_size;
	/* Size in bytes of the set of shader records. */
	__u32 shader_rec_size;
	/* Number of shader records.
	 *
	 * This could just be computed from the contents of shader_records and
	 * the address bits of references to them from the bin CL, but it
	 * keeps the kernel from having to resize some allocations it makes.
	 */
	__u32 shader_rec_count;
	/* Size in bytes of the uniform state. */
	__u32 uniforms_size;

	/* Number of BO handles passed in (size is that times 4). */
	__u32 bo_handle_count;

	/* RCL setup: */
	__u16 width;
	__u16 height;
	__u8 min_x_tile;
	__u8 min_y_tile;
	__u8 max_x_tile;
	__u8 max_y_tile;
	struct drm_vc4_submit_rcl_surface color_read;
	struct drm_vc4_submit_rcl_surface color_write;
	struct drm_vc4_submit_rcl_surface zs_read;
	struct drm_vc4_submit_rcl_surface zs_write;
	struct drm_vc4_submit_rcl_surface msaa_color_write;
	struct drm_vc4_submit_rcl_surface msaa_zs_write;
	__u32 clear_color[2];
	__u32 clear_z;
	__u8 clear_s;

	__u32 pad:24;

/* By default, the kernel gets to choose the order that the tiles are
 * rendered in.  If this is set, then the tiles will be rendered in a
 * raster order, with the right-to-left vs left-to-right and
 * top-to-bottom vs bottom-to-top dictated by
 * VC4_SUBMIT_CL_RCL_ORDER_INCREASING_*.  This allows overlapping
 * blits to be implemented using the 3D engine.
 */
	__u32 flags;

	/* Returned value of the seqno of this render job (for the
	 * wait ioctl).
	 */
	__u64 seqno;

	/* ID of the perfmon to attach to this job. 0 means no perfmon. */
	__u32 perfmonid;

	/* Syncobj handle to wait on. If set, processing of this render job
	 * will not start until the syncobj is signaled. 0 means ignore.
	 */
	__u32 in_sync;

	/* Syncobj handle to export fence to. If set, the fence in the syncobj
	 * will be replaced with a fence that signals upon completion of this
	 * render job. 0 means ignore.
	 */
	__u32 out_sync;

	__u32 pad2;
};

static __always_inline __maybe_unused void
__from_c64_drm_vc4_submit_cl(struct drm_vc4_submit_cl *p)
{
	union {
		struct drm_vc4_submit_cl native;
		const struct __c64_drm_vc4_submit_cl compat;
	} *u = (void *)p;

	u->native.pad2 = u->compat.pad2;
	u->native.out_sync = u->compat.out_sync;
	u->native.in_sync = u->compat.in_sync;
	u->native.perfmonid = u->compat.perfmonid;
	u->native.seqno = u->compat.seqno;
	u->native.flags = u->compat.flags;
	u->native.pad = u->compat.pad;
	u->native.clear_s = u->compat.clear_s;
	u->native.clear_z = u->compat.clear_z;
	BUILD_BUG_ON(sizeof(u->compat.clear_color) != sizeof(u->native.clear_color));
	memmove(&u->native.clear_color, &u->compat.clear_color, sizeof(u->native.clear_color));
	BUILD_BUG_ON(sizeof(u->compat.msaa_zs_write) != sizeof(u->native.msaa_zs_write));
	memmove(&u->native.msaa_zs_write, &u->compat.msaa_zs_write, sizeof(u->native.msaa_zs_write));
	BUILD_BUG_ON(sizeof(u->compat.msaa_color_write) != sizeof(u->native.msaa_color_write));
	memmove(&u->native.msaa_color_write, &u->compat.msaa_color_write, sizeof(u->native.msaa_color_write));
	BUILD_BUG_ON(sizeof(u->compat.zs_write) != sizeof(u->native.zs_write));
	memmove(&u->native.zs_write, &u->compat.zs_write, sizeof(u->native.zs_write));
	BUILD_BUG_ON(sizeof(u->compat.zs_read) != sizeof(u->native.zs_read));
	memmove(&u->native.zs_read, &u->compat.zs_read, sizeof(u->native.zs_read));
	BUILD_BUG_ON(sizeof(u->compat.color_write) != sizeof(u->native.color_write));
	memmove(&u->native.color_write, &u->compat.color_write, sizeof(u->native.color_write));
	BUILD_BUG_ON(sizeof(u->compat.color_read) != sizeof(u->native.color_read));
	memmove(&u->native.color_read, &u->compat.color_read, sizeof(u->native.color_read));
	u->native.max_y_tile = u->compat.max_y_tile;
	u->native.max_x_tile = u->compat.max_x_tile;
	u->native.min_y_tile = u->compat.min_y_tile;
	u->native.min_x_tile = u->compat.min_x_tile;
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
	u->native.bo_handle_count = u->compat.bo_handle_count;
	u->native.uniforms_size = u->compat.uniforms_size;
	u->native.shader_rec_count = u->compat.shader_rec_count;
	u->native.shader_rec_size = u->compat.shader_rec_size;
	u->native.bin_cl_size = u->compat.bin_cl_size;
	u->native.bo_handles = (user_uintptr_t)compat_ptr(u->compat.bo_handles);
	u->native.uniforms = (user_uintptr_t)compat_ptr(u->compat.uniforms);
	u->native.shader_rec = (user_uintptr_t)compat_ptr(u->compat.shader_rec);
	u->native.bin_cl = (user_uintptr_t)compat_ptr(u->compat.bin_cl);
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_submit_cl(struct drm_vc4_submit_cl *p)
{
	union {
		struct __c64_drm_vc4_submit_cl compat;
		const struct drm_vc4_submit_cl native;
	} *u = (void *)p;

	u->compat.bin_cl = (__c64_ptr64 __force)u->native.bin_cl;
	u->compat.shader_rec = (__c64_ptr64 __force)u->native.shader_rec;
	u->compat.uniforms = (__c64_ptr64 __force)u->native.uniforms;
	u->compat.bo_handles = (__c64_ptr64 __force)u->native.bo_handles;
	u->compat.bin_cl_size = u->native.bin_cl_size;
	u->compat.shader_rec_size = u->native.shader_rec_size;
	u->compat.shader_rec_count = u->native.shader_rec_count;
	u->compat.uniforms_size = u->native.uniforms_size;
	u->compat.bo_handle_count = u->native.bo_handle_count;
	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.min_x_tile = u->native.min_x_tile;
	u->compat.min_y_tile = u->native.min_y_tile;
	u->compat.max_x_tile = u->native.max_x_tile;
	u->compat.max_y_tile = u->native.max_y_tile;
	BUILD_BUG_ON(sizeof(u->native.color_read) != sizeof(u->compat.color_read));
	memmove(&u->compat.color_read, &u->native.color_read, sizeof(u->compat.color_read));
	BUILD_BUG_ON(sizeof(u->native.color_write) != sizeof(u->compat.color_write));
	memmove(&u->compat.color_write, &u->native.color_write, sizeof(u->compat.color_write));
	BUILD_BUG_ON(sizeof(u->native.zs_read) != sizeof(u->compat.zs_read));
	memmove(&u->compat.zs_read, &u->native.zs_read, sizeof(u->compat.zs_read));
	BUILD_BUG_ON(sizeof(u->native.zs_write) != sizeof(u->compat.zs_write));
	memmove(&u->compat.zs_write, &u->native.zs_write, sizeof(u->compat.zs_write));
	BUILD_BUG_ON(sizeof(u->native.msaa_color_write) != sizeof(u->compat.msaa_color_write));
	memmove(&u->compat.msaa_color_write, &u->native.msaa_color_write, sizeof(u->compat.msaa_color_write));
	BUILD_BUG_ON(sizeof(u->native.msaa_zs_write) != sizeof(u->compat.msaa_zs_write));
	memmove(&u->compat.msaa_zs_write, &u->native.msaa_zs_write, sizeof(u->compat.msaa_zs_write));
	BUILD_BUG_ON(sizeof(u->native.clear_color) != sizeof(u->compat.clear_color));
	memmove(&u->compat.clear_color, &u->native.clear_color, sizeof(u->compat.clear_color));
	u->compat.clear_z = u->native.clear_z;
	u->compat.clear_s = u->native.clear_s;
	u->compat.pad = u->native.pad;
	u->compat.flags = u->native.flags;
	u->compat.seqno = u->native.seqno;
	u->compat.perfmonid = u->native.perfmonid;
	u->compat.in_sync = u->native.in_sync;
	u->compat.out_sync = u->native.out_sync;
	u->compat.pad2 = u->native.pad2;
}
static __always_inline __maybe_unused void
__from_c64_drm_vc4_submit_cl_2(struct drm_vc4_submit_cl *native, const struct __c64_drm_vc4_submit_cl *compat)
{

	native->bin_cl = (user_uintptr_t)compat_ptr(compat->bin_cl);
	native->shader_rec = (user_uintptr_t)compat_ptr(compat->shader_rec);
	native->uniforms = (user_uintptr_t)compat_ptr(compat->uniforms);
	native->bo_handles = (user_uintptr_t)compat_ptr(compat->bo_handles);
	native->bin_cl_size = compat->bin_cl_size;
	native->shader_rec_size = compat->shader_rec_size;
	native->shader_rec_count = compat->shader_rec_count;
	native->uniforms_size = compat->uniforms_size;
	native->bo_handle_count = compat->bo_handle_count;
	native->width = compat->width;
	native->height = compat->height;
	native->min_x_tile = compat->min_x_tile;
	native->min_y_tile = compat->min_y_tile;
	native->max_x_tile = compat->max_x_tile;
	native->max_y_tile = compat->max_y_tile;
	BUILD_BUG_ON(sizeof(compat->color_read) != sizeof(native->color_read));
	memcpy(&native->color_read, &compat->color_read, sizeof(native->color_read));
	BUILD_BUG_ON(sizeof(compat->color_write) != sizeof(native->color_write));
	memcpy(&native->color_write, &compat->color_write, sizeof(native->color_write));
	BUILD_BUG_ON(sizeof(compat->zs_read) != sizeof(native->zs_read));
	memcpy(&native->zs_read, &compat->zs_read, sizeof(native->zs_read));
	BUILD_BUG_ON(sizeof(compat->zs_write) != sizeof(native->zs_write));
	memcpy(&native->zs_write, &compat->zs_write, sizeof(native->zs_write));
	BUILD_BUG_ON(sizeof(compat->msaa_color_write) != sizeof(native->msaa_color_write));
	memcpy(&native->msaa_color_write, &compat->msaa_color_write, sizeof(native->msaa_color_write));
	BUILD_BUG_ON(sizeof(compat->msaa_zs_write) != sizeof(native->msaa_zs_write));
	memcpy(&native->msaa_zs_write, &compat->msaa_zs_write, sizeof(native->msaa_zs_write));
	BUILD_BUG_ON(sizeof(compat->clear_color) != sizeof(native->clear_color));
	memcpy(&native->clear_color, &compat->clear_color, sizeof(native->clear_color));
	native->clear_z = compat->clear_z;
	native->clear_s = compat->clear_s;
	native->pad = compat->pad;
	native->flags = compat->flags;
	native->seqno = compat->seqno;
	native->perfmonid = compat->perfmonid;
	native->in_sync = compat->in_sync;
	native->out_sync = compat->out_sync;
	native->pad2 = compat->pad2;
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_submit_cl_2(struct __c64_drm_vc4_submit_cl *compat, const struct drm_vc4_submit_cl *native)
{

	compat->bin_cl = (__c64_ptr64 __force)native->bin_cl;
	compat->shader_rec = (__c64_ptr64 __force)native->shader_rec;
	compat->uniforms = (__c64_ptr64 __force)native->uniforms;
	compat->bo_handles = (__c64_ptr64 __force)native->bo_handles;
	compat->bin_cl_size = native->bin_cl_size;
	compat->shader_rec_size = native->shader_rec_size;
	compat->shader_rec_count = native->shader_rec_count;
	compat->uniforms_size = native->uniforms_size;
	compat->bo_handle_count = native->bo_handle_count;
	compat->width = native->width;
	compat->height = native->height;
	compat->min_x_tile = native->min_x_tile;
	compat->min_y_tile = native->min_y_tile;
	compat->max_x_tile = native->max_x_tile;
	compat->max_y_tile = native->max_y_tile;
	BUILD_BUG_ON(sizeof(native->color_read) != sizeof(compat->color_read));
	memcpy(&compat->color_read, &native->color_read, sizeof(compat->color_read));
	BUILD_BUG_ON(sizeof(native->color_write) != sizeof(compat->color_write));
	memcpy(&compat->color_write, &native->color_write, sizeof(compat->color_write));
	BUILD_BUG_ON(sizeof(native->zs_read) != sizeof(compat->zs_read));
	memcpy(&compat->zs_read, &native->zs_read, sizeof(compat->zs_read));
	BUILD_BUG_ON(sizeof(native->zs_write) != sizeof(compat->zs_write));
	memcpy(&compat->zs_write, &native->zs_write, sizeof(compat->zs_write));
	BUILD_BUG_ON(sizeof(native->msaa_color_write) != sizeof(compat->msaa_color_write));
	memcpy(&compat->msaa_color_write, &native->msaa_color_write, sizeof(compat->msaa_color_write));
	BUILD_BUG_ON(sizeof(native->msaa_zs_write) != sizeof(compat->msaa_zs_write));
	memcpy(&compat->msaa_zs_write, &native->msaa_zs_write, sizeof(compat->msaa_zs_write));
	BUILD_BUG_ON(sizeof(native->clear_color) != sizeof(compat->clear_color));
	memcpy(&compat->clear_color, &native->clear_color, sizeof(compat->clear_color));
	compat->clear_z = native->clear_z;
	compat->clear_s = native->clear_s;
	compat->pad = native->pad;
	compat->flags = native->flags;
	compat->seqno = native->seqno;
	compat->perfmonid = native->perfmonid;
	compat->in_sync = native->in_sync;
	compat->out_sync = native->out_sync;
	compat->pad2 = native->pad2;
}
struct __c64_drm_vc4_create_shader_bo {
	/* Size of the data argument. */
	__u32 size;
	/* Flags, currently must be 0. */
	__u32 flags;

	/* Pointer to the data. */
	__c64_ptr64 data;

	/** Returned GEM handle for the BO. */
	__u32 handle;
	/* Pad, must be 0. */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_vc4_create_shader_bo(struct drm_vc4_create_shader_bo *p)
{
	union {
		struct drm_vc4_create_shader_bo native;
		const struct __c64_drm_vc4_create_shader_bo compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.handle = u->compat.handle;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_create_shader_bo(struct drm_vc4_create_shader_bo *p)
{
	union {
		struct __c64_drm_vc4_create_shader_bo compat;
		const struct drm_vc4_create_shader_bo native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.handle = u->native.handle;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_vc4_create_shader_bo_2(struct drm_vc4_create_shader_bo *native, const struct __c64_drm_vc4_create_shader_bo *compat)
{

	native->size = compat->size;
	native->flags = compat->flags;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->handle = compat->handle;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_create_shader_bo_2(struct __c64_drm_vc4_create_shader_bo *compat, const struct drm_vc4_create_shader_bo *native)
{

	compat->size = native->size;
	compat->flags = native->flags;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->handle = native->handle;
	compat->pad = native->pad;
}
struct __c64_drm_vc4_get_hang_state {
	/** Pointer to array of struct drm_vc4_get_hang_state_bo. */
	__c64_ptr64 bo;
	/**
	 * On input, the size of the bo array.  Output is the number
	 * of bos to be returned.
	 */
	__u32 bo_count;

	__u32 start_bin, start_render;

	__u32 ct0ca, ct0ea;
	__u32 ct1ca, ct1ea;
	__u32 ct0cs, ct1cs;
	__u32 ct0ra0, ct1ra0;

	__u32 bpca, bpcs;
	__u32 bpoa, bpos;

	__u32 vpmbase;

	__u32 dbge;
	__u32 fdbgo;
	__u32 fdbgb;
	__u32 fdbgr;
	__u32 fdbgs;
	__u32 errstat;

	/* Pad that we may save more registers into in the future. */
	__u32 pad[16];
};

static __always_inline __maybe_unused void
__from_c64_drm_vc4_get_hang_state(struct drm_vc4_get_hang_state *p)
{
	union {
		struct drm_vc4_get_hang_state native;
		const struct __c64_drm_vc4_get_hang_state compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.pad) != sizeof(u->native.pad));
	memmove(&u->native.pad, &u->compat.pad, sizeof(u->native.pad));
	u->native.errstat = u->compat.errstat;
	u->native.fdbgs = u->compat.fdbgs;
	u->native.fdbgr = u->compat.fdbgr;
	u->native.fdbgb = u->compat.fdbgb;
	u->native.fdbgo = u->compat.fdbgo;
	u->native.dbge = u->compat.dbge;
	u->native.vpmbase = u->compat.vpmbase;
	u->native.bpos = u->compat.bpos;
	u->native.bpoa = u->compat.bpoa;
	u->native.bpcs = u->compat.bpcs;
	u->native.bpca = u->compat.bpca;
	u->native.ct1ra0 = u->compat.ct1ra0;
	u->native.ct0ra0 = u->compat.ct0ra0;
	u->native.ct1cs = u->compat.ct1cs;
	u->native.ct0cs = u->compat.ct0cs;
	u->native.ct1ea = u->compat.ct1ea;
	u->native.ct1ca = u->compat.ct1ca;
	u->native.ct0ea = u->compat.ct0ea;
	u->native.ct0ca = u->compat.ct0ca;
	u->native.start_render = u->compat.start_render;
	u->native.start_bin = u->compat.start_bin;
	u->native.bo_count = u->compat.bo_count;
	u->native.bo = (user_uintptr_t)compat_ptr(u->compat.bo);
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_get_hang_state(struct drm_vc4_get_hang_state *p)
{
	union {
		struct __c64_drm_vc4_get_hang_state compat;
		const struct drm_vc4_get_hang_state native;
	} *u = (void *)p;

	u->compat.bo = (__c64_ptr64 __force)u->native.bo;
	u->compat.bo_count = u->native.bo_count;
	u->compat.start_bin = u->native.start_bin;
	u->compat.start_render = u->native.start_render;
	u->compat.ct0ca = u->native.ct0ca;
	u->compat.ct0ea = u->native.ct0ea;
	u->compat.ct1ca = u->native.ct1ca;
	u->compat.ct1ea = u->native.ct1ea;
	u->compat.ct0cs = u->native.ct0cs;
	u->compat.ct1cs = u->native.ct1cs;
	u->compat.ct0ra0 = u->native.ct0ra0;
	u->compat.ct1ra0 = u->native.ct1ra0;
	u->compat.bpca = u->native.bpca;
	u->compat.bpcs = u->native.bpcs;
	u->compat.bpoa = u->native.bpoa;
	u->compat.bpos = u->native.bpos;
	u->compat.vpmbase = u->native.vpmbase;
	u->compat.dbge = u->native.dbge;
	u->compat.fdbgo = u->native.fdbgo;
	u->compat.fdbgb = u->native.fdbgb;
	u->compat.fdbgr = u->native.fdbgr;
	u->compat.fdbgs = u->native.fdbgs;
	u->compat.errstat = u->native.errstat;
	BUILD_BUG_ON(sizeof(u->native.pad) != sizeof(u->compat.pad));
	memmove(&u->compat.pad, &u->native.pad, sizeof(u->compat.pad));
}
static __always_inline __maybe_unused void
__from_c64_drm_vc4_get_hang_state_2(struct drm_vc4_get_hang_state *native, const struct __c64_drm_vc4_get_hang_state *compat)
{

	native->bo = (user_uintptr_t)compat_ptr(compat->bo);
	native->bo_count = compat->bo_count;
	native->start_bin = compat->start_bin;
	native->start_render = compat->start_render;
	native->ct0ca = compat->ct0ca;
	native->ct0ea = compat->ct0ea;
	native->ct1ca = compat->ct1ca;
	native->ct1ea = compat->ct1ea;
	native->ct0cs = compat->ct0cs;
	native->ct1cs = compat->ct1cs;
	native->ct0ra0 = compat->ct0ra0;
	native->ct1ra0 = compat->ct1ra0;
	native->bpca = compat->bpca;
	native->bpcs = compat->bpcs;
	native->bpoa = compat->bpoa;
	native->bpos = compat->bpos;
	native->vpmbase = compat->vpmbase;
	native->dbge = compat->dbge;
	native->fdbgo = compat->fdbgo;
	native->fdbgb = compat->fdbgb;
	native->fdbgr = compat->fdbgr;
	native->fdbgs = compat->fdbgs;
	native->errstat = compat->errstat;
	BUILD_BUG_ON(sizeof(compat->pad) != sizeof(native->pad));
	memcpy(&native->pad, &compat->pad, sizeof(native->pad));
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_get_hang_state_2(struct __c64_drm_vc4_get_hang_state *compat, const struct drm_vc4_get_hang_state *native)
{

	compat->bo = (__c64_ptr64 __force)native->bo;
	compat->bo_count = native->bo_count;
	compat->start_bin = native->start_bin;
	compat->start_render = native->start_render;
	compat->ct0ca = native->ct0ca;
	compat->ct0ea = native->ct0ea;
	compat->ct1ca = native->ct1ca;
	compat->ct1ea = native->ct1ea;
	compat->ct0cs = native->ct0cs;
	compat->ct1cs = native->ct1cs;
	compat->ct0ra0 = native->ct0ra0;
	compat->ct1ra0 = native->ct1ra0;
	compat->bpca = native->bpca;
	compat->bpcs = native->bpcs;
	compat->bpoa = native->bpoa;
	compat->bpos = native->bpos;
	compat->vpmbase = native->vpmbase;
	compat->dbge = native->dbge;
	compat->fdbgo = native->fdbgo;
	compat->fdbgb = native->fdbgb;
	compat->fdbgr = native->fdbgr;
	compat->fdbgs = native->fdbgs;
	compat->errstat = native->errstat;
	BUILD_BUG_ON(sizeof(native->pad) != sizeof(compat->pad));
	memcpy(&compat->pad, &native->pad, sizeof(compat->pad));
}
struct __c64_drm_vc4_label_bo {
	__u32 handle;
	__u32 len;
	__c64_ptr64 name;
};

static __always_inline __maybe_unused void
__from_c64_drm_vc4_label_bo(struct drm_vc4_label_bo *p)
{
	union {
		struct drm_vc4_label_bo native;
		const struct __c64_drm_vc4_label_bo compat;
	} *u = (void *)p;

	u->native.name = (user_uintptr_t)compat_ptr(u->compat.name);
	u->native.len = u->compat.len;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_label_bo(struct drm_vc4_label_bo *p)
{
	union {
		struct __c64_drm_vc4_label_bo compat;
		const struct drm_vc4_label_bo native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat.len = u->native.len;
	u->compat.name = (__c64_ptr64 __force)u->native.name;
}
static __always_inline __maybe_unused void
__from_c64_drm_vc4_label_bo_2(struct drm_vc4_label_bo *native, const struct __c64_drm_vc4_label_bo *compat)
{

	native->handle = compat->handle;
	native->len = compat->len;
	native->name = (user_uintptr_t)compat_ptr(compat->name);
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_label_bo_2(struct __c64_drm_vc4_label_bo *compat, const struct drm_vc4_label_bo *native)
{

	compat->handle = native->handle;
	compat->len = native->len;
	compat->name = (__c64_ptr64 __force)native->name;
}
struct __c64_drm_vc4_perfmon_get_values {
	__u32 id;
	__c64_ptr64 values_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_vc4_perfmon_get_values(struct drm_vc4_perfmon_get_values *p)
{
	union {
		struct drm_vc4_perfmon_get_values native;
		const struct __c64_drm_vc4_perfmon_get_values compat;
	} *u = (void *)p;

	u->native.values_ptr = (user_uintptr_t)compat_ptr(u->compat.values_ptr);
	u->native.id = u->compat.id;
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_perfmon_get_values(struct drm_vc4_perfmon_get_values *p)
{
	union {
		struct __c64_drm_vc4_perfmon_get_values compat;
		const struct drm_vc4_perfmon_get_values native;
	} *u = (void *)p;

	u->compat.id = u->native.id;
	u->compat.values_ptr = (__c64_ptr64 __force)u->native.values_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_vc4_perfmon_get_values_2(struct drm_vc4_perfmon_get_values *native, const struct __c64_drm_vc4_perfmon_get_values *compat)
{

	native->id = compat->id;
	native->values_ptr = (user_uintptr_t)compat_ptr(compat->values_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_vc4_perfmon_get_values_2(struct __c64_drm_vc4_perfmon_get_values *compat, const struct drm_vc4_perfmon_get_values *native)
{

	compat->id = native->id;
	compat->values_ptr = (__c64_ptr64 __force)native->values_ptr;
}
