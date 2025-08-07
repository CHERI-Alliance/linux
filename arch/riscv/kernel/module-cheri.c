// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2025 Codasip GmbH
// Florian Schmaus <florian.schmaus@codasip.com>

#include <linux/module.h>
#include <linux/moduleloader.h>
#include <linux/slab.h>
#include <linux/sort.h>

struct captable_entry *module_emit_captable_entry(struct module *mod, uintptr_t val,
						  bool is_init)
{
	int i;
	struct captable_entry *cap;
	struct mod_section *captable_sec;

	if (is_init)
		captable_sec = &mod->arch.init_captable;
	else
		captable_sec = &mod->arch.captable;

	cap = get_captable_entry(val, captable_sec);
	if (cap)
		return cap;

	/* There is no duplicate entry, create a new one */

	i = captable_sec->num_entries++;
	BUG_ON(captable_sec->num_entries > captable_sec->max_entries);

	cap = shdr_addr(captable_sec->shdr);
	cap[i] = emit_captable_entry(val);

	return &cap[i];
}

static int cmp_rela(const void *a, const void *b)
{
	const Elf_Rela *x = a, *y = b;
	int i;

	i = cmp_int(x->r_info, y->r_info);
	if (i == 0)
		i = cmp_int(x->r_addend, y->r_addend);
	return i;
}

static void add_relas_to_scratch(Elf_Rela *scratch, size_t *num_relas,
			    Elf_Rela *relas, size_t num_sec_relas)
{
	for (size_t i = 0; i < num_sec_relas; i++) {
		switch (ELF_R_TYPE(relas[i].r_info)) {
		case R_RISCV_GOT_HI20:
			scratch[(*num_relas)++] = relas[i];
			break;
		}
	}
}

static size_t count_max_caps(Elf_Rela *scratch, size_t num_relas)
{
	size_t caps;

	if (!num_relas)
		return 0;

	sort(scratch, num_relas, sizeof(*scratch), cmp_rela, NULL);

	/* There is at least one unique entry */
	caps = 1;
	for (Elf_Rela *rela = scratch + 1; rela < scratch + num_relas; rela++) {
		/*
		 * Entries are sorted. Therefore, we only need to compare
		 * with the preceding entry to check for duplicates.
		 */
		if (cmp_rela(rela, rela - 1))
			caps++;
	}

	return caps;
}

static void init_captable(struct mod_section *captable, size_t num_caps, Elf_Word extra_flags)
{
	captable->shdr->sh_type = SHT_NOBITS;
	captable->shdr->sh_flags = SHF_ALLOC | SHF_WRITE | extra_flags;
	captable->shdr->sh_addralign = L1_CACHE_BYTES;
	captable->shdr->sh_size = num_caps * sizeof(struct captable_entry);
	captable->num_entries = 0;
	captable->max_entries = num_caps;
}

int module_frob_arch_sections_module_cheri(Elf_Ehdr *ehdr, Elf_Shdr *sechdrs,
			      char *secstrings, struct module *mod)
{
	int i, res = 0;
	Elf_Shdr *dst_sec;
	Elf_Rela *relas;
	const char *sname;
	Elf_Rela *scratch __free(kvfree) = NULL, *init_scratch __free(kvfree) = NULL;
	size_t num_sec_relas, num_caps, num_init_caps, num_relas = 0, num_init_relas = 0;

	for (i = 0; i < ehdr->e_shnum; i++) {
		sname = secstrings + sechdrs[i].sh_name;
		if (!strcmp(sname, ".captable"))
			mod->arch.captable.shdr = sechdrs + i;
		else if (!strcmp(sname, ".init.captable"))
			mod->arch.init_captable.shdr = sechdrs + i;
	}

	if (!mod->arch.captable.shdr || !mod->arch.init_captable.shdr) {
		pr_err("%s, module captable section(s) missing\n", mod->name);
		return -ENOEXEC;
	}

	for (i = 0; i < ehdr->e_shnum; i++) {
		if (sechdrs[i].sh_type != SHT_RELA)
			continue;

		/* ignore relocations that operate on non-exec sections */
		dst_sec = sechdrs + sechdrs[i].sh_info;
		if (!(dst_sec->sh_flags & SHF_EXECINSTR))
			continue;

		sname = secstrings + dst_sec->sh_name;
		num_sec_relas = sechdrs[i].sh_size / sizeof(Elf_Rela);
		if (module_init_layout_section(sname))
			num_init_relas += num_sec_relas;
		else
			num_relas += num_sec_relas;
	}

	scratch = kvmalloc_array(num_relas, sizeof(*scratch), GFP_KERNEL);
	if (!scratch)
		return -ENOMEM;

	init_scratch = kvmalloc_array(num_init_relas, sizeof(*scratch), GFP_KERNEL);
	if (!init_scratch)
		return -ENOMEM;

	num_relas = 0, num_init_relas = 0;
	for (i = 0; i < ehdr->e_shnum; i++) {
		if (sechdrs[i].sh_type != SHT_RELA)
			continue;

		/* ignore relocations that operate on non-exec sections */
		dst_sec = sechdrs + sechdrs[i].sh_info;
		if (!(dst_sec->sh_flags & SHF_EXECINSTR))
			continue;

		sname = secstrings + dst_sec->sh_name;
		relas = (void *)ehdr + sechdrs[i].sh_offset;
		num_sec_relas = sechdrs[i].sh_size / sizeof(*relas);
		if (module_init_layout_section(sname))
			add_relas_to_scratch(init_scratch, &num_init_relas,
					     relas, num_sec_relas);
		else
			add_relas_to_scratch(scratch, &num_relas,
					     relas, num_sec_relas);
	}

	num_caps = count_max_caps(scratch, num_relas);
	num_init_caps = count_max_caps(init_scratch, num_init_relas);

	pr_debug("%s: .captable holds %zu caps, .init.captable holds %zu caps\n",
		 mod->name, num_caps, num_init_caps);

	init_captable(&mod->arch.captable, num_caps, SHF_RO_AFTER_INIT);
	init_captable(&mod->arch.init_captable, num_init_caps, 0);

	return res;
}
