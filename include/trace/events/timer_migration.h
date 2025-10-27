/* SPDX-License-Identifier: GPL-2.0-only */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM timer_migration

#if !defined(_TRACE_TIMER_MIGRATION_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_TIMER_MIGRATION_H

#include <linux/tracepoint.h>

/* Group events */
TRACE_EVENT(tmigr_group_set,

	TP_PROTO(struct tmigr_group *group),

	TP_ARGS(group),

	TP_STRUCT__entry(
		__ptr( void *,		group		)
		__field( unsigned int,	lvl		)
		__field( unsigned int,	numa_node	)
	),

	TP_fast_assign(
		__assign_ptr(group, group);
		__entry->lvl		= group->level;
		__entry->numa_node	= group->numa_node;
	),

	TP_printk("group=" TRACE_CAP_FMT " lvl=%d numa=%d",
		  __get_cap(group), __entry->lvl, __entry->numa_node)
);

TRACE_EVENT(tmigr_connect_child_parent,

	TP_PROTO(struct tmigr_group *child),

	TP_ARGS(child),

	TP_STRUCT__entry(
		__ptr( void *,		child		)
		__ptr( void *,		parent		)
		__field( unsigned int,	lvl		)
		__field( unsigned int,	numa_node	)
		__field( unsigned int,	num_children	)
		__field( u32,		groupmask	)
	),

	TP_fast_assign(
		__assign_ptr(child, child);
		__assign_ptr(parent, child->parent);
		__entry->lvl		= child->parent->level;
		__entry->numa_node	= child->parent->numa_node;
		__entry->num_children	= child->parent->num_children;
		__entry->groupmask	= child->groupmask;
	),

	TP_printk("group=" TRACE_CAP_FMT " groupmask=%0x parent=" TRACE_CAP_FMT " lvl=%d numa=%d num_children=%d",
		  __get_cap(child),  __entry->groupmask, __get_cap(parent),
		  __entry->lvl, __entry->numa_node, __entry->num_children)
);

TRACE_EVENT(tmigr_connect_cpu_parent,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc),

	TP_STRUCT__entry(
		__ptr( void *,		parent		)
		__field( unsigned int,	cpu		)
		__field( unsigned int,	lvl		)
		__field( unsigned int,	numa_node	)
		__field( unsigned int,	num_children	)
		__field( u32,		groupmask	)
	),

	TP_fast_assign(
		__assign_ptr(parent, tmc->tmgroup);
		__entry->cpu		= tmc->cpuevt.cpu;
		__entry->lvl		= tmc->tmgroup->level;
		__entry->numa_node	= tmc->tmgroup->numa_node;
		__entry->num_children	= tmc->tmgroup->num_children;
		__entry->groupmask	= tmc->groupmask;
	),

	TP_printk("cpu=%d groupmask=%0x parent=" TRACE_CAP_FMT " lvl=%d numa=%d num_children=%d",
		  __entry->cpu,	 __entry->groupmask, __get_cap(parent),
		  __entry->lvl, __entry->numa_node, __entry->num_children)
);

DECLARE_EVENT_CLASS(tmigr_group_and_cpu,

	TP_PROTO(struct tmigr_group *group, union tmigr_state state, u32 childmask),

	TP_ARGS(group, state, childmask),

	TP_STRUCT__entry(
		__ptr( void *,		group		)
		__ptr( void *,		parent		)
		__field( unsigned int,	lvl		)
		__field( unsigned int,	numa_node	)
		__field( u32,		childmask	)
		__field( u8,		active		)
		__field( u8,		migrator	)
	),

	TP_fast_assign(
		__assign_ptr(group, group);
		__assign_ptr(parent, group->parent);
		__entry->lvl		= group->level;
		__entry->numa_node	= group->numa_node;
		__entry->childmask	= childmask;
		__entry->active		= state.active;
		__entry->migrator	= state.migrator;
	),

	TP_printk("group=" TRACE_CAP_FMT " lvl=%d numa=%d active=%0x migrator=%0x "
		  "parent=" TRACE_CAP_FMT " childmask=%0x",
		  __get_cap(group), __entry->lvl, __entry->numa_node,
		  __entry->active, __entry->migrator,
		  __get_cap(parent), __entry->childmask)
);

DEFINE_EVENT(tmigr_group_and_cpu, tmigr_group_set_cpu_inactive,

	TP_PROTO(struct tmigr_group *group, union tmigr_state state, u32 childmask),

	TP_ARGS(group, state, childmask)
);

DEFINE_EVENT(tmigr_group_and_cpu, tmigr_group_set_cpu_active,

	TP_PROTO(struct tmigr_group *group, union tmigr_state state, u32 childmask),

	TP_ARGS(group, state, childmask)
);

