#pragma once


#include <linux/compat.h>
#include <linux/compat64_in.h>


struct __c64_sockaddr_rxrpc {
	__kernel_sa_family_t	srx_family;	/* address family */
	__u16			srx_service;	/* service desired */
	__u16			transport_type;	/* type of transport socket (SOCK_DGRAM) */
	__u16			transport_len;	/* length of transport address */
	union {
		__kernel_sa_family_t family;	/* transport address family */
		struct __c64_sockaddr_in sin;		/* IPv4 transport address */
		struct sockaddr_in6 sin6;	/* IPv6 transport address */
	} transport;
};

