/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_RISCVCHERI_H
#define __ASM_RISCVCHERI_H

#ifdef CONFIG_CHERI_KERNEL

extern void __init riscv_cheri_init(void);
extern void __init init_cap_relocs(uintcap_t inf);
extern void __init riscv_cheri_caps_init(uintcap_t inf);

extern unsigned char has_cheri_levels;

#else

static inline void riscv_cheri_init(void)
{
}
#endif

#ifdef CONFIG_RISCV_CHERI_DEBUG_USER_COPY
extern void do_warn_tags(void *, void *, size_t, void *);
#endif

#endif /* __ASM_RISCVCHERI_H */
