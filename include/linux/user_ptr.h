/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_USER_PTR_H
#define _LINUX_USER_PTR_H

#include <linux/cheri.h>
#include <linux/limits.h>
#include <linux/typecheck.h>

struct reserv_struct;

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

typedef cheri_perms_t user_ptr_perms_t;

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

/**
 * check_user_ptr_owning() - Check whether a user pointer owns a memory region.
 * @user_ptr: The pointer to check.
 * @len: The size of the region to check.
 *
 * Checks whether @ptr owns the memory region starting at the address of @ptr
 * and of size @len.
 *
 * Return: true if @ptr passes the check.
 */
bool check_user_ptr_owning(user_uintptr_t user_ptr, size_t len);

/**
 * make_user_ptr_owning() - Create a user pointer owning the specified
 * reservation.
 *
 * @reserv: Reservation information.
 * @addr: Address to set the user pointer to.
 *
 * Return: The constructed user pointer.
 *
 * The bounds of the returned user pointer are set (exactly) to the bounds of
 * @reserv, and so are its permissions.
 */
user_uintptr_t make_user_ptr_owning(const struct reserv_struct *reserv,
				    ptraddr_t addr);

/**
 * user_ptr_owning_perms_from_prot() - Calculate capability permissions from
 * prot flags and vm_flags.
 * @prot: Memory protection flags.
 * @vm_flags: vm_flags of the underlying VMA.
 *
 * Return: Calculated capability permission flags.
 *
 * Note: unsigned long is used instead of vm_flags_t as linux/mm_types.h cannot
 * be included here.
 */
user_ptr_perms_t user_ptr_owning_perms_from_prot(int prot, unsigned long vm_flags);

#else /* CONFIG_CHERI_PURECAP_UABI */

typedef int user_ptr_perms_t;

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

static inline bool check_user_ptr_owning(user_uintptr_t user_ptr, size_t len)

{
	return true;
}

static inline user_uintptr_t make_user_ptr_owning(const struct reserv_struct *reserv,
						  ptraddr_t addr)
{
	return addr;
}

static inline user_ptr_perms_t user_ptr_owning_perms_from_prot(int prot,
							       unsigned long vm_flags)
{
	return 0;
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
 * user_ptr_base() - Extract the lower bound (base) of a user pointer.
 * @ptr: The user pointer to extract the base from.
 *
 * The base of @ptr represents the lowest address than can be accessed
 * through @ptr. If @ptr does not carry any bound information, the start of the
 * address space is returned.
 *
 * Return: The base of @ptr.
 */
static inline ptraddr_t user_ptr_base(const void __user *ptr)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_base_get(ptr);
#else
	return 0;
#endif
}

/**
 * user_ptr_limit() - Extract the upper bound (limit) of a user pointer.
 * @ptr: The user pointer to extract the limit from.
 *
 * The limit of @ptr represents the end of the region than can be accessed
 * through @ptr (that is one byte past the highest accessible address). If @ptr
 * does not carry any bound information, the end of the address space is
 * returned.
 *
 * Return: The limit of @ptr.
 */
static inline ptraddr_t user_ptr_limit(const void __user *ptr)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_base_get(ptr) + __builtin_cheri_length_get(ptr);
#else
	/*
	 * Ideally TASK_SIZE_MAX, unfortunately we cannot safely include
	 * <linux/uaccess.h> in this header.
	 */
	return ULONG_MAX;
#endif
}

/**
 * user_ptr_is_valid() - Check if a user pointer is valid.
 * @ptr: The user pointer to check.
 *
 * Return: true if @ptr is valid (tag set in PCuABI).
 */
static inline bool user_ptr_is_valid(const void __user *ptr)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_tag_get(ptr);
#else
	return 0;
#endif
}

/**
 * user_ptr_is_same() - Check whether two user pointers are exactly the same.
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

/**
 * user_ptr_set_addr() - Set the address of the user pointer.
 * @ptr: The user pointer to set the address of.
 * @addr: The address to set the pointer to.
 *
 * Return: A user pointer with its address set to @addr.
 */
static inline void __user *user_ptr_set_addr(void __user *ptr, ptraddr_t addr)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_address_set(ptr, addr);
#else
	return as_user_ptr(addr);
#endif
}

/**
 * user_ptr_set_bounds() - Set the lower and upper bounds of a user pointer.
 * @ptr: The input user pointer.
 * @len: The length of the new bounds.
 *
 * The lower bound (base) of @ptr is set to its address, and its upper bound
 * (limit) is set to its address + @len. The lower and upper bounds may be
 * adjusted downwards (resp. upwards) if they cannot be exactly represented. If
 * @ptr does not carry any bound information, this function returns @ptr
 * unchanged.
 *
 * Return: @ptr with adjusted bounds.
 */
static inline void __user *user_ptr_set_bounds(void __user *ptr, size_t len)
{
#ifdef CONFIG_CHERI_PURECAP_UABI
	return __builtin_cheri_bounds_set(ptr, len);
#else
	return ptr;
#endif
}

#endif	/* _LINUX_USER_PTR_H */
