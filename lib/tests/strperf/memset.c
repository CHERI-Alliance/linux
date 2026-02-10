// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2024 Strahinja Stanisic <strajabot@FreeBSD.org>
 */

/* memset benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam
    param40   = { .avglen = 40,   .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0x234567890ULL },
    param168  = { .avglen = 168,  .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0x33368176fa5eULL },
    param2k   = { .avglen = 2048, .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0x13374223f001ULL },
    param256k = { .avglen = 1000000, .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0xdeadbeeffee1ULL },
    param16m  = { .avglen = 1000000, .buflen = 1 << 20, .charlen = 16, .maxchar = 127, .xseed = 0xc0fef00db01dULL },
    param1g   = { .avglen = 1000000, .buflen = 1 << 20, .charlen = 16, .maxchar = 127, .xseed = 0x471131254096ULL };

static void
domemsetbench(void **ptrs, char *dest, size_t n)
{
	size_t i;
	void *src;

	src = ptrs[0];
	for (i = 0; i < n; i++)
		memset(dest + (ptrs[i] - src), '1', (size_t)(ptrs[i + 1] - ptrs[i]));
}

static void
memsetbench(struct B *b, void *payload)
{
	struct testparam *param;
	size_t n;
	long i;
	void **ptrs;
	char *dest;

	param = payload;
	b->bytes = param->buflen;
	ptrs = genmemtests(param, &n);
	dest = kmalloc(param->buflen, GFP_KERNEL);
	if (dest == NULL)
		return;

	domemsetbench(ptrs, dest, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		domemsetbench(ptrs, dest, n);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
}

extern void
strperf_memset(void)
{
	runbenchmark("40", memsetbench, (void *)&param40);
	runbenchmark("168", memsetbench, (void *)&param168);
	runbenchmark("2k", memsetbench, (void *)&param2k);
	runbenchmark("256k", memsetbench, (void *)&param256k);
	runbenchmark("16m", memsetbench, (void *)&param16m);
	runbenchmark("1g", memsetbench, (void *)&param1g);
}
