#pragma once


#include <linux/compat.h>


struct __c64_hdspm_mixer_ioctl {
	__c64_uptr mixer;
};

static __always_inline __maybe_unused void
__from_c64_hdspm_mixer_ioctl(struct hdspm_mixer_ioctl *p)
{
	union {
		struct hdspm_mixer_ioctl native;
		const struct __c64_hdspm_mixer_ioctl compat;
	} *u = (void *)p;

	u->native.mixer =  compat_ptr(u->compat.mixer);
}
static __always_inline __maybe_unused void
__to_c64_hdspm_mixer_ioctl(struct hdspm_mixer_ioctl *p)
{
	union {
		struct __c64_hdspm_mixer_ioctl compat;
		const struct hdspm_mixer_ioctl native;
	} *u = (void *)p;

	u->compat.mixer =  (__c64_uptr __force)(user_uintptr_t)u->native.mixer;
}
static __always_inline __maybe_unused void
__from_c64_hdspm_mixer_ioctl_2(struct hdspm_mixer_ioctl *native, const struct __c64_hdspm_mixer_ioctl *compat)
{

	native->mixer =  compat_ptr(compat->mixer);
}
static __always_inline __maybe_unused void
__to_c64_hdspm_mixer_ioctl_2(struct __c64_hdspm_mixer_ioctl *compat, const struct hdspm_mixer_ioctl *native)
{

	compat->mixer =  (__c64_uptr __force)(user_uintptr_t)native->mixer;
}
