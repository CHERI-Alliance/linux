// SPDX-License-Identifier: GPL-2.0-or-later OR BSD-2-Clause
/*
 * Copyright (c) 2023 The FreeBSD Foundation
 */

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uts.h>
#include <linux/time.h>
#include <generated/compile.h>

#include "benchmark.h"

#define GOALNS 1000000000LL /* goal time for benchmark */

/*
 * Start the benchmark timer if it is stopped.
 */
extern void
starttimer(struct B *b) {
	if (b->timeron)
		return;

	b->start = ktime_get_raw();
	b->timeron = true;
}

/*
 * Stop the benchmark timer if it runs.
 */
extern void
stoptimer(struct B *b) {
	ktime_t now;

	if (!b->timeron)
		return;

	now = ktime_get_raw();
	b->duration = ktime_add(b->duration, ktime_sub(now, b->start));
	b->timeron = false;
	cond_resched();
}

/*
 * Reset the benchmark timer without affecting if it runs.
 */
extern void
resettimer(struct B *b) {
	cond_resched();
	b->start = ktime_get_raw();
	b->duration = 0;
}

/*
 * Returns the number of nanoseconds that elapsed while the benchmark
 * timer was running.
 */
extern long long
elapsed(struct B *b) {
	ktime_t d;

	d = b->duration;
	if (b->timeron) {
		ktime_t now = ktime_get_raw();
		d = ktime_add(d, ktime_sub(now, b->start));
	}

	return ktime_to_ns(d);
}

/*
 * run the benchmark for the specified number of iterations
 */
static void
runn(struct B *b, long n) {
	b->n = n;
	resettimer(b);
	starttimer(b);
	b->func(b, b->payload);
	stoptimer(b);
	b->prevn = n;
	b->prevduration = b->duration;
}

/*
 * Print the result of the last run of b.
 */
static void
printresult(struct B *b)
{
	ktime_t ns;

	ns = elapsed(b);

	if (b->bytes > 0)
		pr_info("Benchmark %-30s%8ld%10lld.%02lld ns/op%10lld.%02lld MiB/s\n",
		    b->name, b->n,
		    ns / b->n, 100 * (ns % b->n) / b->n,
		    b->n * b->bytes * (1000000000 / 1048576) / ns,
		    100 * ((b->n * b->bytes * (1000000000 /1048576)) % ns) / ns);
	else
		pr_info("Benchmark %-30s%8ld%10lld.%02lld ns/op\n",
		    b->name, b->n, ns / b->n, 100 * (ns % b->n) / b->n);
}

/*
 * Run the benchmark with the given name and print its status
 * to stdout.
 */
extern void
__runbenchmark(const char *name, void (*func)(struct B *, void *), void *payload)
{
	struct B b;
	long long n, duration;

	b.bytes = 0;
	b.name = name;
	b.func = func;
	b.payload = payload;
	b.timeron = false;

	runn(&b, 1); /* initial run to calibrate benchmark */

	n = 1;
	while (duration = ktime_to_ns(b.prevduration), duration < GOALNS && n < 1000000000) {
		long long last;

		last = n;
		if (duration <= 0)
			duration = 1;

		n = GOALNS * n / duration;
		n += n / 5;
		if (n > 100 * last)
			n = 100 * last;

		if (n <= last)
			n = last + 1;

		if (n > 1000000000)
			n = 1000000000;

		runn(&b, n);
	}

	printresult(&b);
}

/*
 * Print a preamble to the benchmark results with data on the host system.
 */
extern void
preamble(void)
{
	pr_info("os: %s\narch: %s\n", UTS_SYSNAME, UTS_MACHINE);
}

static int strperf_run(void)
{
	preamble();

	strperf_strchrnul();
	strperf_memchr();
	strperf_memcmp();
	strperf_memcpy();
	strperf_memset();
	strperf_stpcpy();
	strperf_strcmp();
	strperf_strcspn();
	strperf_strlen();
	strperf_strncmp();
	strperf_strnlen();
	strperf_strrchr();
	strperf_strspn();

	return 0;
}

static void strperf_done(void)
{
}

module_init(strperf_run);
module_exit(strperf_done);

MODULE_DESCRIPTION("Kernel version of strperf benchmark");
MODULE_LICENSE("Dual BSD/GPL");
