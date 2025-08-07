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

#endif /* __has_feature(capabilities) */
