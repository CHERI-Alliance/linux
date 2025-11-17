#pragma once


#include <linux/compat.h>
#include <asm/compat64_i_ptrace.h>


struct __c64_user_cap {
	__c64_uptr val;
	__u8 tag;
	/// UAPI: NoConvert: Padding
	__u8 _pad[sizeof(__c64_uptr ) - 1];
};

static __always_inline __maybe_unused void
__from_c64_user_cap(struct user_cap *p)
{
	union {
		struct user_cap native;
		const struct __c64_user_cap compat;
	} *u = (void *)p;

	u->native.tag = u->compat.tag;
	u->native.val = (user_uintptr_t)compat_ptr(u->compat.val);
}
static __always_inline __maybe_unused void
__to_c64_user_cap(struct user_cap *p)
{
	union {
		struct __c64_user_cap compat;
		const struct user_cap native;
	} *u = (void *)p;

	u->compat.val = (__c64_uptr __force)u->native.val;
	u->compat.tag = u->native.tag;
}
static __always_inline __maybe_unused void
__from_c64_user_cap_2(struct user_cap *native, const struct __c64_user_cap *compat)
{

	native->val = (user_uintptr_t)compat_ptr(compat->val);
	native->tag = compat->tag;
}
static __always_inline __maybe_unused void
__to_c64_user_cap_2(struct __c64_user_cap *compat, const struct user_cap *native)
{

	compat->val = (__c64_uptr __force)native->val;
	compat->tag = native->tag;
}
struct __c64___riscv_v_ext_state {
	unsigned long vstart;
	unsigned long vl;
	unsigned long vtype;
	unsigned long vcsr;
	unsigned long vlenb;
	__c64_uptr datap;
	/*
	 * In signal handler, datap will be set a correct user stack offset
	 * and vector registers will be copied to the address of datap
	 * pointer.
	 */
};

static __always_inline __maybe_unused void
__from_c64___riscv_v_ext_state(struct __riscv_v_ext_state *p)
{
	union {
		struct __riscv_v_ext_state native;
		const struct __c64___riscv_v_ext_state compat;
	} *u = (void *)p;

	u->native.datap =  compat_ptr(u->compat.datap);
	u->native.vlenb = u->compat.vlenb;
	u->native.vcsr = u->compat.vcsr;
	u->native.vtype = u->compat.vtype;
	u->native.vl = u->compat.vl;
	u->native.vstart = u->compat.vstart;
}
static __always_inline __maybe_unused void
__to_c64___riscv_v_ext_state(struct __riscv_v_ext_state *p)
{
	union {
		struct __c64___riscv_v_ext_state compat;
		const struct __riscv_v_ext_state native;
	} *u = (void *)p;

	u->compat.vstart = u->native.vstart;
	u->compat.vl = u->native.vl;
	u->compat.vtype = u->native.vtype;
	u->compat.vcsr = u->native.vcsr;
	u->compat.vlenb = u->native.vlenb;
	u->compat.datap =  (__c64_uptr __force)(user_uintptr_t)u->native.datap;
}
static __always_inline __maybe_unused void
__from_c64___riscv_v_ext_state_2(struct __riscv_v_ext_state *native, const struct __c64___riscv_v_ext_state *compat)
{

	native->vstart = compat->vstart;
	native->vl = compat->vl;
	native->vtype = compat->vtype;
	native->vcsr = compat->vcsr;
	native->vlenb = compat->vlenb;
	native->datap =  compat_ptr(compat->datap);
}
static __always_inline __maybe_unused void
__to_c64___riscv_v_ext_state_2(struct __c64___riscv_v_ext_state *compat, const struct __riscv_v_ext_state *native)
{

	compat->vstart = native->vstart;
	compat->vl = native->vl;
	compat->vtype = native->vtype;
	compat->vcsr = native->vcsr;
	compat->vlenb = native->vlenb;
	compat->datap =  (__c64_uptr __force)(user_uintptr_t)native->datap;
}
