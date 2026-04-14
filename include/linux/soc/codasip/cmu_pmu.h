/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026 Codasip GmbH. All rights reserved.
 */

#ifndef _LINUX_SOC_CODASIP_CMU_H
#define _LINUX_SOC_CODASIP_CMU_H

#include <linux/auxiliary_bus.h>

struct codasip_cmu_pmu_adev {
	struct auxiliary_device adev;
	void __iomem *ipsr;
	void __iomem *hpmcntovf;
	void __iomem *hpmcntinh;
	void __iomem *hpmcycles;
	void __iomem *hpmctr_base;
	void __iomem *hpmevt_base;
	int irq;
	int num_hpm_regs;
};

#define adev_to_codasip_cmu_pmu_adev(pmu_adev) \
			container_of_const(pmu_adev, struct codasip_cmu_pmu_adev, adev)

#endif
