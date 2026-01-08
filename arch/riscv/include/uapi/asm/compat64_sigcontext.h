#pragma once


#include <linux/compat.h>
#include <asm/compat64_ptrace.h>


struct __c64___sc_riscv_v_state {
	struct __c64___riscv_v_ext_state v_state;
} __attribute__((aligned(16)));

static __always_inline __maybe_unused void
__from_c64___sc_riscv_v_state(struct __sc_riscv_v_state *p)
{
	union {
		struct __sc_riscv_v_state native;
		const struct __c64___sc_riscv_v_state compat;
	} *u = (void *)p;

	u->native.v_state.datap =  compat_ptr(u->compat.v_state.datap);
	u->native.v_state.vlenb = u->compat.v_state.vlenb;
	u->native.v_state.vcsr = u->compat.v_state.vcsr;
	u->native.v_state.vtype = u->compat.v_state.vtype;
	u->native.v_state.vl = u->compat.v_state.vl;
	u->native.v_state.vstart = u->compat.v_state.vstart;
}
static __always_inline __maybe_unused void
__to_c64___sc_riscv_v_state(struct __sc_riscv_v_state *p)
{
	union {
		struct __c64___sc_riscv_v_state compat;
		const struct __sc_riscv_v_state native;
	} *u = (void *)p;

	u->compat.v_state.vstart = u->native.v_state.vstart;
	u->compat.v_state.vl = u->native.v_state.vl;
	u->compat.v_state.vtype = u->native.v_state.vtype;
	u->compat.v_state.vcsr = u->native.v_state.vcsr;
	u->compat.v_state.vlenb = u->native.v_state.vlenb;
	u->compat.v_state.datap =  (__c64_uptr __force)(user_uintptr_t)u->native.v_state.datap;
}
static __always_inline __maybe_unused void
__from_c64___sc_riscv_v_state_2(struct __sc_riscv_v_state *native, const struct __c64___sc_riscv_v_state *compat)
{

	native->v_state.vstart = compat->v_state.vstart;
	native->v_state.vl = compat->v_state.vl;
	native->v_state.vtype = compat->v_state.vtype;
	native->v_state.vcsr = compat->v_state.vcsr;
	native->v_state.vlenb = compat->v_state.vlenb;
	native->v_state.datap =  compat_ptr(compat->v_state.datap);
}
static __always_inline __maybe_unused void
__to_c64___sc_riscv_v_state_2(struct __c64___sc_riscv_v_state *compat, const struct __sc_riscv_v_state *native)
{

	compat->v_state.vstart = native->v_state.vstart;
	compat->v_state.vl = native->v_state.vl;
	compat->v_state.vtype = native->v_state.vtype;
	compat->v_state.vcsr = native->v_state.vcsr;
	compat->v_state.vlenb = native->v_state.vlenb;
	compat->v_state.datap =  (__c64_uptr __force)(user_uintptr_t)native->v_state.datap;
}
struct __c64_sigcontext {
	struct __c64_user_regs_struct sc_regs;
	union {
		union __riscv_fp_state sc_fpregs;
		struct __riscv_extra_ext_header sc_extdesc;
	};
};

