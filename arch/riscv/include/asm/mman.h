/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MMAN_H__
#define __ASM_MMAN_H__

#include <linux/compiler.h>
#include <linux/types.h>
#include <uapi/asm/mman.h>

#ifdef CONFIG_CHERI_KERNEL

static inline unsigned long arch_calc_vm_flag_bits(unsigned long flags)
{
	unsigned long ret = 0;

	if ((flags & MAP_TYPE) == 0x02 /* MAP_PRIVATE */)
		ret |= VM_READ_CAPS | VM_WRITE_CAPS;

	return ret;
}
#define arch_calc_vm_flag_bits(flags) arch_calc_vm_flag_bits(flags)

#endif

#endif /* ! __ASM_MMAN_H__ */
