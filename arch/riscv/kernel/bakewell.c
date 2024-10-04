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

/*
 * Set to false if the initial root capability does not meet
 * expectations. This is used to delay the resulting panic to
 * a pointer where console output is likely active.
 */
static bool root_cap_valid = true;

void __init bakewell_init(void)
{
	if (!root_cap_valid)
		panic("CHERI: Invalid root cap\n");
	pr_info("CHERI bakewell support\n");

	/* Enable user space CHERI support. */
	__asm__ __volatile__("csrs senvcfg, %0\n" : : "r" (1 << 28));
}

/* Check validity of the root capability. */
static void __init bakewell_check_root_cap(uintcap_t root_cap)
{
	cheri_perms_t perms = cheri_perms_get(root_cap);

	pr_info("CHERI: Root capability: %#lp (%lp)\n", root_cap, root_cap);

	if (!cheri_tag_get(root_cap)) {
		pr_crit("CHERI: Root capability is invalid\n");
		root_cap_valid = false;
	}

	if (cheri_is_sealed(root_cap)) {
		pr_crit("CHERI: Root capability is sealed\n");
		root_cap_valid = false;
	}

	if ((perms & CHERI_PERMS_ALL) != CHERI_PERMS_ALL) {
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

static inline __init uintcap_t __build_cap(uintcap_t root,
					   cheri_perms_t perms, ptraddr_t len)
{
	return cheri_bounds_set(cheri_perms_and(root, perms), len);
}

/* Initialize the kernel's authorizing capabilities for special situations. */
void __init bakewell_caps_init(uintcap_t root_cap)
{
	cheri_perms_t perms;

	bakewell_check_root_cap(root_cap);

	/* Sanitize root capability. */
	root_cap = cheri_address_set(root_cap, 0);
	/* FIXCHERI: M-bit */

	/* All permissions but limited to user addresses. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_allperms_cap = __build_cap(root_cap, perms,
						   TASK_SIZE_MAX);
	pr_info("CHERI: user allperms cap: %#lp\n",
		cheri_user_root_allperms_cap);

	/* All permission, unlimited address range. */
	perms = CHERI_PERMS_ROOTCAP |
	    CHERI_PERMS_READ | CHERI_PERMS_WRITE | CHERI_PERMS_EXEC;
	cheri_user_root_cap = cheri_perms_and(root_cap, perms);
	pr_info("CHERI: user root cap: %#lp\n", cheri_user_root_cap);

	/* Not supported on RISCV bakewell. */
	cheri_user_root_seal_cap = __c_fakeu(0);
	cheri_user_root_cid_cap = __c_fakeu(0);
}

/* FIXCHERI: Check capability restrictions. */
void __init init_cap_relocs(void * __capability rw, void * __capability rx)
{
	cheri_init_globals_3(rw, rx, rx);
}
