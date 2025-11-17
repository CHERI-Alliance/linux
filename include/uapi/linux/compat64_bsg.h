#pragma once


#include <linux/compat.h>


struct __c64_sg_io_v4 {
	__s32 guard;		/* [i] 'Q' to differentiate from v3 */
	__u32 protocol;		/* [i] 0 -> SCSI , .... */
	__u32 subprotocol;	/* [i] 0 -> SCSI command, 1 -> SCSI task
				   management function, .... */

	__u32 request_len;	/* [i] in bytes */
	__c64_ptr64 request;	/* [i], [*i] {SCSI: cdb} */
	__u64 request_tag;	/* [i] {SCSI: task tag (only if flagged)} */
	__u32 request_attr;	/* [i] {SCSI: task attribute} */
	__u32 request_priority;	/* [i] {SCSI: task priority} */
	__u32 request_extra;	/* [i] {spare, for padding} */
	__u32 max_response_len;	/* [i] in bytes */
	__c64_ptr64 response;	/* [i], [*o] {SCSI: (auto)sense data} */

        /* "dout_": data out (to device); "din_": data in (from device) */
	__u32 dout_iovec_count;	/* [i] 0 -> "flat" dout transfer else
				   dout_xfer points to array of iovec */
	__u32 dout_xfer_len;	/* [i] bytes to be transferred to device */
	__u32 din_iovec_count;	/* [i] 0 -> "flat" din transfer */
	__u32 din_xfer_len;	/* [i] bytes to be transferred from device */
	__c64_ptr64 dout_xferp;	/* [i], [*i] */
	__c64_ptr64 din_xferp;	/* [i], [*o] */

	__u32 timeout;		/* [i] units: millisecond */
	__u32 flags;		/* [i] bit mask */
	__u64 usr_ptr;		/* [i->o] unused internally */
	__u32 spare_in;		/* [i] */

	__u32 driver_status;	/* [o] 0 -> ok */
	__u32 transport_status;	/* [o] 0 -> ok */
	__u32 device_status;	/* [o] {SCSI: command completion status} */
	__u32 retry_delay;	/* [o] {SCSI: status auxiliary information} */
	__u32 info;		/* [o] additional information */
	__u32 duration;		/* [o] time to complete, in milliseconds */
	__u32 response_len;	/* [o] bytes of response actually written */
	__s32 din_resid;	/* [o] din_xfer_len - actual_din_xfer_len */
	__s32 dout_resid;	/* [o] dout_xfer_len - actual_dout_xfer_len */
	__u64 generated_tag;	/* [o] {SCSI: transport generated task tag} */
	__u32 spare_out;	/* [o] */

	__u32 padding;
};

