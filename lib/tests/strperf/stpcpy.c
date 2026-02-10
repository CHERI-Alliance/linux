// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

/* stpcpy benchmark */

#include <linux/kernel.h>

#include "benchmark.h"


static struct testparam
    shortparam = { .avglen = 16,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x123456789 },
    midparam =   { .avglen = 64,      .buflen = 1 << 17, .charlen = 1, .maxchar = 255, .xseed = 0x234567890 },
    longparam =  { .avglen = 1 << 18, .buflen = 1 << 20, .charlen = 1, .maxchar = 255, .xseed = 0x345678910 };

static void
dostpcpybench(char *dest, const char *src, size_t len)
{
	char *volatile destpos;

	destpos = dest;
	while (destpos < dest + len) {
		const char *srcpos;

		srcpos = src + (destpos - dest);
		destpos = stpcpy(destpos, srcpos) + 1;
	}
}

static void
stpcpybench(struct B *b, void *payload)
{
	struct testparam *param;
	char *src, *dest;
	long i;

	param = payload;
	b->bytes = param->buflen;
	src = gentests(param);
	dest = kmalloc(param->buflen, GFP_KERNEL | __GFP_ZERO);

	if (dest == NULL)
		return;

	dostpcpybench(dest, src, param->buflen);
	resettimer(b);
	for (i = 0; i < b->n; i++)
		dostpcpybench(dest, src, param->buflen);
	stoptimer(b);

	kfree(src);
	kfree(dest);
}

extern void
strperf_stpcpy(void)
{
	runbenchmark("short", stpcpybench, (void *)&shortparam);
	runbenchmark("mid", stpcpybench, (void *)&midparam);
	runbenchmark("long", stpcpybench, (void *)&longparam);
}
