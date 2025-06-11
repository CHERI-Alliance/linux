/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_USER_PTR_H
#define __ASM_USER_PTR_H

#include <asm/morello.h>

#ifdef CONFIG_CHERI_PURECAP_UABI

static inline void __user *uaddr_to_user_ptr(ptraddr_t addr)
{
	/*
	 * TODO [PCuABI] - the user root capability should be used, not the
	 * kernel one.
	 */
	uintcap_t root_cap = morello_get_root_cap();

	return (void __user *)__builtin_cheri_address_set(root_cap, addr);
}
#define uaddr_to_user_ptr(addr) uaddr_to_user_ptr(addr)

static inline void __user *uaddr_to_user_ptr_safe(ptraddr_t addr)
{
	/*
	 * TODO [PCuABI] - the user root capability should be used, not the
	 * kernel one.
	 */
	uintcap_t root_cap = morello_get_root_cap();

	return (void __user *)__builtin_cheri_address_set(root_cap, addr);
}
#define uaddr_to_user_ptr_safe(addr) uaddr_to_user_ptr_safe(addr)

static inline void __user *kaddr_to_user_ptr(ptraddr_t addr)
{
	uintcap_t root_cap = morello_get_root_cap();

	return (void __user *)__builtin_cheri_address_set(root_cap, addr);
}
#define kaddr_to_user_ptr(addr) kaddr_to_user_ptr(addr)

#endif /* CONFIG_CHERI_PURECAP_UABI */

#endif /* __ASM_USER_PTR_H */
