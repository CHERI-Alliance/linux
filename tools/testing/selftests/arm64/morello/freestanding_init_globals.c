// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <cheriintrin.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <linux/auxvec.h>
#include <linux/elf.h>

#include "freestanding.h"

#define DRELOC_FRAG_EXEC		4
#define DRELOC_FRAG_RWDATA		2
#define DRELOC_FRAG_RODATA		1

#define CHERI_PERM_MASK_BASE ( \
	CHERI_PERM_GLOBAL)

#define CHERI_PERM_MASK_R ( \
	CHERI_PERM_MASK_BASE | \
	CHERI_PERM_LOAD | \
	CHERI_PERM_LOAD_CAP | \
	ARM_CAP_PERMISSION_MUTABLE_LOAD)

#define CHERI_PERM_MASK_RW ( \
	CHERI_PERM_MASK_R | \
	CHERI_PERM_STORE | \
	CHERI_PERM_STORE_CAP | \
	CHERI_PERM_STORE_LOCAL_CAP)

#define CHERI_PERM_MASK_RX ( \
	CHERI_PERM_MASK_R | \
	CHERI_PERM_EXECUTE | \
	ARM_CAP_PERMISSION_EXECUTIVE | \
	CHERI_PERM_SYSTEM_REGS)

#ifndef R_MORELLO_RELATIVE
#define R_MORELLO_RELATIVE		59395
#endif

struct cap_reloc {
	size_t capability_location;
	size_t base;
	size_t offset;
	size_t size;
	size_t perms_to_clear;
};

static void get_caps(uintptr_t *cap_rx, uintptr_t *cap_rw, const uintptr_t *auxv)
{
	for (;;) {
		switch ((unsigned long)auxv[0])	{
		case AT_NULL:
			return;
		case AT_CHERI_EXEC_RX_CAP:
			*cap_rx = auxv[1];
			*cap_rx = cheri_perms_and(*cap_rx, CHERI_PERM_MASK_RX);
			break;
		case AT_CHERI_EXEC_RW_CAP:
			*cap_rw = auxv[1];
			*cap_rw = cheri_perms_and(*cap_rw, CHERI_PERM_MASK_RW);
			break;
		}
		auxv += 2;
	}
}

/*
 * Process capability relocations stored in the __cap_relocs section. Each
 * entry in that section has a layout corresponding to struct cap_reloc.
 *
 * Note that this function cannot refer to any global symbol (function or data),
 * because capability relocations must have already been processed in order to
 * refer to such symbols.
 */
void __morello_process_cap_relocs(void *auxv)
{
	const struct cap_reloc *start_cap_relocs, *end_cap_relocs, *reloc;
	uintptr_t cap_rx = 0;
	uintptr_t cap_rw = 0;

	/*
	 * References to the linker-generated start/stop section symbols must
	 * not be indirected through the GOT, as this would create a capability
	 * relocation. We need assembly to refer to those directly.
	 */
	asm(".weak __start___cap_relocs\n\t"
	    ".hidden __start___cap_relocs\n\t"
	    "adrp %0, __start___cap_relocs\n\t"
	    "add %0, %0, #:lo12:__start___cap_relocs\n\t"
	    : "=C"(start_cap_relocs));

	asm(".weak __stop___cap_relocs\n\t"
	    ".hidden __stop___cap_relocs\n\t"
	    "adrp %0, __stop___cap_relocs\n\t"
	    "add %0, %0, #:lo12:__stop___cap_relocs"
	    : "=C"(end_cap_relocs));

	get_caps(&cap_rx, &cap_rw, auxv);

	for (reloc = start_cap_relocs; reloc < end_cap_relocs; ++reloc) {
		bool is_writable =
			(reloc->perms_to_clear & CHERI_PERM_STORE) == 0;
		bool is_executable =
			(reloc->perms_to_clear & CHERI_PERM_EXECUTE) == 0;
		uintcap_t cap;
		uintcap_t *target;

		if (is_writable)
			cap = cheri_address_set(cap_rw, reloc->base);
		else
			cap = cheri_address_set(cap_rx, reloc->base);

		if (!is_executable && reloc->size)
			cap = cheri_bounds_set(cap, reloc->size);

		cap += reloc->offset;
		cap = cheri_perms_clear(cap, reloc->perms_to_clear);

		if (is_executable)
			cap = cheri_sentry_create(cap);

		target = (uintcap_t *)cheri_address_set(cap_rw,
						reloc->capability_location);
		*target = cap;
	}
}

static inline uintptr_t morello_relative(uint64_t base, uintptr_t cap_rx, uintptr_t cap_rw,
					 Elf64_Rela *reloc, void *reloc_addr)
{
	uint64_t __attribute__((may_alias)) *u64_reloc_addr = reloc_addr;

	/*
	 * Fragment identified by r_offset has the following information:
	 * | 64-bit: address | 56-bits: length | 8-bits: permissions |
	 */
	unsigned long loc = u64_reloc_addr[0];
	unsigned long len = u64_reloc_addr[1] & ((1UL << 56) - 1);
	unsigned long perm = u64_reloc_addr[1] >> 56;
	uintptr_t value;

	if (perm == DRELOC_FRAG_RWDATA)
		value = cheri_address_set(cap_rw, base + loc);
	else
		value = cheri_address_set(cap_rx, base + loc);

	value = cheri_bounds_set_exact(value, len);
	value = value + reloc->r_addend;

	if (perm == DRELOC_FRAG_RODATA)
		value = cheri_perms_and(value, CHERI_PERM_MASK_R);

	/* Seal executable capabilities with MORELLO_RB.  */
	if (perm == DRELOC_FRAG_EXEC)
		value = cheri_sentry_create(value);

	return value;
}

void __morello_process_dynamic_relocs(void *auxv)
{
	Elf64_Rela *rela_dyn_start, *rela_dyn_end, *reloc;
	uintptr_t cap_rx = 0;
	uintptr_t cap_rw = 0;

	asm(".weak __rela_dyn_start\n\t"
	    ".hidden __rela_dyn_start\n\t"
	    "adrp %0, __rela_dyn_start\n\t"
	    "add %0, %0, #:lo12:__rela_dyn_start\n\t"
	    : "=C"(rela_dyn_start));

	asm(".weak __rela_dyn_end\n\t"
	    ".hidden __rela_dyn_end\n\t"
	    "adrp %0, __rela_dyn_end\n\t"
	    "add %0, %0, #:lo12:__rela_dyn_end"
	    : "=C"(rela_dyn_end));

	get_caps(&cap_rx, &cap_rw, auxv);
	for (reloc = rela_dyn_start; reloc < rela_dyn_end; ++reloc) {
		uintptr_t *reloc_addr, value;

		if (reloc->r_info != R_MORELLO_RELATIVE)
			continue;
		reloc_addr = (uintptr_t *)cheri_address_set(cap_rw, reloc->r_offset);
		value = morello_relative(0, cap_rx, cap_rw, reloc, reloc_addr);
		*reloc_addr = value;
	}
}
