/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_RISCV_FPROBE_H
#define _ASM_RISCV_FPROBE_H

#include <asm-generic/fprobe.h>

#ifdef CONFIG_CHERI_KERNEL
#undef ARCH_DEFINE_ENCODE_FPROBE_HEADER
#endif

#endif /* _ASM_RISCV_FPROBE_H */
