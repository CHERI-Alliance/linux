#pragma once


#include <linux/compat.h>


struct __c64_drm_amdgpu_bo_list_in {
	/** Type of operation */
	__u32 operation;
	/** Handle of list or 0 if we want to create one */
	__u32 list_handle;
	/** Number of BOs in list  */
	__u32 bo_number;
	/** Size of each element describing BO */
	__u32 bo_info_size;
	/** Pointer to array describing BOs */
	__c64_ptr64 bo_info_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_bo_list_in(struct drm_amdgpu_bo_list_in *p)
{
	union {
		struct drm_amdgpu_bo_list_in native;
		const struct __c64_drm_amdgpu_bo_list_in compat;
	} *u = (void *)p;

	u->native.bo_info_ptr = (user_uintptr_t)compat_ptr(u->compat.bo_info_ptr);
	u->native.bo_info_size = u->compat.bo_info_size;
	u->native.bo_number = u->compat.bo_number;
	u->native.list_handle = u->compat.list_handle;
	u->native.operation = u->compat.operation;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_bo_list_in(struct drm_amdgpu_bo_list_in *p)
{
	union {
		struct __c64_drm_amdgpu_bo_list_in compat;
		const struct drm_amdgpu_bo_list_in native;
	} *u = (void *)p;

	u->compat.operation = u->native.operation;
	u->compat.list_handle = u->native.list_handle;
	u->compat.bo_number = u->native.bo_number;
	u->compat.bo_info_size = u->native.bo_info_size;
	u->compat.bo_info_ptr = (__c64_ptr64 __force)u->native.bo_info_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_bo_list_in_2(struct drm_amdgpu_bo_list_in *native, const struct __c64_drm_amdgpu_bo_list_in *compat)
{

	native->operation = compat->operation;
	native->list_handle = compat->list_handle;
	native->bo_number = compat->bo_number;
	native->bo_info_size = compat->bo_info_size;
	native->bo_info_ptr = (user_uintptr_t)compat_ptr(compat->bo_info_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_bo_list_in_2(struct __c64_drm_amdgpu_bo_list_in *compat, const struct drm_amdgpu_bo_list_in *native)
{

	compat->operation = native->operation;
	compat->list_handle = native->list_handle;
	compat->bo_number = native->bo_number;
	compat->bo_info_size = native->bo_info_size;
	compat->bo_info_ptr = (__c64_ptr64 __force)native->bo_info_ptr;
}
union __c64_drm_amdgpu_bo_list {
	struct __c64_drm_amdgpu_bo_list_in in;
	struct drm_amdgpu_bo_list_out out;
};

struct __c64_drm_amdgpu_userq_in {
	/** AMDGPU_USERQ_OP_* */
	__u32	op;
	/** Queue id passed for operation USERQ_OP_FREE */
	__u32	queue_id;
	/** the target GPU engine to execute workload (AMDGPU_HW_IP_*) */
	__u32   ip_type;
	/**
	 * @doorbell_handle: the handle of doorbell GEM object
	 * associated with this userqueue client.
	 */
	__u32   doorbell_handle;
	/**
	 * @doorbell_offset: 32-bit offset of the doorbell in the doorbell bo.
	 * Kernel will generate absolute doorbell offset using doorbell_handle
	 * and doorbell_offset in the doorbell bo.
	 */
	__u32   doorbell_offset;
	/**
	 * @flags: flags used for queue parameters
	 */
	__u32 flags;
	/**
	 * @queue_va: Virtual address of the GPU memory which holds the queue
	 * object. The queue holds the workload packets.
	 */
	__u64   queue_va;
	/**
	 * @queue_size: Size of the queue in bytes, this needs to be 256-byte
	 * aligned.
	 */
	__u64   queue_size;
	/**
	 * @rptr_va : Virtual address of the GPU memory which holds the ring RPTR.
	 * This object must be at least 8 byte in size and aligned to 8-byte offset.
	 */
	__u64   rptr_va;
	/**
	 * @wptr_va : Virtual address of the GPU memory which holds the ring WPTR.
	 * This object must be at least 8 byte in size and aligned to 8-byte offset.
	 *
	 * Queue, RPTR and WPTR can come from the same object, as long as the size
	 * and alignment related requirements are met.
	 */
	__u64   wptr_va;
	/**
	 * @mqd: MQD (memory queue descriptor) is a set of parameters which allow
	 * the GPU to uniquely define and identify a usermode queue.
	 *
	 * MQD data can be of different size for different GPU IP/engine and
	 * their respective versions/revisions, so this points to a __u64 *
	 * which holds IP specific MQD of this usermode queue.
	 */
	__c64_ptr64 mqd;
	/**
	 * @size: size of MQD data in bytes, it must match the MQD structure
	 * size of the respective engine/revision defined in UAPI for ex, for
	 * gfx11 workloads, size = sizeof(drm_amdgpu_userq_mqd_gfx11).
	 */
	__u64 mqd_size;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_in(struct drm_amdgpu_userq_in *p)
{
	union {
		struct drm_amdgpu_userq_in native;
		const struct __c64_drm_amdgpu_userq_in compat;
	} *u = (void *)p;

	u->native.mqd_size = u->compat.mqd_size;
	u->native.mqd = (user_uintptr_t)compat_ptr(u->compat.mqd);
	u->native.wptr_va = u->compat.wptr_va;
	u->native.rptr_va = u->compat.rptr_va;
	u->native.queue_size = u->compat.queue_size;
	u->native.queue_va = u->compat.queue_va;
	u->native.flags = u->compat.flags;
	u->native.doorbell_offset = u->compat.doorbell_offset;
	u->native.doorbell_handle = u->compat.doorbell_handle;
	u->native.ip_type = u->compat.ip_type;
	u->native.queue_id = u->compat.queue_id;
	u->native.op = u->compat.op;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_in(struct drm_amdgpu_userq_in *p)
{
	union {
		struct __c64_drm_amdgpu_userq_in compat;
		const struct drm_amdgpu_userq_in native;
	} *u = (void *)p;

	u->compat.op = u->native.op;
	u->compat.queue_id = u->native.queue_id;
	u->compat.ip_type = u->native.ip_type;
	u->compat.doorbell_handle = u->native.doorbell_handle;
	u->compat.doorbell_offset = u->native.doorbell_offset;
	u->compat.flags = u->native.flags;
	u->compat.queue_va = u->native.queue_va;
	u->compat.queue_size = u->native.queue_size;
	u->compat.rptr_va = u->native.rptr_va;
	u->compat.wptr_va = u->native.wptr_va;
	u->compat.mqd = (__c64_ptr64 __force)u->native.mqd;
	u->compat.mqd_size = u->native.mqd_size;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_in_2(struct drm_amdgpu_userq_in *native, const struct __c64_drm_amdgpu_userq_in *compat)
{

	native->op = compat->op;
	native->queue_id = compat->queue_id;
	native->ip_type = compat->ip_type;
	native->doorbell_handle = compat->doorbell_handle;
	native->doorbell_offset = compat->doorbell_offset;
	native->flags = compat->flags;
	native->queue_va = compat->queue_va;
	native->queue_size = compat->queue_size;
	native->rptr_va = compat->rptr_va;
	native->wptr_va = compat->wptr_va;
	native->mqd = (user_uintptr_t)compat_ptr(compat->mqd);
	native->mqd_size = compat->mqd_size;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_in_2(struct __c64_drm_amdgpu_userq_in *compat, const struct drm_amdgpu_userq_in *native)
{

	compat->op = native->op;
	compat->queue_id = native->queue_id;
	compat->ip_type = native->ip_type;
	compat->doorbell_handle = native->doorbell_handle;
	compat->doorbell_offset = native->doorbell_offset;
	compat->flags = native->flags;
	compat->queue_va = native->queue_va;
	compat->queue_size = native->queue_size;
	compat->rptr_va = native->rptr_va;
	compat->wptr_va = native->wptr_va;
	compat->mqd = (__c64_ptr64 __force)native->mqd;
	compat->mqd_size = native->mqd_size;
}
union __c64_drm_amdgpu_userq {
	struct __c64_drm_amdgpu_userq_in in;
	struct drm_amdgpu_userq_out out;
};

struct __c64_drm_amdgpu_userq_signal {
	/**
	 * @queue_id: Queue handle used by the userq fence creation function
	 * to retrieve the WPTR.
	 */
	__u32	queue_id;
	__u32	pad;
	/**
	 * @syncobj_handles: The list of syncobj handles submitted by the user queue
	 * job to be signaled.
	 */
	__c64_ptr64	syncobj_handles;
	/**
	 * @num_syncobj_handles: A count that represents the number of syncobj handles in
	 * @syncobj_handles.
	 */
	__u64	num_syncobj_handles;
	/**
	 * @bo_read_handles: The list of BO handles that the submitted user queue job
	 * is using for read only. This will update BO fences in the kernel.
	 */
	__c64_ptr64	bo_read_handles;
	/**
	 * @bo_write_handles: The list of BO handles that the submitted user queue job
	 * is using for write only. This will update BO fences in the kernel.
	 */
	__c64_ptr64	bo_write_handles;
	/**
	 * @num_bo_read_handles: A count that represents the number of read BO handles in
	 * @bo_read_handles.
	 */
	__u32	num_bo_read_handles;
	/**
	 * @num_bo_write_handles: A count that represents the number of write BO handles in
	 * @bo_write_handles.
	 */
	__u32	num_bo_write_handles;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_signal(struct drm_amdgpu_userq_signal *p)
{
	union {
		struct drm_amdgpu_userq_signal native;
		const struct __c64_drm_amdgpu_userq_signal compat;
	} *u = (void *)p;

	u->native.num_bo_write_handles = u->compat.num_bo_write_handles;
	u->native.num_bo_read_handles = u->compat.num_bo_read_handles;
	u->native.bo_write_handles = (user_uintptr_t)compat_ptr(u->compat.bo_write_handles);
	u->native.bo_read_handles = (user_uintptr_t)compat_ptr(u->compat.bo_read_handles);
	u->native.num_syncobj_handles = u->compat.num_syncobj_handles;
	u->native.syncobj_handles = (user_uintptr_t)compat_ptr(u->compat.syncobj_handles);
	u->native.pad = u->compat.pad;
	u->native.queue_id = u->compat.queue_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_signal(struct drm_amdgpu_userq_signal *p)
{
	union {
		struct __c64_drm_amdgpu_userq_signal compat;
		const struct drm_amdgpu_userq_signal native;
	} *u = (void *)p;

	u->compat.queue_id = u->native.queue_id;
	u->compat.pad = u->native.pad;
	u->compat.syncobj_handles = (__c64_ptr64 __force)u->native.syncobj_handles;
	u->compat.num_syncobj_handles = u->native.num_syncobj_handles;
	u->compat.bo_read_handles = (__c64_ptr64 __force)u->native.bo_read_handles;
	u->compat.bo_write_handles = (__c64_ptr64 __force)u->native.bo_write_handles;
	u->compat.num_bo_read_handles = u->native.num_bo_read_handles;
	u->compat.num_bo_write_handles = u->native.num_bo_write_handles;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_signal_2(struct drm_amdgpu_userq_signal *native, const struct __c64_drm_amdgpu_userq_signal *compat)
{

	native->queue_id = compat->queue_id;
	native->pad = compat->pad;
	native->syncobj_handles = (user_uintptr_t)compat_ptr(compat->syncobj_handles);
	native->num_syncobj_handles = compat->num_syncobj_handles;
	native->bo_read_handles = (user_uintptr_t)compat_ptr(compat->bo_read_handles);
	native->bo_write_handles = (user_uintptr_t)compat_ptr(compat->bo_write_handles);
	native->num_bo_read_handles = compat->num_bo_read_handles;
	native->num_bo_write_handles = compat->num_bo_write_handles;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_signal_2(struct __c64_drm_amdgpu_userq_signal *compat, const struct drm_amdgpu_userq_signal *native)
{

	compat->queue_id = native->queue_id;
	compat->pad = native->pad;
	compat->syncobj_handles = (__c64_ptr64 __force)native->syncobj_handles;
	compat->num_syncobj_handles = native->num_syncobj_handles;
	compat->bo_read_handles = (__c64_ptr64 __force)native->bo_read_handles;
	compat->bo_write_handles = (__c64_ptr64 __force)native->bo_write_handles;
	compat->num_bo_read_handles = native->num_bo_read_handles;
	compat->num_bo_write_handles = native->num_bo_write_handles;
}
struct __c64_drm_amdgpu_userq_wait {
	/**
	 * @waitq_id: Queue handle used by the userq wait IOCTL to retrieve the
	 * wait queue and maintain the fence driver references in it.
	 */
	__u32	waitq_id;
	__u32	pad;
	/**
	 * @syncobj_handles: The list of syncobj handles submitted by the user queue
	 * job to get the va/value pairs.
	 */
	__c64_ptr64	syncobj_handles;
	/**
	 * @syncobj_timeline_handles: The list of timeline syncobj handles submitted by
	 * the user queue job to get the va/value pairs at given @syncobj_timeline_points.
	 */
	__c64_ptr64	syncobj_timeline_handles;
	/**
	 * @syncobj_timeline_points: The list of timeline syncobj points submitted by the
	 * user queue job for the corresponding @syncobj_timeline_handles.
	 */
	__c64_ptr64	syncobj_timeline_points;
	/**
	 * @bo_read_handles: The list of read BO handles submitted by the user queue
	 * job to get the va/value pairs.
	 */
	__c64_ptr64	bo_read_handles;
	/**
	 * @bo_write_handles: The list of write BO handles submitted by the user queue
	 * job to get the va/value pairs.
	 */
	__c64_ptr64	bo_write_handles;
	/**
	 * @num_syncobj_timeline_handles: A count that represents the number of timeline
	 * syncobj handles in @syncobj_timeline_handles.
	 */
	__u16	num_syncobj_timeline_handles;
	/**
	 * @num_fences: This field can be used both as input and output. As input it defines
	 * the maximum number of fences that can be returned and as output it will specify
	 * how many fences were actually returned from the ioctl.
	 */
	__u16	num_fences;
	/**
	 * @num_syncobj_handles: A count that represents the number of syncobj handles in
	 * @syncobj_handles.
	 */
	__u32	num_syncobj_handles;
	/**
	 * @num_bo_read_handles: A count that represents the number of read BO handles in
	 * @bo_read_handles.
	 */
	__u32	num_bo_read_handles;
	/**
	 * @num_bo_write_handles: A count that represents the number of write BO handles in
	 * @bo_write_handles.
	 */
	__u32	num_bo_write_handles;
	/**
	 * @out_fences: The field is a return value from the ioctl containing the list of
	 * address/value pairs to wait for.
	 */
	__c64_ptr64	out_fences;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_wait(struct drm_amdgpu_userq_wait *p)
{
	union {
		struct drm_amdgpu_userq_wait native;
		const struct __c64_drm_amdgpu_userq_wait compat;
	} *u = (void *)p;

	u->native.out_fences = (user_uintptr_t)compat_ptr(u->compat.out_fences);
	u->native.num_bo_write_handles = u->compat.num_bo_write_handles;
	u->native.num_bo_read_handles = u->compat.num_bo_read_handles;
	u->native.num_syncobj_handles = u->compat.num_syncobj_handles;
	u->native.num_fences = u->compat.num_fences;
	u->native.num_syncobj_timeline_handles = u->compat.num_syncobj_timeline_handles;
	u->native.bo_write_handles = (user_uintptr_t)compat_ptr(u->compat.bo_write_handles);
	u->native.bo_read_handles = (user_uintptr_t)compat_ptr(u->compat.bo_read_handles);
	u->native.syncobj_timeline_points = (user_uintptr_t)compat_ptr(u->compat.syncobj_timeline_points);
	u->native.syncobj_timeline_handles = (user_uintptr_t)compat_ptr(u->compat.syncobj_timeline_handles);
	u->native.syncobj_handles = (user_uintptr_t)compat_ptr(u->compat.syncobj_handles);
	u->native.pad = u->compat.pad;
	u->native.waitq_id = u->compat.waitq_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_wait(struct drm_amdgpu_userq_wait *p)
{
	union {
		struct __c64_drm_amdgpu_userq_wait compat;
		const struct drm_amdgpu_userq_wait native;
	} *u = (void *)p;

	u->compat.waitq_id = u->native.waitq_id;
	u->compat.pad = u->native.pad;
	u->compat.syncobj_handles = (__c64_ptr64 __force)u->native.syncobj_handles;
	u->compat.syncobj_timeline_handles = (__c64_ptr64 __force)u->native.syncobj_timeline_handles;
	u->compat.syncobj_timeline_points = (__c64_ptr64 __force)u->native.syncobj_timeline_points;
	u->compat.bo_read_handles = (__c64_ptr64 __force)u->native.bo_read_handles;
	u->compat.bo_write_handles = (__c64_ptr64 __force)u->native.bo_write_handles;
	u->compat.num_syncobj_timeline_handles = u->native.num_syncobj_timeline_handles;
	u->compat.num_fences = u->native.num_fences;
	u->compat.num_syncobj_handles = u->native.num_syncobj_handles;
	u->compat.num_bo_read_handles = u->native.num_bo_read_handles;
	u->compat.num_bo_write_handles = u->native.num_bo_write_handles;
	u->compat.out_fences = (__c64_ptr64 __force)u->native.out_fences;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_userq_wait_2(struct drm_amdgpu_userq_wait *native, const struct __c64_drm_amdgpu_userq_wait *compat)
{

	native->waitq_id = compat->waitq_id;
	native->pad = compat->pad;
	native->syncobj_handles = (user_uintptr_t)compat_ptr(compat->syncobj_handles);
	native->syncobj_timeline_handles = (user_uintptr_t)compat_ptr(compat->syncobj_timeline_handles);
	native->syncobj_timeline_points = (user_uintptr_t)compat_ptr(compat->syncobj_timeline_points);
	native->bo_read_handles = (user_uintptr_t)compat_ptr(compat->bo_read_handles);
	native->bo_write_handles = (user_uintptr_t)compat_ptr(compat->bo_write_handles);
	native->num_syncobj_timeline_handles = compat->num_syncobj_timeline_handles;
	native->num_fences = compat->num_fences;
	native->num_syncobj_handles = compat->num_syncobj_handles;
	native->num_bo_read_handles = compat->num_bo_read_handles;
	native->num_bo_write_handles = compat->num_bo_write_handles;
	native->out_fences = (user_uintptr_t)compat_ptr(compat->out_fences);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_userq_wait_2(struct __c64_drm_amdgpu_userq_wait *compat, const struct drm_amdgpu_userq_wait *native)
{

	compat->waitq_id = native->waitq_id;
	compat->pad = native->pad;
	compat->syncobj_handles = (__c64_ptr64 __force)native->syncobj_handles;
	compat->syncobj_timeline_handles = (__c64_ptr64 __force)native->syncobj_timeline_handles;
	compat->syncobj_timeline_points = (__c64_ptr64 __force)native->syncobj_timeline_points;
	compat->bo_read_handles = (__c64_ptr64 __force)native->bo_read_handles;
	compat->bo_write_handles = (__c64_ptr64 __force)native->bo_write_handles;
	compat->num_syncobj_timeline_handles = native->num_syncobj_timeline_handles;
	compat->num_fences = native->num_fences;
	compat->num_syncobj_handles = native->num_syncobj_handles;
	compat->num_bo_read_handles = native->num_bo_read_handles;
	compat->num_bo_write_handles = native->num_bo_write_handles;
	compat->out_fences = (__c64_ptr64 __force)native->out_fences;
}
struct __c64_drm_amdgpu_wait_fences_in {
	/** This points to uint64_t * which points to fences */
	__c64_ptr64 fences;
	__u32 fence_count;
	__u32 wait_all;
	__u64 timeout_ns;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_wait_fences_in(struct drm_amdgpu_wait_fences_in *p)
{
	union {
		struct drm_amdgpu_wait_fences_in native;
		const struct __c64_drm_amdgpu_wait_fences_in compat;
	} *u = (void *)p;

	u->native.timeout_ns = u->compat.timeout_ns;
	u->native.wait_all = u->compat.wait_all;
	u->native.fence_count = u->compat.fence_count;
	u->native.fences = (user_uintptr_t)compat_ptr(u->compat.fences);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_wait_fences_in(struct drm_amdgpu_wait_fences_in *p)
{
	union {
		struct __c64_drm_amdgpu_wait_fences_in compat;
		const struct drm_amdgpu_wait_fences_in native;
	} *u = (void *)p;

	u->compat.fences = (__c64_ptr64 __force)u->native.fences;
	u->compat.fence_count = u->native.fence_count;
	u->compat.wait_all = u->native.wait_all;
	u->compat.timeout_ns = u->native.timeout_ns;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_wait_fences_in_2(struct drm_amdgpu_wait_fences_in *native, const struct __c64_drm_amdgpu_wait_fences_in *compat)
{

	native->fences = (user_uintptr_t)compat_ptr(compat->fences);
	native->fence_count = compat->fence_count;
	native->wait_all = compat->wait_all;
	native->timeout_ns = compat->timeout_ns;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_wait_fences_in_2(struct __c64_drm_amdgpu_wait_fences_in *compat, const struct drm_amdgpu_wait_fences_in *native)
{

	compat->fences = (__c64_ptr64 __force)native->fences;
	compat->fence_count = native->fence_count;
	compat->wait_all = native->wait_all;
	compat->timeout_ns = native->timeout_ns;
}
union __c64_drm_amdgpu_wait_fences {
	struct __c64_drm_amdgpu_wait_fences_in in;
	struct drm_amdgpu_wait_fences_out out;
};

struct __c64_drm_amdgpu_gem_op {
	/** GEM object handle */
	__u32	handle;
	/** AMDGPU_GEM_OP_* */
	__u32	op;
	/** Input or return value */
	__c64_ptr64	value;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_gem_op(struct drm_amdgpu_gem_op *p)
{
	union {
		struct drm_amdgpu_gem_op native;
		const struct __c64_drm_amdgpu_gem_op compat;
	} *u = (void *)p;

	u->native.value = (user_uintptr_t)compat_ptr(u->compat.value);
	u->native.op = u->compat.op;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_gem_op(struct drm_amdgpu_gem_op *p)
{
	union {
		struct __c64_drm_amdgpu_gem_op compat;
		const struct drm_amdgpu_gem_op native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat.op = u->native.op;
	u->compat.value = (__c64_ptr64 __force)u->native.value;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_gem_op_2(struct drm_amdgpu_gem_op *native, const struct __c64_drm_amdgpu_gem_op *compat)
{

	native->handle = compat->handle;
	native->op = compat->op;
	native->value = (user_uintptr_t)compat_ptr(compat->value);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_gem_op_2(struct __c64_drm_amdgpu_gem_op *compat, const struct drm_amdgpu_gem_op *native)
{

	compat->handle = native->handle;
	compat->op = native->op;
	compat->value = (__c64_ptr64 __force)native->value;
}
struct __c64_drm_amdgpu_gem_va {
	/** GEM object handle */
	__u32 handle;
	__u32 _pad;
	/** AMDGPU_VA_OP_* */
	__u32 operation;
	/** AMDGPU_VM_PAGE_* */
	__u32 flags;
	/** va address to assign . Must be correctly aligned.*/
	__u64 va_address;
	/** Specify offset inside of BO to assign. Must be correctly aligned.*/
	__u64 offset_in_bo;
	/** Specify mapping size. Must be correctly aligned. */
	__u64 map_size;
	/**
	 * vm_timeline_point is a sequence number used to add new timeline point.
	 */
	__u64 vm_timeline_point;
	/**
	 * The vm page table update fence is installed in given vm_timeline_syncobj_out
	 * at vm_timeline_point.
	 */
	__u32 vm_timeline_syncobj_out;
	/** the number of syncobj handles in @input_fence_syncobj_handles */
	__u32 num_syncobj_handles;
	/** Array of sync object handle to wait for given input fences */
	__c64_ptr64 input_fence_syncobj_handles;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_gem_va(struct drm_amdgpu_gem_va *p)
{
	union {
		struct drm_amdgpu_gem_va native;
		const struct __c64_drm_amdgpu_gem_va compat;
	} *u = (void *)p;

	u->native.input_fence_syncobj_handles = (user_uintptr_t)compat_ptr(u->compat.input_fence_syncobj_handles);
	u->native.num_syncobj_handles = u->compat.num_syncobj_handles;
	u->native.vm_timeline_syncobj_out = u->compat.vm_timeline_syncobj_out;
	u->native.vm_timeline_point = u->compat.vm_timeline_point;
	u->native.map_size = u->compat.map_size;
	u->native.offset_in_bo = u->compat.offset_in_bo;
	u->native.va_address = u->compat.va_address;
	u->native.flags = u->compat.flags;
	u->native.operation = u->compat.operation;
	u->native._pad = u->compat._pad;
	u->native.handle = u->compat.handle;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_gem_va(struct drm_amdgpu_gem_va *p)
{
	union {
		struct __c64_drm_amdgpu_gem_va compat;
		const struct drm_amdgpu_gem_va native;
	} *u = (void *)p;

	u->compat.handle = u->native.handle;
	u->compat._pad = u->native._pad;
	u->compat.operation = u->native.operation;
	u->compat.flags = u->native.flags;
	u->compat.va_address = u->native.va_address;
	u->compat.offset_in_bo = u->native.offset_in_bo;
	u->compat.map_size = u->native.map_size;
	u->compat.vm_timeline_point = u->native.vm_timeline_point;
	u->compat.vm_timeline_syncobj_out = u->native.vm_timeline_syncobj_out;
	u->compat.num_syncobj_handles = u->native.num_syncobj_handles;
	u->compat.input_fence_syncobj_handles = (__c64_ptr64 __force)u->native.input_fence_syncobj_handles;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_gem_va_2(struct drm_amdgpu_gem_va *native, const struct __c64_drm_amdgpu_gem_va *compat)
{

	native->handle = compat->handle;
	native->_pad = compat->_pad;
	native->operation = compat->operation;
	native->flags = compat->flags;
	native->va_address = compat->va_address;
	native->offset_in_bo = compat->offset_in_bo;
	native->map_size = compat->map_size;
	native->vm_timeline_point = compat->vm_timeline_point;
	native->vm_timeline_syncobj_out = compat->vm_timeline_syncobj_out;
	native->num_syncobj_handles = compat->num_syncobj_handles;
	native->input_fence_syncobj_handles = (user_uintptr_t)compat_ptr(compat->input_fence_syncobj_handles);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_gem_va_2(struct __c64_drm_amdgpu_gem_va *compat, const struct drm_amdgpu_gem_va *native)
{

	compat->handle = native->handle;
	compat->_pad = native->_pad;
	compat->operation = native->operation;
	compat->flags = native->flags;
	compat->va_address = native->va_address;
	compat->offset_in_bo = native->offset_in_bo;
	compat->map_size = native->map_size;
	compat->vm_timeline_point = native->vm_timeline_point;
	compat->vm_timeline_syncobj_out = native->vm_timeline_syncobj_out;
	compat->num_syncobj_handles = native->num_syncobj_handles;
	compat->input_fence_syncobj_handles = (__c64_ptr64 __force)native->input_fence_syncobj_handles;
}
struct __c64_drm_amdgpu_cs_chunk {
	__u32		chunk_id;
	__u32		length_dw;
	__c64_ptr64	chunk_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_cs_chunk(struct drm_amdgpu_cs_chunk *p)
{
	union {
		struct drm_amdgpu_cs_chunk native;
		const struct __c64_drm_amdgpu_cs_chunk compat;
	} *u = (void *)p;

	u->native.chunk_data = (user_uintptr_t)compat_ptr(u->compat.chunk_data);
	u->native.length_dw = u->compat.length_dw;
	u->native.chunk_id = u->compat.chunk_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_cs_chunk(struct drm_amdgpu_cs_chunk *p)
{
	union {
		struct __c64_drm_amdgpu_cs_chunk compat;
		const struct drm_amdgpu_cs_chunk native;
	} *u = (void *)p;

	u->compat.chunk_id = u->native.chunk_id;
	u->compat.length_dw = u->native.length_dw;
	u->compat.chunk_data = (__c64_ptr64 __force)u->native.chunk_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_cs_chunk_2(struct drm_amdgpu_cs_chunk *native, const struct __c64_drm_amdgpu_cs_chunk *compat)
{

	native->chunk_id = compat->chunk_id;
	native->length_dw = compat->length_dw;
	native->chunk_data = (user_uintptr_t)compat_ptr(compat->chunk_data);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_cs_chunk_2(struct __c64_drm_amdgpu_cs_chunk *compat, const struct drm_amdgpu_cs_chunk *native)
{

	compat->chunk_id = native->chunk_id;
	compat->length_dw = native->length_dw;
	compat->chunk_data = (__c64_ptr64 __force)native->chunk_data;
}
struct __c64_drm_amdgpu_cs_in {
	/** Rendering context id */
	__u32		ctx_id;
	/**  Handle of resource list associated with CS */
	__u32		bo_list_handle;
	__u32		num_chunks;
	__u32		flags;
	/** this points to __u64 * which point to cs chunks */
	__c64_ptr64	chunks;
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_cs_in(struct drm_amdgpu_cs_in *p)
{
	union {
		struct drm_amdgpu_cs_in native;
		const struct __c64_drm_amdgpu_cs_in compat;
	} *u = (void *)p;

	u->native.chunks = (user_uintptr_t)compat_ptr(u->compat.chunks);
	u->native.flags = u->compat.flags;
	u->native.num_chunks = u->compat.num_chunks;
	u->native.bo_list_handle = u->compat.bo_list_handle;
	u->native.ctx_id = u->compat.ctx_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_cs_in(struct drm_amdgpu_cs_in *p)
{
	union {
		struct __c64_drm_amdgpu_cs_in compat;
		const struct drm_amdgpu_cs_in native;
	} *u = (void *)p;

	u->compat.ctx_id = u->native.ctx_id;
	u->compat.bo_list_handle = u->native.bo_list_handle;
	u->compat.num_chunks = u->native.num_chunks;
	u->compat.flags = u->native.flags;
	u->compat.chunks = (__c64_ptr64 __force)u->native.chunks;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_cs_in_2(struct drm_amdgpu_cs_in *native, const struct __c64_drm_amdgpu_cs_in *compat)
{

	native->ctx_id = compat->ctx_id;
	native->bo_list_handle = compat->bo_list_handle;
	native->num_chunks = compat->num_chunks;
	native->flags = compat->flags;
	native->chunks = (user_uintptr_t)compat_ptr(compat->chunks);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_cs_in_2(struct __c64_drm_amdgpu_cs_in *compat, const struct drm_amdgpu_cs_in *native)
{

	compat->ctx_id = native->ctx_id;
	compat->bo_list_handle = native->bo_list_handle;
	compat->num_chunks = native->num_chunks;
	compat->flags = native->flags;
	compat->chunks = (__c64_ptr64 __force)native->chunks;
}
union __c64_drm_amdgpu_cs {
	struct __c64_drm_amdgpu_cs_in in;
	struct drm_amdgpu_cs_out out;
};

struct __c64_drm_amdgpu_info {
	/* Where the return value will be stored */
	__c64_ptr64 return_pointer;
	/* The size of the return value. Just like "size" in "snprintf",
	 * it limits how many bytes the kernel can write. */
	__u32 return_size;
	/* The query request id. */
	__u32 query;

	union {
		struct {
			__u32 id;
			__u32 _pad;
		} mode_crtc;

		struct {
			/** AMDGPU_HW_IP_* */
			__u32 type;
			/**
			 * Index of the IP if there are more IPs of the same
			 * type. Ignored by AMDGPU_INFO_HW_IP_COUNT.
			 */
			__u32 ip_instance;
		} query_hw_ip;

		struct {
			__u32 dword_offset;
			/** number of registers to read */
			__u32 count;
			__u32 instance;
			/** For future use, no flags defined so far */
			__u32 flags;
		} read_mmr_reg;

		struct drm_amdgpu_query_fw query_fw;

		struct {
			__u32 type;
			__u32 offset;
		} vbios_info;

		struct {
			__u32 type;
		} sensor_info;

		struct {
			__u32 type;
		} video_cap;
	};
};

static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_info(struct drm_amdgpu_info *p)
{
	union {
		struct drm_amdgpu_info native;
		const struct __c64_drm_amdgpu_info compat;
	} *u = (void *)p;

	u->native.video_cap.type = u->compat.video_cap.type;
	u->native.sensor_info.type = u->compat.sensor_info.type;
	u->native.vbios_info.offset = u->compat.vbios_info.offset;
	u->native.vbios_info.type = u->compat.vbios_info.type;
	BUILD_BUG_ON(sizeof(u->compat.query_fw) != sizeof(u->native.query_fw));
	memmove(&u->native.query_fw, &u->compat.query_fw, sizeof(u->native.query_fw));
	u->native.read_mmr_reg.flags = u->compat.read_mmr_reg.flags;
	u->native.read_mmr_reg.instance = u->compat.read_mmr_reg.instance;
	u->native.read_mmr_reg.count = u->compat.read_mmr_reg.count;
	u->native.read_mmr_reg.dword_offset = u->compat.read_mmr_reg.dword_offset;
	u->native.query_hw_ip.ip_instance = u->compat.query_hw_ip.ip_instance;
	u->native.query_hw_ip.type = u->compat.query_hw_ip.type;
	u->native.mode_crtc._pad = u->compat.mode_crtc._pad;
	u->native.mode_crtc.id = u->compat.mode_crtc.id;
	u->native.query = u->compat.query;
	u->native.return_size = u->compat.return_size;
	u->native.return_pointer = (user_uintptr_t)compat_ptr(u->compat.return_pointer);
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_info(struct drm_amdgpu_info *p)
{
	union {
		struct __c64_drm_amdgpu_info compat;
		const struct drm_amdgpu_info native;
	} *u = (void *)p;

	u->compat.return_pointer = (__c64_ptr64 __force)u->native.return_pointer;
	u->compat.return_size = u->native.return_size;
	u->compat.query = u->native.query;
	u->compat.mode_crtc.id = u->native.mode_crtc.id;
	u->compat.mode_crtc._pad = u->native.mode_crtc._pad;
	u->compat.query_hw_ip.type = u->native.query_hw_ip.type;
	u->compat.query_hw_ip.ip_instance = u->native.query_hw_ip.ip_instance;
	u->compat.read_mmr_reg.dword_offset = u->native.read_mmr_reg.dword_offset;
	u->compat.read_mmr_reg.count = u->native.read_mmr_reg.count;
	u->compat.read_mmr_reg.instance = u->native.read_mmr_reg.instance;
	u->compat.read_mmr_reg.flags = u->native.read_mmr_reg.flags;
	BUILD_BUG_ON(sizeof(u->native.query_fw) != sizeof(u->compat.query_fw));
	memmove(&u->compat.query_fw, &u->native.query_fw, sizeof(u->compat.query_fw));
	u->compat.vbios_info.type = u->native.vbios_info.type;
	u->compat.vbios_info.offset = u->native.vbios_info.offset;
	u->compat.sensor_info.type = u->native.sensor_info.type;
	u->compat.video_cap.type = u->native.video_cap.type;
}
static __always_inline __maybe_unused void
__from_c64_drm_amdgpu_info_2(struct drm_amdgpu_info *native, const struct __c64_drm_amdgpu_info *compat)
{

	native->return_pointer = (user_uintptr_t)compat_ptr(compat->return_pointer);
	native->return_size = compat->return_size;
	native->query = compat->query;
	native->mode_crtc.id = compat->mode_crtc.id;
	native->mode_crtc._pad = compat->mode_crtc._pad;
	native->query_hw_ip.type = compat->query_hw_ip.type;
	native->query_hw_ip.ip_instance = compat->query_hw_ip.ip_instance;
	native->read_mmr_reg.dword_offset = compat->read_mmr_reg.dword_offset;
	native->read_mmr_reg.count = compat->read_mmr_reg.count;
	native->read_mmr_reg.instance = compat->read_mmr_reg.instance;
	native->read_mmr_reg.flags = compat->read_mmr_reg.flags;
	BUILD_BUG_ON(sizeof(compat->query_fw) != sizeof(native->query_fw));
	memcpy(&native->query_fw, &compat->query_fw, sizeof(native->query_fw));
	native->vbios_info.type = compat->vbios_info.type;
	native->vbios_info.offset = compat->vbios_info.offset;
	native->sensor_info.type = compat->sensor_info.type;
	native->video_cap.type = compat->video_cap.type;
}
static __always_inline __maybe_unused void
__to_c64_drm_amdgpu_info_2(struct __c64_drm_amdgpu_info *compat, const struct drm_amdgpu_info *native)
{

	compat->return_pointer = (__c64_ptr64 __force)native->return_pointer;
	compat->return_size = native->return_size;
	compat->query = native->query;
	compat->mode_crtc.id = native->mode_crtc.id;
	compat->mode_crtc._pad = native->mode_crtc._pad;
	compat->query_hw_ip.type = native->query_hw_ip.type;
	compat->query_hw_ip.ip_instance = native->query_hw_ip.ip_instance;
	compat->read_mmr_reg.dword_offset = native->read_mmr_reg.dword_offset;
	compat->read_mmr_reg.count = native->read_mmr_reg.count;
	compat->read_mmr_reg.instance = native->read_mmr_reg.instance;
	compat->read_mmr_reg.flags = native->read_mmr_reg.flags;
	BUILD_BUG_ON(sizeof(native->query_fw) != sizeof(compat->query_fw));
	memcpy(&compat->query_fw, &native->query_fw, sizeof(compat->query_fw));
	compat->vbios_info.type = native->vbios_info.type;
	compat->vbios_info.offset = native->vbios_info.offset;
	compat->sensor_info.type = native->sensor_info.type;
	compat->video_cap.type = native->video_cap.type;
}
