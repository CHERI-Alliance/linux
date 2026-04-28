#include <linux/sched.h>
#include <linux/printk.h>
#include <linux/cheri.h>
#include <linux/pgtable.h>
#include <linux/ratelimit.h>

#include <asm/riscvcheri.h>

#ifndef __CHECKER__
#include "cheri_init_globals_bw.h"
#else
#define cheri_init_globals_3(a,b,c) do { } while (0)
#endif

#define __PI __attribute__((nocaprelocs))

#ifdef CONFIG_64BIT
#define CHERI_MBIT_MASK	(1UL << 52)
#else
#error "CHERI 32-bit not implemented, yet."
#endif

struct page *__vmemmap_ptr;
EXPORT_SYMBOL(__vmemmap_ptr);

/*
 * Set to false if the initial root capability does not meet
 * expectations. This is used to delay the resulting panic to
 * a pointer where console output is likely active.
 */
static bool root_cap_valid = true;

void __init riscv_cheri_init(void)
{
	if (!root_cap_valid)
		panic("CHERI: Invalid root cap\n");

	pr_info("CHERI: riscv cheri support\n");

	pr_info("CHERI: Selected SATP mode: 0x%lx PTE.CW support: %s\n",
		(unsigned long)satp_mode, riscv_cheripte_cw ? "yes" : "no");

	pr_info("CHERI: kernel code cap: %#lp\n", kernel_code_cap);
	pr_info("CHERI: kernel data cap: %#lp\n", kernel_data_cap);
	pr_info("CHERI: kernel ro   cap: %#lp\n", kernel_ro_cap);
	pr_info("CHERI: user allperms cap: %#lp\n",
		(void *)cheri_user_root_allperms_cap);
	pr_info("CHERI: user root cap: %#lp\n", (void *)cheri_user_root_cap);
	pr_info("CHERI: Permission bits not supported by hardware: 0x%x\n",
		cheri_unsupported_perms);
}

/* Check validity of the root capability. */
static void __init riscv_cheri_check_root_cap(uintcap_t root_cap)
{
	cheri_perms_t allperms = CHERI_PERMS_READ |
		CHERI_PERMS_WRITE | CHERI_PERMS_EXEC | CHERI_PERMS_ROOTCAP;

	if (!has_cheri_levels)
		cheri_unsupported_perms |= ZCHERILEVELS_PERMS;
	allperms &= ~cheri_unsupported_perms;

	cheri_perms_t perms = cheri_perms_get(root_cap);

	pr_info("CHERI: Root capability: %#lp (%lp)\n",
		(void *)root_cap, (void *)root_cap);

	if (!cheri_tag_get(root_cap)) {
		pr_crit("CHERI: Root capability is invalid\n");
		root_cap_valid = false;
	}

	if (cheri_is_sealed(root_cap)) {
		pr_crit("CHERI: Root capability is sealed\n");
		root_cap_valid = false;
	}

	if ((perms & allperms) != allperms) {
		pr_crit("CHERI: Root capability has bad permissions: is=0x%lx expected=0x%lx\n",
			(unsigned long)perms, (unsigned long)allperms);
		root_cap_valid = false;
	}

	if (cheri_base_get(root_cap) != 0) {
		pr_crit("CHERI: Root capability has bad base\n");
		root_cap_valid = false;
	}

	if (cheri_length_get(root_cap) != ~0UL) {
		pr_crit("CHERI: Root capability has bad length\n");
		root_cap_valid = false;
	}
}

static inline __init uintcap_t __build_cap(uintcap_t root, cheri_perms_t perms,
					   ptraddr_t base, ptraddr_t len)
{
	root = cheri_address_set(root, base);
	root = cheri_bounds_set(root, len);
	return cheri_perms_and(root, perms);
}

void __init __PI init_cap_relocs(uintcap_t inf)
{
	uintcap_t rw, ro, rx;
	ptraddr_t split = 1UL << (8 * __SIZEOF_LONG__ - 1);

	rw = __build_cap(inf, CHERI_PERMS_READ | CHERI_PERMS_WRITE,
			 split, split);
	rx = __build_cap(inf, CHERI_PERMS_READ | CHERI_PERMS_EXEC,
			 split, split);
	ro = __build_cap(inf, CHERI_PERMS_READ, split, split);

	cheri_init_globals_3((void * __capability)rw, (void * __capability)rx,
			     (void * __capability)ro);

	kernel_data_cap = (void * __capability)rw;
	kernel_code_cap = (void * __capability)rx;
	kernel_ro_cap = (void *__capability)ro;
}

/* Initialize the kernel's authorizing capabilities for special situations. */
void __init riscv_cheri_caps_init(uintcap_t inf)
{
	cheri_perms_t perms;

	riscv_cheri_check_root_cap(inf);

	/* Sanitize root capability. */
	inf = cheri_address_set(inf, 0);

	/* All permissions but limited to user addresses. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_allperms_cap = __build_cap(inf, perms, 0,
					1UL << (8 * __SIZEOF_LONG__ - 1));

	/* All permission, unlimited address range. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_cap = cheri_perms_and(cheri_user_root_allperms_cap,
					      perms);

	/* Not supported on RISCV CHERI. */
	cheri_user_root_seal_cap = __c_fakeu(0);
	cheri_user_root_cid_cap = __c_fakeu(0);

	__vmemmap_ptr = cheri_make_kernel_data_cap(VMEMMAP_START, VMEMMAP_SIZE);
}

bool
__riscv_cheri_is_capmode(void * __capability cap)
{
	return !(cheri_high_get(cap) & CHERI_MBIT_MASK);
}

void * __capability riscv_cheri_set_capmode(void * __capability cap)
{
	__asm__ volatile ("scmode %0, %0, %1"
			  : "=C" (cap) : "r" (0), "0" (cap));

	return cap;
}

void * __capability riscv_cheri_clear_capmode(void * __capability cap)
{
	__asm__ volatile ("scmode %0, %0, %1"
			  : "=C" (cap) : "r" (1), "0" (cap));

	return cap;
}

#ifdef CONFIG_RISCV_CHERI_DEBUG_USER_COPY
void do_warn_tags(void *dst, void *src, size_t len, void *p)
{
	WARN_RATELIMIT(1, "Tags stripped in usercopy: src=%#p dst=%#p 0x%lx fault=%#p", src, dst, len, p);
}
#endif

