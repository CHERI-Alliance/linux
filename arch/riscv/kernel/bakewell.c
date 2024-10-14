#include <linux/sched.h>
#include <linux/printk.h>
#include <linux/cheri.h>
#include <linux/pgtable.h>

#include <asm/bakewell.h>

#ifndef __CHECKER__
#include "cheri_init_globals_bw.h"
#else
#define cheri_init_globals_3(a,b,c) do { } while (0)
#endif

#define __PI __attribute__((nocaprelocs))

/*
 * Set to false if the initial root capability does not meet
 * expectations. This is used to delay the resulting panic to
 * a pointer where console output is likely active.
 */
static bool root_cap_valid = true;

void __init bakewell_init(void)
{
	BUG_ON(!!IS_ENABLED(CONFIG_RISCV_BAKEWELL_LEGACY_PERMS) !=
	       !!acperm_legacy);

	if (!root_cap_valid)
		panic("CHERI: Invalid root cap\n");

	pr_info("CHERI: bakewell support%s\n",
		acperm_legacy ? " (legacy acperm)" : "");

	pr_info("CHERI: M-bit mask=0x%lx gchi=%d scmode=%d hybrid=%s\n",
		cheri_mbit_mask, !!cheri_mbit_value, scmode_capmode_value,
		cheri_hybrid_support ? "yes" : "no");

	pr_info("CHERI: kernel code cap: %#lp\n", kernel_code_cap);
	pr_info("CHERI: kernel data cap: %#lp\n", kernel_data_cap);
	pr_info("CHERI: user allperms cap: %#lp\n",
		(void *)cheri_user_root_allperms_cap);
	pr_info("CHERI: user root cap: %#lp\n", (void *)cheri_user_root_cap);
}

/* Check validity of the root capability. */
static void __init bakewell_check_root_cap(uintcap_t root_cap)
{
	static const cheri_perms_t allperms = CHERI_PERMS_READ |
		CHERI_PERMS_WRITE | CHERI_PERMS_EXEC | CHERI_PERMS_ROOTCAP;
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
		pr_crit("CHERI: Root capability has bad permissions\n");
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
	ptraddr_t split = 1ULL << 63;

	rw = __build_cap(inf, CHERI_PERMS_READ | CHERI_PERMS_WRITE,
			 split, split);
	rx = __build_cap(inf, CHERI_PERMS_READ | CHERI_PERMS_EXEC,
			 split, split);
	ro = __build_cap(inf, CHERI_PERMS_READ, split, split);

	cheri_init_globals_3((void * __capability)rw, (void * __capability)rx,
			     (void * __capability)ro);

	kernel_data_cap = (void * __capability)rw;
	kernel_code_cap = (void * __capability)rx;
}

/* Initialize the kernel's authorizing capabilities for special situations. */
void __init bakewell_caps_init(uintcap_t inf)
{
	cheri_perms_t perms;

	bakewell_check_root_cap(inf);

	/* Sanitize root capability. */
	inf = cheri_address_set(inf, 0);

	/* All permissions but limited to user addresses. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_allperms_cap = __build_cap(inf, perms, 0, TASK_SIZE_MAX);

	/* All permission, unlimited address range. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_cap = cheri_perms_and(cheri_user_root_allperms_cap,
					      perms);

	/* Not supported on RISCV bakewell. */
	cheri_user_root_seal_cap = __c_fakeu(0);
	cheri_user_root_cid_cap = __c_fakeu(0);
}

bool
__bakewell_is_capmode(void * __capability cap)
{
	return (cheri_high_get(cap) & cheri_mbit_mask) == cheri_mbit_value;
}

void * __capability bakewell_set_capmode(void * __capability cap)
{
	__asm__ volatile ("scmode %0, %0, %1"
			  : "=C" (cap) : "r" (scmode_capmode_value), "0" (cap));

	return cap;
}

void * __capability bakewell_clear_capmode(void * __capability cap)
{
	BUG_ON(!cheri_hybrid_support);
	__asm__ volatile ("scmode %0, %0, %1"
			  : "=C" (cap) : "r" (!scmode_capmode_value), "0" (cap));

	return cap;
}

