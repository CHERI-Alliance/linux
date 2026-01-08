#pragma once


#include <linux/compat.h>


struct __c64_fw_cdev_event_common {
	__c64_ptr64 closure;
	__u32 type;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_common(struct fw_cdev_event_common *p)
{
	union {
		struct fw_cdev_event_common native;
		const struct __c64_fw_cdev_event_common compat;
	} *u = (void *)p;

	u->native.type = u->compat.type;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_common(struct fw_cdev_event_common *p)
{
	union {
		struct __c64_fw_cdev_event_common compat;
		const struct fw_cdev_event_common native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.type = u->native.type;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_common_2(struct fw_cdev_event_common *native, const struct __c64_fw_cdev_event_common *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->type = compat->type;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_common_2(struct __c64_fw_cdev_event_common *compat, const struct fw_cdev_event_common *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->type = native->type;
}
struct __c64_fw_cdev_event_bus_reset {
	__c64_ptr64 closure;
	__u32 type;
	__u32 node_id;
	__u32 local_node_id;
	__u32 bm_node_id;
	__u32 irm_node_id;
	__u32 root_node_id;
	__u32 generation;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_bus_reset(struct fw_cdev_event_bus_reset *p)
{
	union {
		struct fw_cdev_event_bus_reset native;
		const struct __c64_fw_cdev_event_bus_reset compat;
	} *u = (void *)p;

	u->native.generation = u->compat.generation;
	u->native.root_node_id = u->compat.root_node_id;
	u->native.irm_node_id = u->compat.irm_node_id;
	u->native.bm_node_id = u->compat.bm_node_id;
	u->native.local_node_id = u->compat.local_node_id;
	u->native.node_id = u->compat.node_id;
	u->native.type = u->compat.type;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_bus_reset(struct fw_cdev_event_bus_reset *p)
{
	union {
		struct __c64_fw_cdev_event_bus_reset compat;
		const struct fw_cdev_event_bus_reset native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.type = u->native.type;
	u->compat.node_id = u->native.node_id;
	u->compat.local_node_id = u->native.local_node_id;
	u->compat.bm_node_id = u->native.bm_node_id;
	u->compat.irm_node_id = u->native.irm_node_id;
	u->compat.root_node_id = u->native.root_node_id;
	u->compat.generation = u->native.generation;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_bus_reset_2(struct fw_cdev_event_bus_reset *native, const struct __c64_fw_cdev_event_bus_reset *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->type = compat->type;
	native->node_id = compat->node_id;
	native->local_node_id = compat->local_node_id;
	native->bm_node_id = compat->bm_node_id;
	native->irm_node_id = compat->irm_node_id;
	native->root_node_id = compat->root_node_id;
	native->generation = compat->generation;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_bus_reset_2(struct __c64_fw_cdev_event_bus_reset *compat, const struct fw_cdev_event_bus_reset *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->type = native->type;
	compat->node_id = native->node_id;
	compat->local_node_id = native->local_node_id;
	compat->bm_node_id = native->bm_node_id;
	compat->irm_node_id = native->irm_node_id;
	compat->root_node_id = native->root_node_id;
	compat->generation = native->generation;
}
struct __c64_fw_cdev_event_response {
	__c64_ptr64 closure;
	__u32 type;
	__u32 rcode;
	__u32 length;
	__u32 data[];
};

struct __c64_fw_cdev_event_response2 {
	__c64_ptr64 closure;
	__u32 type;
	__u32 rcode;
	__u32 length;
	__u32 request_tstamp;
	__u32 response_tstamp;
	__u32 padding;
	__u32 data[];
};

struct __c64_fw_cdev_event_request {
	__c64_ptr64 closure;
	__u32 type;
	__u32 tcode;
	__u64 offset;
	__u32 handle;
	__u32 length;
	__u32 data[];
};

struct __c64_fw_cdev_event_request2 {
	__c64_ptr64 closure;
	__u32 type;
	__u32 tcode;
	__u64 offset;
	__u32 source_node_id;
	__u32 destination_node_id;
	__u32 card;
	__u32 generation;
	__u32 handle;
	__u32 length;
	__u32 data[];
};

struct __c64_fw_cdev_event_request3 {
	__c64_ptr64 closure;
	__u32 type;
	__u32 tcode;
	__u64 offset;
	__u32 source_node_id;
	__u32 destination_node_id;
	__u32 card;
	__u32 generation;
	__u32 handle;
	__u32 length;
	__u32 tstamp;
	__u32 padding;
	__u32 data[];
};

struct __c64_fw_cdev_event_iso_interrupt {
	__c64_ptr64 closure;
	__u32 type;
	__u32 cycle;
	__u32 header_length;
	__u32 header[];
};

struct __c64_fw_cdev_event_iso_interrupt_mc {
	__c64_ptr64 closure;
	__u32 type;
	__u32 completed;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_iso_interrupt_mc(struct fw_cdev_event_iso_interrupt_mc *p)
{
	union {
		struct fw_cdev_event_iso_interrupt_mc native;
		const struct __c64_fw_cdev_event_iso_interrupt_mc compat;
	} *u = (void *)p;

	u->native.completed = u->compat.completed;
	u->native.type = u->compat.type;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_iso_interrupt_mc(struct fw_cdev_event_iso_interrupt_mc *p)
{
	union {
		struct __c64_fw_cdev_event_iso_interrupt_mc compat;
		const struct fw_cdev_event_iso_interrupt_mc native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.type = u->native.type;
	u->compat.completed = u->native.completed;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_iso_interrupt_mc_2(struct fw_cdev_event_iso_interrupt_mc *native, const struct __c64_fw_cdev_event_iso_interrupt_mc *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->type = compat->type;
	native->completed = compat->completed;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_iso_interrupt_mc_2(struct __c64_fw_cdev_event_iso_interrupt_mc *compat, const struct fw_cdev_event_iso_interrupt_mc *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->type = native->type;
	compat->completed = native->completed;
}
struct __c64_fw_cdev_event_iso_resource {
	__c64_ptr64 closure;
	__u32 type;
	__u32 handle;
	__s32 channel;
	__s32 bandwidth;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_iso_resource(struct fw_cdev_event_iso_resource *p)
{
	union {
		struct fw_cdev_event_iso_resource native;
		const struct __c64_fw_cdev_event_iso_resource compat;
	} *u = (void *)p;

	u->native.bandwidth = u->compat.bandwidth;
	u->native.channel = u->compat.channel;
	u->native.handle = u->compat.handle;
	u->native.type = u->compat.type;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_iso_resource(struct fw_cdev_event_iso_resource *p)
{
	union {
		struct __c64_fw_cdev_event_iso_resource compat;
		const struct fw_cdev_event_iso_resource native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.type = u->native.type;
	u->compat.handle = u->native.handle;
	u->compat.channel = u->native.channel;
	u->compat.bandwidth = u->native.bandwidth;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_event_iso_resource_2(struct fw_cdev_event_iso_resource *native, const struct __c64_fw_cdev_event_iso_resource *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->type = compat->type;
	native->handle = compat->handle;
	native->channel = compat->channel;
	native->bandwidth = compat->bandwidth;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_event_iso_resource_2(struct __c64_fw_cdev_event_iso_resource *compat, const struct fw_cdev_event_iso_resource *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->type = native->type;
	compat->handle = native->handle;
	compat->channel = native->channel;
	compat->bandwidth = native->bandwidth;
}
struct __c64_fw_cdev_event_phy_packet {
	__c64_ptr64 closure;
	__u32 type;
	__u32 rcode;
	__u32 length;
	__u32 data[];
};

struct __c64_fw_cdev_event_phy_packet2 {
	__c64_ptr64 closure;
	__u32 type;
	__u32 rcode;
	__u32 length;
	__u32 tstamp;
	__u32 data[];
};

union __c64_fw_cdev_event {
	struct __c64_fw_cdev_event_common		common;
	struct __c64_fw_cdev_event_bus_reset		bus_reset;
	struct __c64_fw_cdev_event_response		response;
	struct __c64_fw_cdev_event_request		request;
	struct __c64_fw_cdev_event_request2		request2;		/* added in 2.6.36 */
	struct __c64_fw_cdev_event_iso_interrupt	iso_interrupt;
	struct __c64_fw_cdev_event_iso_interrupt_mc	iso_interrupt_mc;	/* added in 2.6.36 */
	struct __c64_fw_cdev_event_iso_resource	iso_resource;		/* added in 2.6.30 */
	struct __c64_fw_cdev_event_phy_packet		phy_packet;		/* added in 2.6.36 */
	struct __c64_fw_cdev_event_request3		request3;		/* added in 6.5 */
	struct __c64_fw_cdev_event_response2		response2;		/* added in 6.5 */
	struct __c64_fw_cdev_event_phy_packet2	phy_packet2;		/* added in 6.5 */
};

struct __c64_fw_cdev_get_info {
	__u32 version;
	__u32 rom_length;
	__c64_ptr64 rom;
	__c64_ptr64 bus_reset;
	__c64_ptr64 bus_reset_closure;
	__u32 card;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_get_info(struct fw_cdev_get_info *p)
{
	union {
		struct fw_cdev_get_info native;
		const struct __c64_fw_cdev_get_info compat;
	} *u = (void *)p;

	u->native.card = u->compat.card;
	u->native.bus_reset_closure = (user_uintptr_t)compat_ptr(u->compat.bus_reset_closure);
	u->native.bus_reset = (user_uintptr_t)compat_ptr(u->compat.bus_reset);
	u->native.rom = (user_uintptr_t)compat_ptr(u->compat.rom);
	u->native.rom_length = u->compat.rom_length;
	u->native.version = u->compat.version;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_get_info(struct fw_cdev_get_info *p)
{
	union {
		struct __c64_fw_cdev_get_info compat;
		const struct fw_cdev_get_info native;
	} *u = (void *)p;

	u->compat.version = u->native.version;
	u->compat.rom_length = u->native.rom_length;
	u->compat.rom = (__c64_ptr64 __force)u->native.rom;
	u->compat.bus_reset = (__c64_ptr64 __force)u->native.bus_reset;
	u->compat.bus_reset_closure = (__c64_ptr64 __force)u->native.bus_reset_closure;
	u->compat.card = u->native.card;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_get_info_2(struct fw_cdev_get_info *native, const struct __c64_fw_cdev_get_info *compat)
{

	native->version = compat->version;
	native->rom_length = compat->rom_length;
	native->rom = (user_uintptr_t)compat_ptr(compat->rom);
	native->bus_reset = (user_uintptr_t)compat_ptr(compat->bus_reset);
	native->bus_reset_closure = (user_uintptr_t)compat_ptr(compat->bus_reset_closure);
	native->card = compat->card;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_get_info_2(struct __c64_fw_cdev_get_info *compat, const struct fw_cdev_get_info *native)
{

	compat->version = native->version;
	compat->rom_length = native->rom_length;
	compat->rom = (__c64_ptr64 __force)native->rom;
	compat->bus_reset = (__c64_ptr64 __force)native->bus_reset;
	compat->bus_reset_closure = (__c64_ptr64 __force)native->bus_reset_closure;
	compat->card = native->card;
}
struct __c64_fw_cdev_send_request {
	__u32 tcode;
	__u32 length;
	__u64 offset;
	__c64_ptr64 closure;
	__c64_ptr64 data;
	__u32 generation;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_request(struct fw_cdev_send_request *p)
{
	union {
		struct fw_cdev_send_request native;
		const struct __c64_fw_cdev_send_request compat;
	} *u = (void *)p;

	u->native.generation = u->compat.generation;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
	u->native.offset = u->compat.offset;
	u->native.length = u->compat.length;
	u->native.tcode = u->compat.tcode;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_request(struct fw_cdev_send_request *p)
{
	union {
		struct __c64_fw_cdev_send_request compat;
		const struct fw_cdev_send_request native;
	} *u = (void *)p;

	u->compat.tcode = u->native.tcode;
	u->compat.length = u->native.length;
	u->compat.offset = u->native.offset;
	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.generation = u->native.generation;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_request_2(struct fw_cdev_send_request *native, const struct __c64_fw_cdev_send_request *compat)
{

	native->tcode = compat->tcode;
	native->length = compat->length;
	native->offset = compat->offset;
	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->generation = compat->generation;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_request_2(struct __c64_fw_cdev_send_request *compat, const struct fw_cdev_send_request *native)
{

	compat->tcode = native->tcode;
	compat->length = native->length;
	compat->offset = native->offset;
	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->generation = native->generation;
}
struct __c64_fw_cdev_send_response {
	__u32 rcode;
	__u32 length;
	__c64_ptr64 data;
	__u32 handle;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_response(struct fw_cdev_send_response *p)
{
	union {
		struct fw_cdev_send_response native;
		const struct __c64_fw_cdev_send_response compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.length = u->compat.length;
	u->native.rcode = u->compat.rcode;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_response(struct fw_cdev_send_response *p)
{
	union {
		struct __c64_fw_cdev_send_response compat;
		const struct fw_cdev_send_response native;
	} *u = (void *)p;

	u->compat.rcode = u->native.rcode;
	u->compat.length = u->native.length;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_response_2(struct fw_cdev_send_response *native, const struct __c64_fw_cdev_send_response *compat)
{

	native->rcode = compat->rcode;
	native->length = compat->length;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_response_2(struct __c64_fw_cdev_send_response *compat, const struct fw_cdev_send_response *native)
{

	compat->rcode = native->rcode;
	compat->length = native->length;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->handle = native->handle;
}
struct __c64_fw_cdev_allocate {
	__u64 offset;
	__c64_ptr64 closure;
	__u32 length;
	__u32 handle;
	__u64 region_end;	/* available since kernel version 2.6.36 */
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_allocate(struct fw_cdev_allocate *p)
{
	union {
		struct fw_cdev_allocate native;
		const struct __c64_fw_cdev_allocate compat;
	} *u = (void *)p;

	u->native.region_end = u->compat.region_end;
	u->native.handle = u->compat.handle;
	u->native.length = u->compat.length;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_allocate(struct fw_cdev_allocate *p)
{
	union {
		struct __c64_fw_cdev_allocate compat;
		const struct fw_cdev_allocate native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.length = u->native.length;
	u->compat.handle = u->native.handle;
	u->compat.region_end = u->native.region_end;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_allocate_2(struct fw_cdev_allocate *native, const struct __c64_fw_cdev_allocate *compat)
{

	native->offset = compat->offset;
	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->length = compat->length;
	native->handle = compat->handle;
	native->region_end = compat->region_end;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_allocate_2(struct __c64_fw_cdev_allocate *compat, const struct fw_cdev_allocate *native)
{

	compat->offset = native->offset;
	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->length = native->length;
	compat->handle = native->handle;
	compat->region_end = native->region_end;
}
struct __c64_fw_cdev_add_descriptor {
	__u32 immediate;
	__u32 key;
	__c64_ptr64 data;
	__u32 length;
	__u32 handle;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_add_descriptor(struct fw_cdev_add_descriptor *p)
{
	union {
		struct fw_cdev_add_descriptor native;
		const struct __c64_fw_cdev_add_descriptor compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.length = u->compat.length;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.key = u->compat.key;
	u->native.immediate = u->compat.immediate;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_add_descriptor(struct fw_cdev_add_descriptor *p)
{
	union {
		struct __c64_fw_cdev_add_descriptor compat;
		const struct fw_cdev_add_descriptor native;
	} *u = (void *)p;

	u->compat.immediate = u->native.immediate;
	u->compat.key = u->native.key;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.length = u->native.length;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_add_descriptor_2(struct fw_cdev_add_descriptor *native, const struct __c64_fw_cdev_add_descriptor *compat)
{

	native->immediate = compat->immediate;
	native->key = compat->key;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->length = compat->length;
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_add_descriptor_2(struct __c64_fw_cdev_add_descriptor *compat, const struct fw_cdev_add_descriptor *native)
{

	compat->immediate = native->immediate;
	compat->key = native->key;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->length = native->length;
	compat->handle = native->handle;
}
struct __c64_fw_cdev_create_iso_context {
	__u32 type;
	__u32 header_size;
	__u32 channel;
	__u32 speed;
	__c64_ptr64 closure;
	__u32 handle;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_create_iso_context(struct fw_cdev_create_iso_context *p)
{
	union {
		struct fw_cdev_create_iso_context native;
		const struct __c64_fw_cdev_create_iso_context compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
	u->native.speed = u->compat.speed;
	u->native.channel = u->compat.channel;
	u->native.header_size = u->compat.header_size;
	u->native.type = u->compat.type;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_create_iso_context(struct fw_cdev_create_iso_context *p)
{
	union {
		struct __c64_fw_cdev_create_iso_context compat;
		const struct fw_cdev_create_iso_context native;
	} *u = (void *)p;

	u->compat.type = u->native.type;
	u->compat.header_size = u->native.header_size;
	u->compat.channel = u->native.channel;
	u->compat.speed = u->native.speed;
	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_create_iso_context_2(struct fw_cdev_create_iso_context *native, const struct __c64_fw_cdev_create_iso_context *compat)
{

	native->type = compat->type;
	native->header_size = compat->header_size;
	native->channel = compat->channel;
	native->speed = compat->speed;
	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_create_iso_context_2(struct __c64_fw_cdev_create_iso_context *compat, const struct fw_cdev_create_iso_context *native)
{

	compat->type = native->type;
	compat->header_size = native->header_size;
	compat->channel = native->channel;
	compat->speed = native->speed;
	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->handle = native->handle;
}
struct __c64_fw_cdev_queue_iso {
	__c64_ptr64 packets;
	__u64 data;
	__u32 size;
	__u32 handle;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_queue_iso(struct fw_cdev_queue_iso *p)
{
	union {
		struct fw_cdev_queue_iso native;
		const struct __c64_fw_cdev_queue_iso compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.size = u->compat.size;
	u->native.data = u->compat.data;
	u->native.packets = (user_uintptr_t)compat_ptr(u->compat.packets);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_queue_iso(struct fw_cdev_queue_iso *p)
{
	union {
		struct __c64_fw_cdev_queue_iso compat;
		const struct fw_cdev_queue_iso native;
	} *u = (void *)p;

	u->compat.packets = (__c64_ptr64 __force)u->native.packets;
	u->compat.data = u->native.data;
	u->compat.size = u->native.size;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_queue_iso_2(struct fw_cdev_queue_iso *native, const struct __c64_fw_cdev_queue_iso *compat)
{

	native->packets = (user_uintptr_t)compat_ptr(compat->packets);
	native->data = compat->data;
	native->size = compat->size;
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_queue_iso_2(struct __c64_fw_cdev_queue_iso *compat, const struct fw_cdev_queue_iso *native)
{

	compat->packets = (__c64_ptr64 __force)native->packets;
	compat->data = native->data;
	compat->size = native->size;
	compat->handle = native->handle;
}
struct __c64_fw_cdev_allocate_iso_resource {
	__c64_ptr64 closure;
	__u64 channels;
	__u32 bandwidth;
	__u32 handle;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_allocate_iso_resource(struct fw_cdev_allocate_iso_resource *p)
{
	union {
		struct fw_cdev_allocate_iso_resource native;
		const struct __c64_fw_cdev_allocate_iso_resource compat;
	} *u = (void *)p;

	u->native.handle = u->compat.handle;
	u->native.bandwidth = u->compat.bandwidth;
	u->native.channels = u->compat.channels;
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_allocate_iso_resource(struct fw_cdev_allocate_iso_resource *p)
{
	union {
		struct __c64_fw_cdev_allocate_iso_resource compat;
		const struct fw_cdev_allocate_iso_resource native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.channels = u->native.channels;
	u->compat.bandwidth = u->native.bandwidth;
	u->compat.handle = u->native.handle;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_allocate_iso_resource_2(struct fw_cdev_allocate_iso_resource *native, const struct __c64_fw_cdev_allocate_iso_resource *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->channels = compat->channels;
	native->bandwidth = compat->bandwidth;
	native->handle = compat->handle;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_allocate_iso_resource_2(struct __c64_fw_cdev_allocate_iso_resource *compat, const struct fw_cdev_allocate_iso_resource *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->channels = native->channels;
	compat->bandwidth = native->bandwidth;
	compat->handle = native->handle;
}
struct __c64_fw_cdev_send_stream_packet {
	__u32 length;
	__u32 tag;
	__u32 channel;
	__u32 sy;
	__c64_ptr64 closure;
	__c64_ptr64 data;
	__u32 generation;
	__u32 speed;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_stream_packet(struct fw_cdev_send_stream_packet *p)
{
	union {
		struct fw_cdev_send_stream_packet native;
		const struct __c64_fw_cdev_send_stream_packet compat;
	} *u = (void *)p;

	u->native.speed = u->compat.speed;
	u->native.generation = u->compat.generation;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
	u->native.sy = u->compat.sy;
	u->native.channel = u->compat.channel;
	u->native.tag = u->compat.tag;
	u->native.length = u->compat.length;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_stream_packet(struct fw_cdev_send_stream_packet *p)
{
	union {
		struct __c64_fw_cdev_send_stream_packet compat;
		const struct fw_cdev_send_stream_packet native;
	} *u = (void *)p;

	u->compat.length = u->native.length;
	u->compat.tag = u->native.tag;
	u->compat.channel = u->native.channel;
	u->compat.sy = u->native.sy;
	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.generation = u->native.generation;
	u->compat.speed = u->native.speed;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_stream_packet_2(struct fw_cdev_send_stream_packet *native, const struct __c64_fw_cdev_send_stream_packet *compat)
{

	native->length = compat->length;
	native->tag = compat->tag;
	native->channel = compat->channel;
	native->sy = compat->sy;
	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->generation = compat->generation;
	native->speed = compat->speed;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_stream_packet_2(struct __c64_fw_cdev_send_stream_packet *compat, const struct fw_cdev_send_stream_packet *native)
{

	compat->length = native->length;
	compat->tag = native->tag;
	compat->channel = native->channel;
	compat->sy = native->sy;
	compat->closure = (__c64_ptr64 __force)native->closure;
	compat->data = (__c64_ptr64 __force)native->data;
	compat->generation = native->generation;
	compat->speed = native->speed;
}
struct __c64_fw_cdev_send_phy_packet {
	__c64_ptr64 closure;
	__u32 data[2];
	__u32 generation;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_phy_packet(struct fw_cdev_send_phy_packet *p)
{
	union {
		struct fw_cdev_send_phy_packet native;
		const struct __c64_fw_cdev_send_phy_packet compat;
	} *u = (void *)p;

	u->native.generation = u->compat.generation;
	BUILD_BUG_ON(sizeof(u->compat.data) != sizeof(u->native.data));
	memmove(&u->native.data, &u->compat.data, sizeof(u->native.data));
	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_phy_packet(struct fw_cdev_send_phy_packet *p)
{
	union {
		struct __c64_fw_cdev_send_phy_packet compat;
		const struct fw_cdev_send_phy_packet native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
	BUILD_BUG_ON(sizeof(u->native.data) != sizeof(u->compat.data));
	memmove(&u->compat.data, &u->native.data, sizeof(u->compat.data));
	u->compat.generation = u->native.generation;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_send_phy_packet_2(struct fw_cdev_send_phy_packet *native, const struct __c64_fw_cdev_send_phy_packet *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
	BUILD_BUG_ON(sizeof(compat->data) != sizeof(native->data));
	memcpy(&native->data, &compat->data, sizeof(native->data));
	native->generation = compat->generation;
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_send_phy_packet_2(struct __c64_fw_cdev_send_phy_packet *compat, const struct fw_cdev_send_phy_packet *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
	BUILD_BUG_ON(sizeof(native->data) != sizeof(compat->data));
	memcpy(&compat->data, &native->data, sizeof(compat->data));
	compat->generation = native->generation;
}
struct __c64_fw_cdev_receive_phy_packets {
	__c64_ptr64 closure;
};

static __always_inline __maybe_unused void
__from_c64_fw_cdev_receive_phy_packets(struct fw_cdev_receive_phy_packets *p)
{
	union {
		struct fw_cdev_receive_phy_packets native;
		const struct __c64_fw_cdev_receive_phy_packets compat;
	} *u = (void *)p;

	u->native.closure = (user_uintptr_t)compat_ptr(u->compat.closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_receive_phy_packets(struct fw_cdev_receive_phy_packets *p)
{
	union {
		struct __c64_fw_cdev_receive_phy_packets compat;
		const struct fw_cdev_receive_phy_packets native;
	} *u = (void *)p;

	u->compat.closure = (__c64_ptr64 __force)u->native.closure;
}
static __always_inline __maybe_unused void
__from_c64_fw_cdev_receive_phy_packets_2(struct fw_cdev_receive_phy_packets *native, const struct __c64_fw_cdev_receive_phy_packets *compat)
{

	native->closure = (user_uintptr_t)compat_ptr(compat->closure);
}
static __always_inline __maybe_unused void
__to_c64_fw_cdev_receive_phy_packets_2(struct __c64_fw_cdev_receive_phy_packets *compat, const struct fw_cdev_receive_phy_packets *native)
{

	compat->closure = (__c64_ptr64 __force)native->closure;
}
