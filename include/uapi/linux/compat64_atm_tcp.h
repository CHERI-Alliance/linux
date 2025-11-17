#pragma once


#include <linux/compat.h>
#include <linux/compat64_atmapi.h>


struct __c64_atmtcp_control {
	struct atmtcp_hdr hdr;	/* must be first */
	int type;		/* message type; both directions */
	__c64_atm_kptr_t vcc;		/* both directions */
	struct sockaddr_atmpvc addr; /* suggested value from kernel */
	struct atm_qos	qos;	/* both directions */
	int result;		/* to kernel only */
} __ATM_API_ALIGN;

