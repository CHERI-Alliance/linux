#pragma once


#include <linux/compat.h>


struct __c64_dtv_property {
	__u32 cmd;
	__u32 reserved[3];
	union {
		__u32 data;
		struct dtv_fe_stats st;
		struct {
			__u8 data[32];
			__u32 len;
			__u32 reserved1[3];
			/// UAPI: NoConvert: Unused in kernel
			__c64_uptr reserved2;
		} buffer;
	} u;
	int result;
} __attribute__ ((packed));

struct __c64_dtv_properties {
	__u32 num;
	__c64_uptr props;
};

static __always_inline __maybe_unused void
__from_c64_dtv_properties(struct dtv_properties *p)
{
	union {
		struct dtv_properties native;
		const struct __c64_dtv_properties compat;
	} *u = (void *)p;

	u->native.props =  compat_ptr(u->compat.props);
	u->native.num = u->compat.num;
}
static __always_inline __maybe_unused void
__to_c64_dtv_properties(struct dtv_properties *p)
{
	union {
		struct __c64_dtv_properties compat;
		const struct dtv_properties native;
	} *u = (void *)p;

	u->compat.num = u->native.num;
	u->compat.props =  (__c64_uptr __force)(user_uintptr_t)u->native.props;
}
static __always_inline __maybe_unused void
__from_c64_dtv_properties_2(struct dtv_properties *native, const struct __c64_dtv_properties *compat)
{

	native->num = compat->num;
	native->props =  compat_ptr(compat->props);
}
static __always_inline __maybe_unused void
__to_c64_dtv_properties_2(struct __c64_dtv_properties *compat, const struct dtv_properties *native)
{

	compat->num = native->num;
	compat->props =  (__c64_uptr __force)(user_uintptr_t)native->props;
}
