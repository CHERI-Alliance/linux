/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_CHERI_H
#define __ASM_CHERI_H


#ifdef __CHERI_BW_CAP_PERMISSION_CAPABILITY__
#error "Please update to a CHERI v9.5 compliant compiler."
#endif

#define CHERI_PERM_STORE		0x000001
#define CHERI_PERM_MUTABLE_LOAD		0x000002
#define CHERI_PERM_ELEVATED_LOAD	0x000004
#define CHERI_PERM_STORE_LOCAL_CAP	0x000008
#define CHERI_PERM_GLOBAL		0x000010
#define CHERI_PERM_CAP_RW		0x000020
#define CHERI_PERM_SW_00		0x000040
#define CHERI_PERM_SW_01		0x000080
#define CHERI_PERM_SW_02		0x000100
#define CHERI_PERM_SW_03		0x000200

#define CHERI_PERM_SYSTEM_REGS		0x010000
#define CHERI_PERM_EXECUTE		0x020000
#define CHERI_PERM_LOAD			0x040000


#define ZCHERILEVELS_PERMS \
	(CHERI_PERM_ELEVATED_LOAD | CHERI_PERM_STORE_LOCAL_CAP \
	 | CHERI_PERM_GLOBAL)

#define CHERI_PERM_SW_VMEM		CHERI_PERM_SW_00

#define CHERI_PERMS_LOAD_CAP \
	(CHERI_PERM_CAP_RW | CHERI_PERM_ELEVATED_LOAD | CHERI_PERM_MUTABLE_LOAD)

#define CHERI_PERMS_STORE_CAP \
	(CHERI_PERM_CAP_RW | CHERI_PERM_STORE_LOCAL_CAP)

#define CHERI_PERMS_READ \
	(CHERI_PERM_LOAD | CHERI_PERMS_LOAD_CAP)

#define CHERI_PERMS_WRITE \
	(CHERI_PERM_STORE | CHERI_PERMS_STORE_CAP)

#define CHERI_PERMS_EXEC \
	(CHERI_PERM_EXECUTE | CHERI_PERM_SYSTEM_REGS)

#ifdef CONFIG_CHERI_KERNEL

#ifndef __ASSEMBLY__

extern bool __riscv_cheri_is_capmode(void * __capability cap);
#define cheri_is_capmode(x) __riscv_cheri_is_capmode(x)

extern void * __capability riscv_cheri_set_capmode(void * __capability cap);
extern void * __capability riscv_cheri_clear_capmode(void * __capability cap);

#endif

#endif

#endif /* __ASM_CHERI_H */
