#pragma once


#include <linux/compat.h>


struct __c64_ppl_header {
	__u8 reserved[PPL_HDR_RESERVED];/* reserved space, fill with 0xff */
	__le32 signature;		/* signature (family number of volume) */
	__le32 padding;			/* zero pad */
	__le64 generation;		/* generation number of the header */
	__le32 entries_count;		/* number of entries in entry array */
	__le32 checksum;		/* checksum of the header (~crc32c) */
	struct ppl_header_entry entries[PPL_HDR_MAX_ENTRIES];
} __attribute__ ((__packed__));

static __always_inline __maybe_unused void
__from_c64_ppl_header(struct ppl_header *p)
{
	union {
		struct ppl_header native;
		const struct __c64_ppl_header compat;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->compat.entries) != sizeof(u->native.entries));
	memmove(&u->native.entries, &u->compat.entries, sizeof(u->native.entries));
	u->native.checksum = u->compat.checksum;
	u->native.entries_count = u->compat.entries_count;
	u->native.generation = u->compat.generation;
	u->native.padding = u->compat.padding;
	u->native.signature = u->compat.signature;
	BUILD_BUG_ON(sizeof(u->compat.reserved) != sizeof(u->native.reserved));
	memmove(&u->native.reserved, &u->compat.reserved, sizeof(u->native.reserved));
}
static __always_inline __maybe_unused void
__to_c64_ppl_header(struct ppl_header *p)
{
	union {
		struct __c64_ppl_header compat;
		const struct ppl_header native;
	} *u = (void *)p;

	BUILD_BUG_ON(sizeof(u->native.reserved) != sizeof(u->compat.reserved));
	memmove(&u->compat.reserved, &u->native.reserved, sizeof(u->compat.reserved));
	u->compat.signature = u->native.signature;
	u->compat.padding = u->native.padding;
	u->compat.generation = u->native.generation;
	u->compat.entries_count = u->native.entries_count;
	u->compat.checksum = u->native.checksum;
	BUILD_BUG_ON(sizeof(u->native.entries) != sizeof(u->compat.entries));
	memmove(&u->compat.entries, &u->native.entries, sizeof(u->compat.entries));
}
static __always_inline __maybe_unused void
__from_c64_ppl_header_2(struct ppl_header *native, const struct __c64_ppl_header *compat)
{

	BUILD_BUG_ON(sizeof(compat->reserved) != sizeof(native->reserved));
	memcpy(&native->reserved, &compat->reserved, sizeof(native->reserved));
	native->signature = compat->signature;
	native->padding = compat->padding;
	native->generation = compat->generation;
	native->entries_count = compat->entries_count;
	native->checksum = compat->checksum;
	BUILD_BUG_ON(sizeof(compat->entries) != sizeof(native->entries));
	memcpy(&native->entries, &compat->entries, sizeof(native->entries));
}
static __always_inline __maybe_unused void
__to_c64_ppl_header_2(struct __c64_ppl_header *compat, const struct ppl_header *native)
{

	BUILD_BUG_ON(sizeof(native->reserved) != sizeof(compat->reserved));
	memcpy(&compat->reserved, &native->reserved, sizeof(compat->reserved));
	compat->signature = native->signature;
	compat->padding = native->padding;
	compat->generation = native->generation;
	compat->entries_count = native->entries_count;
	compat->checksum = native->checksum;
	BUILD_BUG_ON(sizeof(native->entries) != sizeof(compat->entries));
	memcpy(&compat->entries, &native->entries, sizeof(compat->entries));
}
