#pragma once


#include <linux/compat.h>


struct __c64_epoll_event {
	__poll_t events;
	__c64_ptr64 data;
} EPOLL_PACKED;

static __always_inline __maybe_unused void
__from_c64_epoll_event(struct epoll_event *p)
{
	union {
		struct epoll_event native;
		const struct __c64_epoll_event compat;
	} *u = (void *)p;

	u->native.data = (user_uintptr_t)compat_ptr(u->compat.data);
	u->native.events = u->compat.events;
}
static __always_inline __maybe_unused void
__to_c64_epoll_event(struct epoll_event *p)
{
	union {
		struct __c64_epoll_event compat;
		const struct epoll_event native;
	} *u = (void *)p;

	u->compat.events = u->native.events;
	u->compat.data = (__c64_ptr64 __force)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_epoll_event_2(struct epoll_event *native, const struct __c64_epoll_event *compat)
{

	native->events = compat->events;
	native->data = (user_uintptr_t)compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_epoll_event_2(struct __c64_epoll_event *compat, const struct epoll_event *native)
{

	compat->events = native->events;
	compat->data = (__c64_ptr64 __force)native->data;
}
