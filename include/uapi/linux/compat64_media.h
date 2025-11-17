#pragma once


#include <linux/compat.h>


struct __c64_media_links_enum {
	__u32 entity;
	/* Should have enough room for pads elements */
	__c64_uptr pads;
	/* Should have enough room for links elements */
	__c64_uptr links;
	__u32 reserved[4];
};

static __always_inline __maybe_unused void
__from_c64_media_links_enum(struct media_links_enum *p)
{
	union {
		struct media_links_enum native;
		const struct __c64_media_links_enum compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.links =  compat_ptr(u->compat.links);
	u->native.pads =  compat_ptr(u->compat.pads);
	u->native.entity = u->compat.entity;
}
static __always_inline __maybe_unused void
__to_c64_media_links_enum(struct media_links_enum *p)
{
	union {
		struct __c64_media_links_enum compat;
		const struct media_links_enum native;
	} *u = (void *)p;

	u->compat.entity = u->native.entity;
	u->compat.pads =  (__c64_uptr __force)(user_uintptr_t)u->native.pads;
	u->compat.links =  (__c64_uptr __force)(user_uintptr_t)u->native.links;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_media_links_enum_2(struct media_links_enum *native, const struct __c64_media_links_enum *compat)
{

	native->entity = compat->entity;
	native->pads =  compat_ptr(compat->pads);
	native->links =  compat_ptr(compat->links);
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_media_links_enum_2(struct __c64_media_links_enum *compat, const struct media_links_enum *native)
{

	compat->entity = native->entity;
	compat->pads =  (__c64_uptr __force)(user_uintptr_t)native->pads;
	compat->links =  (__c64_uptr __force)(user_uintptr_t)native->links;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_media_v2_topology {
	__u64 topology_version;

	__u32 num_entities;
	__u32 reserved1;
	__c64_ptr64 ptr_entities;

	__u32 num_interfaces;
	__u32 reserved2;
	__c64_ptr64 ptr_interfaces;

	__u32 num_pads;
	__u32 reserved3;
	__c64_ptr64 ptr_pads;

	__u32 num_links;
	__u32 reserved4;
	__c64_ptr64 ptr_links;
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_media_v2_topology(struct media_v2_topology *p)
{
	union {
		struct media_v2_topology native;
		const struct __c64_media_v2_topology compat;
	} *u = (void *)p;

	u->native.ptr_links = (user_uintptr_t)compat_ptr(u->compat.ptr_links);
	u->native.reserved4 = u->compat.reserved4;
	u->native.num_links = u->compat.num_links;
	u->native.ptr_pads = (user_uintptr_t)compat_ptr(u->compat.ptr_pads);
	u->native.reserved3 = u->compat.reserved3;
	u->native.num_pads = u->compat.num_pads;
	u->native.ptr_interfaces = (user_uintptr_t)compat_ptr(u->compat.ptr_interfaces);
	u->native.reserved2 = u->compat.reserved2;
	u->native.num_interfaces = u->compat.num_interfaces;
	u->native.ptr_entities = (user_uintptr_t)compat_ptr(u->compat.ptr_entities);
	u->native.reserved1 = u->compat.reserved1;
	u->native.num_entities = u->compat.num_entities;
	u->native.topology_version = u->compat.topology_version;
}
static __always_inline __maybe_unused void
__to_c64_media_v2_topology(struct media_v2_topology *p)
{
	union {
		struct __c64_media_v2_topology compat;
		const struct media_v2_topology native;
	} *u = (void *)p;

	u->compat.topology_version = u->native.topology_version;
	u->compat.num_entities = u->native.num_entities;
	u->compat.reserved1 = u->native.reserved1;
	u->compat.ptr_entities = (__c64_ptr64 __force)u->native.ptr_entities;
	u->compat.num_interfaces = u->native.num_interfaces;
	u->compat.reserved2 = u->native.reserved2;
	u->compat.ptr_interfaces = (__c64_ptr64 __force)u->native.ptr_interfaces;
	u->compat.num_pads = u->native.num_pads;
	u->compat.reserved3 = u->native.reserved3;
	u->compat.ptr_pads = (__c64_ptr64 __force)u->native.ptr_pads;
	u->compat.num_links = u->native.num_links;
	u->compat.reserved4 = u->native.reserved4;
	u->compat.ptr_links = (__c64_ptr64 __force)u->native.ptr_links;
}
static __always_inline __maybe_unused void
__from_c64_media_v2_topology_2(struct media_v2_topology *native, const struct __c64_media_v2_topology *compat)
{

	native->topology_version = compat->topology_version;
	native->num_entities = compat->num_entities;
	native->reserved1 = compat->reserved1;
	native->ptr_entities = (user_uintptr_t)compat_ptr(compat->ptr_entities);
	native->num_interfaces = compat->num_interfaces;
	native->reserved2 = compat->reserved2;
	native->ptr_interfaces = (user_uintptr_t)compat_ptr(compat->ptr_interfaces);
	native->num_pads = compat->num_pads;
	native->reserved3 = compat->reserved3;
	native->ptr_pads = (user_uintptr_t)compat_ptr(compat->ptr_pads);
	native->num_links = compat->num_links;
	native->reserved4 = compat->reserved4;
	native->ptr_links = (user_uintptr_t)compat_ptr(compat->ptr_links);
}
static __always_inline __maybe_unused void
__to_c64_media_v2_topology_2(struct __c64_media_v2_topology *compat, const struct media_v2_topology *native)
{

	compat->topology_version = native->topology_version;
	compat->num_entities = native->num_entities;
	compat->reserved1 = native->reserved1;
	compat->ptr_entities = (__c64_ptr64 __force)native->ptr_entities;
	compat->num_interfaces = native->num_interfaces;
	compat->reserved2 = native->reserved2;
	compat->ptr_interfaces = (__c64_ptr64 __force)native->ptr_interfaces;
	compat->num_pads = native->num_pads;
	compat->reserved3 = native->reserved3;
	compat->ptr_pads = (__c64_ptr64 __force)native->ptr_pads;
	compat->num_links = native->num_links;
	compat->reserved4 = native->reserved4;
	compat->ptr_links = (__c64_ptr64 __force)native->ptr_links;
}
