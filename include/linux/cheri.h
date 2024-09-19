/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_CHERI_H
#define _LINUX_CHERI_H

#ifdef __CHERI__

#include <cheriintrin.h>

#include <linux/types.h>

#include <uapi/asm/cheri.h>
#ifdef CONFIG_HAVE_ARCH_CHERI_H
#include <asm/cheri.h>
#endif

/*
 * Standard permission sets for new capabilities. Can be overridden by
 * architectures to add arch-specific permissions.
 */
#ifndef CHERI_PERMS_READ
#define CHERI_PERMS_READ \
	(CHERI_PERM_LOAD | CHERI_PERM_LOAD_CAP)
#endif

#ifndef CHERI_PERMS_WRITE
#define CHERI_PERMS_WRITE \
	(CHERI_PERM_STORE | CHERI_PERM_STORE_CAP | CHERI_PERM_STORE_LOCAL_CAP)
#endif

#ifndef CHERI_PERMS_EXEC
#define CHERI_PERMS_EXEC \
	(CHERI_PERM_EXECUTE | CHERI_PERM_SYSTEM_REGS)
#endif

#ifndef CHERI_PERMS_ROOTCAP
#define CHERI_PERMS_ROOTCAP \
	(CHERI_PERM_GLOBAL | CHERI_PERM_SW_VMEM)
#endif

/**
 * cheri_build_user_cap() - Create a userspace capability.
 * @addr: Requested capability address.
 * @len: Requested capability length.
 * @perms: Requested capability permissions.
 *
 * Return: A new capability derived from cheri_user_root_cap. Its address and
 *         permissions are set according to @addr and @perms respectively. Its
 *         bounds are set exactly with @addr as base address and @len as
 *         length.
 *
 * The caller is responsible to ensure that:
 * 1. @addr is a valid userspace address.
 * 2. The (@addr, @len) tuple can be represented as capability bounds.
 * 3. @perms are valid permissions for a regular userspace capability.
 *
 * If either 1. or 2. does not hold, the resulting capability will be invalid.
 * If 3. does not hold, the returned capability will not have any of the invalid
 * permissions.
 */
void * __capability
cheri_build_user_cap(ptraddr_t addr, size_t len, cheri_perms_t perms);

/**
 * cheri_build_user_cap_inexact_bounds() - Create a userspace capability,
 *                                         allowing bounds to be enlarged.
 * @addr: Requested capability address.
 * @len: Requested capability length.
 * @perms: Requested capability permissions.
 *
 * Return: A new capability derived from cheri_user_root_cap. Its address and
 *         permissions are set according to @addr and @perms respectively. Its
 *         bounds are set to the smallest representable range that includes the
 *         range [@addr, @addr + @len[.
 *
 * This variant of cheri_build_user_cap() should only be used when it is safe to
 * enlarge the bounds of the capability. In particular, it should never be used
 * when creating a capability that is to be provided to userspace, because the
 * potentially enlarged bounds might give access to unrelated objects.
 *
 * The caller is responsible to ensure that:
 * 1. @addr is a valid userspace address.
 * 2. @perms are valid permissions for a regular userspace capability.
 *
 * If 1. does not hold, the resulting capability will be invalid.
 * If 2. does not hold, the returned capability will not have any of the invalid
 * permissions.
 */
void * __capability
cheri_build_user_cap_inexact_bounds(ptraddr_t addr, size_t len,
				    cheri_perms_t perms);


/**
 * cheri_check_cap() - Check whether a capability gives access to a range of
 *                     addresses.
 * @cap: Capability to check.
 * @len: Length of the access.
 * @perms: Required permissions.
 *
 * Checks whether @cap gives access to a given range of addresses and has the
 * requested permissions. This means that:
 *  * @cap is valid and unsealed.
 *  * The range [@cap.address, @cap.address + @len[ is within the bounds
 *    of @cap.
 *  * The permissions of @cap include at least @perms.
 *
 *  Return: true if @cap passes the checks.
 */
bool cheri_check_cap(const void * __capability cap, size_t len,
		     cheri_perms_t perms);


/*
 * Root capabilities. Should be set in arch code during the early init phase,
 * read-only after that.
 *
 * cheri_user_root_cap is the standard root capability to derive new regular
 * (data/code) capabilities from. It does not include the special permissions
 * Seal/Unseal and CompartmentID; those are available separately via
 * cheri_user_root_{seal,cid}_cap. Finally cheri_user_root_allperms_cap
 * includes all permissions accessible to userspace and is ultimately the root
 * of all user capabilities; it should only be used in very specific
 * situations.
 *
 * The helpers above should be used instead where possible.
 */
extern uintcap_t cheri_user_root_cap;		/* Userspace (data/code) root */
extern uintcap_t cheri_user_root_seal_cap;	/* Userspace sealing root */
extern uintcap_t cheri_user_root_cid_cap;	/* Userspace compartment ID root */
extern uintcap_t cheri_user_root_allperms_cap;	/* Userspace root (all permissions) */

#endif /* __CHERI__ */

