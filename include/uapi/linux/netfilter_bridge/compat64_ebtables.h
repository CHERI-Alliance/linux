#pragma once


#include <linux/compat.h>


struct __c64_ebt_replace {
	char name[EBT_TABLE_MAXNAMELEN];
	unsigned int valid_hooks;
	/* nr of rules in the table */
	unsigned int nentries;
	/* total size of the entries */
	unsigned int entries_size;
	/* start of the chains */
	__c64_uptr hook_entry[NF_BR_NUMHOOKS];
	/* nr of counters userspace expects back */
	unsigned int num_counters;
	/* where the kernel will put the old counters */
	__c64_uptr counters;
	__c64_uptr entries;
};

static __always_inline __maybe_unused void
__from_c64_ebt_replace(struct ebt_replace *p)
{
	union {
		struct ebt_replace native;
		const struct __c64_ebt_replace compat;
	} *u = (void *)p;
	unsigned long i;

	u->native.entries =  compat_ptr(u->compat.entries);
	u->native.counters =  compat_ptr(u->compat.counters);
	u->native.num_counters = u->compat.num_counters;
	BUILD_BUG_ON(ARRAY_SIZE(u->compat.hook_entry) != ARRAY_SIZE(u->native.hook_entry));
	for (i = 0; i < ARRAY_SIZE(u->native.hook_entry); ++i)
		u->native.hook_entry[i] =  compat_ptr(u->compat.hook_entry[i]);
	u->native.entries_size = u->compat.entries_size;
	u->native.nentries = u->compat.nentries;
	u->native.valid_hooks = u->compat.valid_hooks;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_ebt_replace(struct ebt_replace *p)
{
	union {
		struct __c64_ebt_replace compat;
		const struct ebt_replace native;
	} *u = (void *)p;
	unsigned long i;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.valid_hooks = u->native.valid_hooks;
	u->compat.nentries = u->native.nentries;
	u->compat.entries_size = u->native.entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(u->native.hook_entry) != ARRAY_SIZE(u->compat.hook_entry));
	for (i = ARRAY_SIZE(u->compat.hook_entry); i--; )
		u->compat.hook_entry[i] =  (__c64_uptr __force)(user_uintptr_t)u->native.hook_entry[i];
	u->compat.num_counters = u->native.num_counters;
	u->compat.counters =  (__c64_uptr __force)(user_uintptr_t)u->native.counters;
	u->compat.entries =  (__c64_uptr __force)(user_uintptr_t)u->native.entries;
}
static __always_inline __maybe_unused void
__from_c64_ebt_replace_2(struct ebt_replace *native, const struct __c64_ebt_replace *compat)
{
	unsigned long i;

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->valid_hooks = compat->valid_hooks;
	native->nentries = compat->nentries;
	native->entries_size = compat->entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(compat->hook_entry) != ARRAY_SIZE(native->hook_entry));
	for (i = ARRAY_SIZE(native->hook_entry); i--; )
		native->hook_entry[i] =  compat_ptr(compat->hook_entry[i]);
	native->num_counters = compat->num_counters;
	native->counters =  compat_ptr(compat->counters);
	native->entries =  compat_ptr(compat->entries);
}
static __always_inline __maybe_unused void
__to_c64_ebt_replace_2(struct __c64_ebt_replace *compat, const struct ebt_replace *native)
{
	unsigned long i;

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->valid_hooks = native->valid_hooks;
	compat->nentries = native->nentries;
	compat->entries_size = native->entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(native->hook_entry) != ARRAY_SIZE(compat->hook_entry));
	for (i = ARRAY_SIZE(compat->hook_entry); i--; )
		compat->hook_entry[i] =  (__c64_uptr __force)(user_uintptr_t)native->hook_entry[i];
	compat->num_counters = native->num_counters;
	compat->counters =  (__c64_uptr __force)(user_uintptr_t)native->counters;
	compat->entries =  (__c64_uptr __force)(user_uintptr_t)native->entries;
}
struct __c64_ebt_replace_kernel {
	char name[EBT_TABLE_MAXNAMELEN];
	unsigned int valid_hooks;
	/* nr of rules in the table */
	unsigned int nentries;
	/* total size of the entries */
	unsigned int entries_size;
	/* start of the chains */
	__c64_uptr hook_entry[NF_BR_NUMHOOKS];
	/* nr of counters userspace expects back */
	unsigned int num_counters;
	/* where the kernel will put the old counters */
	__c64_uptr counters;
	__c64_uptr entries;
};

