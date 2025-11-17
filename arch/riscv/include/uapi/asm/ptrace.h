/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _UAPI_ASM_RISCV_PTRACE_H
#define _UAPI_ASM_RISCV_PTRACE_H

#ifndef __ASSEMBLY__

#include <linux/types.h>

/* RISCV CHERI specific requests. */
#define PTRACE_PEEKCAP            12
#define PTRACE_POKECAP            13

#define PTRACE_GETFDPIC		33

#define PTRACE_GETFDPIC_EXEC	0
#define PTRACE_GETFDPIC_INTERP	1

typedef __uptr __kernel_register_t;

/*
 * User-mode register state for core dumps, ptrace, sigcontext
 *
 * This decouples struct pt_regs from the userspace ABI.
 * struct user_regs_struct must form a prefix of struct pt_regs.
 */
struct user_regs_struct {
	__kernel_register_t pc;
	__kernel_register_t ra;
	__kernel_register_t sp;
	__kernel_register_t gp;
	__kernel_register_t tp;
	__kernel_register_t t0;
	__kernel_register_t t1;
	__kernel_register_t t2;
	__kernel_register_t s0;
	__kernel_register_t s1;
	__kernel_register_t a0;
	__kernel_register_t a1;
	__kernel_register_t a2;
	__kernel_register_t a3;
	__kernel_register_t a4;
	__kernel_register_t a5;
	__kernel_register_t a6;
	__kernel_register_t a7;
	__kernel_register_t s2;
	__kernel_register_t s3;
	__kernel_register_t s4;
	__kernel_register_t s5;
	__kernel_register_t s6;
	__kernel_register_t s7;
	__kernel_register_t s8;
	__kernel_register_t s9;
	__kernel_register_t s10;
	__kernel_register_t s11;
	__kernel_register_t t3;
	__kernel_register_t t4;
	__kernel_register_t t5;
	__kernel_register_t t6;
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
	/// UAPI: NoConvert: Does not exist in compat version
	__kernel_register_t ddc;
#endif
};

struct user_cap {
	__uptr val;
	__u8 tag;
	/// UAPI: NoConvert: Padding
	__u8 _pad[sizeof(__uptr) - 1];
};

struct __riscv_f_ext_state {
	__u32 f[32];
	__u32 fcsr;
};

struct __riscv_d_ext_state {
	__u64 f[32];
	__u32 fcsr;
};

struct __riscv_q_ext_state {
	__u64 f[64] __attribute__((aligned(16)));
	__u32 fcsr;
	/*
	 * Reserved for expansion of sigcontext structure.  Currently zeroed
	 * upon signal, and must be zero upon sigreturn.
	 */
	__u32 reserved[3];
};

struct __riscv_ctx_hdr {
	__u32 magic;
	__u32 size;
};

struct __riscv_extra_ext_header {
	__u32 __padding[129] __attribute__((aligned(16)));
	/*
	 * Reserved for expansion of sigcontext structure.  Currently zeroed
	 * upon signal, and must be zero upon sigreturn.
	 */
	__u32 reserved;
	struct __riscv_ctx_hdr hdr;
};

union __riscv_fp_state {
	struct __riscv_f_ext_state f;
	struct __riscv_d_ext_state d;
	struct __riscv_q_ext_state q;
};

struct __riscv_v_ext_state {
	unsigned long vstart;
	unsigned long vl;
	unsigned long vtype;
	unsigned long vcsr;
	unsigned long vlenb;
	void *datap;
	/*
	 * In signal handler, datap will be set a correct user stack offset
	 * and vector registers will be copied to the address of datap
	 * pointer.
	 */
};

struct __riscv_v_regset_state {
	unsigned long vstart;
	unsigned long vl;
	unsigned long vtype;
	unsigned long vcsr;
	unsigned long vlenb;
	char vreg[];
};

/*
 * According to spec: The number of bits in a single vector register,
 * VLEN >= ELEN, which must be a power of 2, and must be no greater than
 * 2^16 = 65536bits = 8192bytes
 */
#define RISCV_MAX_VLENB (8192)

#endif /* __ASSEMBLY__ */

#endif /* _UAPI_ASM_RISCV_PTRACE_H */