static __always_inline __maybe_unused void
__from_c64_sg_io_v4(struct sg_io_v4 *p)
{
	union {
		struct sg_io_v4 native;
		const struct __c64_sg_io_v4 compat;
	} *u = (void *)p;

	u->native.padding = u->compat.padding;
	u->native.spare_out = u->compat.spare_out;
	u->native.generated_tag = u->compat.generated_tag;
	u->native.dout_resid = u->compat.dout_resid;
	u->native.din_resid = u->compat.din_resid;
	u->native.response_len = u->compat.response_len;
	u->native.duration = u->compat.duration;
	u->native.info = u->compat.info;
	u->native.retry_delay = u->compat.retry_delay;
	u->native.device_status = u->compat.device_status;
	u->native.transport_status = u->compat.transport_status;
	u->native.driver_status = u->compat.driver_status;
	u->native.spare_in = u->compat.spare_in;
	u->native.usr_ptr = u->compat.usr_ptr;
	u->native.flags = u->compat.flags;
	u->native.timeout = u->compat.timeout;
	u->native.din_xferp = (user_uintptr_t)compat_ptr(u->compat.din_xferp);
	u->native.dout_xferp = (user_uintptr_t)compat_ptr(u->compat.dout_xferp);
	u->native.din_xfer_len = u->compat.din_xfer_len;
	u->native.din_iovec_count = u->compat.din_iovec_count;
	u->native.dout_xfer_len = u->compat.dout_xfer_len;
	u->native.dout_iovec_count = u->compat.dout_iovec_count;
	u->native.response = (user_uintptr_t)compat_ptr(u->compat.response);
	u->native.max_response_len = u->compat.max_response_len;
	u->native.request_extra = u->compat.request_extra;
	u->native.request_priority = u->compat.request_priority;
	u->native.request_attr = u->compat.request_attr;
	u->native.request_tag = u->compat.request_tag;
	u->native.request = (user_uintptr_t)compat_ptr(u->compat.request);
	u->native.request_len = u->compat.request_len;
	u->native.subprotocol = u->compat.subprotocol;
	u->native.protocol = u->compat.protocol;
	u->native.guard = u->compat.guard;
}
static __always_inline __maybe_unused void
__to_c64_sg_io_v4(struct sg_io_v4 *p)
{
	union {
		struct __c64_sg_io_v4 compat;
		const struct sg_io_v4 native;
	} *u = (void *)p;

	u->compat.guard = u->native.guard;
	u->compat.protocol = u->native.protocol;
	u->compat.subprotocol = u->native.subprotocol;
	u->compat.request_len = u->native.request_len;
	u->compat.request = (__c64_ptr64 __force)u->native.request;
	u->compat.request_tag = u->native.request_tag;
	u->compat.request_attr = u->native.request_attr;
	u->compat.request_priority = u->native.request_priority;
	u->compat.request_extra = u->native.request_extra;
	u->compat.max_response_len = u->native.max_response_len;
	u->compat.response = (__c64_ptr64 __force)u->native.response;
	u->compat.dout_iovec_count = u->native.dout_iovec_count;
	u->compat.dout_xfer_len = u->native.dout_xfer_len;
	u->compat.din_iovec_count = u->native.din_iovec_count;
	u->compat.din_xfer_len = u->native.din_xfer_len;
	u->compat.dout_xferp = (__c64_ptr64 __force)u->native.dout_xferp;
	u->compat.din_xferp = (__c64_ptr64 __force)u->native.din_xferp;
	u->compat.timeout = u->native.timeout;
	u->compat.flags = u->native.flags;
	u->compat.usr_ptr = u->native.usr_ptr;
	u->compat.spare_in = u->native.spare_in;
	u->compat.driver_status = u->native.driver_status;
	u->compat.transport_status = u->native.transport_status;
	u->compat.device_status = u->native.device_status;
	u->compat.retry_delay = u->native.retry_delay;
	u->compat.info = u->native.info;
	u->compat.duration = u->native.duration;
	u->compat.response_len = u->native.response_len;
	u->compat.din_resid = u->native.din_resid;
	u->compat.dout_resid = u->native.dout_resid;
	u->compat.generated_tag = u->native.generated_tag;
	u->compat.spare_out = u->native.spare_out;
	u->compat.padding = u->native.padding;
}
static __always_inline __maybe_unused void
__from_c64_sg_io_v4_2(struct sg_io_v4 *native, const struct __c64_sg_io_v4 *compat)
{

	native->guard = compat->guard;
	native->protocol = compat->protocol;
	native->subprotocol = compat->subprotocol;
	native->request_len = compat->request_len;
	native->request = (user_uintptr_t)compat_ptr(compat->request);
	native->request_tag = compat->request_tag;
	native->request_attr = compat->request_attr;
	native->request_priority = compat->request_priority;
	native->request_extra = compat->request_extra;
	native->max_response_len = compat->max_response_len;
	native->response = (user_uintptr_t)compat_ptr(compat->response);
	native->dout_iovec_count = compat->dout_iovec_count;
	native->dout_xfer_len = compat->dout_xfer_len;
	native->din_iovec_count = compat->din_iovec_count;
	native->din_xfer_len = compat->din_xfer_len;
	native->dout_xferp = (user_uintptr_t)compat_ptr(compat->dout_xferp);
	native->din_xferp = (user_uintptr_t)compat_ptr(compat->din_xferp);
	native->timeout = compat->timeout;
	native->flags = compat->flags;
	native->usr_ptr = compat->usr_ptr;
	native->spare_in = compat->spare_in;
	native->driver_status = compat->driver_status;
	native->transport_status = compat->transport_status;
	native->device_status = compat->device_status;
	native->retry_delay = compat->retry_delay;
	native->info = compat->info;
	native->duration = compat->duration;
	native->response_len = compat->response_len;
	native->din_resid = compat->din_resid;
	native->dout_resid = compat->dout_resid;
	native->generated_tag = compat->generated_tag;
	native->spare_out = compat->spare_out;
	native->padding = compat->padding;
}
static __always_inline __maybe_unused void
__to_c64_sg_io_v4_2(struct __c64_sg_io_v4 *compat, const struct sg_io_v4 *native)
{

	compat->guard = native->guard;
	compat->protocol = native->protocol;
	compat->subprotocol = native->subprotocol;
	compat->request_len = native->request_len;
	compat->request = (__c64_ptr64 __force)native->request;
	compat->request_tag = native->request_tag;
	compat->request_attr = native->request_attr;
	compat->request_priority = native->request_priority;
	compat->request_extra = native->request_extra;
	compat->max_response_len = native->max_response_len;
	compat->response = (__c64_ptr64 __force)native->response;
	compat->dout_iovec_count = native->dout_iovec_count;
	compat->dout_xfer_len = native->dout_xfer_len;
	compat->din_iovec_count = native->din_iovec_count;
	compat->din_xfer_len = native->din_xfer_len;
	compat->dout_xferp = (__c64_ptr64 __force)native->dout_xferp;
	compat->din_xferp = (__c64_ptr64 __force)native->din_xferp;
	compat->timeout = native->timeout;
	compat->flags = native->flags;
	compat->usr_ptr = native->usr_ptr;
	compat->spare_in = native->spare_in;
	compat->driver_status = native->driver_status;
	compat->transport_status = native->transport_status;
	compat->device_status = native->device_status;
	compat->retry_delay = native->retry_delay;
	compat->info = native->info;
	compat->duration = native->duration;
	compat->response_len = native->response_len;
	compat->din_resid = native->din_resid;
	compat->dout_resid = native->dout_resid;
	compat->generated_tag = native->generated_tag;
	compat->spare_out = native->spare_out;
	compat->padding = native->padding;
}
