#pragma once


#include <linux/compat.h>


struct __c64_if_settings {
	unsigned int type;	/* Type of physical device or protocol */
	unsigned int size;	/* Size of the data allocated by the caller */
	union {
		/* {atm/eth/dsl}_settings anyone ? */
		__c64_uptr raw_hdlc;
		__c64_uptr cisco;
		__c64_uptr fr;
		__c64_uptr fr_pvc;
		__c64_uptr fr_pvc_info;
		__c64_uptr x25;

		/* interface settings */
		__c64_uptr sync;
		__c64_uptr te1;
	} ifs_ifsu;
};

static __always_inline __maybe_unused void
__from_c64_if_settings(struct if_settings *p)
{
	union {
		struct if_settings native;
		const struct __c64_if_settings compat;
	} *u = (void *)p;

	u->native.ifs_ifsu.raw_hdlc =  compat_ptr(u->compat.ifs_ifsu.raw_hdlc);
	u->native.size = u->compat.size;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_if_settings(struct if_settings *p)
{
	union {
		struct __c64_if_settings compat;
		const struct if_settings native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.size = u->native.size;
	u->compat.ifs_ifsu.raw_hdlc =  (__c64_uptr __force)(user_uintptr_t)u->native.ifs_ifsu.raw_hdlc;
}
static __always_inline __maybe_unused void
__from_c64_if_settings_2(struct if_settings *native, const struct __c64_if_settings *compat)
{

	native->type = compat->type;
	native->size = compat->size;
	native->ifs_ifsu.raw_hdlc =  compat_ptr(compat->ifs_ifsu.raw_hdlc);
}
static __always_inline __maybe_unused void
__to_c64_if_settings_2(struct __c64_if_settings *compat, const struct if_settings *native)
{

	compat->type = native->type;
	compat->size = native->size;
	compat->ifs_ifsu.raw_hdlc =  (__c64_uptr __force)(user_uintptr_t)native->ifs_ifsu.raw_hdlc;
}
struct __c64_ifreq {
	union
	{
		char	ifrn_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	} ifr_ifrn;
	
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
		struct	sockaddr ifru_broadaddr;
		struct	sockaddr ifru_netmask;
		struct  sockaddr ifru_hwaddr;
		short	ifru_flags;
		int	ifru_ivalue;
		int	ifru_mtu;
		struct  ifmap ifru_map;
		char	ifru_slave[IFNAMSIZ];	/* Just fits the size */
		char	ifru_newname[IFNAMSIZ];
		__c64_uptr	ifru_data;
		struct	__c64_if_settings ifru_settings;
	} ifr_ifru;
};

struct __c64_ifconf  {
	int	ifc_len;			/* size of buffer	*/
	union {
		__c64_uptr ifcu_buf;
		__c64_uptr ifcu_req;
	} ifc_ifcu;
};

static __always_inline __maybe_unused void
__from_c64_ifconf(struct ifconf *p)
{
	union {
		struct ifconf native;
		const struct __c64_ifconf compat;
	} *u = (void *)p;

	u->native.ifc_ifcu.ifcu_buf =  compat_ptr(u->compat.ifc_ifcu.ifcu_buf);
	u->native.ifc_len = u->compat.ifc_len;
}
static __always_inline __maybe_unused void
__to_c64_ifconf(struct ifconf *p)
{
	union {
		struct __c64_ifconf compat;
		const struct ifconf native;
	} *u = (void *)p;

	u->compat.ifc_len = u->native.ifc_len;
	u->compat.ifc_ifcu.ifcu_buf =  (__c64_uptr __force)(user_uintptr_t)u->native.ifc_ifcu.ifcu_buf;
}
static __always_inline __maybe_unused void
__from_c64_ifconf_2(struct ifconf *native, const struct __c64_ifconf *compat)
{

	native->ifc_len = compat->ifc_len;
	native->ifc_ifcu.ifcu_buf =  compat_ptr(compat->ifc_ifcu.ifcu_buf);
}
static __always_inline __maybe_unused void
__to_c64_ifconf_2(struct __c64_ifconf *compat, const struct ifconf *native)
{

	compat->ifc_len = native->ifc_len;
	compat->ifc_ifcu.ifcu_buf =  (__c64_uptr __force)(user_uintptr_t)native->ifc_ifcu.ifcu_buf;
}
