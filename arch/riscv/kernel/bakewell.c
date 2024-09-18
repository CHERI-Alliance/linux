#include <linux/sched.h>
#include <linux/printk.h>

#include <linux/cheri.h>
#include <asm/bakewell.h>

void __init bakewell_init(void)
{
	pr_info("CHERI bakewell support\n");

	/* Enable user space CHERI support. */
	__asm__ __volatile__("csrs senvcfg, %0\n" : : "r" (1 << 28));
}
