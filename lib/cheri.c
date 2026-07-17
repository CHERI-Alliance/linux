/* SPDX-License-Identifier: GPL-2.0-only */
#if __has_feature(capabilities)

#include <linux/export.h>
#include <linux/bug.h>
#include <linux/cheri.h>
#include <linux/mm.h>

uintcap_t cheri_user_root_cap __ro_after_init;
uintcap_t cheri_user_root_seal_cap __ro_after_init;
uintcap_t cheri_user_root_cid_cap __ro_after_init;
uintcap_t cheri_user_root_allperms_cap __ro_after_init;
cheri_perms_t cheri_unsupported_perms = 0;

#ifdef CONFIG_CHERI_KERNEL
EXPORT_SYMBOL(kernel_data_cap);
EXPORT_SYMBOL(kernel_code_cap);
EXPORT_SYMBOL(kernel_ro_cap);
#endif

#ifdef CONFIG_COMPAT64
EXPORT_SYMBOL(cheri_user_root_allperms_cap);
#endif

static void __user *
build_user_cap(ptraddr_t addr, size_t len, cheri_perms_t perms, bool exact_bounds)
{
	void __user * ret = (void __user *)cheri_user_root_cap;
	cheri_perms_t root_perms = cheri_perms_get(ret);

	ret = cheri_perms_and(ret, perms);
	ret = cheri_address_set(ret, addr);

	if (exact_bounds)
		ret = cheri_bounds_set_exact(ret, len);
	else
		ret = cheri_bounds_set(ret, len);

	WARN((perms & ~cheri_unsupported_perms) & ~root_perms,
	     "Permission mask %#x discarded while creating user capability %#lp\n",
	     perms & ~root_perms, ret);
	WARN(cheri_is_invalid(ret),
	     "Invalid user capability created: %#lp (%s bounds requested)\n",
	     ret, (exact_bounds ? "exact" : "inexact"));

	return ret;
}

void __user *
cheri_build_user_cap(ptraddr_t addr, size_t len, cheri_perms_t perms)
{
	return build_user_cap(addr, len, perms, true);
}

void __user *
cheri_build_user_cap_inexact_bounds(ptraddr_t addr, size_t len,
				    cheri_perms_t perms)
{
	return build_user_cap(addr, len, perms, false);
}

bool cheri_check_cap(const void __user *cap, size_t len,
		     cheri_perms_t perms)
{
	ptraddr_t addr = untagged_addr(__c_pa_u(cap));
	/*
	 * The base address (as returned by cheri_base_get()) is never tagged,
	 * that is its top byte is always canonical, so no need for
	 * untagged_addr().
	 */
	ptraddr_t base = cheri_base_get(cap);

	if (cheri_is_invalid(cap) || cheri_is_sealed(cap))
		return false;

	if (addr < base || addr > base + cheri_length_get(cap) - len)
		return false;

	perms &= ~cheri_unsupported_perms;
	if (perms & ~cheri_perms_get(cap))
		return false;

	return true;
}

#ifdef CONFIG_CHERI_KERNEL

/*
 * The list below contains settings that might have a negative effect
 * on a CHERI_KERNEL. Mismatched config options will result in a very
 * prominent warning during boot. Thus, please think twice before adding
 * to this list. In general it should be reserved for config options
 * where all of the following are true:
 * - There is good reason to believe that the non-recommended
 *   setting has no benefit on a CHERI kernel.
 * - The non-recommended setting has a noticeable negative effect,
 *   e.g. for performance.
 * - The recommended setting for CHERI differs from the default
 *   or from conventional wisdom on non-CHERI kernels.
 */
#define CHERI_OBSOLETE(X) { IS_ENABLED(X), #X " should be OFF" }
#define CHERI_RECOMMENDED(X) { !IS_ENABLED(X), #X " should be ON" }
static __initconst const struct {
	bool wrong;
	const char *name;
} cheri_configs[] = {
	{ false, NULL }
};

static int __init cheri_kernel_config_warning(void)
{
	unsigned int i;

	for (i = 0; cheri_configs[i].name; ++i) {
		if (cheri_configs[i].wrong)
			break;
	}
	if (cheri_configs[i].name == NULL)
		return 0;

	pr_warn("********************************************************\n");
	pr_warn("** We have detected config settings that are believed **\n");
	pr_warn("** to have little or no benefit on a CHERI kernel.    **\n");
	pr_warn("** Please consider changing them, in particular when  **\n");
	pr_warn("** bencharking.                                       **\n");
	for (; cheri_configs[i].name; ++i) {
		if (!cheri_configs[i].wrong)
			continue;
		pr_warn("**    %-47s **\n", cheri_configs[i].name);
	}
	pr_warn("********************************************************\n");

	return 0;
}

early_initcall(cheri_kernel_config_warning);
#endif

#endif /* __has_feature(capabilities) */
