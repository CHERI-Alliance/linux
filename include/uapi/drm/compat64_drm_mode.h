#pragma once


#include <linux/compat.h>


struct __c64_drm_mode_card_res {
	__c64_ptr64 fb_id_ptr;
	__c64_ptr64 crtc_id_ptr;
	__c64_ptr64 connector_id_ptr;
	__c64_ptr64 encoder_id_ptr;
	__u32 count_fbs;
	__u32 count_crtcs;
	__u32 count_connectors;
	__u32 count_encoders;
	__u32 min_width;
	__u32 max_width;
	__u32 min_height;
	__u32 max_height;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_card_res(struct drm_mode_card_res *p)
{
	union {
		struct drm_mode_card_res native;
		const struct __c64_drm_mode_card_res compat;
	} *u = (void *)p;

	u->native.max_height = u->compat.max_height;
	u->native.min_height = u->compat.min_height;
	u->native.max_width = u->compat.max_width;
	u->native.min_width = u->compat.min_width;
	u->native.count_encoders = u->compat.count_encoders;
	u->native.count_connectors = u->compat.count_connectors;
	u->native.count_crtcs = u->compat.count_crtcs;
	u->native.count_fbs = u->compat.count_fbs;
	u->native.encoder_id_ptr = (user_uintptr_t)compat_ptr(u->compat.encoder_id_ptr);
	u->native.connector_id_ptr = (user_uintptr_t)compat_ptr(u->compat.connector_id_ptr);
	u->native.crtc_id_ptr = (user_uintptr_t)compat_ptr(u->compat.crtc_id_ptr);
	u->native.fb_id_ptr = (user_uintptr_t)compat_ptr(u->compat.fb_id_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_card_res(struct drm_mode_card_res *p)
{
	union {
		struct __c64_drm_mode_card_res compat;
		const struct drm_mode_card_res native;
	} *u = (void *)p;

	u->compat.fb_id_ptr = (__c64_ptr64 __force)u->native.fb_id_ptr;
	u->compat.crtc_id_ptr = (__c64_ptr64 __force)u->native.crtc_id_ptr;
	u->compat.connector_id_ptr = (__c64_ptr64 __force)u->native.connector_id_ptr;
	u->compat.encoder_id_ptr = (__c64_ptr64 __force)u->native.encoder_id_ptr;
	u->compat.count_fbs = u->native.count_fbs;
	u->compat.count_crtcs = u->native.count_crtcs;
	u->compat.count_connectors = u->native.count_connectors;
	u->compat.count_encoders = u->native.count_encoders;
	u->compat.min_width = u->native.min_width;
	u->compat.max_width = u->native.max_width;
	u->compat.min_height = u->native.min_height;
	u->compat.max_height = u->native.max_height;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_card_res_2(struct drm_mode_card_res *native, const struct __c64_drm_mode_card_res *compat)
{

	native->fb_id_ptr = (user_uintptr_t)compat_ptr(compat->fb_id_ptr);
	native->crtc_id_ptr = (user_uintptr_t)compat_ptr(compat->crtc_id_ptr);
	native->connector_id_ptr = (user_uintptr_t)compat_ptr(compat->connector_id_ptr);
	native->encoder_id_ptr = (user_uintptr_t)compat_ptr(compat->encoder_id_ptr);
	native->count_fbs = compat->count_fbs;
	native->count_crtcs = compat->count_crtcs;
	native->count_connectors = compat->count_connectors;
	native->count_encoders = compat->count_encoders;
	native->min_width = compat->min_width;
	native->max_width = compat->max_width;
	native->min_height = compat->min_height;
	native->max_height = compat->max_height;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_card_res_2(struct __c64_drm_mode_card_res *compat, const struct drm_mode_card_res *native)
{

	compat->fb_id_ptr = (__c64_ptr64 __force)native->fb_id_ptr;
	compat->crtc_id_ptr = (__c64_ptr64 __force)native->crtc_id_ptr;
	compat->connector_id_ptr = (__c64_ptr64 __force)native->connector_id_ptr;
	compat->encoder_id_ptr = (__c64_ptr64 __force)native->encoder_id_ptr;
	compat->count_fbs = native->count_fbs;
	compat->count_crtcs = native->count_crtcs;
	compat->count_connectors = native->count_connectors;
	compat->count_encoders = native->count_encoders;
	compat->min_width = native->min_width;
	compat->max_width = native->max_width;
	compat->min_height = native->min_height;
	compat->max_height = native->max_height;
}
struct __c64_drm_mode_crtc {
	__c64_ptr64 set_connectors_ptr;
	__u32 count_connectors;

	__u32 crtc_id; /**< Id */
	__u32 fb_id; /**< Id of framebuffer */

	__u32 x; /**< x Position on the framebuffer */
	__u32 y; /**< y Position on the framebuffer */

	__u32 gamma_size;
	__u32 mode_valid;
	struct drm_mode_modeinfo mode;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc(struct drm_mode_crtc *p)
{
	union {
		struct drm_mode_crtc native;
		const struct __c64_drm_mode_crtc compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.mode) != sizeof(u->native.mode));
	memmove(&u->native.mode, &u->compat.mode, sizeof(u->native.mode));
	u->native.mode_valid = u->compat.mode_valid;
	u->native.gamma_size = u->compat.gamma_size;
	u->native.y = u->compat.y;
	u->native.x = u->compat.x;
	u->native.fb_id = u->compat.fb_id;
	u->native.crtc_id = u->compat.crtc_id;
	u->native.count_connectors = u->compat.count_connectors;
	u->native.set_connectors_ptr = (user_uintptr_t)compat_ptr(u->compat.set_connectors_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc(struct drm_mode_crtc *p)
{
	union {
		struct __c64_drm_mode_crtc compat;
		const struct drm_mode_crtc native;
	} *u = (void *)p;

	u->compat.set_connectors_ptr = (__c64_ptr64 __force)u->native.set_connectors_ptr;
	u->compat.count_connectors = u->native.count_connectors;
	u->compat.crtc_id = u->native.crtc_id;
	u->compat.fb_id = u->native.fb_id;
	u->compat.x = u->native.x;
	u->compat.y = u->native.y;
	u->compat.gamma_size = u->native.gamma_size;
	u->compat.mode_valid = u->native.mode_valid;
	BUILD_BUG_ON(sizeof(u->native.mode) != sizeof(u->compat.mode));
	memmove(&u->compat.mode, &u->native.mode, sizeof(u->compat.mode));
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc_2(struct drm_mode_crtc *native, const struct __c64_drm_mode_crtc *compat)
{

	native->set_connectors_ptr = (user_uintptr_t)compat_ptr(compat->set_connectors_ptr);
	native->count_connectors = compat->count_connectors;
	native->crtc_id = compat->crtc_id;
	native->fb_id = compat->fb_id;
	native->x = compat->x;
	native->y = compat->y;
	native->gamma_size = compat->gamma_size;
	native->mode_valid = compat->mode_valid;
	BUILD_BUG_ON(sizeof(compat->mode) != sizeof(native->mode));
	memcpy(&native->mode, &compat->mode, sizeof(native->mode));
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc_2(struct __c64_drm_mode_crtc *compat, const struct drm_mode_crtc *native)
{

	compat->set_connectors_ptr = (__c64_ptr64 __force)native->set_connectors_ptr;
	compat->count_connectors = native->count_connectors;
	compat->crtc_id = native->crtc_id;
	compat->fb_id = native->fb_id;
	compat->x = native->x;
	compat->y = native->y;
	compat->gamma_size = native->gamma_size;
	compat->mode_valid = native->mode_valid;
	BUILD_BUG_ON(sizeof(native->mode) != sizeof(compat->mode));
	memcpy(&compat->mode, &native->mode, sizeof(compat->mode));
}
struct __c64_drm_mode_get_plane {
	/**
	 * @plane_id: Object ID of the plane whose information should be
	 * retrieved. Set by caller.
	 */
	__u32 plane_id;

	/** @crtc_id: Object ID of the current CRTC. */
	__u32 crtc_id;
	/** @fb_id: Object ID of the current fb. */
	__u32 fb_id;

	/**
	 * @possible_crtcs: Bitmask of CRTC's compatible with the plane. CRTC's
	 * are created and they receive an index, which corresponds to their
	 * position in the bitmask. Bit N corresponds to
	 * :ref:`CRTC index<crtc_index>` N.
	 */
	__u32 possible_crtcs;
	/** @gamma_size: Never used. */
	__u32 gamma_size;

	/** @count_format_types: Number of formats. */
	__u32 count_format_types;
	/**
	 * @format_type_ptr: Pointer to ``__u32`` array of formats that are
	 * supported by the plane. These formats do not require modifiers.
	 */
	__c64_ptr64 format_type_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_plane(struct drm_mode_get_plane *p)
{
	union {
		struct drm_mode_get_plane native;
		const struct __c64_drm_mode_get_plane compat;
	} *u = (void *)p;

	u->native.format_type_ptr = (user_uintptr_t)compat_ptr(u->compat.format_type_ptr);
	u->native.count_format_types = u->compat.count_format_types;
	u->native.gamma_size = u->compat.gamma_size;
	u->native.possible_crtcs = u->compat.possible_crtcs;
	u->native.fb_id = u->compat.fb_id;
	u->native.crtc_id = u->compat.crtc_id;
	u->native.plane_id = u->compat.plane_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_plane(struct drm_mode_get_plane *p)
{
	union {
		struct __c64_drm_mode_get_plane compat;
		const struct drm_mode_get_plane native;
	} *u = (void *)p;

	u->compat.plane_id = u->native.plane_id;
	u->compat.crtc_id = u->native.crtc_id;
	u->compat.fb_id = u->native.fb_id;
	u->compat.possible_crtcs = u->native.possible_crtcs;
	u->compat.gamma_size = u->native.gamma_size;
	u->compat.count_format_types = u->native.count_format_types;
	u->compat.format_type_ptr = (__c64_ptr64 __force)u->native.format_type_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_plane_2(struct drm_mode_get_plane *native, const struct __c64_drm_mode_get_plane *compat)
{

	native->plane_id = compat->plane_id;
	native->crtc_id = compat->crtc_id;
	native->fb_id = compat->fb_id;
	native->possible_crtcs = compat->possible_crtcs;
	native->gamma_size = compat->gamma_size;
	native->count_format_types = compat->count_format_types;
	native->format_type_ptr = (user_uintptr_t)compat_ptr(compat->format_type_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_plane_2(struct __c64_drm_mode_get_plane *compat, const struct drm_mode_get_plane *native)
{

	compat->plane_id = native->plane_id;
	compat->crtc_id = native->crtc_id;
	compat->fb_id = native->fb_id;
	compat->possible_crtcs = native->possible_crtcs;
	compat->gamma_size = native->gamma_size;
	compat->count_format_types = native->count_format_types;
	compat->format_type_ptr = (__c64_ptr64 __force)native->format_type_ptr;
}
struct __c64_drm_mode_get_plane_res {
	__c64_ptr64 plane_id_ptr;
	__u32 count_planes;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_plane_res(struct drm_mode_get_plane_res *p)
{
	union {
		struct drm_mode_get_plane_res native;
		const struct __c64_drm_mode_get_plane_res compat;
	} *u = (void *)p;

	u->native.count_planes = u->compat.count_planes;
	u->native.plane_id_ptr = (user_uintptr_t)compat_ptr(u->compat.plane_id_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_plane_res(struct drm_mode_get_plane_res *p)
{
	union {
		struct __c64_drm_mode_get_plane_res compat;
		const struct drm_mode_get_plane_res native;
	} *u = (void *)p;

	u->compat.plane_id_ptr = (__c64_ptr64 __force)u->native.plane_id_ptr;
	u->compat.count_planes = u->native.count_planes;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_plane_res_2(struct drm_mode_get_plane_res *native, const struct __c64_drm_mode_get_plane_res *compat)
{

	native->plane_id_ptr = (user_uintptr_t)compat_ptr(compat->plane_id_ptr);
	native->count_planes = compat->count_planes;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_plane_res_2(struct __c64_drm_mode_get_plane_res *compat, const struct drm_mode_get_plane_res *native)
{

	compat->plane_id_ptr = (__c64_ptr64 __force)native->plane_id_ptr;
	compat->count_planes = native->count_planes;
}
struct __c64_drm_mode_get_connector {
	/** @encoders_ptr: Pointer to ``__u32`` array of object IDs. */
	__c64_ptr64 encoders_ptr;
	/** @modes_ptr: Pointer to struct drm_mode_modeinfo array. */
	__c64_ptr64 modes_ptr;
	/** @props_ptr: Pointer to ``__u32`` array of property IDs. */
	__c64_ptr64 props_ptr;
	/** @prop_values_ptr: Pointer to ``__u64`` array of property values. */
	__c64_ptr64 prop_values_ptr;

	/** @count_modes: Number of modes. */
	__u32 count_modes;
	/** @count_props: Number of properties. */
	__u32 count_props;
	/** @count_encoders: Number of encoders. */
	__u32 count_encoders;

	/** @encoder_id: Object ID of the current encoder. */
	__u32 encoder_id;
	/** @connector_id: Object ID of the connector. */
	__u32 connector_id;
	/**
	 * @connector_type: Type of the connector.
	 *
	 * See DRM_MODE_CONNECTOR_* defines.
	 */
	__u32 connector_type;
	/**
	 * @connector_type_id: Type-specific connector number.
	 *
	 * This is not an object ID. This is a per-type connector number. Each
	 * (type, type_id) combination is unique across all connectors of a DRM
	 * device.
	 *
	 * The (type, type_id) combination is not a stable identifier: the
	 * type_id can change depending on the driver probe order.
	 */
	__u32 connector_type_id;

	/**
	 * @connection: Status of the connector.
	 *
	 * See enum drm_connector_status.
	 */
	__u32 connection;
	/** @mm_width: Width of the connected sink in millimeters. */
	__u32 mm_width;
	/** @mm_height: Height of the connected sink in millimeters. */
	__u32 mm_height;
	/**
	 * @subpixel: Subpixel order of the connected sink.
	 *
	 * See enum subpixel_order.
	 */
	__u32 subpixel;

	/** @pad: Padding, must be zero. */
	__u32 pad;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_connector(struct drm_mode_get_connector *p)
{
	union {
		struct drm_mode_get_connector native;
		const struct __c64_drm_mode_get_connector compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.subpixel = u->compat.subpixel;
	u->native.mm_height = u->compat.mm_height;
	u->native.mm_width = u->compat.mm_width;
	u->native.connection = u->compat.connection;
	u->native.connector_type_id = u->compat.connector_type_id;
	u->native.connector_type = u->compat.connector_type;
	u->native.connector_id = u->compat.connector_id;
	u->native.encoder_id = u->compat.encoder_id;
	u->native.count_encoders = u->compat.count_encoders;
	u->native.count_props = u->compat.count_props;
	u->native.count_modes = u->compat.count_modes;
	u->native.prop_values_ptr = (user_uintptr_t)compat_ptr(u->compat.prop_values_ptr);
	u->native.props_ptr = (user_uintptr_t)compat_ptr(u->compat.props_ptr);
	u->native.modes_ptr = (user_uintptr_t)compat_ptr(u->compat.modes_ptr);
	u->native.encoders_ptr = (user_uintptr_t)compat_ptr(u->compat.encoders_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_connector(struct drm_mode_get_connector *p)
{
	union {
		struct __c64_drm_mode_get_connector compat;
		const struct drm_mode_get_connector native;
	} *u = (void *)p;

	u->compat.encoders_ptr = (__c64_ptr64 __force)u->native.encoders_ptr;
	u->compat.modes_ptr = (__c64_ptr64 __force)u->native.modes_ptr;
	u->compat.props_ptr = (__c64_ptr64 __force)u->native.props_ptr;
	u->compat.prop_values_ptr = (__c64_ptr64 __force)u->native.prop_values_ptr;
	u->compat.count_modes = u->native.count_modes;
	u->compat.count_props = u->native.count_props;
	u->compat.count_encoders = u->native.count_encoders;
	u->compat.encoder_id = u->native.encoder_id;
	u->compat.connector_id = u->native.connector_id;
	u->compat.connector_type = u->native.connector_type;
	u->compat.connector_type_id = u->native.connector_type_id;
	u->compat.connection = u->native.connection;
	u->compat.mm_width = u->native.mm_width;
	u->compat.mm_height = u->native.mm_height;
	u->compat.subpixel = u->native.subpixel;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_connector_2(struct drm_mode_get_connector *native, const struct __c64_drm_mode_get_connector *compat)
{

	native->encoders_ptr = (user_uintptr_t)compat_ptr(compat->encoders_ptr);
	native->modes_ptr = (user_uintptr_t)compat_ptr(compat->modes_ptr);
	native->props_ptr = (user_uintptr_t)compat_ptr(compat->props_ptr);
	native->prop_values_ptr = (user_uintptr_t)compat_ptr(compat->prop_values_ptr);
	native->count_modes = compat->count_modes;
	native->count_props = compat->count_props;
	native->count_encoders = compat->count_encoders;
	native->encoder_id = compat->encoder_id;
	native->connector_id = compat->connector_id;
	native->connector_type = compat->connector_type;
	native->connector_type_id = compat->connector_type_id;
	native->connection = compat->connection;
	native->mm_width = compat->mm_width;
	native->mm_height = compat->mm_height;
	native->subpixel = compat->subpixel;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_connector_2(struct __c64_drm_mode_get_connector *compat, const struct drm_mode_get_connector *native)
{

	compat->encoders_ptr = (__c64_ptr64 __force)native->encoders_ptr;
	compat->modes_ptr = (__c64_ptr64 __force)native->modes_ptr;
	compat->props_ptr = (__c64_ptr64 __force)native->props_ptr;
	compat->prop_values_ptr = (__c64_ptr64 __force)native->prop_values_ptr;
	compat->count_modes = native->count_modes;
	compat->count_props = native->count_props;
	compat->count_encoders = native->count_encoders;
	compat->encoder_id = native->encoder_id;
	compat->connector_id = native->connector_id;
	compat->connector_type = native->connector_type;
	compat->connector_type_id = native->connector_type_id;
	compat->connection = native->connection;
	compat->mm_width = native->mm_width;
	compat->mm_height = native->mm_height;
	compat->subpixel = native->subpixel;
	compat->pad = native->pad;
}
struct __c64_drm_mode_get_property {
	/** @values_ptr: Pointer to a ``__u64`` array. */
	__c64_ptr64 values_ptr;
	/** @enum_blob_ptr: Pointer to a struct drm_mode_property_enum array. */
	__c64_ptr64 enum_blob_ptr;

	/**
	 * @prop_id: Object ID of the property which should be retrieved. Set
	 * by the caller.
	 */
	__u32 prop_id;
	/**
	 * @flags: ``DRM_MODE_PROP_*`` bitfield. See &drm_property.flags for
	 * a definition of the flags.
	 */
	__u32 flags;
	/**
	 * @name: Symbolic property name. User-space should use this field to
	 * recognize properties.
	 */
	char name[DRM_PROP_NAME_LEN];

	/** @count_values: Number of elements in @values_ptr. */
	__u32 count_values;
	/** @count_enum_blobs: Number of elements in @enum_blob_ptr. */
	__u32 count_enum_blobs;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_property(struct drm_mode_get_property *p)
{
	union {
		struct drm_mode_get_property native;
		const struct __c64_drm_mode_get_property compat;
	} *u = (void *)p;

	u->native.count_enum_blobs = u->compat.count_enum_blobs;
	u->native.count_values = u->compat.count_values;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
	u->native.flags = u->compat.flags;
	u->native.prop_id = u->compat.prop_id;
	u->native.enum_blob_ptr = (user_uintptr_t)compat_ptr(u->compat.enum_blob_ptr);
	u->native.values_ptr = (user_uintptr_t)compat_ptr(u->compat.values_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_property(struct drm_mode_get_property *p)
{
	union {
		struct __c64_drm_mode_get_property compat;
		const struct drm_mode_get_property native;
	} *u = (void *)p;

	u->compat.values_ptr = (__c64_ptr64 __force)u->native.values_ptr;
	u->compat.enum_blob_ptr = (__c64_ptr64 __force)u->native.enum_blob_ptr;
	u->compat.prop_id = u->native.prop_id;
	u->compat.flags = u->native.flags;
	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.count_values = u->native.count_values;
	u->compat.count_enum_blobs = u->native.count_enum_blobs;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_property_2(struct drm_mode_get_property *native, const struct __c64_drm_mode_get_property *compat)
{

	native->values_ptr = (user_uintptr_t)compat_ptr(compat->values_ptr);
	native->enum_blob_ptr = (user_uintptr_t)compat_ptr(compat->enum_blob_ptr);
	native->prop_id = compat->prop_id;
	native->flags = compat->flags;
	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->count_values = compat->count_values;
	native->count_enum_blobs = compat->count_enum_blobs;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_property_2(struct __c64_drm_mode_get_property *compat, const struct drm_mode_get_property *native)
{

	compat->values_ptr = (__c64_ptr64 __force)native->values_ptr;
	compat->enum_blob_ptr = (__c64_ptr64 __force)native->enum_blob_ptr;
	compat->prop_id = native->prop_id;
	compat->flags = native->flags;
	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->count_values = native->count_values;
	compat->count_enum_blobs = native->count_enum_blobs;
}
struct __c64_drm_mode_obj_get_properties {
	__c64_ptr64 props_ptr;
	__c64_ptr64 prop_values_ptr;
	__u32 count_props;
	__u32 obj_id;
	__u32 obj_type;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_obj_get_properties(struct drm_mode_obj_get_properties *p)
{
	union {
		struct drm_mode_obj_get_properties native;
		const struct __c64_drm_mode_obj_get_properties compat;
	} *u = (void *)p;

	u->native.obj_type = u->compat.obj_type;
	u->native.obj_id = u->compat.obj_id;
	u->native.count_props = u->compat.count_props;
	u->native.prop_values_ptr = (user_uintptr_t)compat_ptr(u->compat.prop_values_ptr);
	u->native.props_ptr = (user_uintptr_t)compat_ptr(u->compat.props_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_obj_get_properties(struct drm_mode_obj_get_properties *p)
{
	union {
		struct __c64_drm_mode_obj_get_properties compat;
		const struct drm_mode_obj_get_properties native;
	} *u = (void *)p;

	u->compat.props_ptr = (__c64_ptr64 __force)u->native.props_ptr;
	u->compat.prop_values_ptr = (__c64_ptr64 __force)u->native.prop_values_ptr;
	u->compat.count_props = u->native.count_props;
	u->compat.obj_id = u->native.obj_id;
	u->compat.obj_type = u->native.obj_type;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_obj_get_properties_2(struct drm_mode_obj_get_properties *native, const struct __c64_drm_mode_obj_get_properties *compat)
{

	native->props_ptr = (user_uintptr_t)compat_ptr(compat->props_ptr);
	native->prop_values_ptr = (user_uintptr_t)compat_ptr(compat->prop_values_ptr);
	native->count_props = compat->count_props;
	native->obj_id = compat->obj_id;
	native->obj_type = compat->obj_type;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_obj_get_properties_2(struct __c64_drm_mode_obj_get_properties *compat, const struct drm_mode_obj_get_properties *native)
{

	compat->props_ptr = (__c64_ptr64 __force)native->props_ptr;
	compat->prop_values_ptr = (__c64_ptr64 __force)native->prop_values_ptr;
	compat->count_props = native->count_props;
	compat->obj_id = native->obj_id;
	compat->obj_type = native->obj_type;
}
struct __c64_drm_mode_get_blob {
	__u32 blob_id;
	__u32 length;
	__c64_ptr64 data;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_blob(struct drm_mode_get_blob *p)
{
	union {
		struct drm_mode_get_blob native;
		const struct __c64_drm_mode_get_blob compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.length = u->compat.length;
	u->native.blob_id = u->compat.blob_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_blob(struct drm_mode_get_blob *p)
{
	union {
		struct __c64_drm_mode_get_blob compat;
		const struct drm_mode_get_blob native;
	} *u = (void *)p;

	u->compat.blob_id = u->native.blob_id;
	u->compat.length = u->native.length;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_blob_2(struct drm_mode_get_blob *native, const struct __c64_drm_mode_get_blob *compat)
{

	native->blob_id = compat->blob_id;
	native->length = compat->length;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_blob_2(struct __c64_drm_mode_get_blob *compat, const struct drm_mode_get_blob *native)
{

	compat->blob_id = native->blob_id;
	compat->length = native->length;
	compat->data = (__c64_ptr64 __force)native->data;
}
struct __c64_drm_mode_fb_dirty_cmd {
	__u32 fb_id;
	__u32 flags;
	__u32 color;
	__u32 num_clips;
	__c64_ptr64 clips_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_fb_dirty_cmd(struct drm_mode_fb_dirty_cmd *p)
{
	union {
		struct drm_mode_fb_dirty_cmd native;
		const struct __c64_drm_mode_fb_dirty_cmd compat;
	} *u = (void *)p;

	u->native.clips_ptr = (user_uintptr_t)compat_ptr(u->compat.clips_ptr);
	u->native.num_clips = u->compat.num_clips;
	u->native.color = u->compat.color;
	u->native.flags = u->compat.flags;
	u->native.fb_id = u->compat.fb_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_fb_dirty_cmd(struct drm_mode_fb_dirty_cmd *p)
{
	union {
		struct __c64_drm_mode_fb_dirty_cmd compat;
		const struct drm_mode_fb_dirty_cmd native;
	} *u = (void *)p;

	u->compat.fb_id = u->native.fb_id;
	u->compat.flags = u->native.flags;
	u->compat.color = u->native.color;
	u->compat.num_clips = u->native.num_clips;
	u->compat.clips_ptr = (__c64_ptr64 __force)u->native.clips_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_fb_dirty_cmd_2(struct drm_mode_fb_dirty_cmd *native, const struct __c64_drm_mode_fb_dirty_cmd *compat)
{

	native->fb_id = compat->fb_id;
	native->flags = compat->flags;
	native->color = compat->color;
	native->num_clips = compat->num_clips;
	native->clips_ptr = (user_uintptr_t)compat_ptr(compat->clips_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_fb_dirty_cmd_2(struct __c64_drm_mode_fb_dirty_cmd *compat, const struct drm_mode_fb_dirty_cmd *native)
{

	compat->fb_id = native->fb_id;
	compat->flags = native->flags;
	compat->color = native->color;
	compat->num_clips = native->num_clips;
	compat->clips_ptr = (__c64_ptr64 __force)native->clips_ptr;
}
struct __c64_drm_mode_crtc_lut {
	__u32 crtc_id;
	__u32 gamma_size;

	/* pointers to arrays */
	__c64_ptr64 red;
	__c64_ptr64 green;
	__c64_ptr64 blue;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc_lut(struct drm_mode_crtc_lut *p)
{
	union {
		struct drm_mode_crtc_lut native;
		const struct __c64_drm_mode_crtc_lut compat;
	} *u = (void *)p;

	u->native.blue = (user_uintptr_t)compat_ptr(u->compat.blue);
	u->native.green = (user_uintptr_t)compat_ptr(u->compat.green);
	u->native.red = (user_uintptr_t)compat_ptr(u->compat.red);
	u->native.gamma_size = u->compat.gamma_size;
	u->native.crtc_id = u->compat.crtc_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc_lut(struct drm_mode_crtc_lut *p)
{
	union {
		struct __c64_drm_mode_crtc_lut compat;
		const struct drm_mode_crtc_lut native;
	} *u = (void *)p;

	u->compat.crtc_id = u->native.crtc_id;
	u->compat.gamma_size = u->native.gamma_size;
	u->compat.red = (__c64_ptr64 __force)u->native.red;
	u->compat.green = (__c64_ptr64 __force)u->native.green;
	u->compat.blue = (__c64_ptr64 __force)u->native.blue;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc_lut_2(struct drm_mode_crtc_lut *native, const struct __c64_drm_mode_crtc_lut *compat)
{

	native->crtc_id = compat->crtc_id;
	native->gamma_size = compat->gamma_size;
	native->red = (user_uintptr_t)compat_ptr(compat->red);
	native->green = (user_uintptr_t)compat_ptr(compat->green);
	native->blue = (user_uintptr_t)compat_ptr(compat->blue);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc_lut_2(struct __c64_drm_mode_crtc_lut *compat, const struct drm_mode_crtc_lut *native)
{

	compat->crtc_id = native->crtc_id;
	compat->gamma_size = native->gamma_size;
	compat->red = (__c64_ptr64 __force)native->red;
	compat->green = (__c64_ptr64 __force)native->green;
	compat->blue = (__c64_ptr64 __force)native->blue;
}
struct __c64_drm_mode_crtc_page_flip_target {
	__u32 crtc_id;
	__u32 fb_id;
	__u32 flags;
	__u32 sequence;
	__c64_ptr64 user_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc_page_flip_target(struct drm_mode_crtc_page_flip_target *p)
{
	union {
		struct drm_mode_crtc_page_flip_target native;
		const struct __c64_drm_mode_crtc_page_flip_target compat;
	} *u = (void *)p;

	u->native.user_data = (user_uintptr_t)compat_ptr(u->compat.user_data);
	u->native.sequence = u->compat.sequence;
	u->native.flags = u->compat.flags;
	u->native.fb_id = u->compat.fb_id;
	u->native.crtc_id = u->compat.crtc_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc_page_flip_target(struct drm_mode_crtc_page_flip_target *p)
{
	union {
		struct __c64_drm_mode_crtc_page_flip_target compat;
		const struct drm_mode_crtc_page_flip_target native;
	} *u = (void *)p;

	u->compat.crtc_id = u->native.crtc_id;
	u->compat.fb_id = u->native.fb_id;
	u->compat.flags = u->native.flags;
	u->compat.sequence = u->native.sequence;
	u->compat.user_data = (__c64_ptr64 __force)u->native.user_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_crtc_page_flip_target_2(struct drm_mode_crtc_page_flip_target *native, const struct __c64_drm_mode_crtc_page_flip_target *compat)
{

	native->crtc_id = compat->crtc_id;
	native->fb_id = compat->fb_id;
	native->flags = compat->flags;
	native->sequence = compat->sequence;
	native->user_data = (user_uintptr_t)compat_ptr(compat->user_data);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_crtc_page_flip_target_2(struct __c64_drm_mode_crtc_page_flip_target *compat, const struct drm_mode_crtc_page_flip_target *native)
{

	compat->crtc_id = native->crtc_id;
	compat->fb_id = native->fb_id;
	compat->flags = native->flags;
	compat->sequence = native->sequence;
	compat->user_data = (__c64_ptr64 __force)native->user_data;
}
struct __c64_drm_mode_atomic {
	__u32 flags;
	__u32 count_objs;
	__c64_ptr64 objs_ptr;
	__c64_ptr64 count_props_ptr;
	__c64_ptr64 props_ptr;
	__c64_ptr64 prop_values_ptr;
	__c64_ptr64 reserved;
	__c64_ptr64 user_data;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_atomic(struct drm_mode_atomic *p)
{
	union {
		struct drm_mode_atomic native;
		const struct __c64_drm_mode_atomic compat;
	} *u = (void *)p;

	u->native.user_data = (user_uintptr_t)compat_ptr(u->compat.user_data);
	u->native.reserved = (user_uintptr_t)compat_ptr(u->compat.reserved);
	u->native.prop_values_ptr = (user_uintptr_t)compat_ptr(u->compat.prop_values_ptr);
	u->native.props_ptr = (user_uintptr_t)compat_ptr(u->compat.props_ptr);
	u->native.count_props_ptr = (user_uintptr_t)compat_ptr(u->compat.count_props_ptr);
	u->native.objs_ptr = (user_uintptr_t)compat_ptr(u->compat.objs_ptr);
	u->native.count_objs = u->compat.count_objs;
	u->native.flags = u->compat.flags;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_atomic(struct drm_mode_atomic *p)
{
	union {
		struct __c64_drm_mode_atomic compat;
		const struct drm_mode_atomic native;
	} *u = (void *)p;

	u->compat.flags = u->native.flags;
	u->compat.count_objs = u->native.count_objs;
	u->compat.objs_ptr = (__c64_ptr64 __force)u->native.objs_ptr;
	u->compat.count_props_ptr = (__c64_ptr64 __force)u->native.count_props_ptr;
	u->compat.props_ptr = (__c64_ptr64 __force)u->native.props_ptr;
	u->compat.prop_values_ptr = (__c64_ptr64 __force)u->native.prop_values_ptr;
	u->compat.reserved = (__c64_ptr64 __force)u->native.reserved;
	u->compat.user_data = (__c64_ptr64 __force)u->native.user_data;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_atomic_2(struct drm_mode_atomic *native, const struct __c64_drm_mode_atomic *compat)
{

	native->flags = compat->flags;
	native->count_objs = compat->count_objs;
	native->objs_ptr = (user_uintptr_t)compat_ptr(compat->objs_ptr);
	native->count_props_ptr = (user_uintptr_t)compat_ptr(compat->count_props_ptr);
	native->props_ptr = (user_uintptr_t)compat_ptr(compat->props_ptr);
	native->prop_values_ptr = (user_uintptr_t)compat_ptr(compat->prop_values_ptr);
	native->reserved = (user_uintptr_t)compat_ptr(compat->reserved);
	native->user_data = (user_uintptr_t)compat_ptr(compat->user_data);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_atomic_2(struct __c64_drm_mode_atomic *compat, const struct drm_mode_atomic *native)
{

	compat->flags = native->flags;
	compat->count_objs = native->count_objs;
	compat->objs_ptr = (__c64_ptr64 __force)native->objs_ptr;
	compat->count_props_ptr = (__c64_ptr64 __force)native->count_props_ptr;
	compat->props_ptr = (__c64_ptr64 __force)native->props_ptr;
	compat->prop_values_ptr = (__c64_ptr64 __force)native->prop_values_ptr;
	compat->reserved = (__c64_ptr64 __force)native->reserved;
	compat->user_data = (__c64_ptr64 __force)native->user_data;
}
struct __c64_drm_mode_create_blob {
	/** @data: Pointer to data to copy. */
	__c64_ptr64 data;
	/** @length: Length of data to copy. */
	__u32 length;
	/** @blob_id: Return: new property ID. */
	__u32 blob_id;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_create_blob(struct drm_mode_create_blob *p)
{
	union {
		struct drm_mode_create_blob native;
		const struct __c64_drm_mode_create_blob compat;
	} *u = (void *)p;

	u->native.blob_id = u->compat.blob_id;
	u->native.length = u->compat.length;
	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_create_blob(struct drm_mode_create_blob *p)
{
	union {
		struct __c64_drm_mode_create_blob compat;
		const struct drm_mode_create_blob native;
	} *u = (void *)p;

	u->compat.data = (__c64_ptr64 __force)u->native.data;
	u->compat.length = u->native.length;
	u->compat.blob_id = u->native.blob_id;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_create_blob_2(struct drm_mode_create_blob *native, const struct __c64_drm_mode_create_blob *compat)
{

	native->data = (user_uintptr_t)compat_ptr(compat->data);
	native->length = compat->length;
	native->blob_id = compat->blob_id;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_create_blob_2(struct __c64_drm_mode_create_blob *compat, const struct drm_mode_create_blob *native)
{

	compat->data = (__c64_ptr64 __force)native->data;
	compat->length = native->length;
	compat->blob_id = native->blob_id;
}
struct __c64_drm_mode_create_lease {
	/** @object_ids: Pointer to array of object ids (__u32) */
	__c64_ptr64 object_ids;
	/** @object_count: Number of object ids */
	__u32 object_count;
	/** @flags: flags for new FD (O_CLOEXEC, etc) */
	__u32 flags;

	/** @lessee_id: Return: unique identifier for lessee. */
	__u32 lessee_id;
	/** @fd: Return: file descriptor to new drm_master file */
	__u32 fd;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_create_lease(struct drm_mode_create_lease *p)
{
	union {
		struct drm_mode_create_lease native;
		const struct __c64_drm_mode_create_lease compat;
	} *u = (void *)p;

	u->native.fd = u->compat.fd;
	u->native.lessee_id = u->compat.lessee_id;
	u->native.flags = u->compat.flags;
	u->native.object_count = u->compat.object_count;
	u->native.object_ids = (user_uintptr_t)compat_ptr(u->compat.object_ids);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_create_lease(struct drm_mode_create_lease *p)
{
	union {
		struct __c64_drm_mode_create_lease compat;
		const struct drm_mode_create_lease native;
	} *u = (void *)p;

	u->compat.object_ids = (__c64_ptr64 __force)u->native.object_ids;
	u->compat.object_count = u->native.object_count;
	u->compat.flags = u->native.flags;
	u->compat.lessee_id = u->native.lessee_id;
	u->compat.fd = u->native.fd;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_create_lease_2(struct drm_mode_create_lease *native, const struct __c64_drm_mode_create_lease *compat)
{

	native->object_ids = (user_uintptr_t)compat_ptr(compat->object_ids);
	native->object_count = compat->object_count;
	native->flags = compat->flags;
	native->lessee_id = compat->lessee_id;
	native->fd = compat->fd;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_create_lease_2(struct __c64_drm_mode_create_lease *compat, const struct drm_mode_create_lease *native)
{

	compat->object_ids = (__c64_ptr64 __force)native->object_ids;
	compat->object_count = native->object_count;
	compat->flags = native->flags;
	compat->lessee_id = native->lessee_id;
	compat->fd = native->fd;
}
struct __c64_drm_mode_list_lessees {
	/**
	 * @count_lessees: Number of lessees.
	 *
	 * On input, provides length of the array.
	 * On output, provides total number. No
	 * more than the input number will be written
	 * back, so two calls can be used to get
	 * the size and then the data.
	 */
	__u32 count_lessees;
	/** @pad: Padding. */
	__u32 pad;

	/**
	 * @lessees_ptr: Pointer to lessees.
	 *
	 * Pointer to __u64 array of lessee ids
	 */
	__c64_ptr64 lessees_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_list_lessees(struct drm_mode_list_lessees *p)
{
	union {
		struct drm_mode_list_lessees native;
		const struct __c64_drm_mode_list_lessees compat;
	} *u = (void *)p;

	u->native.lessees_ptr = (user_uintptr_t)compat_ptr(u->compat.lessees_ptr);
	u->native.pad = u->compat.pad;
	u->native.count_lessees = u->compat.count_lessees;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_list_lessees(struct drm_mode_list_lessees *p)
{
	union {
		struct __c64_drm_mode_list_lessees compat;
		const struct drm_mode_list_lessees native;
	} *u = (void *)p;

	u->compat.count_lessees = u->native.count_lessees;
	u->compat.pad = u->native.pad;
	u->compat.lessees_ptr = (__c64_ptr64 __force)u->native.lessees_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_list_lessees_2(struct drm_mode_list_lessees *native, const struct __c64_drm_mode_list_lessees *compat)
{

	native->count_lessees = compat->count_lessees;
	native->pad = compat->pad;
	native->lessees_ptr = (user_uintptr_t)compat_ptr(compat->lessees_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_list_lessees_2(struct __c64_drm_mode_list_lessees *compat, const struct drm_mode_list_lessees *native)
{

	compat->count_lessees = native->count_lessees;
	compat->pad = native->pad;
	compat->lessees_ptr = (__c64_ptr64 __force)native->lessees_ptr;
}
struct __c64_drm_mode_get_lease {
	/**
	 * @count_objects: Number of leased objects.
	 *
	 * On input, provides length of the array.
	 * On output, provides total number. No
	 * more than the input number will be written
	 * back, so two calls can be used to get
	 * the size and then the data.
	 */
	__u32 count_objects;
	/** @pad: Padding. */
	__u32 pad;

	/**
	 * @objects_ptr: Pointer to objects.
	 *
	 * Pointer to __u32 array of object ids.
	 */
	__c64_ptr64 objects_ptr;
};

static __always_inline __maybe_unused void
__from_c64_drm_mode_get_lease(struct drm_mode_get_lease *p)
{
	union {
		struct drm_mode_get_lease native;
		const struct __c64_drm_mode_get_lease compat;
	} *u = (void *)p;

	u->native.objects_ptr = (user_uintptr_t)compat_ptr(u->compat.objects_ptr);
	u->native.pad = u->compat.pad;
	u->native.count_objects = u->compat.count_objects;
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_lease(struct drm_mode_get_lease *p)
{
	union {
		struct __c64_drm_mode_get_lease compat;
		const struct drm_mode_get_lease native;
	} *u = (void *)p;

	u->compat.count_objects = u->native.count_objects;
	u->compat.pad = u->native.pad;
	u->compat.objects_ptr = (__c64_ptr64 __force)u->native.objects_ptr;
}
static __always_inline __maybe_unused void
__from_c64_drm_mode_get_lease_2(struct drm_mode_get_lease *native, const struct __c64_drm_mode_get_lease *compat)
{

	native->count_objects = compat->count_objects;
	native->pad = compat->pad;
	native->objects_ptr = (user_uintptr_t)compat_ptr(compat->objects_ptr);
}
static __always_inline __maybe_unused void
__to_c64_drm_mode_get_lease_2(struct __c64_drm_mode_get_lease *compat, const struct drm_mode_get_lease *native)
{

	compat->count_objects = native->count_objects;
	compat->pad = native->pad;
	compat->objects_ptr = (__c64_ptr64 __force)native->objects_ptr;
}
