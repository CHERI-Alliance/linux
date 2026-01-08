#pragma once


#include <linux/compat.h>


struct __c64_ivtvfb_dma_frame {
	__c64_uptr source;
	unsigned long dest_offset;
	int count;
};

static __always_inline __maybe_unused void
__from_c64_ivtvfb_dma_frame(struct ivtvfb_dma_frame *p)
{
	union {
		struct ivtvfb_dma_frame native;
		const struct __c64_ivtvfb_dma_frame compat;
	} *u = (void *)p;

	u->native.count = u->compat.count;
	u->native.dest_offset = u->compat.dest_offset;
	u->native.source =  compat_ptr(u->compat.source);
}
static __always_inline __maybe_unused void
__to_c64_ivtvfb_dma_frame(struct ivtvfb_dma_frame *p)
{
	union {
		struct __c64_ivtvfb_dma_frame compat;
		const struct ivtvfb_dma_frame native;
	} *u = (void *)p;

	u->compat.source =  (__c64_uptr __force)(user_uintptr_t)u->native.source;
	u->compat.dest_offset = u->native.dest_offset;
	u->compat.count = u->native.count;
}
static __always_inline __maybe_unused void
__from_c64_ivtvfb_dma_frame_2(struct ivtvfb_dma_frame *native, const struct __c64_ivtvfb_dma_frame *compat)
{

	native->source =  compat_ptr(compat->source);
	native->dest_offset = compat->dest_offset;
	native->count = compat->count;
}
static __always_inline __maybe_unused void
__to_c64_ivtvfb_dma_frame_2(struct __c64_ivtvfb_dma_frame *compat, const struct ivtvfb_dma_frame *native)
{

	compat->source =  (__c64_uptr __force)(user_uintptr_t)native->source;
	compat->dest_offset = native->dest_offset;
	compat->count = native->count;
}
