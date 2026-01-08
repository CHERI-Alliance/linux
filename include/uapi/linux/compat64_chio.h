#pragma once


#include <linux/compat.h>


struct __c64_changer_element_status {
	int             ces_type;
	__c64_uptr ces_data;
};

static __always_inline __maybe_unused void
__from_c64_changer_element_status(struct changer_element_status *p)
{
	union {
		struct changer_element_status native;
		const struct __c64_changer_element_status compat;
	} *u = (void *)p;

	u->native.ces_data =  compat_ptr(u->compat.ces_data);
	u->native.ces_type = u->compat.ces_type;
}
static __always_inline __maybe_unused void
__to_c64_changer_element_status(struct changer_element_status *p)
{
	union {
		struct __c64_changer_element_status compat;
		const struct changer_element_status native;
	} *u = (void *)p;

	u->compat.ces_type = u->native.ces_type;
	u->compat.ces_data =  (__c64_uptr __force)(user_uintptr_t)u->native.ces_data;
}
static __always_inline __maybe_unused void
__from_c64_changer_element_status_2(struct changer_element_status *native, const struct __c64_changer_element_status *compat)
{

	native->ces_type = compat->ces_type;
	native->ces_data =  compat_ptr(compat->ces_data);
}
static __always_inline __maybe_unused void
__to_c64_changer_element_status_2(struct __c64_changer_element_status *compat, const struct changer_element_status *native)
{

	compat->ces_type = native->ces_type;
	compat->ces_data =  (__c64_uptr __force)(user_uintptr_t)native->ces_data;
}
