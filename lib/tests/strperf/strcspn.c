// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strcspn benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam /* maxchar to be overridden in main function */
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = -1, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = -1, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = -1, .xseed = 0x345678910ULL };

static void
dostrcspnbench(const char *buf, const char *set, size_t n)
{
	const char *volatile pos;
	size_t i;

	pos = buf;
	for (i = 0; i < n; i++)
		pos += strcspn(pos, set) + 1;
}

static void
strcspnbench(struct B *b, void *payload)
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
	for (j = UCHAR_MAX; j > param->maxchar; j--)
		set[i++] = j;

	set[i] = '\0';

	BUG_ON(!(i <= sizeof set));

	dostrcspnbench(buf, set, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrcspnbench(buf, set, n);
	stoptimer(b);

	kfree(buf);
}

extern void
strperf_strcspn(void)
{
	shortparam.maxchar = UCHAR_MAX;
	runbenchmark("short0", strcspnbench, (void *)&shortparam);
	midparam.maxchar = UCHAR_MAX;
	runbenchmark("mid0", strcspnbench, (void *)&midparam);
	longparam.maxchar = UCHAR_MAX;
	runbenchmark("long0", strcspnbench, (void *)&longparam);

	shortparam.maxchar = UCHAR_MAX - 1;
	runbenchmark("short1", strcspnbench, (void *)&shortparam);
	midparam.maxchar = UCHAR_MAX - 1;
	runbenchmark("mid1", strcspnbench, (void *)&midparam);
	longparam.maxchar = UCHAR_MAX - 1;
	runbenchmark("long1", strcspnbench, (void *)&longparam);

	shortparam.maxchar = UCHAR_MAX - 5;
	runbenchmark("short5", strcspnbench, (void *)&shortparam);
	midparam.maxchar = UCHAR_MAX - 5;
	runbenchmark("mid5", strcspnbench, (void *)&midparam);
	longparam.maxchar = UCHAR_MAX - 5;
	runbenchmark("long5", strcspnbench, (void *)&longparam);

	shortparam.maxchar = UCHAR_MAX - 20;
	runbenchmark("short20", strcspnbench, (void *)&shortparam);
	midparam.maxchar = UCHAR_MAX - 20;
	runbenchmark("mid20", strcspnbench, (void *)&midparam);
	longparam.maxchar = UCHAR_MAX - 20;
	runbenchmark("long20", strcspnbench, (void *)&longparam);

	shortparam.maxchar = UCHAR_MAX - 40;
	runbenchmark("short40", strcspnbench, (void *)&shortparam);
	midparam.maxchar = UCHAR_MAX - 40;
	runbenchmark("mid40", strcspnbench, (void *)&midparam);
	longparam.maxchar = UCHAR_MAX - 40;
	runbenchmark("long40", strcspnbench, (void *)&longparam);
}
