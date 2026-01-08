#pragma once


#include <linux/compat.h>


struct __c64_xt_led_info {
	char id[27];        /* Unique ID for this trigger in the LED class */
	__u8 always_blink;  /* Blink even if the LED is already on */
	__u32 delay;        /* Delay until LED is switched off after trigger */

	/* Kernel data used in the module */
	__c64_uptr internal_data __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_led_info(struct xt_led_info *p)
{
	union {
		struct xt_led_info native;
		const struct __c64_xt_led_info compat;
	} *u = (void *)p;

	u->native.internal_data =  compat_ptr(u->compat.internal_data);
	u->native.delay = u->compat.delay;
	u->native.always_blink = u->compat.always_blink;
	BUILD_BUG_ON(sizeof(u->compat.id) != sizeof(u->native.id));
	memmove(&u->native.id, &u->compat.id, sizeof(u->native.id));
}
static __always_inline __maybe_unused void
__to_c64_xt_led_info(struct xt_led_info *p)
{
	union {
		struct __c64_xt_led_info compat;
		const struct xt_led_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.id) != sizeof(u->compat.id));
	memmove(&u->compat.id, &u->native.id, sizeof(u->compat.id));
	u->compat.always_blink = u->native.always_blink;
	u->compat.delay = u->native.delay;
	u->compat.internal_data =  (__c64_uptr __force)(user_uintptr_t)u->native.internal_data;
}
static __always_inline __maybe_unused void
__from_c64_xt_led_info_2(struct xt_led_info *native, const struct __c64_xt_led_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->id) != sizeof(native->id));
	memcpy(&native->id, &compat->id, sizeof(native->id));
	native->always_blink = compat->always_blink;
	native->delay = compat->delay;
	native->internal_data =  compat_ptr(compat->internal_data);
}
static __always_inline __maybe_unused void
__to_c64_xt_led_info_2(struct __c64_xt_led_info *compat, const struct xt_led_info *native)
{

	BUILD_BUG_ON(sizeof(native->id) != sizeof(compat->id));
	memcpy(&compat->id, &native->id, sizeof(compat->id));
	compat->always_blink = native->always_blink;
	compat->delay = native->delay;
	compat->internal_data =  (__c64_uptr __force)(user_uintptr_t)native->internal_data;
}
