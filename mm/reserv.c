// SPDX-License-Identifier: GPL-2.0

#include <linux/bug.h>
#include <linux/mm_reserv.h>
#include <linux/mm.h>
#include <linux/slab.h>

static inline void
reserv_calculate_outer(struct reserv_struct *reserv)
{
	ptraddr_t start = reserv->inner_start;
	ptraddr_t end = reserv->inner_start + reserv->inner_len;
	ptraddr_t mask = cheri_representable_alignment_mask(end - start);

	while ((start & mask) != start) {
		start &= mask;
		mask = cheri_representable_alignment_mask(end - start);
	}

	reserv->outer_start = start;
	reserv->outer_len = cheri_representable_length(end - start);
}

int reserv_vma_set_reserv(struct vm_area_struct *vma, ptraddr_t start,
			  size_t len, int prot)
{
	if (!reserv_is_supported(vma->vm_mm))
		return 0;
	if (start + len < start)
		return -EINVAL;
	/* Reservation base/length is expected as page aligned */
	VM_BUG_ON(start & ~PAGE_MASK || len % PAGE_SIZE);

	vma->reserv_data.inner_start = start;
	vma->reserv_data.inner_len = len;
	reserv_calculate_outer(&vma->reserv_data);
	vma->reserv_data.perms = user_ptr_owning_perms_from_prot(prot,
								 vma->vm_flags);

	return 0;
}

int reserv_vma_set_reserv_start_len(struct vm_area_struct *vma, ptraddr_t start,
				    size_t len)
{
	if (!reserv_is_supported(vma->vm_mm))
		return 0;
	if (start + len < start)
		return -EINVAL;
	/* Reservation base/length is expected as page aligned */
	VM_BUG_ON(start & ~PAGE_MASK || len % PAGE_SIZE);

	vma->reserv_data.inner_start = start;
	vma->reserv_data.inner_len = len;
	reserv_calculate_outer(&vma->reserv_data);

	return 0;
}

void reserv_vma_set_reserv_data(struct vm_area_struct *vma,
				const struct reserv_struct *reserv_data)
{
	if (!reserv_is_supported(vma->vm_mm))
		return;

	vma->reserv_data = *reserv_data;
}

bool reserv_find_reserv_info_range(ptraddr_t start, size_t len,
				   bool locked, struct reserv_struct *reserv_info)
{
	struct mm_struct *mm = current->mm;
	struct vm_area_struct *next, *prev;
	struct reserv_struct *info = NULL;

	if (!reserv_is_supported(mm))
		return true;
	if (!locked && mmap_read_lock_killable(mm))
		return false;

	next = find_vma_prev(mm, start, &prev);

	if (next && reserv_vma_range_within_reserv(next, start, len))
		info = &next->reserv_data;
	else if (prev && reserv_vma_range_within_reserv(prev, start, len))
		info = &prev->reserv_data;

	if (info && reserv_info)
		*reserv_info = *info;

	if (!locked)
		mmap_read_unlock(mm);

	return !!info;
}

bool reserv_vma_range_within_reserv(struct vm_area_struct *vma, ptraddr_t start,
				    size_t len)
{
	if (!reserv_is_supported(vma->vm_mm))
		return true;

	/* Check if there is match with the existing reservations */
	return vma->reserv_data.inner_start <= start &&
		vma->reserv_data.inner_start + vma->reserv_data.inner_len >= start + len;
}

bool reserv_cap_within_reserv(user_uintptr_t cap, bool locked)
{
	struct reserv_struct reserv;
	ptraddr_t base, len;

	if (!reserv_is_supported(current->mm))
		return true;
	if (!reserv_find_reserv_info_range(cheri_address_get(cap), 1,
					   locked, &reserv))
		return false;

	base = cheri_base_get(cap);
	len = cheri_length_get(cap);
	return base + len > len && reserv.outer_start <= base &&
		base + len <= reserv.outer_start + reserv.outer_len;
}

bool reserv_range_within_reserv(ptraddr_t start, size_t len, bool locked)
{
	ptraddr_t aligned_start = start & cheri_representable_alignment_mask(len);
	size_t aligned_len = cheri_representable_length(len);

	if (start + len < start)
		return false;

	return reserv_find_reserv_info_range(aligned_start, aligned_len,
					     locked, NULL);
}

int reserv_range_mapped(ptraddr_t start, size_t len, bool locked)
{
	struct vm_area_struct *vma, *last_vma = NULL;
	struct mm_struct *mm = current->mm;
	ptraddr_t end = start + len - 1;
	int ret = -ENOMEM;
	VMA_ITERATOR(vmi, mm, 0);

	if (!reserv_is_supported(mm))
		return 0;
	if (!locked && mmap_read_lock_killable(mm))
		return -EINTR;

	start = untagged_addr(start);
	start = round_down(start, PAGE_SIZE);
	len = round_up(len, PAGE_SIZE);
	vma_iter_set(&vmi, start);
	/* Try walking the given range */
	do {
		vma = mas_find(&vmi.mas, end);
		if (vma) {
			/* The new and old vma should be continuous */
			if (last_vma && last_vma->vm_end != vma->vm_start)
				goto out;
			/* End range is within the vma so return success */
			if (end < vma->vm_end) {
				ret = 0;
				goto out;
			}
			last_vma = vma;
		}
	} while (vma);
out:
	if (!locked)
		mmap_read_unlock(mm);
	return ret;
}

user_uintptr_t reserv_make_user_ptr_owning(ptraddr_t vma_addr, bool locked)
{
	struct mm_struct *mm = current->mm;
	struct vm_area_struct *vma;
	struct reserv_struct reserv;

	if (!reserv_is_supported(mm))
		return __c_fakeu(vma_addr);
	if (!locked && mmap_read_lock_killable(mm))
		return __c_fakeu(vma_addr);

	vma = find_vma(mm, vma_addr);

	if (WARN_ON(!vma || vma->vm_start != vma_addr)) {
		if (!locked)
			mmap_read_unlock(mm);
		return __c_fakeu(vma_addr);
	}

	reserv = vma->reserv_data;

	if (!locked)
		mmap_read_unlock(mm);

	return make_user_ptr_owning(&reserv, vma_addr);
}

user_uintptr_t reserv_vma_make_user_ptr_owning(struct vm_area_struct *vma)
{
	if (!reserv_is_supported(vma->vm_mm))
		return __c_fakeu(vma->vm_start);

	return make_user_ptr_owning(&vma->reserv_data, vma->vm_start);
}
