#pragma once


#include <linux/compat.h>


struct __c64_comedi_insn {
	unsigned int insn;
	unsigned int n;
	__c64_uptr data;
	unsigned int subdev;
	unsigned int chanspec;
	unsigned int unused[3];
};

static __always_inline __maybe_unused void
__from_c64_comedi_insn(struct comedi_insn *p)
{
	union {
		struct comedi_insn native;
		const struct __c64_comedi_insn compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.unused) != sizeof(u->native.unused));
	memmove(&u->native.unused, &u->compat.unused, sizeof(u->native.unused));
	u->native.chanspec = u->compat.chanspec;
	u->native.subdev = u->compat.subdev;
	u->native.data =  compat_ptr(u->compat.data);
	u->native.n = u->compat.n;
	u->native.insn = u->compat.insn;
}
static __always_inline __maybe_unused void
__to_c64_comedi_insn(struct comedi_insn *p)
{
	union {
		struct __c64_comedi_insn compat;
		const struct comedi_insn native;
	} *u = (void *)p;

	u->compat.insn = u->native.insn;
	u->compat.n = u->native.n;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
	u->compat.subdev = u->native.subdev;
	u->compat.chanspec = u->native.chanspec;
	BUILD_BUG_ON(sizeof(u->native.unused) != sizeof(u->compat.unused));
	memmove(&u->compat.unused, &u->native.unused, sizeof(u->compat.unused));
}
static __always_inline __maybe_unused void
__from_c64_comedi_insn_2(struct comedi_insn *native, const struct __c64_comedi_insn *compat)
{

	native->insn = compat->insn;
	native->n = compat->n;
	native->data =  compat_ptr(compat->data);
	native->subdev = compat->subdev;
	native->chanspec = compat->chanspec;
	BUILD_BUG_ON(sizeof(compat->unused) != sizeof(native->unused));
	memcpy(&native->unused, &compat->unused, sizeof(native->unused));
}
static __always_inline __maybe_unused void
__to_c64_comedi_insn_2(struct __c64_comedi_insn *compat, const struct comedi_insn *native)
{

	compat->insn = native->insn;
	compat->n = native->n;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
	compat->subdev = native->subdev;
	compat->chanspec = native->chanspec;
	BUILD_BUG_ON(sizeof(native->unused) != sizeof(compat->unused));
	memcpy(&compat->unused, &native->unused, sizeof(compat->unused));
}
struct __c64_comedi_insnlist {
	unsigned int n_insns;
	__c64_uptr insns;
};

static __always_inline __maybe_unused void
__from_c64_comedi_insnlist(struct comedi_insnlist *p)
{
	union {
		struct comedi_insnlist native;
		const struct __c64_comedi_insnlist compat;
	} *u = (void *)p;

	u->native.insns =  compat_ptr(u->compat.insns);
	u->native.n_insns = u->compat.n_insns;
}
static __always_inline __maybe_unused void
__to_c64_comedi_insnlist(struct comedi_insnlist *p)
{
	union {
		struct __c64_comedi_insnlist compat;
		const struct comedi_insnlist native;
	} *u = (void *)p;

	u->compat.n_insns = u->native.n_insns;
	u->compat.insns =  (__c64_uptr __force)(user_uintptr_t)u->native.insns;
}
static __always_inline __maybe_unused void
__from_c64_comedi_insnlist_2(struct comedi_insnlist *native, const struct __c64_comedi_insnlist *compat)
{

	native->n_insns = compat->n_insns;
	native->insns =  compat_ptr(compat->insns);
}
static __always_inline __maybe_unused void
__to_c64_comedi_insnlist_2(struct __c64_comedi_insnlist *compat, const struct comedi_insnlist *native)
{

	compat->n_insns = native->n_insns;
	compat->insns =  (__c64_uptr __force)(user_uintptr_t)native->insns;
}
struct __c64_comedi_cmd {
	unsigned int subdev;
	unsigned int flags;

	unsigned int start_src;
	unsigned int start_arg;

	unsigned int scan_begin_src;
	unsigned int scan_begin_arg;

	unsigned int convert_src;
	unsigned int convert_arg;

	unsigned int scan_end_src;
	unsigned int scan_end_arg;

	unsigned int stop_src;
	unsigned int stop_arg;

	__c64_uptr chanlist;
	unsigned int chanlist_len;

