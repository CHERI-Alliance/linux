#pragma once


#include <linux/compat.h>


struct __c64_drm_panthor_obj_array {
	/** @stride: Stride of object struct. Used for versioning. */
	__u32 stride;

	/** @count: Number of objects in the array. */
	__u32 count;

	/** @array: User pointer to an array of objects. */
	__c64_ptr64 array;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_obj_array(struct drm_panthor_obj_array *p)
{
	union {
		struct drm_panthor_obj_array native;
		const struct __c64_drm_panthor_obj_array compat;
	} *u = (void *)p;

	u->native.array = (user_uintptr_t)compat_ptr(u->compat.array);
	u->native.count = u->compat.count;
	u->native.stride = u->compat.stride;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_obj_array(struct drm_panthor_obj_array *p)
{
	union {
		struct __c64_drm_panthor_obj_array compat;
		const struct drm_panthor_obj_array native;
	} *u = (void *)p;

	u->compat.stride = u->native.stride;
	u->compat.count = u->native.count;
	u->compat.array = (__c64_ptr64 __force)u->native.array;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_obj_array_2(struct drm_panthor_obj_array *native, const struct __c64_drm_panthor_obj_array *compat)
{

	native->stride = compat->stride;
	native->count = compat->count;
	native->array = (user_uintptr_t)compat_ptr(compat->array);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_obj_array_2(struct __c64_drm_panthor_obj_array *compat, const struct drm_panthor_obj_array *native)
{

	compat->stride = native->stride;
	compat->count = native->count;
	compat->array = (__c64_ptr64 __force)native->array;
}
struct __c64_drm_panthor_dev_query {
	/** @type: the query type (see drm_panthor_dev_query_type). */
	__u32 type;

	/**
	 * @size: size of the type being queried.
	 *
	 * If pointer is NULL, size is updated by the driver to provide the
	 * output structure size. If pointer is not NULL, the driver will
	 * only copy min(size, actual_structure_size) bytes to the pointer,
	 * and update the size accordingly. This allows us to extend query
	 * types without breaking userspace.
	 */
	__u32 size;

	/**
	 * @pointer: user pointer to a query type struct.
	 *
	 * Pointer can be NULL, in which case, nothing is copied, but the
	 * actual structure size is returned. If not NULL, it must point to
	 * a location that's large enough to hold size bytes.
	 */
	__c64_ptr64 pointer;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_dev_query(struct drm_panthor_dev_query *p)
{
	union {
		struct drm_panthor_dev_query native;
		const struct __c64_drm_panthor_dev_query compat;
	} *u = (void *)p;

	u->native.pointer = (user_uintptr_t)compat_ptr(u->compat.pointer);
	u->native.size = u->compat.size;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_dev_query(struct drm_panthor_dev_query *p)
{
	union {
		struct __c64_drm_panthor_dev_query compat;
		const struct drm_panthor_dev_query native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.size = u->native.size;
	u->compat.pointer = (__c64_ptr64 __force)u->native.pointer;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_dev_query_2(struct drm_panthor_dev_query *native, const struct __c64_drm_panthor_dev_query *compat)
{

	native->type = compat->type;
	native->size = compat->size;
	native->pointer = (user_uintptr_t)compat_ptr(compat->pointer);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_dev_query_2(struct __c64_drm_panthor_dev_query *compat, const struct drm_panthor_dev_query *native)
{

	compat->type = native->type;
	compat->size = native->size;
	compat->pointer = (__c64_ptr64 __force)native->pointer;
}
struct __c64_drm_panthor_vm_bind_op {
	/** @flags: Combination of drm_panthor_vm_bind_op_flags flags. */
	__u32 flags;

	/**
	 * @bo_handle: Handle of the buffer object to map.
	 * MBZ for unmap or sync-only operations.
	 */
	__u32 bo_handle;

	/**
	 * @bo_offset: Buffer object offset.
	 * MBZ for unmap or sync-only operations.
	 */
	__u64 bo_offset;

	/**
	 * @va: Virtual address to map/unmap.
	 * MBZ for sync-only operations.
	 */
	__u64 va;

	/**
	 * @size: Size to map/unmap.
	 * MBZ for sync-only operations.
	 */
	__u64 size;

	/**
	 * @syncs: Array of struct drm_panthor_sync_op synchronization
	 * operations.
	 *
	 * This array must be empty if %DRM_PANTHOR_VM_BIND_ASYNC is not set on
	 * the drm_panthor_vm_bind object containing this VM bind operation.
	 *
	 * This array shall not be empty for sync-only operations.
	 */
	struct __c64_drm_panthor_obj_array syncs;

};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_vm_bind_op(struct drm_panthor_vm_bind_op *p)
{
	union {
		struct drm_panthor_vm_bind_op native;
		const struct __c64_drm_panthor_vm_bind_op compat;
	} *u = (void *)p;

	u->native.syncs.array = (user_uintptr_t)compat_ptr(u->compat.syncs.array);
	u->native.syncs.count = u->compat.syncs.count;
	u->native.syncs.stride = u->compat.syncs.stride;
	u->native.size = u->compat.size;
	u->native.va = u->compat.va;
	u->native.bo_offset = u->compat.bo_offset;
	u->native.bo_handle = u->compat.bo_handle;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_vm_bind_op(struct drm_panthor_vm_bind_op *p)
{
	union {
		struct __c64_drm_panthor_vm_bind_op compat;
		const struct drm_panthor_vm_bind_op native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.bo_handle = u->native.bo_handle;
	u->compat.bo_offset = u->native.bo_offset;
	u->compat.va = u->native.va;
	u->compat.size = u->native.size;
	u->compat.syncs.stride = u->native.syncs.stride;
	u->compat.syncs.count = u->native.syncs.count;
	u->compat.syncs.array = (__c64_ptr64 __force)u->native.syncs.array;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_vm_bind_op_2(struct drm_panthor_vm_bind_op *native, const struct __c64_drm_panthor_vm_bind_op *compat)
{

	native->flags = compat->flags;
	native->bo_handle = compat->bo_handle;
	native->bo_offset = compat->bo_offset;
	native->va = compat->va;
	native->size = compat->size;
	native->syncs.stride = compat->syncs.stride;
	native->syncs.count = compat->syncs.count;
	native->syncs.array = (user_uintptr_t)compat_ptr(compat->syncs.array);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_vm_bind_op_2(struct __c64_drm_panthor_vm_bind_op *compat, const struct drm_panthor_vm_bind_op *native)
{

	compat->flags = native->flags;
	compat->bo_handle = native->bo_handle;
	compat->bo_offset = native->bo_offset;
	compat->va = native->va;
	compat->size = native->size;
	compat->syncs.stride = native->syncs.stride;
	compat->syncs.count = native->syncs.count;
	compat->syncs.array = (__c64_ptr64 __force)native->syncs.array;
}
struct __c64_drm_panthor_vm_bind {
	/** @vm_id: VM targeted by the bind request. */
	__u32 vm_id;

	/** @flags: Combination of drm_panthor_vm_bind_flags flags. */
	__u32 flags;

	/** @ops: Array of struct drm_panthor_vm_bind_op bind operations. */
	struct __c64_drm_panthor_obj_array ops;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_vm_bind(struct drm_panthor_vm_bind *p)
{
	union {
		struct drm_panthor_vm_bind native;
		const struct __c64_drm_panthor_vm_bind compat;
	} *u = (void *)p;

	u->native.ops.array = (user_uintptr_t)compat_ptr(u->compat.ops.array);
	u->native.ops.count = u->compat.ops.count;
	u->native.ops.stride = u->compat.ops.stride;
	u->native.flags = u->compat.flags;
	u->native.vm_id = u->compat.vm_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_vm_bind(struct drm_panthor_vm_bind *p)
{
	union {
		struct __c64_drm_panthor_vm_bind compat;
		const struct drm_panthor_vm_bind native;
	} *u = (void *)p;

	u->compat.vm_id = u->native.vm_id;
	u->compat.flags = u->native.flags;
	u->compat.ops.stride = u->native.ops.stride;
	u->compat.ops.count = u->native.ops.count;
	u->compat.ops.array = (__c64_ptr64 __force)u->native.ops.array;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_vm_bind_2(struct drm_panthor_vm_bind *native, const struct __c64_drm_panthor_vm_bind *compat)
{

	native->vm_id = compat->vm_id;
	native->flags = compat->flags;
	native->ops.stride = compat->ops.stride;
	native->ops.count = compat->ops.count;
	native->ops.array = (user_uintptr_t)compat_ptr(compat->ops.array);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_vm_bind_2(struct __c64_drm_panthor_vm_bind *compat, const struct drm_panthor_vm_bind *native)
{

	compat->vm_id = native->vm_id;
	compat->flags = native->flags;
	compat->ops.stride = native->ops.stride;
	compat->ops.count = native->ops.count;
	compat->ops.array = (__c64_ptr64 __force)native->ops.array;
}
struct __c64_drm_panthor_group_create {
	/** @queues: Array of drm_panthor_queue_create elements. */
	struct __c64_drm_panthor_obj_array queues;

	/**
	 * @max_compute_cores: Maximum number of cores that can be used by compute
	 * jobs across CS queues bound to this group.
	 *
	 * Must be less or equal to the number of bits set in @compute_core_mask.
	 */
	__u8 max_compute_cores;

	/**
	 * @max_fragment_cores: Maximum number of cores that can be used by fragment
	 * jobs across CS queues bound to this group.
	 *
	 * Must be less or equal to the number of bits set in @fragment_core_mask.
	 */
	__u8 max_fragment_cores;

	/**
	 * @max_tiler_cores: Maximum number of tilers that can be used by tiler jobs
	 * across CS queues bound to this group.
	 *
	 * Must be less or equal to the number of bits set in @tiler_core_mask.
	 */
	__u8 max_tiler_cores;

	/** @priority: Group priority (see enum drm_panthor_group_priority). */
	__u8 priority;

	/** @pad: Padding field, MBZ. */
	__u32 pad;

	/**
	 * @compute_core_mask: Mask encoding cores that can be used for compute jobs.
	 *
	 * This field must have at least @max_compute_cores bits set.
	 *
	 * The bits set here should also be set in drm_panthor_gpu_info::shader_present.
	 */
	__u64 compute_core_mask;

	/**
	 * @fragment_core_mask: Mask encoding cores that can be used for fragment jobs.
	 *
	 * This field must have at least @max_fragment_cores bits set.
	 *
	 * The bits set here should also be set in drm_panthor_gpu_info::shader_present.
	 */
	__u64 fragment_core_mask;

	/**
	 * @tiler_core_mask: Mask encoding cores that can be used for tiler jobs.
	 *
	 * This field must have at least @max_tiler_cores bits set.
	 *
	 * The bits set here should also be set in drm_panthor_gpu_info::tiler_present.
	 */
	__u64 tiler_core_mask;

	/**
	 * @vm_id: VM ID to bind this group to.
	 *
	 * All submission to queues bound to this group will use this VM.
	 */
	__u32 vm_id;

	/**
	 * @group_handle: Returned group handle. Passed back when submitting jobs or
	 * destroying a group.
	 */
	__u32 group_handle;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_group_create(struct drm_panthor_group_create *p)
{
	union {
		struct drm_panthor_group_create native;
		const struct __c64_drm_panthor_group_create compat;
	} *u = (void *)p;

	u->native.group_handle = u->compat.group_handle;
	u->native.vm_id = u->compat.vm_id;
	u->native.tiler_core_mask = u->compat.tiler_core_mask;
	u->native.fragment_core_mask = u->compat.fragment_core_mask;
	u->native.compute_core_mask = u->compat.compute_core_mask;
	u->native.pad = u->compat.pad;
	u->native.priority = u->compat.priority;
	u->native.max_tiler_cores = u->compat.max_tiler_cores;
	u->native.max_fragment_cores = u->compat.max_fragment_cores;
	u->native.max_compute_cores = u->compat.max_compute_cores;
	u->native.queues.array = (user_uintptr_t)compat_ptr(u->compat.queues.array);
	u->native.queues.count = u->compat.queues.count;
	u->native.queues.stride = u->compat.queues.stride;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_group_create(struct drm_panthor_group_create *p)
{
	union {
		struct __c64_drm_panthor_group_create compat;
		const struct drm_panthor_group_create native;
	} *u = (void *)p;

	u->compat.queues.stride = u->native.queues.stride;
	u->compat.queues.count = u->native.queues.count;
	u->compat.queues.array = (__c64_ptr64 __force)u->native.queues.array;
	u->compat.max_compute_cores = u->native.max_compute_cores;
	u->compat.max_fragment_cores = u->native.max_fragment_cores;
	u->compat.max_tiler_cores = u->native.max_tiler_cores;
	u->compat.priority = u->native.priority;
	u->compat.pad = u->native.pad;
	u->compat.compute_core_mask = u->native.compute_core_mask;
	u->compat.fragment_core_mask = u->native.fragment_core_mask;
	u->compat.tiler_core_mask = u->native.tiler_core_mask;
	u->compat.vm_id = u->native.vm_id;
	u->compat.group_handle = u->native.group_handle;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_group_create_2(struct drm_panthor_group_create *native, const struct __c64_drm_panthor_group_create *compat)
{

	native->queues.stride = compat->queues.stride;
	native->queues.count = compat->queues.count;
	native->queues.array = (user_uintptr_t)compat_ptr(compat->queues.array);
	native->max_compute_cores = compat->max_compute_cores;
	native->max_fragment_cores = compat->max_fragment_cores;
	native->max_tiler_cores = compat->max_tiler_cores;
	native->priority = compat->priority;
	native->pad = compat->pad;
	native->compute_core_mask = compat->compute_core_mask;
	native->fragment_core_mask = compat->fragment_core_mask;
	native->tiler_core_mask = compat->tiler_core_mask;
	native->vm_id = compat->vm_id;
	native->group_handle = compat->group_handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_group_create_2(struct __c64_drm_panthor_group_create *compat, const struct drm_panthor_group_create *native)
{

	compat->queues.stride = native->queues.stride;
	compat->queues.count = native->queues.count;
	compat->queues.array = (__c64_ptr64 __force)native->queues.array;
	compat->max_compute_cores = native->max_compute_cores;
	compat->max_fragment_cores = native->max_fragment_cores;
	compat->max_tiler_cores = native->max_tiler_cores;
	compat->priority = native->priority;
	compat->pad = native->pad;
	compat->compute_core_mask = native->compute_core_mask;
	compat->fragment_core_mask = native->fragment_core_mask;
	compat->tiler_core_mask = native->tiler_core_mask;
	compat->vm_id = native->vm_id;
	compat->group_handle = native->group_handle;
}
struct __c64_drm_panthor_queue_submit {
	/** @queue_index: Index of the queue inside a group. */
	__u32 queue_index;

	/**
	 * @stream_size: Size of the command stream to execute.
	 *
	 * Must be 64-bit/8-byte aligned (the size of a CS instruction)
	 *
	 * Can be zero if stream_addr is zero too.
	 *
	 * When the stream size is zero, the queue submit serves as a
	 * synchronization point.
	 */
	__u32 stream_size;

	/**
	 * @stream_addr: GPU address of the command stream to execute.
	 *
	 * Must be aligned on 64-byte.
	 *
	 * Can be zero is stream_size is zero too.
	 */
	__u64 stream_addr;

	/**
	 * @latest_flush: FLUSH_ID read at the time the stream was built.
	 *
	 * This allows cache flush elimination for the automatic
	 * flush+invalidate(all) done at submission time, which is needed to
	 * ensure the GPU doesn't get garbage when reading the indirect command
	 * stream buffers. If you want the cache flush to happen
	 * unconditionally, pass a zero here.
	 *
	 * Ignored when stream_size is zero.
	 */
	__u32 latest_flush;

	/** @pad: MBZ. */
	__u32 pad;

	/** @syncs: Array of struct drm_panthor_sync_op sync operations. */
	struct __c64_drm_panthor_obj_array syncs;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_queue_submit(struct drm_panthor_queue_submit *p)
{
	union {
		struct drm_panthor_queue_submit native;
		const struct __c64_drm_panthor_queue_submit compat;
	} *u = (void *)p;

	u->native.syncs.array = (user_uintptr_t)compat_ptr(u->compat.syncs.array);
	u->native.syncs.count = u->compat.syncs.count;
	u->native.syncs.stride = u->compat.syncs.stride;
	u->native.pad = u->compat.pad;
	u->native.latest_flush = u->compat.latest_flush;
	u->native.stream_addr = u->compat.stream_addr;
	u->native.stream_size = u->compat.stream_size;
	u->native.queue_index = u->compat.queue_index;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_queue_submit(struct drm_panthor_queue_submit *p)
{
	union {
		struct __c64_drm_panthor_queue_submit compat;
		const struct drm_panthor_queue_submit native;
	} *u = (void *)p;

	u->compat.queue_index = u->native.queue_index;
	u->compat.stream_size = u->native.stream_size;
	u->compat.stream_addr = u->native.stream_addr;
	u->compat.latest_flush = u->native.latest_flush;
	u->compat.pad = u->native.pad;
	u->compat.syncs.stride = u->native.syncs.stride;
	u->compat.syncs.count = u->native.syncs.count;
	u->compat.syncs.array = (__c64_ptr64 __force)u->native.syncs.array;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_queue_submit_2(struct drm_panthor_queue_submit *native, const struct __c64_drm_panthor_queue_submit *compat)
{

	native->queue_index = compat->queue_index;
	native->stream_size = compat->stream_size;
	native->stream_addr = compat->stream_addr;
	native->latest_flush = compat->latest_flush;
	native->pad = compat->pad;
	native->syncs.stride = compat->syncs.stride;
	native->syncs.count = compat->syncs.count;
	native->syncs.array = (user_uintptr_t)compat_ptr(compat->syncs.array);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_queue_submit_2(struct __c64_drm_panthor_queue_submit *compat, const struct drm_panthor_queue_submit *native)
{

	compat->queue_index = native->queue_index;
	compat->stream_size = native->stream_size;
	compat->stream_addr = native->stream_addr;
	compat->latest_flush = native->latest_flush;
	compat->pad = native->pad;
	compat->syncs.stride = native->syncs.stride;
	compat->syncs.count = native->syncs.count;
	compat->syncs.array = (__c64_ptr64 __force)native->syncs.array;
}
struct __c64_drm_panthor_group_submit {
	/** @group_handle: Handle of the group to queue jobs to. */
	__u32 group_handle;

	/** @pad: MBZ. */
	__u32 pad;

	/** @queue_submits: Array of drm_panthor_queue_submit objects. */
	struct __c64_drm_panthor_obj_array queue_submits;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_group_submit(struct drm_panthor_group_submit *p)
{
	union {
		struct drm_panthor_group_submit native;
		const struct __c64_drm_panthor_group_submit compat;
	} *u = (void *)p;

	u->native.queue_submits.array = (user_uintptr_t)compat_ptr(u->compat.queue_submits.array);
	u->native.queue_submits.count = u->compat.queue_submits.count;
	u->native.queue_submits.stride = u->compat.queue_submits.stride;
	u->native.pad = u->compat.pad;
	u->native.group_handle = u->compat.group_handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_group_submit(struct drm_panthor_group_submit *p)
{
	union {
		struct __c64_drm_panthor_group_submit compat;
		const struct drm_panthor_group_submit native;
	} *u = (void *)p;

	u->compat.group_handle = u->native.group_handle;
	u->compat.pad = u->native.pad;
	u->compat.queue_submits.stride = u->native.queue_submits.stride;
	u->compat.queue_submits.count = u->native.queue_submits.count;
	u->compat.queue_submits.array = (__c64_ptr64 __force)u->native.queue_submits.array;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_group_submit_2(struct drm_panthor_group_submit *native, const struct __c64_drm_panthor_group_submit *compat)
{

	native->group_handle = compat->group_handle;
	native->pad = compat->pad;
	native->queue_submits.stride = compat->queue_submits.stride;
	native->queue_submits.count = compat->queue_submits.count;
	native->queue_submits.array = (user_uintptr_t)compat_ptr(compat->queue_submits.array);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_group_submit_2(struct __c64_drm_panthor_group_submit *compat, const struct drm_panthor_group_submit *native)
{

	compat->group_handle = native->group_handle;
	compat->pad = native->pad;
	compat->queue_submits.stride = native->queue_submits.stride;
	compat->queue_submits.count = native->queue_submits.count;
	compat->queue_submits.array = (__c64_ptr64 __force)native->queue_submits.array;
}
struct __c64_drm_panthor_bo_set_label {
	/** @handle: Handle of the buffer object to label. */
	__u32 handle;

	/**  @pad: MBZ. */
	__u32 pad;

	/**
	 * @label: User pointer to a NUL-terminated string
	 *
	 * Length cannot be greater than 4096
	 */
	__c64_ptr64 label;
};

static __always_inline __maybe_unused void
__from_c64_drm_panthor_bo_set_label(struct drm_panthor_bo_set_label *p)
{
	union {
		struct drm_panthor_bo_set_label native;
		const struct __c64_drm_panthor_bo_set_label compat;
	} *u = (void *)p;

	u->native.label = (user_uintptr_t)compat_ptr(u->compat.label);
	u->native.pad = u->compat.pad;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_bo_set_label(struct drm_panthor_bo_set_label *p)
{
	union {
		struct __c64_drm_panthor_bo_set_label compat;
		const struct drm_panthor_bo_set_label native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat.pad = u->native.pad;
	u->compat.label = (__c64_ptr64 __force)u->native.label;
}
static __always_inline __maybe_unused void
__from_c64_drm_panthor_bo_set_label_2(struct drm_panthor_bo_set_label *native, const struct __c64_drm_panthor_bo_set_label *compat)
{

	native->handle = compat->handle;
	native->pad = compat->pad;
	native->label = (user_uintptr_t)compat_ptr(compat->label);
}
static __always_inline __maybe_unused void
__to_c64_drm_panthor_bo_set_label_2(struct __c64_drm_panthor_bo_set_label *compat, const struct drm_panthor_bo_set_label *native)
{

	compat->handle = native->handle;
	compat->pad = native->pad;
	compat->label = (__c64_ptr64 __force)native->label;
}
