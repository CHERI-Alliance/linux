// SPDX-License-Identifier: GPL-2.0-only
/*
 * 32-bit compatibility support for ELF format executables and core dumps.
 *
 * Copyright (C) 2007 Red Hat, Inc.  All rights reserved.
 *
 * Red Hat Author: Roland McGrath.
 *
 * This file is used in a 64-bit kernel that wants to support 32-bit ELF.
 * asm/elf.h is responsible for defining the compat_* and COMPAT_* macros
 * used below, with definitions appropriate for 32-bit ABI compatibility.
 *
 * We use macros to rename the ABI types and machine-dependent
 * functions used in binfmt_elf.c to compat versions.
 */

#ifdef CONFIG_COMPAT32
#include <linux/elfcore-compat.h>
#else
/*
 * TODO [PCuABI] - The header linux/elfcore-compat.h needs some changes for
 * complete compat64 support so for time being include minimum definitions
 * from linux/elf.h.
 */
#include <linux/elf.h>
#endif /* CONFIG_COMPAT32 */
#include <linux/time.h>

#define ELF_COMPAT	1

/*
 * Below redefinitions are common for both 32 and 64 bit compat
 * and are required due to the addition of PCuABI changes to linux/elf.h.
 */
#undef elf_stack_item_t
#define elf_stack_item_t			elf_addr_t

#undef elf_uaddr_to_user_ptr
#define elf_uaddr_to_user_ptr(addr)		addr

#ifdef CONFIG_CHERI_PURECAP_UABI

#undef elf_copy_to_user_stack
#define elf_copy_to_user_stack(to, from, len)	copy_to_user(to, from, len)

#undef elf_stack_put_user_ptr
#define elf_stack_put_user_ptr(val, ptr)	put_user(user_ptr_addr(val), ptr)

#undef elf_stack_put_user
#define elf_stack_put_user(val, ptr)		put_user(val, ptr)

#endif /* CONFIG_CHERI_PURECAP_UABI */

#ifdef CONFIG_COMPAT32
/*
 * Rename the basic ELF layout types to refer to the 32-bit class of files.
 */
#undef	ELF_CLASS
#define ELF_CLASS	ELFCLASS32

#undef	elfhdr
#undef	elf_phdr
#undef	elf_shdr
#undef	elf_note
#undef	elf_addr_t
#undef	ELF_GNU_PROPERTY_ALIGN
#define elfhdr		elf32_hdr
#define elf_phdr	elf32_phdr
#define elf_shdr	elf32_shdr
#define elf_note	elf32_note
#define elf_addr_t	Elf32_Addr
#define ELF_GNU_PROPERTY_ALIGN	ELF32_GNU_PROPERTY_ALIGN

/*
 * Some data types as stored in coredump.
 */
#define user_long_t		compat_long_t
#define user_siginfo_t		compat_siginfo_t
#define copy_siginfo_to_external	copy_siginfo_to_external32

/*
 * The machine-dependent core note format types are defined in elfcore-compat.h,
 * which requires asm/elf.h to define compat_elf_gregset_t et al.
 */
#define elf_prstatus	compat_elf_prstatus
#define elf_prstatus_common	compat_elf_prstatus_common
#define elf_prpsinfo	compat_elf_prpsinfo

#undef ns_to_kernel_old_timeval
#define ns_to_kernel_old_timeval ns_to_old_timeval32

/*
 * To use this file, asm/elf.h must define compat_elf_check_arch.
 * The other following macros can be defined if the compat versions
 * differ from the native ones, or omitted when they match.
 */

#ifdef	COMPAT_ELF_PLATFORM
#undef	ELF_PLATFORM
#define	ELF_PLATFORM		COMPAT_ELF_PLATFORM
#endif

#ifdef	COMPAT_ELF_HWCAP
#undef	ELF_HWCAP
#define	ELF_HWCAP		COMPAT_ELF_HWCAP
#endif

#ifdef	COMPAT_ELF_HWCAP2
#undef	ELF_HWCAP2
#define	ELF_HWCAP2		COMPAT_ELF_HWCAP2
#endif

#ifdef	COMPAT_ELF_ET_DYN_BASE
#undef	ELF_ET_DYN_BASE
#define	ELF_ET_DYN_BASE		COMPAT_ELF_ET_DYN_BASE
#endif

#ifdef	COMPAT_ELF_PLAT_INIT
#undef	ELF_PLAT_INIT
#define	ELF_PLAT_INIT		COMPAT_ELF_PLAT_INIT
#endif

#ifdef compat_arch_setup_additional_pages
#define COMPAT_ARCH_SETUP_ADDITIONAL_PAGES(bprm, ex, interpreter) \
	compat_arch_setup_additional_pages(bprm, interpreter)
#endif

#ifdef	COMPAT_ARCH_SETUP_ADDITIONAL_PAGES
#undef	ARCH_HAS_SETUP_ADDITIONAL_PAGES
#define ARCH_HAS_SETUP_ADDITIONAL_PAGES 1
#undef	ARCH_SETUP_ADDITIONAL_PAGES
#define	ARCH_SETUP_ADDITIONAL_PAGES COMPAT_ARCH_SETUP_ADDITIONAL_PAGES
#endif

#ifdef	compat_elf_read_implies_exec
#undef	elf_read_implies_exec
#define	elf_read_implies_exec compat_elf_read_implies_exec
#endif

/*
 * Rename a few of the symbols that binfmt_elf.c will define.
 * These are all local so the names don't really matter, but it
 * might make some debugging less confusing not to duplicate them.
 */
#define elf_format		compat_elf_format
#define init_elf_binfmt		init_compat_elf_binfmt
#define exit_elf_binfmt		exit_compat_elf_binfmt
#define binfmt_elf_test_cases	compat_binfmt_elf_test_cases
#define binfmt_elf_test_suite	compat_binfmt_elf_test_suite

#endif /* CONFIG_COMPAT32 */

#undef	elf_check_arch
#define	elf_check_arch	compat_elf_check_arch

#ifdef	COMPAT_ARCH_DLINFO
#undef	ARCH_DLINFO
#define	ARCH_DLINFO		COMPAT_ARCH_DLINFO
#endif

#ifdef	COMPAT_SET_PERSONALITY
#undef	SET_PERSONALITY
#define	SET_PERSONALITY		COMPAT_SET_PERSONALITY
#endif

#ifdef	compat_start_thread
#define COMPAT_START_THREAD(ex, regs, new_ip, new_sp)	\
	compat_start_thread(regs, new_ip, new_sp)
#endif

#ifdef	COMPAT_START_THREAD
#undef	START_THREAD
#define START_THREAD(elf_ex, regs, elf_entry, bprm)		\
({								\
	COMPAT_START_THREAD(elf_ex, regs, elf_entry, bprm->p);	\
	0; /* binfmt_elf return value */			\
})
#endif

/*
 * We share all the actual code with the native (64-bit) version.
 */
#include "binfmt_elf.c"
