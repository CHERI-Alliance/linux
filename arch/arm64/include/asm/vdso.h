/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Limited
 */
#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H

#define __VDSO_PAGES    4

#ifndef __ASSEMBLER__

#define VDSO_SYMBOL(base, name)						   \
({									   \
	(unsigned long)(vdso_offset_##name + (unsigned long)(base)); \
})

extern char vdso_start[], vdso_end[];
extern char vdso32_start[], vdso32_end[];
extern char vdso_purecap_start[], vdso_purecap_end[];

#endif /* !__ASSEMBLER__ */

#endif /* __ASM_VDSO_H */
