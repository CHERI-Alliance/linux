#pragma once


struct __c64_io_uring_zcrx_area_reg {
	__c64_ptr64	addr;
	__u64	len;
	__u64	rq_area_token;
	__u32	flags;
	__u32	dmabuf_fd;
	__u64	__resv2[2];
};

