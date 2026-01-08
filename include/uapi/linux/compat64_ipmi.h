#pragma once


#include <linux/compat.h>


struct __c64_ipmi_msg {
	unsigned char  netfn;
	unsigned char  cmd;
	unsigned short data_len;
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_ipmi_msg(struct ipmi_msg *p)
{
	union {
		struct ipmi_msg native;
		const struct __c64_ipmi_msg compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.data_len = u->compat.data_len;
	u->native.cmd = u->compat.cmd;
	u->native.netfn = u->compat.netfn;
}
static __always_inline __maybe_unused void
__to_c64_ipmi_msg(struct ipmi_msg *p)
{
	union {
		struct __c64_ipmi_msg compat;
		const struct ipmi_msg native;
	} *u = (void *)p;

	u->compat.netfn = u->native.netfn;
	u->compat.cmd = u->native.cmd;
	u->compat.data_len = u->native.data_len;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_ipmi_msg_2(struct ipmi_msg *native, const struct __c64_ipmi_msg *compat)
{

	native->netfn = compat->netfn;
	native->cmd = compat->cmd;
	native->data_len = compat->data_len;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_ipmi_msg_2(struct __c64_ipmi_msg *compat, const struct ipmi_msg *native)
{

	compat->netfn = native->netfn;
	compat->cmd = native->cmd;
	compat->data_len = native->data_len;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_kernel_ipmi_msg {
	unsigned char  netfn;
	unsigned char  cmd;
	unsigned short data_len;
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_kernel_ipmi_msg(struct kernel_ipmi_msg *p)
{
	union {
		struct kernel_ipmi_msg native;
		const struct __c64_kernel_ipmi_msg compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.data_len = u->compat.data_len;
	u->native.cmd = u->compat.cmd;
	u->native.netfn = u->compat.netfn;
}
static __always_inline __maybe_unused void
__to_c64_kernel_ipmi_msg(struct kernel_ipmi_msg *p)
{
	union {
		struct __c64_kernel_ipmi_msg compat;
		const struct kernel_ipmi_msg native;
	} *u = (void *)p;

	u->compat.netfn = u->native.netfn;
	u->compat.cmd = u->native.cmd;
	u->compat.data_len = u->native.data_len;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_kernel_ipmi_msg_2(struct kernel_ipmi_msg *native, const struct __c64_kernel_ipmi_msg *compat)
{

	native->netfn = compat->netfn;
	native->cmd = compat->cmd;
	native->data_len = compat->data_len;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_kernel_ipmi_msg_2(struct __c64_kernel_ipmi_msg *compat, const struct kernel_ipmi_msg *native)
{

	compat->netfn = native->netfn;
	compat->cmd = native->cmd;
	compat->data_len = native->data_len;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_ipmi_req {
	__c64_uptr addr; /* Address to send the message to. */
	unsigned int  addr_len;

	long    msgid; /* The sequence number for the message.  This
			  exact value will be reported back in the
			  response to this request if it is a command.
			  If it is a response, this will be used as
			  the sequence value for the response.  */

	struct __c64_ipmi_msg msg;
};

static __always_inline __maybe_unused void
__from_c64_ipmi_req(struct ipmi_req *p)
{
	union {
		struct ipmi_req native;
		const struct __c64_ipmi_req compat;
	} *u = (void *)p;

	u->native.msg.data =  compat_ptr(u->compat.msg.data);
	u->native.msg.data_len = u->compat.msg.data_len;
	u->native.msg.cmd = u->compat.msg.cmd;
	u->native.msg.netfn = u->compat.msg.netfn;
	u->native.msgid = u->compat.msgid;
	u->native.addr_len = u->compat.addr_len;
	u->native.addr =  compat_ptr(u->compat.addr);
}
static __always_inline __maybe_unused void
__to_c64_ipmi_req(struct ipmi_req *p)
{
	union {
		struct __c64_ipmi_req compat;
		const struct ipmi_req native;
	} *u = (void *)p;

	u->compat.addr =  (__c64_uptr __force)(user_uintptr_t)u->native.addr;
	u->compat.addr_len = u->native.addr_len;
	u->compat.msgid = u->native.msgid;
	u->compat.msg.netfn = u->native.msg.netfn;
	u->compat.msg.cmd = u->native.msg.cmd;
	u->compat.msg.data_len = u->native.msg.data_len;
	u->compat.msg.data =  (__c64_uptr __force)(user_uintptr_t)u->native.msg.data;
}
static __always_inline __maybe_unused void
__from_c64_ipmi_req_2(struct ipmi_req *native, const struct __c64_ipmi_req *compat)
{

	native->addr =  compat_ptr(compat->addr);
	native->addr_len = compat->addr_len;
	native->msgid = compat->msgid;
	native->msg.netfn = compat->msg.netfn;
	native->msg.cmd = compat->msg.cmd;
	native->msg.data_len = compat->msg.data_len;
	native->msg.data =  compat_ptr(compat->msg.data);
}
static __always_inline __maybe_unused void
__to_c64_ipmi_req_2(struct __c64_ipmi_req *compat, const struct ipmi_req *native)
{

	compat->addr =  (__c64_uptr __force)(user_uintptr_t)native->addr;
	compat->addr_len = native->addr_len;
	compat->msgid = native->msgid;
	compat->msg.netfn = native->msg.netfn;
	compat->msg.cmd = native->msg.cmd;
	compat->msg.data_len = native->msg.data_len;
	compat->msg.data =  (__c64_uptr __force)(user_uintptr_t)native->msg.data;
}
struct __c64_ipmi_req_settime {
	struct __c64_ipmi_req req;

	/* See ipmi_request_settime() above for details on these
	   values. */
	int          retries;
	unsigned int retry_time_ms;
};

static __always_inline __maybe_unused void
__from_c64_ipmi_req_settime(struct ipmi_req_settime *p)
{
	union {
		struct ipmi_req_settime native;
		const struct __c64_ipmi_req_settime compat;
	} *u = (void *)p;

	u->native.retry_time_ms = u->compat.retry_time_ms;
	u->native.retries = u->compat.retries;
	u->native.req.msg.data =  compat_ptr(u->compat.req.msg.data);
	u->native.req.msg.data_len = u->compat.req.msg.data_len;
	u->native.req.msg.cmd = u->compat.req.msg.cmd;
	u->native.req.msg.netfn = u->compat.req.msg.netfn;
	u->native.req.msgid = u->compat.req.msgid;
	u->native.req.addr_len = u->compat.req.addr_len;
	u->native.req.addr =  compat_ptr(u->compat.req.addr);
}
static __always_inline __maybe_unused void
__to_c64_ipmi_req_settime(struct ipmi_req_settime *p)
{
	union {
		struct __c64_ipmi_req_settime compat;
		const struct ipmi_req_settime native;
	} *u = (void *)p;

	u->compat.req.addr =  (__c64_uptr __force)(user_uintptr_t)u->native.req.addr;
	u->compat.req.addr_len = u->native.req.addr_len;
	u->compat.req.msgid = u->native.req.msgid;
	u->compat.req.msg.netfn = u->native.req.msg.netfn;
	u->compat.req.msg.cmd = u->native.req.msg.cmd;
	u->compat.req.msg.data_len = u->native.req.msg.data_len;
	u->compat.req.msg.data =  (__c64_uptr __force)(user_uintptr_t)u->native.req.msg.data;
	u->compat.retries = u->native.retries;
	u->compat.retry_time_ms = u->native.retry_time_ms;
}
static __always_inline __maybe_unused void
__from_c64_ipmi_req_settime_2(struct ipmi_req_settime *native, const struct __c64_ipmi_req_settime *compat)
{

	native->req.addr =  compat_ptr(compat->req.addr);
	native->req.addr_len = compat->req.addr_len;
	native->req.msgid = compat->req.msgid;
	native->req.msg.netfn = compat->req.msg.netfn;
	native->req.msg.cmd = compat->req.msg.cmd;
	native->req.msg.data_len = compat->req.msg.data_len;
	native->req.msg.data =  compat_ptr(compat->req.msg.data);
	native->retries = compat->retries;
	native->retry_time_ms = compat->retry_time_ms;
}
static __always_inline __maybe_unused void
__to_c64_ipmi_req_settime_2(struct __c64_ipmi_req_settime *compat, const struct ipmi_req_settime *native)
{

	compat->req.addr =  (__c64_uptr __force)(user_uintptr_t)native->req.addr;
	compat->req.addr_len = native->req.addr_len;
	compat->req.msgid = native->req.msgid;
	compat->req.msg.netfn = native->req.msg.netfn;
	compat->req.msg.cmd = native->req.msg.cmd;
	compat->req.msg.data_len = native->req.msg.data_len;
	compat->req.msg.data =  (__c64_uptr __force)(user_uintptr_t)native->req.msg.data;
	compat->retries = native->retries;
	compat->retry_time_ms = native->retry_time_ms;
}
struct __c64_ipmi_recv {
	int     recv_type; /* Is this a command, response or an
			      asyncronous event. */

	__c64_uptr addr;    /* Address the message was from is put
				   here.  The caller must supply the
				   memory. */
	unsigned int  addr_len; /* The size of the address buffer.
				   The caller supplies the full buffer
				   length, this value is updated to
				   the actual message length when the
				   message is received. */

	long    msgid; /* The sequence number specified in the request
			  if this is a response.  If this is a command,
			  this will be the sequence number from the
			  command. */

	struct __c64_ipmi_msg msg; /* The data field must point to a buffer.
				The data_size field must be set to the
				size of the message buffer.  The
				caller supplies the full buffer
				length, this value is updated to the
				actual message length when the message
				is received. */
};

static __always_inline __maybe_unused void
__from_c64_ipmi_recv(struct ipmi_recv *p)
{
	union {
		struct ipmi_recv native;
		const struct __c64_ipmi_recv compat;
	} *u = (void *)p;

	u->native.msg.data =  compat_ptr(u->compat.msg.data);
	u->native.msg.data_len = u->compat.msg.data_len;
	u->native.msg.cmd = u->compat.msg.cmd;
	u->native.msg.netfn = u->compat.msg.netfn;
	u->native.msgid = u->compat.msgid;
	u->native.addr_len = u->compat.addr_len;
	u->native.addr =  compat_ptr(u->compat.addr);
	u->native.recv_type = u->compat.recv_type;
}
static __always_inline __maybe_unused void
__to_c64_ipmi_recv(struct ipmi_recv *p)
{
	union {
		struct __c64_ipmi_recv compat;
		const struct ipmi_recv native;
	} *u = (void *)p;

	u->compat.recv_type = u->native.recv_type;
	u->compat.addr =  (__c64_uptr __force)(user_uintptr_t)u->native.addr;
	u->compat.addr_len = u->native.addr_len;
	u->compat.msgid = u->native.msgid;
	u->compat.msg.netfn = u->native.msg.netfn;
	u->compat.msg.cmd = u->native.msg.cmd;
	u->compat.msg.data_len = u->native.msg.data_len;
	u->compat.msg.data =  (__c64_uptr __force)(user_uintptr_t)u->native.msg.data;
}
static __always_inline __maybe_unused void
__from_c64_ipmi_recv_2(struct ipmi_recv *native, const struct __c64_ipmi_recv *compat)
{

	native->recv_type = compat->recv_type;
	native->addr =  compat_ptr(compat->addr);
	native->addr_len = compat->addr_len;
	native->msgid = compat->msgid;
	native->msg.netfn = compat->msg.netfn;
	native->msg.cmd = compat->msg.cmd;
	native->msg.data_len = compat->msg.data_len;
	native->msg.data =  compat_ptr(compat->msg.data);
}
static __always_inline __maybe_unused void
__to_c64_ipmi_recv_2(struct __c64_ipmi_recv *compat, const struct ipmi_recv *native)
{

	compat->recv_type = native->recv_type;
	compat->addr =  (__c64_uptr __force)(user_uintptr_t)native->addr;
	compat->addr_len = native->addr_len;
	compat->msgid = native->msgid;
	compat->msg.netfn = native->msg.netfn;
	compat->msg.cmd = native->msg.cmd;
	compat->msg.data_len = native->msg.data_len;
	compat->msg.data =  (__c64_uptr __force)(user_uintptr_t)native->msg.data;
}
