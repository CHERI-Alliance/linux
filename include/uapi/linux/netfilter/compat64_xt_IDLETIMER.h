#pragma once


#include <linux/compat.h>


struct __c64_idletimer_tg_info {
	__u32 timeout;

	char label[MAX_IDLETIMER_LABEL_SIZE];

	/* for kernel module internal use only */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr timer;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __timer;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_idletimer_tg_info(struct idletimer_tg_info *p)
{
	union {
		struct idletimer_tg_info native;
		const struct __c64_idletimer_tg_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.label) != sizeof(u->native.label));
	memmove(&u->native.label, &u->compat.label, sizeof(u->native.label));
	u->native.timeout = u->compat.timeout;
}
static __always_inline __maybe_unused void
__to_c64_idletimer_tg_info(struct idletimer_tg_info *p)
{
	union {
		struct __c64_idletimer_tg_info compat;
		const struct idletimer_tg_info native;
	} *u = (void *)p;

	u->compat.timeout = u->native.timeout;
	BUILD_BUG_ON(sizeof(u->native.label) != sizeof(u->compat.label));
	memmove(&u->compat.label, &u->native.label, sizeof(u->compat.label));
}
static __always_inline __maybe_unused void
__from_c64_idletimer_tg_info_2(struct idletimer_tg_info *native, const struct __c64_idletimer_tg_info *compat)
{

	native->timeout = compat->timeout;
	BUILD_BUG_ON(sizeof(compat->label) != sizeof(native->label));
	memcpy(&native->label, &compat->label, sizeof(native->label));
}
static __always_inline __maybe_unused void
__to_c64_idletimer_tg_info_2(struct __c64_idletimer_tg_info *compat, const struct idletimer_tg_info *native)
{

	compat->timeout = native->timeout;
	BUILD_BUG_ON(sizeof(native->label) != sizeof(compat->label));
	memcpy(&compat->label, &native->label, sizeof(compat->label));
}
struct __c64_idletimer_tg_info_v1 {
	__u32 timeout;

	char label[MAX_IDLETIMER_LABEL_SIZE];

	__u8 send_nl_msg;   /* unused: for compatibility with Android */
	__u8 timer_type;

	/* for kernel module internal use only */
	union {
		/// UAPI: NoConvert: Kernel only
		__c64_uptr timer;
		/// UAPI: NoConvert: Kernel only
		__c64_uptr __timer;
	} __attribute__((aligned(8)));
};

static __always_inline __maybe_unused void
__from_c64_idletimer_tg_info_v1(struct idletimer_tg_info_v1 *p)
{
	union {
		struct idletimer_tg_info_v1 native;
		const struct __c64_idletimer_tg_info_v1 compat;
	} *u = (void *)p;

	u->native.timer_type = u->compat.timer_type;
	u->native.send_nl_msg = u->compat.send_nl_msg;
	BUILD_BUG_ON(sizeof(u->compat.label) != sizeof(u->native.label));
	memmove(&u->native.label, &u->compat.label, sizeof(u->native.label));
	u->native.timeout = u->compat.timeout;
}
static __always_inline __maybe_unused void
__to_c64_idletimer_tg_info_v1(struct idletimer_tg_info_v1 *p)
{
	union {
		struct __c64_idletimer_tg_info_v1 compat;
		const struct idletimer_tg_info_v1 native;
	} *u = (void *)p;

	u->compat.timeout = u->native.timeout;
	BUILD_BUG_ON(sizeof(u->native.label) != sizeof(u->compat.label));
	memmove(&u->compat.label, &u->native.label, sizeof(u->compat.label));
	u->compat.send_nl_msg = u->native.send_nl_msg;
	u->compat.timer_type = u->native.timer_type;
}
static __always_inline __maybe_unused void
__from_c64_idletimer_tg_info_v1_2(struct idletimer_tg_info_v1 *native, const struct __c64_idletimer_tg_info_v1 *compat)
{

	native->timeout = compat->timeout;
	BUILD_BUG_ON(sizeof(compat->label) != sizeof(native->label));
	memcpy(&native->label, &compat->label, sizeof(native->label));
	native->send_nl_msg = compat->send_nl_msg;
	native->timer_type = compat->timer_type;
}
static __always_inline __maybe_unused void
__to_c64_idletimer_tg_info_v1_2(struct __c64_idletimer_tg_info_v1 *compat, const struct idletimer_tg_info_v1 *native)
{

	compat->timeout = native->timeout;
	BUILD_BUG_ON(sizeof(native->label) != sizeof(compat->label));
	memcpy(&compat->label, &native->label, sizeof(compat->label));
	compat->send_nl_msg = native->send_nl_msg;
	compat->timer_type = native->timer_type;
}
