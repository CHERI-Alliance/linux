#pragma once


#include <linux/compat.h>


struct __c64_drm_drawable_info {
	unsigned int num_rects;
	__c64_uptr rects;
};

static __always_inline __maybe_unused void
__from_c64_drm_drawable_info(struct drm_drawable_info *p)
{
	union {
		struct drm_drawable_info native;
		const struct __c64_drm_drawable_info compat;
	} *u = (void *)p;

	u->native.rects =  compat_ptr(u->compat.rects);
	u->native.num_rects = u->compat.num_rects;
}
static __always_inline __maybe_unused void
__to_c64_drm_drawable_info(struct drm_drawable_info *p)
{
	union {
		struct __c64_drm_drawable_info compat;
		const struct drm_drawable_info native;
	} *u = (void *)p;

	u->compat.num_rects = u->native.num_rects;
	u->compat.rects =  (__c64_uptr __force)(user_uintptr_t)u->native.rects;
}
static __always_inline __maybe_unused void
__from_c64_drm_drawable_info_2(struct drm_drawable_info *native, const struct __c64_drm_drawable_info *compat)
{

	native->num_rects = compat->num_rects;
	native->rects =  compat_ptr(compat->rects);
}
static __always_inline __maybe_unused void
__to_c64_drm_drawable_info_2(struct __c64_drm_drawable_info *compat, const struct drm_drawable_info *native)
{

	compat->num_rects = native->num_rects;
	compat->rects =  (__c64_uptr __force)(user_uintptr_t)native->rects;
}
struct __c64_drm_version {
	int version_major;	  /**< Major version */
	int version_minor;	  /**< Minor version */
	int version_patchlevel;	  /**< Patch level */
	__kernel_size_t name_len;	  /**< Length of name buffer */
	__c64_uptr name;	  /**< Name of driver */
	__kernel_size_t date_len;	  /**< Length of date buffer */
	__c64_uptr date;	  /**< User-space buffer to hold date */
	__kernel_size_t desc_len;	  /**< Length of desc buffer */
	__c64_uptr desc;	  /**< User-space buffer to hold desc */
};

static __always_inline __maybe_unused void
__from_c64_drm_version(struct drm_version *p)
{
	union {
		struct drm_version native;
		const struct __c64_drm_version compat;
	} *u = (void *)p;

	u->native.desc =  compat_ptr(u->compat.desc);
	u->native.desc_len = u->compat.desc_len;
	u->native.date =  compat_ptr(u->compat.date);
	u->native.date_len = u->compat.date_len;
	u->native.name =  compat_ptr(u->compat.name);
	u->native.name_len = u->compat.name_len;
	u->native.version_patchlevel = u->compat.version_patchlevel;
	u->native.version_minor = u->compat.version_minor;
	u->native.version_major = u->compat.version_major;
}
static __always_inline __maybe_unused void
__to_c64_drm_version(struct drm_version *p)
{
	union {
		struct __c64_drm_version compat;
		const struct drm_version native;
	} *u = (void *)p;

	u->compat.version_major = u->native.version_major;
	u->compat.version_minor = u->native.version_minor;
	u->compat.version_patchlevel = u->native.version_patchlevel;
	u->compat.name_len = u->native.name_len;
	u->compat.name =  (__c64_uptr __force)(user_uintptr_t)u->native.name;
	u->compat.date_len = u->native.date_len;
	u->compat.date =  (__c64_uptr __force)(user_uintptr_t)u->native.date;
	u->compat.desc_len = u->native.desc_len;
	u->compat.desc =  (__c64_uptr __force)(user_uintptr_t)u->native.desc;
}
static __always_inline __maybe_unused void
__from_c64_drm_version_2(struct drm_version *native, const struct __c64_drm_version *compat)
{

	native->version_major = compat->version_major;
	native->version_minor = compat->version_minor;
	native->version_patchlevel = compat->version_patchlevel;
	native->name_len = compat->name_len;
	native->name =  compat_ptr(compat->name);
	native->date_len = compat->date_len;
	native->date =  compat_ptr(compat->date);
	native->desc_len = compat->desc_len;
	native->desc =  compat_ptr(compat->desc);
}
static __always_inline __maybe_unused void
__to_c64_drm_version_2(struct __c64_drm_version *compat, const struct drm_version *native)
{

	compat->version_major = native->version_major;
	compat->version_minor = native->version_minor;
	compat->version_patchlevel = native->version_patchlevel;
	compat->name_len = native->name_len;
	compat->name =  (__c64_uptr __force)(user_uintptr_t)native->name;
	compat->date_len = native->date_len;
	compat->date =  (__c64_uptr __force)(user_uintptr_t)native->date;
	compat->desc_len = native->desc_len;
	compat->desc =  (__c64_uptr __force)(user_uintptr_t)native->desc;
}
struct __c64_drm_unique {
	__kernel_size_t unique_len;	  /**< Length of unique */
	__c64_uptr unique;	  /**< Unique name for driver instantiation */
};

