#pragma once


#include <linux/compat.h>


struct __c64_iommu_ioas_iova_ranges {
	__u32 size;
	__u32 ioas_id;
	__u32 num_iovas;
	__u32 __reserved;
	__c64_ptr64 allowed_iovas;
	__aligned_u64 out_iova_alignment;
};

static __always_inline __maybe_unused void
__from_c64_iommu_ioas_iova_ranges(struct iommu_ioas_iova_ranges *p)
{
	union {
		struct iommu_ioas_iova_ranges native;
		const struct __c64_iommu_ioas_iova_ranges compat;
	} *u = (void *)p;

	u->native.out_iova_alignment = u->compat.out_iova_alignment;
	u->native.allowed_iovas = (user_uintptr_t)compat_ptr(u->compat.allowed_iovas);
	u->native.__reserved = u->compat.__reserved;
	u->native.num_iovas = u->compat.num_iovas;
	u->native.ioas_id = u->compat.ioas_id;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_iova_ranges(struct iommu_ioas_iova_ranges *p)
{
	union {
		struct __c64_iommu_ioas_iova_ranges compat;
		const struct iommu_ioas_iova_ranges native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.ioas_id = u->native.ioas_id;
	u->compat.num_iovas = u->native.num_iovas;
	u->compat.__reserved = u->native.__reserved;
	u->compat.allowed_iovas = (__c64_ptr64 __force)u->native.allowed_iovas;
	u->compat.out_iova_alignment = u->native.out_iova_alignment;
}
static __always_inline __maybe_unused void
__from_c64_iommu_ioas_iova_ranges_2(struct iommu_ioas_iova_ranges *native, const struct __c64_iommu_ioas_iova_ranges *compat)
{

	native->size = compat->size;
	native->ioas_id = compat->ioas_id;
	native->num_iovas = compat->num_iovas;
	native->__reserved = compat->__reserved;
	native->allowed_iovas = (user_uintptr_t)compat_ptr(compat->allowed_iovas);
	native->out_iova_alignment = compat->out_iova_alignment;
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_iova_ranges_2(struct __c64_iommu_ioas_iova_ranges *compat, const struct iommu_ioas_iova_ranges *native)
{

	compat->size = native->size;
	compat->ioas_id = native->ioas_id;
	compat->num_iovas = native->num_iovas;
	compat->__reserved = native->__reserved;
	compat->allowed_iovas = (__c64_ptr64 __force)native->allowed_iovas;
	compat->out_iova_alignment = native->out_iova_alignment;
}
struct __c64_iommu_ioas_allow_iovas {
	__u32 size;
	__u32 ioas_id;
	__u32 num_iovas;
	__u32 __reserved;
	__c64_ptr64 allowed_iovas;
};

static __always_inline __maybe_unused void
__from_c64_iommu_ioas_allow_iovas(struct iommu_ioas_allow_iovas *p)
{
	union {
		struct iommu_ioas_allow_iovas native;
		const struct __c64_iommu_ioas_allow_iovas compat;
	} *u = (void *)p;

	u->native.allowed_iovas = (user_uintptr_t)compat_ptr(u->compat.allowed_iovas);
	u->native.__reserved = u->compat.__reserved;
	u->native.num_iovas = u->compat.num_iovas;
	u->native.ioas_id = u->compat.ioas_id;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_allow_iovas(struct iommu_ioas_allow_iovas *p)
{
	union {
		struct __c64_iommu_ioas_allow_iovas compat;
		const struct iommu_ioas_allow_iovas native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.ioas_id = u->native.ioas_id;
	u->compat.num_iovas = u->native.num_iovas;
	u->compat.__reserved = u->native.__reserved;
	u->compat.allowed_iovas = (__c64_ptr64 __force)u->native.allowed_iovas;
}
static __always_inline __maybe_unused void
__from_c64_iommu_ioas_allow_iovas_2(struct iommu_ioas_allow_iovas *native, const struct __c64_iommu_ioas_allow_iovas *compat)
{

	native->size = compat->size;
	native->ioas_id = compat->ioas_id;
	native->num_iovas = compat->num_iovas;
	native->__reserved = compat->__reserved;
	native->allowed_iovas = (user_uintptr_t)compat_ptr(compat->allowed_iovas);
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_allow_iovas_2(struct __c64_iommu_ioas_allow_iovas *compat, const struct iommu_ioas_allow_iovas *native)
{

	compat->size = native->size;
	compat->ioas_id = native->ioas_id;
	compat->num_iovas = native->num_iovas;
	compat->__reserved = native->__reserved;
	compat->allowed_iovas = (__c64_ptr64 __force)native->allowed_iovas;
}
struct __c64_iommu_ioas_map {
	__u32 size;
	__u32 flags;
	__u32 ioas_id;
	__u32 __reserved;
	__c64_ptr64 user_va;
	__aligned_u64 length;
	__aligned_u64 iova;
};

static __always_inline __maybe_unused void
__from_c64_iommu_ioas_map(struct iommu_ioas_map *p)
{
	union {
		struct iommu_ioas_map native;
		const struct __c64_iommu_ioas_map compat;
	} *u = (void *)p;

	u->native.iova = u->compat.iova;
	u->native.length = u->compat.length;
	u->native.user_va = (user_uintptr_t)compat_ptr(u->compat.user_va);
	u->native.__reserved = u->compat.__reserved;
	u->native.ioas_id = u->compat.ioas_id;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_map(struct iommu_ioas_map *p)
{
	union {
		struct __c64_iommu_ioas_map compat;
		const struct iommu_ioas_map native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.ioas_id = u->native.ioas_id;
	u->compat.__reserved = u->native.__reserved;
	u->compat.user_va = (__c64_ptr64 __force)u->native.user_va;
	u->compat.length = u->native.length;
	u->compat.iova = u->native.iova;
}
static __always_inline __maybe_unused void
__from_c64_iommu_ioas_map_2(struct iommu_ioas_map *native, const struct __c64_iommu_ioas_map *compat)
{

	native->size = compat->size;
	native->flags = compat->flags;
	native->ioas_id = compat->ioas_id;
	native->__reserved = compat->__reserved;
	native->user_va = (user_uintptr_t)compat_ptr(compat->user_va);
	native->length = compat->length;
	native->iova = compat->iova;
}
static __always_inline __maybe_unused void
__to_c64_iommu_ioas_map_2(struct __c64_iommu_ioas_map *compat, const struct iommu_ioas_map *native)
{

	compat->size = native->size;
	compat->flags = native->flags;
	compat->ioas_id = native->ioas_id;
	compat->__reserved = native->__reserved;
	compat->user_va = (__c64_ptr64 __force)native->user_va;
	compat->length = native->length;
	compat->iova = native->iova;
}
struct __c64_iommu_hwpt_alloc {
	__u32 size;
	__u32 flags;
	__u32 dev_id;
	__u32 pt_id;
	__u32 out_hwpt_id;
	__u32 __reserved;
	__u32 data_type;
	__u32 data_len;
	__c64_ptr64 data_uptr;
	__u32 fault_id;
	__u32 __reserved2;
};

static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_alloc(struct iommu_hwpt_alloc *p)
{
	union {
		struct iommu_hwpt_alloc native;
		const struct __c64_iommu_hwpt_alloc compat;
	} *u = (void *)p;

	u->native.__reserved2 = u->compat.__reserved2;
	u->native.fault_id = u->compat.fault_id;
	u->native.data_uptr = (user_uintptr_t)compat_ptr(u->compat.data_uptr);
	u->native.data_len = u->compat.data_len;
	u->native.data_type = u->compat.data_type;
	u->native.__reserved = u->compat.__reserved;
	u->native.out_hwpt_id = u->compat.out_hwpt_id;
	u->native.pt_id = u->compat.pt_id;
	u->native.dev_id = u->compat.dev_id;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_alloc(struct iommu_hwpt_alloc *p)
{
	union {
		struct __c64_iommu_hwpt_alloc compat;
		const struct iommu_hwpt_alloc native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.dev_id = u->native.dev_id;
	u->compat.pt_id = u->native.pt_id;
	u->compat.out_hwpt_id = u->native.out_hwpt_id;
	u->compat.__reserved = u->native.__reserved;
	u->compat.data_type = u->native.data_type;
	u->compat.data_len = u->native.data_len;
	u->compat.data_uptr = (__c64_ptr64 __force)u->native.data_uptr;
	u->compat.fault_id = u->native.fault_id;
	u->compat.__reserved2 = u->native.__reserved2;
}
static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_alloc_2(struct iommu_hwpt_alloc *native, const struct __c64_iommu_hwpt_alloc *compat)
{

	native->size = compat->size;
	native->flags = compat->flags;
	native->dev_id = compat->dev_id;
	native->pt_id = compat->pt_id;
	native->out_hwpt_id = compat->out_hwpt_id;
	native->__reserved = compat->__reserved;
	native->data_type = compat->data_type;
	native->data_len = compat->data_len;
	native->data_uptr = (user_uintptr_t)compat_ptr(compat->data_uptr);
	native->fault_id = compat->fault_id;
	native->__reserved2 = compat->__reserved2;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_alloc_2(struct __c64_iommu_hwpt_alloc *compat, const struct iommu_hwpt_alloc *native)
{

	compat->size = native->size;
	compat->flags = native->flags;
	compat->dev_id = native->dev_id;
	compat->pt_id = native->pt_id;
	compat->out_hwpt_id = native->out_hwpt_id;
	compat->__reserved = native->__reserved;
	compat->data_type = native->data_type;
	compat->data_len = native->data_len;
	compat->data_uptr = (__c64_ptr64 __force)native->data_uptr;
	compat->fault_id = native->fault_id;
	compat->__reserved2 = native->__reserved2;
}
struct __c64_iommu_hw_info {
	__u32 size;
	__u32 flags;
	__u32 dev_id;
	__u32 data_len;
	__c64_ptr64 data_uptr;
	__u32 out_data_type;
	__u8 out_max_pasid_log2;
	__u8 __reserved[3];
	__aligned_u64 out_capabilities;
};

static __always_inline __maybe_unused void
__from_c64_iommu_hw_info(struct iommu_hw_info *p)
{
	union {
		struct iommu_hw_info native;
		const struct __c64_iommu_hw_info compat;
	} *u = (void *)p;

	u->native.out_capabilities = u->compat.out_capabilities;
	BUILD_BUG_ON(sizeof(u->compat.__reserved) != sizeof(u->native.__reserved));
	memmove(&u->native.__reserved, &u->compat.__reserved, sizeof(u->native.__reserved));
	u->native.out_max_pasid_log2 = u->compat.out_max_pasid_log2;
	u->native.out_data_type = u->compat.out_data_type;
	u->native.data_uptr = (user_uintptr_t)compat_ptr(u->compat.data_uptr);
	u->native.data_len = u->compat.data_len;
	u->native.dev_id = u->compat.dev_id;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hw_info(struct iommu_hw_info *p)
{
	union {
		struct __c64_iommu_hw_info compat;
		const struct iommu_hw_info native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.dev_id = u->native.dev_id;
	u->compat.data_len = u->native.data_len;
	u->compat.data_uptr = (__c64_ptr64 __force)u->native.data_uptr;
	u->compat.out_data_type = u->native.out_data_type;
	u->compat.out_max_pasid_log2 = u->native.out_max_pasid_log2;
	BUILD_BUG_ON(sizeof(u->native.__reserved) != sizeof(u->compat.__reserved));
	memmove(&u->compat.__reserved, &u->native.__reserved, sizeof(u->compat.__reserved));
	u->compat.out_capabilities = u->native.out_capabilities;
}
static __always_inline __maybe_unused void
__from_c64_iommu_hw_info_2(struct iommu_hw_info *native, const struct __c64_iommu_hw_info *compat)
{

	native->size = compat->size;
	native->flags = compat->flags;
	native->dev_id = compat->dev_id;
	native->data_len = compat->data_len;
	native->data_uptr = (user_uintptr_t)compat_ptr(compat->data_uptr);
	native->out_data_type = compat->out_data_type;
	native->out_max_pasid_log2 = compat->out_max_pasid_log2;
	BUILD_BUG_ON(sizeof(compat->__reserved) != sizeof(native->__reserved));
	memcpy(&native->__reserved, &compat->__reserved, sizeof(native->__reserved));
	native->out_capabilities = compat->out_capabilities;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hw_info_2(struct __c64_iommu_hw_info *compat, const struct iommu_hw_info *native)
{

	compat->size = native->size;
	compat->flags = native->flags;
	compat->dev_id = native->dev_id;
	compat->data_len = native->data_len;
	compat->data_uptr = (__c64_ptr64 __force)native->data_uptr;
	compat->out_data_type = native->out_data_type;
	compat->out_max_pasid_log2 = native->out_max_pasid_log2;
	BUILD_BUG_ON(sizeof(native->__reserved) != sizeof(compat->__reserved));
	memcpy(&compat->__reserved, &native->__reserved, sizeof(compat->__reserved));
	compat->out_capabilities = native->out_capabilities;
}
struct __c64_iommu_hwpt_get_dirty_bitmap {
	__u32 size;
	__u32 hwpt_id;
	__u32 flags;
	__u32 __reserved;
	__aligned_u64 iova;
	__aligned_u64 length;
	__aligned_u64 page_size;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_get_dirty_bitmap(struct iommu_hwpt_get_dirty_bitmap *p)
{
	union {
		struct iommu_hwpt_get_dirty_bitmap native;
		const struct __c64_iommu_hwpt_get_dirty_bitmap compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.page_size = u->compat.page_size;
	u->native.length = u->compat.length;
	u->native.iova = u->compat.iova;
	u->native.__reserved = u->compat.__reserved;
	u->native.flags = u->compat.flags;
	u->native.hwpt_id = u->compat.hwpt_id;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_get_dirty_bitmap(struct iommu_hwpt_get_dirty_bitmap *p)
{
	union {
		struct __c64_iommu_hwpt_get_dirty_bitmap compat;
		const struct iommu_hwpt_get_dirty_bitmap native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.hwpt_id = u->native.hwpt_id;
	u->compat.flags = u->native.flags;
	u->compat.__reserved = u->native.__reserved;
	u->compat.iova = u->native.iova;
	u->compat.length = u->native.length;
	u->compat.page_size = u->native.page_size;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_get_dirty_bitmap_2(struct iommu_hwpt_get_dirty_bitmap *native, const struct __c64_iommu_hwpt_get_dirty_bitmap *compat)
{

	native->size = compat->size;
	native->hwpt_id = compat->hwpt_id;
	native->flags = compat->flags;
	native->__reserved = compat->__reserved;
	native->iova = compat->iova;
	native->length = compat->length;
	native->page_size = compat->page_size;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_get_dirty_bitmap_2(struct __c64_iommu_hwpt_get_dirty_bitmap *compat, const struct iommu_hwpt_get_dirty_bitmap *native)
{

	compat->size = native->size;
	compat->hwpt_id = native->hwpt_id;
	compat->flags = native->flags;
	compat->__reserved = native->__reserved;
	compat->iova = native->iova;
	compat->length = native->length;
	compat->page_size = native->page_size;
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_iommu_hwpt_invalidate {
	__u32 size;
	__u32 hwpt_id;
	__c64_ptr64 data_uptr;
	__u32 data_type;
	__u32 entry_len;
	__u32 entry_num;
	__u32 __reserved;
};

static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_invalidate(struct iommu_hwpt_invalidate *p)
{
	union {
		struct iommu_hwpt_invalidate native;
		const struct __c64_iommu_hwpt_invalidate compat;
	} *u = (void *)p;

	u->native.__reserved = u->compat.__reserved;
	u->native.entry_num = u->compat.entry_num;
	u->native.entry_len = u->compat.entry_len;
	u->native.data_type = u->compat.data_type;
	u->native.data_uptr = (user_uintptr_t)compat_ptr(u->compat.data_uptr);
	u->native.hwpt_id = u->compat.hwpt_id;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_invalidate(struct iommu_hwpt_invalidate *p)
{
	union {
		struct __c64_iommu_hwpt_invalidate compat;
		const struct iommu_hwpt_invalidate native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.hwpt_id = u->native.hwpt_id;
	u->compat.data_uptr = (__c64_ptr64 __force)u->native.data_uptr;
	u->compat.data_type = u->native.data_type;
	u->compat.entry_len = u->native.entry_len;
	u->compat.entry_num = u->native.entry_num;
	u->compat.__reserved = u->native.__reserved;
}
static __always_inline __maybe_unused void
__from_c64_iommu_hwpt_invalidate_2(struct iommu_hwpt_invalidate *native, const struct __c64_iommu_hwpt_invalidate *compat)
{

	native->size = compat->size;
	native->hwpt_id = compat->hwpt_id;
	native->data_uptr = (user_uintptr_t)compat_ptr(compat->data_uptr);
	native->data_type = compat->data_type;
	native->entry_len = compat->entry_len;
	native->entry_num = compat->entry_num;
	native->__reserved = compat->__reserved;
}
static __always_inline __maybe_unused void
__to_c64_iommu_hwpt_invalidate_2(struct __c64_iommu_hwpt_invalidate *compat, const struct iommu_hwpt_invalidate *native)
{

	compat->size = native->size;
	compat->hwpt_id = native->hwpt_id;
	compat->data_uptr = (__c64_ptr64 __force)native->data_uptr;
	compat->data_type = native->data_type;
	compat->entry_len = native->entry_len;
	compat->entry_num = native->entry_num;
	compat->__reserved = native->__reserved;
}
