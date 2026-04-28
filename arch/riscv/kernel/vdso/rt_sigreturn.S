/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2014 Regents of the University of California
 */

#include <linux/linkage.h>
#include <asm/unistd.h>
#include <asm/assembler.h>

	.text
SYM_FUNC_START(__vdso_rt_sigreturn)
	vdso_lpad
	li a7, __NR_rt_sigreturn
	ecall
SYM_FUNC_END(__vdso_rt_sigreturn)

emit_riscv_feature_1_and
