/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_BAKEWELL_H
#define __ASM_BAKEWELL_H

#ifdef CONFIG_RISCV_BAKEWELL

extern void __init bakewell_init(void);

#else

static inline void bakewell_init(void)
{
}

#endif

#endif /* __ASM_BAKEWELL_H */
