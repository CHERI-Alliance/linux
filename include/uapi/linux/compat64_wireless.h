#pragma once


#include <linux/compat.h>


struct __c64_iw_point {
  __c64_uptr pointer;	/* Pointer to the data  (in user space) */
  __u16		length;		/* number of fields or size in bytes */
  __u16		flags;		/* Optional params */
};

static __always_inline __maybe_unused void
__from_c64_iw_point(struct iw_point *p)
{
	union {
		struct iw_point native;
		const struct __c64_iw_point compat;
	} *u = (void *)p;

	u->native.flags = u->compat.flags;
	u->native.length = u->compat.length;
	u->native.pointer =  compat_ptr(u->compat.pointer);
}
static __always_inline __maybe_unused void
__to_c64_iw_point(struct iw_point *p)
{
	union {
		struct __c64_iw_point compat;
		const struct iw_point native;
	} *u = (void *)p;

	u->compat.pointer =  (__c64_uptr __force)(user_uintptr_t)u->native.pointer;
	u->compat.length = u->native.length;
	u->compat.flags = u->native.flags;
}
static __always_inline __maybe_unused void
__from_c64_iw_point_2(struct iw_point *native, const struct __c64_iw_point *compat)
{

	native->pointer =  compat_ptr(compat->pointer);
	native->length = compat->length;
	native->flags = compat->flags;
}
static __always_inline __maybe_unused void
__to_c64_iw_point_2(struct __c64_iw_point *compat, const struct iw_point *native)
{

	compat->pointer =  (__c64_uptr __force)(user_uintptr_t)native->pointer;
	compat->length = native->length;
	compat->flags = native->flags;
}
union __c64_iwreq_data {
	/* Config - generic */
	char		name[IFNAMSIZ];
	/* Name : used to verify the presence of  wireless extensions.
	 * Name of the protocol/provider... */

	struct __c64_iw_point	essid;		/* Extended network name */
	struct iw_param	nwid;		/* network id (or domain - the cell) */
	struct iw_freq	freq;		/* frequency or channel :
					 * 0-1000 = channel
					 * > 1000 = frequency in Hz */

	struct iw_param	sens;		/* signal level threshold */
	struct iw_param	bitrate;	/* default bit rate */
	struct iw_param	txpower;	/* default transmit power */
	struct iw_param	rts;		/* RTS threshold */
	struct iw_param	frag;		/* Fragmentation threshold */
	__u32		mode;		/* Operation mode */
	struct iw_param	retry;		/* Retry limits & lifetime */

	struct __c64_iw_point	encoding;	/* Encoding stuff : tokens */
	struct iw_param	power;		/* PM duration/timeout */
	struct iw_quality qual;		/* Quality part of statistics */

	struct sockaddr	ap_addr;	/* Access point address */
	struct sockaddr	addr;		/* Destination address (hw/mac) */

	struct iw_param	param;		/* Other small parameters */
	struct __c64_iw_point	data;		/* Other large parameters */
};

struct __c64_iwreq {
	union
	{
		char	ifrn_name[IFNAMSIZ];	/* if name, e.g. "eth0" */
	} ifr_ifrn;

	/* Data part (defined just above) */
	union __c64_iwreq_data	u;
};

struct __c64_iw_event {
	__u16		len;			/* Real length of this stuff */
	__u16		cmd;			/* Wireless IOCTL */
	union __c64_iwreq_data	u;		/* IOCTL fixed payload */
};

