// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strchrnul benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

char *strchrnul(const char *, int);

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x123456789 },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 127, .xseed = 0x234567890 },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 127, .xseed = 0x345678910 };

static void
dostrchrnulbench(const char *buf, size_t n)
{
	const char *volatile pos;
	size_t i;

	pos = buf;
	for (i = 0; i < n; i++)
		/* this should never match */
		pos = strchrnul(pos, 128) + 1;
}

static void
strchrnulbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *buf;
	size_t n;
	long i;

	param = payload;
	b->bytes = param->buflen;
	buf = gentests(param);
	if (WARN_ON(buf == NULL))
		return;
	kfree(mkpointers(&n, buf, param->buflen));

	dostrchrnulbench(buf, n);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrchrnulbench(buf, n);
	stoptimer(b);

	kfree(buf);
}

void
strperf_strchrnul(void)
{
	runbenchmark("short", strchrnulbench, (void *)&shortparam);
	runbenchmark("mid", strchrnulbench, (void *)&midparam);
	runbenchmark("long", strchrnulbench, (void *)&longparam);
}
