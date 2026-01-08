#pragma once


#include <linux/compat.h>


typedef struct __c64_osd_cmd_s {
	OSD_Command cmd;
	int x0;
	int y0;
	int x1;
	int y1;
	int color;
	__c64_uptr data;
} __c64_osd_cmd_t;

static __always_inline __maybe_unused void
__from_c64_osd_cmd_s(struct osd_cmd_s *p)
{
	union {
		struct osd_cmd_s native;
		const struct __c64_osd_cmd_s compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.color = u->compat.color;
	u->native.y1 = u->compat.y1;
	u->native.x1 = u->compat.x1;
	u->native.y0 = u->compat.y0;
	u->native.x0 = u->compat.x0;
	u->native.cmd = u->compat.cmd;
}
static __always_inline __maybe_unused void
__to_c64_osd_cmd_s(struct osd_cmd_s *p)
{
	union {
		struct __c64_osd_cmd_s compat;
		const struct osd_cmd_s native;
	} *u = (void *)p;

	u->compat.cmd = u->native.cmd;
	u->compat.x0 = u->native.x0;
	u->compat.y0 = u->native.y0;
	u->compat.x1 = u->native.x1;
	u->compat.y1 = u->native.y1;
	u->compat.color = u->native.color;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_osd_cmd_s_2(struct osd_cmd_s *native, const struct __c64_osd_cmd_s *compat)
{

	native->cmd = compat->cmd;
	native->x0 = compat->x0;
	native->y0 = compat->y0;
	native->x1 = compat->x1;
	native->y1 = compat->y1;
	native->color = compat->color;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_osd_cmd_s_2(struct __c64_osd_cmd_s *compat, const struct osd_cmd_s *native)
{

	compat->cmd = native->cmd;
	compat->x0 = native->x0;
	compat->y0 = native->y0;
	compat->x1 = native->x1;
	compat->y1 = native->y1;
	compat->color = native->color;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
