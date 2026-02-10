// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* memcmp benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static int (*mymemcmp)(const void *, const void *, size_t);

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x123456789 },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x234567890 },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 255, .xseed = 0x345678910 };

static void
domemcmpbench(const char *bufa, const char *bufb, const char **ptrs)
{
	volatile int result = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		result += mymemcmp(ptrs[i], bufb + (ptrs[i] - bufa), (size_t)(ptrs[i+1] - ptrs[i]));
}

static void
memcmpbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *src, *dest;
	const char **ptrs;
	long i;

	param = payload;
	b->bytes = param->buflen;
	src = gentests(param);
	ptrs = (const char **)mkpointers(NULL, src, param->buflen);
	dest = kmalloc(param->buflen, GFP_KERNEL | __GFP_ZERO);
	if (dest == NULL)
		return;

	memcpy(dest, src, param->buflen);
	domemcmpbench(src, dest, ptrs);

	resettimer(b);
	for (i = 0; i < b->n; i++)
		domemcmpbench(src, dest, ptrs);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
	kfree(src);
}

extern void
strperf_memcmp(void)
{
	mymemcmp = memcmp;
	runbenchmark("memcmpShort", memcmpbench, (void *)&shortparam);
	runbenchmark("memcmpMid", memcmpbench, (void *)&midparam);
	runbenchmark("memcmpLong", memcmpbench, (void *)&longparam);

	mymemcmp = bcmp;
	runbenchmark("bcmpShort", memcmpbench, (void *)&shortparam);
	runbenchmark("bcmpMid", memcmpbench, (void *)&midparam);
	runbenchmark("bcmpLong", memcmpbench, (void *)&longparam);

#ifdef __FreeBSD__
	mymemcmp = timingsafe_bcmp;
	runbenchmark("tsBcmpShort", memcmpbench, (void *)&shortparam);
	runbenchmark("tsBcmpMid", memcmpbench, (void *)&midparam);
	runbenchmark("tsBcmpLong", memcmpbench, (void *)&longparam);

	mymemcmp = timingsafe_memcmp;
	runbenchmark("tsMemcmpShort", memcmpbench, (void *)&shortparam);
	runbenchmark("tsMemcmpMid", memcmpbench, (void *)&midparam);
	runbenchmark("tsMemcmpLong", memcmpbench, (void *)&longparam);
#endif
}
