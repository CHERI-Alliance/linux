// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2021  Arm Limited

#include <cheriintrin.h>
#include <stdint.h>

#include <asm/unistd.h>
#include <linux/auxvec.h>

#include "freestanding.h"


#define MMAP_PERMS (CHERI_PERM_LOAD | CHERI_PERM_STORE |		\
	CHERI_PERM_LOAD_CAP | CHERI_PERM_STORE_CAP |			\
	ARM_CAP_PERMISSION_MUTABLE_LOAD | CHERI_PERM_STORE_LOCAL_CAP |	\
	CHERI_PERM_GLOBAL)
#define STACK_PERMS MMAP_PERMS
#define STRING_PERMS (CHERI_PERM_LOAD | CHERI_PERM_STORE)

/* macro so we get a more informative __LINE__ */
#define VERIFY_CAP(cap, size, req_perms, what)\
	do { \
		int tag = cheri_tag_get(cap); \
		ptraddr_t base = cheri_base_get(cap); \
		size_t length = cheri_length_get(cap); \
		ptraddr_t address = cheri_address_get(cap); \
		size_t perms = cheri_perms_get(cap); \
		ASSERT_TRUE(tag) \
			TH_LOG("tag of capability in %s not set", what); \
		ASSERT_LE(base, address) TH_LOG("base is bad"); \
		ASSERT_LE(address + size, base + length) \
			TH_LOG("bad bounds in %s", what); \
		ASSERT_EQ(perms & req_perms, req_perms) \
			TH_LOG("%s doesn't have required permissions", what); \
	} while (0)

#define ASSERT_CAP_EQ(exp, seen) \
	ASSERT_TRUE(__builtin_cheri_equal_exact(exp, seen))

struct morello_auxv {
	long a_type;
	long _padding;
	uintcap_t a_val;
};

struct initial_data {
	int argc;
	char **argv;
	char **envp;
	struct morello_auxv *auxv;
};

static struct initial_data reg_data;

int clear_child_tid;

void verify_string(char *str)
{
	size_t max_len = cheri_length_get(str) - cheri_offset_get(str);
	int str_term = 0;

	/* length check doesn't matter as we do a better one later anyway */
	VERIFY_CAP(str, max_len, STRING_PERMS, "string");

	for (size_t i = 0; i < max_len; i++) {
		if (str[i] == '\0') {
			str_term = 1;
			break;
		}
	}

	ASSERT_TRUE(str_term) TH_LOG("string doesn't fit in bounds");
}

int verify_auxval(struct morello_auxv *auxv)
{
	ASSERT_FALSE(auxv->_padding) TH_LOG("auxv padding not zero");

	switch (auxv->a_type) {
	case AT_NULL:
		return 0;
	case AT_CHERI_EXEC_RW_CAP:
	case AT_CHERI_INTERP_RW_CAP:
	case AT_CHERI_INTERP_RX_CAP:
	case AT_BASE:
		/* Fall through if not null, abi allows it */
		if ((void *)auxv->a_val == NULL)
			break;
	case AT_ENTRY:
	case AT_EXECFN:
	case AT_PLATFORM:
	case AT_RANDOM:
	case AT_PHDR:
	case AT_CHERI_EXEC_RX_CAP:
	case AT_CHERI_STACK_CAP:
	case AT_CHERI_SEAL_CAP:
	case AT_CHERI_CID_CAP:
	case AT_ARGV:
	case AT_ENVP:
		/* valid and unsealed */
		ASSERT_TRUE(cheri_tag_get(auxv->a_val))
			TH_LOG("auxv (%ld) value is invalid", auxv->a_type);
		ASSERT_FALSE(cheri_type_get(auxv->a_val)) {
			TH_LOG("auxv (%ld) value is sealed", auxv->a_type);
		}
		break;
	default:
		/* "null capability with its address set to the usual value" */
		ASSERT_CAP_EQ(
			cheri_address_set(NULL, cheri_address_get(auxv->a_val)),
			auxv->a_val
		) TH_LOG("auxv (%ld) non cap val isn't zeroed", auxv->a_type);
		break;
	}

	return 1;
}

