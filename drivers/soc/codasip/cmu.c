// SPDX-License-Identifier: GPL-2.0
/*
 * Codasip Capability Management Unit (CMU) driver
 *
 * Copyright (c) 2026 Codasip GmbH. All rights reserved.
 *
 */

#include <linux/auxiliary_bus.h>
#include <linux/bitfield.h>
#include <linux/bitops.h>
#include <linux/bits.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/soc/codasip/cmu_pmu.h>
#include <linux/types.h>

#define CMU_VERSION_N_CBASE		0x0
#define CMU_FEATURES_VENDOR_ID		GENMASK_ULL(31, 0)
#define CMU_FEATURES_CBASE_ID		GENMASK_ULL(63, 32)

#define CMU_CONFIG_N_VERSION		0x8
#define CMU_FEATURES_CONFIG_ID		GENMASK_ULL(31, 0)
#define CMU_FEATURES_VERSION_ID		GENMASK_ULL(63, 32)

#define CMU_FEATURES			0x10
#define CMU_FEATURES_TS			BIT_ULL(0)
#define CMU_FEATURES_TC			BIT_ULL(1)
#define CMU_FEATURES_TG			BIT_ULL(2)
#define CMU_FEATURES_HPM		BIT_ULL(3)
#define CMU_FEATURES_RAS		BIT_ULL(4)
#define CMU_FEATURES_CLEN128		BIT_ULL(5)
#define CMU_FEATURES_AFG		GENMASK_ULL(11, 6)
#define CMU_FEATURES_LOG2AFTSZ		GENMASK_ULL(14, 12)
#define CMU_FEATURES_LOG2LMW_BYTE	GENMASK_ULL(17, 15)
#define CMU_FEATURES_LOG2LMSZ_KBYTE	GENMASK_ULL(21, 18)
#define CMU_FEATURES_LOG2TCLSZ_BYTE	GENMASK_ULL(25, 22)
#define CMU_FEATURES_PASZ		GENMASK_ULL(31, 26)
#define CMU_FEATURES_LOG2GCMB		GENMASK_ULL(34, 32)
#define CMU_FEATURES_AHBDW		BIT_ULL(35)
#define CMU_FEATURES_LOG2CSETS		GENMASK_ULL(39, 36)
#define CMU_FEATURES_LOG2CWAYS		GENMASK_ULL(41, 40)
#define CMU_FEATURES_RESERVED		GENMASK_ULL(63, 42)

#define CMU_FCTL			0x18
#define CMU_FCTL_GLOBALEN		BIT_ULL(0)
#define CMU_FCTL_LMWINLOCK		BIT_ULL(1)
#define CMU_FCTL_ETFT			GENMASK_ULL(3, 2)
#define CMU_FCTL_ETFT_ALL		0
#define CMU_FCTL_ETFT_HALF		1
#define CMU_FCTL_ETFT_QUARTER		2
#define CMU_FCTL_ETFT_ONE		3
#define CMU_FCTL_UXTB			GENMASK_ULL(5, 4)
#define CMU_FCTL_UXTB_DISABLE		0
#define CMU_FCTL_UXTB_IGNORE_WRITES	1
#define CMU_FCTL_UXTB_BUS_ERROR		2
#define CMU_FCTL_UXTB_INTERRUPT		3

#define CMU_FCTL_HPMLOCK		BIT_ULL(6)
#define CMU_FCTL_WCNTAREN		BIT_ULL(7)
#define CMU_FCTL_DTSW			BIT_ULL(8)
#define CMU_FCTL_DDTSA			BIT_ULL(9)

#define CMU_AFTELOCKS			0x20

#define CMU_IPSR			0x28
#define CMU_IPSR_PMIP			BIT_ULL(0)
#define CMU_IPSR_UAAGTI			BIT_ULL(1)
#define CMU_IPSR_WCNTARI		BIT_ULL(2)
#define CMU_IPSR_ERRI			BIT_ULL(3)
#define CMU_IPSR_ORLMAI			BIT_ULL(4)
#define CMU_IPSR_CORI			BIT_ULL(5)
#define CMU_IPSR_UXTI			BIT_ULL(6)
#define CMU_IPSR_TICI			BIT_ULL(7)

#define CMU_TCMO			0x30
#define CMU_TCMO_ACTIVATE		BIT_ULL(0)
#define CMU_TCMO_INVALIDATE		BIT_ULL(1)
#define CMU_TCMO_FLUSH			BIT_ULL(2)

