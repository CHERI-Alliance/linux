#pragma once


#include <linux/compat.h>


struct __c64_prctl_mm_map {
	__u64	start_code;		/* code section bounds */
	__u64	end_code;
	__u64	start_data;		/* data section bounds */
	__u64	end_data;
	__u64	start_brk;		/* heap for brk() syscall */
	__u64	brk;
	__u64	start_stack;		/* stack starts at */
	__u64	arg_start;		/* command line arguments bounds */
	__u64	arg_end;
	__u64	env_start;		/* environment variables bounds */
	__u64	env_end;
	__c64_uptr auxv;			/* auxiliary vector */
	__u32	auxv_size;		/* vector size */
	__u32	exe_fd;			/* /proc/$pid/exe link file */
};

static __always_inline __maybe_unused void
__from_c64_prctl_mm_map(struct prctl_mm_map *p)
{
	union {
		struct prctl_mm_map native;
		const struct __c64_prctl_mm_map compat;
	} *u = (void *)p;

	u->native.exe_fd = u->compat.exe_fd;
	u->native.auxv_size = u->compat.auxv_size;
	u->native.auxv =  compat_ptr(u->compat.auxv);
	u->native.env_end = u->compat.env_end;
	u->native.env_start = u->compat.env_start;
	u->native.arg_end = u->compat.arg_end;
	u->native.arg_start = u->compat.arg_start;
	u->native.start_stack = u->compat.start_stack;
	u->native.brk = u->compat.brk;
	u->native.start_brk = u->compat.start_brk;
	u->native.end_data = u->compat.end_data;
	u->native.start_data = u->compat.start_data;
	u->native.end_code = u->compat.end_code;
	u->native.start_code = u->compat.start_code;
}
static __always_inline __maybe_unused void
__to_c64_prctl_mm_map(struct prctl_mm_map *p)
{
	union {
		struct __c64_prctl_mm_map compat;
		const struct prctl_mm_map native;
	} *u = (void *)p;

	u->compat.start_code = u->native.start_code;
	u->compat.end_code = u->native.end_code;
	u->compat.start_data = u->native.start_data;
	u->compat.end_data = u->native.end_data;
	u->compat.start_brk = u->native.start_brk;
	u->compat.brk = u->native.brk;
	u->compat.start_stack = u->native.start_stack;
	u->compat.arg_start = u->native.arg_start;
	u->compat.arg_end = u->native.arg_end;
	u->compat.env_start = u->native.env_start;
	u->compat.env_end = u->native.env_end;
	u->compat.auxv =  (__c64_uptr __force)(user_uintptr_t)u->native.auxv;
	u->compat.auxv_size = u->native.auxv_size;
	u->compat.exe_fd = u->native.exe_fd;
}
static __always_inline __maybe_unused void
__from_c64_prctl_mm_map_2(struct prctl_mm_map *native, const struct __c64_prctl_mm_map *compat)
{

	native->start_code = compat->start_code;
	native->end_code = compat->end_code;
	native->start_data = compat->start_data;
	native->end_data = compat->end_data;
	native->start_brk = compat->start_brk;
	native->brk = compat->brk;
	native->start_stack = compat->start_stack;
	native->arg_start = compat->arg_start;
	native->arg_end = compat->arg_end;
	native->env_start = compat->env_start;
	native->env_end = compat->env_end;
	native->auxv =  compat_ptr(compat->auxv);
	native->auxv_size = compat->auxv_size;
	native->exe_fd = compat->exe_fd;
}
static __always_inline __maybe_unused void
__to_c64_prctl_mm_map_2(struct __c64_prctl_mm_map *compat, const struct prctl_mm_map *native)
{

	compat->start_code = native->start_code;
	compat->end_code = native->end_code;
	compat->start_data = native->start_data;
	compat->end_data = native->end_data;
	compat->start_brk = native->start_brk;
	compat->brk = native->brk;
	compat->start_stack = native->start_stack;
	compat->arg_start = native->arg_start;
	compat->arg_end = native->arg_end;
	compat->env_start = native->env_start;
	compat->env_end = native->env_end;
	compat->auxv =  (__c64_uptr __force)(user_uintptr_t)native->auxv;
	compat->auxv_size = native->auxv_size;
	compat->exe_fd = native->exe_fd;
}
