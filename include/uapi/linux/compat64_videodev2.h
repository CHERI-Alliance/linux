#pragma once


#include <linux/compat.h>


struct __c64_v4l2_plane {
	__u32			bytesused;
	__u32			length;
	union {
		__u32		mem_offset;
		__c64_uptr		userptr;
		__s32		fd;
	} m;
	__u32			data_offset;
	__u32			reserved[11];
};

struct __c64_v4l2_buffer {
	__u32			index;
	__u32			type;
	__u32			bytesused;
	__u32			flags;
	__u32			field;
	struct __kernel_v4l2_timeval timestamp;
	struct v4l2_timecode	timecode;
	__u32			sequence;

	/* memory location */
	__u32			memory;
	union {
		__u32           offset;
		__c64_uptr          userptr;
		__c64_uptr planes;
		__s32		fd;
	} m;
	__u32			length;
	__u32			reserved2;
	union {
		__s32		request_fd;
		__u32		reserved;
	};
};

struct __c64_v4l2_framebuffer {
	__u32			capability;
	__u32			flags;
/* FIXME: in theory we should pass something like PCI device + memory
 * region + offset instead of some physical address */
	__c64_uptr base;
	struct {
		__u32		width;
		__u32		height;
		__u32		pixelformat;
		__u32		field;		/* enum v4l2_field */
		__u32		bytesperline;	/* for padding, zero if unused */
		__u32		sizeimage;
		__u32		colorspace;	/* enum v4l2_colorspace */
		__u32		priv;		/* reserved field, set to 0 */
	} fmt;
};

