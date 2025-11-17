#pragma once


#include <linux/compat.h>


struct __c64_xt_hashlimit_info {
	char name [IFNAMSIZ];		/* name */
	struct hashlimit_cfg cfg;

	/* Used internally by the kernel */
	__c64_uptr hinfo;
	union {
		__c64_uptr ptr;
		__c64_uptr master;
	} u;
};

static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_info(struct xt_hashlimit_info *p)
{
	union {
		struct xt_hashlimit_info native;
		const struct __c64_xt_hashlimit_info compat;
	} *u = (void *)p;

	u->native.u.ptr =  compat_ptr(u->compat.u.ptr);
	u->native.hinfo =  compat_ptr(u->compat.hinfo);
	BUILD_BUG_ON(sizeof(u->compat.cfg) != sizeof(u->native.cfg));
	memmove(&u->native.cfg, &u->compat.cfg, sizeof(u->native.cfg));
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_info(struct xt_hashlimit_info *p)
{
	union {
		struct __c64_xt_hashlimit_info compat;
		const struct xt_hashlimit_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	BUILD_BUG_ON(sizeof(u->native.cfg) != sizeof(u->compat.cfg));
	memmove(&u->compat.cfg, &u->native.cfg, sizeof(u->compat.cfg));
	u->compat.hinfo =  (__c64_uptr __force)(user_uintptr_t)u->native.hinfo;
	u->compat.u.ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.u.ptr;
}
static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_info_2(struct xt_hashlimit_info *native, const struct __c64_xt_hashlimit_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	BUILD_BUG_ON(sizeof(compat->cfg) != sizeof(native->cfg));
	memcpy(&native->cfg, &compat->cfg, sizeof(native->cfg));
	native->hinfo =  compat_ptr(compat->hinfo);
	native->u.ptr =  compat_ptr(compat->u.ptr);
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_info_2(struct __c64_xt_hashlimit_info *compat, const struct xt_hashlimit_info *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	BUILD_BUG_ON(sizeof(native->cfg) != sizeof(compat->cfg));
	memcpy(&compat->cfg, &native->cfg, sizeof(compat->cfg));
	compat->hinfo =  (__c64_uptr __force)(user_uintptr_t)native->hinfo;
	compat->u.ptr =  (__c64_uptr __force)(user_uintptr_t)native->u.ptr;
}
struct __c64_xt_hashlimit_mtinfo1 {
	char name[IFNAMSIZ];
	struct hashlimit_cfg1 cfg;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr hinfo;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __hinfo;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo1(struct xt_hashlimit_mtinfo1 *p)
{
	union {
		struct xt_hashlimit_mtinfo1 native;
		const struct __c64_xt_hashlimit_mtinfo1 compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.cfg) != sizeof(u->native.cfg));
	memmove(&u->native.cfg, &u->compat.cfg, sizeof(u->native.cfg));
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo1(struct xt_hashlimit_mtinfo1 *p)
{
	union {
		struct __c64_xt_hashlimit_mtinfo1 compat;
		const struct xt_hashlimit_mtinfo1 native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	BUILD_BUG_ON(sizeof(u->native.cfg) != sizeof(u->compat.cfg));
	memmove(&u->compat.cfg, &u->native.cfg, sizeof(u->compat.cfg));
}
static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo1_2(struct xt_hashlimit_mtinfo1 *native, const struct __c64_xt_hashlimit_mtinfo1 *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	BUILD_BUG_ON(sizeof(compat->cfg) != sizeof(native->cfg));
	memcpy(&native->cfg, &compat->cfg, sizeof(native->cfg));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo1_2(struct __c64_xt_hashlimit_mtinfo1 *compat, const struct xt_hashlimit_mtinfo1 *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	BUILD_BUG_ON(sizeof(native->cfg) != sizeof(compat->cfg));
	memcpy(&compat->cfg, &native->cfg, sizeof(compat->cfg));
}
struct __c64_xt_hashlimit_mtinfo2 {
	char name[NAME_MAX];
	struct hashlimit_cfg2 cfg;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr hinfo;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __hinfo;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo2(struct xt_hashlimit_mtinfo2 *p)
{
	union {
		struct xt_hashlimit_mtinfo2 native;
		const struct __c64_xt_hashlimit_mtinfo2 compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.cfg) != sizeof(u->native.cfg));
	memmove(&u->native.cfg, &u->compat.cfg, sizeof(u->native.cfg));
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo2(struct xt_hashlimit_mtinfo2 *p)
{
	union {
		struct __c64_xt_hashlimit_mtinfo2 compat;
		const struct xt_hashlimit_mtinfo2 native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	BUILD_BUG_ON(sizeof(u->native.cfg) != sizeof(u->compat.cfg));
	memmove(&u->compat.cfg, &u->native.cfg, sizeof(u->compat.cfg));
}
static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo2_2(struct xt_hashlimit_mtinfo2 *native, const struct __c64_xt_hashlimit_mtinfo2 *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	BUILD_BUG_ON(sizeof(compat->cfg) != sizeof(native->cfg));
	memcpy(&native->cfg, &compat->cfg, sizeof(native->cfg));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo2_2(struct __c64_xt_hashlimit_mtinfo2 *compat, const struct xt_hashlimit_mtinfo2 *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	BUILD_BUG_ON(sizeof(native->cfg) != sizeof(compat->cfg));
	memcpy(&compat->cfg, &native->cfg, sizeof(compat->cfg));
}
struct __c64_xt_hashlimit_mtinfo3 {
	char name[NAME_MAX];
	struct hashlimit_cfg3 cfg;

	/* Used internally by the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr hinfo;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __hinfo;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo3(struct xt_hashlimit_mtinfo3 *p)
{
	union {
		struct xt_hashlimit_mtinfo3 native;
		const struct __c64_xt_hashlimit_mtinfo3 compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.cfg) != sizeof(u->native.cfg));
	memmove(&u->native.cfg, &u->compat.cfg, sizeof(u->native.cfg));
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo3(struct xt_hashlimit_mtinfo3 *p)
{
	union {
		struct __c64_xt_hashlimit_mtinfo3 compat;
		const struct xt_hashlimit_mtinfo3 native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	BUILD_BUG_ON(sizeof(u->native.cfg) != sizeof(u->compat.cfg));
	memmove(&u->compat.cfg, &u->native.cfg, sizeof(u->compat.cfg));
}
static __always_inline __maybe_unused void
__from_c64_xt_hashlimit_mtinfo3_2(struct xt_hashlimit_mtinfo3 *native, const struct __c64_xt_hashlimit_mtinfo3 *compat)
{

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	BUILD_BUG_ON(sizeof(compat->cfg) != sizeof(native->cfg));
	memcpy(&native->cfg, &compat->cfg, sizeof(native->cfg));
}
static __always_inline __maybe_unused void
__to_c64_xt_hashlimit_mtinfo3_2(struct __c64_xt_hashlimit_mtinfo3 *compat, const struct xt_hashlimit_mtinfo3 *native)
{

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	BUILD_BUG_ON(sizeof(native->cfg) != sizeof(compat->cfg));
	memcpy(&compat->cfg, &native->cfg, sizeof(compat->cfg));
}