static __always_inline __maybe_unused void
__from_c64_drm_unique(struct drm_unique *p)
{
	union {
		struct drm_unique native;
		const struct __c64_drm_unique compat;
	} *u = (void *)p;

	u->native.unique =  compat_ptr(u->compat.unique);
	u->native.unique_len = u->compat.unique_len;
}
static __always_inline __maybe_unused void
__to_c64_drm_unique(struct drm_unique *p)
{
	union {
		struct __c64_drm_unique compat;
		const struct drm_unique native;
	} *u = (void *)p;

	u->compat.unique_len = u->native.unique_len;
	u->compat.unique =  (__c64_uptr __force)(user_uintptr_t)u->native.unique;
}
static __always_inline __maybe_unused void
__from_c64_drm_unique_2(struct drm_unique *native, const struct __c64_drm_unique *compat)
{

	native->unique_len = compat->unique_len;
	native->unique =  compat_ptr(compat->unique);
}
static __always_inline __maybe_unused void
__to_c64_drm_unique_2(struct __c64_drm_unique *compat, const struct drm_unique *native)
{

	compat->unique_len = native->unique_len;
	compat->unique =  (__c64_uptr __force)(user_uintptr_t)native->unique;
}
struct __c64_drm_list {
	int count;		  /**< Length of user-space structures */
	__c64_uptr version;
};

static __always_inline __maybe_unused void
__from_c64_drm_list(struct drm_list *p)
{
	union {
		struct drm_list native;
		const struct __c64_drm_list compat;
	} *u = (void *)p;

	u->native.version =  compat_ptr(u->compat.version);
	u->native.count = u->compat.count;
}
static __always_inline __maybe_unused void
__to_c64_drm_list(struct drm_list *p)
{
	union {
		struct __c64_drm_list compat;
		const struct drm_list native;
	} *u = (void *)p;

	u->compat.count = u->native.count;
	u->compat.version =  (__c64_uptr __force)(user_uintptr_t)u->native.version;
}
static __always_inline __maybe_unused void
__from_c64_drm_list_2(struct drm_list *native, const struct __c64_drm_list *compat)
{

	native->count = compat->count;
	native->version =  compat_ptr(compat->version);
}
static __always_inline __maybe_unused void
__to_c64_drm_list_2(struct __c64_drm_list *compat, const struct drm_list *native)
{

	compat->count = native->count;
	compat->version =  (__c64_uptr __force)(user_uintptr_t)native->version;
}
struct __c64_drm_ctx_priv_map {
	unsigned int ctx_id;	 /**< Context requesting private mapping */
	__c64_uptr handle;	 /**< Handle of map */
};

