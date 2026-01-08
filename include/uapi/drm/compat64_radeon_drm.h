#pragma once


#include <linux/compat.h>


typedef struct __c64_drm_radeon_clear {
	unsigned int flags;
	unsigned int clear_color;
	unsigned int clear_depth;
	unsigned int color_mask;
	unsigned int depth_mask;	/* misnamed field:  should be stencil */
	__c64_uptr depth_boxes;
} __c64_drm_radeon_clear_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_clear(struct drm_radeon_clear *p)
{
	union {
		struct drm_radeon_clear native;
		const struct __c64_drm_radeon_clear compat;
	} *u = (void *)p;

	u->native.depth_boxes =  compat_ptr(u->compat.depth_boxes);
	u->native.depth_mask = u->compat.depth_mask;
	u->native.color_mask = u->compat.color_mask;
	u->native.clear_depth = u->compat.clear_depth;
	u->native.clear_color = u->compat.clear_color;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_clear(struct drm_radeon_clear *p)
{
	union {
		struct __c64_drm_radeon_clear compat;
		const struct drm_radeon_clear native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.clear_color = u->native.clear_color;
	u->compat.clear_depth = u->native.clear_depth;
	u->compat.color_mask = u->native.color_mask;
	u->compat.depth_mask = u->native.depth_mask;
	u->compat.depth_boxes =  (__c64_uptr __force)(user_uintptr_t)u->native.depth_boxes;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_clear_2(struct drm_radeon_clear *native, const struct __c64_drm_radeon_clear *compat)
{

	native->flags = compat->flags;
	native->clear_color = compat->clear_color;
	native->clear_depth = compat->clear_depth;
	native->color_mask = compat->color_mask;
	native->depth_mask = compat->depth_mask;
	native->depth_boxes =  compat_ptr(compat->depth_boxes);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_clear_2(struct __c64_drm_radeon_clear *compat, const struct drm_radeon_clear *native)
{

	compat->flags = native->flags;
	compat->clear_color = native->clear_color;
	compat->clear_depth = native->clear_depth;
	compat->color_mask = native->color_mask;
	compat->depth_mask = native->depth_mask;
	compat->depth_boxes =  (__c64_uptr __force)(user_uintptr_t)native->depth_boxes;
}
typedef struct __c64_drm_radeon_vertex2 {
	int idx;		/* Index of vertex buffer */
	int discard;		/* Client finished with buffer? */
	int nr_states;
	__c64_uptr state;
	int nr_prims;
	__c64_uptr prim;
} __c64_drm_radeon_vertex2_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_vertex2(struct drm_radeon_vertex2 *p)
{
	union {
		struct drm_radeon_vertex2 native;
		const struct __c64_drm_radeon_vertex2 compat;
	} *u = (void *)p;

	u->native.prim =  compat_ptr(u->compat.prim);
	u->native.nr_prims = u->compat.nr_prims;
	u->native.state =  compat_ptr(u->compat.state);
	u->native.nr_states = u->compat.nr_states;
	u->native.discard = u->compat.discard;
	u->native.idx = u->compat.idx;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_vertex2(struct drm_radeon_vertex2 *p)
{
	union {
		struct __c64_drm_radeon_vertex2 compat;
		const struct drm_radeon_vertex2 native;
	} *u = (void *)p;

	u->compat.idx = u->native.idx;
	u->compat.discard = u->native.discard;
	u->compat.nr_states = u->native.nr_states;
	u->compat.state =  (__c64_uptr __force)(user_uintptr_t)u->native.state;
	u->compat.nr_prims = u->native.nr_prims;
	u->compat.prim =  (__c64_uptr __force)(user_uintptr_t)u->native.prim;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_vertex2_2(struct drm_radeon_vertex2 *native, const struct __c64_drm_radeon_vertex2 *compat)
{

	native->idx = compat->idx;
	native->discard = compat->discard;
	native->nr_states = compat->nr_states;
	native->state =  compat_ptr(compat->state);
	native->nr_prims = compat->nr_prims;
	native->prim =  compat_ptr(compat->prim);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_vertex2_2(struct __c64_drm_radeon_vertex2 *compat, const struct drm_radeon_vertex2 *native)
{

	compat->idx = native->idx;
	compat->discard = native->discard;
	compat->nr_states = native->nr_states;
	compat->state =  (__c64_uptr __force)(user_uintptr_t)native->state;
	compat->nr_prims = native->nr_prims;
	compat->prim =  (__c64_uptr __force)(user_uintptr_t)native->prim;
}
typedef struct __c64_drm_radeon_cmd_buffer {
	int bufsz;
	__c64_uptr buf;
	int nbox;
	__c64_uptr boxes;
} __c64_drm_radeon_cmd_buffer_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_cmd_buffer(struct drm_radeon_cmd_buffer *p)
{
	union {
		struct drm_radeon_cmd_buffer native;
		const struct __c64_drm_radeon_cmd_buffer compat;
	} *u = (void *)p;

	u->native.boxes =  compat_ptr(u->compat.boxes);
	u->native.nbox = u->compat.nbox;
	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.bufsz = u->compat.bufsz;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cmd_buffer(struct drm_radeon_cmd_buffer *p)
{
	union {
		struct __c64_drm_radeon_cmd_buffer compat;
		const struct drm_radeon_cmd_buffer native;
	} *u = (void *)p;

	u->compat.bufsz = u->native.bufsz;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
	u->compat.nbox = u->native.nbox;
	u->compat.boxes =  (__c64_uptr __force)(user_uintptr_t)u->native.boxes;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_cmd_buffer_2(struct drm_radeon_cmd_buffer *native, const struct __c64_drm_radeon_cmd_buffer *compat)
{

	native->bufsz = compat->bufsz;
	native->buf =  compat_ptr(compat->buf);
	native->nbox = compat->nbox;
	native->boxes =  compat_ptr(compat->boxes);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cmd_buffer_2(struct __c64_drm_radeon_cmd_buffer *compat, const struct drm_radeon_cmd_buffer *native)
{

	compat->bufsz = native->bufsz;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
	compat->nbox = native->nbox;
	compat->boxes =  (__c64_uptr __force)(user_uintptr_t)native->boxes;
}
typedef struct __c64_drm_radeon_tex_image {
	unsigned int x, y;	/* Blit coordinates */
	unsigned int width, height;
	__c64_uptr data;
} __c64_drm_radeon_tex_image_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_tex_image(struct drm_radeon_tex_image *p)
{
	union {
		struct drm_radeon_tex_image native;
		const struct __c64_drm_radeon_tex_image compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
	u->native.y = u->compat.y;
	u->native.x = u->compat.x;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_tex_image(struct drm_radeon_tex_image *p)
{
	union {
		struct __c64_drm_radeon_tex_image compat;
		const struct drm_radeon_tex_image native;
	} *u = (void *)p;

	u->compat.x = u->native.x;
	u->compat.y = u->native.y;
	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_tex_image_2(struct drm_radeon_tex_image *native, const struct __c64_drm_radeon_tex_image *compat)
{

	native->x = compat->x;
	native->y = compat->y;
	native->width = compat->width;
	native->height = compat->height;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_tex_image_2(struct __c64_drm_radeon_tex_image *compat, const struct drm_radeon_tex_image *native)
{

	compat->x = native->x;
	compat->y = native->y;
	compat->width = native->width;
	compat->height = native->height;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
typedef struct __c64_drm_radeon_texture {
	unsigned int offset;
	int pitch;
	int format;
	int width;		/* Texture image coordinates */
	int height;
	__c64_uptr image;
} __c64_drm_radeon_texture_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_texture(struct drm_radeon_texture *p)
{
	union {
		struct drm_radeon_texture native;
		const struct __c64_drm_radeon_texture compat;
	} *u = (void *)p;

	u->native.image =  compat_ptr(u->compat.image);
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
	u->native.format = u->compat.format;
	u->native.pitch = u->compat.pitch;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_texture(struct drm_radeon_texture *p)
{
	union {
		struct __c64_drm_radeon_texture compat;
		const struct drm_radeon_texture native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.pitch = u->native.pitch;
	u->compat.format = u->native.format;
	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.image =  (__c64_uptr __force)(user_uintptr_t)u->native.image;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_texture_2(struct drm_radeon_texture *native, const struct __c64_drm_radeon_texture *compat)
{

	native->offset = compat->offset;
	native->pitch = compat->pitch;
	native->format = compat->format;
	native->width = compat->width;
	native->height = compat->height;
	native->image =  compat_ptr(compat->image);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_texture_2(struct __c64_drm_radeon_texture *compat, const struct drm_radeon_texture *native)
{

	compat->offset = native->offset;
	compat->pitch = native->pitch;
	compat->format = native->format;
	compat->width = native->width;
	compat->height = native->height;
	compat->image =  (__c64_uptr __force)(user_uintptr_t)native->image;
}
typedef struct __c64_drm_radeon_stipple {
	__c64_uptr mask;
} __c64_drm_radeon_stipple_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_stipple(struct drm_radeon_stipple *p)
{
	union {
		struct drm_radeon_stipple native;
		const struct __c64_drm_radeon_stipple compat;
	} *u = (void *)p;

	u->native.mask =  compat_ptr(u->compat.mask);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_stipple(struct drm_radeon_stipple *p)
{
	union {
		struct __c64_drm_radeon_stipple compat;
		const struct drm_radeon_stipple native;
	} *u = (void *)p;

	u->compat.mask =  (__c64_uptr __force)(user_uintptr_t)u->native.mask;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_stipple_2(struct drm_radeon_stipple *native, const struct __c64_drm_radeon_stipple *compat)
{

	native->mask =  compat_ptr(compat->mask);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_stipple_2(struct __c64_drm_radeon_stipple *compat, const struct drm_radeon_stipple *native)
{

	compat->mask =  (__c64_uptr __force)(user_uintptr_t)native->mask;
}
typedef struct __c64_drm_radeon_getparam {
	int param;
	__c64_uptr value;
} __c64_drm_radeon_getparam_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_getparam(struct drm_radeon_getparam *p)
{
	union {
		struct drm_radeon_getparam native;
		const struct __c64_drm_radeon_getparam compat;
	} *u = (void *)p;

	u->native.value =  compat_ptr(u->compat.value);
	u->native.param = u->compat.param;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_getparam(struct drm_radeon_getparam *p)
{
	union {
		struct __c64_drm_radeon_getparam compat;
		const struct drm_radeon_getparam native;
	} *u = (void *)p;

	u->compat.param = u->native.param;
	u->compat.value =  (__c64_uptr __force)(user_uintptr_t)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_getparam_2(struct drm_radeon_getparam *native, const struct __c64_drm_radeon_getparam *compat)
{

	native->param = compat->param;
	native->value =  compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_getparam_2(struct __c64_drm_radeon_getparam *compat, const struct drm_radeon_getparam *native)
{

	compat->param = native->param;
	compat->value =  (__c64_uptr __force)(user_uintptr_t)native->value;
}
typedef struct __c64_drm_radeon_mem_alloc {
	int region;
	int alignment;
	int size;
	__c64_uptr region_offset;	/* offset from start of fb or GART */
} __c64_drm_radeon_mem_alloc_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_mem_alloc(struct drm_radeon_mem_alloc *p)
{
	union {
		struct drm_radeon_mem_alloc native;
		const struct __c64_drm_radeon_mem_alloc compat;
	} *u = (void *)p;

	u->native.region_offset =  compat_ptr(u->compat.region_offset);
	u->native.size = u->compat.size;
	u->native.alignment = u->compat.alignment;
	u->native.region = u->compat.region;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_mem_alloc(struct drm_radeon_mem_alloc *p)
{
	union {
		struct __c64_drm_radeon_mem_alloc compat;
		const struct drm_radeon_mem_alloc native;
	} *u = (void *)p;

	u->compat.region = u->native.region;
	u->compat.alignment = u->native.alignment;
	u->compat.size = u->native.size;
	u->compat.region_offset =  (__c64_uptr __force)(user_uintptr_t)u->native.region_offset;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_mem_alloc_2(struct drm_radeon_mem_alloc *native, const struct __c64_drm_radeon_mem_alloc *compat)
{

	native->region = compat->region;
	native->alignment = compat->alignment;
	native->size = compat->size;
	native->region_offset =  compat_ptr(compat->region_offset);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_mem_alloc_2(struct __c64_drm_radeon_mem_alloc *compat, const struct drm_radeon_mem_alloc *native)
{

	compat->region = native->region;
	compat->alignment = native->alignment;
	compat->size = native->size;
	compat->region_offset =  (__c64_uptr __force)(user_uintptr_t)native->region_offset;
}
typedef struct __c64_drm_radeon_irq_emit {
	__c64_uptr irq_seq;
} __c64_drm_radeon_irq_emit_t;

static __always_inline __maybe_unused void
__from_c64_drm_radeon_irq_emit(struct drm_radeon_irq_emit *p)
{
	union {
		struct drm_radeon_irq_emit native;
		const struct __c64_drm_radeon_irq_emit compat;
	} *u = (void *)p;

	u->native.irq_seq =  compat_ptr(u->compat.irq_seq);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_irq_emit(struct drm_radeon_irq_emit *p)
{
	union {
		struct __c64_drm_radeon_irq_emit compat;
		const struct drm_radeon_irq_emit native;
	} *u = (void *)p;

	u->compat.irq_seq =  (__c64_uptr __force)(user_uintptr_t)u->native.irq_seq;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_irq_emit_2(struct drm_radeon_irq_emit *native, const struct __c64_drm_radeon_irq_emit *compat)
{

	native->irq_seq =  compat_ptr(compat->irq_seq);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_irq_emit_2(struct __c64_drm_radeon_irq_emit *compat, const struct drm_radeon_irq_emit *native)
{

	compat->irq_seq =  (__c64_uptr __force)(user_uintptr_t)native->irq_seq;
}
struct __c64_drm_radeon_cs_chunk {
	__u32		chunk_id;
	__u32		length_dw;
	__c64_ptr64	chunk_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_radeon_cs_chunk(struct drm_radeon_cs_chunk *p)
{
	union {
		struct drm_radeon_cs_chunk native;
		const struct __c64_drm_radeon_cs_chunk compat;
	} *u = (void *)p;

	u->native.chunk_data = (user_uintptr_t)compat_ptr(u->compat.chunk_data);
	u->native.length_dw = u->compat.length_dw;
	u->native.chunk_id = u->compat.chunk_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cs_chunk(struct drm_radeon_cs_chunk *p)
{
	union {
		struct __c64_drm_radeon_cs_chunk compat;
		const struct drm_radeon_cs_chunk native;
	} *u = (void *)p;

	u->compat.chunk_id = u->native.chunk_id;
	u->compat.length_dw = u->native.length_dw;
	u->compat.chunk_data = (__c64_ptr64 __force)u->native.chunk_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_cs_chunk_2(struct drm_radeon_cs_chunk *native, const struct __c64_drm_radeon_cs_chunk *compat)
{

	native->chunk_id = compat->chunk_id;
	native->length_dw = compat->length_dw;
	native->chunk_data = (user_uintptr_t)compat_ptr(compat->chunk_data);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cs_chunk_2(struct __c64_drm_radeon_cs_chunk *compat, const struct drm_radeon_cs_chunk *native)
{

	compat->chunk_id = native->chunk_id;
	compat->length_dw = native->length_dw;
	compat->chunk_data = (__c64_ptr64 __force)native->chunk_data;
}
struct __c64_drm_radeon_cs {
	__u32		num_chunks;
	__u32		cs_id;
	/* this points to __u64 * which point to cs chunks */
	__c64_ptr64	chunks;
	/* updates to the limits after this CS ioctl */
	__u64		gart_limit;
	__u64		vram_limit;
};

static __always_inline __maybe_unused void
__from_c64_drm_radeon_cs(struct drm_radeon_cs *p)
{
	union {
		struct drm_radeon_cs native;
		const struct __c64_drm_radeon_cs compat;
	} *u = (void *)p;

	u->native.vram_limit = u->compat.vram_limit;
	u->native.gart_limit = u->compat.gart_limit;
	u->native.chunks = (user_uintptr_t)compat_ptr(u->compat.chunks);
	u->native.cs_id = u->compat.cs_id;
	u->native.num_chunks = u->compat.num_chunks;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cs(struct drm_radeon_cs *p)
{
	union {
		struct __c64_drm_radeon_cs compat;
		const struct drm_radeon_cs native;
	} *u = (void *)p;

	u->compat.num_chunks = u->native.num_chunks;
	u->compat.cs_id = u->native.cs_id;
	u->compat.chunks = (__c64_ptr64 __force)u->native.chunks;
	u->compat.gart_limit = u->native.gart_limit;
	u->compat.vram_limit = u->native.vram_limit;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_cs_2(struct drm_radeon_cs *native, const struct __c64_drm_radeon_cs *compat)
{

	native->num_chunks = compat->num_chunks;
	native->cs_id = compat->cs_id;
	native->chunks = (user_uintptr_t)compat_ptr(compat->chunks);
	native->gart_limit = compat->gart_limit;
	native->vram_limit = compat->vram_limit;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_cs_2(struct __c64_drm_radeon_cs *compat, const struct drm_radeon_cs *native)
{

	compat->num_chunks = native->num_chunks;
	compat->cs_id = native->cs_id;
	compat->chunks = (__c64_ptr64 __force)native->chunks;
	compat->gart_limit = native->gart_limit;
	compat->vram_limit = native->vram_limit;
}
struct __c64_drm_radeon_info {
	__u32		request;
	__u32		pad;
	__c64_ptr64	value;
};

static __always_inline __maybe_unused void
__from_c64_drm_radeon_info(struct drm_radeon_info *p)
{
	union {
		struct drm_radeon_info native;
		const struct __c64_drm_radeon_info compat;
	} *u = (void *)p;

	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.pad = u->compat.pad;
	u->native.request = u->compat.request;
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_info(struct drm_radeon_info *p)
{
	union {
		struct __c64_drm_radeon_info compat;
		const struct drm_radeon_info native;
	} *u = (void *)p;

	u->compat.request = u->native.request;
	u->compat.pad = u->native.pad;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_radeon_info_2(struct drm_radeon_info *native, const struct __c64_drm_radeon_info *compat)
{

	native->request = compat->request;
	native->pad = compat->pad;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_radeon_info_2(struct __c64_drm_radeon_info *compat, const struct drm_radeon_info *native)
{

	compat->request = native->request;
	compat->pad = native->pad;
	compat->value = (__c64_ptr64 __force)native->value;
}
