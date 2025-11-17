#pragma once


#include <linux/compat.h>


struct __c64_atmif_sioc {
	int number;
	int length;
	__c64_uptr arg;
};

static __always_inline __maybe_unused void
__from_c64_atmif_sioc(struct atmif_sioc *p)
{
	union {
		struct atmif_sioc native;
		const struct __c64_atmif_sioc compat;
	} *u = (void *)p;

	u->native.arg =  compat_ptr(u->compat.arg);
	u->native.length = u->compat.length;
	u->native.number = u->compat.number;
}
static __always_inline __maybe_unused void
__to_c64_atmif_sioc(struct atmif_sioc *p)
{
	union {
		struct __c64_atmif_sioc compat;
		const struct atmif_sioc native;
	} *u = (void *)p;

	u->compat.number = u->native.number;
	u->compat.length = u->native.length;
	u->compat.arg =  (__c64_uptr __force)(user_uintptr_t)u->native.arg;
}
static __always_inline __maybe_unused void
__from_c64_atmif_sioc_2(struct atmif_sioc *native, const struct __c64_atmif_sioc *compat)
{

	native->number = compat->number;
	native->length = compat->length;
	native->arg =  compat_ptr(compat->arg);
}
static __always_inline __maybe_unused void
__to_c64_atmif_sioc_2(struct __c64_atmif_sioc *compat, const struct atmif_sioc *native)
{

	compat->number = native->number;
	compat->length = native->length;
	compat->arg =  (__c64_uptr __force)(user_uintptr_t)native->arg;
}
