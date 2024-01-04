/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _LINUX_MM_RESERV_H
#define _LINUX_MM_RESERV_H

#include <linux/cheri.h>
#include <linux/mm_types.h>
#include <linux/sched/coredump.h>
#include <linux/types.h>

#ifdef CONFIG_CHERI_PURECAP_UABI
#define reserv_representable_alignment(len)				\
	(reserv_is_supported(current->mm)				\
	 ? (PAGE_MASK & ~cheri_representable_alignment_mask(len)) : 0)

#define reserv_representable_base(base, len)				\
	(reserv_is_supported(current->mm)				\
	 ? ((base) & cheri_representable_alignment_mask(len)) : (base))

#define reserv_representable_length(len)				\
	(reserv_is_supported(current->mm)				\
	 ? cheri_representable_length(len) : (len))

#define reserv_vma_reserv_start(vma)					\
	(reserv_is_supported((vma)->vm_mm)				\
	 ? (vma)->reserv_data.start : (vma)->vm_start)

#define reserv_vma_reserv_len(vma)					\
	(reserv_is_supported((vma)->vm_mm)				\
	 ? (vma)->reserv_data.len : ((vma)->vm_end - (vma)->vm_start))

/**
 * reserv_vma_set_reserv() - Set the reservation information in the VMA.
 * @vma: Target VMA.
 * @start: Reservation start address.
 * @len: Reservation length.
 * @prot: prot flags to calculate the reservation permissions.
 *
 * Return: 0 if reservation information set successfully or negative errorcode
 *         otherwise.
 *
 * The start address is stored as CHERI representable base and the length as
 * CHERI representable length. They are expected to not overlap with any other
 * VMA. This function should be called with mmap_lock held.
 */
int reserv_vma_set_reserv(struct vm_area_struct *vma, ptraddr_t start,
			  size_t len, int prot);

/**
 * reserv_vma_set_reserv_start_len() - Set the reservation information in the VMA.
 * @vma: Target VMA.
 * @start: Reservation start address.
 * @len: Reservation length.
 *
 * Return: 0 if reservation information set successfully or negative errorcode
 *         otherwise.
 *
 * The start address is stored as CHERI representable base and the length as
 * CHERI representable length. They are expected to not overlap with any other
 * VMA. The reservation permissions are left unchanged.  This function should
 * be called with mmap_lock held.
 */
int reserv_vma_set_reserv_start_len(struct vm_area_struct *vma, ptraddr_t start,
				    size_t len);

/**
 * reserv_vma_set_reserv_data() - Set the reservation information in the VMA.
 * @vma: Target VMA.
 * @reserv_data: New reservation information
 *
 * The VMA's reservation information is set to the contents of @reserv_data.
 * This function should be called with mmap_lock held.
 */
void reserv_vma_set_reserv_data(struct vm_area_struct *vma,
				const struct reserv_struct *reserv_data);

/**
 * reserv_find_reserv_info_range() - Find a reservation spanning at least the
 *   input address range.
 * @start: Region start address.
 * @len: Region length.
 * @locked: Flag to indicate if mmap_lock is already held.
 * @reserv_info: Pointer to a reserv_struct to set if a matching reservation is
 * 		 found.
 *
 * Return: True if a matching reservation is found or false otherwise.
 *
 * This function internally uses mmap_lock to access VMAs if mmap_lock is not
 * already held.

 */
bool reserv_find_reserv_info_range(ptraddr_t start, size_t len, bool locked,
				   struct reserv_struct *reserv_info);

/**
 * reserv_vma_range_within_reserv() - Check that the input address range falls
 *   within @vma's reservation.
 * @vma: Target VMA.
 * @start: Region start address.
 * @len: Region length.
 *
 * Return: True if the input address range falls within the reserved virtual
 *         address range or false otherwise.
 *
 * This function should be called with mmap_lock held.
 */
bool reserv_vma_range_within_reserv(struct vm_area_struct *vma, ptraddr_t start,
				    size_t len);

/**
 * reserv_cap_within_reserv() - Check that the capability bounds of @cap
 *   are wholly contained within an existing reservation.
 * @cap: Capability to check.
 * @locked: Flag to indicate if mmap_lock is already held.
 *
 * Return: True if the input capability bounds fall within a reservation or
 *         false otherwise.
 *
 * This function internally uses mmap_lock to access VMAs if mmap_lock is not
 * already held.
 */
bool reserv_cap_within_reserv(user_uintptr_t cap, bool locked);

/**
 * reserv_aligned_range_within_reserv() - Check that the input address range falls
 *   within any reservation.
 * @start: Region start address.
 * @len: Region length.
 * @locked: Flag to indicate if mmap_lock is already held.
 *
 * Return: True if the input address range (aligned for representability) falls
 *         within a reservation or false otherwise.
 *
 * @start and @len are appropriately aligned down/up so that the range that is
 * checked corresponds to that of a new reservation. This function should be
 * called with mmap_lock held.
 */
bool reserv_aligned_range_within_reserv(ptraddr_t start, size_t len,
					bool locked);

