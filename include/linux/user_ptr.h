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
 *                            user pointer.
 * @addr: The address to set the pointer to.
 *
 * Return: A user pointer with its address set to @addr.
 *
 * This function should be used when a new user pointer needs to be provided to
 * userspace. @addr should be controlled by the kernel (i.e. not an arbitrary
 * user-provided value).
 *
 * When a user pointer is needed to access user memory (in-kernel use),
 * make_user_ptr_for_*_uaccess() should be used instead.
 *
 * All uses of this function should eventually be replaced by dedicated code
 * ensuring that the bounds and permissions of the user capability are minimised
 * in the pure-capability ABI.
 */
void __user *uaddr_to_user_ptr_safe(ptraddr_t addr);

/**
 * make_user_ptr_for_<perms>_uaccess() - Create a user pointer from kernel-generated
 *                                       parameters, to access user memory.
 * @addr: The address to set the pointer to.
 * @len: The minimum size of the region the pointer should allow to access.
 *
 * Return: A user pointer with its address set to @addr.
 *
 * These functions should be used when a user pointer is required because user
 * memory at a certain address needs to be accessed. The parameters should not
 * originate from userspace, and the returned pointer should not be provided to
 * userspace in any way.
 *
 * When the pure-capability uABI is targeted, the returned capability pointer
 * will have its length set to at least @len (the base and length may be
 * expanded because of representability constraints), and its permissions will
 * be set appropriately for each function (read/write/RW).
 */
const void __user *make_user_ptr_for_read_uaccess(ptraddr_t addr, size_t len);
void __user *make_user_ptr_for_write_uaccess(ptraddr_t addr, size_t len);
void __user *make_user_ptr_for_rw_uaccess(ptraddr_t addr, size_t len);

/**
 * check_user_ptr_<perms>() - Check whether a user pointer grants access to a
 *                            memory region.
 * @ptr: The pointer to check.
 * @len: The size of the region that needs to be accessible.
 * @perms: The type of operation the pointer needs to allow; bitwise combination
 *         of USER_PTR_CAN_*.
 *
 * Checks whether @ptr allows accessing the memory region starting at the
 * address of @ptr and of size @len. The type of access that @ptr should allow
 * is specified by calling the appropriate function (read/write/RW).
 *
 * These functions only check whether the **pointer itself** allows a given
 * access; no other check is performed. Such checks are only performed when user
 * pointers have appropriate metadata, as in the pure-capability uABI, otherwise
 * true is always returned.
 *
 * Return: true if @ptr passes the checks.
 */
bool check_user_ptr_read(const void __user *ptr, size_t len);
bool check_user_ptr_write(void __user *ptr, size_t len);
bool check_user_ptr_rw(void __user *ptr, size_t len);

#else /* CONFIG_CHERI_PURECAP_UABI */

static inline void __user *uaddr_to_user_ptr(ptraddr_t addr)
{
	return as_user_ptr(addr);
}

static inline void __user *uaddr_to_user_ptr_safe(ptraddr_t addr)
{
	return as_user_ptr(addr);
}

static inline const void __user *make_user_ptr_for_read_uaccess(ptraddr_t addr, size_t len)
{
	return as_user_ptr(addr);
}
static inline void __user *make_user_ptr_for_write_uaccess(ptraddr_t addr, size_t len)
{
	return as_user_ptr(addr);
}
static inline void __user *make_user_ptr_for_rw_uaccess(ptraddr_t addr, size_t len)
{
	return as_user_ptr(addr);
}

static inline bool check_user_ptr_read(const void __user *ptr, size_t len)
{
	return true;
}
static inline bool check_user_ptr_write(void __user *ptr, size_t len)
{
	return true;
}
static inline bool check_user_ptr_rw(void __user *ptr, size_t len)
{
	return true;
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