static __always_inline __maybe_unused void
__from_c64_sigcontext(struct sigcontext *p)
{
	union {
		struct sigcontext native;
		const struct __c64_sigcontext compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.sc_extdesc) != sizeof(u->native.sc_extdesc));
	memmove(&u->native.sc_extdesc, &u->compat.sc_extdesc, sizeof(u->native.sc_extdesc));
	BUILD_BUG_ON(sizeof(u->compat.sc_fpregs) != sizeof(u->native.sc_fpregs));
	memmove(&u->native.sc_fpregs, &u->compat.sc_fpregs, sizeof(u->native.sc_fpregs));
	u->native.sc_regs.t6 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t6);
	u->native.sc_regs.t5 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t5);
	u->native.sc_regs.t4 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t4);
	u->native.sc_regs.t3 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t3);
	u->native.sc_regs.s11 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s11);
	u->native.sc_regs.s10 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s10);
	u->native.sc_regs.s9 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s9);
	u->native.sc_regs.s8 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s8);
	u->native.sc_regs.s7 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s7);
	u->native.sc_regs.s6 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s6);
	u->native.sc_regs.s5 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s5);
	u->native.sc_regs.s4 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s4);
	u->native.sc_regs.s3 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s3);
	u->native.sc_regs.s2 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s2);
	u->native.sc_regs.a7 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a7);
	u->native.sc_regs.a6 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a6);
	u->native.sc_regs.a5 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a5);
	u->native.sc_regs.a4 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a4);
	u->native.sc_regs.a3 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a3);
	u->native.sc_regs.a2 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a2);
	u->native.sc_regs.a1 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a1);
	u->native.sc_regs.a0 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.a0);
	u->native.sc_regs.s1 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s1);
	u->native.sc_regs.s0 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.s0);
	u->native.sc_regs.t2 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t2);
	u->native.sc_regs.t1 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t1);
	u->native.sc_regs.t0 = (user_uintptr_t)compat_ptr(u->compat.sc_regs.t0);
	u->native.sc_regs.tp = (user_uintptr_t)compat_ptr(u->compat.sc_regs.tp);
	u->native.sc_regs.gp = (user_uintptr_t)compat_ptr(u->compat.sc_regs.gp);
	u->native.sc_regs.sp = (user_uintptr_t)compat_ptr(u->compat.sc_regs.sp);
	u->native.sc_regs.ra = (user_uintptr_t)compat_ptr(u->compat.sc_regs.ra);
	u->native.sc_regs.pc = (user_uintptr_t)compat_ptr(u->compat.sc_regs.pc);
}
static __always_inline __maybe_unused void
__to_c64_sigcontext(struct sigcontext *p)
{
	union {
		struct __c64_sigcontext compat;
		const struct sigcontext native;
	} *u = (void *)p;

	u->compat.sc_regs.pc = (__c64_uptr __force)u->native.sc_regs.pc;
	u->compat.sc_regs.ra = (__c64_uptr __force)u->native.sc_regs.ra;
	u->compat.sc_regs.sp = (__c64_uptr __force)u->native.sc_regs.sp;
	u->compat.sc_regs.gp = (__c64_uptr __force)u->native.sc_regs.gp;
	u->compat.sc_regs.tp = (__c64_uptr __force)u->native.sc_regs.tp;
	u->compat.sc_regs.t0 = (__c64_uptr __force)u->native.sc_regs.t0;
	u->compat.sc_regs.t1 = (__c64_uptr __force)u->native.sc_regs.t1;
	u->compat.sc_regs.t2 = (__c64_uptr __force)u->native.sc_regs.t2;
	u->compat.sc_regs.s0 = (__c64_uptr __force)u->native.sc_regs.s0;
	u->compat.sc_regs.s1 = (__c64_uptr __force)u->native.sc_regs.s1;
	u->compat.sc_regs.a0 = (__c64_uptr __force)u->native.sc_regs.a0;
	u->compat.sc_regs.a1 = (__c64_uptr __force)u->native.sc_regs.a1;
	u->compat.sc_regs.a2 = (__c64_uptr __force)u->native.sc_regs.a2;
	u->compat.sc_regs.a3 = (__c64_uptr __force)u->native.sc_regs.a3;
	u->compat.sc_regs.a4 = (__c64_uptr __force)u->native.sc_regs.a4;
	u->compat.sc_regs.a5 = (__c64_uptr __force)u->native.sc_regs.a5;
	u->compat.sc_regs.a6 = (__c64_uptr __force)u->native.sc_regs.a6;
	u->compat.sc_regs.a7 = (__c64_uptr __force)u->native.sc_regs.a7;
	u->compat.sc_regs.s2 = (__c64_uptr __force)u->native.sc_regs.s2;
	u->compat.sc_regs.s3 = (__c64_uptr __force)u->native.sc_regs.s3;
	u->compat.sc_regs.s4 = (__c64_uptr __force)u->native.sc_regs.s4;
	u->compat.sc_regs.s5 = (__c64_uptr __force)u->native.sc_regs.s5;
	u->compat.sc_regs.s6 = (__c64_uptr __force)u->native.sc_regs.s6;
	u->compat.sc_regs.s7 = (__c64_uptr __force)u->native.sc_regs.s7;
	u->compat.sc_regs.s8 = (__c64_uptr __force)u->native.sc_regs.s8;
	u->compat.sc_regs.s9 = (__c64_uptr __force)u->native.sc_regs.s9;
	u->compat.sc_regs.s10 = (__c64_uptr __force)u->native.sc_regs.s10;
	u->compat.sc_regs.s11 = (__c64_uptr __force)u->native.sc_regs.s11;
	u->compat.sc_regs.t3 = (__c64_uptr __force)u->native.sc_regs.t3;
	u->compat.sc_regs.t4 = (__c64_uptr __force)u->native.sc_regs.t4;
	u->compat.sc_regs.t5 = (__c64_uptr __force)u->native.sc_regs.t5;
	u->compat.sc_regs.t6 = (__c64_uptr __force)u->native.sc_regs.t6;
	BUILD_BUG_ON(sizeof(u->native.sc_fpregs) != sizeof(u->compat.sc_fpregs));
	memmove(&u->compat.sc_fpregs, &u->native.sc_fpregs, sizeof(u->compat.sc_fpregs));
	BUILD_BUG_ON(sizeof(u->native.sc_extdesc) != sizeof(u->compat.sc_extdesc));
	memmove(&u->compat.sc_extdesc, &u->native.sc_extdesc, sizeof(u->compat.sc_extdesc));
}
static __always_inline __maybe_unused void
__from_c64_sigcontext_2(struct sigcontext *native, const struct __c64_sigcontext *compat)
{

	native->sc_regs.pc = (user_uintptr_t)compat_ptr(compat->sc_regs.pc);
	native->sc_regs.ra = (user_uintptr_t)compat_ptr(compat->sc_regs.ra);
	native->sc_regs.sp = (user_uintptr_t)compat_ptr(compat->sc_regs.sp);
	native->sc_regs.gp = (user_uintptr_t)compat_ptr(compat->sc_regs.gp);
	native->sc_regs.tp = (user_uintptr_t)compat_ptr(compat->sc_regs.tp);
	native->sc_regs.t0 = (user_uintptr_t)compat_ptr(compat->sc_regs.t0);
	native->sc_regs.t1 = (user_uintptr_t)compat_ptr(compat->sc_regs.t1);
	native->sc_regs.t2 = (user_uintptr_t)compat_ptr(compat->sc_regs.t2);
	native->sc_regs.s0 = (user_uintptr_t)compat_ptr(compat->sc_regs.s0);
	native->sc_regs.s1 = (user_uintptr_t)compat_ptr(compat->sc_regs.s1);
	native->sc_regs.a0 = (user_uintptr_t)compat_ptr(compat->sc_regs.a0);
	native->sc_regs.a1 = (user_uintptr_t)compat_ptr(compat->sc_regs.a1);
	native->sc_regs.a2 = (user_uintptr_t)compat_ptr(compat->sc_regs.a2);
	native->sc_regs.a3 = (user_uintptr_t)compat_ptr(compat->sc_regs.a3);
	native->sc_regs.a4 = (user_uintptr_t)compat_ptr(compat->sc_regs.a4);
	native->sc_regs.a5 = (user_uintptr_t)compat_ptr(compat->sc_regs.a5);
	native->sc_regs.a6 = (user_uintptr_t)compat_ptr(compat->sc_regs.a6);
	native->sc_regs.a7 = (user_uintptr_t)compat_ptr(compat->sc_regs.a7);
	native->sc_regs.s2 = (user_uintptr_t)compat_ptr(compat->sc_regs.s2);
	native->sc_regs.s3 = (user_uintptr_t)compat_ptr(compat->sc_regs.s3);
	native->sc_regs.s4 = (user_uintptr_t)compat_ptr(compat->sc_regs.s4);
	native->sc_regs.s5 = (user_uintptr_t)compat_ptr(compat->sc_regs.s5);
	native->sc_regs.s6 = (user_uintptr_t)compat_ptr(compat->sc_regs.s6);
	native->sc_regs.s7 = (user_uintptr_t)compat_ptr(compat->sc_regs.s7);
	native->sc_regs.s8 = (user_uintptr_t)compat_ptr(compat->sc_regs.s8);
	native->sc_regs.s9 = (user_uintptr_t)compat_ptr(compat->sc_regs.s9);
	native->sc_regs.s10 = (user_uintptr_t)compat_ptr(compat->sc_regs.s10);
	native->sc_regs.s11 = (user_uintptr_t)compat_ptr(compat->sc_regs.s11);
	native->sc_regs.t3 = (user_uintptr_t)compat_ptr(compat->sc_regs.t3);
	native->sc_regs.t4 = (user_uintptr_t)compat_ptr(compat->sc_regs.t4);
	native->sc_regs.t5 = (user_uintptr_t)compat_ptr(compat->sc_regs.t5);
	native->sc_regs.t6 = (user_uintptr_t)compat_ptr(compat->sc_regs.t6);
	BUILD_BUG_ON(sizeof(compat->sc_fpregs) != sizeof(native->sc_fpregs));
	memcpy(&native->sc_fpregs, &compat->sc_fpregs, sizeof(native->sc_fpregs));
	BUILD_BUG_ON(sizeof(compat->sc_extdesc) != sizeof(native->sc_extdesc));
	memcpy(&native->sc_extdesc, &compat->sc_extdesc, sizeof(native->sc_extdesc));
}
static __always_inline __maybe_unused void
__to_c64_sigcontext_2(struct __c64_sigcontext *compat, const struct sigcontext *native)
{

	compat->sc_regs.pc = (__c64_uptr __force)native->sc_regs.pc;
	compat->sc_regs.ra = (__c64_uptr __force)native->sc_regs.ra;
	compat->sc_regs.sp = (__c64_uptr __force)native->sc_regs.sp;
	compat->sc_regs.gp = (__c64_uptr __force)native->sc_regs.gp;
	compat->sc_regs.tp = (__c64_uptr __force)native->sc_regs.tp;
	compat->sc_regs.t0 = (__c64_uptr __force)native->sc_regs.t0;
	compat->sc_regs.t1 = (__c64_uptr __force)native->sc_regs.t1;
	compat->sc_regs.t2 = (__c64_uptr __force)native->sc_regs.t2;
	compat->sc_regs.s0 = (__c64_uptr __force)native->sc_regs.s0;
	compat->sc_regs.s1 = (__c64_uptr __force)native->sc_regs.s1;
	compat->sc_regs.a0 = (__c64_uptr __force)native->sc_regs.a0;
	compat->sc_regs.a1 = (__c64_uptr __force)native->sc_regs.a1;
	compat->sc_regs.a2 = (__c64_uptr __force)native->sc_regs.a2;
	compat->sc_regs.a3 = (__c64_uptr __force)native->sc_regs.a3;
	compat->sc_regs.a4 = (__c64_uptr __force)native->sc_regs.a4;
	compat->sc_regs.a5 = (__c64_uptr __force)native->sc_regs.a5;
	compat->sc_regs.a6 = (__c64_uptr __force)native->sc_regs.a6;
	compat->sc_regs.a7 = (__c64_uptr __force)native->sc_regs.a7;
	compat->sc_regs.s2 = (__c64_uptr __force)native->sc_regs.s2;
	compat->sc_regs.s3 = (__c64_uptr __force)native->sc_regs.s3;
	compat->sc_regs.s4 = (__c64_uptr __force)native->sc_regs.s4;
	compat->sc_regs.s5 = (__c64_uptr __force)native->sc_regs.s5;
	compat->sc_regs.s6 = (__c64_uptr __force)native->sc_regs.s6;
	compat->sc_regs.s7 = (__c64_uptr __force)native->sc_regs.s7;
	compat->sc_regs.s8 = (__c64_uptr __force)native->sc_regs.s8;
	compat->sc_regs.s9 = (__c64_uptr __force)native->sc_regs.s9;
	compat->sc_regs.s10 = (__c64_uptr __force)native->sc_regs.s10;
	compat->sc_regs.s11 = (__c64_uptr __force)native->sc_regs.s11;
	compat->sc_regs.t3 = (__c64_uptr __force)native->sc_regs.t3;
	compat->sc_regs.t4 = (__c64_uptr __force)native->sc_regs.t4;
	compat->sc_regs.t5 = (__c64_uptr __force)native->sc_regs.t5;
	compat->sc_regs.t6 = (__c64_uptr __force)native->sc_regs.t6;
	BUILD_BUG_ON(sizeof(native->sc_fpregs) != sizeof(compat->sc_fpregs));
	memcpy(&compat->sc_fpregs, &native->sc_fpregs, sizeof(compat->sc_fpregs));
	BUILD_BUG_ON(sizeof(native->sc_extdesc) != sizeof(compat->sc_extdesc));
	memcpy(&compat->sc_extdesc, &native->sc_extdesc, sizeof(compat->sc_extdesc));
}
