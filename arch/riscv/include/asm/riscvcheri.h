/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_RISCVCHERI_H
#define __ASM_RISCVCHERI_H

#ifdef CONFIG_CHERI_KERNEL

extern void __init riscv_cheri_init(void);
extern void __init init_cap_relocs(uintcap_t inf);
extern void __init riscv_cheri_caps_init(uintcap_t inf);

extern unsigned long cheri_mbit_mask;
extern unsigned long cheri_mbit_value;
extern unsigned char cheri_hybrid_support;
extern unsigned char scmode_capmode_value;
extern unsigned char has_xtval2;
extern unsigned char has_cheri_levels;

#else

static inline void riscv_cheri_init(void)
{
}

#endif

#endif /* __ASM_RISCVCHERI_H */
