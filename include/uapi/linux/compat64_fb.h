#pragma once


#include <linux/compat.h>


struct __c64_fb_cmap {
	__u32 start;			/* First entry	*/
	__u32 len;			/* Number of entries */
	__c64_uptr red;			/* Red values	*/
	__c64_uptr green;
	__c64_uptr blue;
	__c64_uptr transp;			/* transparency, can be NULL */
};

static __always_inline __maybe_unused void
__from_c64_fb_cmap(struct fb_cmap *p)
{
	union {
		struct fb_cmap native;
		const struct __c64_fb_cmap compat;
	} *u = (void *)p;

	u->native.transp =  compat_ptr(u->compat.transp);
	u->native.blue =  compat_ptr(u->compat.blue);
	u->native.green =  compat_ptr(u->compat.green);
	u->native.red =  compat_ptr(u->compat.red);
	u->native.len = u->compat.len;
	u->native.start = u->compat.start;
}
static __always_inline __maybe_unused void
__to_c64_fb_cmap(struct fb_cmap *p)
{
	union {
		struct __c64_fb_cmap compat;
		const struct fb_cmap native;
	} *u = (void *)p;

	u->compat.start = u->native.start;
	u->compat.len = u->native.len;
	u->compat.red =  (__c64_uptr __force)(user_uintptr_t)u->native.red;
	u->compat.green =  (__c64_uptr __force)(user_uintptr_t)u->native.green;
	u->compat.blue =  (__c64_uptr __force)(user_uintptr_t)u->native.blue;
	u->compat.transp =  (__c64_uptr __force)(user_uintptr_t)u->native.transp;
}
static __always_inline __maybe_unused void
__from_c64_fb_cmap_2(struct fb_cmap *native, const struct __c64_fb_cmap *compat)
{

	native->start = compat->start;
	native->len = compat->len;
	native->red =  compat_ptr(compat->red);
	native->green =  compat_ptr(compat->green);
	native->blue =  compat_ptr(compat->blue);
	native->transp =  compat_ptr(compat->transp);
}
static __always_inline __maybe_unused void
__to_c64_fb_cmap_2(struct __c64_fb_cmap *compat, const struct fb_cmap *native)
{

	compat->start = native->start;
	compat->len = native->len;
	compat->red =  (__c64_uptr __force)(user_uintptr_t)native->red;
	compat->green =  (__c64_uptr __force)(user_uintptr_t)native->green;
	compat->blue =  (__c64_uptr __force)(user_uintptr_t)native->blue;
	compat->transp =  (__c64_uptr __force)(user_uintptr_t)native->transp;
}
struct __c64_fb_image {
	__u32 dx;		/* Where to place image */
	__u32 dy;
	__u32 width;		/* Size of image */
	__u32 height;
	__u32 fg_color;		/* Only used when a mono bitmap */
	__u32 bg_color;
	__u8  depth;		/* Depth of the image */
	__c64_uptr data;	/* Pointer to image data */
	struct __c64_fb_cmap cmap;	/* color map info */
};

