/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MMAN_H__
#define __ASM_MMAN_H__

#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/mm.h>
#include <uapi/asm/mman.h>

static inline unsigned long arch_calc_vm_prot_bits(unsigned long prot,
						   unsigned long pkey __always_unused)
{
	unsigned long ret = 0;

	/*
	 * If PROT_WRITE was specified, force it to VM_READ | VM_WRITE.
	 * Only VM_WRITE means shadow stack.
	 */
	if (prot & PROT_WRITE)
		ret = (VM_READ | VM_WRITE);
	return ret;
}

#define arch_calc_vm_prot_bits(prot, pkey) arch_calc_vm_prot_bits(prot, pkey)

#ifdef CONFIG_CHERI_KERNEL

static inline unsigned long arch_calc_vm_flag_bits(struct file * file,
						   unsigned long flags)
{
	unsigned long ret = 0;

	if ((flags & MAP_TYPE) == 0x02 /* MAP_PRIVATE */)
		ret |= VM_READ_CAPS | VM_WRITE_CAPS;
	if (flags & MAP_ANONYMOUS)
		ret |= VM_READ_CAPS | VM_WRITE_CAPS;

	return ret;
}
#define arch_calc_vm_flag_bits(file, flags) arch_calc_vm_flag_bits(file, flags)

#endif

#endif /* ! __ASM_MMAN_H__ */
