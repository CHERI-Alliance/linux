/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Arm Ltd.
 */

#define pr_fmt(fmt) "morello: " fmt

#include <linux/cache.h>
#include <linux/printk.h>

#include <asm/cpufeature.h>
#include <asm/morello.h>

/* Private functions implemented in morello.S */
void __morello_cap_lo_hi_tag(const cap128_t *cap, u64 *lo_val, u64 *hi_val,
			     u8 *tag);
void __morello_get_ddc(cap128_t *dst);

/* Not defined as static because morello.S refers to it */
cap128_t morello_root_cap __ro_after_init;

/* DDC_ELx reset value (low/high 64 bits), as defined in the Morello spec */
#define DDC_RESET_VAL_LOW_64	0x0
#define DDC_RESET_VAL_HIGH_64	0xffffc00000010005ULL

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
