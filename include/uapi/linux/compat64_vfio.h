#pragma once


#include <linux/compat.h>


struct __c64_vfio_device_feature_dma_logging_control {
	__aligned_u64 page_size;
	__u32 num_ranges;
	__u32 __reserved;
	__c64_ptr64 ranges;
};

static __always_inline __maybe_unused void
__from_c64_vfio_device_feature_dma_logging_control(struct vfio_device_feature_dma_logging_control *p)
{
	union {
		struct vfio_device_feature_dma_logging_control native;
		const struct __c64_vfio_device_feature_dma_logging_control compat;
	} *u = (void *)p;

	u->native.ranges = (user_uintptr_t)compat_ptr(u->compat.ranges);
	u->native.__reserved = u->compat.__reserved;
	u->native.num_ranges = u->compat.num_ranges;
	u->native.page_size = u->compat.page_size;
}
static __always_inline __maybe_unused void
__to_c64_vfio_device_feature_dma_logging_control(struct vfio_device_feature_dma_logging_control *p)
{
	union {
		struct __c64_vfio_device_feature_dma_logging_control compat;
		const struct vfio_device_feature_dma_logging_control native;
	} *u = (void *)p;

	u->compat.page_size = u->native.page_size;
	u->compat.num_ranges = u->native.num_ranges;
	u->compat.__reserved = u->native.__reserved;
	u->compat.ranges = (__c64_ptr64 __force)u->native.ranges;
}
static __always_inline __maybe_unused void
__from_c64_vfio_device_feature_dma_logging_control_2(struct vfio_device_feature_dma_logging_control *native, const struct __c64_vfio_device_feature_dma_logging_control *compat)
{

	native->page_size = compat->page_size;
	native->num_ranges = compat->num_ranges;
	native->__reserved = compat->__reserved;
	native->ranges = (user_uintptr_t)compat_ptr(compat->ranges);
}
static __always_inline __maybe_unused void
__to_c64_vfio_device_feature_dma_logging_control_2(struct __c64_vfio_device_feature_dma_logging_control *compat, const struct vfio_device_feature_dma_logging_control *native)
{

	compat->page_size = native->page_size;
	compat->num_ranges = native->num_ranges;
	compat->__reserved = native->__reserved;
	compat->ranges = (__c64_ptr64 __force)native->ranges;
}
struct __c64_vfio_device_feature_dma_logging_report {
	__aligned_u64 iova;
	__aligned_u64 length;
	__aligned_u64 page_size;
	__c64_ptr64 bitmap;
};

static __always_inline __maybe_unused void
__from_c64_vfio_device_feature_dma_logging_report(struct vfio_device_feature_dma_logging_report *p)
{
	union {
		struct vfio_device_feature_dma_logging_report native;
		const struct __c64_vfio_device_feature_dma_logging_report compat;
	} *u = (void *)p;

	u->native.bitmap = (user_uintptr_t)compat_ptr(u->compat.bitmap);
	u->native.page_size = u->compat.page_size;
	u->native.length = u->compat.length;
	u->native.iova = u->compat.iova;
}
static __always_inline __maybe_unused void
__to_c64_vfio_device_feature_dma_logging_report(struct vfio_device_feature_dma_logging_report *p)
{
	union {
		struct __c64_vfio_device_feature_dma_logging_report compat;
		const struct vfio_device_feature_dma_logging_report native;
	} *u = (void *)p;

	u->compat.iova = u->native.iova;
	u->compat.length = u->native.length;
	u->compat.page_size = u->native.page_size;
	u->compat.bitmap = (__c64_ptr64 __force)u->native.bitmap;
}
static __always_inline __maybe_unused void
__from_c64_vfio_device_feature_dma_logging_report_2(struct vfio_device_feature_dma_logging_report *native, const struct __c64_vfio_device_feature_dma_logging_report *compat)
{

	native->iova = compat->iova;
	native->length = compat->length;
	native->page_size = compat->page_size;
	native->bitmap = (user_uintptr_t)compat_ptr(compat->bitmap);
}
static __always_inline __maybe_unused void
__to_c64_vfio_device_feature_dma_logging_report_2(struct __c64_vfio_device_feature_dma_logging_report *compat, const struct vfio_device_feature_dma_logging_report *native)
{

	compat->iova = native->iova;
	compat->length = native->length;
	compat->page_size = native->page_size;
	compat->bitmap = (__c64_ptr64 __force)native->bitmap;
}
struct __c64_vfio_iommu_type1_dma_map {
	__u32	argsz;
	__u32	flags;
	__c64_ptr64	vaddr;			/* Process virtual address */
	__u64	iova;				/* IO virtual address */
	__u64	size;				/* Size of mapping (bytes) */
};

