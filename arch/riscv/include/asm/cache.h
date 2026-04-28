/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2017 Chen Liqin <liqin.chen@sunplusct.com>
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_CACHE_H
#define _ASM_RISCV_CACHE_H

#define L1_CACHE_SHIFT		6

#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)

#ifdef CONFIG_CHERI_KERNEL
#define ARCH_KMALLOC_MINALIGN	__SIZEOF_POINTER__
#endif

#ifdef CONFIG_RISCV_DMA_NONCOHERENT
#define ARCH_DMA_MINALIGN L1_CACHE_BYTES
#ifndef ARCH_KMALLOC_MINALIGN
#define ARCH_KMALLOC_MINALIGN	(8)
#endif
#endif

/*
 * RISC-V requires the stack pointer to be 16-byte aligned, so ensure that
 * the flat loader aligns it accordingly.
 */
#ifndef CONFIG_MMU
#define ARCH_SLAB_MINALIGN	16
#elif defined(CONFIG_CHERI_KERNEL)
#define ARCH_SLAB_MINALIGN	__SIZEOF_POINTER__
#endif

#ifndef __ASSEMBLER__

extern int dma_cache_alignment;
#ifdef CONFIG_RISCV_DMA_NONCOHERENT
#define dma_get_cache_alignment dma_get_cache_alignment
static inline int dma_get_cache_alignment(void)
{
	return dma_cache_alignment;
}
#endif

#endif	/* __ASSEMBLER__ */

#endif /* _ASM_RISCV_CACHE_H */
