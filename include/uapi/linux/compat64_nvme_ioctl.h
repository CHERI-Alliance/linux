#pragma once


#include <linux/compat.h>


struct __c64_nvme_user_io {
	__u8	opcode;
	__u8	flags;
	__u16	control;
	__u16	nblocks;
	__u16	rsvd;
	/* CHERI: 64-bit implicit padding if sizeof(__u64ptr) > sizoef(u64) */
	__c64_ptr64	metadata;
	__c64_ptr64	addr;
	__u64	slba;
	__u32	dsmgmt;
	__u32	reftag;
	__u16	apptag;
	__u16	appmask;
};

static __always_inline __maybe_unused void
__from_c64_nvme_user_io(struct nvme_user_io *p)
{
	union {
		struct nvme_user_io native;
		const struct __c64_nvme_user_io compat;
	} *u = (void *)p;

	u->native.appmask = u->compat.appmask;
	u->native.apptag = u->compat.apptag;
	u->native.reftag = u->compat.reftag;
	u->native.dsmgmt = u->compat.dsmgmt;
	u->native.slba = u->compat.slba;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.metadata = (user_uintptr_t)compat_ptr(u->compat.metadata);
	u->native.rsvd = u->compat.rsvd;
	u->native.nblocks = u->compat.nblocks;
	u->native.control = u->compat.control;
	u->native.flags = u->compat.flags;
	u->native.opcode = u->compat.opcode;
}
static __always_inline __maybe_unused void
__to_c64_nvme_user_io(struct nvme_user_io *p)
{
	union {
		struct __c64_nvme_user_io compat;
		const struct nvme_user_io native;
	} *u = (void *)p;

	u->compat.opcode = u->native.opcode;
	u->compat.flags = u->native.flags;
	u->compat.control = u->native.control;
	u->compat.nblocks = u->native.nblocks;
	u->compat.rsvd = u->native.rsvd;
	u->compat.metadata = (__c64_ptr64 __force)u->native.metadata;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.slba = u->native.slba;
	u->compat.dsmgmt = u->native.dsmgmt;
	u->compat.reftag = u->native.reftag;
	u->compat.apptag = u->native.apptag;
	u->compat.appmask = u->native.appmask;
}
static __always_inline __maybe_unused void
__from_c64_nvme_user_io_2(struct nvme_user_io *native, const struct __c64_nvme_user_io *compat)
{

	native->opcode = compat->opcode;
	native->flags = compat->flags;
	native->control = compat->control;
	native->nblocks = compat->nblocks;
	native->rsvd = compat->rsvd;
	native->metadata = (user_uintptr_t)compat_ptr(compat->metadata);
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->slba = compat->slba;
	native->dsmgmt = compat->dsmgmt;
	native->reftag = compat->reftag;
	native->apptag = compat->apptag;
	native->appmask = compat->appmask;
}
static __always_inline __maybe_unused void
__to_c64_nvme_user_io_2(struct __c64_nvme_user_io *compat, const struct nvme_user_io *native)
{

	compat->opcode = native->opcode;
	compat->flags = native->flags;
	compat->control = native->control;
	compat->nblocks = native->nblocks;
	compat->rsvd = native->rsvd;
	compat->metadata = (__c64_ptr64 __force)native->metadata;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->slba = native->slba;
	compat->dsmgmt = native->dsmgmt;
	compat->reftag = native->reftag;
	compat->apptag = native->apptag;
	compat->appmask = native->appmask;
}
struct __c64_nvme_passthru_cmd {
	__u8	opcode;
	__u8	flags;
	__u16	rsvd1;
	__u32	nsid;
	__u32	cdw2;
	__u32	cdw3;
	__c64_ptr64	metadata;
	__c64_ptr64	addr;
	__u32	metadata_len;
	__u32	data_len;
	__u32	cdw10;
	__u32	cdw11;
	__u32	cdw12;
	__u32	cdw13;
	__u32	cdw14;
	__u32	cdw15;
	__u32	timeout_ms;
	__u32	result;
};

