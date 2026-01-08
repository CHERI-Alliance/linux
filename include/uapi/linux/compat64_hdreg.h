#pragma once


#include <linux/compat.h>


typedef struct __c64_ide_ioctl_request_s {
	__c64_uptr task_request;
	__c64_uptr out_buffer;
	__c64_uptr in_buffer;
} __c64_ide_ioctl_request_t;

static __always_inline __maybe_unused void
__from_c64_ide_ioctl_request_s(struct ide_ioctl_request_s *p)
{
	union {
		struct ide_ioctl_request_s native;
		const struct __c64_ide_ioctl_request_s compat;
	} *u = (void *)p;

	u->native.in_buffer =  compat_ptr(u->compat.in_buffer);
	u->native.out_buffer =  compat_ptr(u->compat.out_buffer);
	u->native.task_request =  compat_ptr(u->compat.task_request);
}
static __always_inline __maybe_unused void
__to_c64_ide_ioctl_request_s(struct ide_ioctl_request_s *p)
{
	union {
		struct __c64_ide_ioctl_request_s compat;
		const struct ide_ioctl_request_s native;
	} *u = (void *)p;

	u->compat.task_request =  (__c64_uptr __force)(user_uintptr_t)u->native.task_request;
	u->compat.out_buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.out_buffer;
	u->compat.in_buffer =  (__c64_uptr __force)(user_uintptr_t)u->native.in_buffer;
}
static __always_inline __maybe_unused void
__from_c64_ide_ioctl_request_s_2(struct ide_ioctl_request_s *native, const struct __c64_ide_ioctl_request_s *compat)
{

	native->task_request =  compat_ptr(compat->task_request);
	native->out_buffer =  compat_ptr(compat->out_buffer);
	native->in_buffer =  compat_ptr(compat->in_buffer);
}
static __always_inline __maybe_unused void
__to_c64_ide_ioctl_request_s_2(struct __c64_ide_ioctl_request_s *compat, const struct ide_ioctl_request_s *native)
{

	compat->task_request =  (__c64_uptr __force)(user_uintptr_t)native->task_request;
	compat->out_buffer =  (__c64_uptr __force)(user_uintptr_t)native->out_buffer;
	compat->in_buffer =  (__c64_uptr __force)(user_uintptr_t)native->in_buffer;
}
