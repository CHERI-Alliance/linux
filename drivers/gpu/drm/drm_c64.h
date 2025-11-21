#pragma once

#include <drm/compat64_drm.h>
#include <drm/compat64_drm_mode.h>

#define __from_c64_null NULL
#define __to_c64_null NULL

#define STRUCT_DRM_IOCTL_VERSION		drm_version
#define STRUCT_DRM_IOCTL_GET_UNIQUE		drm_unique
#define STRUCT_DRM_IOCTL_GET_MAGIC		null
#define STRUCT_DRM_IOCTL_IRQ_BUSID		drm_irq_busid
#define STRUCT_DRM_IOCTL_GET_MAP		drm_map
#define STRUCT_DRM_IOCTL_GET_CLIENT		null
#define STRUCT_DRM_IOCTL_GET_STATS		null
#define STRUCT_DRM_IOCTL_SET_VERSION		null
#define STRUCT_DRM_IOCTL_MODESET_CTL		drm_modeset_ctl
#define STRUCT_DRM_IOCTL_GEM_CLOSE		null
#define STRUCT_DRM_IOCTL_GEM_FLINK		null
#define STRUCT_DRM_IOCTL_GEM_OPEN		null
#define STRUCT_DRM_IOCTL_GET_CAP		null
#define STRUCT_DRM_IOCTL_SET_CLIENT_CAP		null
#define STRUCT_DRM_IOCTL_SET_UNIQUE		drm_unique
#define STRUCT_DRM_IOCTL_AUTH_MAGIC		null
#define STRUCT_DRM_IOCTL_BLOCK			null
#define STRUCT_DRM_IOCTL_UNBLOCK		null
#define STRUCT_DRM_IOCTL_CONTROL		drm_control
#define STRUCT_DRM_IOCTL_ADD_MAP		drm_map
#define STRUCT_DRM_IOCTL_ADD_BUFS		drm_buf_desc
#define STRUCT_DRM_IOCTL_MARK_BUFS		drm_buf_desc
#define STRUCT_DRM_IOCTL_INFO_BUFS		drm_buf_info
#define STRUCT_DRM_IOCTL_MAP_BUFS		drm_buf_map
#define STRUCT_DRM_IOCTL_FREE_BUFS		drm_buf_free
#define STRUCT_DRM_IOCTL_RM_MAP			drm_map
#define STRUCT_DRM_IOCTL_SET_SAREA_CTX		drm_ctx_priv_map
#define STRUCT_DRM_IOCTL_GET_SAREA_CTX 		drm_ctx_priv_map
#define STRUCT_DRM_IOCTL_SET_MASTER		null
#define STRUCT_DRM_IOCTL_DROP_MASTER		null
#define STRUCT_DRM_IOCTL_ADD_CTX		drm_ctx
#define STRUCT_DRM_IOCTL_RM_CTX			drm_ctx
#define STRUCT_DRM_IOCTL_MOD_CTX		drm_ctx
#define STRUCT_DRM_IOCTL_GET_CTX		drm_ctx
#define STRUCT_DRM_IOCTL_SWITCH_CTX		drm_ctx
#define STRUCT_DRM_IOCTL_NEW_CTX		drm_ctx
#define STRUCT_DRM_IOCTL_RES_CTX		drm_ctx_res
#define STRUCT_DRM_IOCTL_ADD_DRAW		null
#define STRUCT_DRM_IOCTL_RM_DRAW		null
#define STRUCT_DRM_IOCTL_DMA			drm_dma
#define STRUCT_DRM_IOCTL_LOCK			null
#define STRUCT_DRM_IOCTL_UNLOCK			null
#define STRUCT_DRM_IOCTL_FINISH			null
#define STRUCT_DRM_IOCTL_PRIME_HANDLE_TO_FD	null
#define STRUCT_DRM_IOCTL_PRIME_FD_TO_HANDLE	null
#define STRUCT_DRM_IOCTL_AGP_ACQUIRE		null
#define STRUCT_DRM_IOCTL_AGP_RELEASE		null
#define STRUCT_DRM_IOCTL_AGP_ENABLE		drm_agp_mode
#define STRUCT_DRM_IOCTL_AGP_INFO		drm_agp_info
#define STRUCT_DRM_IOCTL_AGP_ALLOC		drm_agp_buffer
#define STRUCT_DRM_IOCTL_AGP_FREE		drm_agp_buffer
#define STRUCT_DRM_IOCTL_AGP_BIND		drm_agp_binding
#define STRUCT_DRM_IOCTL_AGP_UNBIND		drm_agp_binding
#define STRUCT_DRM_IOCTL_SG_ALLOC		drm_scatter_gather
#define STRUCT_DRM_IOCTL_SG_FREE		drm_scatter_gather
#define STRUCT_DRM_IOCTL_WAIT_VBLANK		drm_wait_vblank
#define STRUCT_DRM_IOCTL_CRTC_GET_SEQUENCE	null
#define STRUCT_DRM_IOCTL_CRTC_QUEUE_SEQUENCE	drm_crtc_queue_sequence
#define STRUCT_DRM_IOCTL_UPDATE_DRAW		null
#define STRUCT_DRM_IOCTL_MODE_GETRESOURCES	drm_mode_card_res
#define STRUCT_DRM_IOCTL_MODE_GETCRTC		drm_mode_crtc
#define STRUCT_DRM_IOCTL_MODE_SETCRTC		drm_mode_crtc
#define STRUCT_DRM_IOCTL_MODE_CURSOR		null
#define STRUCT_DRM_IOCTL_MODE_GETGAMMA		drm_mode_crtc_lut
#define STRUCT_DRM_IOCTL_MODE_SETGAMMA		drm_mode_crtc_lut
#define STRUCT_DRM_IOCTL_MODE_GETENCODER	null
#define STRUCT_DRM_IOCTL_MODE_GETCONNECTOR	drm_mode_get_connector
#define STRUCT_DRM_IOCTL_MODE_ATTACHMODE	null
#define STRUCT_DRM_IOCTL_MODE_DETACHMODE	null
#define STRUCT_DRM_IOCTL_MODE_GETPROPERTY	drm_mode_get_property
#define STRUCT_DRM_IOCTL_MODE_SETPROPERTY	null
#define STRUCT_DRM_IOCTL_MODE_GETPROPBLOB	drm_mode_get_blob
#define STRUCT_DRM_IOCTL_MODE_GETFB		null
#define STRUCT_DRM_IOCTL_MODE_ADDFB		null
#define STRUCT_DRM_IOCTL_MODE_RMFB		null
#define STRUCT_DRM_IOCTL_MODE_PAGE_FLIP		null
#define STRUCT_DRM_IOCTL_MODE_DIRTYFB		drm_mode_fb_dirty_cmd
#define STRUCT_DRM_IOCTL_MODE_CREATE_DUMB	null
#define STRUCT_DRM_IOCTL_MODE_MAP_DUMB   	null
#define STRUCT_DRM_IOCTL_MODE_DESTROY_DUMB	null
#define STRUCT_DRM_IOCTL_MODE_GETPLANERESOURCES	drm_mode_get_plane_res
#define STRUCT_DRM_IOCTL_MODE_GETPLANE		drm_mode_get_plane
#define STRUCT_DRM_IOCTL_MODE_SETPLANE		null
#define STRUCT_DRM_IOCTL_MODE_ADDFB2		null
#define STRUCT_DRM_IOCTL_MODE_OBJ_GETPROPERTIES	drm_mode_obj_get_properties
#define STRUCT_DRM_IOCTL_MODE_OBJ_SETPROPERTY	null
#define STRUCT_DRM_IOCTL_MODE_CURSOR2		null
#define STRUCT_DRM_IOCTL_MODE_ATOMIC		drm_mode_atomic
#define STRUCT_DRM_IOCTL_MODE_CREATEPROPBLOB	drm_mode_create_blob
#define STRUCT_DRM_IOCTL_MODE_DESTROYPROPBLOB	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_CREATE		null
#define STRUCT_DRM_IOCTL_SYNCOBJ_DESTROY	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_WAIT		drm_syncobj_wait
#define STRUCT_DRM_IOCTL_SYNCOBJ_RESET		drm_syncobj_array
#define STRUCT_DRM_IOCTL_SYNCOBJ_SIGNAL		drm_syncobj_array
#define STRUCT_DRM_IOCTL_MODE_CREATE_LEASE	drm_mode_create_lease
#define STRUCT_DRM_IOCTL_MODE_LIST_LESSEES	drm_mode_list_lessees
#define STRUCT_DRM_IOCTL_MODE_GET_LEASE		drm_mode_get_lease
#define STRUCT_DRM_IOCTL_MODE_REVOKE_LEASE	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT	drm_syncobj_timeline_wait
#define STRUCT_DRM_IOCTL_SYNCOBJ_QUERY		drm_syncobj_timeline_array
#define STRUCT_DRM_IOCTL_SYNCOBJ_TRANSFER	null
#define STRUCT_DRM_IOCTL_SYNCOBJ_TIMELINE_SIGNAL	drm_syncobj_timeline_array
#define STRUCT_DRM_IOCTL_MODE_GETFB2		null
#define STRUCT_DRM_IOCTL_SYNCOBJ_EVENTFD	null
#define STRUCT_DRM_IOCTL_MODE_CLOSEFB		null
#define STRUCT_DRM_IOCTL_SET_CLIENT_NAME	drm_set_client_name
#define STRUCT_DRM_IOCTL_GEM_CHANGE_HANDLE	null

/*
 * Manually provide compat64 conversion functions for drm_wait_vblank.
 * This is a union of the request and the reply and the reply needs
 * no conversion.
 */
static __always_inline __maybe_unused void
__from_c64_drm_wait_vblank(union drm_wait_vblank *p)
{
	__from_c64_drm_wait_vblank_request(&p->request);
}

static __always_inline __maybe_unused void
__to_c64_drm_wait_vblank(union drm_wait_vblank *p)
{
}