#define CMU_TISTART			0x38

#define CMU_TIEND			0x40
#define CMU_TIEND_ACTIVATE		BIT_ULL(0)

#define CMU_LOCALMEMOFF			0x48

#define CMU_ISCTL			0x50
#define CMU_ISCTL_PMIP			GENMASK_ULL(1, 0)
#define CMU_ISCTL_UAAGTI		GENMASK_ULL(3, 2)
#define CMU_ISCTL_WCNTARI		GENMASK_ULL(5, 4)
#define CMU_ISCTL_ERRI			GENMASK_ULL(7, 6)
#define CMU_ISCTL_ORLMAI		GENMASK_ULL(9, 8)
#define CMU_ISCTL_CORI			GENMASK_ULL(11, 10)
#define CMU_ISCTL_UXTI			GENMASK_ULL(13, 12)
#define CMU_ISCTL_TICI			GENMASK_ULL(15, 14)
#define CMU_ISCTL_DISABLE		0
#define CMU_ISCTL_LOW_PRIORITY		1
#define CMU_ISCTL_HIGH_PRIORITY		2
#define CMU_ISCTL_RESERVED		3

#define CMU_HPMCNTOVF			0xa8

#define CMU_HPMCNTINH			0xb0

#define CMU_HPMCYCLES			0xb8

#define CMU_HPMCTR_BASE			0xc0
#define CMU_HPMCTR(n)			(CMU_HPMCTR_BASE + 8 * (n))

#define CMU_HPMEVT_BASE			0x1b8
#define CMU_HPMEVT(n)			(CMU_HPMEVT_BASE + 8 * (n))

#define CMU_AFTE_BASE			0x800
#define CMU_AFTE(n)			(0x800 + (n) * 32)

#define CMU_AFTE_FCTL			0x0
#define CMU_AFTE_FCTL_MODE		GENMASK_ULL(2, 0)
#define CMU_AFTE_FCTL_MODE_INVALID	0
#define CMU_AFTE_FCTL_MODE_EXTERNAL	1
#define CMU_AFTE_FCTL_MODE_CACHE	3
#define CMU_AFTE_FCTL_MODE_STASH	4
#define CMU_AFTE_FCTL_MODE_GROUP	7
#define CMU_AFTE_FCTL_NTAWEN		BIT_ULL(3)
#define CMU_AFTE_FCTL_GRPSETSZ		GENMASK_ULL(7, 4)

#define CMU_AFTE_ADDR			0x8
#define CMU_AFTE_GLOBALTBB		0x10
#define CMU_AFTE_LOCALTBB		0x18
#define CMU_AFTE_LOCALTBZ		0x1c

// Constants for magic numbers
#define CMU_REG_OFFSET_HIGH		4U
#define CMU_BITS_PER_WORD		32U
#define CMU_PAGE_SIZE_KB		1024U
#define CMU_PAGE_SIZE_4K		4096U
#define CMU_CACHE_SIZE_128B		128U
#define CMU_CACHE_SIZE_64B		64U
#define CMU_WORD_SIZE			4U
#define CMU_BYTE_TO_BIT_SHIFT		3U
#define CMU_ALIGN_4_BYTE		3U
#define CMU_ALIGN_8_BYTE		7U
#define CMU_QUAD_WORD_SIZE		8U
#define CMU_CLEN_BASE_BITS		6U
#define CMU_BITS_PER_BYTE		3U
#define CMU_WORD_ALIGN_MASK		3U

/*
 * 4K window allowing access to the locally attached SRAM block used for the
 * tags (stash mode) or group counters.
 */
#define CMU_LOCALMEMWIN			0x1000
#define CMU_LOCALMEMWIN_SIZE		0x1000

/* This is NOT the same scheme as used in the PMPs */
#define CMU_NAPOT(base, size)		(((base) + ((((size) >> 1) - 1))))

/* 8K is maximum possible size, excluding the RAS registers */
#define CMU_REGISTER_WINDOW_SIZE	(8 * 1024)

/* Tag regions have to be aligned on a minimum of a 4K boundary */
#define CMU_MIN_TAG_ALIGN		4096

struct cmu_info {
	/* How many address bits we decode - constrains region size */
	unsigned int granularity;

	/* How much local ram */
	unsigned int local_ram_size;

	/* How many sets we have */
	unsigned int num_sets;

