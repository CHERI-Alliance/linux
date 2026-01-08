#pragma once


#include <linux/compat.h>


struct __c64_pm_scan_arg {
	__u64 size;
	__u64 flags;
	__u64 start;
	__u64 end;
	__u64 walk_end;
	__c64_ptr64 vec;
	__u64 vec_len;
	__u64 max_pages;
	__u64 category_inverted;
	__u64 category_mask;
	__u64 category_anyof_mask;
	__u64 return_mask;
};

static __always_inline __maybe_unused void
__from_c64_pm_scan_arg(struct pm_scan_arg *p)
{
	union {
		struct pm_scan_arg native;
		const struct __c64_pm_scan_arg compat;
	} *u = (void *)p;

	u->native.return_mask = u->compat.return_mask;
	u->native.category_anyof_mask = u->compat.category_anyof_mask;
	u->native.category_mask = u->compat.category_mask;
	u->native.category_inverted = u->compat.category_inverted;
	u->native.max_pages = u->compat.max_pages;
	u->native.vec_len = u->compat.vec_len;
	u->native.vec = (user_uintptr_t)compat_ptr(u->compat.vec);
	u->native.walk_end = u->compat.walk_end;
	u->native.end = u->compat.end;
	u->native.start = u->compat.start;
	u->native.flags = u->compat.flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_pm_scan_arg(struct pm_scan_arg *p)
{
	union {
		struct __c64_pm_scan_arg compat;
		const struct pm_scan_arg native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.flags = u->native.flags;
	u->compat.start = u->native.start;
	u->compat.end = u->native.end;
	u->compat.walk_end = u->native.walk_end;
	u->compat.vec = (__c64_ptr64 __force)u->native.vec;
	u->compat.vec_len = u->native.vec_len;
	u->compat.max_pages = u->native.max_pages;
	u->compat.category_inverted = u->native.category_inverted;
	u->compat.category_mask = u->native.category_mask;
	u->compat.category_anyof_mask = u->native.category_anyof_mask;
	u->compat.return_mask = u->native.return_mask;
}
static __always_inline __maybe_unused void
__from_c64_pm_scan_arg_2(struct pm_scan_arg *native, const struct __c64_pm_scan_arg *compat)
{

	native->size = compat->size;
	native->flags = compat->flags;
	native->start = compat->start;
	native->end = compat->end;
	native->walk_end = compat->walk_end;
	native->vec = (user_uintptr_t)compat_ptr(compat->vec);
	native->vec_len = compat->vec_len;
	native->max_pages = compat->max_pages;
	native->category_inverted = compat->category_inverted;
	native->category_mask = compat->category_mask;
	native->category_anyof_mask = compat->category_anyof_mask;
	native->return_mask = compat->return_mask;
}
static __always_inline __maybe_unused void
__to_c64_pm_scan_arg_2(struct __c64_pm_scan_arg *compat, const struct pm_scan_arg *native)
{

	compat->size = native->size;
	compat->flags = native->flags;
	compat->start = native->start;
	compat->end = native->end;
	compat->walk_end = native->walk_end;
	compat->vec = (__c64_ptr64 __force)native->vec;
	compat->vec_len = native->vec_len;
	compat->max_pages = native->max_pages;
	compat->category_inverted = native->category_inverted;
	compat->category_mask = native->category_mask;
	compat->category_anyof_mask = native->category_anyof_mask;
	compat->return_mask = native->return_mask;
}
struct __c64_procmap_query {
	/* Query struct size, for backwards/forward compatibility */
	__u64 size;
	/*
	 * Query flags, a combination of enum procmap_query_flags values.
	 * Defines query filtering and behavior, see enum procmap_query_flags.
	 *
	 * Input argument, provided by user. Kernel doesn't modify it.
	 */
	__u64 query_flags;		/* in */
	/*
	 * Query address. By default, VMA that covers this address will
	 * be looked up. PROCMAP_QUERY_* flags above modify this default
	 * behavior further.
	 *
	 * Input argument, provided by user. Kernel doesn't modify it.
	 */
	__u64 query_addr;		/* in */
	/* VMA starting (inclusive) and ending (exclusive) address, if VMA is found. */
	__u64 vma_start;		/* out */
	__u64 vma_end;			/* out */
	/* VMA permissions flags. A combination of PROCMAP_QUERY_VMA_* flags. */
	__u64 vma_flags;		/* out */
	/* VMA backing page size granularity. */
	__u64 vma_page_size;		/* out */
	/*
	 * VMA file offset. If VMA has file backing, this specifies offset
	 * within the file that VMA's start address corresponds to.
	 * Is set to zero if VMA has no backing file.
	 */
	__u64 vma_offset;		/* out */
	/* Backing file's inode number, or zero, if VMA has no backing file. */
	__u64 inode;			/* out */
	/* Backing file's device major/minor number, or zero, if VMA has no backing file. */
	__u32 dev_major;		/* out */
	__u32 dev_minor;		/* out */
	/*
	 * If set to non-zero value, signals the request to return VMA name
	 * (i.e., VMA's backing file's absolute path, with " (deleted)" suffix
	 * appended, if file was unlinked from FS) for matched VMA. VMA name
	 * can also be some special name (e.g., "[heap]", "[stack]") or could
	 * be even user-supplied with prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME).
	 *
	 * Kernel will set this field to zero, if VMA has no associated name.
	 * Otherwise kernel will return actual amount of bytes filled in
	 * user-supplied buffer (see vma_name_addr field below), including the
	 * terminating zero.
	 *
	 * If VMA name is longer that user-supplied maximum buffer size,
	 * -E2BIG error is returned.
	 *
	 * If this field is set to non-zero value, vma_name_addr should point
	 * to valid user space memory buffer of at least vma_name_size bytes.
	 * If set to zero, vma_name_addr should be set to zero as well
	 */
	__u32 vma_name_size;		/* in/out */
	/*
	 * If set to non-zero value, signals the request to extract and return
	 * VMA's backing file's build ID, if the backing file is an ELF file
	 * and it contains embedded build ID.
	 *
	 * Kernel will set this field to zero, if VMA has no backing file,
	 * backing file is not an ELF file, or ELF file has no build ID
	 * embedded.
	 *
	 * Build ID is a binary value (not a string). Kernel will set
	 * build_id_size field to exact number of bytes used for build ID.
	 * If build ID is requested and present, but needs more bytes than
	 * user-supplied maximum buffer size (see build_id_addr field below),
	 * -E2BIG error will be returned.
	 *
	 * If this field is set to non-zero value, build_id_addr should point
	 * to valid user space memory buffer of at least build_id_size bytes.
	 * If set to zero, build_id_addr should be set to zero as well
	 */
	__u32 build_id_size;		/* in/out */
	/*
	 * User-supplied address of a buffer of at least vma_name_size bytes
	 * for kernel to fill with matched VMA's name (see vma_name_size field
	 * description above for details).
	 *
	 * Should be set to zero if VMA name should not be returned.
	 */
	__c64_ptr64 vma_name_addr;		/* in */
	/*
	 * User-supplied address of a buffer of at least build_id_size bytes
	 * for kernel to fill with matched VMA's ELF build ID, if available
	 * (see build_id_size field description above for details).
	 *
	 * Should be set to zero if build ID should not be returned.
	 */
	__c64_ptr64 build_id_addr;		/* in */
};

static __always_inline __maybe_unused void
__from_c64_procmap_query(struct procmap_query *p)
{
	union {
		struct procmap_query native;
		const struct __c64_procmap_query compat;
	} *u = (void *)p;

	u->native.build_id_addr = (user_uintptr_t)compat_ptr(u->compat.build_id_addr);
	u->native.vma_name_addr = (user_uintptr_t)compat_ptr(u->compat.vma_name_addr);
	u->native.build_id_size = u->compat.build_id_size;
	u->native.vma_name_size = u->compat.vma_name_size;
	u->native.dev_minor = u->compat.dev_minor;
	u->native.dev_major = u->compat.dev_major;
	u->native.inode = u->compat.inode;
	u->native.vma_offset = u->compat.vma_offset;
	u->native.vma_page_size = u->compat.vma_page_size;
	u->native.vma_flags = u->compat.vma_flags;
	u->native.vma_end = u->compat.vma_end;
	u->native.vma_start = u->compat.vma_start;
	u->native.query_addr = u->compat.query_addr;
	u->native.query_flags = u->compat.query_flags;
	u->native.size = u->compat.size;
}
static __always_inline __maybe_unused void
__to_c64_procmap_query(struct procmap_query *p)
{
	union {
		struct __c64_procmap_query compat;
		const struct procmap_query native;
	} *u = (void *)p;

	u->compat.size = u->native.size;
	u->compat.query_flags = u->native.query_flags;
	u->compat.query_addr = u->native.query_addr;
	u->compat.vma_start = u->native.vma_start;
	u->compat.vma_end = u->native.vma_end;
	u->compat.vma_flags = u->native.vma_flags;
	u->compat.vma_page_size = u->native.vma_page_size;
	u->compat.vma_offset = u->native.vma_offset;
	u->compat.inode = u->native.inode;
	u->compat.dev_major = u->native.dev_major;
	u->compat.dev_minor = u->native.dev_minor;
	u->compat.vma_name_size = u->native.vma_name_size;
	u->compat.build_id_size = u->native.build_id_size;
	u->compat.vma_name_addr = (__c64_ptr64 __force)u->native.vma_name_addr;
	u->compat.build_id_addr = (__c64_ptr64 __force)u->native.build_id_addr;
}
static __always_inline __maybe_unused void
__from_c64_procmap_query_2(struct procmap_query *native, const struct __c64_procmap_query *compat)
{

	native->size = compat->size;
	native->query_flags = compat->query_flags;
	native->query_addr = compat->query_addr;
	native->vma_start = compat->vma_start;
	native->vma_end = compat->vma_end;
	native->vma_flags = compat->vma_flags;
	native->vma_page_size = compat->vma_page_size;
	native->vma_offset = compat->vma_offset;
	native->inode = compat->inode;
	native->dev_major = compat->dev_major;
	native->dev_minor = compat->dev_minor;
	native->vma_name_size = compat->vma_name_size;
	native->build_id_size = compat->build_id_size;
	native->vma_name_addr = (user_uintptr_t)compat_ptr(compat->vma_name_addr);
	native->build_id_addr = (user_uintptr_t)compat_ptr(compat->build_id_addr);
}
static __always_inline __maybe_unused void
__to_c64_procmap_query_2(struct __c64_procmap_query *compat, const struct procmap_query *native)
{

	compat->size = native->size;
	compat->query_flags = native->query_flags;
	compat->query_addr = native->query_addr;
	compat->vma_start = native->vma_start;
	compat->vma_end = native->vma_end;
	compat->vma_flags = native->vma_flags;
	compat->vma_page_size = native->vma_page_size;
	compat->vma_offset = native->vma_offset;
	compat->inode = native->inode;
	compat->dev_major = native->dev_major;
	compat->dev_minor = native->dev_minor;
	compat->vma_name_size = native->vma_name_size;
	compat->build_id_size = native->build_id_size;
	compat->vma_name_addr = (__c64_ptr64 __force)native->vma_name_addr;
	compat->build_id_addr = (__c64_ptr64 __force)native->build_id_addr;
}