static __always_inline __maybe_unused void
__from_c64_drm_ctx_priv_map(struct drm_ctx_priv_map *p)
{
	union {
		struct drm_ctx_priv_map native;
		const struct __c64_drm_ctx_priv_map compat;
	} *u = (void *)p;

	u->native.handle =  compat_ptr(u->compat.handle);
	u->native.ctx_id = u->compat.ctx_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_ctx_priv_map(struct drm_ctx_priv_map *p)
{
	union {
		struct __c64_drm_ctx_priv_map compat;
		const struct drm_ctx_priv_map native;
	} *u = (void *)p;

	u->compat.ctx_id = u->native.ctx_id;
	u->compat.handle =  (__c64_uptr __force)(user_uintptr_t)u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_drm_ctx_priv_map_2(struct drm_ctx_priv_map *native, const struct __c64_drm_ctx_priv_map *compat)
{

	native->ctx_id = compat->ctx_id;
	native->handle =  compat_ptr(compat->handle);
}
static __always_inline __maybe_unused void
__to_c64_drm_ctx_priv_map_2(struct __c64_drm_ctx_priv_map *compat, const struct drm_ctx_priv_map *native)
{

	compat->ctx_id = native->ctx_id;
	compat->handle =  (__c64_uptr __force)(user_uintptr_t)native->handle;
}
struct __c64_drm_map {
	unsigned long offset;	 /**< Requested physical address (0 for SAREA)*/
	unsigned long size;	 /**< Requested physical size (bytes) */
	enum drm_map_type type;	 /**< Type of memory to map */
	enum drm_map_flags flags;	 /**< Flags */
	__c64_uptr handle;	 /**< User-space: "Handle" to pass to mmap() */
				 /**< Kernel-space: kernel-virtual address */
	int mtrr;		 /**< MTRR slot used */
	/*   Private data */
};

static __always_inline __maybe_unused void
__from_c64_drm_map(struct drm_map *p)
{
	union {
		struct drm_map native;
		const struct __c64_drm_map compat;
	} *u = (void *)p;

	u->native.mtrr = u->compat.mtrr;
	u->native.handle =  compat_ptr(u->compat.handle);
	u->native.flags = u->compat.flags;
	u->native.type = u->compat.type;
	u->native.size = u->compat.size;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_drm_map(struct drm_map *p)
{
	union {
		struct __c64_drm_map compat;
		const struct drm_map native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.size = u->native.size;
	u->compat.type = u->native.type;
	u->compat.flags = u->native.flags;
	u->compat.handle =  (__c64_uptr __force)(user_uintptr_t)u->native.handle;
	u->compat.mtrr = u->native.mtrr;
}
static __always_inline __maybe_unused void
__from_c64_drm_map_2(struct drm_map *native, const struct __c64_drm_map *compat)
{

	native->offset = compat->offset;
	native->size = compat->size;
	native->type = compat->type;
	native->flags = compat->flags;
	native->handle =  compat_ptr(compat->handle);
	native->mtrr = compat->mtrr;
}
static __always_inline __maybe_unused void
__to_c64_drm_map_2(struct __c64_drm_map *compat, const struct drm_map *native)
{

	compat->offset = native->offset;
	compat->size = native->size;
	compat->type = native->type;
	compat->flags = native->flags;
	compat->handle =  (__c64_uptr __force)(user_uintptr_t)native->handle;
	compat->mtrr = native->mtrr;
}
struct __c64_drm_buf_info {
	int count;		/**< Entries in list */
	__c64_uptr list;
};

static __always_inline __maybe_unused void
__from_c64_drm_buf_info(struct drm_buf_info *p)
{
	union {
		struct drm_buf_info native;
		const struct __c64_drm_buf_info compat;
	} *u = (void *)p;

	u->native.list =  compat_ptr(u->compat.list);
	u->native.count = u->compat.count;
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_info(struct drm_buf_info *p)
{
	union {
		struct __c64_drm_buf_info compat;
		const struct drm_buf_info native;
	} *u = (void *)p;

	u->compat.count = u->native.count;
	u->compat.list =  (__c64_uptr __force)(user_uintptr_t)u->native.list;
}
static __always_inline __maybe_unused void
__from_c64_drm_buf_info_2(struct drm_buf_info *native, const struct __c64_drm_buf_info *compat)
{

	native->count = compat->count;
	native->list =  compat_ptr(compat->list);
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_info_2(struct __c64_drm_buf_info *compat, const struct drm_buf_info *native)
{

	compat->count = native->count;
	compat->list =  (__c64_uptr __force)(user_uintptr_t)native->list;
}
struct __c64_drm_buf_free {
	int count;
	__c64_uptr list;
};

static __always_inline __maybe_unused void
__from_c64_drm_buf_free(struct drm_buf_free *p)
{
	union {
		struct drm_buf_free native;
		const struct __c64_drm_buf_free compat;
	} *u = (void *)p;

	u->native.list =  compat_ptr(u->compat.list);
	u->native.count = u->compat.count;
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_free(struct drm_buf_free *p)
{
	union {
		struct __c64_drm_buf_free compat;
		const struct drm_buf_free native;
	} *u = (void *)p;

	u->compat.count = u->native.count;
	u->compat.list =  (__c64_uptr __force)(user_uintptr_t)u->native.list;
}
static __always_inline __maybe_unused void
__from_c64_drm_buf_free_2(struct drm_buf_free *native, const struct __c64_drm_buf_free *compat)
{

	native->count = compat->count;
	native->list =  compat_ptr(compat->list);
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_free_2(struct __c64_drm_buf_free *compat, const struct drm_buf_free *native)
{

	compat->count = native->count;
	compat->list =  (__c64_uptr __force)(user_uintptr_t)native->list;
}
struct __c64_drm_buf_pub {
	int idx;		       /**< Index into the master buffer list */
	int total;		       /**< Buffer size */
	int used;		       /**< Amount of buffer in use (for DMA) */
	__c64_uptr address;	       /**< Address of buffer */
};

static __always_inline __maybe_unused void
__from_c64_drm_buf_pub(struct drm_buf_pub *p)
{
	union {
		struct drm_buf_pub native;
		const struct __c64_drm_buf_pub compat;
	} *u = (void *)p;

	u->native.address =  compat_ptr(u->compat.address);
	u->native.used = u->compat.used;
	u->native.total = u->compat.total;
	u->native.idx = u->compat.idx;
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_pub(struct drm_buf_pub *p)
{
	union {
		struct __c64_drm_buf_pub compat;
		const struct drm_buf_pub native;
	} *u = (void *)p;

	u->compat.idx = u->native.idx;
	u->compat.total = u->native.total;
	u->compat.used = u->native.used;
	u->compat.address =  (__c64_uptr __force)(user_uintptr_t)u->native.address;
}
static __always_inline __maybe_unused void
__from_c64_drm_buf_pub_2(struct drm_buf_pub *native, const struct __c64_drm_buf_pub *compat)
{

	native->idx = compat->idx;
	native->total = compat->total;
	native->used = compat->used;
	native->address =  compat_ptr(compat->address);
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_pub_2(struct __c64_drm_buf_pub *compat, const struct drm_buf_pub *native)
{

	compat->idx = native->idx;
	compat->total = native->total;
	compat->used = native->used;
	compat->address =  (__c64_uptr __force)(user_uintptr_t)native->address;
}
struct __c64_drm_buf_map {
	int count;		/**< Length of the buffer list */
	__c64_uptr virtual;		/**< Mmap'd area in user-virtual */
	__c64_uptr list;	/**< Buffer information */
};

static __always_inline __maybe_unused void
__from_c64_drm_buf_map(struct drm_buf_map *p)
{
	union {
		struct drm_buf_map native;
		const struct __c64_drm_buf_map compat;
	} *u = (void *)p;

	u->native.list =  compat_ptr(u->compat.list);
	u->native.virtual =  compat_ptr(u->compat.virtual);
	u->native.count = u->compat.count;
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_map(struct drm_buf_map *p)
{
	union {
		struct __c64_drm_buf_map compat;
		const struct drm_buf_map native;
	} *u = (void *)p;

	u->compat.count = u->native.count;
	u->compat.virtual =  (__c64_uptr __force)(user_uintptr_t)u->native.virtual;
	u->compat.list =  (__c64_uptr __force)(user_uintptr_t)u->native.list;
}
static __always_inline __maybe_unused void
__from_c64_drm_buf_map_2(struct drm_buf_map *native, const struct __c64_drm_buf_map *compat)
{

	native->count = compat->count;
	native->virtual =  compat_ptr(compat->virtual);
	native->list =  compat_ptr(compat->list);
}
static __always_inline __maybe_unused void
__to_c64_drm_buf_map_2(struct __c64_drm_buf_map *compat, const struct drm_buf_map *native)
{

	compat->count = native->count;
	compat->virtual =  (__c64_uptr __force)(user_uintptr_t)native->virtual;
	compat->list =  (__c64_uptr __force)(user_uintptr_t)native->list;
}
struct __c64_drm_dma {
	int context;			  /**< Context handle */
	int send_count;			  /**< Number of buffers to send */
	__c64_uptr send_indices;	  /**< List of handles to buffers */
	__c64_uptr send_sizes;		  /**< Lengths of data to send */
	enum drm_dma_flags flags;	  /**< Flags */
	int request_count;		  /**< Number of buffers requested */
	int request_size;		  /**< Desired size for buffers */
	__c64_uptr request_indices;	  /**< Buffer information */
	__c64_uptr request_sizes;
	int granted_count;		  /**< Number of buffers granted */
};

static __always_inline __maybe_unused void
__from_c64_drm_dma(struct drm_dma *p)
{
	union {
		struct drm_dma native;
		const struct __c64_drm_dma compat;
	} *u = (void *)p;

	u->native.granted_count = u->compat.granted_count;
	u->native.request_sizes =  compat_ptr(u->compat.request_sizes);
	u->native.request_indices =  compat_ptr(u->compat.request_indices);
	u->native.request_size = u->compat.request_size;
	u->native.request_count = u->compat.request_count;
	u->native.flags = u->compat.flags;
	u->native.send_sizes =  compat_ptr(u->compat.send_sizes);
	u->native.send_indices =  compat_ptr(u->compat.send_indices);
	u->native.send_count = u->compat.send_count;
	u->native.context = u->compat.context;
}
static __always_inline __maybe_unused void
__to_c64_drm_dma(struct drm_dma *p)
{
	union {
		struct __c64_drm_dma compat;
		const struct drm_dma native;
	} *u = (void *)p;

	u->compat.context = u->native.context;
	u->compat.send_count = u->native.send_count;
	u->compat.send_indices =  (__c64_uptr __force)(user_uintptr_t)u->native.send_indices;
	u->compat.send_sizes =  (__c64_uptr __force)(user_uintptr_t)u->native.send_sizes;
	u->compat.flags = u->native.flags;
	u->compat.request_count = u->native.request_count;
	u->compat.request_size = u->native.request_size;
	u->compat.request_indices =  (__c64_uptr __force)(user_uintptr_t)u->native.request_indices;
	u->compat.request_sizes =  (__c64_uptr __force)(user_uintptr_t)u->native.request_sizes;
	u->compat.granted_count = u->native.granted_count;
}
static __always_inline __maybe_unused void
__from_c64_drm_dma_2(struct drm_dma *native, const struct __c64_drm_dma *compat)
{

	native->context = compat->context;
	native->send_count = compat->send_count;
	native->send_indices =  compat_ptr(compat->send_indices);
	native->send_sizes =  compat_ptr(compat->send_sizes);
	native->flags = compat->flags;
	native->request_count = compat->request_count;
	native->request_size = compat->request_size;
	native->request_indices =  compat_ptr(compat->request_indices);
	native->request_sizes =  compat_ptr(compat->request_sizes);
	native->granted_count = compat->granted_count;
}
static __always_inline __maybe_unused void
__to_c64_drm_dma_2(struct __c64_drm_dma *compat, const struct drm_dma *native)
{

	compat->context = native->context;
	compat->send_count = native->send_count;
	compat->send_indices =  (__c64_uptr __force)(user_uintptr_t)native->send_indices;
	compat->send_sizes =  (__c64_uptr __force)(user_uintptr_t)native->send_sizes;
	compat->flags = native->flags;
	compat->request_count = native->request_count;
	compat->request_size = native->request_size;
	compat->request_indices =  (__c64_uptr __force)(user_uintptr_t)native->request_indices;
	compat->request_sizes =  (__c64_uptr __force)(user_uintptr_t)native->request_sizes;
	compat->granted_count = native->granted_count;
}
struct __c64_drm_ctx_res {
	int count;
	__c64_uptr contexts;
};

static __always_inline __maybe_unused void
__from_c64_drm_ctx_res(struct drm_ctx_res *p)
{
	union {
		struct drm_ctx_res native;
		const struct __c64_drm_ctx_res compat;
	} *u = (void *)p;

	u->native.contexts =  compat_ptr(u->compat.contexts);
	u->native.count = u->compat.count;
}
static __always_inline __maybe_unused void
__to_c64_drm_ctx_res(struct drm_ctx_res *p)
{
	union {
		struct __c64_drm_ctx_res compat;
		const struct drm_ctx_res native;
	} *u = (void *)p;

	u->compat.count = u->native.count;
	u->compat.contexts =  (__c64_uptr __force)(user_uintptr_t)u->native.contexts;
}
static __always_inline __maybe_unused void
__from_c64_drm_ctx_res_2(struct drm_ctx_res *native, const struct __c64_drm_ctx_res *compat)
{

	native->count = compat->count;
	native->contexts =  compat_ptr(compat->contexts);
}
static __always_inline __maybe_unused void
__to_c64_drm_ctx_res_2(struct __c64_drm_ctx_res *compat, const struct drm_ctx_res *native)
{

	compat->count = native->count;
	compat->contexts =  (__c64_uptr __force)(user_uintptr_t)native->contexts;
}
struct __c64_drm_wait_vblank_request {
	enum drm_vblank_seq_type type;
	unsigned int sequence;
	__c64_uptr signal;
};

static __always_inline __maybe_unused void
__from_c64_drm_wait_vblank_request(struct drm_wait_vblank_request *p)
{
	union {
		struct drm_wait_vblank_request native;
		const struct __c64_drm_wait_vblank_request compat;
	} *u = (void *)p;

	u->native.signal = (user_uintptr_t)compat_ptr(u->compat.signal);
	u->native.sequence = u->compat.sequence;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_drm_wait_vblank_request(struct drm_wait_vblank_request *p)
{
	union {
		struct __c64_drm_wait_vblank_request compat;
		const struct drm_wait_vblank_request native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.sequence = u->native.sequence;
	u->compat.signal = (__c64_uptr __force)u->native.signal;
}
static __always_inline __maybe_unused void
__from_c64_drm_wait_vblank_request_2(struct drm_wait_vblank_request *native, const struct __c64_drm_wait_vblank_request *compat)
{

	native->type = compat->type;
	native->sequence = compat->sequence;
	native->signal = (user_uintptr_t)compat_ptr(compat->signal);
}
static __always_inline __maybe_unused void
__to_c64_drm_wait_vblank_request_2(struct __c64_drm_wait_vblank_request *compat, const struct drm_wait_vblank_request *native)
{

	compat->type = native->type;
	compat->sequence = native->sequence;
	compat->signal = (__c64_uptr __force)native->signal;
}
union __c64_drm_wait_vblank {
	struct __c64_drm_wait_vblank_request request;
	struct drm_wait_vblank_reply reply;
};

struct __c64_drm_syncobj_wait {
	__c64_ptr64 handles;
	/* absolute timeout */
	__s64 timeout_nsec;
	__u32 count_handles;
	__u32 flags;
	__u32 first_signaled; /* only valid when not waiting all */
	__u32 pad;
	/**
	 * @deadline_nsec - fence deadline hint
	 *
	 * Deadline hint, in absolute CLOCK_MONOTONIC, to set on backing
	 * fence(s) if the DRM_SYNCOBJ_WAIT_FLAGS_WAIT_DEADLINE flag is
	 * set.
	 */
	__u64 deadline_nsec;
};

static __always_inline __maybe_unused void
__from_c64_drm_syncobj_wait(struct drm_syncobj_wait *p)
{
	union {
		struct drm_syncobj_wait native;
		const struct __c64_drm_syncobj_wait compat;
	} *u = (void *)p;

	u->native.deadline_nsec = u->compat.deadline_nsec;
	u->native.pad = u->compat.pad;
	u->native.first_signaled = u->compat.first_signaled;
	u->native.flags = u->compat.flags;
	u->native.count_handles = u->compat.count_handles;
	u->native.timeout_nsec = u->compat.timeout_nsec;
	u->native.handles = (user_uintptr_t)compat_ptr(u->compat.handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_wait(struct drm_syncobj_wait *p)
{
	union {
		struct __c64_drm_syncobj_wait compat;
		const struct drm_syncobj_wait native;
	} *u = (void *)p;

	u->compat.handles = (__c64_ptr64 __force)u->native.handles;
	u->compat.timeout_nsec = u->native.timeout_nsec;
	u->compat.count_handles = u->native.count_handles;
	u->compat.flags = u->native.flags;
	u->compat.first_signaled = u->native.first_signaled;
	u->compat.pad = u->native.pad;
	u->compat.deadline_nsec = u->native.deadline_nsec;
}
static __always_inline __maybe_unused void
__from_c64_drm_syncobj_wait_2(struct drm_syncobj_wait *native, const struct __c64_drm_syncobj_wait *compat)
{

	native->handles = (user_uintptr_t)compat_ptr(compat->handles);
	native->timeout_nsec = compat->timeout_nsec;
	native->count_handles = compat->count_handles;
	native->flags = compat->flags;
	native->first_signaled = compat->first_signaled;
	native->pad = compat->pad;
	native->deadline_nsec = compat->deadline_nsec;
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_wait_2(struct __c64_drm_syncobj_wait *compat, const struct drm_syncobj_wait *native)
{

	compat->handles = (__c64_ptr64 __force)native->handles;
	compat->timeout_nsec = native->timeout_nsec;
	compat->count_handles = native->count_handles;
	compat->flags = native->flags;
	compat->first_signaled = native->first_signaled;
	compat->pad = native->pad;
	compat->deadline_nsec = native->deadline_nsec;
}
struct __c64_drm_syncobj_timeline_wait {
	__c64_ptr64 handles;
	/* wait on specific timeline point for every handles*/
	__c64_ptr64 points;
	/* absolute timeout */
	__s64 timeout_nsec;
	__u32 count_handles;
	__u32 flags;
	__u32 first_signaled; /* only valid when not waiting all */
	__u32 pad;
	/**
	 * @deadline_nsec - fence deadline hint
	 *
	 * Deadline hint, in absolute CLOCK_MONOTONIC, to set on backing
	 * fence(s) if the DRM_SYNCOBJ_WAIT_FLAGS_WAIT_DEADLINE flag is
	 * set.
	 */
	__u64 deadline_nsec;
};

static __always_inline __maybe_unused void
__from_c64_drm_syncobj_timeline_wait(struct drm_syncobj_timeline_wait *p)
{
	union {
		struct drm_syncobj_timeline_wait native;
		const struct __c64_drm_syncobj_timeline_wait compat;
	} *u = (void *)p;

	u->native.deadline_nsec = u->compat.deadline_nsec;
	u->native.pad = u->compat.pad;
	u->native.first_signaled = u->compat.first_signaled;
	u->native.flags = u->compat.flags;
	u->native.count_handles = u->compat.count_handles;
	u->native.timeout_nsec = u->compat.timeout_nsec;
	u->native.points = (user_uintptr_t)compat_ptr(u->compat.points);
	u->native.handles = (user_uintptr_t)compat_ptr(u->compat.handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_timeline_wait(struct drm_syncobj_timeline_wait *p)
{
	union {
		struct __c64_drm_syncobj_timeline_wait compat;
		const struct drm_syncobj_timeline_wait native;
	} *u = (void *)p;

	u->compat.handles = (__c64_ptr64 __force)u->native.handles;
	u->compat.points = (__c64_ptr64 __force)u->native.points;
	u->compat.timeout_nsec = u->native.timeout_nsec;
	u->compat.count_handles = u->native.count_handles;
	u->compat.flags = u->native.flags;
	u->compat.first_signaled = u->native.first_signaled;
	u->compat.pad = u->native.pad;
	u->compat.deadline_nsec = u->native.deadline_nsec;
}
static __always_inline __maybe_unused void
__from_c64_drm_syncobj_timeline_wait_2(struct drm_syncobj_timeline_wait *native, const struct __c64_drm_syncobj_timeline_wait *compat)
{

	native->handles = (user_uintptr_t)compat_ptr(compat->handles);
	native->points = (user_uintptr_t)compat_ptr(compat->points);
	native->timeout_nsec = compat->timeout_nsec;
	native->count_handles = compat->count_handles;
	native->flags = compat->flags;
	native->first_signaled = compat->first_signaled;
	native->pad = compat->pad;
	native->deadline_nsec = compat->deadline_nsec;
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_timeline_wait_2(struct __c64_drm_syncobj_timeline_wait *compat, const struct drm_syncobj_timeline_wait *native)
{

	compat->handles = (__c64_ptr64 __force)native->handles;
	compat->points = (__c64_ptr64 __force)native->points;
	compat->timeout_nsec = native->timeout_nsec;
	compat->count_handles = native->count_handles;
	compat->flags = native->flags;
	compat->first_signaled = native->first_signaled;
	compat->pad = native->pad;
	compat->deadline_nsec = native->deadline_nsec;
}
struct __c64_drm_syncobj_array {
	__c64_ptr64 handles;
	__u32 count_handles;
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_syncobj_array(struct drm_syncobj_array *p)
{
	union {
		struct drm_syncobj_array native;
		const struct __c64_drm_syncobj_array compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.count_handles = u->compat.count_handles;
	u->native.handles = (user_uintptr_t)compat_ptr(u->compat.handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_array(struct drm_syncobj_array *p)
{
	union {
		struct __c64_drm_syncobj_array compat;
		const struct drm_syncobj_array native;
	} *u = (void *)p;

	u->compat.handles = (__c64_ptr64 __force)u->native.handles;
	u->compat.count_handles = u->native.count_handles;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_syncobj_array_2(struct drm_syncobj_array *native, const struct __c64_drm_syncobj_array *compat)
{

	native->handles = (user_uintptr_t)compat_ptr(compat->handles);
	native->count_handles = compat->count_handles;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_array_2(struct __c64_drm_syncobj_array *compat, const struct drm_syncobj_array *native)
{

	compat->handles = (__c64_ptr64 __force)native->handles;
	compat->count_handles = native->count_handles;
	compat->pad = native->pad;
}
struct __c64_drm_syncobj_timeline_array {
	__c64_ptr64 handles;
	__c64_ptr64 points;
	__u32 count_handles;
	__u32 flags;
};

static __always_inline __maybe_unused void
__from_c64_drm_syncobj_timeline_array(struct drm_syncobj_timeline_array *p)
{
	union {
		struct drm_syncobj_timeline_array native;
		const struct __c64_drm_syncobj_timeline_array compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.count_handles = u->compat.count_handles;
	u->native.points = (user_uintptr_t)compat_ptr(u->compat.points);
	u->native.handles = (user_uintptr_t)compat_ptr(u->compat.handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_timeline_array(struct drm_syncobj_timeline_array *p)
{
	union {
		struct __c64_drm_syncobj_timeline_array compat;
		const struct drm_syncobj_timeline_array native;
	} *u = (void *)p;

	u->compat.handles = (__c64_ptr64 __force)u->native.handles;
	u->compat.points = (__c64_ptr64 __force)u->native.points;
	u->compat.count_handles = u->native.count_handles;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_drm_syncobj_timeline_array_2(struct drm_syncobj_timeline_array *native, const struct __c64_drm_syncobj_timeline_array *compat)
{

	native->handles = (user_uintptr_t)compat_ptr(compat->handles);
	native->points = (user_uintptr_t)compat_ptr(compat->points);
	native->count_handles = compat->count_handles;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_syncobj_timeline_array_2(struct __c64_drm_syncobj_timeline_array *compat, const struct drm_syncobj_timeline_array *native)
{

	compat->handles = (__c64_ptr64 __force)native->handles;
	compat->points = (__c64_ptr64 __force)native->points;
	compat->count_handles = native->count_handles;
	compat->flags = native->flags;
}
struct __c64_drm_crtc_queue_sequence {
	__u32 crtc_id;
	__u32 flags;
	__u64 sequence;		/* on input, target sequence. on output, actual sequence */
	__c64_ptr64 user_data;	/* user data passed to event */
};

static __always_inline __maybe_unused void
__from_c64_drm_crtc_queue_sequence(struct drm_crtc_queue_sequence *p)
{
	union {
		struct drm_crtc_queue_sequence native;
		const struct __c64_drm_crtc_queue_sequence compat;
	} *u = (void *)p;

	u->native.user_data = (user_uintptr_t)compat_ptr(u->compat.user_data);
	u->native.sequence = u->compat.sequence;
	u->native.flags = u->compat.flags;
	u->native.crtc_id = u->compat.crtc_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_crtc_queue_sequence(struct drm_crtc_queue_sequence *p)
{
	union {
		struct __c64_drm_crtc_queue_sequence compat;
		const struct drm_crtc_queue_sequence native;
	} *u = (void *)p;

	u->compat.crtc_id = u->native.crtc_id;
	u->compat.flags = u->native.flags;
	u->compat.sequence = u->native.sequence;
	u->compat.user_data = (__c64_ptr64 __force)u->native.user_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_crtc_queue_sequence_2(struct drm_crtc_queue_sequence *native, const struct __c64_drm_crtc_queue_sequence *compat)
{

	native->crtc_id = compat->crtc_id;
	native->flags = compat->flags;
	native->sequence = compat->sequence;
	native->user_data = (user_uintptr_t)compat_ptr(compat->user_data);
}
static __always_inline __maybe_unused void
__to_c64_drm_crtc_queue_sequence_2(struct __c64_drm_crtc_queue_sequence *compat, const struct drm_crtc_queue_sequence *native)
{

	compat->crtc_id = native->crtc_id;
	compat->flags = native->flags;
	compat->sequence = native->sequence;
	compat->user_data = (__c64_ptr64 __force)native->user_data;
}
struct __c64_drm_set_client_name {
	__u64 name_len;
	__c64_ptr64 name;
};

static __always_inline __maybe_unused void
__from_c64_drm_set_client_name(struct drm_set_client_name *p)
{
	union {
		struct drm_set_client_name native;
		const struct __c64_drm_set_client_name compat;
	} *u = (void *)p;

	u->native.name = (user_uintptr_t)compat_ptr(u->compat.name);
	u->native.name_len = u->compat.name_len;
}
static __always_inline __maybe_unused void
__to_c64_drm_set_client_name(struct drm_set_client_name *p)
{
	union {
		struct __c64_drm_set_client_name compat;
		const struct drm_set_client_name native;
	} *u = (void *)p;

	u->compat.name_len = u->native.name_len;
	u->compat.name = (__c64_ptr64 __force)u->native.name;
}
static __always_inline __maybe_unused void
__from_c64_drm_set_client_name_2(struct drm_set_client_name *native, const struct __c64_drm_set_client_name *compat)
{

	native->name_len = compat->name_len;
	native->name = (user_uintptr_t)compat_ptr(compat->name);
}
static __always_inline __maybe_unused void
__to_c64_drm_set_client_name_2(struct __c64_drm_set_client_name *compat, const struct drm_set_client_name *native)
{

	compat->name_len = native->name_len;
	compat->name = (__c64_ptr64 __force)native->name;
}
struct __c64_drm_event_vblank {
	struct drm_event base;
	__c64_ptr64 user_data;
	__u32 tv_sec;
	__u32 tv_usec;
	__u32 sequence;
	__u32 crtc_id; /* 0 on older kernels that do not support this */
};

static __always_inline __maybe_unused void
__from_c64_drm_event_vblank(struct drm_event_vblank *p)
{
	union {
		struct drm_event_vblank native;
		const struct __c64_drm_event_vblank compat;
	} *u = (void *)p;

	u->native.crtc_id = u->compat.crtc_id;
	u->native.sequence = u->compat.sequence;
	u->native.tv_usec = u->compat.tv_usec;
	u->native.tv_sec = u->compat.tv_sec;
	u->native.user_data = (user_uintptr_t)compat_ptr(u->compat.user_data);
	BUILD_BUG_ON(sizeof(u->compat.base) != sizeof(u->native.base));
	memmove(&u->native.base, &u->compat.base, sizeof(u->native.base));
}
static __always_inline __maybe_unused void
__to_c64_drm_event_vblank(struct drm_event_vblank *p)
{
	union {
		struct __c64_drm_event_vblank compat;
		const struct drm_event_vblank native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.base) != sizeof(u->compat.base));
	memmove(&u->compat.base, &u->native.base, sizeof(u->compat.base));
	u->compat.user_data = (__c64_ptr64 __force)u->native.user_data;
	u->compat.tv_sec = u->native.tv_sec;
	u->compat.tv_usec = u->native.tv_usec;
	u->compat.sequence = u->native.sequence;
	u->compat.crtc_id = u->native.crtc_id;
}
static __always_inline __maybe_unused void
__from_c64_drm_event_vblank_2(struct drm_event_vblank *native, const struct __c64_drm_event_vblank *compat)
{

	BUILD_BUG_ON(sizeof(compat->base) != sizeof(native->base));
	memcpy(&native->base, &compat->base, sizeof(native->base));
	native->user_data = (user_uintptr_t)compat_ptr(compat->user_data);
	native->tv_sec = compat->tv_sec;
	native->tv_usec = compat->tv_usec;
	native->sequence = compat->sequence;
	native->crtc_id = compat->crtc_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_event_vblank_2(struct __c64_drm_event_vblank *compat, const struct drm_event_vblank *native)
{

	BUILD_BUG_ON(sizeof(native->base) != sizeof(compat->base));
	memcpy(&compat->base, &native->base, sizeof(compat->base));
	compat->user_data = (__c64_ptr64 __force)native->user_data;
	compat->tv_sec = native->tv_sec;
	compat->tv_usec = native->tv_usec;
	compat->sequence = native->sequence;
	compat->crtc_id = native->crtc_id;
}
struct __c64_drm_event_crtc_sequence {
	struct drm_event	base;
	__c64_ptr64		user_data;
	__s64			time_ns;
	__u64			sequence;
};

static __always_inline __maybe_unused void
__from_c64_drm_event_crtc_sequence(struct drm_event_crtc_sequence *p)
{
	union {
		struct drm_event_crtc_sequence native;
		const struct __c64_drm_event_crtc_sequence compat;
	} *u = (void *)p;

	u->native.sequence = u->compat.sequence;
	u->native.time_ns = u->compat.time_ns;
	u->native.user_data = (user_uintptr_t)compat_ptr(u->compat.user_data);
	BUILD_BUG_ON(sizeof(u->compat.base) != sizeof(u->native.base));
	memmove(&u->native.base, &u->compat.base, sizeof(u->native.base));
}
static __always_inline __maybe_unused void
__to_c64_drm_event_crtc_sequence(struct drm_event_crtc_sequence *p)
{
	union {
		struct __c64_drm_event_crtc_sequence compat;
		const struct drm_event_crtc_sequence native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.base) != sizeof(u->compat.base));
	memmove(&u->compat.base, &u->native.base, sizeof(u->compat.base));
	u->compat.user_data = (__c64_ptr64 __force)u->native.user_data;
	u->compat.time_ns = u->native.time_ns;
	u->compat.sequence = u->native.sequence;
}
static __always_inline __maybe_unused void
__from_c64_drm_event_crtc_sequence_2(struct drm_event_crtc_sequence *native, const struct __c64_drm_event_crtc_sequence *compat)
{

	BUILD_BUG_ON(sizeof(compat->base) != sizeof(native->base));
	memcpy(&native->base, &compat->base, sizeof(native->base));
	native->user_data = (user_uintptr_t)compat_ptr(compat->user_data);
	native->time_ns = compat->time_ns;
	native->sequence = compat->sequence;
}
static __always_inline __maybe_unused void
__to_c64_drm_event_crtc_sequence_2(struct __c64_drm_event_crtc_sequence *compat, const struct drm_event_crtc_sequence *native)
{

	BUILD_BUG_ON(sizeof(native->base) != sizeof(compat->base));
	memcpy(&compat->base, &native->base, sizeof(compat->base));
	compat->user_data = (__c64_ptr64 __force)native->user_data;
	compat->time_ns = native->time_ns;
	compat->sequence = native->sequence;
}
