#ifndef ___DRIVERS_FIRMWARE_EFI_EFISTUB_MODE_H
#define ___DRIVERS_FIRMWARE_EFI_EFISTUB_MODE_H

/*
 * Force the EFI stub to be built in pure aarch64 mode.
 * This means disabling Morello & CHERI related config options
 */
#undef CONFIG_ARM64_MORELLO
#undef CONFIG_CHERI_PURECAP_UABI

#endif /*___DRIVERS_FIRMWARE_EFI_EFISTUB_MODE_H*/
