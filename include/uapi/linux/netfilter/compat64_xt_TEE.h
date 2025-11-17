#pragma once


#include <linux/compat.h>


struct __c64_xt_tee_tginfo {
	union nf_inet_addr gw;
	char oif[16];

	/* used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr priv;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __priv;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_tee_tginfo(struct xt_tee_tginfo *p)
{
	union {
		struct xt_tee_tginfo native;
		const struct __c64_xt_tee_tginfo compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.oif) != sizeof(u->native.oif));
	memmove(&u->native.oif, &u->compat.oif, sizeof(u->native.oif));
	BUILD_BUG_ON(sizeof(u->compat.gw) != sizeof(u->native.gw));
	memmove(&u->native.gw, &u->compat.gw, sizeof(u->native.gw));
}
static __always_inline __maybe_unused void
__to_c64_xt_tee_tginfo(struct xt_tee_tginfo *p)
{
	union {
		struct __c64_xt_tee_tginfo compat;
		const struct xt_tee_tginfo native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.gw) != sizeof(u->compat.gw));
	memmove(&u->compat.gw, &u->native.gw, sizeof(u->compat.gw));
	BUILD_BUG_ON(sizeof(u->native.oif) != sizeof(u->compat.oif));
	memmove(&u->compat.oif, &u->native.oif, sizeof(u->compat.oif));
}
static __always_inline __maybe_unused void
__from_c64_xt_tee_tginfo_2(struct xt_tee_tginfo *native, const struct __c64_xt_tee_tginfo *compat)
{

	BUILD_BUG_ON(sizeof(compat->gw) != sizeof(native->gw));
	memcpy(&native->gw, &compat->gw, sizeof(native->gw));
	BUILD_BUG_ON(sizeof(compat->oif) != sizeof(native->oif));
	memcpy(&native->oif, &compat->oif, sizeof(native->oif));
}
static __always_inline __maybe_unused void
__to_c64_xt_tee_tginfo_2(struct __c64_xt_tee_tginfo *compat, const struct xt_tee_tginfo *native)
{

	BUILD_BUG_ON(sizeof(native->gw) != sizeof(compat->gw));
	memcpy(&compat->gw, &native->gw, sizeof(compat->gw));
	BUILD_BUG_ON(sizeof(native->oif) != sizeof(compat->oif));
	memcpy(&compat->oif, &native->oif, sizeof(compat->oif));
}
