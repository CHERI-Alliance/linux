#pragma once


#include <linux/compat.h>


struct __c64_consolefontdesc {
	unsigned short charcount;	/* characters in font (256 or 512) */
	unsigned short charheight;	/* scan lines per character (1-32) */
	__c64_uptr chardata;		/* font data in expanded form */
};

static __always_inline __maybe_unused void
__from_c64_consolefontdesc(struct consolefontdesc *p)
{
	union {
		struct consolefontdesc native;
		const struct __c64_consolefontdesc compat;
	} *u = (void *)p;

	u->native.chardata =  compat_ptr(u->compat.chardata);
	u->native.charheight = u->compat.charheight;
	u->native.charcount = u->compat.charcount;
}
static __always_inline __maybe_unused void
__to_c64_consolefontdesc(struct consolefontdesc *p)
{
	union {
		struct __c64_consolefontdesc compat;
		const struct consolefontdesc native;
	} *u = (void *)p;

	u->compat.charcount = u->native.charcount;
	u->compat.charheight = u->native.charheight;
	u->compat.chardata =  (__c64_uptr __force)(user_uintptr_t)u->native.chardata;
}
static __always_inline __maybe_unused void
__from_c64_consolefontdesc_2(struct consolefontdesc *native, const struct __c64_consolefontdesc *compat)
{

	native->charcount = compat->charcount;
	native->charheight = compat->charheight;
	native->chardata =  compat_ptr(compat->chardata);
}
static __always_inline __maybe_unused void
__to_c64_consolefontdesc_2(struct __c64_consolefontdesc *compat, const struct consolefontdesc *native)
{

	compat->charcount = native->charcount;
	compat->charheight = native->charheight;
	compat->chardata =  (__c64_uptr __force)(user_uintptr_t)native->chardata;
}
struct __c64_unimapdesc {
	unsigned short entry_ct;
	__c64_uptr entries;
};

static __always_inline __maybe_unused void
__from_c64_unimapdesc(struct unimapdesc *p)
{
	union {
		struct unimapdesc native;
		const struct __c64_unimapdesc compat;
	} *u = (void *)p;

	u->native.entries =  compat_ptr(u->compat.entries);
	u->native.entry_ct = u->compat.entry_ct;
}
static __always_inline __maybe_unused void
__to_c64_unimapdesc(struct unimapdesc *p)
{
	union {
		struct __c64_unimapdesc compat;
		const struct unimapdesc native;
	} *u = (void *)p;

	u->compat.entry_ct = u->native.entry_ct;
	u->compat.entries =  (__c64_uptr __force)(user_uintptr_t)u->native.entries;
}
static __always_inline __maybe_unused void
__from_c64_unimapdesc_2(struct unimapdesc *native, const struct __c64_unimapdesc *compat)
{

	native->entry_ct = compat->entry_ct;
	native->entries =  compat_ptr(compat->entries);
}
static __always_inline __maybe_unused void
__to_c64_unimapdesc_2(struct __c64_unimapdesc *compat, const struct unimapdesc *native)
{

	compat->entry_ct = native->entry_ct;
	compat->entries =  (__c64_uptr __force)(user_uintptr_t)native->entries;
}
struct __c64_console_font_op {
	unsigned int op;	/* operation code KD_FONT_OP_* */
	unsigned int flags;	/* KD_FONT_FLAG_* */
	unsigned int width, height;	/* font size */
	unsigned int charcount;
	__c64_uptr data;	/* font data with vpitch fixed to 32 for
					 * KD_FONT_OP_SET/GET
					 */
};

static __always_inline __maybe_unused void
__from_c64_console_font_op(struct console_font_op *p)
{
	union {
		struct console_font_op native;
		const struct __c64_console_font_op compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.charcount = u->compat.charcount;
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
	u->native.flags = u->compat.flags;
	u->native.op = u->compat.op;
}
static __always_inline __maybe_unused void
__to_c64_console_font_op(struct console_font_op *p)
{
	union {
		struct __c64_console_font_op compat;
		const struct console_font_op native;
	} *u = (void *)p;

	u->compat.op = u->native.op;
	u->compat.flags = u->native.flags;
	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.charcount = u->native.charcount;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_console_font_op_2(struct console_font_op *native, const struct __c64_console_font_op *compat)
{

	native->op = compat->op;
	native->flags = compat->flags;
	native->width = compat->width;
	native->height = compat->height;
	native->charcount = compat->charcount;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_console_font_op_2(struct __c64_console_font_op *compat, const struct console_font_op *native)
{

	compat->op = native->op;
	compat->flags = native->flags;
	compat->width = native->width;
	compat->height = native->height;
	compat->charcount = native->charcount;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_console_font {
	unsigned int width, height;	/* font size */
	unsigned int charcount;
	__c64_uptr data;	/* font data with vpitch fixed to 32 for
				 * KD_FONT_OP_SET/GET
				 */
};

static __always_inline __maybe_unused void
__from_c64_console_font(struct console_font *p)
{
	union {
		struct console_font native;
		const struct __c64_console_font compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.charcount = u->compat.charcount;
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
}
static __always_inline __maybe_unused void
__to_c64_console_font(struct console_font *p)
{
	union {
		struct __c64_console_font compat;
		const struct console_font native;
	} *u = (void *)p;

	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.charcount = u->native.charcount;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_console_font_2(struct console_font *native, const struct __c64_console_font *compat)
{

	native->width = compat->width;
	native->height = compat->height;
	native->charcount = compat->charcount;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_console_font_2(struct __c64_console_font *compat, const struct console_font *native)
{

	compat->width = native->width;
	compat->height = native->height;
	compat->charcount = native->charcount;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
