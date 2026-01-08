#pragma once


#include <linux/compat.h>


struct __c64_xt_ct_target_info {
	__u16 flags;
	__u16 zone;
	__u32 ct_events;
	__u32 exp_events;
	char helper[16];

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr ct;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __ct;
	}  __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_ct_target_info(struct xt_ct_target_info *p)
{
	union {
		struct xt_ct_target_info native;
		const struct __c64_xt_ct_target_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.helper) != sizeof(u->native.helper));
	memmove(&u->native.helper, &u->compat.helper, sizeof(u->native.helper));
	u->native.exp_events = u->compat.exp_events;
	u->native.ct_events = u->compat.ct_events;
	u->native.zone = u->compat.zone;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_xt_ct_target_info(struct xt_ct_target_info *p)
{
	union {
		struct __c64_xt_ct_target_info compat;
		const struct xt_ct_target_info native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.zone = u->native.zone;
	u->compat.ct_events = u->native.ct_events;
	u->compat.exp_events = u->native.exp_events;
	BUILD_BUG_ON(sizeof(u->native.helper) != sizeof(u->compat.helper));
	memmove(&u->compat.helper, &u->native.helper, sizeof(u->compat.helper));
}
static __always_inline __maybe_unused void
__from_c64_xt_ct_target_info_2(struct xt_ct_target_info *native, const struct __c64_xt_ct_target_info *compat)
{

	native->flags = compat->flags;
	native->zone = compat->zone;
	native->ct_events = compat->ct_events;
	native->exp_events = compat->exp_events;
	BUILD_BUG_ON(sizeof(compat->helper) != sizeof(native->helper));
	memcpy(&native->helper, &compat->helper, sizeof(native->helper));
}
static __always_inline __maybe_unused void
__to_c64_xt_ct_target_info_2(struct __c64_xt_ct_target_info *compat, const struct xt_ct_target_info *native)
{

	compat->flags = native->flags;
	compat->zone = native->zone;
	compat->ct_events = native->ct_events;
	compat->exp_events = native->exp_events;
	BUILD_BUG_ON(sizeof(native->helper) != sizeof(compat->helper));
	memcpy(&compat->helper, &native->helper, sizeof(compat->helper));
}
struct __c64_xt_ct_target_info_v1 {
	__u16 flags;
	__u16 zone;
	__u32 ct_events;
	__u32 exp_events;
	char helper[16];
	char timeout[32];

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr ct;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __ct;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_ct_target_info_v1(struct xt_ct_target_info_v1 *p)
{
	union {
		struct xt_ct_target_info_v1 native;
		const struct __c64_xt_ct_target_info_v1 compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.timeout) != sizeof(u->native.timeout));
	memmove(&u->native.timeout, &u->compat.timeout, sizeof(u->native.timeout));
	BUILD_BUG_ON(sizeof(u->compat.helper) != sizeof(u->native.helper));
	memmove(&u->native.helper, &u->compat.helper, sizeof(u->native.helper));
	u->native.exp_events = u->compat.exp_events;
	u->native.ct_events = u->compat.ct_events;
	u->native.zone = u->compat.zone;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_xt_ct_target_info_v1(struct xt_ct_target_info_v1 *p)
{
	union {
		struct __c64_xt_ct_target_info_v1 compat;
		const struct xt_ct_target_info_v1 native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.zone = u->native.zone;
	u->compat.ct_events = u->native.ct_events;
	u->compat.exp_events = u->native.exp_events;
	BUILD_BUG_ON(sizeof(u->native.helper) != sizeof(u->compat.helper));
	memmove(&u->compat.helper, &u->native.helper, sizeof(u->compat.helper));
	BUILD_BUG_ON(sizeof(u->native.timeout) != sizeof(u->compat.timeout));
	memmove(&u->compat.timeout, &u->native.timeout, sizeof(u->compat.timeout));
}
static __always_inline __maybe_unused void
__from_c64_xt_ct_target_info_v1_2(struct xt_ct_target_info_v1 *native, const struct __c64_xt_ct_target_info_v1 *compat)
{

	native->flags = compat->flags;
	native->zone = compat->zone;
	native->ct_events = compat->ct_events;
	native->exp_events = compat->exp_events;
	BUILD_BUG_ON(sizeof(compat->helper) != sizeof(native->helper));
	memcpy(&native->helper, &compat->helper, sizeof(native->helper));
	BUILD_BUG_ON(sizeof(compat->timeout) != sizeof(native->timeout));
	memcpy(&native->timeout, &compat->timeout, sizeof(native->timeout));
}
static __always_inline __maybe_unused void
__to_c64_xt_ct_target_info_v1_2(struct __c64_xt_ct_target_info_v1 *compat, const struct xt_ct_target_info_v1 *native)
{

	compat->flags = native->flags;
	compat->zone = native->zone;
	compat->ct_events = native->ct_events;
	compat->exp_events = native->exp_events;
	BUILD_BUG_ON(sizeof(native->helper) != sizeof(compat->helper));
	memcpy(&compat->helper, &native->helper, sizeof(compat->helper));
	BUILD_BUG_ON(sizeof(native->timeout) != sizeof(compat->timeout));
	memcpy(&compat->timeout, &native->timeout, sizeof(compat->timeout));
}
