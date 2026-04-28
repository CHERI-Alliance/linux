/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2021  Arm Limited
 * Original author: Amit Daniel <amit.kachhap@arm.com>
 */

#include <asm/unistd.h>

.equ	OPEN_MASK,	0x42	/* O_RDWR|O_CREAT */
.equ	FILE_PERM,	0666	/* S_IRWU|S_IRWG|S_IRWO */
.data
.align 16
msg_write:
	.asciz "Pure cap binary\n" /* Length is MSG_LEN byte*/
.equ	MSG_LEN,	16

.align 16
msg_write_pass:
	.asciz "All Test Passed\n" /* Length is MSG_LEN byte*/
.equ	MSG_LEN_PASS,	16

.align 16
msg_write_err:
	.asciz "Test Failed\n" /* Length is MSG_LEN byte*/
.equ	MSG_LEN_ERR,	12

.align 16
msg_read:
	.asciz ""

.align 16
file:
	.asciz "/check_cap.txt"

.align 16
w_vec_msg1:
	.asciz "This message"	/* Each vector message length is 12 bytes */
.align 16
w_vec_msg2:
	.asciz " is vector\n"
.align 16
w_iovec:
	.quad	0, 0, 12, 0, 0, 0, 12, 0  /* struct iovec { void __user *iov_base;  __kernel_size_t iov_len; } = 128 + 128 byte */
.align 16
r_vec_msg1:
	.asciz ""
.align 16
r_vec_msg2:
	.asciz ""
.align 16
r_iovec:
	.quad	0, 0, 12, 0, 0, 0, 12, 0  /* struct iovec { void __user *iov_base;  __kernel_size_t iov_len; } = 128 + 128 byte */

.equ	VEC_MSG_NUM,	2
.equ	VEC_MSG_LEN,	12
.equ	VEC_MSG_BYTE,	24

.text
.macro syscall
	svc	#0
.endm

.macro halt
	b	.
.endm

.macro print_err_and_exit
	mov	x8, #__NR_write
	mov	x0, #0x1		/* 1=stdout */
	ldr	x1, =msg_write_err
	cvtd	c1, x1
	mov	x2, #MSG_LEN_ERR	/* Length of message */
	syscall
	mov	x8, #__NR_exit
	mov	x0, #0x1
	syscall
.endm

.macro print_pass_and_exit
	mov	x8, #__NR_write
	mov	x0, #0x1		/* 1=stdout */
	ldr	x1, =msg_write_pass
	cvtd	c1, x1
	mov	x2, #MSG_LEN_PASS	/* Length of message */
	syscall
	mov	x8, #__NR_exit
	mov	x0, #0x0
	syscall
.endm

.macro syscall_lseek
	mov	x8, #__NR_lseek
	mov	x0, x9			/* fd */
	mov	x1, 0			/* offset = 0 */
	mov	x2, 0			/* SEEK_SET*/
	syscall
.endm

.macro compare_buffer buf1 buf2 len
	/* Verify the read message */
	mov	x0, #\len
	ldr	x1, =\buf1
	cvtd	c1, x1
	ldr	x2, =\buf2
	cvtd	c2, x2
.Lcomp_buf_rep\@:
	ldrb	w3, [c1]
	ldrb	w4, [c2]
	cmp	w3, w4
	b.eq	.Lcomp_buf_cont\@
	print_err_and_exit
.Lcomp_buf_cont\@:
	add	c1, c1, #1
	add	c2, c2, #1
	sub	x0, x0, #1
	cbnz	x0, .Lcomp_buf_rep\@
.endm

