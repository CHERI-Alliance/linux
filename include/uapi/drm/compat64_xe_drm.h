#pragma once


#include <linux/compat.h>


struct __c64_drm_xe_user_extension {
	/**
	 * @next_extension:
	 *
	 * Pointer to the next struct drm_xe_user_extension, or zero if the end.
	 */
	__c64_ptr64 next_extension;

	/**
	 * @name: Name of the extension.
	 *
	 * Note that the name here is just some integer.
	 *
	 * Also note that the name space for this is not global for the whole
	 * driver, but rather its scope/meaning is limited to the specific piece
	 * of uAPI which has embedded the struct drm_xe_user_extension.
	 */
	__u32 name;

	/**
	 * @pad: MBZ
	 *
	 * All undefined bits must be zero.
	 */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_user_extension(struct drm_xe_user_extension *p)
{
	union {
		struct drm_xe_user_extension native;
		const struct __c64_drm_xe_user_extension compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.name = u->compat.name;
	u->native.next_extension = (user_uintptr_t)compat_ptr(u->compat.next_extension);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_user_extension(struct drm_xe_user_extension *p)
{
	union {
		struct __c64_drm_xe_user_extension compat;
		const struct drm_xe_user_extension native;
	} *u = (void *)p;

	u->compat.next_extension = (__c64_ptr64 __force)u->native.next_extension;
	u->compat.name = u->native.name;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_user_extension_2(struct drm_xe_user_extension *native, const struct __c64_drm_xe_user_extension *compat)
{

	native->next_extension = (user_uintptr_t)compat_ptr(compat->next_extension);
	native->name = compat->name;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_user_extension_2(struct __c64_drm_xe_user_extension *compat, const struct drm_xe_user_extension *native)
{

	compat->next_extension = (__c64_ptr64 __force)native->next_extension;
	compat->name = native->name;
	compat->pad = native->pad;
}
struct __c64_drm_xe_ext_set_property {
	/** @base: base user extension */
	struct __c64_drm_xe_user_extension base;

	/** @property: property to set */
	__u32 property;

	/** @pad: MBZ */
	__u32 pad;

	union {
		struct {
			/** @value: property value */
			__c64_ptr64 value;

			/** @reserved: Reserved */
		};
		/// UAPI: NoConvert: Padding
		__u64 reserved[3];
	};
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_ext_set_property(struct drm_xe_ext_set_property *p)
{
	union {
		struct drm_xe_ext_set_property native;
		const struct __c64_drm_xe_ext_set_property compat;
	} *u = (void *)p;

	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.pad = u->compat.pad;
	u->native.property = u->compat.property;
	u->native.base.pad = u->compat.base.pad;
	u->native.base.name = u->compat.base.name;
	u->native.base.next_extension = (user_uintptr_t)compat_ptr(u->compat.base.next_extension);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_ext_set_property(struct drm_xe_ext_set_property *p)
{
	union {
		struct __c64_drm_xe_ext_set_property compat;
		const struct drm_xe_ext_set_property native;
	} *u = (void *)p;

	u->compat.base.next_extension = (__c64_ptr64 __force)u->native.base.next_extension;
	u->compat.base.name = u->native.base.name;
	u->compat.base.pad = u->native.base.pad;
	u->compat.property = u->native.property;
	u->compat.pad = u->native.pad;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_ext_set_property_2(struct drm_xe_ext_set_property *native, const struct __c64_drm_xe_ext_set_property *compat)
{

	native->base.next_extension = (user_uintptr_t)compat_ptr(compat->base.next_extension);
	native->base.name = compat->base.name;
	native->base.pad = compat->base.pad;
	native->property = compat->property;
	native->pad = compat->pad;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_ext_set_property_2(struct __c64_drm_xe_ext_set_property *compat, const struct drm_xe_ext_set_property *native)
{

	compat->base.next_extension = (__c64_ptr64 __force)native->base.next_extension;
	compat->base.name = native->base.name;
	compat->base.pad = native->base.pad;
	compat->property = native->property;
	compat->pad = native->pad;
	compat->value = (__c64_ptr64 __force)native->value;
}
struct __c64_drm_xe_device_query {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @query: The type of data to query */
	__u32 query;

	/** @size: Size of the queried data */
	__u32 size;

	/** @data: Queried data is placed here */
	__c64_ptr64 data;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_device_query(struct drm_xe_device_query *p)
{
	union {
		struct drm_xe_device_query native;
		const struct __c64_drm_xe_device_query compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.size = u->compat.size;
	u->native.query = u->compat.query;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_device_query(struct drm_xe_device_query *p)
{
	union {
		struct __c64_drm_xe_device_query compat;
		const struct drm_xe_device_query native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.query = u->native.query;
	u->compat.size = u->native.size;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_device_query_2(struct drm_xe_device_query *native, const struct __c64_drm_xe_device_query *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->query = compat->query;
	native->size = compat->size;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_device_query_2(struct __c64_drm_xe_device_query *compat, const struct drm_xe_device_query *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->query = native->query;
	compat->size = native->size;
	compat->data = (__c64_ptr64 __force)native->data;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_gem_create {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/**
	 * @size: Size of the object to be created, must match region
	 * (system or vram) minimum alignment (&min_page_size).
	 */
	__u64 size;

	/**
	 * @placement: A mask of memory instances of where BO can be placed.
	 * Each index in this mask refers directly to the struct
	 * drm_xe_query_mem_regions' instance, no assumptions should
	 * be made about order. The type of each region is described
	 * by struct drm_xe_query_mem_regions' mem_class.
	 */
	__u32 placement;

	/**
	 * @flags: Flags, currently a mask of memory instances of where BO can
	 * be placed
	 */
	__u32 flags;

	/**
	 * @vm_id: Attached VM, if any
	 *
	 * If a VM is specified, this BO must:
	 *
	 *  1. Only ever be bound to that VM.
	 *  2. Cannot be exported as a PRIME fd.
	 */
	__u32 vm_id;

	/**
	 * @handle: Returned handle for the object.
	 *
	 * Object handles are nonzero.
	 */
	__u32 handle;

	/**
	 * @cpu_caching: The CPU caching mode to select for this object. If
	 * mmaping the object the mode selected here will also be used. The
	 * exception is when mapping system memory (including data evicted
	 * to system) on discrete GPUs. The caching mode selected will
	 * then be overridden to DRM_XE_GEM_CPU_CACHING_WB, and coherency
	 * between GPU- and CPU is guaranteed. The caching mode of
	 * existing CPU-mappings will be updated transparently to
	 * user-space clients.
	 */
	__u16 cpu_caching;
	/** @pad: MBZ */
	__u16 pad[3];

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_gem_create(struct drm_xe_gem_create *p)
{
	union {
		struct drm_xe_gem_create native;
		const struct __c64_drm_xe_gem_create compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	BUILD_BUG_ON(sizeof(u->compat.pad) != sizeof(u->native.pad));
	memmove(&u->native.pad, &u->compat.pad, sizeof(u->native.pad));
	u->native.cpu_caching = u->compat.cpu_caching;
	u->native.handle = u->compat.handle;
	u->native.vm_id = u->compat.vm_id;
	u->native.flags = u->compat.flags;
	u->native.placement = u->compat.placement;
	u->native.size = u->compat.size;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_gem_create(struct drm_xe_gem_create *p)
{
	union {
		struct __c64_drm_xe_gem_create compat;
		const struct drm_xe_gem_create native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.size = u->native.size;
	u->compat.placement = u->native.placement;
	u->compat.flags = u->native.flags;
	u->compat.vm_id = u->native.vm_id;
	u->compat.handle = u->native.handle;
	u->compat.cpu_caching = u->native.cpu_caching;
	BUILD_BUG_ON(sizeof(u->native.pad) != sizeof(u->compat.pad));
	memmove(&u->compat.pad, &u->native.pad, sizeof(u->compat.pad));
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_gem_create_2(struct drm_xe_gem_create *native, const struct __c64_drm_xe_gem_create *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->size = compat->size;
	native->placement = compat->placement;
	native->flags = compat->flags;
	native->vm_id = compat->vm_id;
	native->handle = compat->handle;
	native->cpu_caching = compat->cpu_caching;
	BUILD_BUG_ON(sizeof(compat->pad) != sizeof(native->pad));
	memcpy(&native->pad, &compat->pad, sizeof(native->pad));
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_gem_create_2(struct __c64_drm_xe_gem_create *compat, const struct drm_xe_gem_create *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->size = native->size;
	compat->placement = native->placement;
	compat->flags = native->flags;
	compat->vm_id = native->vm_id;
	compat->handle = native->handle;
	compat->cpu_caching = native->cpu_caching;
	BUILD_BUG_ON(sizeof(native->pad) != sizeof(compat->pad));
	memcpy(&compat->pad, &native->pad, sizeof(compat->pad));
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_gem_mmap_offset {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @handle: Handle for the object being mapped. */
	__u32 handle;

	/** @flags: Flags */
	__u32 flags;

	/** @offset: The fake offset to use for subsequent mmap call */
	__u64 offset;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_gem_mmap_offset(struct drm_xe_gem_mmap_offset *p)
{
	union {
		struct drm_xe_gem_mmap_offset native;
		const struct __c64_drm_xe_gem_mmap_offset compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.offset = u->compat.offset;
	u->native.flags = u->compat.flags;
	u->native.handle = u->compat.handle;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_gem_mmap_offset(struct drm_xe_gem_mmap_offset *p)
{
	union {
		struct __c64_drm_xe_gem_mmap_offset compat;
		const struct drm_xe_gem_mmap_offset native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.handle = u->native.handle;
	u->compat.flags = u->native.flags;
	u->compat.offset = u->native.offset;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_gem_mmap_offset_2(struct drm_xe_gem_mmap_offset *native, const struct __c64_drm_xe_gem_mmap_offset *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->handle = compat->handle;
	native->flags = compat->flags;
	native->offset = compat->offset;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_gem_mmap_offset_2(struct __c64_drm_xe_gem_mmap_offset *compat, const struct drm_xe_gem_mmap_offset *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->handle = native->handle;
	compat->flags = native->flags;
	compat->offset = native->offset;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_vm_create {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @flags: Flags */
	__u32 flags;

	/** @vm_id: Returned VM ID */
	__u32 vm_id;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_vm_create(struct drm_xe_vm_create *p)
{
	union {
		struct drm_xe_vm_create native;
		const struct __c64_drm_xe_vm_create compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.vm_id = u->compat.vm_id;
	u->native.flags = u->compat.flags;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_vm_create(struct drm_xe_vm_create *p)
{
	union {
		struct __c64_drm_xe_vm_create compat;
		const struct drm_xe_vm_create native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.flags = u->native.flags;
	u->compat.vm_id = u->native.vm_id;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_vm_create_2(struct drm_xe_vm_create *native, const struct __c64_drm_xe_vm_create *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->flags = compat->flags;
	native->vm_id = compat->vm_id;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_vm_create_2(struct __c64_drm_xe_vm_create *compat, const struct drm_xe_vm_create *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->flags = native->flags;
	compat->vm_id = native->vm_id;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_vm_bind_op {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/**
	 * @obj: GEM object to operate on, MBZ for MAP_USERPTR, MBZ for UNMAP
	 */
	__u32 obj;

	/**
	 * @pat_index: The platform defined @pat_index to use for this mapping.
	 * The index basically maps to some predefined memory attributes,
	 * including things like caching, coherency, compression etc.  The exact
	 * meaning of the pat_index is platform specific and defined in the
	 * Bspec and PRMs.  When the KMD sets up the binding the index here is
	 * encoded into the ppGTT PTE.
	 *
	 * For coherency the @pat_index needs to be at least 1way coherent when
	 * drm_xe_gem_create.cpu_caching is DRM_XE_GEM_CPU_CACHING_WB. The KMD
	 * will extract the coherency mode from the @pat_index and reject if
	 * there is a mismatch (see note below for pre-MTL platforms).
	 *
	 * Note: On pre-MTL platforms there is only a caching mode and no
	 * explicit coherency mode, but on such hardware there is always a
	 * shared-LLC (or is dgpu) so all GT memory accesses are coherent with
	 * CPU caches even with the caching mode set as uncached.  It's only the
	 * display engine that is incoherent (on dgpu it must be in VRAM which
	 * is always mapped as WC on the CPU). However to keep the uapi somewhat
	 * consistent with newer platforms the KMD groups the different cache
	 * levels into the following coherency buckets on all pre-MTL platforms:
	 *
	 *	ppGTT UC -> COH_NONE
	 *	ppGTT WC -> COH_NONE
	 *	ppGTT WT -> COH_NONE
	 *	ppGTT WB -> COH_AT_LEAST_1WAY
	 *
	 * In practice UC/WC/WT should only ever used for scanout surfaces on
	 * such platforms (or perhaps in general for dma-buf if shared with
	 * another device) since it is only the display engine that is actually
	 * incoherent.  Everything else should typically use WB given that we
	 * have a shared-LLC.  On MTL+ this completely changes and the HW
	 * defines the coherency mode as part of the @pat_index, where
	 * incoherent GT access is possible.
	 *
	 * Note: For userptr and externally imported dma-buf the kernel expects
	 * either 1WAY or 2WAY for the @pat_index.
	 *
	 * For DRM_XE_VM_BIND_FLAG_NULL bindings there are no KMD restrictions
	 * on the @pat_index. For such mappings there is no actual memory being
	 * mapped (the address in the PTE is invalid), so the various PAT memory
	 * attributes likely do not apply.  Simply leaving as zero is one
	 * option (still a valid pat_index). Same applies to
	 * DRM_XE_VM_BIND_FLAG_CPU_ADDR_MIRROR bindings as for such mapping
	 * there is no actual memory being mapped.
	 */
	__u16 pat_index;

	/** @pad: MBZ */
	__u16 pad;

	union {
		/**
		 * @obj_offset: Offset into the object, MBZ for CLEAR_RANGE,
		 * ignored for unbind
		 */
		__u64 obj_offset;

		/** @userptr: user pointer to bind on */
		__c64_ptr64 userptr;

		/**
		 * @cpu_addr_mirror_offset: Offset from GPU @addr to create
		 * CPU address mirror mappings. MBZ with current level of
		 * support (e.g. 1 to 1 mapping between GPU and CPU mappings
		 * only supported).
		 */
		__s64 cpu_addr_mirror_offset;
	};

	/**
	 * @range: Number of bytes from the object to bind to addr, MBZ for UNMAP_ALL
	 */
	__u64 range;

	/** @addr: Address to operate on, MBZ for UNMAP_ALL */
	__u64 addr;

	/** @op: Bind operation to perform */
	__u32 op;

	/** @flags: Bind flags */
	__u32 flags;

	/**
	 * @prefetch_mem_region_instance: Memory region to prefetch VMA to.
	 * It is a region instance, not a mask.
	 * To be used only with %DRM_XE_VM_BIND_OP_PREFETCH operation.
	 */
	__u32 prefetch_mem_region_instance;

	/** @pad2: MBZ */
	__u32 pad2;

	/** @reserved: Reserved */
	__u64 reserved[3];
};

struct __c64_drm_xe_vm_bind {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @vm_id: The ID of the VM to bind to */
	__u32 vm_id;

	/**
	 * @exec_queue_id: exec_queue_id, must be of class DRM_XE_ENGINE_CLASS_VM_BIND
	 * and exec queue must have same vm_id. If zero, the default VM bind engine
	 * is used.
	 */
	__u32 exec_queue_id;

	/** @pad: MBZ */
	__u32 pad;

	/** @num_binds: number of binds in this IOCTL */
	__u32 num_binds;

	union {
		/** @bind: used if num_binds == 1 */
		struct __c64_drm_xe_vm_bind_op bind;

		/**
		 * @vector_of_binds: userptr to array of struct
		 * drm_xe_vm_bind_op if num_binds > 1
		 */
		__c64_ptr64 vector_of_binds;
	};

	/** @pad2: MBZ */
	__u32 pad2;

	/** @num_syncs: amount of syncs to wait on */
	__u32 num_syncs;

	/** @syncs: pointer to struct drm_xe_sync array */
	__c64_ptr64 syncs;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

struct __c64_drm_xe_exec_queue_create {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @width: submission width (number BB per exec) for this exec queue */
	__u16 width;

	/** @num_placements: number of valid placements for this exec queue */
	__u16 num_placements;

	/** @vm_id: VM to use for this exec queue */
	__u32 vm_id;

	/** @flags: flags to use for this exec queue */
	__u32 flags;

	/** @exec_queue_id: Returned exec queue ID */
	__u32 exec_queue_id;

	/**
	 * @instances: user pointer to a 2-d array of struct
	 * drm_xe_engine_class_instance
	 *
	 * length = width (i) * num_placements (j)
	 * index = j + i * width
	 */
	__c64_ptr64 instances;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_exec_queue_create(struct drm_xe_exec_queue_create *p)
{
	union {
		struct drm_xe_exec_queue_create native;
		const struct __c64_drm_xe_exec_queue_create compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.instances = (user_uintptr_t)compat_ptr(u->compat.instances);
	u->native.exec_queue_id = u->compat.exec_queue_id;
	u->native.flags = u->compat.flags;
	u->native.vm_id = u->compat.vm_id;
	u->native.num_placements = u->compat.num_placements;
	u->native.width = u->compat.width;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec_queue_create(struct drm_xe_exec_queue_create *p)
{
	union {
		struct __c64_drm_xe_exec_queue_create compat;
		const struct drm_xe_exec_queue_create native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.width = u->native.width;
	u->compat.num_placements = u->native.num_placements;
	u->compat.vm_id = u->native.vm_id;
	u->compat.flags = u->native.flags;
	u->compat.exec_queue_id = u->native.exec_queue_id;
	u->compat.instances = (__c64_ptr64 __force)u->native.instances;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_exec_queue_create_2(struct drm_xe_exec_queue_create *native, const struct __c64_drm_xe_exec_queue_create *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->width = compat->width;
	native->num_placements = compat->num_placements;
	native->vm_id = compat->vm_id;
	native->flags = compat->flags;
	native->exec_queue_id = compat->exec_queue_id;
	native->instances = (user_uintptr_t)compat_ptr(compat->instances);
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec_queue_create_2(struct __c64_drm_xe_exec_queue_create *compat, const struct drm_xe_exec_queue_create *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->width = native->width;
	compat->num_placements = native->num_placements;
	compat->vm_id = native->vm_id;
	compat->flags = native->flags;
	compat->exec_queue_id = native->exec_queue_id;
	compat->instances = (__c64_ptr64 __force)native->instances;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_exec_queue_get_property {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @exec_queue_id: Exec queue ID */
	__u32 exec_queue_id;

	/** @property: property to get */
	__u32 property;

	/** @value: property value */
	__u64 value;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_exec_queue_get_property(struct drm_xe_exec_queue_get_property *p)
{
	union {
		struct drm_xe_exec_queue_get_property native;
		const struct __c64_drm_xe_exec_queue_get_property compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.value = u->compat.value;
	u->native.property = u->compat.property;
	u->native.exec_queue_id = u->compat.exec_queue_id;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec_queue_get_property(struct drm_xe_exec_queue_get_property *p)
{
	union {
		struct __c64_drm_xe_exec_queue_get_property compat;
		const struct drm_xe_exec_queue_get_property native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.exec_queue_id = u->native.exec_queue_id;
	u->compat.property = u->native.property;
	u->compat.value = u->native.value;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_exec_queue_get_property_2(struct drm_xe_exec_queue_get_property *native, const struct __c64_drm_xe_exec_queue_get_property *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->exec_queue_id = compat->exec_queue_id;
	native->property = compat->property;
	native->value = compat->value;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec_queue_get_property_2(struct __c64_drm_xe_exec_queue_get_property *compat, const struct drm_xe_exec_queue_get_property *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->exec_queue_id = native->exec_queue_id;
	compat->property = native->property;
	compat->value = native->value;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_sync {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @type: Type of the this sync object */
	__u32 type;

	/** @flags: Sync Flags */
	__u32 flags;

	union {
		/** @handle: Handle for the object */
		/// UAPI: NoConvert: Only convert as an u64
		__u32 handle;

		/**
		 * @addr: Address of user fence. When sync is passed in via exec
		 * IOCTL this is a GPU address in the VM. When sync passed in via
		 * VM bind IOCTL this is a user pointer. In either case, it is
		 * the users responsibility that this address is present and
		 * mapped when the user fence is signalled. Must be qword
		 * aligned.
		 */
		/// UAPI: NoConvert: Only convert as an u64
		__c64_ptr64 __c64_addr;
		__u64 __c64_copy;
	};

	/**
	 * @timeline_value: Input for the timeline sync object. Needs to be
	 * different than 0 when used with %DRM_XE_SYNC_FLAG_TIMELINE_SYNCOBJ.
	 */
	__u64 timeline_value;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_sync(struct drm_xe_sync *p)
{
	union {
		struct drm_xe_sync native;
		const struct __c64_drm_xe_sync compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.timeline_value = u->compat.timeline_value;
	u->native.__c64_copy = u->compat.__c64_copy;
	u->native.flags = u->compat.flags;
	u->native.type = u->compat.type;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_sync(struct drm_xe_sync *p)
{
	union {
		struct __c64_drm_xe_sync compat;
		const struct drm_xe_sync native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.type = u->native.type;
	u->compat.flags = u->native.flags;
	u->compat.__c64_copy = u->native.__c64_copy;
	u->compat.timeline_value = u->native.timeline_value;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_sync_2(struct drm_xe_sync *native, const struct __c64_drm_xe_sync *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->type = compat->type;
	native->flags = compat->flags;
	native->__c64_copy = compat->__c64_copy;
	native->timeline_value = compat->timeline_value;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_sync_2(struct __c64_drm_xe_sync *compat, const struct drm_xe_sync *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->type = native->type;
	compat->flags = native->flags;
	compat->__c64_copy = native->__c64_copy;
	compat->timeline_value = native->timeline_value;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_exec {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @exec_queue_id: Exec queue ID for the batch buffer */
	__u32 exec_queue_id;

	/** @num_syncs: Amount of struct drm_xe_sync in array. */
	__u32 num_syncs;

	/** @syncs: Pointer to struct drm_xe_sync array. */
	__c64_ptr64 syncs;

	/**
	 * @address: address of batch buffer if num_batch_buffer == 1 or an
	 * array of batch buffer addresses
	 */
	__c64_ptr64 address;

	/**
	 * @num_batch_buffer: number of batch buffer in this exec, must match
	 * the width of the engine
	 */
	__u16 num_batch_buffer;

	/** @pad: MBZ */
	__u16 pad[3];

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_exec(struct drm_xe_exec *p)
{
	union {
		struct drm_xe_exec native;
		const struct __c64_drm_xe_exec compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	BUILD_BUG_ON(sizeof(u->compat.pad) != sizeof(u->native.pad));
	memmove(&u->native.pad, &u->compat.pad, sizeof(u->native.pad));
	u->native.num_batch_buffer = u->compat.num_batch_buffer;
	u->native.address = (user_uintptr_t)compat_ptr(u->compat.address);
	u->native.syncs = (user_uintptr_t)compat_ptr(u->compat.syncs);
	u->native.num_syncs = u->compat.num_syncs;
	u->native.exec_queue_id = u->compat.exec_queue_id;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec(struct drm_xe_exec *p)
{
	union {
		struct __c64_drm_xe_exec compat;
		const struct drm_xe_exec native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.exec_queue_id = u->native.exec_queue_id;
	u->compat.num_syncs = u->native.num_syncs;
	u->compat.syncs = (__c64_ptr64 __force)u->native.syncs;
	u->compat.address = (__c64_ptr64 __force)u->native.address;
	u->compat.num_batch_buffer = u->native.num_batch_buffer;
	BUILD_BUG_ON(sizeof(u->native.pad) != sizeof(u->compat.pad));
	memmove(&u->compat.pad, &u->native.pad, sizeof(u->compat.pad));
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_exec_2(struct drm_xe_exec *native, const struct __c64_drm_xe_exec *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->exec_queue_id = compat->exec_queue_id;
	native->num_syncs = compat->num_syncs;
	native->syncs = (user_uintptr_t)compat_ptr(compat->syncs);
	native->address = (user_uintptr_t)compat_ptr(compat->address);
	native->num_batch_buffer = compat->num_batch_buffer;
	BUILD_BUG_ON(sizeof(compat->pad) != sizeof(native->pad));
	memcpy(&native->pad, &compat->pad, sizeof(native->pad));
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_exec_2(struct __c64_drm_xe_exec *compat, const struct drm_xe_exec *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->exec_queue_id = native->exec_queue_id;
	compat->num_syncs = native->num_syncs;
	compat->syncs = (__c64_ptr64 __force)native->syncs;
	compat->address = (__c64_ptr64 __force)native->address;
	compat->num_batch_buffer = native->num_batch_buffer;
	BUILD_BUG_ON(sizeof(native->pad) != sizeof(compat->pad));
	memcpy(&compat->pad, &native->pad, sizeof(compat->pad));
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_wait_user_fence {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/**
	 * @addr: user pointer address to wait on, must qword aligned
	 */
	__c64_ptr64 addr;

	/** @op: wait operation (type of comparison) */
	__u16 op;

	/** @flags: wait flags */
	__u16 flags;

	/** @pad: MBZ */
	__u32 pad;

	/** @value: compare value */
	__u64 value;

	/** @mask: comparison mask */
	__u64 mask;

	/**
	 * @timeout: how long to wait before bailing, value in nanoseconds.
	 * Without DRM_XE_UFENCE_WAIT_FLAG_ABSTIME flag set (relative timeout)
	 * it contains timeout expressed in nanoseconds to wait (fence will
	 * expire at now() + timeout).
	 * When DRM_XE_UFENCE_WAIT_FLAG_ABSTIME flat is set (absolute timeout) wait
	 * will end at timeout (uses system MONOTONIC_CLOCK).
	 * Passing negative timeout leads to neverending wait.
	 *
	 * On relative timeout this value is updated with timeout left
	 * (for restarting the call in case of signal delivery).
	 * On absolute timeout this value stays intact (restarted call still
	 * expire at the same point of time).
	 */
	__s64 timeout;

	/** @exec_queue_id: exec_queue_id returned from xe_exec_queue_create_ioctl */
	__u32 exec_queue_id;

	/** @pad2: MBZ */
	__u32 pad2;

	/** @reserved: Reserved */
	__u64 reserved[2];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_wait_user_fence(struct drm_xe_wait_user_fence *p)
{
	union {
		struct drm_xe_wait_user_fence native;
		const struct __c64_drm_xe_wait_user_fence compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.pad2 = u->compat.pad2;
	u->native.exec_queue_id = u->compat.exec_queue_id;
	u->native.timeout = u->compat.timeout;
	u->native.mask = u->compat.mask;
	u->native.value = u->compat.value;
	u->native.pad = u->compat.pad;
	u->native.flags = u->compat.flags;
	u->native.op = u->compat.op;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_wait_user_fence(struct drm_xe_wait_user_fence *p)
{
	union {
		struct __c64_drm_xe_wait_user_fence compat;
		const struct drm_xe_wait_user_fence native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.op = u->native.op;
	u->compat.flags = u->native.flags;
	u->compat.pad = u->native.pad;
	u->compat.value = u->native.value;
	u->compat.mask = u->native.mask;
	u->compat.timeout = u->native.timeout;
	u->compat.exec_queue_id = u->native.exec_queue_id;
	u->compat.pad2 = u->native.pad2;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_wait_user_fence_2(struct drm_xe_wait_user_fence *native, const struct __c64_drm_xe_wait_user_fence *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->op = compat->op;
	native->flags = compat->flags;
	native->pad = compat->pad;
	native->value = compat->value;
	native->mask = compat->mask;
	native->timeout = compat->timeout;
	native->exec_queue_id = compat->exec_queue_id;
	native->pad2 = compat->pad2;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_wait_user_fence_2(struct __c64_drm_xe_wait_user_fence *compat, const struct drm_xe_wait_user_fence *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->op = native->op;
	compat->flags = native->flags;
	compat->pad = native->pad;
	compat->value = native->value;
	compat->mask = native->mask;
	compat->timeout = native->timeout;
	compat->exec_queue_id = native->exec_queue_id;
	compat->pad2 = native->pad2;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_drm_xe_observation_param {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;
	/** @observation_type: observation stream type, of enum @drm_xe_observation_type */
	__u64 observation_type;
	/** @observation_op: observation stream op, of enum @drm_xe_observation_op */
	__u64 observation_op;
	/** @param: Pointer to actual stream params */
	__c64_ptr64 param;
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_observation_param(struct drm_xe_observation_param *p)
{
	union {
		struct drm_xe_observation_param native;
		const struct __c64_drm_xe_observation_param compat;
	} *u = (void *)p;

	u->native.param = (user_uintptr_t)compat_ptr(u->compat.param);
	u->native.observation_op = u->compat.observation_op;
	u->native.observation_type = u->compat.observation_type;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_observation_param(struct drm_xe_observation_param *p)
{
	union {
		struct __c64_drm_xe_observation_param compat;
		const struct drm_xe_observation_param native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.observation_type = u->native.observation_type;
	u->compat.observation_op = u->native.observation_op;
	u->compat.param = (__c64_ptr64 __force)u->native.param;
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_observation_param_2(struct drm_xe_observation_param *native, const struct __c64_drm_xe_observation_param *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->observation_type = compat->observation_type;
	native->observation_op = compat->observation_op;
	native->param = (user_uintptr_t)compat_ptr(compat->param);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_observation_param_2(struct __c64_drm_xe_observation_param *compat, const struct drm_xe_observation_param *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->observation_type = native->observation_type;
	compat->observation_op = native->observation_op;
	compat->param = (__c64_ptr64 __force)native->param;
}
struct __c64_drm_xe_oa_config {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @uuid: String formatted like "%\08x-%\04x-%\04x-%\04x-%\012x" */
	char uuid[36];

	/** @n_regs: Number of regs in @regs_ptr */
	__u32 n_regs;

	/**
	 * @regs_ptr: Pointer to (register address, value) pairs for OA config
	 * registers. Expected length of buffer is: (2 * sizeof(u32) * @n_regs).
	 */
	__c64_ptr64 regs_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_oa_config(struct drm_xe_oa_config *p)
{
	union {
		struct drm_xe_oa_config native;
		const struct __c64_drm_xe_oa_config compat;
	} *u = (void *)p;

	u->native.regs_ptr = (user_uintptr_t)compat_ptr(u->compat.regs_ptr);
	u->native.n_regs = u->compat.n_regs;
	BUILD_BUG_ON(sizeof(u->compat.uuid) != sizeof(u->native.uuid));
	memmove(&u->native.uuid, &u->compat.uuid, sizeof(u->native.uuid));
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_oa_config(struct drm_xe_oa_config *p)
{
	union {
		struct __c64_drm_xe_oa_config compat;
		const struct drm_xe_oa_config native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	BUILD_BUG_ON(sizeof(u->native.uuid) != sizeof(u->compat.uuid));
	memmove(&u->compat.uuid, &u->native.uuid, sizeof(u->compat.uuid));
	u->compat.n_regs = u->native.n_regs;
	u->compat.regs_ptr = (__c64_ptr64 __force)u->native.regs_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_oa_config_2(struct drm_xe_oa_config *native, const struct __c64_drm_xe_oa_config *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	BUILD_BUG_ON(sizeof(compat->uuid) != sizeof(native->uuid));
	memcpy(&native->uuid, &compat->uuid, sizeof(native->uuid));
	native->n_regs = compat->n_regs;
	native->regs_ptr = (user_uintptr_t)compat_ptr(compat->regs_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_oa_config_2(struct __c64_drm_xe_oa_config *compat, const struct drm_xe_oa_config *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	BUILD_BUG_ON(sizeof(native->uuid) != sizeof(compat->uuid));
	memcpy(&compat->uuid, &native->uuid, sizeof(compat->uuid));
	compat->n_regs = native->n_regs;
	compat->regs_ptr = (__c64_ptr64 __force)native->regs_ptr;
}
struct __c64_drm_xe_oa_stream_info {
	/** @extensions: Pointer to the first extension struct, if any */
	__c64_ptr64 extensions;

	/** @oa_buf_size: OA buffer size */
	__u64 oa_buf_size;

	/** @reserved: reserved for future use */
	__u64 reserved[3];
};

static __always_inline __maybe_unused void
__from_c64_drm_xe_oa_stream_info(struct drm_xe_oa_stream_info *p)
{
	union {
		struct drm_xe_oa_stream_info native;
		const struct __c64_drm_xe_oa_stream_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.oa_buf_size = u->compat.oa_buf_size;
	u->native.extensions = (user_uintptr_t)compat_ptr(u->compat.extensions);
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_oa_stream_info(struct drm_xe_oa_stream_info *p)
{
	union {
		struct __c64_drm_xe_oa_stream_info compat;
		const struct drm_xe_oa_stream_info native;
	} *u = (void *)p;

	u->compat.extensions = (__c64_ptr64 __force)u->native.extensions;
	u->compat.oa_buf_size = u->native.oa_buf_size;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_drm_xe_oa_stream_info_2(struct drm_xe_oa_stream_info *native, const struct __c64_drm_xe_oa_stream_info *compat)
{

	native->extensions = (user_uintptr_t)compat_ptr(compat->extensions);
	native->oa_buf_size = compat->oa_buf_size;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_drm_xe_oa_stream_info_2(struct __c64_drm_xe_oa_stream_info *compat, const struct drm_xe_oa_stream_info *native)
{

	compat->extensions = (__c64_ptr64 __force)native->extensions;
	compat->oa_buf_size = native->oa_buf_size;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
