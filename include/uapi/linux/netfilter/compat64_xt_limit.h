#pragma once


#include <linux/compat.h>


struct __c64_xt_rateinfo {
	__u32 avg;    /* Average secs between packets * scale */
	__u32 burst;  /* Period multiplier for upper limit. */

	/* Used internally by the kernel */
	unsigned long prev; /* moved to xt_limit_priv */
	__u32 credit; /* moved to xt_limit_priv */
	__u32 credit_cap, cost;

	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr master;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __master;
	};
};

static __always_inline __maybe_unused void
__from_c64_xt_rateinfo(struct xt_rateinfo *p)
{
	union {
		struct xt_rateinfo native;
		const struct __c64_xt_rateinfo compat;
	} *u = (void *)p;

	u->native.cost = u->compat.cost;
	u->native.credit_cap = u->compat.credit_cap;
	u->native.credit = u->compat.credit;
	u->native.prev = u->compat.prev;
	u->native.burst = u->compat.burst;
	u->native.avg = u->compat.avg;
}
static __always_inline __maybe_unused void
__to_c64_xt_rateinfo(struct xt_rateinfo *p)
{
	union {
		struct __c64_xt_rateinfo compat;
		const struct xt_rateinfo native;
	} *u = (void *)p;

	u->compat.avg = u->native.avg;
	u->compat.burst = u->native.burst;
	u->compat.prev = u->native.prev;
	u->compat.credit = u->native.credit;
	u->compat.credit_cap = u->native.credit_cap;
	u->compat.cost = u->native.cost;
}
static __always_inline __maybe_unused void
__from_c64_xt_rateinfo_2(struct xt_rateinfo *native, const struct __c64_xt_rateinfo *compat)
{

	native->avg = compat->avg;
	native->burst = compat->burst;
	native->prev = compat->prev;
	native->credit = compat->credit;
	native->credit_cap = compat->credit_cap;
	native->cost = compat->cost;
}
static __always_inline __maybe_unused void
__to_c64_xt_rateinfo_2(struct __c64_xt_rateinfo *compat, const struct xt_rateinfo *native)
{

	compat->avg = native->avg;
	compat->burst = native->burst;
	compat->prev = native->prev;
	compat->credit = native->credit;
	compat->credit_cap = native->credit_cap;
	compat->cost = native->cost;
}
