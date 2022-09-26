/* SPDX-License-Identifier: GPL-2.0-only */
#ifdef __CHERI__

#include <linux/bug.h>
#include <linux/cheri.h>
#include <linux/mm.h>

uintcap_t cheri_user_root_cap __ro_after_init;
uintcap_t cheri_user_root_seal_cap __ro_after_init;
uintcap_t cheri_user_root_cid_cap __ro_after_init;
uintcap_t cheri_user_root_allperms_cap __ro_after_init;

static void * __capability
build_user_cap(ptraddr_t addr, size_t len, cheri_perms_t perms, bool exact_bounds)
{
	void * __capability ret = (void * __capability)cheri_user_root_cap;
	cheri_perms_t root_perms = cheri_perms_get(ret);

	ret = cheri_perms_and(ret, perms);
	ret = cheri_address_set(ret, addr);

	if (exact_bounds)
		ret = cheri_bounds_set_exact(ret, len);
	else
		ret = cheri_bounds_set(ret, len);

	WARN(perms & ~root_perms,
	     "Permission mask %#lx discarded while creating user capability %#lp\n",
	     perms & ~root_perms, ret);
	WARN(cheri_is_invalid(ret),
	     "Invalid user capability created: %#lp (%s bounds requested)\n",
	     ret, (exact_bounds ? "exact" : "inexact"));

	return ret;
}

void * __capability
cheri_build_user_cap(ptraddr_t addr, size_t len, cheri_perms_t perms)
{
	return build_user_cap(addr, len, perms, true);
}

void * __capability
cheri_build_user_cap_inexact_bounds(ptraddr_t addr, size_t len,
				    cheri_perms_t perms)
{
	return build_user_cap(addr, len, perms, false);
}

bool cheri_check_cap(const void * __capability cap, size_t len,
		     cheri_perms_t perms)
{
	ptraddr_t addr = untagged_addr(cheri_address_get(cap));
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

	if (perms & ~cheri_perms_get(cap))
		return false;

	return true;
}

#endif /* __CHERI__ */
