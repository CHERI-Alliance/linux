/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM csd

#if !defined(_TRACE_CSD_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_CSD_H

#include <linux/tracepoint.h>

TRACE_EVENT(csd_queue_cpu,

	TP_PROTO(const unsigned int cpu,
		unsigned long callsite,
		smp_call_func_t func,
		call_single_data_t *csd),

	TP_ARGS(cpu, callsite, func, csd),

	TP_STRUCT__entry(
		__field(unsigned int, cpu)
		__ptr(void *, callsite)
		__ptr(void *, func)
		__ptr(void *, csd)
		),

	    TP_fast_assign(
		__entry->cpu = cpu;
		__assign_ptr(callsite, __c_fakep(callsite));
		__assign_ptr(func, func);
		__assign_ptr(csd, csd);
		),

	TP_printk("cpu=%u callsite=%pS func=%ps csd=" TRACE_CAP_FMT,
		__entry->cpu, __get_ptr(callsite), __get_ptr(func), __get_cap(csd))
	);

/*
 * Tracepoints for a function which is called as an effect of smp_call_function.*
 */
DECLARE_EVENT_CLASS(csd_function,

	TP_PROTO(smp_call_func_t func, call_single_data_t *csd),

	TP_ARGS(func, csd),

	TP_STRUCT__entry(
		__ptr(void *,	func)
		__ptr(void *,	csd)
	),

	TP_fast_assign(
		__assign_ptr(func, func);
		__assign_ptr(csd, csd);
	),

	TP_printk("func=%ps, csd=" TRACE_CAP_FMT, __get_ptr(func), __get_cap(csd))
);

DEFINE_EVENT(csd_function, csd_function_entry,
	TP_PROTO(smp_call_func_t func, call_single_data_t *csd),
	TP_ARGS(func, csd)
);

DEFINE_EVENT(csd_function, csd_function_exit,
	TP_PROTO(smp_call_func_t func, call_single_data_t *csd),
	TP_ARGS(func, csd)
);

#endif /* _TRACE_CSD_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
