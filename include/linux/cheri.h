/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_CHERI_H
#define _LINUX_CHERI_H

#include <linux/types.h>

#if defined(__CHECKER__) || defined(__GENKSYMS__)
typedef unsigned int cheri_perms_t;
#endif

#ifdef __CHECKER__
#define __capability
#endif

#if __has_feature(capabilities)

#ifndef __CHECKER__

#include <cheriintrin.h>

/* For ARM morello. */
#ifndef cheri_high_get
#define cheri_high_get(x) __builtin_cheri_copy_from_high(x)
#endif

#else /* __CHECKER__ */

#define cheri_address_set(__c, __a) ((__typeof__(__c))(uintptr_t __force)__a)
#define cheri_bounds_set(__c, __l) (__c)
#define cheri_bounds_set_exact(__c, __l) (__c)
#define cheri_sentry_create(__c) (__c)

#define cheri_base_get(__c) ((ptraddr_t)0)
#define cheri_address_get(__c) ((ptraddr_t __force)(uintptr_t __force)__c)
#define cheri_length_get(__c) (~(ptraddr_t)0)
#define cheri_high_get(__c) ((ptraddr_t)0)
#define cheri_tag_get(__c) (1)
#define cheri_representable_alignment_mask(__l) (~(ptraddr_t)0)
#define cheri_representable_length(__l) (__l)
#define __builtin_cheri_equal_exact(p1, p2) (((uintptr_t __force)p1) == ((uintptr_t __force)p2))
#define cheri_is_sealed(__c) (0)
#define cheri_is_unsealed(__c) (1)
#define cheri_is_sentry(__c) (0)
#define cheri_is_valid(__c) (1)
#define cheri_is_invalid(__c) (0)
#define cheri_perms_and(__c, __m) (__c)
#define cheri_perms_get(__c) ~0U

#endif /* __CHECKER__ */

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

/*
 * Trace events store capabilites as two separate fields: tag+metadata and
 * address. TRACE_EVT_TAG points to a reserved-0 bit in the metadata that
 * can be used for the tag.
 * Put the defines here, they depend on the capability encoding. The defaults
 * below work for the risc-v cheri encodings. Architectures with other
 * encodings may overwrite them.
 */
#ifndef TRACE_EVT_TAG
#ifdef CONFIG_64BIT
#define TRACE_EVT_TAG 28
#else
#define TRACE_EVT_TAG 21
#endif
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
void __user *
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
void __user * __capability
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
bool cheri_check_cap(const void __user * __capability cap, size_t len,
		     cheri_perms_t perms);

/**
 * Return the maximum length accessible from this capability starting
 * with its current base.
 * @c Capability
 * @max An upper bound on the limit to return.
 * @return The number of accessible bytes.
 */
static __always_inline unsigned long
cheri_restrict_len(const volatile void __user *c, ptraddr_t max)
{
	ptraddr_t l =
		cheri_base_get(c) + cheri_length_get(c) - cheri_address_get(c);

	return (l < max)  ? l : max;
}

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
extern cheri_perms_t cheri_unsupported_perms;	/* Permission bits not supported by current hardware. */

#else

#define cheri_build_user_cap(__c, __l, __p) ((void *)(__c))
#define cheri_build_user_cap_inexact_bounds(__c, __l, __p) ((void *)(__c))
#define cheri_check_cap(cap, len, perms) (true)
#define cheri_address_set(cap, addr) ((void *)(addr))
#define cheri_bounds_set(__c, __l) (__c)
#define cheri_bounds_set_exact(__c, __l) (__c)
#define cheri_sentry_create(__c) (__c)
#define cheri_restrict_len(C, L) (L)

#endif /* __has_feature(capabilities) */

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
static __always_inline ptraddr_t
__c_pa(const volatile void *ptr)
{
	return (ptraddr_t __force)(uintptr_t)ptr;
}