static __always_inline __maybe_unused void
__from_c64_fb_image(struct fb_image *p)
{
	union {
		struct fb_image native;
		const struct __c64_fb_image compat;
	} *u = (void *)p;

	u->native.cmap.transp =  compat_ptr(u->compat.cmap.transp);
	u->native.cmap.blue =  compat_ptr(u->compat.cmap.blue);
	u->native.cmap.green =  compat_ptr(u->compat.cmap.green);
	u->native.cmap.red =  compat_ptr(u->compat.cmap.red);
	u->native.cmap.len = u->compat.cmap.len;
	u->native.cmap.start = u->compat.cmap.start;
	u->native.data =  compat_ptr(u->compat.data);
	u->native.depth = u->compat.depth;
	u->native.bg_color = u->compat.bg_color;
	u->native.fg_color = u->compat.fg_color;
	u->native.height = u->compat.height;
	u->native.width = u->compat.width;
	u->native.dy = u->compat.dy;
	u->native.dx = u->compat.dx;
}
static __always_inline __maybe_unused void
__to_c64_fb_image(struct fb_image *p)
{
	union {
		struct __c64_fb_image compat;
		const struct fb_image native;
	} *u = (void *)p;

	u->compat.dx = u->native.dx;
	u->compat.dy = u->native.dy;
	u->compat.width = u->native.width;
	u->compat.height = u->native.height;
	u->compat.fg_color = u->native.fg_color;
	u->compat.bg_color = u->native.bg_color;
	u->compat.depth = u->native.depth;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
	u->compat.cmap.start = u->native.cmap.start;
	u->compat.cmap.len = u->native.cmap.len;
	u->compat.cmap.red =  (__c64_uptr __force)(user_uintptr_t)u->native.cmap.red;
	u->compat.cmap.green =  (__c64_uptr __force)(user_uintptr_t)u->native.cmap.green;
	u->compat.cmap.blue =  (__c64_uptr __force)(user_uintptr_t)u->native.cmap.blue;
	u->compat.cmap.transp =  (__c64_uptr __force)(user_uintptr_t)u->native.cmap.transp;
}
static __always_inline __maybe_unused void
__from_c64_fb_image_2(struct fb_image *native, const struct __c64_fb_image *compat)
{

	native->dx = compat->dx;
	native->dy = compat->dy;
	native->width = compat->width;
	native->height = compat->height;
	native->fg_color = compat->fg_color;
	native->bg_color = compat->bg_color;
	native->depth = compat->depth;
	native->data =  compat_ptr(compat->data);
	native->cmap.start = compat->cmap.start;
	native->cmap.len = compat->cmap.len;
	native->cmap.red =  compat_ptr(compat->cmap.red);
	native->cmap.green =  compat_ptr(compat->cmap.green);
	native->cmap.blue =  compat_ptr(compat->cmap.blue);
	native->cmap.transp =  compat_ptr(compat->cmap.transp);
}
static __always_inline __maybe_unused void
__to_c64_fb_image_2(struct __c64_fb_image *compat, const struct fb_image *native)
{

	compat->dx = native->dx;
	compat->dy = native->dy;
	compat->width = native->width;
	compat->height = native->height;
	compat->fg_color = native->fg_color;
	compat->bg_color = native->bg_color;
	compat->depth = native->depth;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
	compat->cmap.start = native->cmap.start;
	compat->cmap.len = native->cmap.len;
	compat->cmap.red =  (__c64_uptr __force)(user_uintptr_t)native->cmap.red;
	compat->cmap.green =  (__c64_uptr __force)(user_uintptr_t)native->cmap.green;
	compat->cmap.blue =  (__c64_uptr __force)(user_uintptr_t)native->cmap.blue;
	compat->cmap.transp =  (__c64_uptr __force)(user_uintptr_t)native->cmap.transp;
}
struct __c64_fb_cursor {
	__u16 set;		/* what to set */
	__u16 enable;		/* cursor on/off */
	__u16 rop;		/* bitop operation */
	__c64_uptr mask;	/* cursor mask bits */
	struct fbcurpos hot;	/* cursor hot spot */
	struct __c64_fb_image	image;	/* Cursor image */
};

