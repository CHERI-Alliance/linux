#pragma once


#include <linux/compat.h>


typedef struct {
	unsigned char _[sizeof(__c64_ptr64 )];
} __ATM_API_ALIGN __c64_atm_kptr_t;

