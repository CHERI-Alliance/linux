#pragma once


#include <linux/compat.h>
#include <linux/compat64_atmapi.h>


struct __c64_atmsvc_msg {
	enum atmsvc_msg_type type;
	__c64_atm_kptr_t vcc;
	__c64_atm_kptr_t listen_vcc;		/* indicate */
	int reply;			/* for okay and close:		   */
					/*   < 0: error before active	   */
					/*        (sigd has discarded ctx) */
					/*   ==0: success		   */
				        /*   > 0: error when active (still */
					/*        need to close)	   */
	struct sockaddr_atmpvc pvc;	/* indicate, okay (connect) */
	struct sockaddr_atmsvc local;	/* local SVC address */
	struct atm_qos qos;		/* QOS parameters */
	struct atm_sap sap;		/* SAP */
	unsigned int session;		/* for p2pm */
	struct sockaddr_atmsvc svc;	/* SVC address */
} __ATM_API_ALIGN;

