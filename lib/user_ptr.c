/* SPDX-License-Identifier: GPL-2.0-only */
#include <linux/bug.h>
#include <linux/cheri.h>
#include <linux/mm_types.h>
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

/*
 * Grant all permissions in each category, e.g. loading/storing capabilities in
 * addition to standard data.
 */
const void __user *make_user_ptr_for_read_uaccess(ptraddr_t addr, size_t len)
{
	cheri_perms_t cap_perms = CHERI_PERM_GLOBAL | CHERI_PERMS_READ;

	return cheri_build_user_cap_inexact_bounds(addr, len, cap_perms);
}

void __user *make_user_ptr_for_write_uaccess(ptraddr_t addr, size_t len)
{
	cheri_perms_t cap_perms = CHERI_PERM_GLOBAL | CHERI_PERMS_WRITE;

	return cheri_build_user_cap_inexact_bounds(addr, len, cap_perms);
}

void __user *make_user_ptr_for_rw_uaccess(ptraddr_t addr, size_t len)
{
	cheri_perms_t cap_perms = CHERI_PERM_GLOBAL | CHERI_PERMS_READ
						    | CHERI_PERMS_WRITE;

	return cheri_build_user_cap_inexact_bounds(addr, len, cap_perms);
}

/*
 * Only check whether the capability has the minimal data permissions (Load /
 * Store). The underlying assumption is that these functions are only used
 * before user data pages are grabbed via GUP and the data is then copied
 * through a kernel mapping, and does not contain capabilities.
 */
bool check_user_ptr_read(const void __user *ptr, size_t len)
{
	return cheri_check_cap(ptr, len, CHERI_PERM_LOAD);
}

bool check_user_ptr_write(void __user *ptr, size_t len)
{
	return cheri_check_cap(ptr, len, CHERI_PERM_STORE);
}

bool check_user_ptr_rw(void __user *ptr, size_t len)
{
	return cheri_check_cap(ptr, len, CHERI_PERM_LOAD | CHERI_PERM_STORE);
}

bool check_user_ptr_owning(user_uintptr_t user_ptr, size_t len)
{
	ptraddr_t addr;

	addr = round_down((ptraddr_t)user_ptr, PAGE_SIZE);
	len = round_up(len, PAGE_SIZE);
	user_ptr = cheri_address_set(user_ptr, addr);

	return cheri_check_cap((void * __capability)user_ptr, len,
			       CHERI_PERMS_ROOTCAP);
}

user_uintptr_t make_user_ptr_owning(const struct reserv_struct *reserv,
				    ptraddr_t addr)
{
	user_uintptr_t user_ptr;

	user_ptr = (user_uintptr_t)cheri_build_user_cap(reserv->start,
							reserv->len,
							reserv->perms);
	user_ptr = cheri_address_set(user_ptr, addr);

	return user_ptr;
}

user_ptr_perms_t user_ptr_owning_perms_from_prot(int prot, unsigned long vm_flags)
{
	/* TODO [PCuABI] - capability permission conversion from memory permission */
	return (CHERI_PERMS_READ | CHERI_PERMS_WRITE |
		CHERI_PERMS_EXEC | CHERI_PERMS_ROOTCAP);
}
