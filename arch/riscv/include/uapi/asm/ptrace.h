/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _UAPI_ASM_RISCV_PTRACE_H
#define _UAPI_ASM_RISCV_PTRACE_H

#ifndef __ASSEMBLER__

#include <linux/types.h>

/* RISCV CHERI specific requests. */
#define PTRACE_PEEKCAP            12
#define PTRACE_POKECAP            13

#define PTRACE_GETFDPIC		33

#define PTRACE_GETFDPIC_EXEC	0
#define PTRACE_GETFDPIC_INTERP	1

/*
 * User-mode register state for core dumps, ptrace, sigcontext
 *
 * This decouples struct pt_regs from the userspace ABI.
 * struct user_regs_struct must form a prefix of struct pt_regs.
 */
struct user_regs_struct {
	__uptr pc;
	__uptr ra;
	__uptr sp;
	__uptr gp;
	__uptr tp;
	__uptr t0;
	__uptr t1;
	__uptr t2;
	__uptr s0;
	__uptr s1;
	__uptr a0;
	__uptr a1;
	__uptr a2;
	__uptr a3;
	__uptr a4;
	__uptr a5;
	__uptr a6;
	__uptr a7;
	__uptr s2;
	__uptr s3;
	__uptr s4;
	__uptr s5;
	__uptr s6;
	__uptr s7;
	__uptr s8;
	__uptr s9;
	__uptr s10;
	__uptr s11;
	__uptr t3;
	__uptr t4;
	__uptr t5;
	__uptr t6;
#if defined(__ARCH_WANT_PURECAP) || defined(__CHERI_PURE_CAPABILITY__)
	/// UAPI: NoConvert: Does not exist in compat version
	__uptr ddc;
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

#endif /* __ASSEMBLER__ */

#endif /* _UAPI_ASM_RISCV_PTRACE_H */
