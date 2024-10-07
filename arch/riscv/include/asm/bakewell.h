/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_BAKEWELL_H
#define __ASM_BAKEWELL_H

#ifdef CONFIG_RISCV_CHERI_BAKEWELL

extern void __init bakewell_init(void);
extern void __init init_cap_relocs(void * __capability rw,
				   void * __capability rx);
extern void __init bakewell_caps_init(uintcap_t rootcap);

extern unsigned long cheri_mbit_mask;
extern unsigned long cheri_mbit_value;
extern unsigned char cheri_hybrid_support;
extern unsigned char scmode_capmode_value;
extern unsigned char acperm_legacy;

#else

static inline void bakewell_init(void)
{
}

#endif

#endif /* __ASM_BAKEWELL_H */