/*
 * Macros to correctly cast between unsigned long (aka ptraddr_t), void *
 * the kernel notion of uintptr_t. These macros are for in kernel
 * conversions between pointers and plain addresses and are relevant
 * if CONFIG_CHERI_KERNEL is set. Conversion for user pointers has
 * a different set of macros.
 */

/*
 * Downgrade a pointer to its address.
 * Use this if you intentionally want to remove the pointer property
 * from a pointer and reduce it to its address. The result cannot be
 * turned back into a pointer with CHERI.
 *
 * A valid example use would be an alignment check on a pointer's address:
 *	static inline unsigned long offset_in_page(const void *ptr)
 *	{
 *		return __c_pa(ptr) % PAGE_SIZE;
 *	}
 *
 * Other potential uses could be:
 * - Decode additional information stored in the low bits of the pointer's
 *   address (e.g. maple_tree, rb_tree).
 * - Pass the address to printk.
 * - Most of the VMA functions operate on addresses and not pointers, too.
 */
static inline ptraddr_t
__c_pa(const volatile void *ptr)
{
	return (ptraddr_t __force)(uintptr_t)ptr;
}

/*
 * Downgrade a uintptr_t to its address.
 *
 * Like __c_pa but takese a uintptr_t instead of a void * argument.
 */
static inline ptraddr_t
__c_ua(uintptr_t ptr)
{
	return (unsigned long __force)ptr;
}

/*
 * Force cast a pointer, uintptr or other integer to an unsigned long.
 * The result cannot be dereferenced. If possible use __c_pa() or __c_ua()
 * as approriate instead.
 *
 * Valid uses of this macro are in a macro that implements things like
 * cmpxchg which might be instantiated with both real pointers or a
 * uintptr_t.
 */
#define __c_a(x) (__c_ua((uintptr_t __force)(x)))

/*
 * Generate a pointer from an unsigned long value. The resulting pointer
 * cannot be dereferenced!
 *
 * Valid user of this macro must be able to proof that the generated
 * pointer will not be dereferenced.
 *
 * Examples of a valid use are:
 * - An integer value is stored directly in a ->private field of some data
 *   structure and users of the ->private data field will cast it back to
 *   the original non-pointer type.
 * - Additionally, the ERR_PTR related macros use this.
 */
static inline void *
__c_fakep(ptraddr_t val)
{
	return (void *)(uintptr_t __force)val;
}

/*
 * Like __c_fakep but creates a uintptr_t instead of a void * pointer.
 */
static inline uintptr_t
__c_fakeu(ptraddr_t val)
{
	return (uintptr_t __force)val;
}

#ifdef CONFIG_CHERI_KERNEL

#define __cheri_pointer_align __attribute__((aligned(__SIZEOF_POINTER__)))

/* Kernel root capabilities. Use with care. */
extern void * kernel_data_cap;
extern void * kernel_code_cap;

/* User root capabilities. */
extern void * user_data_cap;
extern void * user_code_cap;

/*
 * Create a read/write data capability for a kernel address.
 * @addr The address.
 * @return A pointer with bounds that allow access to the
 *     entire kernel range.
 *
 * NOTE: A need to use this function means that the CHERI adoption
 *       is incomplete. The caller should at least be able to provide
 *       bounds and thus use cheri_make_kernel_data_cap or
 *       cheri_make_kernel_code_cap instead.
 */
static inline void *
cheri_kcap(ptraddr_t addr)
{
	return cheri_address_set(kernel_data_cap, addr);
}

/*
 * Create a capability to access kernel data. The capability is
 * derived from kernel_data_cap and thus will allow read and write
 * accesses.
 */
static inline void *
cheri_make_kernel_data_cap(ptraddr_t addr, size_t len)
{
	void * ret = cheri_address_set(kernel_data_cap, addr);

	return cheri_bounds_set(ret, len);
}

/*
 * Create a capbility for kernel read-only data and/or code.
 * The capability is derived from kernel_code_cap and thus will
 * allow read/exec and (if used as a pcc) access to system registers.
 */
static inline void *
cheri_make_kernel_code_cap(ptraddr_t addr)
{
	return cheri_address_set(kernel_code_cap, addr);
}

/* The same for user code. */
static inline void __user *
cheri_make_user_code_cap(ptraddr_t addr, size_t len)
{
	void * ret = cheri_address_set(user_code_cap, addr);

	return (void __user *)cheri_bounds_set(ret, len);
}

#else

#define __cheri_pointer_align

static inline void *
cheri_kcap(ptraddr_t addr)
{
	return (void *)addr;
}

static inline void *
cheri_make_kernel_data_cap(ptraddr_t addr, size_t len)
{
	(void)len;

	return (void *)addr;
}

static inline void *
cheri_make_kernel_code_cap(ptraddr_t addr)
{
	return (void *)addr;
}

static inline void __user *
cheri_make_user_code_cap(ptraddr_t addr, size_t len)
{
	(void)len;

	return (void __user *)addr;
}

#endif

#endif	/* _LINUX_CHERI_H */
