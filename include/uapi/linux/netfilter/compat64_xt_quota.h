#pragma once


#include <linux/compat.h>


struct __c64_xt_quota_info {
	__u32 flags;
	__u32 pad;
	__aligned_u64 quota;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr master;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __master;
	};
};

static __always_inline __maybe_unused void
__from_c64_xt_quota_info(struct xt_quota_info *p)
{
	union {
		struct xt_quota_info native;
		const struct __c64_xt_quota_info compat;
	} *u = (void *)p;

	u->native.quota = u->compat.quota;
	u->native.pad = u->compat.pad;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_xt_quota_info(struct xt_quota_info *p)
{
	union {
		struct __c64_xt_quota_info compat;
		const struct xt_quota_info native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.pad = u->native.pad;
	u->compat.quota = u->native.quota;
}
static __always_inline __maybe_unused void
__from_c64_xt_quota_info_2(struct xt_quota_info *native, const struct __c64_xt_quota_info *compat)
{

	native->flags = compat->flags;
	native->pad = compat->pad;
	native->quota = compat->quota;
}
static __always_inline __maybe_unused void
__to_c64_xt_quota_info_2(struct __c64_xt_quota_info *compat, const struct xt_quota_info *native)
{

	compat->flags = native->flags;
	compat->pad = native->pad;
	compat->quota = native->quota;
}
