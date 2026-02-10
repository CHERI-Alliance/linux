// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strnlen benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam
	shortparam = { .avglen = 16,	  .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x123456789ULL },
	midparam =	 { .avglen = 64,	  .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x234567890ULL },
	longparam =	 { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 255, .xseed = 0x345678910ULL };

static void
dostrnlenbench(const char *buf, size_t len, size_t maxlen)
{
	volatile size_t total = 0;

	while (total < len)
		total += strnlen(buf + total, maxlen) + 1;
}

static void
strnlenbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *buf;
	long i;

	param = payload;
	b->bytes = param->buflen;
	buf = gentests(param);

	dostrnlenbench(buf, param->buflen, param->avglen);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrnlenbench(buf, param->buflen, param->avglen);
	stoptimer(b);

	kfree(buf);
}

extern void
strperf_strnlen(void)
{
	runbenchmark("short", strnlenbench, (void *)&shortparam);
	runbenchmark("mid", strnlenbench, (void *)&midparam);
	runbenchmark("long", strnlenbench, (void *)&longparam);
}
