#pragma once


#include <linux/compat.h>


struct __c64_uvc_xu_control_mapping {
	__u32 id;
	__u8 name[32];
	__u8 entity[16];
	__u8 selector;

	__u8 size;
	__u8 offset;
	__u32 v4l2_type;
	__u32 data_type;

	__c64_uptr menu_info;
	__u32 menu_count;

	__u32 reserved[4];
};

static __always_inline __maybe_unused void
__from_c64_uvc_xu_control_mapping(struct uvc_xu_control_mapping *p)
{
	union {
		struct uvc_xu_control_mapping native;
		const struct __c64_uvc_xu_control_mapping compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.menu_count = u->compat.menu_count;
	u->native.menu_info =  compat_ptr(u->compat.menu_info);
	u->native.data_type = u->compat.data_type;
	u->native.v4l2_type = u->compat.v4l2_type;
	u->native.offset = u->compat.offset;
	u->native.size = u->compat.size;
	u->native.selector = u->compat.selector;
	BUILD_BUG_ON(sizeof(u->compat.entity) != sizeof(u->native.entity));
	memmove(&u->native.entity, &u->compat.entity, sizeof(u->native.entity));
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
	u->native.id = u->compat.id;
}
static __always_inline __maybe_unused void
__to_c64_uvc_xu_control_mapping(struct uvc_xu_control_mapping *p)
{
	union {
		struct __c64_uvc_xu_control_mapping compat;
		const struct uvc_xu_control_mapping native;
	} *u = (void *)p;

	u->compat.id = u->native.id;
	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	BUILD_BUG_ON(sizeof(u->native.entity) != sizeof(u->compat.entity));
	memmove(&u->compat.entity, &u->native.entity, sizeof(u->compat.entity));
	u->compat.selector = u->native.selector;
	u->compat.size = u->native.size;
	u->compat.offset = u->native.offset;
	u->compat.v4l2_type = u->native.v4l2_type;
	u->compat.data_type = u->native.data_type;
	u->compat.menu_info =  (__c64_uptr __force)(user_uintptr_t)u->native.menu_info;
	u->compat.menu_count = u->native.menu_count;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_uvc_xu_control_mapping_2(struct uvc_xu_control_mapping *native, const struct __c64_uvc_xu_control_mapping *compat)
{

	native->id = compat->id;
	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	BUILD_BUG_ON(sizeof(compat->entity) != sizeof(native->entity));
	memcpy(&native->entity, &compat->entity, sizeof(native->entity));
	native->selector = compat->selector;
	native->size = compat->size;
	native->offset = compat->offset;
	native->v4l2_type = compat->v4l2_type;
	native->data_type = compat->data_type;
	native->menu_info =  compat_ptr(compat->menu_info);
	native->menu_count = compat->menu_count;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_uvc_xu_control_mapping_2(struct __c64_uvc_xu_control_mapping *compat, const struct uvc_xu_control_mapping *native)
{

	compat->id = native->id;
	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	BUILD_BUG_ON(sizeof(native->entity) != sizeof(compat->entity));
	memcpy(&compat->entity, &native->entity, sizeof(compat->entity));
	compat->selector = native->selector;
	compat->size = native->size;
	compat->offset = native->offset;
	compat->v4l2_type = native->v4l2_type;
	compat->data_type = native->data_type;
	compat->menu_info =  (__c64_uptr __force)(user_uintptr_t)native->menu_info;
	compat->menu_count = native->menu_count;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_uvc_xu_control_query {
	__u8 unit;
	__u8 selector;
	__u8 query;		/* Video Class-Specific Request Code, */
				/* defined in linux/usb/video.h A.8.  */
	__u16 size;
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_uvc_xu_control_query(struct uvc_xu_control_query *p)
{
	union {
		struct uvc_xu_control_query native;
		const struct __c64_uvc_xu_control_query compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.size = u->compat.size;
	u->native.query = u->compat.query;
	u->native.selector = u->compat.selector;
	u->native.unit = u->compat.unit;
}
static __always_inline __maybe_unused void
__to_c64_uvc_xu_control_query(struct uvc_xu_control_query *p)
{
	union {
		struct __c64_uvc_xu_control_query compat;
		const struct uvc_xu_control_query native;
	} *u = (void *)p;

	u->compat.unit = u->native.unit;
	u->compat.selector = u->native.selector;
	u->compat.query = u->native.query;
	u->compat.size = u->native.size;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_uvc_xu_control_query_2(struct uvc_xu_control_query *native, const struct __c64_uvc_xu_control_query *compat)
{

	native->unit = compat->unit;
	native->selector = compat->selector;
	native->query = compat->query;
	native->size = compat->size;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_uvc_xu_control_query_2(struct __c64_uvc_xu_control_query *compat, const struct uvc_xu_control_query *native)
{

	compat->unit = native->unit;
	compat->selector = native->selector;
	compat->query = native->query;
	compat->size = native->size;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
