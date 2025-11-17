#pragma once


#include <linux/compat.h>


struct __c64_xt_entry_match {
	union {
		struct {
			__u16 match_size;

			/* Used by userspace */
			char name[XT_EXTENSION_MAXNAMELEN];
			__u8 revision;
		} user;
		struct {
			__u16 match_size;

			/* Used inside the kernel */
			union {
				/// UAPI: NoConvert: Kernel only
				__c64_uptr match;
				/// UAPI: NoConvert: Kernel only
				__c64_uptr __match;
			};
		} kernel;

		/* Total length */
		__u16 match_size;
	} u;

	unsigned char data[];
};

struct __c64_xt_entry_target {
	union {
		struct {
			__u16 target_size;

			/* Used by userspace */
			char name[XT_EXTENSION_MAXNAMELEN];
			__u8 revision;
		} user;
		struct {
			__u16 target_size;

			/* Used inside the kernel */
			union {
				/// UAPI: NoConvert: Kernel only
				__c64_uptr target;
				/// UAPI: NoConvert: Kernel only
				__c64_uptr __target;
			};
		} kernel;

		/* Total length */
		__u16 target_size;
	} u;

	unsigned char data[0];
};

struct __c64_xt_standard_target {
	struct __c64_xt_entry_target target;
	int verdict;
};

struct __c64_xt_error_target {
	struct __c64_xt_entry_target target;
	char errorname[XT_FUNCTION_MAXNAMELEN];
};

struct __c64_xt_counters {
	union {
		struct {
			__u64 pcnt, bcnt;	/* Packet and byte counters */
		};
		/** UAPI: NoConvert: FIXCHERI: Move this out of the UAPI */
		__c64_uptr percpu;
	};
};

static __always_inline __maybe_unused void
__from_c64_xt_counters(struct xt_counters *p)
{
	union {
		struct xt_counters native;
		const struct __c64_xt_counters compat;
	} *u = (void *)p;

	u->native.bcnt = u->compat.bcnt;
	u->native.pcnt = u->compat.pcnt;
}
static __always_inline __maybe_unused void
__to_c64_xt_counters(struct xt_counters *p)
{
	union {
		struct __c64_xt_counters compat;
		const struct xt_counters native;
	} *u = (void *)p;

	u->compat.pcnt = u->native.pcnt;
	u->compat.bcnt = u->native.bcnt;
}
static __always_inline __maybe_unused void
__from_c64_xt_counters_2(struct xt_counters *native, const struct __c64_xt_counters *compat)
{

	native->pcnt = compat->pcnt;
	native->bcnt = compat->bcnt;
}
static __always_inline __maybe_unused void
__to_c64_xt_counters_2(struct __c64_xt_counters *compat, const struct xt_counters *native)
{

	compat->pcnt = native->pcnt;
	compat->bcnt = native->bcnt;
}
struct __c64_xt_counters_info {
	/* Which table. */
	char name[XT_TABLE_MAXNAMELEN];

	unsigned int num_counters;

	/* The counters (actually `number' of these). */
	struct __c64_xt_counters counters[];
};

