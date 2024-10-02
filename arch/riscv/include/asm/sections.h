/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2020 Western Digital Corporation or its affiliates.
 */
#ifndef __ASM_SECTIONS_H
#define __ASM_SECTIONS_H

#include <asm-generic/sections.h>
#include <linux/mm.h>

extern char _start[];
extern char _start_kernel[];
extern char __init_data_begin[], __init_data_end[];
extern char __init_text_begin[], __init_text_end[];
extern char __alt_start[], __alt_end[];
extern char __exittext_begin[], __exittext_end[];

static inline bool is_va_kernel_text(unsigned long va)
{
	unsigned long start = __c_pa(_start);
	unsigned long end = __c_pa(__init_data_begin);

	return va >= start && va < end;
}

static inline bool is_va_kernel_lm_alias_text(unsigned long va)
{
	unsigned long start = __c_pa(lm_alias(_start));
	unsigned long end = __c_pa(lm_alias(__init_data_begin));

	return va >= start && va < end;
}

#endif /* __ASM_SECTIONS_H */
