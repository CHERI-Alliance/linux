// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strrchr benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

char *strrchr(const char *, int);

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 127, .xseed = 0x345678910ULL };

static void
dostrrchrbench(char **ptrs, size_t n)
{
	volatile uintptr_t sum = 0;
	size_t i;

	for (i = 0; ptrs[i+1] != NULL; i++)
		sum += (uintptr_t)strrchr(ptrs[i], 128) + 1;
}

static void
strrchrbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *buf;
	char **ptrs;
	size_t n;
	long i;

	param = payload;
	b->bytes = param->buflen;
	buf = gentests(param);
	ptrs = mkpointers(&n, buf, param->buflen);

	dostrrchrbench(ptrs, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrrchrbench(ptrs, n);
	stoptimer(b);

	kfree(ptrs);
	kfree(buf);
}

extern void
strperf_strrchr(void)
{
	runbenchmark("short", strrchrbench, (void *)&shortparam);
	runbenchmark("mid", strrchrbench, (void *)&midparam);
	runbenchmark("long", strrchrbench, (void *)&longparam);
}
