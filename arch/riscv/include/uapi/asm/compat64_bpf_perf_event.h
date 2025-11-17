#pragma once


#include <linux/compat.h>
#include <asm/compat64_ptrace.h>


typedef struct __c64_user_regs_struct __c64_bpf_user_pt_regs_t;

static __always_inline __maybe_unused void
__from_c64_bpf_user_pt_regs_t(bpf_user_pt_regs_t *p)
{
	union {
		bpf_user_pt_regs_t native;
		const __c64_bpf_user_pt_regs_t compat;
	} *u = (void *)p;

	u->native.t6 = (user_uintptr_t)compat_ptr(u->compat.t6);
	u->native.t5 = (user_uintptr_t)compat_ptr(u->compat.t5);
	u->native.t4 = (user_uintptr_t)compat_ptr(u->compat.t4);
	u->native.t3 = (user_uintptr_t)compat_ptr(u->compat.t3);
	u->native.s11 = (user_uintptr_t)compat_ptr(u->compat.s11);
	u->native.s10 = (user_uintptr_t)compat_ptr(u->compat.s10);
	u->native.s9 = (user_uintptr_t)compat_ptr(u->compat.s9);
	u->native.s8 = (user_uintptr_t)compat_ptr(u->compat.s8);
	u->native.s7 = (user_uintptr_t)compat_ptr(u->compat.s7);
	u->native.s6 = (user_uintptr_t)compat_ptr(u->compat.s6);
	u->native.s5 = (user_uintptr_t)compat_ptr(u->compat.s5);
	u->native.s4 = (user_uintptr_t)compat_ptr(u->compat.s4);
	u->native.s3 = (user_uintptr_t)compat_ptr(u->compat.s3);
	u->native.s2 = (user_uintptr_t)compat_ptr(u->compat.s2);
	u->native.a7 = (user_uintptr_t)compat_ptr(u->compat.a7);
	u->native.a6 = (user_uintptr_t)compat_ptr(u->compat.a6);
	u->native.a5 = (user_uintptr_t)compat_ptr(u->compat.a5);
	u->native.a4 = (user_uintptr_t)compat_ptr(u->compat.a4);
	u->native.a3 = (user_uintptr_t)compat_ptr(u->compat.a3);
	u->native.a2 = (user_uintptr_t)compat_ptr(u->compat.a2);
	u->native.a1 = (user_uintptr_t)compat_ptr(u->compat.a1);
	u->native.a0 = (user_uintptr_t)compat_ptr(u->compat.a0);
	u->native.s1 = (user_uintptr_t)compat_ptr(u->compat.s1);
	u->native.s0 = (user_uintptr_t)compat_ptr(u->compat.s0);
	u->native.t2 = (user_uintptr_t)compat_ptr(u->compat.t2);
	u->native.t1 = (user_uintptr_t)compat_ptr(u->compat.t1);
	u->native.t0 = (user_uintptr_t)compat_ptr(u->compat.t0);
	u->native.tp = (user_uintptr_t)compat_ptr(u->compat.tp);
	u->native.gp = (user_uintptr_t)compat_ptr(u->compat.gp);
	u->native.sp = (user_uintptr_t)compat_ptr(u->compat.sp);
	u->native.ra = (user_uintptr_t)compat_ptr(u->compat.ra);
	u->native.pc = (user_uintptr_t)compat_ptr(u->compat.pc);
}
static __always_inline __maybe_unused void
__to_c64_bpf_user_pt_regs_t(bpf_user_pt_regs_t *p)
{
	union {
		__c64_bpf_user_pt_regs_t compat;
		const bpf_user_pt_regs_t native;
	} *u = (void *)p;

	u->compat.pc = (__c64_uptr __force)u->native.pc;
	u->compat.ra = (__c64_uptr __force)u->native.ra;
	u->compat.sp = (__c64_uptr __force)u->native.sp;
	u->compat.gp = (__c64_uptr __force)u->native.gp;
	u->compat.tp = (__c64_uptr __force)u->native.tp;
	u->compat.t0 = (__c64_uptr __force)u->native.t0;
	u->compat.t1 = (__c64_uptr __force)u->native.t1;
	u->compat.t2 = (__c64_uptr __force)u->native.t2;
	u->compat.s0 = (__c64_uptr __force)u->native.s0;
	u->compat.s1 = (__c64_uptr __force)u->native.s1;
	u->compat.a0 = (__c64_uptr __force)u->native.a0;
	u->compat.a1 = (__c64_uptr __force)u->native.a1;
	u->compat.a2 = (__c64_uptr __force)u->native.a2;
	u->compat.a3 = (__c64_uptr __force)u->native.a3;
	u->compat.a4 = (__c64_uptr __force)u->native.a4;
	u->compat.a5 = (__c64_uptr __force)u->native.a5;
	u->compat.a6 = (__c64_uptr __force)u->native.a6;
	u->compat.a7 = (__c64_uptr __force)u->native.a7;
	u->compat.s2 = (__c64_uptr __force)u->native.s2;
	u->compat.s3 = (__c64_uptr __force)u->native.s3;
	u->compat.s4 = (__c64_uptr __force)u->native.s4;
	u->compat.s5 = (__c64_uptr __force)u->native.s5;
	u->compat.s6 = (__c64_uptr __force)u->native.s6;
	u->compat.s7 = (__c64_uptr __force)u->native.s7;
	u->compat.s8 = (__c64_uptr __force)u->native.s8;
	u->compat.s9 = (__c64_uptr __force)u->native.s9;
	u->compat.s10 = (__c64_uptr __force)u->native.s10;
	u->compat.s11 = (__c64_uptr __force)u->native.s11;
	u->compat.t3 = (__c64_uptr __force)u->native.t3;
	u->compat.t4 = (__c64_uptr __force)u->native.t4;
	u->compat.t5 = (__c64_uptr __force)u->native.t5;
	u->compat.t6 = (__c64_uptr __force)u->native.t6;
}
static __always_inline __maybe_unused void
__from_c64_bpf_user_pt_regs_t_2(bpf_user_pt_regs_t *native, const __c64_bpf_user_pt_regs_t *compat)
{

	native->pc = (user_uintptr_t)compat_ptr(compat->pc);
	native->ra = (user_uintptr_t)compat_ptr(compat->ra);
	native->sp = (user_uintptr_t)compat_ptr(compat->sp);
	native->gp = (user_uintptr_t)compat_ptr(compat->gp);
	native->tp = (user_uintptr_t)compat_ptr(compat->tp);
	native->t0 = (user_uintptr_t)compat_ptr(compat->t0);
	native->t1 = (user_uintptr_t)compat_ptr(compat->t1);
	native->t2 = (user_uintptr_t)compat_ptr(compat->t2);
	native->s0 = (user_uintptr_t)compat_ptr(compat->s0);
	native->s1 = (user_uintptr_t)compat_ptr(compat->s1);
	native->a0 = (user_uintptr_t)compat_ptr(compat->a0);
	native->a1 = (user_uintptr_t)compat_ptr(compat->a1);
	native->a2 = (user_uintptr_t)compat_ptr(compat->a2);
	native->a3 = (user_uintptr_t)compat_ptr(compat->a3);
	native->a4 = (user_uintptr_t)compat_ptr(compat->a4);
	native->a5 = (user_uintptr_t)compat_ptr(compat->a5);
	native->a6 = (user_uintptr_t)compat_ptr(compat->a6);
	native->a7 = (user_uintptr_t)compat_ptr(compat->a7);
	native->s2 = (user_uintptr_t)compat_ptr(compat->s2);
	native->s3 = (user_uintptr_t)compat_ptr(compat->s3);
	native->s4 = (user_uintptr_t)compat_ptr(compat->s4);
	native->s5 = (user_uintptr_t)compat_ptr(compat->s5);
	native->s6 = (user_uintptr_t)compat_ptr(compat->s6);
	native->s7 = (user_uintptr_t)compat_ptr(compat->s7);
	native->s8 = (user_uintptr_t)compat_ptr(compat->s8);
	native->s9 = (user_uintptr_t)compat_ptr(compat->s9);
	native->s10 = (user_uintptr_t)compat_ptr(compat->s10);
	native->s11 = (user_uintptr_t)compat_ptr(compat->s11);
	native->t3 = (user_uintptr_t)compat_ptr(compat->t3);
	native->t4 = (user_uintptr_t)compat_ptr(compat->t4);
	native->t5 = (user_uintptr_t)compat_ptr(compat->t5);
	native->t6 = (user_uintptr_t)compat_ptr(compat->t6);
}
static __always_inline __maybe_unused void
__to_c64_bpf_user_pt_regs_t_2(__c64_bpf_user_pt_regs_t *compat, const bpf_user_pt_regs_t *native)
{

	compat->pc = (__c64_uptr __force)native->pc;
	compat->ra = (__c64_uptr __force)native->ra;
	compat->sp = (__c64_uptr __force)native->sp;
	compat->gp = (__c64_uptr __force)native->gp;
	compat->tp = (__c64_uptr __force)native->tp;
	compat->t0 = (__c64_uptr __force)native->t0;
	compat->t1 = (__c64_uptr __force)native->t1;
	compat->t2 = (__c64_uptr __force)native->t2;
	compat->s0 = (__c64_uptr __force)native->s0;
	compat->s1 = (__c64_uptr __force)native->s1;
	compat->a0 = (__c64_uptr __force)native->a0;
	compat->a1 = (__c64_uptr __force)native->a1;
	compat->a2 = (__c64_uptr __force)native->a2;
	compat->a3 = (__c64_uptr __force)native->a3;
	compat->a4 = (__c64_uptr __force)native->a4;
	compat->a5 = (__c64_uptr __force)native->a5;
	compat->a6 = (__c64_uptr __force)native->a6;
	compat->a7 = (__c64_uptr __force)native->a7;
	compat->s2 = (__c64_uptr __force)native->s2;
	compat->s3 = (__c64_uptr __force)native->s3;
	compat->s4 = (__c64_uptr __force)native->s4;
	compat->s5 = (__c64_uptr __force)native->s5;
	compat->s6 = (__c64_uptr __force)native->s6;
	compat->s7 = (__c64_uptr __force)native->s7;
	compat->s8 = (__c64_uptr __force)native->s8;
	compat->s9 = (__c64_uptr __force)native->s9;
	compat->s10 = (__c64_uptr __force)native->s10;
	compat->s11 = (__c64_uptr __force)native->s11;
	compat->t3 = (__c64_uptr __force)native->t3;
	compat->t4 = (__c64_uptr __force)native->t4;
	compat->t5 = (__c64_uptr __force)native->t5;
	compat->t6 = (__c64_uptr __force)native->t6;
}
