/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef PARSE_VDSO_H
#define PARSE_VDSO_H

#include <stdint.h>
#include <sys/auxv.h>

/*
 * To use this vDSO parser, first call one of the vdso_init_* functions.
 * If you've already parsed auxv, then pass the value of AT_SYSINFO_EHDR
 * to vdso_init_from_sysinfo_ehdr.  Otherwise pass auxv to vdso_init_from_auxv.
 * Then call vdso_sym for each symbol you want.  For example, to look up
 * gettimeofday on x86_64, use:
 *
 *     <some pointer> = vdso_sym("LINUX_2.6", "gettimeofday");
 * or
 *     <some pointer> = vdso_sym("LINUX_2.6", "__vdso_gettimeofday");
 *
 * vdso_sym will return 0 if the symbol doesn't exist or if the init function
 * failed or was not called.  vdso_sym is a little slow, so its return value
 * should be cached.
 *
 * vdso_sym is threadsafe; the init functions are not.
 *
 * These are the prototypes:
 */
void *vdso_sym(const char *version, const char *name);
void vdso_init_from_sysinfo_ehdr(uintptr_t base);
void vdso_init_from_auxv(void *auxv);

/*
 * Under PCuABI, pointers in the auxiliary vector can no longer be represented
 * as unsigned long as they are now capabilities. Get the capability to the
 * vDSO using getauxptr() instead, which returns a a capability instead of
 * unsigned long.
 */
static inline uintptr_t get_sysinfo_ehdr()
{
#ifdef __CHERI_PURE_CAPABILITY__
	return getauxptr(AT_SYSINFO_EHDR);
#else
	return (uintptr_t)getauxval(AT_SYSINFO_EHDR);
#endif
}

#endif
