/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_USER_PTR_H
#define _LINUX_USER_PTR_H

#include <linux/typecheck.h>

/**
 * as_user_ptr() - Convert an arbitrary integer value to a user pointer.
 * @x: The integer value to convert.
 *
 * Return: Up to 64 bits of @x represented as a user pointer. The result is
 *         not a valid pointer and shall not be dereferenced.
 */
#define as_user_ptr(x) ((void __user *)(user_uintptr_t)(u64)(x))

/* Same semantics as as_user_ptr(), but also requires x to be of a given type */
#define as_user_ptr_strict(type, x) (	\
{					\
	typecheck(type, (x));		\
	as_user_ptr(x);			\
}					\
)

/* Legacy user pointer conversion macro, new code should use as_user_ptr() */
#define u64_to_user_ptr(x) as_user_ptr_strict(u64, (x))

#ifdef CONFIG_CHERI_PURECAP_UABI

/**
 * uaddr_to_user_ptr() - Convert a user-provided address to a user pointer.
 * @addr: The address to set the pointer to.
 *
 * Return: A user pointer with its address set to @addr.
 *
 * This function should be used when a user pointer is required because userspace
 * provided a raw address (e.g. via a __u64 member of a struct), and the memory
 * at that address needs to be accessed.
 *
 * When the pure-capability uABI is targeted, uses of this function bypass the
 * capability model and should be minimised.
 */
void __user *uaddr_to_user_ptr(ptraddr_t addr);

/**
 * uaddr_to_user_ptr_safe() - Convert a kernel-generated user address to a
 *   user pointer.
 * @addr: The address to set the pointer to.
 *
 * Return: A user pointer with its address set to @addr.
 *
 * This function should be used when a user pointer is required because user
 * memory at a certain address needs to be accessed, and that address originates
 * from the kernel itself (i.e. it is not provided by userspace).
 */
void __user *uaddr_to_user_ptr_safe(ptraddr_t addr);

#else /* CONFIG_CHERI_PURECAP_UABI */

static inline void __user *uaddr_to_user_ptr(ptraddr_t addr)
{
	return as_user_ptr(addr);
}

static inline void __user *uaddr_to_user_ptr_safe(ptraddr_t addr)
{
	return as_user_ptr(addr);
}

#endif /* CONFIG_CHERI_PURECAP_UABI */

/**
 * user_ptr_addr() - Extract the address of a user pointer.
 * @ptr: The user pointer to extract the address from.
 *
 * Return: The address @ptr points to.
 */
static inline ptraddr_t user_ptr_addr(const void __user *ptr)
{
	return (ptraddr_t)(user_uintptr_t)ptr;
}

/**
 * user_ptr_is_same() - Checks where two user pointers are exactly the same.
 * @p1: The first user pointer to check.
 * @p2: The second user pointer to check.
 *
 * Return: true if @p1 and @p2 are exactly the same user pointers.
 *
 * Only use this function if you need to know that two user pointers are
 * interchangeable, not to check that their address is the same (use the ==
 * operator for that purpose).
 */
static inline bool user_ptr_is_same(const void __user *p1, const void __user *p2)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_equal_exact(p1, p2);
#else
	return p1 == p2;
#endif
}

#endif	/* _LINUX_USER_PTR_H */