TEST(test_write)
{
	char msg[] = "write() test message\n";
	ssize_t ret;

	/* don't ASSERT to avoid triggering the harness (and printf) */
	/* as failure reporting cannot happen with write() if it fails */
	ret = write(1, msg, sizeof(msg));
	/* write() failed, exit with a weird error code to give a clue */
	if (ret != sizeof(msg))
		exit(3);
}

/*
 * C64/A64 transitions can happen at any time and we can't detect those. This
 * will only catch major issues and not subtle errors (eg incorrectly declared
 * assembly subroutine)
 */
TEST(test_c64)
{
	uintcap_t cap;

	asm volatile("mov %0, c30" : "=C"(cap));
	/* LSB is set on LR if we came from C64 */
	ASSERT_TRUE(cap & 0x1) TH_LOG("we did not come from C64");

	/* will write to Cn register in C64 and Xn in A64, clearing the tag */
	asm volatile("adr %0, #0" : "=C"(cap));
	ASSERT_TRUE(cheri_tag_get(cap)) TH_LOG("not running in C64");
}

TEST(test_stack)
{
	/* copy the pointer so we can modify it */
	char **stack = stack_from_kernel;
	int argc_stack;
	/* start with an argc check */
	VERIFY_CAP(stack, sizeof(void *), STACK_PERMS, "argc");

	/* dereference and go past argc */
	argc_stack = *(int *)stack;
	ASSERT_EQ(argc_stack, reg_data.argc);
	stack += 1;

	/* argv + null */
	VERIFY_CAP(stack, sizeof(void *) * (argc_stack + 1), STACK_PERMS, "argv_stack");
	ASSERT_CAP_EQ(reg_data.argv, stack);

	/* we are clear to dereference all argv */
	for (int i = 0; i < argc_stack; i++) {
		char *arg = *(stack + i);
		verify_string(arg);
	}

	/* go past argv */
	stack += argc_stack;
	ASSERT_NULL(*stack) TH_LOG("argv was not null terminated on stack");
	/* go past the null terminator */
	stack += 1;

	/* progressively check bounds for envp and dereference */
	ASSERT_CAP_EQ(reg_data.envp, stack);
	while (1) {
		char *envp_stack = *stack;

		VERIFY_CAP(stack, sizeof(void *), STACK_PERMS, "envp");
		stack += 1;
		if (envp_stack == NULL)
			break;
		verify_string(envp_stack);
	}

	/* finally, go through auxv */
	ASSERT_CAP_EQ(reg_data.auxv, stack);
	while (1) {
		struct morello_auxv *auxv_stack = ((struct morello_auxv *) stack);

		VERIFY_CAP(auxv_stack, sizeof(struct morello_auxv), STACK_PERMS, "auxv");
		if (verify_auxval(auxv_stack) == 0)
			break;
		stack += 2;
	}
}

/* this only runs the syscalls, actual test is with clone() */
TEST(test_set_tid_address_initial)
{
	/* these never fail, safe to call unless kernel is very wrong */
	pid_t tid = syscall(__NR_gettid);
	long ret = syscall(__NR_set_tid_address, &clear_child_tid);
	ASSERT_EQ(tid, ret) TH_LOG("tid was different");
}

/*
 * These tests are the second part of the bootstrap test suite, right after the
 * exit test. We assume exit() works and we progressively build a known working
 * test environment.
 */
int main(int argc, char **argv, char **envp, struct morello_auxv *auxv)
{
	reg_data.argc = argc;
	reg_data.argv = argv;
	reg_data.envp = envp;
	reg_data.auxv = auxv;

	test_write();
	/* from now on write and exit work, so go wild */
	test_c64();
	test_stack();
	/* stack is good, use it so we don't overflow the temp one */
	install_kernel_stack();
	test_set_tid_address_initial();

	return 0;
}
