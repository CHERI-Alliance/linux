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

#endif	/* _LINUX_CHERI_H */
