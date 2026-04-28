/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2017 SiFive
 */

#define RO_EXCEPTION_TABLE_ALIGN	4
#define RUNTIME_DISCARD_EXIT

#ifdef CONFIG_XIP_KERNEL
#include "vmlinux-xip.lds.S"
#else

#include <asm/pgtable.h>
#define LOAD_OFFSET KERNEL_LINK_ADDR

#include <asm/vmlinux.lds.h>
#include <asm/page.h>
#include <asm/cache.h>
#include <asm/thread_info.h>
#include <asm/set_memory.h>
#include "image-vars.h"

#include <linux/sizes.h>
OUTPUT_ARCH(riscv)
ENTRY(_start)

jiffies = jiffies_64;
size$jiffies = 8;

SECTIONS
{
	/* Beginning of code and text segment */
	. = LOAD_OFFSET;
	_start = .;
	HEAD_TEXT_SECTION
	. = ALIGN(PAGE_SIZE);

	.text : {
		_text = .;
		_stext = .;
		TEXT_TEXT
		SCHED_TEXT
		LOCK_TEXT
		KPROBES_TEXT
		ENTRY_TEXT
		IRQENTRY_TEXT
		SOFTIRQENTRY_TEXT
		_etext = .;
		size$_text = ABSOLUTE(. - _text);
		size$_stext = ABSOLUTE(. - _stext);
		size$_etext = 1;
	}

	. = ALIGN(SECTION_ALIGN);
	__init_begin = .;
	__init_text_begin = .;
	.init.text : AT(ADDR(.init.text) - LOAD_OFFSET) ALIGN(SECTION_ALIGN) { \
		_sinittext = .;						\
		INIT_TEXT						\
		_einittext = .;						\
		size$_sinittext = ABSOLUTE(. - _sinittext);
		size$_einittext = 1;
	}

	. = ALIGN(8);
	__soc_early_init_table : {
		__soc_early_init_table_start = .;
		KEEP(*(__soc_early_init_table))
		__soc_early_init_table_end = .;
		size$__soc_early_init_table_start =
			ABSOLUTE(. - __soc_early_init_table_start);
		size$__soc_early_init_table_end = 1;
	}
	__soc_builtin_dtb_table : {
		__soc_builtin_dtb_table_start = .;
		KEEP(*(__soc_builtin_dtb_table))
		__soc_builtin_dtb_table_end = .;
		size$__soc_builtin_dtb_table_start =
			ABSOLUTE(. - __soc_builtin_dtb_table_start);
		size$__soc_builtin_dtb_table_end = 1;
	}
	/* we have to discard exit text and such at runtime, not link time */
	__exittext_begin = .;
	.exit.text :
	{
		EXIT_TEXT
	}
	__exittext_end = .;
	size$__exittext_begin = ABSOLUTE(. - __exittext_begin);
	size$__exittext_end = 1;

	__init_text_end = .;
	. = ALIGN(SECTION_ALIGN);
#ifdef CONFIG_EFI
	. = ALIGN(PECOFF_SECTION_ALIGNMENT);
	__pecoff_text_end = .;
#endif
	/* Start of init data section */
	__init_data_begin = .;
	INIT_DATA_SECTION(16)

	.init.pi : {
		KEEP(*(.init.pi*))
	}

	.init.bss : {
		KEEP(*(.init.bss*))	/* from the EFI stub */
	}
	.exit.data :
	{
		EXIT_DATA
	}

	RUNTIME_CONST_VARIABLES

	PERCPU_SECTION(L1_CACHE_BYTES)

	.rel.dyn : {
		*(.rel.dyn*)
	}

	.rela.dyn : ALIGN(8) {
		__rela_dyn_start = .;
		*(.rela .rela*)
		__rela_dyn_end = .;
	}

#ifdef CONFIG_CHERI_KERNEL
	__cap_relocs : ALIGN(8) {
		*(__cap_relocs)
	}
#endif

	__init_data_end = .;
	size$__init_data_begin = ABSOLUTE(. - __init_data_begin);
	size$__init_data_end = 1;

	. = ALIGN(8);
	.alternative : {
		__alt_start = .;
		KEEP(*(.alternative))
		__alt_end = .;
		size$__alt_start = ABSOLUTE(. - __alt_start);
		size$__alt_end = 1;
	}
	__init_end = .;
	size$__init_begin = ABSOLUTE(. - __init_begin);
	size$__init_end = 1;

	/* Start of data section */
	_sdata = .;
	RO_DATA(SECTION_ALIGN)
	.srodata : {
		*(.srodata*)
	}

	. = ALIGN(SECTION_ALIGN);
	_data = .;

	RW_DATA(L1_CACHE_BYTES, PAGE_SIZE, THREAD_ALIGN)

#ifdef CONFIG_CHERI_KERNEL
	.captable : {
		*(.captable)
	}
#endif

	.sdata : {
		__global_pointer$ = . + 0x800;
		*(.sdata*)
	}

	.got : { *(.got*) }

	.data.rel : { *(.data.rel*) }

#ifdef CONFIG_RELOCATABLE
	.data.rel : { *(.data.rel*) }
	.plt : { *(.plt) }
	.dynamic : { *(.dynamic) }
	.dynsym : { *(.dynsym) }
	.dynstr : { *(.dynstr) }
	.hash : { *(.hash) }
	.gnu.hash : { *(.gnu.hash) }
#endif

#ifdef CONFIG_EFI
	.pecoff_edata_padding : { BYTE(0); . = ALIGN(PECOFF_FILE_ALIGNMENT); }
	__pecoff_data_raw_size = ABSOLUTE(. - __pecoff_text_end);
	__pecoff_data_raw_end = ABSOLUTE(.);
#endif

	/* End of data section */
	_edata = .;
	size$_data = ABSOLUTE(. - _data);
	size$_sdata = ABSOLUTE(. - _sdata);
	size$_edata = 1;

	BSS_SECTION(PAGE_SIZE, PAGE_SIZE, 0)

#ifdef CONFIG_EFI
	. = ALIGN(PECOFF_SECTION_ALIGNMENT);
	__pecoff_data_virt_size = ABSOLUTE(. - __pecoff_text_end);
	__pecoff_data_virt_end = ABSOLUTE(.);
#endif
	_end = .;
	size$_start = ABSOLUTE(. - _start);
	size$_end = 1;

	STABS_DEBUG
	DWARF_DEBUG
	MODINFO
	ELF_DETAILS
	.riscv.attributes 0 : { *(.riscv.attributes) }

	DISCARDS
}
#endif /* CONFIG_XIP_KERNEL */