	__c64_uptr data;
	unsigned int data_len;
};

static __always_inline __maybe_unused void
__from_c64_comedi_cmd(struct comedi_cmd *p)
{
	union {
		struct comedi_cmd native;
		const struct __c64_comedi_cmd compat;
	} *u = (void *)p;

	u->native.data_len = u->compat.data_len;
	u->native.data =  compat_ptr(u->compat.data);
	u->native.chanlist_len = u->compat.chanlist_len;
	u->native.chanlist =  compat_ptr(u->compat.chanlist);
	u->native.stop_arg = u->compat.stop_arg;
	u->native.stop_src = u->compat.stop_src;
	u->native.scan_end_arg = u->compat.scan_end_arg;
	u->native.scan_end_src = u->compat.scan_end_src;
	u->native.convert_arg = u->compat.convert_arg;
	u->native.convert_src = u->compat.convert_src;
	u->native.scan_begin_arg = u->compat.scan_begin_arg;
	u->native.scan_begin_src = u->compat.scan_begin_src;
	u->native.start_arg = u->compat.start_arg;
	u->native.start_src = u->compat.start_src;
	u->native.flags = u->compat.flags;
	u->native.subdev = u->compat.subdev;
}
static __always_inline __maybe_unused void
__to_c64_comedi_cmd(struct comedi_cmd *p)
{
	union {
		struct __c64_comedi_cmd compat;
		const struct comedi_cmd native;
	} *u = (void *)p;

	u->compat.subdev = u->native.subdev;
	u->compat.flags = u->native.flags;
	u->compat.start_src = u->native.start_src;
	u->compat.start_arg = u->native.start_arg;
	u->compat.scan_begin_src = u->native.scan_begin_src;
	u->compat.scan_begin_arg = u->native.scan_begin_arg;
	u->compat.convert_src = u->native.convert_src;
	u->compat.convert_arg = u->native.convert_arg;
	u->compat.scan_end_src = u->native.scan_end_src;
	u->compat.scan_end_arg = u->native.scan_end_arg;
	u->compat.stop_src = u->native.stop_src;
	u->compat.stop_arg = u->native.stop_arg;
	u->compat.chanlist =  (__c64_uptr __force)(user_uintptr_t)u->native.chanlist;
	u->compat.chanlist_len = u->native.chanlist_len;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
	u->compat.data_len = u->native.data_len;
}
static __always_inline __maybe_unused void
__from_c64_comedi_cmd_2(struct comedi_cmd *native, const struct __c64_comedi_cmd *compat)
{

	native->subdev = compat->subdev;
	native->flags = compat->flags;
	native->start_src = compat->start_src;
	native->start_arg = compat->start_arg;
	native->scan_begin_src = compat->scan_begin_src;
	native->scan_begin_arg = compat->scan_begin_arg;
	native->convert_src = compat->convert_src;
	native->convert_arg = compat->convert_arg;
	native->scan_end_src = compat->scan_end_src;
	native->scan_end_arg = compat->scan_end_arg;
	native->stop_src = compat->stop_src;
	native->stop_arg = compat->stop_arg;
	native->chanlist =  compat_ptr(compat->chanlist);
	native->chanlist_len = compat->chanlist_len;
	native->data =  compat_ptr(compat->data);
	native->data_len = compat->data_len;
}
static __always_inline __maybe_unused void
__to_c64_comedi_cmd_2(struct __c64_comedi_cmd *compat, const struct comedi_cmd *native)
{

	compat->subdev = native->subdev;
	compat->flags = native->flags;
	compat->start_src = native->start_src;
	compat->start_arg = native->start_arg;
	compat->scan_begin_src = native->scan_begin_src;
	compat->scan_begin_arg = native->scan_begin_arg;
	compat->convert_src = native->convert_src;
	compat->convert_arg = native->convert_arg;
	compat->scan_end_src = native->scan_end_src;
	compat->scan_end_arg = native->scan_end_arg;
	compat->stop_src = native->stop_src;
	compat->stop_arg = native->stop_arg;
	compat->chanlist =  (__c64_uptr __force)(user_uintptr_t)native->chanlist;
	compat->chanlist_len = native->chanlist_len;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
	compat->data_len = native->data_len;
}
struct __c64_comedi_chaninfo {
	unsigned int subdev;
	__c64_uptr maxdata_list;
	__c64_uptr flaglist;
	__c64_uptr rangelist;
	unsigned int unused[4];
};