static __always_inline __maybe_unused void
__from_c64_vfio_iommu_type1_dma_map(struct vfio_iommu_type1_dma_map *p)
{
	union {
		struct vfio_iommu_type1_dma_map native;
		const struct __c64_vfio_iommu_type1_dma_map compat;
	} *u = (void *)p;

	u->native.size = u->compat.size;
	u->native.iova = u->compat.iova;
	u->native.vaddr = (user_uintptr_t)compat_ptr(u->compat.vaddr);
	u->native.flags = u->compat.flags;
	u->native.argsz = u->compat.argsz;
}
static __always_inline __maybe_unused void
__to_c64_vfio_iommu_type1_dma_map(struct vfio_iommu_type1_dma_map *p)
{
	union {
		struct __c64_vfio_iommu_type1_dma_map compat;
		const struct vfio_iommu_type1_dma_map native;
	} *u = (void *)p;

	u->compat.argsz = u->native.argsz;
	u->compat.flags = u->native.flags;
	u->compat.vaddr = (__c64_ptr64 __force)u->native.vaddr;
	u->compat.iova = u->native.iova;
	u->compat.size = u->native.size;
}
static __always_inline __maybe_unused void
__from_c64_vfio_iommu_type1_dma_map_2(struct vfio_iommu_type1_dma_map *native, const struct __c64_vfio_iommu_type1_dma_map *compat)
{

	native->argsz = compat->argsz;
	native->flags = compat->flags;
	native->vaddr = (user_uintptr_t)compat_ptr(compat->vaddr);
	native->iova = compat->iova;
	native->size = compat->size;
}
static __always_inline __maybe_unused void
__to_c64_vfio_iommu_type1_dma_map_2(struct __c64_vfio_iommu_type1_dma_map *compat, const struct vfio_iommu_type1_dma_map *native)
{

	compat->argsz = native->argsz;
	compat->flags = native->flags;
	compat->vaddr = (__c64_ptr64 __force)native->vaddr;
	compat->iova = native->iova;
	compat->size = native->size;
}
struct __c64_vfio_bitmap {
	__u64        pgsize;	/* page size for bitmap in bytes */
	__u64        size;	/* in bytes */
	__c64_uptr data;	/* one bit per page */
};

static __always_inline __maybe_unused void
__from_c64_vfio_bitmap(struct vfio_bitmap *p)
{
	union {
		struct vfio_bitmap native;
		const struct __c64_vfio_bitmap compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.size = u->compat.size;
	u->native.pgsize = u->compat.pgsize;
}
static __always_inline __maybe_unused void
__to_c64_vfio_bitmap(struct vfio_bitmap *p)
{
	union {
		struct __c64_vfio_bitmap compat;
		const struct vfio_bitmap native;
	} *u = (void *)p;

	u->compat.pgsize = u->native.pgsize;
	u->compat.size = u->native.size;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_vfio_bitmap_2(struct vfio_bitmap *native, const struct __c64_vfio_bitmap *compat)
{

	native->pgsize = compat->pgsize;
	native->size = compat->size;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_vfio_bitmap_2(struct __c64_vfio_bitmap *compat, const struct vfio_bitmap *native)
{

	compat->pgsize = native->pgsize;
	compat->size = native->size;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_vfio_iommu_type1_dirty_bitmap_get {
	__u64              iova;	/* IO virtual address */
	__u64              size;	/* Size of iova range */
	struct __c64_vfio_bitmap bitmap;
};

static __always_inline __maybe_unused void
__from_c64_vfio_iommu_type1_dirty_bitmap_get(struct vfio_iommu_type1_dirty_bitmap_get *p)
{
	union {
		struct vfio_iommu_type1_dirty_bitmap_get native;
		const struct __c64_vfio_iommu_type1_dirty_bitmap_get compat;
	} *u = (void *)p;

	u->native.bitmap.data =  compat_ptr(u->compat.bitmap.data);
	u->native.bitmap.size = u->compat.bitmap.size;
	u->native.bitmap.pgsize = u->compat.bitmap.pgsize;
	u->native.size = u->compat.size;
	u->native.iova = u->compat.iova;
}
static __always_inline __maybe_unused void
__to_c64_vfio_iommu_type1_dirty_bitmap_get(struct vfio_iommu_type1_dirty_bitmap_get *p)
{
	union {
		struct __c64_vfio_iommu_type1_dirty_bitmap_get compat;
		const struct vfio_iommu_type1_dirty_bitmap_get native;
	} *u = (void *)p;

	u->compat.iova = u->native.iova;
	u->compat.size = u->native.size;
	u->compat.bitmap.pgsize = u->native.bitmap.pgsize;
	u->compat.bitmap.size = u->native.bitmap.size;
	u->compat.bitmap.data =  (__c64_uptr __force)(user_uintptr_t)u->native.bitmap.data;
}
static __always_inline __maybe_unused void
__from_c64_vfio_iommu_type1_dirty_bitmap_get_2(struct vfio_iommu_type1_dirty_bitmap_get *native, const struct __c64_vfio_iommu_type1_dirty_bitmap_get *compat)
{

	native->iova = compat->iova;
	native->size = compat->size;
	native->bitmap.pgsize = compat->bitmap.pgsize;
	native->bitmap.size = compat->bitmap.size;
	native->bitmap.data =  compat_ptr(compat->bitmap.data);
}
static __always_inline __maybe_unused void
__to_c64_vfio_iommu_type1_dirty_bitmap_get_2(struct __c64_vfio_iommu_type1_dirty_bitmap_get *compat, const struct vfio_iommu_type1_dirty_bitmap_get *native)
{

	compat->iova = native->iova;
	compat->size = native->size;
	compat->bitmap.pgsize = native->bitmap.pgsize;
	compat->bitmap.size = native->bitmap.size;
	compat->bitmap.data =  (__c64_uptr __force)(user_uintptr_t)native->bitmap.data;
}
