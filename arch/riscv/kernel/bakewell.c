#include <linux/sched.h>
#include <linux/printk.h>

#include <asm/bakewell.h>

#include "cheri_init_globals_bw.h"

void __init bakewell_init(void)
{
	pr_info("CHERI bakewell support\n");

	/* Enable user space CHERI support. */
	__asm__ __volatile__("csrs senvcfg, %0\n" : : "r" (1 << 28));
}

/* FIXCHERI: Check capability restrictions. */
void __init init_cap_relocs(void * __capability rw, void * __capability rx)
{
	cheri_init_globals_3(rw, rx, rx);
}
