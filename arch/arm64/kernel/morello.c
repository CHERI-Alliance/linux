/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */

#define pr_fmt(fmt) "morello: " fmt

#include <linux/cache.h>
#include <linux/printk.h>

#include <asm/cpufeature.h>
#include <asm/morello.h>
#include <asm/ptrace.h>

/* Private functions implemented in morello.S */
void __morello_cap_lo_hi_tag(const cap128_t *cap, u64 *lo_val, u64 *hi_val,
			     u8 *tag);
void __morello_cap_cpy(cap128_t *dst, const cap128_t *src);
void __morello_merge_c_x(cap128_t *creg, u64 xreg);
void __morello_get_ddc(cap128_t *dst);

/* Not defined as static because morello.S refers to it */
cap128_t morello_root_cap __ro_after_init;

/* DDC_ELx reset value (low/high 64 bits), as defined in the Morello spec */
#define DDC_RESET_VAL_LOW_64	0x0
#define DDC_RESET_VAL_HIGH_64	0xffffc00000010005ULL

static void init_pc_pcc(struct pt_regs *regs, unsigned long pc)
{
	/*
	 * Set PCC to the root capability. There is no need to set its value to
	 * pc, this will be taken care of when PC is merged into PCC during
	 * ret_to_user.
	 */
	__morello_cap_cpy(&regs->pcc, &morello_root_cap);

	if (pc & 0x1) {
		/*
		 * The LSB of the entry point is set, start the thread in the
		 * C64 ISA by setting PSTATE.C64. Unlike T32 in AArch32, the
		 * architecture also requires PC's LSB to be cleared.
		 */
		regs->pstate |= PSR_C64_BIT;
		regs->pc = pc & ~0x1;
	}
}

void morello_thread_start(struct pt_regs *regs, unsigned long pc)
{
	init_pc_pcc(regs, pc);
}

void morello_setup_signal_return(struct pt_regs *regs)
{
	/*
	 * Setup PC/PCC for the signal handler like for the program's entry
	 * point (this means in particular that the signal handler is invoked in
	 * Executive).
	 */
	init_pc_pcc(regs, regs->pc);

	/*
	 * Also set CLR to a valid capability, to allow a C64 handler to return
	 * to the trampoline using `ret clr`.
	 */
	__morello_cap_cpy(&regs->cregs[30], &morello_root_cap);
}

void morello_merge_cap_regs(struct pt_regs *regs)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(regs->cregs); i++)
		__morello_merge_c_x(&regs->cregs[i], regs->regs[i]);

	__morello_merge_c_x(&regs->csp, regs->sp);
	__morello_merge_c_x(&regs->pcc, regs->pc);
}


static void __init check_root_cap(const cap128_t *cap)
{
	u64 lo_val, hi_val;
	u8 tag;

	__morello_cap_lo_hi_tag(cap, &lo_val, &hi_val, &tag);

	/*
	 * Check that DDC has the reset value, otherwise morello_root_cap and
	 * all capabilities derived from it (especially those exposed to
	 * userspace) may not be reliable.
	 */
	if (!(tag == 1 &&
	      lo_val == DDC_RESET_VAL_LOW_64 &&
	      hi_val == DDC_RESET_VAL_HIGH_64))
		pr_warn("DDC does not have its reset value, this may be a firmware bug\n");
}

static int __init morello_cap_init(void)
{
	if (!system_supports_morello())
		return 0;

	__morello_get_ddc(&morello_root_cap);

	check_root_cap(&morello_root_cap);

	return 0;
}
arch_initcall(morello_cap_init);
