#pragma once


#include <linux/compat.h>


struct __c64_atm_iobuf {
	int length;
	__c64_uptr buffer;
};

static __always_inline __maybe_unused void
__from_c64_atm_iobuf(struct atm_iobuf *p)
{
	union {
		struct atm_iobuf native;
		const struct __c64_atm_iobuf compat;
	} *u = (void *)p;

	u->native.buffer =  compat_ptr(u->compat.buffer);
	u->native.length = u->compat.length;
}
static __always_inline __maybe_unused void
__to_c64_atm_iobuf(struct atm_iobuf *p)
{
	union {
		struct __c64_atm_iobuf compat;
		const struct atm_iobuf native;
	} *u = (void *)p;

	u->compat.length = u->native.length;
	u->compat.buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.buffer;
}
static __always_inline __maybe_unused void
__from_c64_atm_iobuf_2(struct atm_iobuf *native, const struct __c64_atm_iobuf *compat)
{

	native->length = compat->length;
	native->buffer =  compat_ptr(compat->buffer);
}
static __always_inline __maybe_unused void
__to_c64_atm_iobuf_2(struct __c64_atm_iobuf *compat, const struct atm_iobuf *native)
{

	compat->length = native->length;
	compat->buffer =  (__c64_uptr __force)(user_uintptr_t)native->buffer;
}
