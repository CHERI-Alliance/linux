/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM notifier

#if !defined(_TRACE_NOTIFIERS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_NOTIFIERS_H

#include <linux/tracepoint.h>

DECLARE_EVENT_CLASS(notifier_info,

	TP_PROTO(void *cb),

	TP_ARGS(cb),

	TP_STRUCT__entry(
		__ptr(void *, cb)
	),

	TP_fast_assign(
		__assign_ptr(cb, cb);
	),

	TP_printk("%ps", __get_ptr(cb))
);

/*
 * notifier_register - called upon notifier callback registration
 *
 * @cb:		callback pointer
 *
 */
DEFINE_EVENT(notifier_info, notifier_register,

	TP_PROTO(void *cb),

	TP_ARGS(cb)
);

/*
 * notifier_unregister - called upon notifier callback unregistration
 *
 * @cb:		callback pointer
 *
 */
DEFINE_EVENT(notifier_info, notifier_unregister,

	TP_PROTO(void *cb),

	TP_ARGS(cb)
);

/*
 * notifier_run - called upon notifier callback execution
 *
 * @cb:		callback pointer
 *
 */
DEFINE_EVENT(notifier_info, notifier_run,

	TP_PROTO(void *cb),

	TP_ARGS(cb)
);

#endif /* _TRACE_NOTIFIERS_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
