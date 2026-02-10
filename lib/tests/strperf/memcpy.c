// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* memcpy benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam
    param64   = { .avglen = 1 <<  6, .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0x234567890ULL },
    param4k   = { .avglen = 1 << 12, .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0x13374223f001ULL },
    param256k = { .avglen = 1000000, .buflen = 1 << 18, .charlen = 1, .maxchar = 127, .xseed = 0xdeadbeeffee1ULL },
    param16m  = { .avglen = 1000000, .buflen = 1 << 20, .charlen = 16, .maxchar = 127, .xseed = 0xc0fef00db01dULL },
    param1g   = { .avglen = 1000000, .buflen = 1 << 20, .charlen = 16, .maxchar = 127, .xseed = 0x471131254096 };

static void
domemcpybench(void **ptrs, char *dest, size_t n)
{
	size_t i;
	void *src;

	src = ptrs[0];
	for (i = 0; i < n; i++)
		memcpy(dest + (ptrs[i] - src), src, (size_t)(ptrs[i + 1] - ptrs[i]));
}

static void
memcpybench(struct B *b, void *payload)
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

	domemcpybench(ptrs, dest, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		domemcpybench(ptrs, dest, n);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
}

extern void
strperf_memcpy(void)
{
	runbenchmark("64", memcpybench, (void *)&param64);
	runbenchmark("4k", memcpybench, (void *)&param4k);
	runbenchmark("256k", memcpybench, (void *)&param256k);
	runbenchmark("16m", memcpybench, (void *)&param16m);
	runbenchmark("1g", memcpybench, (void *)&param1g);
}
