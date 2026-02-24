/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_MODULELOADER_H
#define _LINUX_MODULELOADER_H
/* The stuff needed for archs to support modules. */

#include <linux/module.h>
#include <linux/elf.h>

/* These may be implemented by architectures that need to hook into the
 * module loader code.  Architectures that don't need to do anything special
 * can just rely on the 'weak' default hooks defined in kernel/module.c.
 * Note, however, that at least one of apply_relocate or apply_relocate_add
 * must be implemented by each architecture.
 */

/*
 * More elaborate information about the resolved symbols. This is
 * mainly used if CONFIG_CHERI_KERNEL is set.
 * symval: Contains a full capability for the symbol (if the symbol
 *     references a memory object, i.e. it is not absolute).
 *     For symbols provided by the kernel or other modules this is
 *     directly taken from the symbol table and permissions should
 *     not be modified. For symbols provided by this module bounds
 *     are set correctly and permissions are either read/write for
 *     data or a sentry if the object is a function. In this case
 *     memtype is provided to allow for refinement of the permission
 *     for read-only data.
 *     For symbols that do not resolve to a capability (e.g. absolute
 *     symbols) this field contains just the symbol value and the
 *     memtype field is MOD_INVALID. In all cases the address part
 *     of the capability must be equal to the value of the symbol.
 * memtype: If the symbol resolves to a capability and the object is
 *     provided by this module this field contains the module memory
 *     type of the object (i.e. the type of section that the symbol is
 *     in. This should be used during relocation to remove write permissions
 *     from data capabilities as necessary.
 * error: If not zero it indicates an error that occured while trying
 *     to resolve the symbol. In some cases this error can be ignored
 *     but it is fatal if the symbol is required for a relocation.
 */
struct mod_sym_info {
	uintptr_t symval;
	enum mod_mem_type memtype;
	int error;
};

/* arch may override to do additional checking of ELF header architecture */
bool module_elf_check_arch(Elf_Ehdr *hdr);

/* Adjust arch-specific sections.  Return 0 on success.  */
int module_frob_arch_sections(Elf_Ehdr *hdr,
			      Elf_Shdr *sechdrs,
			      char *secstrings,
			      struct module *mod);

/* Additional bytes needed by arch in front of individual sections */
unsigned int arch_mod_section_prepend(struct module *mod, unsigned int section);

/* Determines if the section name is an init section (that is only used during
 * module loading).
 */
bool module_init_section(const char *name);

/* Determines if the section name is an exit section (that is only used during
 * module unloading)
 */
bool module_exit_section(const char *name);

/* Describes whether within_module_init() will consider this an init section
 * or not. This behaviour changes with CONFIG_MODULE_UNLOAD.
 */
bool module_init_layout_section(const char *sname);

/*
 * Apply the given relocation to the (simplified) ELF.  Return -error
 * or 0.
 */
#ifdef CONFIG_MODULES_USE_ELF_REL
int apply_relocate(Elf_Shdr *sechdrs,
		   const char *strtab,
		   unsigned int symindex,
		   unsigned int relsec,
		   struct module *mod);
int apply_relocate_sym(Elf_Shdr *sechdrs,
		       const char *strtab,
		       unsigned int symindex,
		       unsigned int relsec,
		       struct mod_sym_info *syms,
		       struct module *mod);
#else
static inline int apply_relocate(Elf_Shdr *sechdrs,
				 const char *strtab,
				 unsigned int symindex,
				 unsigned int relsec,
				 struct module *me)
{
	printk(KERN_ERR "module %s: REL relocation unsupported\n",
	       module_name(me));
	return -ENOEXEC;
}
#endif

#ifndef apply_relocate_sym
#define apply_relocate_sym(secs, strtab, symidx, relsec, symtab, mod) \
	apply_relocate(secs, strtab, symidx, relsec, mod)
#endif

/*
 * Apply the given add relocation to the (simplified) ELF.  Return
 * -error or 0
 */
#ifdef CONFIG_MODULES_USE_ELF_RELA
int apply_relocate_add(Elf_Shdr *sechdrs,
		       const char *strtab,
		       unsigned int symindex,
		       unsigned int relsec,
		       struct module *mod);
int apply_relocate_add_sym(Elf_Shdr *sechdrs,
			   const char *strtab,
			   unsigned int symindex,
			   unsigned int relsec,
			   struct mod_sym_info *syms,
			   struct module *mod);
#ifdef CONFIG_LIVEPATCH
/*
 * Some architectures (namely x86_64 and ppc64) perform sanity checks when
 * applying relocations.  If a patched module gets unloaded and then later
 * reloaded (and re-patched), klp re-applies relocations to the replacement
 * function(s).  Any leftover relocations from the previous loading of the
 * patched module might trigger the sanity checks.
 *
 * To prevent that, when unloading a patched module, clear out any relocations
 * that might trigger arch-specific sanity checks on a future module reload.
 */
void clear_relocate_add(Elf_Shdr *sechdrs,
		   const char *strtab,
		   unsigned int symindex,
		   unsigned int relsec,
		   struct module *me);
#endif
#else
static inline int apply_relocate_add(Elf_Shdr *sechdrs,
				     const char *strtab,
				     unsigned int symindex,
				     unsigned int relsec,
				     struct module *me)
{
	printk(KERN_ERR "module %s: REL relocation unsupported\n",
	       module_name(me));
	return -ENOEXEC;
}
#endif

#ifndef apply_relocate_add_sym
#define apply_relocate_add_sym(secs, strtab, symidx, relsec, symtab, mod) \
	apply_relocate(secs, strtab, symidx, relsec, mod)
#endif

/* Any final processing of module before access.  Return -error or 0. */
int module_finalize(const Elf_Ehdr *hdr,
		    const Elf_Shdr *sechdrs,
		    struct module *mod);

#ifdef CONFIG_MODULES
void flush_module_init_free_work(void);
#else
static inline void flush_module_init_free_work(void)
{
}
#endif

/* Any cleanup needed when module leaves. */
void module_arch_cleanup(struct module *mod);

/* Any cleanup before freeing mod->module_init */
void module_arch_freeing_init(struct module *mod);

#endif
