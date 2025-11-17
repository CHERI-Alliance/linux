#pragma once


#include <linux/compat.h>


struct __c64_v4l2_subdev_routing {
	__u32 which;
	__u32 len_routes;
	__c64_ptr64 routes;
	__u32 num_routes;
	/// UAPI: NoConvert: Padding
	__u32 reserved[13 - sizeof(__c64_ptr64 ) / 4];
};

static __always_inline __maybe_unused void
__from_c64_v4l2_subdev_routing(struct v4l2_subdev_routing *p)
{
	union {
		struct v4l2_subdev_routing native;
		const struct __c64_v4l2_subdev_routing compat;
	} *u = (void *)p;

	u->native.num_routes = u->compat.num_routes;
	u->native.routes = (user_uintptr_t)compat_ptr(u->compat.routes);
	u->native.len_routes = u->compat.len_routes;
	u->native.which = u->compat.which;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_subdev_routing(struct v4l2_subdev_routing *p)
{
	union {
		struct __c64_v4l2_subdev_routing compat;
		const struct v4l2_subdev_routing native;
	} *u = (void *)p;

	u->compat.which = u->native.which;
	u->compat.len_routes = u->native.len_routes;
	u->compat.routes = (__c64_ptr64 __force)u->native.routes;
	u->compat.num_routes = u->native.num_routes;
}
static __always_inline __maybe_unused void
__from_c64_v4l2_subdev_routing_2(struct v4l2_subdev_routing *native, const struct __c64_v4l2_subdev_routing *compat)
{

	native->which = compat->which;
	native->len_routes = compat->len_routes;
	native->routes = (user_uintptr_t)compat_ptr(compat->routes);
	native->num_routes = compat->num_routes;
}
static __always_inline __maybe_unused void
__to_c64_v4l2_subdev_routing_2(struct __c64_v4l2_subdev_routing *compat, const struct v4l2_subdev_routing *native)
{

	compat->which = native->which;
	compat->len_routes = native->len_routes;
	compat->routes = (__c64_ptr64 __force)native->routes;
	compat->num_routes = native->num_routes;
}
