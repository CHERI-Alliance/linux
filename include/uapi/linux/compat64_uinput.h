#pragma once


#include <linux/compat.h>
#include <linux/compat64_input.h>


struct __c64_uinput_ff_upload {
	__u32			request_id;
	__s32			retval;
	struct __c64_ff_effect	effect;
	struct __c64_ff_effect	old;
};

