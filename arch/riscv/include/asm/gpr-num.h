/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ASM_GPR_NUM_H
#define __ASM_GPR_NUM_H

#define __ALL_GPR_NUMS 		\
	__ONE_GPR_NUM(zero, 0)	\
	__ONE_GPR_NUM(cnull, 0)	\
	__ONE_GPR_NUM(ra, 1)	\
	__ONE_GPR_NUM(sp, 2)	\
	__ONE_GPR_NUM(gp, 3)	\
	__ONE_GPR_NUM(tp, 4)	\
	__ONE_GPR_NUM(t0, 5)	\
	__ONE_GPR_NUM(t1, 6)	\
	__ONE_GPR_NUM(t2, 7)	\
	__ONE_GPR_NUM(s0, 8)	\
	__ONE_GPR_NUM(s1, 9)	\
	__ONE_GPR_NUM(a0, 10)	\
	__ONE_GPR_NUM(a1, 11)	\
	__ONE_GPR_NUM(a2, 12)	\
	__ONE_GPR_NUM(a3, 13)	\
	__ONE_GPR_NUM(a4, 14)	\
	__ONE_GPR_NUM(a5, 15)	\
	__ONE_GPR_NUM(a6, 16)	\
	__ONE_GPR_NUM(a7, 17)	\
	__ONE_GPR_NUM(s2, 18)	\
	__ONE_GPR_NUM(s3, 19)	\
	__ONE_GPR_NUM(s4, 20)	\
	__ONE_GPR_NUM(s5, 21)	\
	__ONE_GPR_NUM(s6, 22)	\
	__ONE_GPR_NUM(s7, 23)	\
	__ONE_GPR_NUM(s8, 24)	\
	__ONE_GPR_NUM(s9, 25)	\
	__ONE_GPR_NUM(s10, 26)	\
	__ONE_GPR_NUM(s11, 27)	\
	__ONE_GPR_NUM(t3, 28)	\
	__ONE_GPR_NUM(t4, 29)	\
	__ONE_GPR_NUM(t5, 30)	\
	__ONE_GPR_NUM(t6, 31)

#ifdef __ASSEMBLER__

#define __ONE_GPR_NUM(__name, __num) \
	.equ	.L__gpr_num_x ## __num  , __num; \
	.equ	.L__gpr_num_c ## __num  , __num; \
	.equ	.L__gpr_num_  ## __name , __num; \
	.equ	.L__gpr_num_c ## __name , __num;

	.irp	num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
	.equ	.L__gpr_num_x\num, \num
	.endr

	__ALL_GPR_NUMS

#else /* __ASSEMBLER__ */

#define __ONE_GPR_NUM(__name, __num) \
	".equ	.L__gpr_num_x" #__num  ", " #__num "\n" \
	".equ	.L__gpr_num_c" #__num  ", " #__num "\n" \
	".equ	.L__gpr_num_"  #__name ", " #__num "\n" \
	".equ	.L__gpr_num_c" #__name ", " #__num "\n"

#define __DEFINE_ASM_GPR_NUMS __ALL_GPR_NUMS

#endif /* __ASSEMBLER__ */

#endif /* __ASM_GPR_NUM_H */