static __always_inline __maybe_unused void
__from_c64_nvme_passthru_cmd(struct nvme_passthru_cmd *p)
{
	union {
		struct nvme_passthru_cmd native;
		const struct __c64_nvme_passthru_cmd compat;
	} *u = (void *)p;

	u->native.result = u->compat.result;
	u->native.timeout_ms = u->compat.timeout_ms;
	u->native.cdw15 = u->compat.cdw15;
	u->native.cdw14 = u->compat.cdw14;
	u->native.cdw13 = u->compat.cdw13;
	u->native.cdw12 = u->compat.cdw12;
	u->native.cdw11 = u->compat.cdw11;
	u->native.cdw10 = u->compat.cdw10;
	u->native.data_len = u->compat.data_len;
	u->native.metadata_len = u->compat.metadata_len;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.metadata = (user_uintptr_t)compat_ptr(u->compat.metadata);
	u->native.cdw3 = u->compat.cdw3;
	u->native.cdw2 = u->compat.cdw2;
	u->native.nsid = u->compat.nsid;
	u->native.rsvd1 = u->compat.rsvd1;
	u->native.flags = u->compat.flags;
	u->native.opcode = u->compat.opcode;
}
static __always_inline __maybe_unused void
__to_c64_nvme_passthru_cmd(struct nvme_passthru_cmd *p)
{
	union {
		struct __c64_nvme_passthru_cmd compat;
		const struct nvme_passthru_cmd native;
	} *u = (void *)p;

	u->compat.opcode = u->native.opcode;
	u->compat.flags = u->native.flags;
	u->compat.rsvd1 = u->native.rsvd1;
	u->compat.nsid = u->native.nsid;
	u->compat.cdw2 = u->native.cdw2;
	u->compat.cdw3 = u->native.cdw3;
	u->compat.metadata = (__c64_ptr64 __force)u->native.metadata;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.metadata_len = u->native.metadata_len;
	u->compat.data_len = u->native.data_len;
	u->compat.cdw10 = u->native.cdw10;
	u->compat.cdw11 = u->native.cdw11;
	u->compat.cdw12 = u->native.cdw12;
	u->compat.cdw13 = u->native.cdw13;
	u->compat.cdw14 = u->native.cdw14;
	u->compat.cdw15 = u->native.cdw15;
	u->compat.timeout_ms = u->native.timeout_ms;
	u->compat.result = u->native.result;
}
static __always_inline __maybe_unused void
__from_c64_nvme_passthru_cmd_2(struct nvme_passthru_cmd *native, const struct __c64_nvme_passthru_cmd *compat)
{

	native->opcode = compat->opcode;
	native->flags = compat->flags;
	native->rsvd1 = compat->rsvd1;
	native->nsid = compat->nsid;
	native->cdw2 = compat->cdw2;
	native->cdw3 = compat->cdw3;
	native->metadata = (user_uintptr_t)compat_ptr(compat->metadata);
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->metadata_len = compat->metadata_len;
	native->data_len = compat->data_len;
	native->cdw10 = compat->cdw10;
	native->cdw11 = compat->cdw11;
	native->cdw12 = compat->cdw12;
	native->cdw13 = compat->cdw13;
	native->cdw14 = compat->cdw14;
	native->cdw15 = compat->cdw15;
	native->timeout_ms = compat->timeout_ms;
	native->result = compat->result;
}
static __always_inline __maybe_unused void
__to_c64_nvme_passthru_cmd_2(struct __c64_nvme_passthru_cmd *compat, const struct nvme_passthru_cmd *native)
{

	compat->opcode = native->opcode;
	compat->flags = native->flags;
	compat->rsvd1 = native->rsvd1;
	compat->nsid = native->nsid;
	compat->cdw2 = native->cdw2;
	compat->cdw3 = native->cdw3;
	compat->metadata = (__c64_ptr64 __force)native->metadata;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->metadata_len = native->metadata_len;
	compat->data_len = native->data_len;
	compat->cdw10 = native->cdw10;
	compat->cdw11 = native->cdw11;
	compat->cdw12 = native->cdw12;
	compat->cdw13 = native->cdw13;
	compat->cdw14 = native->cdw14;
	compat->cdw15 = native->cdw15;
	compat->timeout_ms = native->timeout_ms;
	compat->result = native->result;
}
struct __c64_nvme_passthru_cmd64 {
	__u8	opcode;
	__u8	flags;
	__u16	rsvd1;
	__u32	nsid;
	__u32	cdw2;
	__u32	cdw3;
	__c64_ptr64	metadata;
	__c64_ptr64	addr;
	__u32	metadata_len;
	union {
		__u32	data_len; /* for non-vectored io */
		__u32	vec_cnt; /* for vectored io */
	};
	__u32	cdw10;
	__u32	cdw11;
	__u32	cdw12;
	__u32	cdw13;
	__u32	cdw14;
	__u32	cdw15;
	__u32	timeout_ms;
	__u32   rsvd2;
	__u64	result;
};

