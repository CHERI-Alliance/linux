#pragma once


#include <linux/compat.h>


typedef union __c64_sigval {
	int sival_int;
	__c64_uptr sival_ptr;
} __c64_sigval_t;