/* CPU events*/
DECLARE_EVENT_CLASS(tmigr_cpugroup,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc),

	TP_STRUCT__entry(
		__field( u64,		wakeup	)
		__ptr( void *,		parent	)
		__field( unsigned int,	cpu	)

	),

	TP_fast_assign(
		__entry->wakeup		= tmc->wakeup;
		__assign_ptr(parent, tmc->tmgroup);
		__entry->cpu		= tmc->cpuevt.cpu;
	),

	TP_printk("cpu=%d parent=" TRACE_CAP_FMT " wakeup=%llu", __entry->cpu, __get_cap(parent), __entry->wakeup)
);

DEFINE_EVENT(tmigr_cpugroup, tmigr_cpu_new_timer,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc)
);

DEFINE_EVENT(tmigr_cpugroup, tmigr_cpu_active,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc)
);

DEFINE_EVENT(tmigr_cpugroup, tmigr_cpu_online,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc)
);

DEFINE_EVENT(tmigr_cpugroup, tmigr_cpu_offline,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc)
);

DEFINE_EVENT(tmigr_cpugroup, tmigr_handle_remote_cpu,

	TP_PROTO(struct tmigr_cpu *tmc),

	TP_ARGS(tmc)
);

DECLARE_EVENT_CLASS(tmigr_idle,

	TP_PROTO(struct tmigr_cpu *tmc, u64 nextevt),

	TP_ARGS(tmc, nextevt),

	TP_STRUCT__entry(
		__field( u64,		nextevt)
		__field( u64,		wakeup)
		__ptr( void *,		parent)
		__field( unsigned int,	cpu)
	),

	TP_fast_assign(
		__entry->nextevt	= nextevt;
		__entry->wakeup		= tmc->wakeup;
		__assign_ptr(parent, tmc->tmgroup);
		__entry->cpu		= tmc->cpuevt.cpu;
	),

	TP_printk("cpu=%d parent=" TRACE_CAP_FMT " nextevt=%llu wakeup=%llu",
		  __entry->cpu, __get_cap(parent), __entry->nextevt, __entry->wakeup)
);

DEFINE_EVENT(tmigr_idle, tmigr_cpu_idle,

	TP_PROTO(struct tmigr_cpu *tmc, u64 nextevt),

	TP_ARGS(tmc, nextevt)
);

DEFINE_EVENT(tmigr_idle, tmigr_cpu_new_timer_idle,

	TP_PROTO(struct tmigr_cpu *tmc, u64 nextevt),

	TP_ARGS(tmc, nextevt)
);

TRACE_EVENT(tmigr_update_events,

	TP_PROTO(struct tmigr_group *child, struct tmigr_group *group,
		 union tmigr_state childstate,	union tmigr_state groupstate,
		 u64 nextevt),

	TP_ARGS(child, group, childstate, groupstate, nextevt),

	TP_STRUCT__entry(
		__ptr( void *,		child			)
		__ptr( void *,		group			)
		__field( u64,		nextevt			)
		__field( u64,		group_next_expiry	)
		__field( u64,		child_evt_expiry	)
		__field( unsigned int,	group_lvl		)
		__field( unsigned int,	child_evtcpu		)
		__field( u8,		child_active		)
		__field( u8,		group_active		)
	),

	TP_fast_assign(
		__assign_ptr(child, child);
		__assign_ptr(group, group);
		__entry->nextevt		= nextevt;
		__entry->group_next_expiry	= group->next_expiry;
		__entry->child_evt_expiry	= child ? child->groupevt.nextevt.expires : 0;
		__entry->group_lvl		= group->level;
		__entry->child_evtcpu		= child ? child->groupevt.cpu : 0;
		__entry->child_active		= childstate.active;
		__entry->group_active		= groupstate.active;
	),

	TP_printk("child=" TRACE_CAP_FMT " group=" TRACE_CAP_FMT " group_lvl=%d child_active=%0x group_active=%0x "
		  "nextevt=%llu next_expiry=%llu child_evt_expiry=%llu child_evtcpu=%d",
		  __get_cap(child), __get_cap(group), __entry->group_lvl, __entry->child_active,
		  __entry->group_active,
		  __entry->nextevt, __entry->group_next_expiry, __entry->child_evt_expiry,
		  __entry->child_evtcpu)
);

TRACE_EVENT(tmigr_handle_remote,

	TP_PROTO(struct tmigr_group *group),

	TP_ARGS(group),

	TP_STRUCT__entry(
		__ptr( void * ,		group	)
		__field( unsigned int ,	lvl	)
	),

	TP_fast_assign(
		__assign_ptr(group, group);
		__entry->lvl		= group->level;
	),

	TP_printk("group=" TRACE_CAP_FMT " lvl=%d",
		   __get_cap(group), __entry->lvl)
);

#endif /*  _TRACE_TIMER_MIGRATION_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