static __always_inline __maybe_unused void
__from_c64_nvme_passthru_cmd64(struct nvme_passthru_cmd64 *p)
{
	union {
		struct nvme_passthru_cmd64 native;
		const struct __c64_nvme_passthru_cmd64 compat;
	} *u = (void *)p;

	u->native.result = u->compat.result;
	u->native.rsvd2 = u->compat.rsvd2;
	u->native.timeout_ms = u->compat.timeout_ms;
	u->native.cdw15 = u->compat.cdw15;
	u->native.cdw14 = u->compat.cdw14;
	u->native.cdw13 = u->compat.cdw13;
	u->native.cdw12 = u->compat.cdw12;
	u->native.cdw11 = u->compat.cdw11;
	u->native.cdw10 = u->compat.cdw10;
	u->native.vec_cnt = u->compat.vec_cnt;
	u->native.data_len = u->compat.data_len;
	u->native.metadata_len = u->compat.metadata_len;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.metadata = (user_uintptr_t)compat_ptr(u->compat.metadata);
	u->native.cdw3 = u->compat.cdw3;
	u->native.cdw2 = u->compat.cdw2;
	u->native.nsid = u->compat.nsid;
	u->native.rsvd1 = u->compat.rsvd1;
	u->native.flags = u->compat.flags;
	u->native.opcode = u->compat.opcode;
}
static __always_inline __maybe_unused void
__to_c64_nvme_passthru_cmd64(struct nvme_passthru_cmd64 *p)
{
	union {
		struct __c64_nvme_passthru_cmd64 compat;
		const struct nvme_passthru_cmd64 native;
	} *u = (void *)p;

	u->compat.opcode = u->native.opcode;
	u->compat.flags = u->native.flags;
	u->compat.rsvd1 = u->native.rsvd1;
	u->compat.nsid = u->native.nsid;
	u->compat.cdw2 = u->native.cdw2;
	u->compat.cdw3 = u->native.cdw3;
	u->compat.metadata = (__c64_ptr64 __force)u->native.metadata;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.metadata_len = u->native.metadata_len;
	u->compat.data_len = u->native.data_len;
	u->compat.vec_cnt = u->native.vec_cnt;
	u->compat.cdw10 = u->native.cdw10;
	u->compat.cdw11 = u->native.cdw11;
	u->compat.cdw12 = u->native.cdw12;
	u->compat.cdw13 = u->native.cdw13;
	u->compat.cdw14 = u->native.cdw14;
	u->compat.cdw15 = u->native.cdw15;
	u->compat.timeout_ms = u->native.timeout_ms;
	u->compat.rsvd2 = u->native.rsvd2;
	u->compat.result = u->native.result;
}
static __always_inline __maybe_unused void
__from_c64_nvme_passthru_cmd64_2(struct nvme_passthru_cmd64 *native, const struct __c64_nvme_passthru_cmd64 *compat)
{

	native->opcode = compat->opcode;
	native->flags = compat->flags;
	native->rsvd1 = compat->rsvd1;
	native->nsid = compat->nsid;
	native->cdw2 = compat->cdw2;
	native->cdw3 = compat->cdw3;
	native->metadata = (user_uintptr_t)compat_ptr(compat->metadata);
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->metadata_len = compat->metadata_len;
	native->data_len = compat->data_len;
	native->vec_cnt = compat->vec_cnt;
	native->cdw10 = compat->cdw10;
	native->cdw11 = compat->cdw11;
	native->cdw12 = compat->cdw12;
	native->cdw13 = compat->cdw13;
	native->cdw14 = compat->cdw14;
	native->cdw15 = compat->cdw15;
	native->timeout_ms = compat->timeout_ms;
	native->rsvd2 = compat->rsvd2;
	native->result = compat->result;
}
static __always_inline __maybe_unused void
__to_c64_nvme_passthru_cmd64_2(struct __c64_nvme_passthru_cmd64 *compat, const struct nvme_passthru_cmd64 *native)
{

	compat->opcode = native->opcode;
	compat->flags = native->flags;
	compat->rsvd1 = native->rsvd1;
	compat->nsid = native->nsid;
	compat->cdw2 = native->cdw2;
	compat->cdw3 = native->cdw3;
	compat->metadata = (__c64_ptr64 __force)native->metadata;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->metadata_len = native->metadata_len;
	compat->data_len = native->data_len;
	compat->vec_cnt = native->vec_cnt;
	compat->cdw10 = native->cdw10;
	compat->cdw11 = native->cdw11;
	compat->cdw12 = native->cdw12;
	compat->cdw13 = native->cdw13;
	compat->cdw14 = native->cdw14;
	compat->cdw15 = native->cdw15;
	compat->timeout_ms = native->timeout_ms;
	compat->rsvd2 = native->rsvd2;
	compat->result = native->result;
}
struct __c64_nvme_uring_cmd {
	__u8	opcode;
	__u8	flags;
	__u16	rsvd1;
	__u32	nsid;
	__u32	cdw2;
	__u32	cdw3;
	__c64_ptr64	metadata;
	__c64_ptr64	addr;
	__u32	metadata_len;
	__u32	data_len;
	__u32	cdw10;
	__u32	cdw11;
	__u32	cdw12;
	__u32	cdw13;
	__u32	cdw14;
	__u32	cdw15;
	__u32	timeout_ms;
	__u32   rsvd2;
};

