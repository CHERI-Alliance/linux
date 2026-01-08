#pragma once


#include <linux/compat.h>


struct __c64_xt_nfacct_match_info {
	char		name[NFACCT_NAME_MAX];
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr nfacct;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __nfacct;
	};
};

static __always_inline __maybe_unused void
__from_c64_xt_nfacct_match_info(struct xt_nfacct_match_info *p)
{
	union {
		struct xt_nfacct_match_info native;
		const struct __c64_xt_nfacct_match_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_nfacct_match_info(struct xt_nfacct_match_info *p)
{
	union {
		struct __c64_xt_nfacct_match_info compat;
		const struct xt_nfacct_match_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
}
static __always_inline __maybe_unused void
__from_c64_xt_nfacct_match_info_2(struct xt_nfacct_match_info *native, const struct __c64_xt_nfacct_match_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
}
static __always_inline __maybe_unused void
__to_c64_xt_nfacct_match_info_2(struct __c64_xt_nfacct_match_info *compat, const struct xt_nfacct_match_info *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
}
struct __c64_xt_nfacct_match_info_v1 {
	char		name[NFACCT_NAME_MAX];
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr nfacct;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __nfacct;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_nfacct_match_info_v1(struct xt_nfacct_match_info_v1 *p)
{
	union {
		struct xt_nfacct_match_info_v1 native;
		const struct __c64_xt_nfacct_match_info_v1 compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_nfacct_match_info_v1(struct xt_nfacct_match_info_v1 *p)
{
	union {
		struct __c64_xt_nfacct_match_info_v1 compat;
		const struct xt_nfacct_match_info_v1 native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
}
static __always_inline __maybe_unused void
__from_c64_xt_nfacct_match_info_v1_2(struct xt_nfacct_match_info_v1 *native, const struct __c64_xt_nfacct_match_info_v1 *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
}
static __always_inline __maybe_unused void
__to_c64_xt_nfacct_match_info_v1_2(struct __c64_xt_nfacct_match_info_v1 *compat, const struct xt_nfacct_match_info_v1 *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
}