static __always_inline ptraddr_t
__c_pa_u(const volatile void __user *ptr)
{
#if __has_feature(capabilities)
	return (ptraddr_t __force)(__kernel_uintptr_t)ptr;
#else
	return (ptraddr_t __force)ptr;
#endif
}

/*
 * Downgrade a uintptr_t or similar to its address.
 *
 * This function is similar to __c_pa but takes a __u64ptr (or more
 * commonly a promoted uintptr_t/user_uintptr_t and returns the
 * address part. The explicit use of __u64ptr and __u64 ensures
 * that a __u64ptr on 32-bit does not lose the higher bits.
 */
static __always_inline __u64
__c_ua(__u64ptr ptr)
{
	return (unsigned long long __force)ptr;
}

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
static __always_inline void *
__c_fakep(ptraddr_t val)
{
	return (void *)(uintptr_t __force)val;
}

/*
 * Like __c_fakep but creates a __u64ptr instead of a void * pointer.
 * Similar to __c_ua() the input and output values are at least 64-bit
 * even on 32-bit systems.
 */
static __always_inline __u64ptr
__c_fakeu(__u64 val)
{
	return (__u64ptr __force)val;
}

/*
 * Fix the bounds of a pointer by taking them from another pointer.
 * This is useful in some special cases, e.g. after reallocation when
 * we know that the address of a pointer should be within the bounds
 * of another pointer but due to address calculations the tag and bounds
 * on the pointer may have been lost.
 */
#define cheri_fixup_bounds(__AUTH, __TOFIX) do {	\
	void * __tofix = (__TOFIX);			\
	void * __auth = (__AUTH);			\
	(__TOFIX) = __auth + (__tofix - __auth);	\
} while (0)

#ifdef CONFIG_CHERI_KERNEL

#define __cheri_pointer_align __attribute__((aligned(__SIZEOF_POINTER__)))
#define __packed_if_not_cheri
#define cheri_bounds_set_kernel(__c, __l) cheri_bounds_set(__c, __l)

/* Kernel root capabilities. Use with care. */
extern void * kernel_data_cap;
extern void * kernel_code_cap;
extern void * kernel_ro_cap;

/*
 * Create a read-only data capability for a kernel address.
 * @addr The address.
 * @return A pointer with bounds that allow access to the
 *     entire kernel range.
 *
 * NOTE: A need to use this function means that the CHERI adoption
 *       is incomplete. The caller should at least be able to provide
 *       bounds and thus use cheri_make_kernel_data_cap or
 *       cheri_make_kernel_code_cap instead.
 */
static __always_inline void *
cheri_kcap_ro(ptraddr_t addr)
{
	return cheri_address_set(kernel_ro_cap, addr);
}

/*
 * Create a capability to access kernel data. The capability is
 * derived from kernel_data_cap and thus will allow read and write
 * accesses.
 */
static __always_inline void *
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
static __always_inline void *
cheri_make_kernel_code_cap(ptraddr_t addr)
{
	return cheri_address_set(kernel_code_cap, addr);
}

static __maybe_unused void *
cheri_build_kernel_data_cap(ptraddr_t base, ptraddr_t addr, size_t len)
{
	return cheri_address_set(cheri_make_kernel_data_cap(base, len), addr);
}

#else

#define __cheri_pointer_align
#define __packed_if_not_cheri __packed
#define cheri_bounds_set_kernel(__c, __l) (__c)

static __always_inline void *
cheri_kcap_ro(ptraddr_t addr)
{
	return (void *)addr;
}

static __always_inline void *
cheri_make_kernel_data_cap(ptraddr_t addr, size_t len)
{
	(void)len;

	return (void *)addr;
}

static __always_inline void *
cheri_make_kernel_code_cap(ptraddr_t addr)
{
	return (void *)addr;
}

static __always_inline void *
cheri_build_kernel_data_cap(ptraddr_t base, ptraddr_t addr, size_t len)
{
	return (void *)addr;
}

#endif

#endif	/* _LINUX_CHERI_H */
