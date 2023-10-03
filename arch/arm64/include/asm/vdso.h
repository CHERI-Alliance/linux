/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Limited
 */
#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H

/*
 * Default link address for the vDSO.
 * Since we randomise the VDSO mapping, there's little point in trying
 * to prelink this.
 */
#define VDSO_LBASE	0x0

#define __VVAR_PAGES    2

#ifndef __ASSEMBLY__

#ifdef CONFIG_COMPAT_VDSO
#include <generated/vdso32-offsets.h>
#endif

#define VDSO_SYMBOL(base, name)						   \
({									   \
	(unsigned long)(vdso_offset_##name - VDSO_LBASE + (unsigned long)(base)); \
})

extern char vdso_start[], vdso_end[];
extern char vdso32_start[], vdso32_end[];
extern char vdso_purecap_start[], vdso_purecap_end[];

#endif /* !__ASSEMBLY__ */

#endif /* __ASM_VDSO_H */
