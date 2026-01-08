#pragma once


#include <linux/compat.h>


struct __c64_ethtool_tunable {
	__u32	cmd;
	__u32	id;
	__u32	type_id;
	__u32	len;
	__c64_uptr data[];
};

