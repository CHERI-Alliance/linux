/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_PTRACE_H
#define _ASM_RISCV_PTRACE_H

#include <uapi/asm/ptrace.h>
#include <asm/csr.h>
#include <linux/compiler.h>

#ifndef __ASSEMBLY__

typedef __kernel_register_t register_t;

struct pt_regs {
	register_t epc;
	register_t ra;
	register_t sp;
	register_t gp;
	register_t tp;
	register_t t0;
	register_t t1;
	register_t t2;
	register_t s0;
	register_t s1;
	struct_group(a_regs,
		register_t a0;
		register_t a1;
		register_t a2;
		register_t a3;
		register_t a4;
		register_t a5;
		register_t a6;
		register_t a7;
	);
	register_t s2;
	register_t s3;
	register_t s4;
	register_t s5;
	register_t s6;
	register_t s7;
	register_t s8;
	register_t s9;
	register_t s10;
	register_t s11;
	register_t t3;
	register_t t4;
	register_t t5;
	register_t t6;
#ifdef CONFIG_CHERI_KERNEL
	register_t ddc;
#endif
	/* a0 value before the syscall */
	register_t orig_a0;
	/* Supervisor/Machine CSRs */
	unsigned long status;
	unsigned long badaddr;
	unsigned long cause;
#ifdef CONFIG_CHERI_KERNEL
	unsigned long _pad;
#endif
};

#define PTRACE_SYSEMU			0x1f
#define PTRACE_SYSEMU_SINGLESTEP	0x20

#ifdef CONFIG_64BIT
#define REG_FMT "%016lx"
#else
#define REG_FMT "%08lx"
#endif

#ifdef CONFIG_CHERI_KERNEL
#define CREG_FMT "%#p"
#else
#define CREG_FMT "%p"
#endif

#define user_mode(regs) (((regs)->status & SR_PP) == 0)

#define MAX_REG_OFFSET offsetof(struct pt_regs, orig_a0)

/* Helpers for working with the instruction pointer */
static inline register_t instruction_pointer(struct pt_regs *regs)
{
	return regs->epc;
}
static inline void instruction_pointer_set(struct pt_regs *regs,
					   register_t val)
{
	regs->epc = val;
}

#define profile_pc(regs) instruction_pointer(regs)

/* Helpers for working with the user stack pointer */
static inline register_t user_stack_pointer(struct pt_regs *regs)
{
	return regs->sp;
}
static inline void user_stack_pointer_set(struct pt_regs *regs,
					  register_t val)
{
	regs->sp =  val;
}

/* Valid only for Kernel mode traps. */
static inline register_t kernel_stack_pointer(struct pt_regs *regs)
{
	return regs->sp;
}

/* Helpers for working with the frame pointer */
static inline register_t frame_pointer(struct pt_regs *regs)
{
	return regs->s0;
}
static inline void frame_pointer_set(struct pt_regs *regs,
				     register_t val)
{
	regs->s0 = val;
}

static inline register_t regs_return_value(struct pt_regs *regs)
{
	return regs->a0;
}

static inline void regs_set_return_value(struct pt_regs *regs,
					 register_t val)
{
	regs->a0 = val;
}

extern int regs_query_register_offset(const char *name);
extern unsigned long regs_get_kernel_stack_nth(struct pt_regs *regs,
					       unsigned int n);

void prepare_ftrace_return(uintptr_t *parent, unsigned long self_addr,
			   unsigned long frame_pointer);

/**
 * regs_get_register() - get register value from its offset
 * @regs:	pt_regs from which register value is gotten
 * @offset:	offset of the register.
 *
 * regs_get_register returns the value of a register whose offset from @regs.
 * The @offset is the offset of the register in struct pt_regs.
 * If @offset is bigger than MAX_REG_OFFSET, this returns 0.
 */
static inline register_t regs_get_register(struct pt_regs *regs,
					   unsigned int offset)
{
	if (unlikely(offset > MAX_REG_OFFSET))
		return 0;

	return *(register_t *)((uintptr_t)regs + offset);
}

/**
 * regs_get_kernel_argument() - get Nth function argument in kernel
 * @regs:       pt_regs of that context
 * @n:          function argument number (start from 0)
 *
 * regs_get_argument() returns @n th argument of the function call.
 *
 * Note you can get the parameter correctly if the function has no
 * more than eight arguments.
 */
static inline register_t regs_get_kernel_argument(struct pt_regs *regs,
						  unsigned int n)
{
	static const int nr_reg_arguments = 8;
	static const unsigned int argument_offs[] = {
		offsetof(struct pt_regs, a0),
		offsetof(struct pt_regs, a1),
		offsetof(struct pt_regs, a2),
		offsetof(struct pt_regs, a3),
		offsetof(struct pt_regs, a4),
		offsetof(struct pt_regs, a5),
		offsetof(struct pt_regs, a6),
		offsetof(struct pt_regs, a7),
	};

	if (n < nr_reg_arguments)
		return regs_get_register(regs, argument_offs[n]);
	return 0;
}

static __always_inline bool regs_irqs_disabled(struct pt_regs *regs)
{
	return !(regs->status & SR_PIE);
}

#endif /* __ASSEMBLY__ */

#endif /* _ASM_RISCV_PTRACE_H */