/**
 * reserv_range_mapped() - Check that the input address range is fully mapped.
 * @start: Region start address.
 * @len: Region length.
 * @locked: Flag to indicate if mmap_lock is already held.
 *
 * Return: 0 if the range is fully mapped or negative errorcode otherwise.
 *
 * This is useful to find if the requested range is fully mapped without
 * fragmentation. This function internally uses mmap_lock to access VMAs if
 * mmap_lock is not already held.
 */
int reserv_range_mapped(ptraddr_t start, size_t len, bool locked);

/**
 * reserv_make_user_ptr_owning() - Build an owning user pointer for a given
 *   reservation.
 * @vma_addr: VMA address.
 * @locked: Flag to indicate if mmap_lock is already held.
 *
 * Return: the constructed user pointer.
 *
 * @vma_addr must be the address of an existing VMA, whose reservation
 * information will be used to set the user pointer's bounds and permissions.
 * Its address will be set to @vma_addr. This function internally uses
 * mmap_lock to access VMAs if mmap_lock is not already held.
 */
user_uintptr_t reserv_make_user_ptr_owning(ptraddr_t vma_addr, bool locked);

/**
 * reserv_vma_make_user_ptr_owning() - Build an owning user pointer for a given
 *   reservation.
 * @vma: Target VMA.
 *
 * Return: the constructed user pointer.
 *
 * @vma's reservation information will be used to set the user
 *   pointer's bounds and permissions. Its address will be set to @vma's start
 *   address. This function should be called with mmap_lock held.
 */
user_uintptr_t reserv_vma_make_user_ptr_owning(struct vm_area_struct *vma);

/**
 * reserv_is_supported() - Check if reservations are enabled for the given mm.
 *
 * @mm: The mm pointer.
 *
 * Return: True if mm has reservations enabled or false otherwise.
 */
static inline bool reserv_is_supported(struct mm_struct *mm)
{
	return test_bit(MMF_PCUABI_RESERV, &mm->flags);
}

/**
 * reserv_mm_set_flag() - Set the MMF_PCUABI_RESERV flag according to @compat.
 *
 * @mm: mm pointer.
 * @compat: Flag indicating if the current task is compat.
 */
static inline void reserv_mm_set_flag(struct mm_struct *mm, bool compat)
{
	if (compat)
		clear_bit(MMF_PCUABI_RESERV, &mm->flags);
	else
		set_bit(MMF_PCUABI_RESERV, &mm->flags);
}

/**
 * reserv_fork() - Copy the MMF_PCUABI_RESERV flag from @oldmm to @mm.
 *
 * @mm: New mm pointer.
 * @oldmm: Old mm pointer.
 */
static inline void reserv_fork(struct mm_struct *mm, struct mm_struct *oldmm)
{
	if (test_bit(MMF_PCUABI_RESERV, &oldmm->flags))
		set_bit(MMF_PCUABI_RESERV, &mm->flags);
}

#else /* CONFIG_CHERI_PURECAP_UABI */

#define reserv_representable_alignment(len) 0

#define reserv_representable_base(base, len) base

#define reserv_representable_length(len) len

#define reserv_vma_reserv_start(vma) vma->vm_start

#define reserv_vma_reserv_len(vma) (vma->vm_end - vma->vm_start)

static inline int reserv_vma_set_reserv(struct vm_area_struct *vma,
					ptraddr_t start, size_t len, int prot)
{
	return 0;
}

static inline int reserv_vma_set_reserv_start_len(struct vm_area_struct *vma,
						  ptraddr_t start, size_t len)
{
	return 0;
}

static inline void reserv_vma_set_reserv_data(struct vm_area_struct *vma,
					      const struct reserv_struct *reserv_data)
{}

static inline bool reserv_find_reserv_info_range(ptraddr_t start,
						 size_t len, bool locked,
						 struct reserv_struct *reserv_info)
{
	return true;
}

static inline bool reserv_vma_range_within_reserv(struct vm_area_struct *vma,
						  ptraddr_t start,
						  size_t len)
{
	return true;
}

static inline bool reserv_cap_within_reserv(user_uintptr_t cap, bool locked)
{
	return true;
}

static inline bool reserv_aligned_range_within_reserv(ptraddr_t start,
						      size_t len,
						      bool locked)
{
	return true;
}

static inline int reserv_range_mapped(ptraddr_t start, size_t len, bool locked)
{
	return 0;
}

static inline user_uintptr_t reserv_make_user_ptr_owning(ptraddr_t vma_addr,
							 bool locked)
{
	return vma_addr;
}

static inline user_uintptr_t reserv_vma_make_user_ptr_owning(struct vm_area_struct *vma)
{
	return vma->vm_start;
}

static inline bool reserv_is_supported(struct mm_struct *mm)
{
	return false;
}

static inline void reserv_mm_set_flag(struct mm_struct *mm, bool compat) {}

static inline void reserv_fork(struct mm_struct *mm, struct mm_struct *oldmm) {}

#endif /* CONFIG_CHERI_PURECAP_UABI */

#endif /* _LINUX_MM_RESERV_H */
