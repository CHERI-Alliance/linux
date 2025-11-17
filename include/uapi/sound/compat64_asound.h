#pragma once


#include <linux/compat.h>


struct __c64_snd_hwdep_dsp_image {
	unsigned int index;		/* W: DSP index */
	unsigned char name[64];		/* W: ID (e.g. file name) */
	__c64_uptr image;	/* W: binary image */
	size_t length;			/* W: size of image in bytes */
	__c64_uptr driver_data;		/* W: driver-specific data */
};

static __always_inline __maybe_unused void
__from_c64_snd_hwdep_dsp_image(struct snd_hwdep_dsp_image *p)
{
	union {
		struct snd_hwdep_dsp_image native;
		const struct __c64_snd_hwdep_dsp_image compat;
	} *u = (void *)p;

	u->native.driver_data = (user_uintptr_t)compat_ptr(u->compat.driver_data);
	u->native.length = u->compat.length;
	u->native.image =  compat_ptr(u->compat.image);
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
	u->native.index = u->compat.index;
}
static __always_inline __maybe_unused void
__to_c64_snd_hwdep_dsp_image(struct snd_hwdep_dsp_image *p)
{
	union {
		struct __c64_snd_hwdep_dsp_image compat;
		const struct snd_hwdep_dsp_image native;
	} *u = (void *)p;

	u->compat.index = u->native.index;
	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.image =  (__c64_uptr __force)(user_uintptr_t)u->native.image;
	u->compat.length = u->native.length;
	u->compat.driver_data = (__c64_uptr __force)u->native.driver_data;
}
static __always_inline __maybe_unused void
__from_c64_snd_hwdep_dsp_image_2(struct snd_hwdep_dsp_image *native, const struct __c64_snd_hwdep_dsp_image *compat)
{

	native->index = compat->index;
	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->image =  compat_ptr(compat->image);
	native->length = compat->length;
	native->driver_data = (user_uintptr_t)compat_ptr(compat->driver_data);
}
static __always_inline __maybe_unused void
__to_c64_snd_hwdep_dsp_image_2(struct __c64_snd_hwdep_dsp_image *compat, const struct snd_hwdep_dsp_image *native)
{

	compat->index = native->index;
	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->image =  (__c64_uptr __force)(user_uintptr_t)native->image;
	compat->length = native->length;
	compat->driver_data = (__c64_uptr __force)native->driver_data;
}
struct __c64_snd_xferi {
	snd_pcm_sframes_t result;
	__c64_uptr buf;
	snd_pcm_uframes_t frames;
};

static __always_inline __maybe_unused void
__from_c64_snd_xferi(struct snd_xferi *p)
{
	union {
		struct snd_xferi native;
		const struct __c64_snd_xferi compat;
	} *u = (void *)p;

	u->native.frames = u->compat.frames;
	u->native.buf =  compat_ptr(u->compat.buf);
	u->native.result = u->compat.result;
}
static __always_inline __maybe_unused void
__to_c64_snd_xferi(struct snd_xferi *p)
{
	union {
		struct __c64_snd_xferi compat;
		const struct snd_xferi native;
	} *u = (void *)p;

	u->compat.result = u->native.result;
	u->compat.buf =  (__c64_uptr __force)(user_uintptr_t)u->native.buf;
	u->compat.frames = u->native.frames;
}
static __always_inline __maybe_unused void
__from_c64_snd_xferi_2(struct snd_xferi *native, const struct __c64_snd_xferi *compat)
{

	native->result = compat->result;
	native->buf =  compat_ptr(compat->buf);
	native->frames = compat->frames;
}
static __always_inline __maybe_unused void
__to_c64_snd_xferi_2(struct __c64_snd_xferi *compat, const struct snd_xferi *native)
{

	compat->result = native->result;
	compat->buf =  (__c64_uptr __force)(user_uintptr_t)native->buf;
	compat->frames = native->frames;
}
struct __c64_snd_xfern {
	snd_pcm_sframes_t result;
	__c64_uptr bufs;
	snd_pcm_uframes_t frames;
};

