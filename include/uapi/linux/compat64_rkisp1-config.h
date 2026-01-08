#pragma once


#include <linux/compat.h>


struct __c64_rkisp1_ext_params_cfg {
	__u32 version;
	__u32 data_size;
	__u8 data[RKISP1_EXT_PARAMS_MAX_SIZE];
};

static __always_inline __maybe_unused void
__from_c64_rkisp1_ext_params_cfg(struct rkisp1_ext_params_cfg *p)
{
	union {
		struct rkisp1_ext_params_cfg native;
		const struct __c64_rkisp1_ext_params_cfg compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.data) != sizeof(u->native.data));
	memmove(&u->native.data, &u->compat.data, sizeof(u->native.data));
	u->native.data_size = u->compat.data_size;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_rkisp1_ext_params_cfg(struct rkisp1_ext_params_cfg *p)
{
	union {
		struct __c64_rkisp1_ext_params_cfg compat;
		const struct rkisp1_ext_params_cfg native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.data_size = u->native.data_size;
	BUILD_BUG_ON(sizeof(u->native.data) != sizeof(u->compat.data));
	memmove(&u->compat.data, &u->native.data, sizeof(u->compat.data));
}
static __always_inline __maybe_unused void
__from_c64_rkisp1_ext_params_cfg_2(struct rkisp1_ext_params_cfg *native, const struct __c64_rkisp1_ext_params_cfg *compat)
{

	native->version = compat->version;
	native->data_size = compat->data_size;
	BUILD_BUG_ON(sizeof(compat->data) != sizeof(native->data));
	memcpy(&native->data, &compat->data, sizeof(native->data));
}
static __always_inline __maybe_unused void
__to_c64_rkisp1_ext_params_cfg_2(struct __c64_rkisp1_ext_params_cfg *compat, const struct rkisp1_ext_params_cfg *native)
{

	compat->version = native->version;
	compat->data_size = native->data_size;
	BUILD_BUG_ON(sizeof(native->data) != sizeof(compat->data));
	memcpy(&compat->data, &native->data, sizeof(compat->data));
}
