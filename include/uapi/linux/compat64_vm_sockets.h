#pragma once


#include <linux/compat.h>


struct __c64_sockaddr_vm {
	__kernel_sa_family_t svm_family;
	unsigned short svm_reserved1;
	unsigned int svm_port;
	unsigned int svm_cid;
	__u8 svm_flags;
	unsigned char svm_zero[sizeof(struct sockaddr) -
			       sizeof(sa_family_t) -
			       sizeof(unsigned short) -
			       sizeof(unsigned int) -
			       sizeof(unsigned int) -
			       sizeof(__u8)];
};

static __always_inline __maybe_unused void
__from_c64_sockaddr_vm(struct sockaddr_vm *p)
{
	union {
		struct sockaddr_vm native;
		const struct __c64_sockaddr_vm compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.svm_zero) != sizeof(u->native.svm_zero));
	memmove(&u->native.svm_zero, &u->compat.svm_zero, sizeof(u->native.svm_zero));
	u->native.svm_flags = u->compat.svm_flags;
	u->native.svm_cid = u->compat.svm_cid;
	u->native.svm_port = u->compat.svm_port;
	u->native.svm_reserved1 = u->compat.svm_reserved1;
	u->native.svm_family = u->compat.svm_family;
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_vm(struct sockaddr_vm *p)
{
	union {
		struct __c64_sockaddr_vm compat;
		const struct sockaddr_vm native;
	} *u = (void *)p;

	u->compat.svm_family = u->native.svm_family;
	u->compat.svm_reserved1 = u->native.svm_reserved1;
	u->compat.svm_port = u->native.svm_port;
	u->compat.svm_cid = u->native.svm_cid;
	u->compat.svm_flags = u->native.svm_flags;
	BUILD_BUG_ON(sizeof(u->native.svm_zero) != sizeof(u->compat.svm_zero));
	memmove(&u->compat.svm_zero, &u->native.svm_zero, sizeof(u->compat.svm_zero));
}
static __always_inline __maybe_unused void
__from_c64_sockaddr_vm_2(struct sockaddr_vm *native, const struct __c64_sockaddr_vm *compat)
{

	native->svm_family = compat->svm_family;
	native->svm_reserved1 = compat->svm_reserved1;
	native->svm_port = compat->svm_port;
	native->svm_cid = compat->svm_cid;
	native->svm_flags = compat->svm_flags;
	BUILD_BUG_ON(sizeof(compat->svm_zero) != sizeof(native->svm_zero));
	memcpy(&native->svm_zero, &compat->svm_zero, sizeof(native->svm_zero));
}
static __always_inline __maybe_unused void
__to_c64_sockaddr_vm_2(struct __c64_sockaddr_vm *compat, const struct sockaddr_vm *native)
{

	compat->svm_family = native->svm_family;
	compat->svm_reserved1 = native->svm_reserved1;
	compat->svm_port = native->svm_port;
	compat->svm_cid = native->svm_cid;
	compat->svm_flags = native->svm_flags;
	BUILD_BUG_ON(sizeof(native->svm_zero) != sizeof(compat->svm_zero));
	memcpy(&compat->svm_zero, &native->svm_zero, sizeof(compat->svm_zero));
}
