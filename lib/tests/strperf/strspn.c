// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strspn benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

enum { EXTRACHARS = 64 };

static struct testparam /* maxchar to be overridden in main function */
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = -1, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = -1, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = -1, .xseed = 0x345678910ULL };

static void
dostrspnbench(const char *buf, const char *set, size_t n)
{
	const char *volatile pos;
	size_t i;

	pos = buf;
	for (i = 0; i < n; i++)
		pos += strspn(pos, set) + 1;
}

static void
strspnbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *buf, set[64];
	size_t n;
	long i;
	int j;

	param = payload;
	b->bytes = param->buflen;
	buf = gentests(param);
	kfree(mkpointers(&n, buf, param->buflen));

	i = 0;
	for (j = 1; j <= param->maxchar; j++)
		set[i++] = j;

	set[i] = '\0';

	BUG_ON(!(i <= sizeof set));

	dostrspnbench(buf, set, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrspnbench(buf, set, n);
	stoptimer(b);

	kfree(buf);
}

extern void
strperf_strspn(void)
{
	shortparam.maxchar = 1;
	runbenchmark("short1", strspnbench, (void *)&shortparam);
	midparam.maxchar = 1;
	runbenchmark("mid1", strspnbench, (void *)&midparam);
	longparam.maxchar = 1;
	runbenchmark("long1", strspnbench, (void *)&longparam);

	shortparam.maxchar = 5;
	runbenchmark("short5", strspnbench, (void *)&shortparam);
	midparam.maxchar = 5;
	runbenchmark("mid5", strspnbench, (void *)&midparam);
	longparam.maxchar = 5;
	runbenchmark("long5", strspnbench, (void *)&longparam);

	shortparam.maxchar = 20;
	runbenchmark("short20", strspnbench, (void *)&shortparam);
	midparam.maxchar = 20;
	runbenchmark("mid20", strspnbench, (void *)&midparam);
	longparam.maxchar = 20;
	runbenchmark("long20", strspnbench, (void *)&longparam);

	shortparam.maxchar = 40;
	runbenchmark("short40", strspnbench, (void *)&shortparam);
	midparam.maxchar = 40;
	runbenchmark("mid40", strspnbench, (void *)&midparam);
	longparam.maxchar = 40;
	runbenchmark("long40", strspnbench, (void *)&longparam);
}
