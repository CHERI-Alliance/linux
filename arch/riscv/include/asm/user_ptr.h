/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_USER_PTR_H
#define __ASM_USER_PTR_H

#include <linux/cheri.h>
#include <linux/mman.h>
#include <linux/sched/task_stack.h>
#include <asm/processor.h>

#ifdef CONFIG_CHERI_PURECAP_UABI

static inline
user_ptr_perms_t arch_user_ptr_owning_perms_from_prot(int prot, unsigned long vm_flags)
{
	struct pt_regs *regs = task_pt_regs(current);
	cheri_perms_t perms = 0;

	if (prot & PROT_EXEC) {
		if (cheri_perms_get(regs->epc) & CHERI_BW_PERM_SYSTEM_REGS)
			perms |= CHERI_BW_PERM_SYSTEM_REGS;
	}

	return perms;
}
#define arch_user_ptr_owning_perms_from_prot arch_user_ptr_owning_perms_from_prot

#endif /* CONFIG_CHERI_PURECAP_UABI */

#endif /* __ASM_USER_PTR_H */
