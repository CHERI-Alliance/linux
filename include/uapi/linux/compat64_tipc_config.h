#pragma once


#include <linux/compat.h>


struct __c64_tlv_list_desc {
	__c64_uptr tlv_ptr;	/* ptr to current TLV */
	__u32 tlv_space;		/* # bytes from curr TLV to list end */
};

static __always_inline __maybe_unused void
__from_c64_tlv_list_desc(struct tlv_list_desc *p)
{
	union {
		struct tlv_list_desc native;
		const struct __c64_tlv_list_desc compat;
	} *u = (void *)p;

	u->native.tlv_space = u->compat.tlv_space;
	u->native.tlv_ptr =  compat_ptr(u->compat.tlv_ptr);
}
static __always_inline __maybe_unused void
__to_c64_tlv_list_desc(struct tlv_list_desc *p)
{
	union {
		struct __c64_tlv_list_desc compat;
		const struct tlv_list_desc native;
	} *u = (void *)p;

	u->compat.tlv_ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.tlv_ptr;
	u->compat.tlv_space = u->native.tlv_space;
}
static __always_inline __maybe_unused void
__from_c64_tlv_list_desc_2(struct tlv_list_desc *native, const struct __c64_tlv_list_desc *compat)
{

	native->tlv_ptr =  compat_ptr(compat->tlv_ptr);
	native->tlv_space = compat->tlv_space;
}
static __always_inline __maybe_unused void
__to_c64_tlv_list_desc_2(struct __c64_tlv_list_desc *compat, const struct tlv_list_desc *native)
{

	compat->tlv_ptr =  (__c64_uptr __force)(user_uintptr_t)native->tlv_ptr;
	compat->tlv_space = native->tlv_space;
}
