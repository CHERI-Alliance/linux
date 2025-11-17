#pragma once


#include <linux/compat.h>


struct __c64_sockaddr_in {
  __kernel_sa_family_t	sin_family;	/* Address family		*/
  __be16		sin_port;	/* Port number			*/
  struct in_addr	sin_addr;	/* Internet address		*/

  /* Pad to size of `struct sockaddr'. */
  unsigned char		__pad[__SOCK_SIZE__ - sizeof(short int) -
			sizeof(unsigned short int) - sizeof(struct in_addr)];
};

static __always_inline __maybe_unused void
__from_c64_sockaddr_in(struct sockaddr_in *p)
{
	union {
		struct sockaddr_in native;
		const struct __c64_sockaddr_in compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.__pad) != sizeof(u->native.__pad));
	memmove(&u->native.__pad, &u->compat.__pad, sizeof(u->native.__pad));
	BUILD_BUG_ON(sizeof(u->compat.sin_addr) != sizeof(u->native.sin_addr));
	memmove(&u->native.sin_addr, &u->compat.sin_addr, sizeof(u->native.sin_addr));
	u->native.sin_port = u->compat.sin_port;
	u->native.sin_family = u->compat.sin_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_in(struct sockaddr_in *p)
{
	union {
		struct __c64_sockaddr_in compat;
		const struct sockaddr_in native;
	} *u = (void *)p;

	u->compat.sin_family = u->native.sin_family;
	u->compat.sin_port = u->native.sin_port;
	BUILD_BUG_ON(sizeof(u->native.sin_addr) != sizeof(u->compat.sin_addr));
	memmove(&u->compat.sin_addr, &u->native.sin_addr, sizeof(u->compat.sin_addr));
	BUILD_BUG_ON(sizeof(u->native.__pad) != sizeof(u->compat.__pad));
	memmove(&u->compat.__pad, &u->native.__pad, sizeof(u->compat.__pad));
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_in_2(struct sockaddr_in *native, const struct __c64_sockaddr_in *compat)
{

	native->sin_family = compat->sin_family;
	native->sin_port = compat->sin_port;
	BUILD_BUG_ON(sizeof(compat->sin_addr) != sizeof(native->sin_addr));
	memcpy(&native->sin_addr, &compat->sin_addr, sizeof(native->sin_addr));
	BUILD_BUG_ON(sizeof(compat->__pad) != sizeof(native->__pad));
	memcpy(&native->__pad, &compat->__pad, sizeof(native->__pad));
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_in_2(struct __c64_sockaddr_in *compat, const struct sockaddr_in *native)
{

	compat->sin_family = native->sin_family;
	compat->sin_port = native->sin_port;
	BUILD_BUG_ON(sizeof(native->sin_addr) != sizeof(compat->sin_addr));
	memcpy(&compat->sin_addr, &native->sin_addr, sizeof(compat->sin_addr));
	BUILD_BUG_ON(sizeof(native->__pad) != sizeof(compat->__pad));
	memcpy(&compat->__pad, &native->__pad, sizeof(compat->__pad));
}