static __always_inline __maybe_unused void
__from_c64_v4l2_framebuffer(struct v4l2_framebuffer *p)
{
	union {
		struct v4l2_framebuffer native;
		const struct __c64_v4l2_framebuffer compat;
	} *u = (void *)p;

	u->native.fmt.priv = u->compat.fmt.priv;
	u->native.fmt.colorspace = u->compat.fmt.colorspace;
	u->native.fmt.sizeimage = u->compat.fmt.sizeimage;
	u->native.fmt.bytesperline = u->compat.fmt.bytesperline;
	u->native.fmt.field = u->compat.fmt.field;
	u->native.fmt.pixelformat = u->compat.fmt.pixelformat;
	u->native.fmt.height = u->compat.fmt.height;
	u->native.fmt.width = u->compat.fmt.width;
	u->native.base =  compat_ptr(u->compat.base);
	u->native.flags = u->compat.flags;
	u->native.capability = u->compat.capability;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_framebuffer(struct v4l2_framebuffer *p)
{
	union {
		struct __c64_v4l2_framebuffer compat;
		const struct v4l2_framebuffer native;
	} *u = (void *)p;

	u->compat.capability = u->native.capability;
	u->compat.flags = u->native.flags;
	u->compat.base =  (__c64_uptr __force)(user_uintptr_t)u->native.base;
	u->compat.fmt.width = u->native.fmt.width;
	u->compat.fmt.height = u->native.fmt.height;
	u->compat.fmt.pixelformat = u->native.fmt.pixelformat;
	u->compat.fmt.field = u->native.fmt.field;
	u->compat.fmt.bytesperline = u->native.fmt.bytesperline;
	u->compat.fmt.sizeimage = u->native.fmt.sizeimage;
	u->compat.fmt.colorspace = u->native.fmt.colorspace;
	u->compat.fmt.priv = u->native.fmt.priv;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_framebuffer_2(struct v4l2_framebuffer *native, const struct __c64_v4l2_framebuffer *compat)
{

	native->capability = compat->capability;
	native->flags = compat->flags;
	native->base =  compat_ptr(compat->base);
	native->fmt.width = compat->fmt.width;
	native->fmt.height = compat->fmt.height;
	native->fmt.pixelformat = compat->fmt.pixelformat;
	native->fmt.field = compat->fmt.field;
	native->fmt.bytesperline = compat->fmt.bytesperline;
	native->fmt.sizeimage = compat->fmt.sizeimage;
	native->fmt.colorspace = compat->fmt.colorspace;
	native->fmt.priv = compat->fmt.priv;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_framebuffer_2(struct __c64_v4l2_framebuffer *compat, const struct v4l2_framebuffer *native)
{

	compat->capability = native->capability;
	compat->flags = native->flags;
	compat->base =  (__c64_uptr __force)(user_uintptr_t)native->base;
	compat->fmt.width = native->fmt.width;
	compat->fmt.height = native->fmt.height;
	compat->fmt.pixelformat = native->fmt.pixelformat;
	compat->fmt.field = native->fmt.field;
	compat->fmt.bytesperline = native->fmt.bytesperline;
	compat->fmt.sizeimage = native->fmt.sizeimage;
	compat->fmt.colorspace = native->fmt.colorspace;
	compat->fmt.priv = native->fmt.priv;
}
struct __c64_v4l2_clip {
	struct v4l2_rect        c;
	__c64_uptr next;
};

static __always_inline __maybe_unused void
__from_c64_v4l2_clip(struct v4l2_clip *p)
{
	union {
		struct v4l2_clip native;
		const struct __c64_v4l2_clip compat;
	} *u = (void *)p;

	u->native.next =  compat_ptr(u->compat.next);
	BUILD_BUG_ON(sizeof(u->compat.c) != sizeof(u->native.c));
	memmove(&u->native.c, &u->compat.c, sizeof(u->native.c));
}
static __always_inline __maybe_unused void
__to_c64_v4l2_clip(struct v4l2_clip *p)
{
	union {
		struct __c64_v4l2_clip compat;
		const struct v4l2_clip native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.c) != sizeof(u->compat.c));
	memmove(&u->compat.c, &u->native.c, sizeof(u->compat.c));
	u->compat.next =  (__c64_uptr __force)(user_uintptr_t)u->native.next;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_clip_2(struct v4l2_clip *native, const struct __c64_v4l2_clip *compat)
{

	BUILD_BUG_ON(sizeof(compat->c) != sizeof(native->c));
	memcpy(&native->c, &compat->c, sizeof(native->c));
	native->next =  compat_ptr(compat->next);
}
static __always_inline __maybe_unused void
__to_c64_v4l2_clip_2(struct __c64_v4l2_clip *compat, const struct v4l2_clip *native)
{

	BUILD_BUG_ON(sizeof(native->c) != sizeof(compat->c));
	memcpy(&compat->c, &native->c, sizeof(compat->c));
	compat->next =  (__c64_uptr __force)(user_uintptr_t)native->next;
}
struct __c64_v4l2_window {
	struct v4l2_rect        w;
	__u32			field;	 /* enum v4l2_field */
	__u32			chromakey;
	__c64_uptr clips;
	__u32			clipcount;
	__c64_uptr bitmap;
	__u8                    global_alpha;
};

static __always_inline __maybe_unused void
__from_c64_v4l2_window(struct v4l2_window *p)
{
	union {
		struct v4l2_window native;
		const struct __c64_v4l2_window compat;
	} *u = (void *)p;

	u->native.global_alpha = u->compat.global_alpha;
	u->native.bitmap =  compat_ptr(u->compat.bitmap);
	u->native.clipcount = u->compat.clipcount;
	u->native.clips =  compat_ptr(u->compat.clips);
	u->native.chromakey = u->compat.chromakey;
	u->native.field = u->compat.field;
	BUILD_BUG_ON(sizeof(u->compat.w) != sizeof(u->native.w));
	memmove(&u->native.w, &u->compat.w, sizeof(u->native.w));
}
static __always_inline __maybe_unused void
__to_c64_v4l2_window(struct v4l2_window *p)
{
	union {
		struct __c64_v4l2_window compat;
		const struct v4l2_window native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.w) != sizeof(u->compat.w));
	memmove(&u->compat.w, &u->native.w, sizeof(u->compat.w));
	u->compat.field = u->native.field;
	u->compat.chromakey = u->native.chromakey;
	u->compat.clips =  (__c64_uptr __force)(user_uintptr_t)u->native.clips;
	u->compat.clipcount = u->native.clipcount;
	u->compat.bitmap =  (__c64_uptr __force)(user_uintptr_t)u->native.bitmap;
	u->compat.global_alpha = u->native.global_alpha;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_window_2(struct v4l2_window *native, const struct __c64_v4l2_window *compat)
{

	BUILD_BUG_ON(sizeof(compat->w) != sizeof(native->w));
	memcpy(&native->w, &compat->w, sizeof(native->w));
	native->field = compat->field;
	native->chromakey = compat->chromakey;
	native->clips =  compat_ptr(compat->clips);
	native->clipcount = compat->clipcount;
	native->bitmap =  compat_ptr(compat->bitmap);
	native->global_alpha = compat->global_alpha;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_window_2(struct __c64_v4l2_window *compat, const struct v4l2_window *native)
{

	BUILD_BUG_ON(sizeof(native->w) != sizeof(compat->w));
	memcpy(&compat->w, &native->w, sizeof(compat->w));
	compat->field = native->field;
	compat->chromakey = native->chromakey;
	compat->clips =  (__c64_uptr __force)(user_uintptr_t)native->clips;
	compat->clipcount = native->clipcount;
	compat->bitmap =  (__c64_uptr __force)(user_uintptr_t)native->bitmap;
	compat->global_alpha = native->global_alpha;
}
struct __c64_v4l2_ext_control {
	__u32 id;
	__u32 size;
	__u32 reserved2[1];
	union {
		__s32 value;
		__s64 value64;
		__c64_uptr string;
		__c64_uptr p_u8;
		__c64_uptr p_u16;
		__c64_uptr p_u32;
		__c64_uptr p_s32;
		__c64_uptr p_s64;
		__c64_uptr p_area;
		__c64_uptr p_rect;
		__c64_uptr p_h264_sps;
		__c64_uptr p_h264_pps;
		__c64_uptr p_h264_scaling_matrix;
		__c64_uptr p_h264_pred_weights;
		__c64_uptr p_h264_slice_params;
		__c64_uptr p_h264_decode_params;
		__c64_uptr p_fwht_params;
		__c64_uptr p_vp8_frame;
		__c64_uptr p_mpeg2_sequence;
		__c64_uptr p_mpeg2_picture;
		__c64_uptr p_mpeg2_quantisation;
		__c64_uptr p_vp9_compressed_hdr_probs;
		__c64_uptr p_vp9_frame;
		__c64_uptr p_hevc_sps;
		__c64_uptr p_hevc_pps;
		__c64_uptr p_hevc_slice_params;
		__c64_uptr p_hevc_scaling_matrix;
		__c64_uptr p_hevc_decode_params;
		__c64_uptr p_av1_sequence;
		__c64_uptr p_av1_tile_group_entry;
		__c64_uptr p_av1_frame;
		__c64_uptr p_av1_film_grain;
		__c64_uptr p_hdr10_cll_info;
		__c64_uptr p_hdr10_mastering_display;
		__c64_uptr ptr;
	} __attribute__((packed));
} __attribute__((packed));

struct __c64_v4l2_ext_controls {
	union {
		__u32 ctrl_class;
		__u32 which;
	};
	__u32 count;
	__u32 error_idx;
	__s32 request_fd;
	__u32 reserved[1];
	__c64_uptr controls;
};

static __always_inline __maybe_unused void
__from_c64_v4l2_ext_controls(struct v4l2_ext_controls *p)
{
	union {
		struct v4l2_ext_controls native;
		const struct __c64_v4l2_ext_controls compat;
	} *u = (void *)p;

	u->native.controls =  compat_ptr(u->compat.controls);
	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.request_fd = u->compat.request_fd;
	u->native.error_idx = u->compat.error_idx;
	u->native.count = u->compat.count;
	u->native.which = u->compat.which;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_ext_controls(struct v4l2_ext_controls *p)
{
	union {
		struct __c64_v4l2_ext_controls compat;
		const struct v4l2_ext_controls native;
	} *u = (void *)p;

	u->compat.which = u->native.which;
	u->compat.count = u->native.count;
	u->compat.error_idx = u->native.error_idx;
	u->compat.request_fd = u->native.request_fd;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
	u->compat.controls =  (__c64_uptr __force)(user_uintptr_t)u->native.controls;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_ext_controls_2(struct v4l2_ext_controls *native, const struct __c64_v4l2_ext_controls *compat)
{

	native->which = compat->which;
	native->count = compat->count;
	native->error_idx = compat->error_idx;
	native->request_fd = compat->request_fd;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
	native->controls =  compat_ptr(compat->controls);
}
static __always_inline __maybe_unused void
__to_c64_v4l2_ext_controls_2(struct __c64_v4l2_ext_controls *compat, const struct v4l2_ext_controls *native)
{

	compat->which = native->which;
	compat->count = native->count;
	compat->error_idx = native->error_idx;
	compat->request_fd = native->request_fd;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
	compat->controls =  (__c64_uptr __force)(user_uintptr_t)native->controls;
}
struct __c64_v4l2_format {
	__u32	 type;
	union {
		struct v4l2_pix_format		pix;     /* V4L2_BUF_TYPE_VIDEO_CAPTURE */
		struct v4l2_pix_format_mplane	pix_mp;  /* V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE */
		struct __c64_v4l2_window		win;     /* V4L2_BUF_TYPE_VIDEO_OVERLAY */
		struct v4l2_vbi_format		vbi;     /* V4L2_BUF_TYPE_VBI_CAPTURE */
		struct v4l2_sliced_vbi_format	sliced;  /* V4L2_BUF_TYPE_SLICED_VBI_CAPTURE */
		struct v4l2_sdr_format		sdr;     /* V4L2_BUF_TYPE_SDR_CAPTURE */
		struct v4l2_meta_format		meta;    /* V4L2_BUF_TYPE_META_CAPTURE */
		__u8	raw_data[200];                   /* user-defined */
	} fmt;
};

struct __c64_v4l2_create_buffers {
	__u32			index;
	__u32			count;
	__u32			memory;
	struct __c64_v4l2_format	format;
	__u32			capabilities;
	__u32			flags;
	__u32			max_num_buffers;
	__u32			reserved[5];
};

