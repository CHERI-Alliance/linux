// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* memchr benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x123456789 },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x234567890 },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 127, .xseed = 0x345678910 };

static void
domemchrbench(void **ptrs, size_t n)
{
	volatile uintptr_t accum = 0;
	size_t i;

	for (i = 0; i < n; i++)
		/* this should never match */
		accum += (uintptr_t)memchr(ptrs[i], 128, (size_t)(ptrs[i + 1] - ptrs[i]));
}

static void
memchrbench(struct B *b, void *payload)
{
	struct testparam *param;
	size_t n;
	long i;
	void **ptrs;

	param = payload;
	b->bytes = param->buflen;
	ptrs = genmemtests(param, &n);

	domemchrbench(ptrs, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		domemchrbench(ptrs, n);
	stoptimer(b);

	kfree(ptrs);
}

extern void
strperf_memchr(void)
{
	runbenchmark("short", memchrbench, (void *)&shortparam);
	runbenchmark("mid", memchrbench, (void *)&midparam);
	runbenchmark("long", memchrbench, (void *)&longparam);
}
