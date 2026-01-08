#pragma once


#include <linux/compat.h>


struct __c64_clone_args {
	__aligned_u64 flags;
	__c64_ptr64 pidfd;
	__c64_ptr64 child_tid;
	__c64_ptr64 parent_tid;
	__aligned_u64 exit_signal;
	__c64_ptr64 stack;
	__aligned_u64 stack_size;
	__c64_ptr64 tls;
	__c64_ptr64 set_tid;
	__aligned_u64 set_tid_size;
	__aligned_u64 cgroup;
};

static __always_inline __maybe_unused void
__from_c64_clone_args(struct clone_args *p)
{
	union {
		struct clone_args native;
		const struct __c64_clone_args compat;
	} *u = (void *)p;

	u->native.cgroup = u->compat.cgroup;
	u->native.set_tid_size = u->compat.set_tid_size;
	u->native.set_tid = (user_uintptr_t)compat_ptr(u->compat.set_tid);
	u->native.tls = (user_uintptr_t)compat_ptr(u->compat.tls);
	u->native.stack_size = u->compat.stack_size;
	u->native.stack = (user_uintptr_t)compat_ptr(u->compat.stack);
	u->native.exit_signal = u->compat.exit_signal;
	u->native.parent_tid = (user_uintptr_t)compat_ptr(u->compat.parent_tid);
	u->native.child_tid = (user_uintptr_t)compat_ptr(u->compat.child_tid);
	u->native.pidfd = (user_uintptr_t)compat_ptr(u->compat.pidfd);
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_clone_args(struct clone_args *p)
{
	union {
		struct __c64_clone_args compat;
		const struct clone_args native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.pidfd = (__c64_ptr64 __force)u->native.pidfd;
	u->compat.child_tid = (__c64_ptr64 __force)u->native.child_tid;
	u->compat.parent_tid = (__c64_ptr64 __force)u->native.parent_tid;
	u->compat.exit_signal = u->native.exit_signal;
	u->compat.stack = (__c64_ptr64 __force)u->native.stack;
	u->compat.stack_size = u->native.stack_size;
	u->compat.tls = (__c64_ptr64 __force)u->native.tls;
	u->compat.set_tid = (__c64_ptr64 __force)u->native.set_tid;
	u->compat.set_tid_size = u->native.set_tid_size;
	u->compat.cgroup = u->native.cgroup;
}
static __always_inline __maybe_unused void
__from_c64_clone_args_2(struct clone_args *native, const struct __c64_clone_args *compat)
{

	native->flags = compat->flags;
	native->pidfd = (user_uintptr_t)compat_ptr(compat->pidfd);
	native->child_tid = (user_uintptr_t)compat_ptr(compat->child_tid);
	native->parent_tid = (user_uintptr_t)compat_ptr(compat->parent_tid);
	native->exit_signal = compat->exit_signal;
	native->stack = (user_uintptr_t)compat_ptr(compat->stack);
	native->stack_size = compat->stack_size;
	native->tls = (user_uintptr_t)compat_ptr(compat->tls);
	native->set_tid = (user_uintptr_t)compat_ptr(compat->set_tid);
	native->set_tid_size = compat->set_tid_size;
	native->cgroup = compat->cgroup;
}
static __always_inline __maybe_unused void
__to_c64_clone_args_2(struct __c64_clone_args *compat, const struct clone_args *native)
{

	compat->flags = native->flags;
	compat->pidfd = (__c64_ptr64 __force)native->pidfd;
	compat->child_tid = (__c64_ptr64 __force)native->child_tid;
	compat->parent_tid = (__c64_ptr64 __force)native->parent_tid;
	compat->exit_signal = native->exit_signal;
	compat->stack = (__c64_ptr64 __force)native->stack;
	compat->stack_size = native->stack_size;
	compat->tls = (__c64_ptr64 __force)native->tls;
	compat->set_tid = (__c64_ptr64 __force)native->set_tid;
	compat->set_tid_size = native->set_tid_size;
	compat->cgroup = native->cgroup;
}
