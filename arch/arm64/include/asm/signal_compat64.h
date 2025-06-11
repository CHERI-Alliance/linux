/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2022 ARM Ltd.
 */
#ifndef __ASM_SIGNAL_COMPAT64_H
#define __ASM_SIGNAL_COMPAT64_H

#ifdef CONFIG_COMPAT64
#include <linux/compat.h>

int compat_setup_rt_frame(int usig, struct ksignal *ksig, sigset_t *set,
			  struct pt_regs *regs);
#else /* !CONFIG_COMPAT64 */
static inline int compat_setup_rt_frame(int usig, struct ksignal *ksig, sigset_t *set,
					struct pt_regs *regs)
{
	return -ENOSYS;
}
#endif
#endif /* __ASM_SIGNAL_COMPAT64_H */
