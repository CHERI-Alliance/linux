#pragma once


struct __c64_iocb {
	/* these are internal to the kernel/libc. */
	__c64_ptr64	aio_data;	/* data to be returned in event's data */

#if defined(__BYTE_ORDER) ? __BYTE_ORDER == __LITTLE_ENDIAN : defined(__LITTLE_ENDIAN)
	__u32	aio_key;	/* the kernel sets aio_key to the req # */
	__kernel_rwf_t aio_rw_flags;	/* RWF_* flags */
#elif defined(__BYTE_ORDER) ? __BYTE_ORDER == __BIG_ENDIAN : defined(__BIG_ENDIAN)
	__kernel_rwf_t aio_rw_flags;	/* RWF_* flags */
	__u32	aio_key;	/* the kernel sets aio_key to the req # */
#else
#error edit for your odd byteorder.
#endif

	/* common fields */
	__u16	aio_lio_opcode;	/* see IOCB_CMD_ above */
	__s16	aio_reqprio;
	__u32	aio_fildes;

	__c64_ptr64	aio_buf;
	__u64	aio_nbytes;
	__s64	aio_offset;

	/* extra parameters */
	__u64	aio_reserved2;	/* TODO: use this for a (struct sigevent *) */

	/* flags for the "struct iocb" */
	__u32	aio_flags;

	/*
	 * if the IOCB_FLAG_RESFD flag of "aio_flags" is set, this is an
	 * eventfd to signal AIO readiness to
	 */
	__u32	aio_resfd;
};

