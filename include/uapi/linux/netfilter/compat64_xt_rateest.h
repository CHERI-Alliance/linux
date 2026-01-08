#pragma once


#include <linux/compat.h>


struct __c64_xt_rateest_match_info {
	char			name1[IFNAMSIZ];
	char			name2[IFNAMSIZ];
	__u16		flags;
	__u16		mode;
	__u32		bps1;
	__u32		pps1;
	__u32		bps2;
	__u32		pps2;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr est1;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __est1;
	} __attribute__((aligned(8)));
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr est2;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __est2;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_rateest_match_info(struct xt_rateest_match_info *p)
{
	union {
		struct xt_rateest_match_info native;
		const struct __c64_xt_rateest_match_info compat;
	} *u = (void *)p;

	u->native.pps2 = u->compat.pps2;
	u->native.bps2 = u->compat.bps2;
	u->native.pps1 = u->compat.pps1;
	u->native.bps1 = u->compat.bps1;
	u->native.mode = u->compat.mode;
	u->native.flags = u->compat.flags;
	BUILD_BUG_ON(sizeof(u->compat.name2) != sizeof(u->native.name2));
	memmove(&u->native.name2, &u->compat.name2, sizeof(u->native.name2));
	BUILD_BUG_ON(sizeof(u->compat.name1) != sizeof(u->native.name1));
	memmove(&u->native.name1, &u->compat.name1, sizeof(u->native.name1));
}
static __always_inline __maybe_unused void
__to_c64_xt_rateest_match_info(struct xt_rateest_match_info *p)
{
	union {
		struct __c64_xt_rateest_match_info compat;
		const struct xt_rateest_match_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name1) != sizeof(u->compat.name1));
	memmove(&u->compat.name1, &u->native.name1, sizeof(u->compat.name1));
	BUILD_BUG_ON(sizeof(u->native.name2) != sizeof(u->compat.name2));
	memmove(&u->compat.name2, &u->native.name2, sizeof(u->compat.name2));
	u->compat.flags = u->native.flags;
	u->compat.mode = u->native.mode;
	u->compat.bps1 = u->native.bps1;
	u->compat.pps1 = u->native.pps1;
	u->compat.bps2 = u->native.bps2;
	u->compat.pps2 = u->native.pps2;
}
static __always_inline __maybe_unused void
__from_c64_xt_rateest_match_info_2(struct xt_rateest_match_info *native, const struct __c64_xt_rateest_match_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->name1) != sizeof(native->name1));
	memcpy(&native->name1, &compat->name1, sizeof(native->name1));
	BUILD_BUG_ON(sizeof(compat->name2) != sizeof(native->name2));
	memcpy(&native->name2, &compat->name2, sizeof(native->name2));
	native->flags = compat->flags;
	native->mode = compat->mode;
	native->bps1 = compat->bps1;
	native->pps1 = compat->pps1;
	native->bps2 = compat->bps2;
	native->pps2 = compat->pps2;
}
static __always_inline __maybe_unused void
__to_c64_xt_rateest_match_info_2(struct __c64_xt_rateest_match_info *compat, const struct xt_rateest_match_info *native)
{

	BUILD_BUG_ON(sizeof(native->name1) != sizeof(compat->name1));
	memcpy(&compat->name1, &native->name1, sizeof(compat->name1));
	BUILD_BUG_ON(sizeof(native->name2) != sizeof(compat->name2));
	memcpy(&compat->name2, &native->name2, sizeof(compat->name2));
	compat->flags = native->flags;
	compat->mode = native->mode;
	compat->bps1 = native->bps1;
	compat->pps1 = native->pps1;
	compat->bps2 = native->bps2;
	compat->pps2 = native->pps2;
}
