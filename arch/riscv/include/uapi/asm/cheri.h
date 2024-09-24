/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI__ASM_CHERI_H
#define _UAPI__ASM_CHERI_H

/*
 * VMem software-defined capability permission, assigned to
 * the first software defined permission bit on Bakewell.
 */
#define CHERI_PERM_SW_00	(1 << 16)
#define CHERI_PERM_SW_01	(1 << 17)
#define CHERI_PERM_SW_02	(1 << 18)
#define CHERI_PERM_SW_03	(1 << 19)

#define CHERI_PERM_SW_VMEM	CHERI_PERM_SW_00

#endif /* _UAPI__ASM_CHERI_H */
