#pragma once


#include <linux/compat.h>


struct __c64_ivtv_dma_frame {
	enum v4l2_buf_type type; /* V4L2_BUF_TYPE_VIDEO_OUTPUT */
	__u32 pixelformat;	 /* 0 == same as destination */
	__c64_uptr y_source;   /* if NULL and type == V4L2_BUF_TYPE_VIDEO_OUTPUT,
				    then just switch to user DMA YUV output mode */
	__c64_uptr uv_source;  /* Unused for RGB pixelformats */
	struct v4l2_rect src;
	struct v4l2_rect dst;
	__u32 src_width;
	__u32 src_height;
};

static __always_inline __maybe_unused void
__from_c64_ivtv_dma_frame(struct ivtv_dma_frame *p)
{
	union {
		struct ivtv_dma_frame native;
		const struct __c64_ivtv_dma_frame compat;
	} *u = (void *)p;

	u->native.src_height = u->compat.src_height;
	u->native.src_width = u->compat.src_width;
	BUILD_BUG_ON(sizeof(u->compat.dst) != sizeof(u->native.dst));
	memmove(&u->native.dst, &u->compat.dst, sizeof(u->native.dst));
	BUILD_BUG_ON(sizeof(u->compat.src) != sizeof(u->native.src));
	memmove(&u->native.src, &u->compat.src, sizeof(u->native.src));
	u->native.uv_source =  compat_ptr(u->compat.uv_source);
	u->native.y_source =  compat_ptr(u->compat.y_source);
	u->native.pixelformat = u->compat.pixelformat;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_ivtv_dma_frame(struct ivtv_dma_frame *p)
{
	union {
		struct __c64_ivtv_dma_frame compat;
		const struct ivtv_dma_frame native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.pixelformat = u->native.pixelformat;
	u->compat.y_source =  (__c64_uptr __force)(user_uintptr_t)u->native.y_source;
	u->compat.uv_source =  (__c64_uptr __force)(user_uintptr_t)u->native.uv_source;
	BUILD_BUG_ON(sizeof(u->native.src) != sizeof(u->compat.src));
	memmove(&u->compat.src, &u->native.src, sizeof(u->compat.src));
	BUILD_BUG_ON(sizeof(u->native.dst) != sizeof(u->compat.dst));
	memmove(&u->compat.dst, &u->native.dst, sizeof(u->compat.dst));
	u->compat.src_width = u->native.src_width;
	u->compat.src_height = u->native.src_height;
}
static __always_inline __maybe_unused void
__from_c64_ivtv_dma_frame_2(struct ivtv_dma_frame *native, const struct __c64_ivtv_dma_frame *compat)
{

	native->type = compat->type;
	native->pixelformat = compat->pixelformat;
	native->y_source =  compat_ptr(compat->y_source);
	native->uv_source =  compat_ptr(compat->uv_source);
	BUILD_BUG_ON(sizeof(compat->src) != sizeof(native->src));
	memcpy(&native->src, &compat->src, sizeof(native->src));
	BUILD_BUG_ON(sizeof(compat->dst) != sizeof(native->dst));
	memcpy(&native->dst, &compat->dst, sizeof(native->dst));
	native->src_width = compat->src_width;
	native->src_height = compat->src_height;
}
static __always_inline __maybe_unused void
__to_c64_ivtv_dma_frame_2(struct __c64_ivtv_dma_frame *compat, const struct ivtv_dma_frame *native)
{

	compat->type = native->type;
	compat->pixelformat = native->pixelformat;
	compat->y_source =  (__c64_uptr __force)(user_uintptr_t)native->y_source;
	compat->uv_source =  (__c64_uptr __force)(user_uintptr_t)native->uv_source;
	BUILD_BUG_ON(sizeof(native->src) != sizeof(compat->src));
	memcpy(&compat->src, &native->src, sizeof(compat->src));
	BUILD_BUG_ON(sizeof(native->dst) != sizeof(compat->dst));
	memcpy(&compat->dst, &native->dst, sizeof(compat->dst));
	compat->src_width = native->src_width;
	compat->src_height = native->src_height;
}
