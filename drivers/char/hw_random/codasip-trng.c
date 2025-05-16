// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2024 Codasip GmbH
 */

#include <linux/hw_random.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/printk.h>
#include <linux/clk.h>
#include <linux/reset.h>

#define TRNG_RAW	0x0	/* RAW TERO data */
#define TRNG_RAWN	0x4	/* Number of RAW samples in the FIFO */
#define TRNG_RND	0x8	/* Processed TERO data */
#define TRNG_RNDN	0xC	/* Number of processed samples in the FIFO */
#define TRNG_CONFIG	0x10	/* Hardware configuration */
#define TRNG_STATUS	0x14	/* The error count */

struct codasip_trng_priv {
	struct hwrng rng;
	void __iomem *base;
};

static inline struct codasip_trng_priv *to_trng_priv(struct hwrng *rng)
{
	return container_of(rng, struct codasip_trng_priv, rng);
}

static int codasip_trng_read(struct hwrng *rng, void *buf, size_t max,
			       bool wait)
{
	struct codasip_trng_priv *priv = to_trng_priv(rng);
	u32 max_words = max / sizeof(u32);
	u32 num_words, count;

	while ((num_words = readl(priv->base + TRNG_RNDN)) == 0) {
		if (!wait)
			return 0;
		hwrng_yield(rng);
	}

	if (num_words > max_words)
		num_words = max_words;

	for (count = 0; count < num_words; count++)
		((u32 *)buf)[count] = readl(priv->base + TRNG_RND);

	return num_words * sizeof(u32);
}

static const struct of_device_id codasip_trng_of_match[] = {
	{ .compatible = "codasip,codasip-rng"},
	{},
};

static int codasip_trng_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct codasip_trng_priv *priv;
	int err;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->base = devm_platform_ioremap_resource(pdev, 0);
	if (IS_ERR(priv->base))
		return PTR_ERR(priv->base);

	priv->rng.name = pdev->name;
	priv->rng.read = codasip_trng_read;

	err = devm_hwrng_register(dev, &priv->rng);
	if (err)
		dev_err(dev, "hwrng registration failed\n");
	else
		dev_info(dev, "hwrng registered\n");

	return err;
}

MODULE_DEVICE_TABLE(of, codasip_trng_of_match);

static const struct platform_device_id codasip_trng_devtype[] = {
	{ .name = "codasip-rng" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(platform, codasip_trng_devtype);

static struct platform_driver codasip_trng_driver = {
	.driver = {
		.name = "codasip-trng",
		.of_match_table = codasip_trng_of_match,
	},
	.probe		= codasip_trng_probe,
	.id_table	= codasip_trng_devtype,
};
module_platform_driver(codasip_trng_driver);

MODULE_AUTHOR("Stuart Menefy <stuart.menefy@codasip.com>");
MODULE_DESCRIPTION("Codasip True Random Number Generator (TRNG) driver");
MODULE_LICENSE("GPL");
