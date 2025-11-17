#pragma once


#include <linux/compat.h>


struct __c64_input_mask {
	__u32 type;
	__u32 codes_size;
	__c64_ptr64 codes_ptr;
};

static __always_inline __maybe_unused void
__from_c64_input_mask(struct input_mask *p)
{
	union {
		struct input_mask native;
		const struct __c64_input_mask compat;
	} *u = (void *)p;

	u->native.codes_ptr = (user_uintptr_t)compat_ptr(u->compat.codes_ptr);
	u->native.codes_size = u->compat.codes_size;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_input_mask(struct input_mask *p)
{
	union {
		struct __c64_input_mask compat;
		const struct input_mask native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.codes_size = u->native.codes_size;
	u->compat.codes_ptr = (__c64_ptr64 __force)u->native.codes_ptr;
}
static __always_inline __maybe_unused void
__from_c64_input_mask_2(struct input_mask *native, const struct __c64_input_mask *compat)
{

	native->type = compat->type;
	native->codes_size = compat->codes_size;
	native->codes_ptr = (user_uintptr_t)compat_ptr(compat->codes_ptr);
}
static __always_inline __maybe_unused void
__to_c64_input_mask_2(struct __c64_input_mask *compat, const struct input_mask *native)
{

	compat->type = native->type;
	compat->codes_size = native->codes_size;
	compat->codes_ptr = (__c64_ptr64 __force)native->codes_ptr;
}
struct __c64_ff_periodic_effect {
	__u16 waveform;
	__u16 period;
	__s16 magnitude;
	__s16 offset;
	__u16 phase;

	struct ff_envelope envelope;

	__u32 custom_len;
	__c64_uptr custom_data;
};

static __always_inline __maybe_unused void
__from_c64_ff_periodic_effect(struct ff_periodic_effect *p)
{
	union {
		struct ff_periodic_effect native;
		const struct __c64_ff_periodic_effect compat;
	} *u = (void *)p;

	u->native.custom_data =  compat_ptr(u->compat.custom_data);
	u->native.custom_len = u->compat.custom_len;
	BUILD_BUG_ON(sizeof(u->compat.envelope) != sizeof(u->native.envelope));
	memmove(&u->native.envelope, &u->compat.envelope, sizeof(u->native.envelope));
	u->native.phase = u->compat.phase;
	u->native.offset = u->compat.offset;
	u->native.magnitude = u->compat.magnitude;
	u->native.period = u->compat.period;
	u->native.waveform = u->compat.waveform;
}
static __always_inline __maybe_unused void
__to_c64_ff_periodic_effect(struct ff_periodic_effect *p)
{
	union {
		struct __c64_ff_periodic_effect compat;
		const struct ff_periodic_effect native;
	} *u = (void *)p;

	u->compat.waveform = u->native.waveform;
	u->compat.period = u->native.period;
	u->compat.magnitude = u->native.magnitude;
	u->compat.offset = u->native.offset;
	u->compat.phase = u->native.phase;
	BUILD_BUG_ON(sizeof(u->native.envelope) != sizeof(u->compat.envelope));
	memmove(&u->compat.envelope, &u->native.envelope, sizeof(u->compat.envelope));
	u->compat.custom_len = u->native.custom_len;
	u->compat.custom_data =  (__c64_uptr __force)(user_uintptr_t)u->native.custom_data;
}
static __always_inline __maybe_unused void
__from_c64_ff_periodic_effect_2(struct ff_periodic_effect *native, const struct __c64_ff_periodic_effect *compat)
{

	native->waveform = compat->waveform;
	native->period = compat->period;
	native->magnitude = compat->magnitude;
	native->offset = compat->offset;
	native->phase = compat->phase;
	BUILD_BUG_ON(sizeof(compat->envelope) != sizeof(native->envelope));
	memcpy(&native->envelope, &compat->envelope, sizeof(native->envelope));
	native->custom_len = compat->custom_len;
	native->custom_data =  compat_ptr(compat->custom_data);
}
static __always_inline __maybe_unused void
__to_c64_ff_periodic_effect_2(struct __c64_ff_periodic_effect *compat, const struct ff_periodic_effect *native)
{

	compat->waveform = native->waveform;
	compat->period = native->period;
	compat->magnitude = native->magnitude;
	compat->offset = native->offset;
	compat->phase = native->phase;
	BUILD_BUG_ON(sizeof(native->envelope) != sizeof(compat->envelope));
	memcpy(&compat->envelope, &native->envelope, sizeof(compat->envelope));
	compat->custom_len = native->custom_len;
	compat->custom_data =  (__c64_uptr __force)(user_uintptr_t)native->custom_data;
}
struct __c64_ff_effect {
	__u16 type;
	__s16 id;
	__u16 direction;
	struct ff_trigger trigger;
	struct ff_replay replay;

	union {
		struct ff_constant_effect constant;
		struct ff_ramp_effect ramp;
		struct __c64_ff_periodic_effect periodic;
		struct ff_condition_effect condition[2]; /* One for each axis */
		struct ff_rumble_effect rumble;
	} u;
};