.macro create_vec_data iovec buf1 buf2
	ldr	x1, =\iovec
	cvtd	c0, x1

	ldr     x2, =\buf1
	str	x2, [c0]

	ldr     x2, =\buf2
	str	x2, [c0, #32]
.endm

syscall_getpid:
	mov	x8, #__NR_getpid
	mov	x0, #0x0
	syscall
	ret	lr

syscall_exit:
	mov	x8, #__NR_exit
	mov	x0, #0x0
	syscall
	ret	lr

syscall_write:
	mov	x8, #__NR_write
	mov	x0, #0x1		/* 1=stdout */
	ldr	x1, =msg_write
	cvtd	c1, x1
	mov	x2, #MSG_LEN		/* Length of message */
	syscall
	cmp	x0, #MSG_LEN
	beq	1f
	halt
1:
	ret	lr

syscall_open:
	mov	x8, #__NR_openat
	mov	x0, #0x0
	ldr	x1, =file
	cvtd	c1, x1			/* Name of file */
	mov	x2, #OPEN_MASK		/* O_RDWR|O_CREAT */
	mov	x3, #FILE_PERM
	syscall
	cmp	x0, #0x0
	b.ge	1f
	print_err_and_exit
1:
	/* save the fd for later use in non-clobbered register */
	mov	x9, x0
	ret	lr

syscall_close:
	mov	x0, x9
	mov	x8, #__NR_close
	syscall
	cmp	x0, #0x0
	beq	1f
	print_err_and_exit
1:
	ret	lr

syscall_read:
	/* write some data to be read again */
	mov	x8, #__NR_write
	mov	x0, x9
	ldr	x1, =msg_write
	cvtd	c1, x1
	mov	x2, #MSG_LEN		/* Length of message */
	syscall
	cmp	x0, #MSG_LEN
	beq	1f
	print_err_and_exit
1:
	/* lseek file offset to 0 */
	syscall_lseek

	/* Read the data back and verify if they are same*/
	mov	x8, #__NR_read
	mov	x0, x9
	ldr	x1, =msg_read
	cvtd	c1, x1
	mov	x2, #MSG_LEN		/* Length of message */
	syscall
	cmp	x0, #MSG_LEN
	beq	2f
	print_err_and_exit
2:
	/* Verify the read message */
	compare_buffer msg_read msg_write MSG_LEN
	ret	lr


syscall_writev:
	mov	x8, #__NR_writev
	create_vec_data w_iovec w_vec_msg1 w_vec_msg2
	mov	c1, c0
	mov	x0, #0x1		/* 1=stdout */
	mov	x2, #VEC_MSG_NUM	/* Length of vector */
	syscall
	cmp	x0, #VEC_MSG_BYTE
	beq	1f
	print_err_and_exit
1:
	ret	lr

syscall_readv:
	/* lseek file offset to 0 */
	syscall_lseek

	mov	x8, #__NR_writev
	create_vec_data w_iovec w_vec_msg1 w_vec_msg2
	mov	c1, c0
	mov	x0, x9			/* x0 = fd */
	mov	x2, #VEC_MSG_NUM	/* Length of vector */
	syscall
	cmp	x0, #VEC_MSG_BYTE
	beq	1f
	print_err_and_exit
1:
	/* lseek file offset to 0 */
	syscall_lseek

	mov	x8, #__NR_readv
	create_vec_data r_iovec r_vec_msg1 r_vec_msg2
	mov	c1, c0
	mov	x0, x9			/* x0 = fd */
	mov	x2, #VEC_MSG_NUM	/* Length of vector */
	syscall
	cmp	x0, #VEC_MSG_BYTE
	beq	2f
	print_err_and_exit
2:
	/* Verify the read message */
	compare_buffer w_vec_msg1 r_vec_msg1 VEC_MSG_LEN
	compare_buffer w_vec_msg2 r_vec_msg2 VEC_MSG_LEN
	ret	lr


.globl _start
_start:
	/* Call getpid syscall */
	bl	syscall_getpid

	/* Call write syscall in stdout */
	bl	syscall_write

	/* Call writev syscall in stdout */
	bl	syscall_writev

	/* Call open syscall */
	bl	syscall_open

	/* Call read syscall */
	bl	syscall_read

	/* Call readv syscall */
	bl	syscall_readv

	/* Call close syscall */
	bl	syscall_close

	print_pass_and_exit

	/* Below code should be unreachable */
	halt
