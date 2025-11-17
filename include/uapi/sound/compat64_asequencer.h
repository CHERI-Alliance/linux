#pragma once


#include <linux/compat.h>


struct __c64_snd_seq_ev_ext {
	unsigned int len;	/* length of data */
	__c64_uptr ptr;		/* pointer to data (note: maybe 64-bit) */
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_snd_seq_ev_ext(struct snd_seq_ev_ext *p)
{
	union {
		struct snd_seq_ev_ext native;
		const struct __c64_snd_seq_ev_ext compat;
	} *u = (void *)p;

	u->native.ptr =  compat_ptr(u->compat.ptr);
	u->native.len = u->compat.len;
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_ev_ext(struct snd_seq_ev_ext *p)
{
	union {
		struct __c64_snd_seq_ev_ext compat;
		const struct snd_seq_ev_ext native;
	} *u = (void *)p;

	u->compat.len = u->native.len;
	u->compat.ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.ptr;
}
static __always_inline __maybe_unused void
__from_c64_snd_seq_ev_ext_2(struct snd_seq_ev_ext *native, const struct __c64_snd_seq_ev_ext *compat)
{

	native->len = compat->len;
	native->ptr =  compat_ptr(compat->ptr);
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_ev_ext_2(struct __c64_snd_seq_ev_ext *compat, const struct snd_seq_ev_ext *native)
{

	compat->len = native->len;
	compat->ptr =  (__c64_uptr __force)(user_uintptr_t)native->ptr;
}
struct __c64_snd_seq_ev_quote {
	struct snd_seq_addr origin;		/* original sender */
	unsigned short value;		/* optional data */
	__c64_uptr event;		/* quoted event */
} __attribute__((packed));

static __always_inline __maybe_unused void
__from_c64_snd_seq_ev_quote(struct snd_seq_ev_quote *p)
{
	union {
		struct snd_seq_ev_quote native;
		const struct __c64_snd_seq_ev_quote compat;
	} *u = (void *)p;

	u->native.event =  compat_ptr(u->compat.event);
	u->native.value = u->compat.value;
	BUILD_BUG_ON(sizeof(u->compat.origin) != sizeof(u->native.origin));
	memmove(&u->native.origin, &u->compat.origin, sizeof(u->native.origin));
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_ev_quote(struct snd_seq_ev_quote *p)
{
	union {
		struct __c64_snd_seq_ev_quote compat;
		const struct snd_seq_ev_quote native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.origin) != sizeof(u->compat.origin));
	memmove(&u->compat.origin, &u->native.origin, sizeof(u->compat.origin));
	u->compat.value = u->native.value;
	u->compat.event =  (__c64_uptr __force)(user_uintptr_t)u->native.event;
}
static __always_inline __maybe_unused void
__from_c64_snd_seq_ev_quote_2(struct snd_seq_ev_quote *native, const struct __c64_snd_seq_ev_quote *compat)
{

	BUILD_BUG_ON(sizeof(compat->origin) != sizeof(native->origin));
	memcpy(&native->origin, &compat->origin, sizeof(native->origin));
	native->value = compat->value;
	native->event =  compat_ptr(compat->event);
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_ev_quote_2(struct __c64_snd_seq_ev_quote *compat, const struct snd_seq_ev_quote *native)
{

	BUILD_BUG_ON(sizeof(native->origin) != sizeof(compat->origin));
	memcpy(&compat->origin, &native->origin, sizeof(compat->origin));
	compat->value = native->value;
	compat->event =  (__c64_uptr __force)(user_uintptr_t)native->event;
}
union __c64_snd_seq_event_data { /* event data... */
	struct snd_seq_ev_note note;
	struct snd_seq_ev_ctrl control;
	struct snd_seq_ev_raw8 raw8;
	struct snd_seq_ev_raw32 raw32;
	struct __c64_snd_seq_ev_ext ext;
	struct snd_seq_ev_queue_control queue;
	union snd_seq_timestamp time;
	struct snd_seq_addr addr;
	struct snd_seq_connect connect;
	struct snd_seq_result result;
	struct __c64_snd_seq_ev_quote quote;
	struct snd_seq_ev_ump_notify ump_notify;
};

struct __c64_snd_seq_event {
	snd_seq_event_type_t type;	/* event type */
	unsigned char flags;		/* event flags */
	char tag;
	
	unsigned char queue;		/* schedule queue */
	union snd_seq_timestamp time;	/* schedule time */

	struct snd_seq_addr source;	/* source address */
	struct snd_seq_addr dest;	/* destination address */

	union __c64_snd_seq_event_data data;
};

struct __c64_snd_seq_ump_event {
	snd_seq_event_type_t type;	/* event type */
	unsigned char flags;		/* event flags */
	char tag;
	unsigned char queue;		/* schedule queue */
	union snd_seq_timestamp time;	/* schedule time */
	struct snd_seq_addr source;	/* source address */
	struct snd_seq_addr dest;	/* destination address */

	union {
		union __c64_snd_seq_event_data data;
		unsigned int ump[4];
	};
};

struct __c64_snd_seq_event_bounce {
	int err;
	struct __c64_snd_seq_event event;
	/* external data follows here. */
};

struct __c64_snd_seq_port_info {
	struct snd_seq_addr addr;	/* client/port numbers */
	char name[64];			/* port name */

	unsigned int capability;	/* port capability bits */
	unsigned int type;		/* port type bits */
	int midi_channels;		/* channels per MIDI port */
	int midi_voices;		/* voices per MIDI port */
	int synth_voices;		/* voices per SYNTH port */

	int read_use;			/* R/O: subscribers for output (from this port) */
	int write_use;			/* R/O: subscribers for input (to this port) */

	__c64_uptr kernel;			/* reserved for kernel use (must be NULL) */
	unsigned int flags;		/* misc. conditioning */
	unsigned char time_queue;	/* queue # for timestamping */
	unsigned char direction;	/* port usage direction (r/w/bidir) */
	unsigned char ump_group;	/* 0 = UMP EP (no conversion), 1-16 = UMP group number */
	char reserved[57];		/* for future use */
};

static __always_inline __maybe_unused void
__from_c64_snd_seq_port_info(struct snd_seq_port_info *p)
{
	union {
		struct snd_seq_port_info native;
		const struct __c64_snd_seq_port_info compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.ump_group = u->compat.ump_group;
	u->native.direction = u->compat.direction;
	u->native.time_queue = u->compat.time_queue;
	u->native.flags = u->compat.flags;
	u->native.kernel =  compat_ptr(u->compat.kernel);
	u->native.write_use = u->compat.write_use;
	u->native.read_use = u->compat.read_use;
	u->native.synth_voices = u->compat.synth_voices;
	u->native.midi_voices = u->compat.midi_voices;
	u->native.midi_channels = u->compat.midi_channels;
	u->native.type = u->compat.type;
	u->native.capability = u->compat.capability;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
	BUILD_BUG_ON(sizeof(u->compat.addr) != sizeof(u->native.addr));
	memmove(&u->native.addr, &u->compat.addr, sizeof(u->native.addr));
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_port_info(struct snd_seq_port_info *p)
{
	union {
		struct __c64_snd_seq_port_info compat;
		const struct snd_seq_port_info native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.addr) != sizeof(u->compat.addr));
	memmove(&u->compat.addr, &u->native.addr, sizeof(u->compat.addr));
	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.capability = u->native.capability;
	u->compat.type = u->native.type;
	u->compat.midi_channels = u->native.midi_channels;
	u->compat.midi_voices = u->native.midi_voices;
	u->compat.synth_voices = u->native.synth_voices;
	u->compat.read_use = u->native.read_use;
	u->compat.write_use = u->native.write_use;
	u->compat.kernel =  (__c64_uptr __force)(user_uintptr_t)u->native.kernel;
	u->compat.flags = u->native.flags;
	u->compat.time_queue = u->native.time_queue;
	u->compat.direction = u->native.direction;
	u->compat.ump_group = u->native.ump_group;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_snd_seq_port_info_2(struct snd_seq_port_info *native, const struct __c64_snd_seq_port_info *compat)
{

	BUILD_BUG_ON(sizeof(compat->addr) != sizeof(native->addr));
	memcpy(&native->addr, &compat->addr, sizeof(native->addr));
	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->capability = compat->capability;
	native->type = compat->type;
	native->midi_channels = compat->midi_channels;
	native->midi_voices = compat->midi_voices;
	native->synth_voices = compat->synth_voices;
	native->read_use = compat->read_use;
	native->write_use = compat->write_use;
	native->kernel =  compat_ptr(compat->kernel);
	native->flags = compat->flags;
	native->time_queue = compat->time_queue;
	native->direction = compat->direction;
	native->ump_group = compat->ump_group;
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_snd_seq_port_info_2(struct __c64_snd_seq_port_info *compat, const struct snd_seq_port_info *native)
{

	BUILD_BUG_ON(sizeof(native->addr) != sizeof(compat->addr));
	memcpy(&compat->addr, &native->addr, sizeof(compat->addr));
	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->capability = native->capability;
	compat->type = native->type;
	compat->midi_channels = native->midi_channels;
	compat->midi_voices = native->midi_voices;
	compat->synth_voices = native->synth_voices;
	compat->read_use = native->read_use;
	compat->write_use = native->write_use;
	compat->kernel =  (__c64_uptr __force)(user_uintptr_t)native->kernel;
	compat->flags = native->flags;
	compat->time_queue = native->time_queue;
	compat->direction = native->direction;
	compat->ump_group = native->ump_group;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