static __always_inline __maybe_unused void
__from_c64_ebt_replace_kernel(struct ebt_replace_kernel *p)
{
	union {
		struct ebt_replace_kernel native;
		const struct __c64_ebt_replace_kernel compat;
	} *u = (void *)p;
	unsigned long i;

	u->native.entries =  compat_ptr(u->compat.entries);
	u->native.counters =  compat_ptr(u->compat.counters);
	u->native.num_counters = u->compat.num_counters;
	BUILD_BUG_ON(ARRAY_SIZE(u->compat.hook_entry) != ARRAY_SIZE(u->native.hook_entry));
	for (i = 0; i < ARRAY_SIZE(u->native.hook_entry); ++i)
		u->native.hook_entry[i] =  compat_ptr(u->compat.hook_entry[i]);
	u->native.entries_size = u->compat.entries_size;
	u->native.nentries = u->compat.nentries;
	u->native.valid_hooks = u->compat.valid_hooks;
	BUILD_BUG_ON(sizeof(u->compat.name) != sizeof(u->native.name));
	memmove(&u->native.name, &u->compat.name, sizeof(u->native.name));
}
static __always_inline __maybe_unused void
__to_c64_ebt_replace_kernel(struct ebt_replace_kernel *p)
{
	union {
		struct __c64_ebt_replace_kernel compat;
		const struct ebt_replace_kernel native;
	} *u = (void *)p;
	unsigned long i;

	BUILD_BUG_ON(sizeof(u->native.name) != sizeof(u->compat.name));
	memmove(&u->compat.name, &u->native.name, sizeof(u->compat.name));
	u->compat.valid_hooks = u->native.valid_hooks;
	u->compat.nentries = u->native.nentries;
	u->compat.entries_size = u->native.entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(u->native.hook_entry) != ARRAY_SIZE(u->compat.hook_entry));
	for (i = ARRAY_SIZE(u->compat.hook_entry); i--; )
		u->compat.hook_entry[i] =  (__c64_uptr __force)(user_uintptr_t)u->native.hook_entry[i];
	u->compat.num_counters = u->native.num_counters;
	u->compat.counters =  (__c64_uptr __force)(user_uintptr_t)u->native.counters;
	u->compat.entries =  (__c64_uptr __force)(user_uintptr_t)u->native.entries;
}
static __always_inline __maybe_unused void
__from_c64_ebt_replace_kernel_2(struct ebt_replace_kernel *native, const struct __c64_ebt_replace_kernel *compat)
{
	unsigned long i;

	BUILD_BUG_ON(sizeof(compat->name) != sizeof(native->name));
	memcpy(&native->name, &compat->name, sizeof(native->name));
	native->valid_hooks = compat->valid_hooks;
	native->nentries = compat->nentries;
	native->entries_size = compat->entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(compat->hook_entry) != ARRAY_SIZE(native->hook_entry));
	for (i = ARRAY_SIZE(native->hook_entry); i--; )
		native->hook_entry[i] =  compat_ptr(compat->hook_entry[i]);
	native->num_counters = compat->num_counters;
	native->counters =  compat_ptr(compat->counters);
	native->entries =  compat_ptr(compat->entries);
}
static __always_inline __maybe_unused void
__to_c64_ebt_replace_kernel_2(struct __c64_ebt_replace_kernel *compat, const struct ebt_replace_kernel *native)
{
	unsigned long i;

	BUILD_BUG_ON(sizeof(native->name) != sizeof(compat->name));
	memcpy(&compat->name, &native->name, sizeof(compat->name));
	compat->valid_hooks = native->valid_hooks;
	compat->nentries = native->nentries;
	compat->entries_size = native->entries_size;
	BUILD_BUG_ON(ARRAY_SIZE(native->hook_entry) != ARRAY_SIZE(compat->hook_entry));
	for (i = ARRAY_SIZE(compat->hook_entry); i--; )
		compat->hook_entry[i] =  (__c64_uptr __force)(user_uintptr_t)native->hook_entry[i];
	compat->num_counters = native->num_counters;
	compat->counters =  (__c64_uptr __force)(user_uintptr_t)native->counters;
	compat->entries =  (__c64_uptr __force)(user_uintptr_t)native->entries;
}
struct __c64_ebt_entries {
	/* this field is always set to zero
	 * See EBT_ENTRY_OR_ENTRIES.
	 * Must be same size as ebt_entry.bitmask */
	unsigned int distinguisher;
	/* the chain name */
	char name[EBT_CHAIN_MAXNAMELEN];
	/* counter offset for this chain */
	unsigned int counter_offset;
	/* one standard (accept, drop, return) per hook */
	int policy;
	/* nr. of entries */
	unsigned int nentries;
	/* entry list */
	char data[] __attribute__ ((aligned (__alignof__(struct __c64_ebt_replace))));
};

