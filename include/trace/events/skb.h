/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM skb

#if !defined(_TRACE_SKB_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_SKB_H

#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/tracepoint.h>

#undef FN
#define FN(reason)	TRACE_DEFINE_ENUM(SKB_DROP_REASON_##reason);
DEFINE_DROP_REASON(FN, FN)

#undef FN
#undef FNe
#define FN(reason)	{ SKB_DROP_REASON_##reason, #reason },
#define FNe(reason)	{ SKB_DROP_REASON_##reason, #reason }

/*
 * Tracepoint for free an sk_buff:
 */
TRACE_EVENT(kfree_skb,

	TP_PROTO(struct sk_buff *skb, void *location,
		 enum skb_drop_reason reason, struct sock *rx_sk),

	TP_ARGS(skb, location, reason, rx_sk),

	TP_STRUCT__entry(
		__ptr(void *,		skbaddr)
		__ptr(void *,		location)
		__ptr(void *,		rx_sk)
		__field(unsigned short,	protocol)
		__field(enum skb_drop_reason,	reason)
	),

	TP_fast_assign(
		__assign_ptr(skbaddr, skb);
		__assign_ptr(location, location);
		__assign_ptr(rx_sk, rx_sk);
		__entry->protocol = ntohs(skb->protocol);
		__entry->reason = reason;
	),

	TP_printk("skbaddr=" TRACE_CAP_FMT " rx_sk=" TRACE_CAP_FMT " protocol=%u location=%pS reason: %s",
		  __get_cap(skbaddr), __get_cap(rx_sk), __entry->protocol,
		  __get_ptr(location),
		  __print_symbolic(__entry->reason,
				   DEFINE_DROP_REASON(FN, FNe)))
);

#undef FN
#undef FNe

TRACE_EVENT(consume_skb,

	TP_PROTO(struct sk_buff *skb, void *location),

	TP_ARGS(skb, location),

	TP_STRUCT__entry(
		__ptr(		void *,	skbaddr)
		__ptr(		void *,	location)
	),

	TP_fast_assign(
		__assign_ptr(skbaddr, skb);
		__assign_ptr(location, location);
	),

	TP_printk("skbaddr=" TRACE_CAP_FMT " location=%pS", __get_cap(skbaddr), __get_ptr(location))
);

TRACE_EVENT(skb_copy_datagram_iovec,

	TP_PROTO(const struct sk_buff *skb, int len),

	TP_ARGS(skb, len),

	TP_STRUCT__entry(
		__ptr(		const void *,		skbaddr		)
		__field(	int,			len		)
	),

	TP_fast_assign(
		__assign_ptr(skbaddr, skb);
		__entry->len = len;
	),

	TP_printk("skbaddr=" TRACE_CAP_FMT " len=%d", __get_cap(skbaddr), __entry->len)
);

#endif /* _TRACE_SKB_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