	/* Line size in bytes */
	unsigned int line_size;

	u8 num_afte;

	/* How wide the local ram is */
	u8 local_ram_width;

	/* log2 of line cache line size in bits */
	u8 log2_line_size;

	/* Number of ways */
	u8 num_ways;

	/* Number of performance registers */
	u8 num_hpm_regs;

	/* How wide the bus to the CMU registers is */
	u8 ahb_width;

	/* Maximum size of group counters */
	u8 gcnt_max_bits;

	/* Does it support these modes ? True if supported */
	bool stash : 1, cache : 1, group : 1;
	bool hpm : 1, ras : 1;

	/* True if Capability size is 128 bits */
	bool clen128 : 1;
};

struct cmu_version {
	u32 vendor;
	u32 cbase;
	u32 config;
	u32 version;
};

struct cmu {
	struct device *dev;
	void __iomem *base;
	int irq_high;
	int irq_low;
	int id;

	struct cmu_version version;
	struct cmu_info info;

	struct codasip_cmu_pmu_adev *pmu_adev;
};

static void cmu_pmu_adev_release(struct device *dev)
{
	struct auxiliary_device *adev = to_auxiliary_dev(dev);
	struct codasip_cmu_pmu_adev *pmu_adev = adev_to_codasip_cmu_pmu_adev(adev);

	kfree(pmu_adev);
}

static void cmu_pmu_adev_interrupt_enable(struct cmu *cmu)
{
	u64 isctl;

	isctl = readq(cmu->base + CMU_ISCTL);

	FIELD_MODIFY(CMU_ISCTL_PMIP, &isctl, CMU_ISCTL_LOW_PRIORITY);

	writeq(isctl, cmu->base + CMU_ISCTL);
}

static struct auxiliary_device *cmu_pmu_adev_alloc(struct cmu *cmu)
{
	struct auxiliary_device *adev;
	int ret;

	cmu->pmu_adev = kzalloc_obj(*cmu->pmu_adev, GFP_KERNEL);
	if (!cmu->pmu_adev)
		return ERR_PTR(-ENOMEM);

	cmu->pmu_adev->ipsr = cmu->base + CMU_IPSR;
	cmu->pmu_adev->hpmcntovf = cmu->base + CMU_HPMCNTOVF;
	cmu->pmu_adev->hpmcntinh = cmu->base + CMU_HPMCNTINH;
	cmu->pmu_adev->hpmcycles = cmu->base + CMU_HPMCYCLES;
	cmu->pmu_adev->hpmctr_base = cmu->base + CMU_HPMCTR_BASE;
	cmu->pmu_adev->hpmevt_base = cmu->base + CMU_HPMEVT_BASE;

	cmu->pmu_adev->irq = cmu->irq_low;
	cmu->pmu_adev->num_hpm_regs = cmu->info.num_hpm_regs;

	adev = &cmu->pmu_adev->adev;
	adev->name = "pmu";
	adev->dev.parent = cmu->dev;
	adev->dev.release = cmu_pmu_adev_release;
	adev->id = cmu->id;

	cmu_pmu_adev_interrupt_enable(cmu);

	ret = auxiliary_device_init(adev);
	if (ret) {
		kfree(cmu->pmu_adev);
		cmu->pmu_adev = NULL;
		return ERR_PTR(ret);
	}

	return adev;
}

static int cmu_pmu_adev_register(struct cmu *cmu)
{
	struct auxiliary_device *adev;
	int ret;

	adev = cmu_pmu_adev_alloc(cmu);
	if (IS_ERR(adev))
		return PTR_ERR(adev);

	ret = auxiliary_device_add(adev);
	if (ret) {
		auxiliary_device_uninit(adev);
		cmu->pmu_adev = NULL;
	}

	return ret;
}

static void cmu_pmu_adev_unregister(struct cmu *cmu)
{
	struct auxiliary_device *adev = &cmu->pmu_adev->adev;

	auxiliary_device_delete(adev);
	auxiliary_device_uninit(adev);
}

static void cmu_get_version(struct cmu *cmu)
{
	struct cmu_version *version = &cmu->version;
	u64 vendor_cbase = readq(cmu->base + CMU_VERSION_N_CBASE);
	u64 config_version = readq(cmu->base + CMU_CONFIG_N_VERSION);

	version->vendor = FIELD_GET(CMU_FEATURES_VENDOR_ID, vendor_cbase);
	version->cbase = FIELD_GET(CMU_FEATURES_CBASE_ID, vendor_cbase);
	version->config = FIELD_GET(CMU_FEATURES_CONFIG_ID, config_version);
	version->version = FIELD_GET(CMU_FEATURES_VERSION_ID, config_version);
}

