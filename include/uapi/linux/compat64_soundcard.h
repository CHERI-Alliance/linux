#pragma once


#include <linux/compat.h>


typedef struct __c64_buffmem_desc {
		__c64_uptr buffer;
		int size;
	} __c64_buffmem_desc;

static __always_inline __maybe_unused void
__from_c64_buffmem_desc(struct buffmem_desc *p)
{
	union {
		struct buffmem_desc native;
		const struct __c64_buffmem_desc compat;
	} *u = (void *)p;

	u->native.size = u->compat.size;
	u->native.buffer =  compat_ptr(u->compat.buffer);
}
static __always_inline __maybe_unused void
__to_c64_buffmem_desc(struct buffmem_desc *p)
{
	union {
		struct __c64_buffmem_desc compat;
		const struct buffmem_desc native;
	} *u = (void *)p;

	u->compat.buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.buffer;
	u->compat.size = u->native.size;
}
static __always_inline __maybe_unused void
__from_c64_buffmem_desc_2(struct buffmem_desc *native, const struct __c64_buffmem_desc *compat)
{

	native->buffer =  compat_ptr(compat->buffer);
	native->size = compat->size;
}
static __always_inline __maybe_unused void
__to_c64_buffmem_desc_2(struct __c64_buffmem_desc *compat, const struct buffmem_desc *native)
{

	compat->buffer =  (__c64_uptr __force)(user_uintptr_t)native->buffer;
	compat->size = native->size;
}
