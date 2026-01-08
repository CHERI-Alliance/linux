#pragma once


#include <linux/compat.h>


struct __c64_hdsp_firmware {
	__c64_uptr firmware_data;	/* 24413 x 4 bytes */
};

static __always_inline __maybe_unused void
__from_c64_hdsp_firmware(struct hdsp_firmware *p)
{
	union {
		struct hdsp_firmware native;
		const struct __c64_hdsp_firmware compat;
	} *u = (void *)p;

	u->native.firmware_data =  compat_ptr(u->compat.firmware_data);
}
static __always_inline __maybe_unused void
__to_c64_hdsp_firmware(struct hdsp_firmware *p)
{
	union {
		struct __c64_hdsp_firmware compat;
		const struct hdsp_firmware native;
	} *u = (void *)p;

	u->compat.firmware_data =  (__c64_uptr __force)(user_uintptr_t)u->native.firmware_data;
}
static __always_inline __maybe_unused void
__from_c64_hdsp_firmware_2(struct hdsp_firmware *native, const struct __c64_hdsp_firmware *compat)
{

	native->firmware_data =  compat_ptr(compat->firmware_data);
}
static __always_inline __maybe_unused void
__to_c64_hdsp_firmware_2(struct __c64_hdsp_firmware *compat, const struct hdsp_firmware *native)
{

	compat->firmware_data =  (__c64_uptr __force)(user_uintptr_t)native->firmware_data;
}
