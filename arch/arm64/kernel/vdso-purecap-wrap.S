/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2023 ARM Limited
 */

#include <linux/init.h>
#include <linux/linkage.h>
#include <linux/const.h>
#include <asm/assembler.h>
#include <asm/page.h>

	.globl vdso_purecap_start, vdso_purecap_end
	.section .rodata
	.balign PAGE_SIZE
vdso_purecap_start:
	.incbin "arch/arm64/kernel/vdso/purecap/vdso.so"
	.balign PAGE_SIZE
vdso_purecap_end:

	.previous

emit_aarch64_feature_1_and
