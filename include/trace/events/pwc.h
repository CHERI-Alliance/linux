/* SPDX-License-Identifier: GPL-2.0 */
#if !defined(_TRACE_PWC_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PWC_H

#include <linux/usb.h>
#include <linux/tracepoint.h>

#undef TRACE_SYSTEM
#define TRACE_SYSTEM pwc

TRACE_EVENT(pwc_handler_enter,
	TP_PROTO(struct urb *urb, struct pwc_device *pdev),
	TP_ARGS(urb, pdev),
	TP_STRUCT__entry(
		__ptr(struct urb*, urb)
		__ptr(struct pwc_frame_buf*, fbuf)
		__field(int, urb__status)
		__field(u32, urb__actual_length)
		__field(int, fbuf__filled)
		__string(name, pdev->v4l2_dev.name)
	),
	TP_fast_assign(
		__assign_ptr(urb, urb);
		__assign_ptr(fbuf, pdev->fill_buf);
		__entry->urb__status = urb->status;
		__entry->urb__actual_length = urb->actual_length;
		__entry->fbuf__filled = (pdev->fill_buf
					 ? pdev->fill_buf->filled : 0);
		__assign_str(name);
	),
	TP_printk("dev=%s (fbuf=" TRACE_CAP_FMT " filled=%d) urb=" TRACE_CAP_FMT " (status=%d actual_length=%u)",
		__get_str(name),
		__get_cap(fbuf),
		__entry->fbuf__filled,
		__get_cap(urb),
		__entry->urb__status,
		__entry->urb__actual_length)
);

TRACE_EVENT(pwc_handler_exit,
	TP_PROTO(struct urb *urb, struct pwc_device *pdev),
	TP_ARGS(urb, pdev),
	TP_STRUCT__entry(
		__ptr(struct urb*, urb)
		__ptr(struct pwc_frame_buf*, fbuf)
		__field(int, fbuf__filled)
		__string(name, pdev->v4l2_dev.name)
	),
	TP_fast_assign(
		__assign_ptr(urb, urb);
		__assign_ptr(fbuf, pdev->fill_buf);
		__entry->fbuf__filled = pdev->fill_buf->filled;
		__assign_str(name);
	),
	TP_printk(" dev=%s (fbuf=" TRACE_CAP_FMT " filled=%d) urb=" TRACE_CAP_FMT "",
		__get_str(name),
		__get_cap(fbuf),
		__entry->fbuf__filled,
		__get_cap(urb))
);

#endif /* _TRACE_PWC_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
