#pragma once


#include <linux/compat.h>


struct __c64_sctp_getaddrs_old {
	sctp_assoc_t            assoc_id;
	int			addr_num;
	__c64_uptr addrs;
};

static __always_inline __maybe_unused void
__from_c64_sctp_getaddrs_old(struct sctp_getaddrs_old *p)
{
	union {
		struct sctp_getaddrs_old native;
		const struct __c64_sctp_getaddrs_old compat;
	} *u = (void *)p;

	u->native.addrs =  compat_ptr(u->compat.addrs);
	u->native.addr_num = u->compat.addr_num;
	u->native.assoc_id = u->compat.assoc_id;
}
static __always_inline __maybe_unused void
__to_c64_sctp_getaddrs_old(struct sctp_getaddrs_old *p)
{
	union {
		struct __c64_sctp_getaddrs_old compat;
		const struct sctp_getaddrs_old native;
	} *u = (void *)p;

	u->compat.assoc_id = u->native.assoc_id;
	u->compat.addr_num = u->native.addr_num;
	u->compat.addrs =  (__c64_uptr __force)(user_uintptr_t)u->native.addrs;
}
static __always_inline __maybe_unused void
__from_c64_sctp_getaddrs_old_2(struct sctp_getaddrs_old *native, const struct __c64_sctp_getaddrs_old *compat)
{

	native->assoc_id = compat->assoc_id;
	native->addr_num = compat->addr_num;
	native->addrs =  compat_ptr(compat->addrs);
}
static __always_inline __maybe_unused void
__to_c64_sctp_getaddrs_old_2(struct __c64_sctp_getaddrs_old *compat, const struct sctp_getaddrs_old *native)
{

	compat->assoc_id = native->assoc_id;
	compat->addr_num = native->addr_num;
	compat->addrs =  (__c64_uptr __force)(user_uintptr_t)native->addrs;
}
