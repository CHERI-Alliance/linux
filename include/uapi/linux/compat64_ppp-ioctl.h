#pragma once


#include <linux/compat.h>


struct __c64_ppp_option_data {
	__c64_uptr ptr;
	__u32	length;
	int	transmit;
};

static __always_inline __maybe_unused void
__from_c64_ppp_option_data(struct ppp_option_data *p)
{
	union {
		struct ppp_option_data native;
		const struct __c64_ppp_option_data compat;
	} *u = (void *)p;

	u->native.transmit = u->compat.transmit;
	u->native.length = u->compat.length;
	u->native.ptr =  compat_ptr(u->compat.ptr);
}
static __always_inline __maybe_unused void
__to_c64_ppp_option_data(struct ppp_option_data *p)
{
	union {
		struct __c64_ppp_option_data compat;
		const struct ppp_option_data native;
	} *u = (void *)p;

	u->compat.ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.ptr;
	u->compat.length = u->native.length;
	u->compat.transmit = u->native.transmit;
}
static __always_inline __maybe_unused void
__from_c64_ppp_option_data_2(struct ppp_option_data *native, const struct __c64_ppp_option_data *compat)
{

	native->ptr =  compat_ptr(compat->ptr);
	native->length = compat->length;
	native->transmit = compat->transmit;
}
static __always_inline __maybe_unused void
__to_c64_ppp_option_data_2(struct __c64_ppp_option_data *compat, const struct ppp_option_data *native)
{

	compat->ptr =  (__c64_uptr __force)(user_uintptr_t)native->ptr;
	compat->length = native->length;
	compat->transmit = native->transmit;
}
