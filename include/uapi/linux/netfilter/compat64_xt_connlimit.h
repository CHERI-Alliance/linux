#pragma once


#include <linux/compat.h>


struct __c64_xt_connlimit_info {
	union {
		union nf_inet_addr mask;
		union {
			__be32 v4_mask;
			__be32 v6_mask[4];
		};
	};
	unsigned int limit;
	/* revision 1 */
	__u32 flags;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr data;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __data;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_connlimit_info(struct xt_connlimit_info *p)
{
	union {
		struct xt_connlimit_info native;
		const struct __c64_xt_connlimit_info compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.limit = u->compat.limit;
	BUILD_BUG_ON(sizeof(u->compat.mask) != sizeof(u->native.mask));
	memmove(&u->native.mask, &u->compat.mask, sizeof(u->native.mask));
}
static __always_inline __maybe_unused void
__to_c64_xt_connlimit_info(struct xt_connlimit_info *p)
{
	union {
		struct __c64_xt_connlimit_info compat;
		const struct xt_connlimit_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.mask) != sizeof(u->compat.mask));
	memmove(&u->compat.mask, &u->native.mask, sizeof(u->compat.mask));
	u->compat.limit = u->native.limit;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_xt_connlimit_info_2(struct xt_connlimit_info *native, const struct __c64_xt_connlimit_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->mask) != sizeof(native->mask));
	memcpy(&native->mask, &compat->mask, sizeof(native->mask));
	native->limit = compat->limit;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_xt_connlimit_info_2(struct __c64_xt_connlimit_info *compat, const struct xt_connlimit_info *native)
{

	BUILD_BUG_ON(sizeof(native->mask) != sizeof(compat->mask));
	memcpy(&compat->mask, &native->mask, sizeof(compat->mask));
	compat->limit = native->limit;
	compat->flags = native->flags;
}
