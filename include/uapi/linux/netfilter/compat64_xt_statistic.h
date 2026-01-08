#pragma once


#include <linux/compat.h>


struct __c64_xt_statistic_info {
	__u16			mode;
	__u16			flags;
	union {
		struct {
			__u32	probability;
		} random;
		struct {
			__u32	every;
			__u32	packet;
			__u32	count; /* unused */
		} nth;
	} u;
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr master;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __master;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_statistic_info(struct xt_statistic_info *p)
{
	union {
		struct xt_statistic_info native;
		const struct __c64_xt_statistic_info compat;
	} *u = (void *)p;

	u->native.u.nth.count = u->compat.u.nth.count;
	u->native.u.nth.packet = u->compat.u.nth.packet;
	u->native.u.nth.every = u->compat.u.nth.every;
	u->native.u.random.probability = u->compat.u.random.probability;
	u->native.flags = u->compat.flags;
	u->native.mode = u->compat.mode;
}
static __always_inline __maybe_unused void
__to_c64_xt_statistic_info(struct xt_statistic_info *p)
{
	union {
		struct __c64_xt_statistic_info compat;
		const struct xt_statistic_info native;
	} *u = (void *)p;

	u->compat.mode = u->native.mode;
	u->compat.flags = u->native.flags;
	u->compat.u.random.probability = u->native.u.random.probability;
	u->compat.u.nth.every = u->native.u.nth.every;
	u->compat.u.nth.packet = u->native.u.nth.packet;
	u->compat.u.nth.count = u->native.u.nth.count;
}
static __always_inline __maybe_unused void
__from_c64_xt_statistic_info_2(struct xt_statistic_info *native, const struct __c64_xt_statistic_info *compat)
{

	native->mode = compat->mode;
	native->flags = compat->flags;
	native->u.random.probability = compat->u.random.probability;
	native->u.nth.every = compat->u.nth.every;
	native->u.nth.packet = compat->u.nth.packet;
	native->u.nth.count = compat->u.nth.count;
}
static __always_inline __maybe_unused void
__to_c64_xt_statistic_info_2(struct __c64_xt_statistic_info *compat, const struct xt_statistic_info *native)
{

	compat->mode = native->mode;
	compat->flags = native->flags;
	compat->u.random.probability = native->u.random.probability;
	compat->u.nth.every = native->u.nth.every;
	compat->u.nth.packet = native->u.nth.packet;
	compat->u.nth.count = native->u.nth.count;
}
