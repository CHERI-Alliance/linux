#pragma once


#include <linux/compat.h>


struct __c64_xt_bpf_info {
	__u16 bpf_program_num_elem;
	struct sock_filter bpf_program[XT_BPF_MAX_NUM_INSTR];

	/* only used in the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr filter;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __filter;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_xt_bpf_info(struct xt_bpf_info *p)
{
	union {
		struct xt_bpf_info native;
		const struct __c64_xt_bpf_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.bpf_program) != sizeof(u->native.bpf_program));
	memmove(&u->native.bpf_program, &u->compat.bpf_program, sizeof(u->native.bpf_program));
	u->native.bpf_program_num_elem = u->compat.bpf_program_num_elem;
}
static __always_inline __maybe_unused void
__to_c64_xt_bpf_info(struct xt_bpf_info *p)
{
	union {
		struct __c64_xt_bpf_info compat;
		const struct xt_bpf_info native;
	} *u = (void *)p;

	u->compat.bpf_program_num_elem = u->native.bpf_program_num_elem;
	BUILD_BUG_ON(sizeof(u->native.bpf_program) != sizeof(u->compat.bpf_program));
	memmove(&u->compat.bpf_program, &u->native.bpf_program, sizeof(u->compat.bpf_program));
}
static __always_inline __maybe_unused void
__from_c64_xt_bpf_info_2(struct xt_bpf_info *native, const struct __c64_xt_bpf_info *compat)
{

	native->bpf_program_num_elem = compat->bpf_program_num_elem;
	BUILD_BUG_ON(sizeof(compat->bpf_program) != sizeof(native->bpf_program));
	memcpy(&native->bpf_program, &compat->bpf_program, sizeof(native->bpf_program));
}
static __always_inline __maybe_unused void
__to_c64_xt_bpf_info_2(struct __c64_xt_bpf_info *compat, const struct xt_bpf_info *native)
{

	compat->bpf_program_num_elem = native->bpf_program_num_elem;
	BUILD_BUG_ON(sizeof(native->bpf_program) != sizeof(compat->bpf_program));
	memcpy(&compat->bpf_program, &native->bpf_program, sizeof(compat->bpf_program));
}
struct __c64_xt_bpf_info_v1 {
	__u16 mode;
	__u16 bpf_program_num_elem;
	__s32 fd;
	union {
		struct sock_filter bpf_program[XT_BPF_MAX_NUM_INSTR];
		char path[XT_BPF_PATH_MAX];
	};

	/* only used in the kernel */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr filter;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __filter;
	} __attribute__((aligned(8)));
};

