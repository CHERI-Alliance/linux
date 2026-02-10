// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strncmp benchmark */

#include <linux/kernel.h>
#include <linux/sort.h>

#include "benchmark.h"

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 16, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 16, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 16, .xseed = 0x345678910ULL };

static void
dostrncmpbench(const char *bufa, const char *bufb, const char **ptrs)
{
	volatile int result = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		result += strncmp(ptrs[i], bufb + (ptrs[i] - bufa), (size_t)(ptrs[i+1] - ptrs[i]));
}

static void
strncmpbench(struct B *b, void *payload)
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
	dostrncmpbench(src, dest, ptrs);

	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrncmpbench(src, dest, ptrs);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
	kfree(src);
}

static void
dostrncmpbenchu(const char *src, const char *dest, const char **ptrs)
{
	volatile int result = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		result += strncmp(ptrs[i], dest + (ptrs[i] - src) + i + 1, (size_t)(ptrs[i+1] - ptrs[i]));
}

static void
strncmpbenchu(struct B *b, void *payload)
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

	dostrncmpbenchu(src, dest, ptrs);

	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrncmpbenchu(src, dest, ptrs);
	stoptimer(b);

	kfree(dest);
	kfree(ptrs);
	kfree(src);
}

struct string {
	const char *buf;
	size_t len;
};

static int
strncmp_compar(const void *a, const void *b)
{
	const struct string *A = a, *B = b;

	/* purposefully be asymmetric */
	return (strncmp(A->buf, B->buf, A->len));
}

static void
strncmpqsort(struct B *b, void *payload)
{
	struct testparam *param;
	struct string *strings;
	size_t nstr, j;
	char *src;
	const char **orig;
	long i;

	param = payload;
	b->bytes = param->buflen;
	src = gentests(param);
	orig = (const char **)mkpointers(&nstr, src, param->buflen);
	strings = kmalloc(nstr * sizeof *strings, GFP_KERNEL | __GFP_ZERO);
	if (strings == NULL)
		return;

	for (j = 0; j < nstr; j++) {
		strings[j].buf = orig[j];
		strings[j].len = (size_t)(orig[j+1] - orig[j]);
	}
	sort(strings, nstr, sizeof *strings, strncmp_compar, NULL);

	resettimer(b);
	for (i = 0; i < b->n; i++) {
		stoptimer(b);
		for (j = 0; j < nstr; j++) {
			strings[j].buf = orig[j];
			strings[j].len = (size_t)(orig[j+1] - orig[j]);
		}
		starttimer(b);
		sort(strings, nstr, sizeof *strings, strncmp_compar, NULL);
	}
	stoptimer(b);

	kfree(strings);
	kfree(orig);
	kfree(src);
}

extern void
strperf_strncmp(void)
{
	/* benchmark with equal alignment */
	runbenchmark("ShortAligned", strncmpbench, (void *)&shortparam);
	runbenchmark("MidAligned", strncmpbench, (void *)&midparam);
	runbenchmark("LongAligned", strncmpbench, (void *)&longparam);

	/* benchmark with unequal alignment */
	runbenchmark("ShortUnaligned", strncmpbenchu, (void *)&shortparam);
	runbenchmark("MidUnaligned", strncmpbenchu, (void *)&midparam);
	runbenchmark("LongUnaligned", strncmpbenchu, (void *)&longparam);

	/* qsort benchmarks */
	runbenchmark("ShortQsort", strncmpqsort, (void *)&shortparam);
	runbenchmark("MidQsort", strncmpqsort, (void *)&midparam);
}
