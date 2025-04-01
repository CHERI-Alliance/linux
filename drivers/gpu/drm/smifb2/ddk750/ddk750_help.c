#include "ddk750_help.h"

volatile unsigned char __iomem * smi_mmio750 = NULL;


/* after driver mapped io registers, use this function first */
void ddk750_set_mmio(volatile unsigned char * addr,unsigned short devId,char revId)
{
	smi_mmio750 = addr;
	printk("Found SM750 Chip\n");
}

