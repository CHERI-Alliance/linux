#pragma once


#include <linux/compat.h>


struct __c64_xt_rateest_target_info {
	char			name[IFNAMSIZ];
	__s8			interval;
	__u8		ewma_log;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr est;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __est;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_rateest_target_info(struct xt_rateest_target_info *p)
{
	union {
		struct xt_rateest_target_info native;
		const struct __c64_xt_rateest_target_info compat;
	} *u = (void *)p;

	u->native.ewma_log = u->compat.ewma_log;
	u->native.interval = u->compat.interval;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_rateest_target_info(struct xt_rateest_target_info *p)
{
	union {
		struct __c64_xt_rateest_target_info compat;
		const struct xt_rateest_target_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.interval = u->native.interval;
	u->compat.ewma_log = u->native.ewma_log;
}
static __always_inline __maybe_unused void
__from_c64_xt_rateest_target_info_2(struct xt_rateest_target_info *native, const struct __c64_xt_rateest_target_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->interval = compat->interval;
	native->ewma_log = compat->ewma_log;
}
static __always_inline __maybe_unused void
__to_c64_xt_rateest_target_info_2(struct __c64_xt_rateest_target_info *compat, const struct xt_rateest_target_info *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->interval = native->interval;
	compat->ewma_log = native->ewma_log;
}