struct __c64_ebt_entry_match {
	union {
		struct {
			char name[EBT_EXTENSION_MAXNAMELEN];
			__u8 revision;
		};
		union {
			/// UAPI: NoConvert: Kernel only
			__c64_uptr match;
			/// UAPI: NoConvert: Kernel only
			__c64_uptr __match;
		};
	} u;
	/* size of data */
	unsigned int match_size;
	unsigned char data[] __attribute__ ((aligned (__alignof__(struct __c64_ebt_replace))));
};

struct __c64_ebt_entry_watcher {
	union {
		struct {
			char name[EBT_EXTENSION_MAXNAMELEN];
			__u8 revision;
		};
		union {
			/// UAPI: NoConvert: Kernel only
			__c64_uptr watcher;
			/// UAPI: NoConvert: Kernel only
			__c64_uptr __watcher;
		};
	} u;
	/* size of data */
	unsigned int watcher_size;
	unsigned char data[] __attribute__ ((aligned (__alignof__(struct __c64_ebt_replace))));
};

struct __c64_ebt_entry_target {
	union {
		struct {
			char name[EBT_EXTENSION_MAXNAMELEN];
			__u8 revision;
		};
		union {
			/// UAPI: NoConvert: Kernel only
			__c64_uptr target;
			/// UAPI: NoConvert: Kernel only
			__c64_uptr __target;
		};
	} u;
	/* size of data */
	unsigned int target_size;
	unsigned char data[0] __attribute__ ((aligned (__alignof__(struct __c64_ebt_replace))));
};

struct __c64_ebt_standard_target {
	struct __c64_ebt_entry_target target;
	int verdict;
};

struct __c64_ebt_entry {
	/* this needs to be the first field */
	unsigned int bitmask;
	unsigned int invflags;
	__be16 ethproto;
	/* the physical in-dev */
	char in[IFNAMSIZ];
	/* the logical in-dev */
	char logical_in[IFNAMSIZ];
	/* the physical out-dev */
	char out[IFNAMSIZ];
	/* the logical out-dev */
	char logical_out[IFNAMSIZ];
	unsigned char sourcemac[ETH_ALEN];
	unsigned char sourcemsk[ETH_ALEN];
	unsigned char destmac[ETH_ALEN];
	unsigned char destmsk[ETH_ALEN];
	__struct_group(/* no tag */, offsets, /* no attrs */,
		/* sizeof ebt_entry + matches */
		unsigned int watchers_offset;
		/* sizeof ebt_entry + matches + watchers */
		unsigned int target_offset;
		/* sizeof ebt_entry + matches + watchers + target */
		unsigned int next_offset;
	);
	unsigned char elems[] __attribute__ ((aligned (__alignof__(struct __c64_ebt_replace))));
};

