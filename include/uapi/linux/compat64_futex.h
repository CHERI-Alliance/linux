#pragma once


#include <linux/compat.h>


struct __c64_futex_waitv {
	__u64 val;
	__c64_ptr64 uaddr;
	__u32 flags;
	__u32 __reserved;
};

static __always_inline __maybe_unused void
__from_c64_futex_waitv(struct futex_waitv *p)
{
	union {
		struct futex_waitv native;
		const struct __c64_futex_waitv compat;
	} *u = (void *)p;

	u->native.__reserved = u->compat.__reserved;
	u->native.flags = u->compat.flags;
	u->native.uaddr = (user_uintptr_t)compat_ptr(u->compat.uaddr);
	u->native.val = u->compat.val;
}
static __always_inline __maybe_unused void
__to_c64_futex_waitv(struct futex_waitv *p)
{
	union {
		struct __c64_futex_waitv compat;
		const struct futex_waitv native;
	} *u = (void *)p;

	u->compat.val = u->native.val;
	u->compat.uaddr = (__c64_ptr64 __force)u->native.uaddr;
	u->compat.flags = u->native.flags;
	u->compat.__reserved = u->native.__reserved;
}
static __always_inline __maybe_unused void
__from_c64_futex_waitv_2(struct futex_waitv *native, const struct __c64_futex_waitv *compat)
{

	native->val = compat->val;
	native->uaddr = (user_uintptr_t)compat_ptr(compat->uaddr);
	native->flags = compat->flags;
	native->__reserved = compat->__reserved;
}
static __always_inline __maybe_unused void
__to_c64_futex_waitv_2(struct __c64_futex_waitv *compat, const struct futex_waitv *native)
{

	compat->val = native->val;
	compat->uaddr = (__c64_ptr64 __force)native->uaddr;
	compat->flags = native->flags;
	compat->__reserved = native->__reserved;
}
struct __c64_robust_list {
	__c64_uptr next;
};

static __always_inline __maybe_unused void
__from_c64_robust_list(struct robust_list *p)
{
	union {
		struct robust_list native;
		const struct __c64_robust_list compat;
	} *u = (void *)p;

	u->native.next =  compat_ptr(u->compat.next);
}
static __always_inline __maybe_unused void
__to_c64_robust_list(struct robust_list *p)
{
	union {
		struct __c64_robust_list compat;
		const struct robust_list native;
	} *u = (void *)p;

	u->compat.next =  (__c64_uptr __force)(user_uintptr_t)u->native.next;
}
static __always_inline __maybe_unused void
__from_c64_robust_list_2(struct robust_list *native, const struct __c64_robust_list *compat)
{

	native->next =  compat_ptr(compat->next);
}
static __always_inline __maybe_unused void
__to_c64_robust_list_2(struct __c64_robust_list *compat, const struct robust_list *native)
{

	compat->next =  (__c64_uptr __force)(user_uintptr_t)native->next;
}
struct __c64_robust_list_head {
	/*
	 * The head of the list. Points back to itself if empty:
	 */
	struct __c64_robust_list list;

	/*
	 * This relative offset is set by user-space, it gives the kernel
	 * the relative position of the futex field to examine. This way
	 * we keep userspace flexible, to freely shape its data-structure,
	 * without hardcoding any particular offset into the kernel:
	 */
	long futex_offset;

	/*
	 * The death of the thread may race with userspace setting
	 * up a lock's links. So to handle this race, userspace first
	 * sets this field to the address of the to-be-taken lock,
	 * then does the lock acquire, and then adds itself to the
	 * list, and then clears this field. Hence the kernel will
	 * always have full knowledge of all locks that the thread
	 * _might_ have taken. We check the owner TID in any case,
	 * so only truly owned locks will be handled.
	 */
	__c64_uptr list_op_pending;
};

static __always_inline __maybe_unused void
__from_c64_robust_list_head(struct robust_list_head *p)
{
	union {
		struct robust_list_head native;
		const struct __c64_robust_list_head compat;
	} *u = (void *)p;

	u->native.list_op_pending =  compat_ptr(u->compat.list_op_pending);
	u->native.futex_offset = u->compat.futex_offset;
	u->native.list.next =  compat_ptr(u->compat.list.next);
}
static __always_inline __maybe_unused void
__to_c64_robust_list_head(struct robust_list_head *p)
{
	union {
		struct __c64_robust_list_head compat;
		const struct robust_list_head native;
	} *u = (void *)p;

	u->compat.list.next =  (__c64_uptr __force)(user_uintptr_t)u->native.list.next;
	u->compat.futex_offset = u->native.futex_offset;
	u->compat.list_op_pending =  (__c64_uptr __force)(user_uintptr_t)u->native.list_op_pending;
}
static __always_inline __maybe_unused void
__from_c64_robust_list_head_2(struct robust_list_head *native, const struct __c64_robust_list_head *compat)
{

	native->list.next =  compat_ptr(compat->list.next);
	native->futex_offset = compat->futex_offset;
	native->list_op_pending =  compat_ptr(compat->list_op_pending);
}
static __always_inline __maybe_unused void
__to_c64_robust_list_head_2(struct __c64_robust_list_head *compat, const struct robust_list_head *native)
{

	compat->list.next =  (__c64_uptr __force)(user_uintptr_t)native->list.next;
	compat->futex_offset = native->futex_offset;
	compat->list_op_pending =  (__c64_uptr __force)(user_uintptr_t)native->list_op_pending;
}
