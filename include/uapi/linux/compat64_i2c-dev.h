#pragma once


#include <linux/compat.h>


struct __c64_i2c_smbus_ioctl_data {
	__u8 read_write;
	__u8 command;
	__u32 size;
	__c64_uptr data;
};

static __always_inline __maybe_unused void
__from_c64_i2c_smbus_ioctl_data(struct i2c_smbus_ioctl_data *p)
{
	union {
		struct i2c_smbus_ioctl_data native;
		const struct __c64_i2c_smbus_ioctl_data compat;
	} *u = (void *)p;

	u->native.data =  compat_ptr(u->compat.data);
	u->native.size = u->compat.size;
	u->native.command = u->compat.command;
	u->native.read_write = u->compat.read_write;
}
static __always_inline __maybe_unused void
__to_c64_i2c_smbus_ioctl_data(struct i2c_smbus_ioctl_data *p)
{
	union {
		struct __c64_i2c_smbus_ioctl_data compat;
		const struct i2c_smbus_ioctl_data native;
	} *u = (void *)p;

	u->compat.read_write = u->native.read_write;
	u->compat.command = u->native.command;
	u->compat.size = u->native.size;
	u->compat.data =  (__c64_uptr __force)(user_uintptr_t)u->native.data;
}
static __always_inline __maybe_unused void
__from_c64_i2c_smbus_ioctl_data_2(struct i2c_smbus_ioctl_data *native, const struct __c64_i2c_smbus_ioctl_data *compat)
{

	native->read_write = compat->read_write;
	native->command = compat->command;
	native->size = compat->size;
	native->data =  compat_ptr(compat->data);
}
static __always_inline __maybe_unused void
__to_c64_i2c_smbus_ioctl_data_2(struct __c64_i2c_smbus_ioctl_data *compat, const struct i2c_smbus_ioctl_data *native)
{

	compat->read_write = native->read_write;
	compat->command = native->command;
	compat->size = native->size;
	compat->data =  (__c64_uptr __force)(user_uintptr_t)native->data;
}
struct __c64_i2c_rdwr_ioctl_data {
	__c64_uptr msgs;	/* pointers to i2c_msgs */
	__u32 nmsgs;			/* number of i2c_msgs */
};

static __always_inline __maybe_unused void
__from_c64_i2c_rdwr_ioctl_data(struct i2c_rdwr_ioctl_data *p)
{
	union {
		struct i2c_rdwr_ioctl_data native;
		const struct __c64_i2c_rdwr_ioctl_data compat;
	} *u = (void *)p;

	u->native.nmsgs = u->compat.nmsgs;
	u->native.msgs =  compat_ptr(u->compat.msgs);
}
static __always_inline __maybe_unused void
__to_c64_i2c_rdwr_ioctl_data(struct i2c_rdwr_ioctl_data *p)
{
	union {
		struct __c64_i2c_rdwr_ioctl_data compat;
		const struct i2c_rdwr_ioctl_data native;
	} *u = (void *)p;

	u->compat.msgs =  (__c64_uptr __force)(user_uintptr_t)u->native.msgs;
	u->compat.nmsgs = u->native.nmsgs;
}
static __always_inline __maybe_unused void
__from_c64_i2c_rdwr_ioctl_data_2(struct i2c_rdwr_ioctl_data *native, const struct __c64_i2c_rdwr_ioctl_data *compat)
{

	native->msgs =  compat_ptr(compat->msgs);
	native->nmsgs = compat->nmsgs;
}
static __always_inline __maybe_unused void
__to_c64_i2c_rdwr_ioctl_data_2(struct __c64_i2c_rdwr_ioctl_data *compat, const struct i2c_rdwr_ioctl_data *native)
{

	compat->msgs =  (__c64_uptr __force)(user_uintptr_t)native->msgs;
	compat->nmsgs = native->nmsgs;
}
