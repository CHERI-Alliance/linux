// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <cheriintrin.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct cap_reloc {
	size_t capability_location;
	size_t base;
	size_t offset;
	size_t size;
	size_t perms_to_clear;
};

/*
 * Process capability relocations stored in the __cap_relocs section. Each
 * entry in that section has a layout corresponding to struct cap_reloc.
 *
 * Note that this function cannot refer to any global symbol (function or data),
 * because capability relocations must have already been processed in order to
 * refer to such symbols.
 */
void __morello_init_globals(void)
{
	const struct cap_reloc *start_cap_relocs, *end_cap_relocs, *reloc;
	uintcap_t root_cap;

	/*
	 * References to the linker-generated start/stop section symbols must
	 * not be indirected through the GOT, as this would create a capability
	 * relocation. We need assembly to refer to those directly.
	 */
	asm("adrp %0, __start___cap_relocs\n\t"
	    "add %0, %0, #:lo12:__start___cap_relocs\n\t"
	    "adrp %1, __stop___cap_relocs\n\t"
	    "add %1, %1, #:lo12:__stop___cap_relocs"
	    : "=C"(start_cap_relocs), "=C"(end_cap_relocs));

	root_cap = (uintcap_t)cheri_ddc_get();

	for (reloc = start_cap_relocs; reloc < end_cap_relocs; ++reloc) {
		bool is_executable =
			(reloc->perms_to_clear & CHERI_PERM_EXECUTE) == 0;
		uintcap_t cap;
		uintcap_t *target;

		cap = cheri_address_set(root_cap, reloc->base);

		if (!is_executable && reloc->size)
			cap = cheri_bounds_set(cap, reloc->size);

		cap += reloc->offset;
		cap = cheri_perms_clear(cap, reloc->perms_to_clear);

		if (is_executable)
			cap = cheri_sentry_create(cap);

		target = (uintcap_t *)cheri_address_set(root_cap,
						reloc->capability_location);
		*target = cap;
	}
}