static __always_inline __maybe_unused void
__from_c64_comedi_chaninfo(struct comedi_chaninfo *p)
{
	union {
		struct comedi_chaninfo native;
		const struct __c64_comedi_chaninfo compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.unused) != sizeof(u->native.unused));
	memmove(&u->native.unused, &u->compat.unused, sizeof(u->native.unused));
	u->native.rangelist =  compat_ptr(u->compat.rangelist);
	u->native.flaglist =  compat_ptr(u->compat.flaglist);
	u->native.maxdata_list =  compat_ptr(u->compat.maxdata_list);
	u->native.subdev = u->compat.subdev;
}
static __always_inline __maybe_unused void
__to_c64_comedi_chaninfo(struct comedi_chaninfo *p)
{
	union {
		struct __c64_comedi_chaninfo compat;
		const struct comedi_chaninfo native;
	} *u = (void *)p;

	u->compat.subdev = u->native.subdev;
	u->compat.maxdata_list =  (__c64_uptr __force)(user_uintptr_t)u->native.maxdata_list;
	u->compat.flaglist =  (__c64_uptr __force)(user_uintptr_t)u->native.flaglist;
	u->compat.rangelist =  (__c64_uptr __force)(user_uintptr_t)u->native.rangelist;
	BUILD_BUG_ON(sizeof(u->native.unused) != sizeof(u->compat.unused));
	memmove(&u->compat.unused, &u->native.unused, sizeof(u->compat.unused));
}
static __always_inline __maybe_unused void
__from_c64_comedi_chaninfo_2(struct comedi_chaninfo *native, const struct __c64_comedi_chaninfo *compat)
{

	native->subdev = compat->subdev;
	native->maxdata_list =  compat_ptr(compat->maxdata_list);
	native->flaglist =  compat_ptr(compat->flaglist);
	native->rangelist =  compat_ptr(compat->rangelist);
	BUILD_BUG_ON(sizeof(compat->unused) != sizeof(native->unused));
	memcpy(&native->unused, &compat->unused, sizeof(native->unused));
}
static __always_inline __maybe_unused void
__to_c64_comedi_chaninfo_2(struct __c64_comedi_chaninfo *compat, const struct comedi_chaninfo *native)
{

	compat->subdev = native->subdev;
	compat->maxdata_list =  (__c64_uptr __force)(user_uintptr_t)native->maxdata_list;
	compat->flaglist =  (__c64_uptr __force)(user_uintptr_t)native->flaglist;
	compat->rangelist =  (__c64_uptr __force)(user_uintptr_t)native->rangelist;
	BUILD_BUG_ON(sizeof(native->unused) != sizeof(compat->unused));
	memcpy(&compat->unused, &native->unused, sizeof(compat->unused));
}
struct __c64_comedi_rangeinfo {
	unsigned int range_type;
	__c64_uptr range_ptr;
};

static __always_inline __maybe_unused void
__from_c64_comedi_rangeinfo(struct comedi_rangeinfo *p)
{
	union {
		struct comedi_rangeinfo native;
		const struct __c64_comedi_rangeinfo compat;
	} *u = (void *)p;

	u->native.range_ptr =  compat_ptr(u->compat.range_ptr);
	u->native.range_type = u->compat.range_type;
}
static __always_inline __maybe_unused void
__to_c64_comedi_rangeinfo(struct comedi_rangeinfo *p)
{
	union {
		struct __c64_comedi_rangeinfo compat;
		const struct comedi_rangeinfo native;
	} *u = (void *)p;

	u->compat.range_type = u->native.range_type;
	u->compat.range_ptr =  (__c64_uptr __force)(user_uintptr_t)u->native.range_ptr;
}
static __always_inline __maybe_unused void
__from_c64_comedi_rangeinfo_2(struct comedi_rangeinfo *native, const struct __c64_comedi_rangeinfo *compat)
{

	native->range_type = compat->range_type;
	native->range_ptr =  compat_ptr(compat->range_ptr);
}
static __always_inline __maybe_unused void
__to_c64_comedi_rangeinfo_2(struct __c64_comedi_rangeinfo *compat, const struct comedi_rangeinfo *native)
{

	compat->range_type = native->range_type;
	compat->range_ptr =  (__c64_uptr __force)(user_uintptr_t)native->range_ptr;
}
