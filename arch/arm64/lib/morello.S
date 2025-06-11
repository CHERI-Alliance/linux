/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */

#include <linux/linkage.h>

#include <asm/assembler.h>
#include <asm/sysreg.h>

SYM_FUNC_START(morello_cpu_setup)
	/* Disable trapping of Morello instructions */
	mrs	x0, cpacr_el1
	orr	x0, x0, CPACR_EL1_CEN
	msr	cpacr_el1, x0
	isb

	/* Disable PCC/DDC base offset and other capability-related features */
	msr	cctlr_el1, xzr
	/*
	 * Now that trapping is disabled, capability exception entry is enabled
	 * and therefore CVBAR_EL1 needs to be set to a valid capability
	 * (derived from PCC).
	 */
	mrs	x0, vbar_el1
	cvtp	c0, x0
	msr	cvbar_el1, c0
	isb

	ret
SYM_FUNC_END(morello_cpu_setup)