static __always_inline __maybe_unused void
__from_c64_snd_xfern(struct snd_xfern *p)
{
	union {
		struct snd_xfern native;
		const struct __c64_snd_xfern compat;
	} *u = (void *)p;

	u->native.frames = u->compat.frames;
	u->native.bufs =  compat_ptr(u->compat.bufs);
	u->native.result = u->compat.result;
}
static __always_inline __maybe_unused void
__to_c64_snd_xfern(struct snd_xfern *p)
{
	union {
		struct __c64_snd_xfern compat;
		const struct snd_xfern native;
	} *u = (void *)p;

	u->compat.result = u->native.result;
	u->compat.bufs =  (__c64_uptr __force)(user_uintptr_t)u->native.bufs;
	u->compat.frames = u->native.frames;
}
static __always_inline __maybe_unused void
__from_c64_snd_xfern_2(struct snd_xfern *native, const struct __c64_snd_xfern *compat)
{

	native->result = compat->result;
	native->bufs =  compat_ptr(compat->bufs);
	native->frames = compat->frames;
}
static __always_inline __maybe_unused void
__to_c64_snd_xfern_2(struct __c64_snd_xfern *compat, const struct snd_xfern *native)
{

	compat->result = native->result;
	compat->bufs =  (__c64_uptr __force)(user_uintptr_t)native->bufs;
	compat->frames = native->frames;
}
struct __c64_snd_ctl_elem_list {
	unsigned int offset;		/* W: first element ID to get */
	unsigned int space;		/* W: count of element IDs to get */
	unsigned int used;		/* R: count of element IDs set */
	unsigned int count;		/* R: count of all elements */
	__c64_uptr pids; /* R: IDs */
	unsigned char reserved[50];
};

static __always_inline __maybe_unused void
__from_c64_snd_ctl_elem_list(struct snd_ctl_elem_list *p)
{
	union {
		struct snd_ctl_elem_list native;
		const struct __c64_snd_ctl_elem_list compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
	u->native.pids =  compat_ptr(u->compat.pids);
	u->native.count = u->compat.count;
	u->native.used = u->compat.used;
	u->native.space = u->compat.space;
	u->native.offset = u->compat.offset;
}
static __always_inline __maybe_unused void
__to_c64_snd_ctl_elem_list(struct snd_ctl_elem_list *p)
{
	union {
		struct __c64_snd_ctl_elem_list compat;
		const struct snd_ctl_elem_list native;
	} *u = (void *)p;

	u->compat.offset = u->native.offset;
	u->compat.space = u->native.space;
	u->compat.used = u->native.used;
	u->compat.count = u->native.count;
	u->compat.pids =  (__c64_uptr __force)(user_uintptr_t)u->native.pids;
	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
}
static __always_inline __maybe_unused void
__from_c64_snd_ctl_elem_list_2(struct snd_ctl_elem_list *native, const struct __c64_snd_ctl_elem_list *compat)
{

	native->offset = compat->offset;
	native->space = compat->space;
	native->used = compat->used;
	native->count = compat->count;
	native->pids =  compat_ptr(compat->pids);
	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
}
static __always_inline __maybe_unused void
__to_c64_snd_ctl_elem_list_2(struct __c64_snd_ctl_elem_list *compat, const struct snd_ctl_elem_list *native)
{

	compat->offset = native->offset;
	compat->space = native->space;
	compat->used = native->used;
	compat->count = native->count;
	compat->pids =  (__c64_uptr __force)(user_uintptr_t)native->pids;
	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
}
struct __c64_snd_ctl_elem_info {
	struct snd_ctl_elem_id id;	/* W: element ID */
	snd_ctl_elem_type_t type;	/* R: value type - SNDRV_CTL_ELEM_TYPE_* */
	unsigned int access;		/* R: value access (bitmask) - SNDRV_CTL_ELEM_ACCESS_* */
	unsigned int count;		/* count of values */
	__kernel_pid_t owner;		/* owner's PID of this control */
	union {
		struct {
			long min;		/* R: minimum value */
			long max;		/* R: maximum value */
			long step;		/* R: step (0 variable) */
		} integer;
		struct {
			long long min;		/* R: minimum value */
			long long max;		/* R: maximum value */
			long long step;		/* R: step (0 variable) */
		} integer64;
		struct {
			unsigned int items;	/* R: number of items */
			unsigned int item;	/* W: item number */
			char name[64];		/* R: value name */
			__c64_ptr64 names_ptr;	/* W: names list (ELEM_ADD only) */
			unsigned int names_length;
		} enumerated;
		unsigned char reserved[128];
	} value;
	unsigned char reserved[64];
};

struct __c64_snd_ctl_elem_value {
	struct snd_ctl_elem_id id;	/* W: element ID */
	unsigned int indirect: 1;	/* W: indirect access - obsoleted */
	union {
		union {
			long value[128];
			__c64_uptr value_ptr;	/* obsoleted */
		} integer;
		union {
			long long value[64];
			__c64_uptr value_ptr;	/* obsoleted */
		} integer64;
		union {
			unsigned int item[128];
			__c64_uptr item_ptr;	/* obsoleted */
		} enumerated;
		union {
			unsigned char data[512];
			__c64_uptr data_ptr;	/* obsoleted */
		} bytes;
		struct snd_aes_iec958 iec958;
	} value;		/* RO */
	unsigned char reserved[128];
};

