// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* strlen benchmark */

#include <linux/kernel.h>

#include "benchmark.h"

static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x123456789ULL },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x234567890ULL },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 255, .xseed = 0x345678910ULL };

static void
dostrlenbench(const char *buf, size_t len)
{
	volatile size_t total = 0;

	while (total < len)
		total += strlen(buf + total) + 1;
}

static void
strlenbench(struct B *b, void *payload)
{
	struct testparam *param;
	char *buf;
	long i;

	param = payload;
	b->bytes = param->buflen;
	buf = gentests(param);

	dostrlenbench(buf, param->buflen);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostrlenbench(buf, param->buflen);
	stoptimer(b);

	kfree(buf);
}

extern void
strperf_strlen(void)
{
	runbenchmark("short", strlenbench, (void *)&shortparam);
	runbenchmark("mid", strlenbench, (void *)&midparam);
	runbenchmark("long", strlenbench, (void *)&longparam);
}
