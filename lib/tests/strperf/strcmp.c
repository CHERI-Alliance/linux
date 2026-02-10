// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strcmp benchmark */

#include <linux/kernel.h>
#include <linux/sort.h>

#include "benchmark.h"

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 16, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 16, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 16, .xseed = 0x345678910ULL };

static void
dostrcmpbench(const char *bufa, const char *bufb, const char **ptrs)
{
	volatile int result = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		result += strcmp(ptrs[i], bufb + (ptrs[i] - bufa));
}

static void
strcmpbench(struct B *b, void *payload)
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
	dostrcmpbench(src, dest, ptrs);

	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrcmpbench(src, dest, ptrs);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
	kfree(src);
}

static void
dostrcmpbenchu(const char *src, const char *dest, const char **ptrs)
{
	volatile int result = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		result += strcmp(ptrs[i], dest + (ptrs[i] - src) + i + 1);
}

static void
strcmpbenchu(struct B *b, void *payload)
{
	struct testparam *param;
	size_t nstr, j;
	char *src, *dest, *p;
	const char **ptrs;
	long i;

	param = payload;
	b->bytes = param->buflen;
	src = gentests(param);
	ptrs = (const char **)mkpointers(&nstr, src, param->buflen);
	dest = kmalloc(param->buflen + nstr, GFP_KERNEL | __GFP_ZERO);
	if (dest == NULL)
		return;

	for (j = 0, p = dest; j < nstr; j++)
		p = stpcpy(p + 1, ptrs[j]) + 1;

	dostrcmpbenchu(src, dest, ptrs);

	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrcmpbenchu(src, dest, ptrs);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
	kfree(src);
}

static int
strcmp_compar(const void *a, const void *b)
{
	return (strcmp(*(char **)a, *(char **)b));
}

static void
strcmpqsort(struct B *b, void *payload)
{
	struct testparam *param;
	size_t nstr;
	char *src;
	const char **orig, **ptrs;
	long i;

	param = payload;
	b->bytes = param->buflen;
	src = gentests(param);
	orig = (const char **)mkpointers(&nstr, src, param->buflen);
	ptrs = kmalloc(nstr * sizeof *ptrs, GFP_KERNEL | __GFP_ZERO);
	if (ptrs == NULL)
		return;

	memcpy(ptrs, orig, nstr * sizeof *ptrs);
	sort(ptrs, nstr, sizeof *ptrs, strcmp_compar, NULL);

	resettimer(b);
	for (i = 0; i < b->n; i++) {
		stoptimer(b);
		memcpy(ptrs, orig, nstr * sizeof *ptrs);
		starttimer(b);
		sort(ptrs, nstr, sizeof *ptrs, strcmp_compar, NULL);
	}
	stoptimer(b);

	kfree(ptrs);
	kfree(orig);
	kfree(src);
}

extern void
strperf_strcmp(void)
{
	/* benchmark with equal alignment */
	runbenchmark("ShortAligned", strcmpbench, (void *)&shortparam);
	runbenchmark("MidAligned", strcmpbench, (void *)&midparam);
	runbenchmark("LongAligned", strcmpbench, (void *)&longparam);

	/* benchmark with unequal alignment */
	runbenchmark("ShortUnaligned", strcmpbenchu, (void *)&shortparam);
	runbenchmark("MidUnaligned", strcmpbenchu, (void *)&midparam);
	runbenchmark("LongUnaligned", strcmpbenchu, (void *)&longparam);

	/* sort benchmarks */
	runbenchmark("ShortQsort", strcmpqsort, (void *)&shortparam);
	runbenchmark("MidQsort", strcmpqsort, (void *)&midparam);
}
