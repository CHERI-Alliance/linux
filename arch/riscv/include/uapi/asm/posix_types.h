/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * This file is generally used by user-level software, so you need to
 * be a little careful about namespace pollution etc.  Also, we cannot
 * assume GCC is being used.
 */

#ifndef __RISCV_POSIX_TYPES_H
#define __RISCV_POSIX_TYPES_H

#define _KERNEL_NSIG		64
#define _KERNEL_NSIG_BPW	(8 * __SIZEOF_LONG__)
#define _KERNEL_NSIG_WORDS	(_KERNEL_NSIG / _KERNEL_NSIG_BPW)

typedef struct {
	unsigned long sig[_KERNEL_NSIG_WORDS];
} __kernel_sigset_t;

#include <asm-generic/posix_types.h>

#endif /* __RISCV_POSIX_TYPES_H */