static void cmu_get_features(struct cmu *cmu)
{
	struct cmu_info *info = &cmu->info;
	u64 features = readq(cmu->base + CMU_FEATURES);

	info->num_afte = 1 << FIELD_GET(CMU_FEATURES_LOG2AFTSZ, features);
	info->clen128 = FIELD_GET(CMU_FEATURES_CLEN128, features);
	info->stash = FIELD_GET(CMU_FEATURES_TS, features);
	info->cache = FIELD_GET(CMU_FEATURES_TC, features);
	info->group = FIELD_GET(CMU_FEATURES_TG, features);
	info->ras = FIELD_GET(CMU_FEATURES_RAS, features);
	info->hpm = FIELD_GET(CMU_FEATURES_HPM, features);
	info->granularity = 1 << FIELD_GET(CMU_FEATURES_AFG, features);
	info->log2_line_size = FIELD_GET(CMU_FEATURES_LOG2TCLSZ_BYTE, features)
				+ CMU_BYTE_TO_BIT_SHIFT; /* line size in BITS */
	info->line_size = (1 << info->log2_line_size) >> CMU_BYTE_TO_BIT_SHIFT;
	info->local_ram_size = (1 << FIELD_GET(CMU_FEATURES_LOG2LMSZ_KBYTE, features))
				* CMU_PAGE_SIZE_KB;
	info->local_ram_width = 1 << FIELD_GET(CMU_FEATURES_LOG2LMW_BYTE, features);
	info->num_hpm_regs = info->hpm ?
				hweight64(readq(cmu->base + CMU_HPMCNTINH)) - 1 : 0;
	info->num_ways = 1 << FIELD_GET(CMU_FEATURES_LOG2CWAYS, features);
	info->num_sets = 1 << FIELD_GET(CMU_FEATURES_LOG2CSETS, features);
	info->ahb_width = CMU_BITS_PER_WORD << FIELD_GET(CMU_FEATURES_AHBDW, features);
	info->gcnt_max_bits = 1 << FIELD_GET(CMU_FEATURES_LOG2GCMB, features);
}

static int cmu_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct cmu *cmu;

	cmu = devm_kzalloc(dev, sizeof(*cmu), GFP_KERNEL);
	if (!cmu)
		return -ENOMEM;

	cmu->dev = dev;

	cmu->base = devm_platform_ioremap_resource(pdev, 0);
	if (IS_ERR(cmu->base))
		return PTR_ERR(cmu->base);

	cmu->irq_high = platform_get_irq_byname(pdev, "high");
	if (cmu->irq_high < 0)
		return cmu->irq_high;

	cmu->irq_low = platform_get_irq_byname(pdev, "low");
	if (cmu->irq_low < 0)
		return cmu->irq_low;

	cmu->id = of_alias_get_id(dev->of_node, "cmu");
	if (cmu->id < 0)
		return cmu->id;

	cmu_get_version(cmu);
	cmu_get_features(cmu);

	if (cmu->info.hpm) {
		if (cmu_pmu_adev_register(cmu))
			dev_warn(dev, "register pmu auxiliary device failed\n");
		else
			dev_info(dev, "pmu auxiliary device registered\n");
	}

	platform_set_drvdata(pdev, cmu);

	return 0;
}

static void cmu_remove(struct platform_device *pdev)
{
	struct cmu *cmu = platform_get_drvdata(pdev);

	if (cmu->pmu_adev)
		cmu_pmu_adev_unregister(cmu);
}

static const struct of_device_id codasip_cmu_of_match[] = {
	{ .compatible = "codasip,codasip-cmu", },
	{ }
};
MODULE_DEVICE_TABLE(of, codasip_cmu_of_match);

static struct platform_driver codasip_cmu_driver = {
	.probe = cmu_probe,
	.remove = cmu_remove,
	.driver = {
		.name = "codasip-cmu",
		.of_match_table = codasip_cmu_of_match,
	},
};
module_platform_driver(codasip_cmu_driver);

MODULE_DESCRIPTION("Codasip Capability Management Unit Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ka Leung Ho <ka.ho@codasip.com>");
