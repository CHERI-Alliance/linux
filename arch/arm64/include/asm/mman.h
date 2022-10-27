/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MMAN_H__
#define __ASM_MMAN_H__

#include <linux/compiler.h>
#include <linux/types.h>
#include <uapi/asm/mman.h>

static inline unsigned long arch_calc_vm_prot_bits(unsigned long prot,
	unsigned long pkey __always_unused)
{
	unsigned long ret = 0;

	if (system_supports_bti() && (prot & PROT_BTI))
		ret |= VM_ARM64_BTI;

	if (system_supports_mte() && (prot & PROT_MTE))
		ret |= VM_MTE;

	return ret;
}
#define arch_calc_vm_prot_bits(prot, pkey) arch_calc_vm_prot_bits(prot, pkey)

static inline unsigned long arch_calc_vm_flag_bits(unsigned long flags)
{
	unsigned long ret = 0;

	/*
	 * Only allow MTE on anonymous mappings as these are guaranteed to be
	 * backed by tags-capable memory. The vm_flags may be overridden by a
	 * filesystem supporting MTE (RAM-based).
	 */
	if (system_supports_mte() && (flags & MAP_ANONYMOUS))
		ret |= VM_MTE_ALLOWED;

	/*
	 * Allow capability tag access for private mappings as they don't pose
	 * the risk of leaking capabilities outside their original address-space.
	 *
	 * TODO [Morello]: There are certain situations where it is not possible
	 * to enable capability access in file-backed mappings, even private.
	 * This is notably the case for DAX, where backing pages are directly
	 * mapped, and the underlying storage is unlikely to support capability
	 * tags. Might need to explicitly allow or explicitly disallow certain
	 * filesystems.
	 */
	if (system_supports_morello() && ((flags & MAP_TYPE) == 0x02 /* MAP_PRIVATE */))
		ret |= VM_READ_CAPS | VM_WRITE_CAPS;

	return ret;
}
#define arch_calc_vm_flag_bits(flags) arch_calc_vm_flag_bits(flags)

static inline bool arch_validate_prot(unsigned long prot,
	unsigned long addr __always_unused)
{
	unsigned long supported = PROT_READ | PROT_WRITE | PROT_EXEC | PROT_SEM;

	if (system_supports_bti())
		supported |= PROT_BTI;

	if (system_supports_mte())
		supported |= PROT_MTE;

	return (prot & ~supported) == 0;
}
#define arch_validate_prot(prot, addr) arch_validate_prot(prot, addr)

static inline bool arch_validate_flags(unsigned long vm_flags)
{
	if (!system_supports_mte())
		return true;

	/* only allow VM_MTE if VM_MTE_ALLOWED has been set previously */
	return !(vm_flags & VM_MTE) || (vm_flags & VM_MTE_ALLOWED);
}
#define arch_validate_flags(vm_flags) arch_validate_flags(vm_flags)

#endif /* ! __ASM_MMAN_H__ */