static __always_inline __maybe_unused void
__from_c64_nvme_uring_cmd(struct nvme_uring_cmd *p)
{
	union {
		struct nvme_uring_cmd native;
		const struct __c64_nvme_uring_cmd compat;
	} *u = (void *)p;

	u->native.rsvd2 = u->compat.rsvd2;
	u->native.timeout_ms = u->compat.timeout_ms;
	u->native.cdw15 = u->compat.cdw15;
	u->native.cdw14 = u->compat.cdw14;
	u->native.cdw13 = u->compat.cdw13;
	u->native.cdw12 = u->compat.cdw12;
	u->native.cdw11 = u->compat.cdw11;
	u->native.cdw10 = u->compat.cdw10;
	u->native.data_len = u->compat.data_len;
	u->native.metadata_len = u->compat.metadata_len;
	u->native.addr = (user_uintptr_t)compat_ptr(u->compat.addr);
	u->native.metadata = (user_uintptr_t)compat_ptr(u->compat.metadata);
	u->native.cdw3 = u->compat.cdw3;
	u->native.cdw2 = u->compat.cdw2;
	u->native.nsid = u->compat.nsid;
	u->native.rsvd1 = u->compat.rsvd1;
	u->native.flags = u->compat.flags;
	u->native.opcode = u->compat.opcode;
}
static __always_inline __maybe_unused void
__to_c64_nvme_uring_cmd(struct nvme_uring_cmd *p)
{
	union {
		struct __c64_nvme_uring_cmd compat;
		const struct nvme_uring_cmd native;
	} *u = (void *)p;

	u->compat.opcode = u->native.opcode;
	u->compat.flags = u->native.flags;
	u->compat.rsvd1 = u->native.rsvd1;
	u->compat.nsid = u->native.nsid;
	u->compat.cdw2 = u->native.cdw2;
	u->compat.cdw3 = u->native.cdw3;
	u->compat.metadata = (__c64_ptr64 __force)u->native.metadata;
	u->compat.addr = (__c64_ptr64 __force)u->native.addr;
	u->compat.metadata_len = u->native.metadata_len;
	u->compat.data_len = u->native.data_len;
	u->compat.cdw10 = u->native.cdw10;
	u->compat.cdw11 = u->native.cdw11;
	u->compat.cdw12 = u->native.cdw12;
	u->compat.cdw13 = u->native.cdw13;
	u->compat.cdw14 = u->native.cdw14;
	u->compat.cdw15 = u->native.cdw15;
	u->compat.timeout_ms = u->native.timeout_ms;
	u->compat.rsvd2 = u->native.rsvd2;
}
static __always_inline __maybe_unused void
__from_c64_nvme_uring_cmd_2(struct nvme_uring_cmd *native, const struct __c64_nvme_uring_cmd *compat)
{

	native->opcode = compat->opcode;
	native->flags = compat->flags;
	native->rsvd1 = compat->rsvd1;
	native->nsid = compat->nsid;
	native->cdw2 = compat->cdw2;
	native->cdw3 = compat->cdw3;
	native->metadata = (user_uintptr_t)compat_ptr(compat->metadata);
	native->addr = (user_uintptr_t)compat_ptr(compat->addr);
	native->metadata_len = compat->metadata_len;
	native->data_len = compat->data_len;
	native->cdw10 = compat->cdw10;
	native->cdw11 = compat->cdw11;
	native->cdw12 = compat->cdw12;
	native->cdw13 = compat->cdw13;
	native->cdw14 = compat->cdw14;
	native->cdw15 = compat->cdw15;
	native->timeout_ms = compat->timeout_ms;
	native->rsvd2 = compat->rsvd2;
}
static __always_inline __maybe_unused void
__to_c64_nvme_uring_cmd_2(struct __c64_nvme_uring_cmd *compat, const struct nvme_uring_cmd *native)
{

	compat->opcode = native->opcode;
	compat->flags = native->flags;
	compat->rsvd1 = native->rsvd1;
	compat->nsid = native->nsid;
	compat->cdw2 = native->cdw2;
	compat->cdw3 = native->cdw3;
	compat->metadata = (__c64_ptr64 __force)native->metadata;
	compat->addr = (__c64_ptr64 __force)native->addr;
	compat->metadata_len = native->metadata_len;
	compat->data_len = native->data_len;
	compat->cdw10 = native->cdw10;
	compat->cdw11 = native->cdw11;
	compat->cdw12 = native->cdw12;
	compat->cdw13 = native->cdw13;
	compat->cdw14 = native->cdw14;
	compat->cdw15 = native->cdw15;
	compat->timeout_ms = native->timeout_ms;
	compat->rsvd2 = native->rsvd2;
}
