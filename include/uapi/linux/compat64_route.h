#pragma once


#include <linux/compat.h>


struct __c64_rtentry {
	unsigned long	rt_pad1;
	struct sockaddr	rt_dst;		/* target address		*/
	struct sockaddr	rt_gateway;	/* gateway addr (RTF_GATEWAY)	*/
	struct sockaddr	rt_genmask;	/* target network mask (IP)	*/
	unsigned short	rt_flags;
	short		rt_pad2;
	unsigned long	rt_pad3;
	unsigned long	rt_pad4;	// it is actually 8 bytes
	short		rt_metric;	/* +1 for binary compatibility!	*/
	__c64_uptr rt_dev;	/* forcing the device at add	*/
	unsigned long	rt_mtu;		/* per route MTU/Window 	*/
	unsigned long	rt_window;	/* Window clamping 		*/
	unsigned short	rt_irtt;	/* Initial RTT			*/
};

static __always_inline __maybe_unused void
__from_c64_rtentry(struct rtentry *p)
{
	union {
		struct rtentry native;
		const struct __c64_rtentry compat;
	} *u = (void *)p;

	u->native.rt_irtt = u->compat.rt_irtt;
	u->native.rt_window = u->compat.rt_window;
	u->native.rt_mtu = u->compat.rt_mtu;
	u->native.rt_dev =  compat_ptr(u->compat.rt_dev);
	u->native.rt_metric = u->compat.rt_metric;
	u->native.rt_pad4 = u->compat.rt_pad4;
	u->native.rt_pad3 = u->compat.rt_pad3;
	u->native.rt_pad2 = u->compat.rt_pad2;
	u->native.rt_flags = u->compat.rt_flags;
	BUILD_BUG_ON(sizeof(u->compat.rt_genmask) != sizeof(u->native.rt_genmask));
	memmove(&u->native.rt_genmask, &u->compat.rt_genmask, sizeof(u->native.rt_genmask));
	BUILD_BUG_ON(sizeof(u->compat.rt_gateway) != sizeof(u->native.rt_gateway));
	memmove(&u->native.rt_gateway, &u->compat.rt_gateway, sizeof(u->native.rt_gateway));
	BUILD_BUG_ON(sizeof(u->compat.rt_dst) != sizeof(u->native.rt_dst));
	memmove(&u->native.rt_dst, &u->compat.rt_dst, sizeof(u->native.rt_dst));
	u->native.rt_pad1 = u->compat.rt_pad1;
}
static __always_inline __maybe_unused void
__to_c64_rtentry(struct rtentry *p)
{
	union {
		struct __c64_rtentry compat;
		const struct rtentry native;
	} *u = (void *)p;

	u->compat.rt_pad1 = u->native.rt_pad1;
	BUILD_BUG_ON(sizeof(u->native.rt_dst) != sizeof(u->compat.rt_dst));
	memmove(&u->compat.rt_dst, &u->native.rt_dst, sizeof(u->compat.rt_dst));
	BUILD_BUG_ON(sizeof(u->native.rt_gateway) != sizeof(u->compat.rt_gateway));
	memmove(&u->compat.rt_gateway, &u->native.rt_gateway, sizeof(u->compat.rt_gateway));
	BUILD_BUG_ON(sizeof(u->native.rt_genmask) != sizeof(u->compat.rt_genmask));
	memmove(&u->compat.rt_genmask, &u->native.rt_genmask, sizeof(u->compat.rt_genmask));
	u->compat.rt_flags = u->native.rt_flags;
	u->compat.rt_pad2 = u->native.rt_pad2;
	u->compat.rt_pad3 = u->native.rt_pad3;
	u->compat.rt_pad4 = u->native.rt_pad4;
	u->compat.rt_metric = u->native.rt_metric;
	u->compat.rt_dev =  (__c64_uptr __force)(user_uintptr_t)u->native.rt_dev;
	u->compat.rt_mtu = u->native.rt_mtu;
	u->compat.rt_window = u->native.rt_window;
	u->compat.rt_irtt = u->native.rt_irtt;
}
static __always_inline __maybe_unused void
__from_c64_rtentry_2(struct rtentry *native, const struct __c64_rtentry *compat)
{

	native->rt_pad1 = compat->rt_pad1;
	BUILD_BUG_ON(sizeof(compat->rt_dst) != sizeof(native->rt_dst));
	memcpy(&native->rt_dst, &compat->rt_dst, sizeof(native->rt_dst));
	BUILD_BUG_ON(sizeof(compat->rt_gateway) != sizeof(native->rt_gateway));
	memcpy(&native->rt_gateway, &compat->rt_gateway, sizeof(native->rt_gateway));
	BUILD_BUG_ON(sizeof(compat->rt_genmask) != sizeof(native->rt_genmask));
	memcpy(&native->rt_genmask, &compat->rt_genmask, sizeof(native->rt_genmask));
	native->rt_flags = compat->rt_flags;
	native->rt_pad2 = compat->rt_pad2;
	native->rt_pad3 = compat->rt_pad3;
	native->rt_pad4 = compat->rt_pad4;
	native->rt_metric = compat->rt_metric;
	native->rt_dev =  compat_ptr(compat->rt_dev);
	native->rt_mtu = compat->rt_mtu;
	native->rt_window = compat->rt_window;
	native->rt_irtt = compat->rt_irtt;
}
static __always_inline __maybe_unused void
__to_c64_rtentry_2(struct __c64_rtentry *compat, const struct rtentry *native)
{

	compat->rt_pad1 = native->rt_pad1;
	BUILD_BUG_ON(sizeof(native->rt_dst) != sizeof(compat->rt_dst));
	memcpy(&compat->rt_dst, &native->rt_dst, sizeof(compat->rt_dst));
	BUILD_BUG_ON(sizeof(native->rt_gateway) != sizeof(compat->rt_gateway));
	memcpy(&compat->rt_gateway, &native->rt_gateway, sizeof(compat->rt_gateway));
	BUILD_BUG_ON(sizeof(native->rt_genmask) != sizeof(compat->rt_genmask));
	memcpy(&compat->rt_genmask, &native->rt_genmask, sizeof(compat->rt_genmask));
	compat->rt_flags = native->rt_flags;
	compat->rt_pad2 = native->rt_pad2;
	compat->rt_pad3 = native->rt_pad3;
	compat->rt_pad4 = native->rt_pad4;
	compat->rt_metric = native->rt_metric;
	compat->rt_dev =  (__c64_uptr __force)(user_uintptr_t)native->rt_dev;
	compat->rt_mtu = native->rt_mtu;
	compat->rt_window = native->rt_window;
	compat->rt_irtt = native->rt_irtt;
}
