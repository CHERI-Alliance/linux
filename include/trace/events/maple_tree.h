/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM maple_tree

#if !defined(_TRACE_MM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MM_H


#include <linux/tracepoint.h>

struct ma_state;

TRACE_EVENT(ma_op,

	TP_PROTO(const char *fn, struct ma_state *mas),

	TP_ARGS(fn, mas),

	TP_STRUCT__entry(
			__ptr(const char *, fn)
			__field(unsigned long, min)
			__field(unsigned long, max)
			__field(unsigned long, index)
			__field(unsigned long, last)
			__ptr(void *, node)
	),

	TP_fast_assign(
			__assign_ptr(fn, fn);
			__entry->min		= mas->min;
			__entry->max		= mas->max;
			__entry->index		= mas->index;
			__entry->last		= mas->last;
			__assign_ptr(node, mas->node);
	),

	TP_printk("%s\tNode: " TRACE_CAP_FMT " (%lu %lu) range: %lu-%lu",
		  __get_ptr_str(fn),
		  __get_cap(node),
		  (unsigned long) __entry->min,
		  (unsigned long) __entry->max,
		  (unsigned long) __entry->index,
		  (unsigned long) __entry->last
	)
)
TRACE_EVENT(ma_read,

	TP_PROTO(const char *fn, struct ma_state *mas),

	TP_ARGS(fn, mas),

	TP_STRUCT__entry(
			__ptr(const char *, fn)
			__field(unsigned long, min)
			__field(unsigned long, max)
			__field(unsigned long, index)
			__field(unsigned long, last)
			__ptr(void *, node)
	),

	TP_fast_assign(
			__assign_ptr(fn, fn);
			__entry->min		= mas->min;
			__entry->max		= mas->max;
			__entry->index		= mas->index;
			__entry->last		= mas->last;
			__assign_ptr(node, mas->node);
	),

	TP_printk("%s\tNode: " TRACE_CAP_FMT " (%lu %lu) range: %lu-%lu",
		  __get_ptr_str(fn),
		  __get_cap(node),
		  (unsigned long) __entry->min,
		  (unsigned long) __entry->max,
		  (unsigned long) __entry->index,
		  (unsigned long) __entry->last
	)
)

TRACE_EVENT(ma_write,

	TP_PROTO(const char *fn, struct ma_state *mas, unsigned long piv,
		 void *val),

	TP_ARGS(fn, mas, piv, val),

	TP_STRUCT__entry(
			__ptr(const char *, fn)
			__field(unsigned long, min)
			__field(unsigned long, max)
			__field(unsigned long, index)
			__field(unsigned long, last)
			__field(unsigned long, piv)
			__ptr(void *, val)
			__ptr(void *, node)
	),

	TP_fast_assign(
			__assign_ptr(fn, fn);
			__entry->min		= mas->min;
			__entry->max		= mas->max;
			__entry->index		= mas->index;
			__entry->last		= mas->last;
			__entry->piv		= piv;
			__assign_ptr(val, val);
			__assign_ptr(node, mas->node);
	),

	TP_printk("%s\tNode " TRACE_CAP_FMT " (%lu %lu) range:%lu-%lu piv (%lu) val " TRACE_CAP_FMT,
		  __get_ptr_str(fn),
		  __get_cap(node),
		  (unsigned long) __entry->min,
		  (unsigned long) __entry->max,
		  (unsigned long) __entry->index,
		  (unsigned long) __entry->last,
		  (unsigned long) __entry->piv,
		  __get_cap(val)
	)
)
#endif /* _TRACE_MM_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
