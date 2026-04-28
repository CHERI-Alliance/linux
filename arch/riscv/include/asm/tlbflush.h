/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2009 Chen Liqin <liqin.chen@sunplusct.com>
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_TLBFLUSH_H
#define _ASM_RISCV_TLBFLUSH_H

#include <linux/mm_types.h>
#include <asm/smp.h>
#include <asm/errata_list.h>

#define FLUSH_TLB_MAX_SIZE      ((unsigned long)-1)
#define FLUSH_TLB_NO_ASID       ((unsigned long)-1)

#ifdef CONFIG_MMU
static inline void local_flush_tlb_all(void)
{
	__asm__ __volatile__ ("sfence.vma" : : : "memory");
}

static inline void local_flush_tlb_all_asid(unsigned long asid)
{
	if (asid != FLUSH_TLB_NO_ASID)
		ALT_SFENCE_VMA_ASID(asid);
	else
		local_flush_tlb_all();
}

/* Flush one page from local TLB */
static inline void local_flush_tlb_page(__ptraddr_t addr)
{
	ALT_SFENCE_VMA_ADDR(addr);
}

static inline void local_flush_tlb_page_asid(__ptraddr_t addr,
					     unsigned long asid)
{
	if (asid != FLUSH_TLB_NO_ASID)
		ALT_SFENCE_VMA_ADDR_ASID(addr, asid);
	else
		local_flush_tlb_page(addr);
}

void flush_tlb_all(void);
void flush_tlb_mm(struct mm_struct *mm);
void flush_tlb_mm_range(struct mm_struct *mm, __ptraddr_t start,
			__ptraddr_t end, unsigned int page_size);
void flush_tlb_page(struct vm_area_struct *vma, __ptraddr_t addr);
void flush_tlb_range(struct vm_area_struct *vma, __ptraddr_t start,
		     __ptraddr_t end);
void flush_tlb_kernel_range(__ptraddr_t start, __ptraddr_t end);
void local_flush_tlb_kernel_range(__ptraddr_t start, __ptraddr_t end);
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define __HAVE_ARCH_FLUSH_PMD_TLB_RANGE
void flush_pmd_tlb_range(struct vm_area_struct *vma, __ptraddr_t start,
			unsigned long end);
void flush_pud_tlb_range(struct vm_area_struct *vma, __ptraddr_t start,
			 unsigned long end);
#endif

bool arch_tlbbatch_should_defer(struct mm_struct *mm);
void arch_tlbbatch_add_pending(struct arch_tlbflush_unmap_batch *batch,
		struct mm_struct *mm, __ptraddr_t start, __ptraddr_t end);
void arch_tlbbatch_flush(struct arch_tlbflush_unmap_batch *batch);

extern unsigned long tlb_flush_all_threshold;
#else /* CONFIG_MMU */
#define local_flush_tlb_all()			do { } while (0)
#endif /* CONFIG_MMU */

#endif /* _ASM_RISCV_TLBFLUSH_H */
