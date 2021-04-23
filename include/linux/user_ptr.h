/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_USER_PTR_H
#define _LINUX_USER_PTR_H

#include <linux/typecheck.h>

/**
 * as_user_ptr - convert an arbitrary integer value to a user pointer
 * @x: the integer value to convert
 *
 * Returns @x represented as a user pointer. The result is not a valid pointer
 * and shall not be dereferenced.
 */
#define as_user_ptr(x) ((void __user *)(user_uintptr_t)(x))

/* Same semantics as as_user_ptr(), but also requires x to be of a given type */
#define as_user_ptr_strict(type, x) (	\
{					\
	typecheck(type, (x));		\
	as_user_ptr(x);			\
}					\
)

/* Legacy user pointer conversion macro, new code should use as_user_ptr() */
#define u64_to_user_ptr(x) as_user_ptr_strict(u64, (x))

#ifndef uaddr_to_user_ptr
/**
 * uaddr_to_user_ptr - convert a user-provided address to a user pointer
 * @addr: the address to set the pointer to
 *
 * Returns a user pointer with its address set to @addr.
 *
 * This function should be used when a user pointer is required because userspace
 * provided a raw address (e.g. via a __u64 member of a struct), and the memory
 * at that address needs to be accessed.
 *
 * When the pure-capability uABI is targeted, uses of this function bypass the
 * capability model and should be minimised.
 */
static inline void __user *uaddr_to_user_ptr(ptraddr_t addr)
{
	return as_user_ptr(addr);
}
#endif

#ifndef uaddr_to_user_ptr_safe
/**
 * uaddr_to_user_ptr_safe - convert a kernel-generated user address to a user pointer
 * @addr: the address to set the pointer to
 *
 * Returns a user pointer with its address set to @addr.
 *
 * This function should be used when a user pointer is required because user
 * memory at a certain address needs to be accessed, and that address originates
 * from the kernel itself (i.e. it is not provided by userspace).
 */
static inline void __user *uaddr_to_user_ptr_safe(ptraddr_t addr)
{
	return as_user_ptr(addr);
}
#endif

#ifndef kaddr_to_user_ptr
/**
 * kaddr_to_user_ptr - convert a kernel address to a user pointer
 * @addr: the address to set the pointer to
 *
 * Returns a user pointer with its address set to @addr.
 *
 * This function should be used when kernel memory needs to be accessed via a
 * user pointer. There should be no use for it after the removal of set_fs().
 */
static inline void __user *kaddr_to_user_ptr(ptraddr_t addr)
{
	return as_user_ptr(addr);
}
#endif

/**
 * user_ptr_addr - extract the address of a user pointer
 * @ptr: the user pointer to extract the address from
 *
 * Returns the address @ptr points to.
 */
static inline ptraddr_t user_ptr_addr(const void __user *ptr)
{
	return (ptraddr_t)(user_uintptr_t)ptr;
}

#endif	/* _LINUX_USER_PTR_H */
