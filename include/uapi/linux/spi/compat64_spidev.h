#pragma once


#include <linux/compat.h>


struct __c64_spi_ioc_transfer {
	__c64_ptr64	tx_buf;
	__c64_ptr64	rx_buf;

	__u32		len;
	__u32		speed_hz;

	__u16		delay_usecs;
	__u8		bits_per_word;
	__u8		cs_change;
	__u8		tx_nbits;
	__u8		rx_nbits;
	__u8		word_delay_usecs;
	__u8		pad;

	/* If the contents of 'struct spi_ioc_transfer' ever change
	 * incompatibly, then the ioctl number (currently 0) must change;
	 * ioctls with constant size fields get a bit more in the way of
	 * error checking than ones (like this) where that field varies.
	 *
	 * NOTE: struct layout is the same in 64bit and 32bit userspace.
	 */
};

static __always_inline __maybe_unused void
__from_c64_spi_ioc_transfer(struct spi_ioc_transfer *p)
{
	union {
		struct spi_ioc_transfer native;
		const struct __c64_spi_ioc_transfer compat;
	} *u = (void *)p;

	u->native.pad = u->compat.pad;
	u->native.word_delay_usecs = u->compat.word_delay_usecs;
	u->native.rx_nbits = u->compat.rx_nbits;
	u->native.tx_nbits = u->compat.tx_nbits;
	u->native.cs_change = u->compat.cs_change;
	u->native.bits_per_word = u->compat.bits_per_word;
	u->native.delay_usecs = u->compat.delay_usecs;
	u->native.speed_hz = u->compat.speed_hz;
	u->native.len = u->compat.len;
	u->native.rx_buf = (user_uintptr_t)compat_ptr(u->compat.rx_buf);
	u->native.tx_buf = (user_uintptr_t)compat_ptr(u->compat.tx_buf);
}
static __always_inline __maybe_unused void
__to_c64_spi_ioc_transfer(struct spi_ioc_transfer *p)
{
	union {
		struct __c64_spi_ioc_transfer compat;
		const struct spi_ioc_transfer native;
	} *u = (void *)p;

	u->compat.tx_buf = (__c64_ptr64 __force)u->native.tx_buf;
	u->compat.rx_buf = (__c64_ptr64 __force)u->native.rx_buf;
	u->compat.len = u->native.len;
	u->compat.speed_hz = u->native.speed_hz;
	u->compat.delay_usecs = u->native.delay_usecs;
	u->compat.bits_per_word = u->native.bits_per_word;
	u->compat.cs_change = u->native.cs_change;
	u->compat.tx_nbits = u->native.tx_nbits;
	u->compat.rx_nbits = u->native.rx_nbits;
	u->compat.word_delay_usecs = u->native.word_delay_usecs;
	u->compat.pad = u->native.pad;
}
static __always_inline __maybe_unused void
__from_c64_spi_ioc_transfer_2(struct spi_ioc_transfer *native, const struct __c64_spi_ioc_transfer *compat)
{

	native->tx_buf = (user_uintptr_t)compat_ptr(compat->tx_buf);
	native->rx_buf = (user_uintptr_t)compat_ptr(compat->rx_buf);
	native->len = compat->len;
	native->speed_hz = compat->speed_hz;
	native->delay_usecs = compat->delay_usecs;
	native->bits_per_word = compat->bits_per_word;
	native->cs_change = compat->cs_change;
	native->tx_nbits = compat->tx_nbits;
	native->rx_nbits = compat->rx_nbits;
	native->word_delay_usecs = compat->word_delay_usecs;
	native->pad = compat->pad;
}
static __always_inline __maybe_unused void
__to_c64_spi_ioc_transfer_2(struct __c64_spi_ioc_transfer *compat, const struct spi_ioc_transfer *native)
{

	compat->tx_buf = (__c64_ptr64 __force)native->tx_buf;
	compat->rx_buf = (__c64_ptr64 __force)native->rx_buf;
	compat->len = native->len;
	compat->speed_hz = native->speed_hz;
	compat->delay_usecs = native->delay_usecs;
	compat->bits_per_word = native->bits_per_word;
	compat->cs_change = native->cs_change;
	compat->tx_nbits = native->tx_nbits;
	compat->rx_nbits = native->rx_nbits;
	compat->word_delay_usecs = native->word_delay_usecs;
	compat->pad = native->pad;
}