static __always_inline __maybe_unused void
__from_c64_fb_cursor(struct fb_cursor *p)
{
	union {
		struct fb_cursor native;
		const struct __c64_fb_cursor compat;
	} *u = (void *)p;

	u->native.image.cmap.transp =  compat_ptr(u->compat.image.cmap.transp);
	u->native.image.cmap.blue =  compat_ptr(u->compat.image.cmap.blue);
	u->native.image.cmap.green =  compat_ptr(u->compat.image.cmap.green);
	u->native.image.cmap.red =  compat_ptr(u->compat.image.cmap.red);
	u->native.image.cmap.len = u->compat.image.cmap.len;
	u->native.image.cmap.start = u->compat.image.cmap.start;
	u->native.image.data =  compat_ptr(u->compat.image.data);
	u->native.image.depth = u->compat.image.depth;
	u->native.image.bg_color = u->compat.image.bg_color;
	u->native.image.fg_color = u->compat.image.fg_color;
	u->native.image.height = u->compat.image.height;
	u->native.image.width = u->compat.image.width;
	u->native.image.dy = u->compat.image.dy;
	u->native.image.dx = u->compat.image.dx;
	BUILD_BUG_ON(sizeof(u->compat.hot) != sizeof(u->native.hot));
	memmove(&u->native.hot, &u->compat.hot, sizeof(u->native.hot));
	u->native.mask =  compat_ptr(u->compat.mask);
	u->native.rop = u->compat.rop;
	u->native.enable = u->compat.enable;
	u->native.set = u->compat.set;
}
static __always_inline __maybe_unused void
__to_c64_fb_cursor(struct fb_cursor *p)
{
	union {
		struct __c64_fb_cursor compat;
		const struct fb_cursor native;
	} *u = (void *)p;

	u->compat.set = u->native.set;
	u->compat.enable = u->native.enable;
	u->compat.rop = u->native.rop;
	u->compat.mask =  (__c64_uptr __force)(user_uintptr_t)u->native.mask;
	BUILD_BUG_ON(sizeof(u->native.hot) != sizeof(u->compat.hot));
	memmove(&u->compat.hot, &u->native.hot, sizeof(u->compat.hot));
	u->compat.image.dx = u->native.image.dx;
	u->compat.image.dy = u->native.image.dy;
	u->compat.image.width = u->native.image.width;
	u->compat.image.height = u->native.image.height;
	u->compat.image.fg_color = u->native.image.fg_color;
	u->compat.image.bg_color = u->native.image.bg_color;
	u->compat.image.depth = u->native.image.depth;
	u->compat.image.data =  (__c64_uptr __force)(user_uintptr_t)u->native.image.data;
	u->compat.image.cmap.start = u->native.image.cmap.start;
	u->compat.image.cmap.len = u->native.image.cmap.len;
	u->compat.image.cmap.red =  (__c64_uptr __force)(user_uintptr_t)u->native.image.cmap.red;
	u->compat.image.cmap.green =  (__c64_uptr __force)(user_uintptr_t)u->native.image.cmap.green;
	u->compat.image.cmap.blue =  (__c64_uptr __force)(user_uintptr_t)u->native.image.cmap.blue;
	u->compat.image.cmap.transp =  (__c64_uptr __force)(user_uintptr_t)u->native.image.cmap.transp;
}
static __always_inline __maybe_unused void
__from_c64_fb_cursor_2(struct fb_cursor *native, const struct __c64_fb_cursor *compat)
{

	native->set = compat->set;
	native->enable = compat->enable;
	native->rop = compat->rop;
	native->mask =  compat_ptr(compat->mask);
	BUILD_BUG_ON(sizeof(compat->hot) != sizeof(native->hot));
	memcpy(&native->hot, &compat->hot, sizeof(native->hot));
	native->image.dx = compat->image.dx;
	native->image.dy = compat->image.dy;
	native->image.width = compat->image.width;
	native->image.height = compat->image.height;
	native->image.fg_color = compat->image.fg_color;
	native->image.bg_color = compat->image.bg_color;
	native->image.depth = compat->image.depth;
	native->image.data =  compat_ptr(compat->image.data);
	native->image.cmap.start = compat->image.cmap.start;
	native->image.cmap.len = compat->image.cmap.len;
	native->image.cmap.red =  compat_ptr(compat->image.cmap.red);
	native->image.cmap.green =  compat_ptr(compat->image.cmap.green);
	native->image.cmap.blue =  compat_ptr(compat->image.cmap.blue);
	native->image.cmap.transp =  compat_ptr(compat->image.cmap.transp);
}
static __always_inline __maybe_unused void
__to_c64_fb_cursor_2(struct __c64_fb_cursor *compat, const struct fb_cursor *native)
{

	compat->set = native->set;
	compat->enable = native->enable;
	compat->rop = native->rop;
	compat->mask =  (__c64_uptr __force)(user_uintptr_t)native->mask;
	BUILD_BUG_ON(sizeof(native->hot) != sizeof(compat->hot));
	memcpy(&compat->hot, &native->hot, sizeof(compat->hot));
	compat->image.dx = native->image.dx;
	compat->image.dy = native->image.dy;
	compat->image.width = native->image.width;
	compat->image.height = native->image.height;
	compat->image.fg_color = native->image.fg_color;
	compat->image.bg_color = native->image.bg_color;
	compat->image.depth = native->image.depth;
	compat->image.data =  (__c64_uptr __force)(user_uintptr_t)native->image.data;
	compat->image.cmap.start = native->image.cmap.start;
	compat->image.cmap.len = native->image.cmap.len;
	compat->image.cmap.red =  (__c64_uptr __force)(user_uintptr_t)native->image.cmap.red;
	compat->image.cmap.green =  (__c64_uptr __force)(user_uintptr_t)native->image.cmap.green;
	compat->image.cmap.blue =  (__c64_uptr __force)(user_uintptr_t)native->image.cmap.blue;
	compat->image.cmap.transp =  (__c64_uptr __force)(user_uintptr_t)native->image.cmap.transp;
}
