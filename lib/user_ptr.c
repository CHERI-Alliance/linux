/* SPDX-License-Identifier: GPL-2.0-only */
#include <linux/bug.h>
#include <linux/cheri.h>
#include <linux/user_ptr.h>

void __user *uaddr_to_user_ptr(ptraddr_t addr)
{
	/*
	 * No warning if the result is invalid as the input address is not
	 * controlled by the kernel.
	 */
	return (void __user *)cheri_address_set(cheri_user_root_cap, addr);
}

void __user *uaddr_to_user_ptr_safe(ptraddr_t addr)
{
	void __user *ret;

	ret = (void __user *)cheri_address_set(cheri_user_root_cap, addr);

	WARN(!cheri_tag_get(ret),
	     "Invalid user capability created: %#lp\n", ret);

	return ret;
}
