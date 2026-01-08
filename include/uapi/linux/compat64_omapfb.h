#pragma once


#include <linux/compat.h>


struct __c64_omapfb_memory_read {
	__u16 x;
	__u16 y;
	__u16 w;
	__u16 h;
	size_t buffer_size;
	__c64_uptr buffer;
};

static __always_inline __maybe_unused void
__from_c64_omapfb_memory_read(struct omapfb_memory_read *p)
{
	union {
		struct omapfb_memory_read native;
		const struct __c64_omapfb_memory_read compat;
	} *u = (void *)p;

	u->native.buffer =  compat_ptr(u->compat.buffer);
	u->native.buffer_size = u->compat.buffer_size;
	u->native.h = u->compat.h;
	u->native.w = u->compat.w;
	u->native.y = u->compat.y;
	u->native.x = u->compat.x;
}
static __always_inline __maybe_unused void
__to_c64_omapfb_memory_read(struct omapfb_memory_read *p)
{
	union {
		struct __c64_omapfb_memory_read compat;
		const struct omapfb_memory_read native;
	} *u = (void *)p;

	u->compat.x = u->native.x;
	u->compat.y = u->native.y;
	u->compat.w = u->native.w;
	u->compat.h = u->native.h;
	u->compat.buffer_size = u->native.buffer_size;
	u->compat.buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.buffer;
}
static __always_inline __maybe_unused void
__from_c64_omapfb_memory_read_2(struct omapfb_memory_read *native, const struct __c64_omapfb_memory_read *compat)
{

	native->x = compat->x;
	native->y = compat->y;
	native->w = compat->w;
	native->h = compat->h;
	native->buffer_size = compat->buffer_size;
	native->buffer =  compat_ptr(compat->buffer);
}
static __always_inline __maybe_unused void
__to_c64_omapfb_memory_read_2(struct __c64_omapfb_memory_read *compat, const struct omapfb_memory_read *native)
{

	compat->x = native->x;
	compat->y = native->y;
	compat->w = native->w;
	compat->h = native->h;
	compat->buffer_size = native->buffer_size;
	compat->buffer =  (__c64_uptr __force)(user_uintptr_t)native->buffer;
}
