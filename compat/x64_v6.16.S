	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p1_m2p0_a2p1_c2p0"
	.file	"x64.c"
	.globl	asm_offsets                     # -- Begin function asm_offsets
	.p2align	2
	.type	asm_offsets,@function
asm_offsets:                            # @asm_offsets
# %bb.0:
	addi	sp, sp, -16
	sd	ra, 8(sp)                       # 8-byte Folded Spill
	sd	s0, 0(sp)                       # 8-byte Folded Spill
	addi	s0, sp, 16
	#APP

	.ascii	"->SIZEOF__BIG_IOCTL_Command_struct 96 sizeof( __C(BIG_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__BIG_IOCTL_Command_struct 8 __alignof( __C(BIG_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_LogDev 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_LogDev_reserved 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.LogDev.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_LunAddrBytes 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.LunAddrBytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev_DevLSB 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogUnit 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev_Dev 4 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev_DevLSB 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogUnit 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev_Dev 0 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_Request 8 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), Request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_Request_CDB 12 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), Request.CDB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_Request_CDBLen 8 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), Request.CDBLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_Request_Timeout 10 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), Request.Timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_Request_Type 9 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), Request.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_buf 88 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_buf_size 80 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info 28 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_CommandStatus 30 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.CommandStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo 36 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info 36 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_ErrorInfo 40 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.ErrorInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Reserved 36 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Type 39 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd 36 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_Reserved 36 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_num 39 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_size 38 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_value 40 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_ResidualCnt 32 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.ResidualCnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_ScsiStatus 28 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.ScsiStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_SenseInfo 44 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.SenseInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_error_info_SenseLen 29 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), error_info.SenseLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_BIG_IOCTL_Command_struct_malloc_size 76 __builtin_offsetof( __C(BIG_IOCTL_Command_struct), malloc_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__IOCTL_Command_struct 88 sizeof( __C(IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__IOCTL_Command_struct 8 __alignof( __C(IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_LogDev 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_LogDev_reserved 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.LogDev.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_LunAddrBytes 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.LunAddrBytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev_DevLSB 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogUnit 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev_Dev 4 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev_DevLSB 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogUnit 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev_Dev 0 __builtin_offsetof( __C(IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_Request 8 __builtin_offsetof( __C(IOCTL_Command_struct), Request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_Request_CDB 12 __builtin_offsetof( __C(IOCTL_Command_struct), Request.CDB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_Request_CDBLen 8 __builtin_offsetof( __C(IOCTL_Command_struct), Request.CDBLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_Request_Timeout 10 __builtin_offsetof( __C(IOCTL_Command_struct), Request.Timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_Request_Type 9 __builtin_offsetof( __C(IOCTL_Command_struct), Request.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_buf 80 __builtin_offsetof( __C(IOCTL_Command_struct), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_buf_size 76 __builtin_offsetof( __C(IOCTL_Command_struct), buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info 28 __builtin_offsetof( __C(IOCTL_Command_struct), error_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_CommandStatus 30 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.CommandStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo 36 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info 36 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_ErrorInfo 40 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.ErrorInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Reserved 36 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Type 39 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd 36 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_Reserved 36 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_num 39 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_size 38 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_value 40 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_ResidualCnt 32 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.ResidualCnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_ScsiStatus 28 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.ScsiStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_SenseInfo 44 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.SenseInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_IOCTL_Command_struct_error_info_SenseLen 29 __builtin_offsetof( __C(IOCTL_Command_struct), error_info.SenseLen)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__atm_kptr_t 8 sizeof( __C(atm_kptr_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__atm_kptr_t 1 __alignof( __C(atm_kptr_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atm_kptr_t__ 0 __builtin_offsetof( __C(atm_kptr_t), _)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__bpf_user_pt_regs_t 256 sizeof( __C(bpf_user_pt_regs_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__bpf_user_pt_regs_t 8 __alignof( __C(bpf_user_pt_regs_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a0 80 __builtin_offsetof( __C(bpf_user_pt_regs_t), a0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a1 88 __builtin_offsetof( __C(bpf_user_pt_regs_t), a1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a2 96 __builtin_offsetof( __C(bpf_user_pt_regs_t), a2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a3 104 __builtin_offsetof( __C(bpf_user_pt_regs_t), a3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a4 112 __builtin_offsetof( __C(bpf_user_pt_regs_t), a4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a5 120 __builtin_offsetof( __C(bpf_user_pt_regs_t), a5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a6 128 __builtin_offsetof( __C(bpf_user_pt_regs_t), a6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_a7 136 __builtin_offsetof( __C(bpf_user_pt_regs_t), a7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_gp 24 __builtin_offsetof( __C(bpf_user_pt_regs_t), gp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_pc 0 __builtin_offsetof( __C(bpf_user_pt_regs_t), pc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_ra 8 __builtin_offsetof( __C(bpf_user_pt_regs_t), ra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s0 64 __builtin_offsetof( __C(bpf_user_pt_regs_t), s0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s1 72 __builtin_offsetof( __C(bpf_user_pt_regs_t), s1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s10 208 __builtin_offsetof( __C(bpf_user_pt_regs_t), s10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s11 216 __builtin_offsetof( __C(bpf_user_pt_regs_t), s11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s2 144 __builtin_offsetof( __C(bpf_user_pt_regs_t), s2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s3 152 __builtin_offsetof( __C(bpf_user_pt_regs_t), s3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s4 160 __builtin_offsetof( __C(bpf_user_pt_regs_t), s4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s5 168 __builtin_offsetof( __C(bpf_user_pt_regs_t), s5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s6 176 __builtin_offsetof( __C(bpf_user_pt_regs_t), s6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s7 184 __builtin_offsetof( __C(bpf_user_pt_regs_t), s7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s8 192 __builtin_offsetof( __C(bpf_user_pt_regs_t), s8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_s9 200 __builtin_offsetof( __C(bpf_user_pt_regs_t), s9)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_sp 16 __builtin_offsetof( __C(bpf_user_pt_regs_t), sp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t0 40 __builtin_offsetof( __C(bpf_user_pt_regs_t), t0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t1 48 __builtin_offsetof( __C(bpf_user_pt_regs_t), t1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t2 56 __builtin_offsetof( __C(bpf_user_pt_regs_t), t2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t3 224 __builtin_offsetof( __C(bpf_user_pt_regs_t), t3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t4 232 __builtin_offsetof( __C(bpf_user_pt_regs_t), t4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t5 240 __builtin_offsetof( __C(bpf_user_pt_regs_t), t5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_t6 248 __builtin_offsetof( __C(bpf_user_pt_regs_t), t6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_user_pt_regs_t_tp 32 __builtin_offsetof( __C(bpf_user_pt_regs_t), tp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__buffmem_desc 16 sizeof( __C(buffmem_desc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__buffmem_desc 8 __alignof( __C(buffmem_desc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_buffmem_desc_buffer 0 __builtin_offsetof( __C(buffmem_desc), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_buffmem_desc_size 8 __builtin_offsetof( __C(buffmem_desc), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_clear_t 32 sizeof( __C(drm_radeon_clear_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_clear_t 8 __alignof( __C(drm_radeon_clear_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_clear_color 4 __builtin_offsetof( __C(drm_radeon_clear_t), clear_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_clear_depth 8 __builtin_offsetof( __C(drm_radeon_clear_t), clear_depth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_color_mask 12 __builtin_offsetof( __C(drm_radeon_clear_t), color_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_depth_boxes 24 __builtin_offsetof( __C(drm_radeon_clear_t), depth_boxes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_depth_mask 16 __builtin_offsetof( __C(drm_radeon_clear_t), depth_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_t_flags 0 __builtin_offsetof( __C(drm_radeon_clear_t), flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_cmd_buffer_t 32 sizeof( __C(drm_radeon_cmd_buffer_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_cmd_buffer_t 8 __alignof( __C(drm_radeon_cmd_buffer_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_t_boxes 24 __builtin_offsetof( __C(drm_radeon_cmd_buffer_t), boxes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_t_buf 8 __builtin_offsetof( __C(drm_radeon_cmd_buffer_t), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_t_bufsz 0 __builtin_offsetof( __C(drm_radeon_cmd_buffer_t), bufsz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_t_nbox 16 __builtin_offsetof( __C(drm_radeon_cmd_buffer_t), nbox)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_getparam_t 16 sizeof( __C(drm_radeon_getparam_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_getparam_t 8 __alignof( __C(drm_radeon_getparam_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_getparam_t_param 0 __builtin_offsetof( __C(drm_radeon_getparam_t), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_getparam_t_value 8 __builtin_offsetof( __C(drm_radeon_getparam_t), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_irq_emit_t 8 sizeof( __C(drm_radeon_irq_emit_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_irq_emit_t 8 __alignof( __C(drm_radeon_irq_emit_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_irq_emit_t_irq_seq 0 __builtin_offsetof( __C(drm_radeon_irq_emit_t), irq_seq)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_mem_alloc_t 24 sizeof( __C(drm_radeon_mem_alloc_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_mem_alloc_t 8 __alignof( __C(drm_radeon_mem_alloc_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_t_alignment 4 __builtin_offsetof( __C(drm_radeon_mem_alloc_t), alignment)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_t_region 0 __builtin_offsetof( __C(drm_radeon_mem_alloc_t), region)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_t_region_offset 16 __builtin_offsetof( __C(drm_radeon_mem_alloc_t), region_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_t_size 8 __builtin_offsetof( __C(drm_radeon_mem_alloc_t), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_stipple_t 8 sizeof( __C(drm_radeon_stipple_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_stipple_t 8 __alignof( __C(drm_radeon_stipple_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_stipple_t_mask 0 __builtin_offsetof( __C(drm_radeon_stipple_t), mask)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_tex_image_t 24 sizeof( __C(drm_radeon_tex_image_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_tex_image_t 8 __alignof( __C(drm_radeon_tex_image_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_t_data 16 __builtin_offsetof( __C(drm_radeon_tex_image_t), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_t_height 12 __builtin_offsetof( __C(drm_radeon_tex_image_t), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_t_width 8 __builtin_offsetof( __C(drm_radeon_tex_image_t), width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_t_x 0 __builtin_offsetof( __C(drm_radeon_tex_image_t), x)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_t_y 4 __builtin_offsetof( __C(drm_radeon_tex_image_t), y)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_texture_t 32 sizeof( __C(drm_radeon_texture_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_texture_t 8 __alignof( __C(drm_radeon_texture_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_format 8 __builtin_offsetof( __C(drm_radeon_texture_t), format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_height 16 __builtin_offsetof( __C(drm_radeon_texture_t), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_image 24 __builtin_offsetof( __C(drm_radeon_texture_t), image)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_offset 0 __builtin_offsetof( __C(drm_radeon_texture_t), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_pitch 4 __builtin_offsetof( __C(drm_radeon_texture_t), pitch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_t_width 12 __builtin_offsetof( __C(drm_radeon_texture_t), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__drm_radeon_vertex2_t 40 sizeof( __C(drm_radeon_vertex2_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__drm_radeon_vertex2_t 8 __alignof( __C(drm_radeon_vertex2_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_discard 4 __builtin_offsetof( __C(drm_radeon_vertex2_t), discard)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_idx 0 __builtin_offsetof( __C(drm_radeon_vertex2_t), idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_nr_prims 24 __builtin_offsetof( __C(drm_radeon_vertex2_t), nr_prims)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_nr_states 8 __builtin_offsetof( __C(drm_radeon_vertex2_t), nr_states)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_prim 32 __builtin_offsetof( __C(drm_radeon_vertex2_t), prim)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_t_state 16 __builtin_offsetof( __C(drm_radeon_vertex2_t), state)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__ide_ioctl_request_t 24 sizeof( __C(ide_ioctl_request_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__ide_ioctl_request_t 8 __alignof( __C(ide_ioctl_request_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_t_in_buffer 16 __builtin_offsetof( __C(ide_ioctl_request_t), in_buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_t_out_buffer 8 __builtin_offsetof( __C(ide_ioctl_request_t), out_buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_t_task_request 0 __builtin_offsetof( __C(ide_ioctl_request_t), task_request)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__osd_cmd_t 32 sizeof( __C(osd_cmd_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__osd_cmd_t 8 __alignof( __C(osd_cmd_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_cmd 0 __builtin_offsetof( __C(osd_cmd_t), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_color 20 __builtin_offsetof( __C(osd_cmd_t), color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_data 24 __builtin_offsetof( __C(osd_cmd_t), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_x0 4 __builtin_offsetof( __C(osd_cmd_t), x0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_x1 12 __builtin_offsetof( __C(osd_cmd_t), x1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_y0 8 __builtin_offsetof( __C(osd_cmd_t), y0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_t_y1 16 __builtin_offsetof( __C(osd_cmd_t), y1)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__sigval_t 8 sizeof( __C(sigval_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__sigval_t 8 __alignof( __C(sigval_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigval_t_sival_int 0 __builtin_offsetof( __C(sigval_t), sival_int)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigval_t_sival_ptr 0 __builtin_offsetof( __C(sigval_t), sival_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF__stack_t 24 sizeof( __C(stack_t))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF__stack_t 8 __alignof( __C(stack_t))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_stack_t_ss_flags 8 __builtin_offsetof( __C(stack_t), ss_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_stack_t_ss_size 16 __builtin_offsetof( __C(stack_t), ss_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_stack_t_ss_sp 0 __builtin_offsetof( __C(stack_t), ss_sp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_PioctlData 40 sizeof(struct __C(PioctlData))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_PioctlData 8 __alignof(struct __C(PioctlData))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_follow 8 __builtin_offsetof(struct __C(PioctlData), follow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_path 0 __builtin_offsetof(struct __C(PioctlData), path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_vi 16 __builtin_offsetof(struct __C(PioctlData), vi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_vi_in 16 __builtin_offsetof(struct __C(PioctlData), vi.in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_vi_in_size 32 __builtin_offsetof(struct __C(PioctlData), vi.in_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_vi_out 24 __builtin_offsetof(struct __C(PioctlData), vi.out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_PioctlData_vi_out_size 34 __builtin_offsetof(struct __C(PioctlData), vi.out_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ViceIoctl 24 sizeof(struct __C(ViceIoctl))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ViceIoctl 8 __alignof(struct __C(ViceIoctl))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ViceIoctl_in 0 __builtin_offsetof(struct __C(ViceIoctl), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ViceIoctl_in_size 16 __builtin_offsetof(struct __C(ViceIoctl), in_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ViceIoctl_out 8 __builtin_offsetof(struct __C(ViceIoctl), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ViceIoctl_out_size 18 __builtin_offsetof(struct __C(ViceIoctl), out_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct__BIG_IOCTL_Command_struct 96 sizeof(struct __C(_BIG_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct__BIG_IOCTL_Command_struct 8 __alignof(struct __C(_BIG_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_LogDev 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_LogDev_reserved 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.LogDev.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_LunAddrBytes 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.LunAddrBytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev_DevLSB 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogUnit 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev_Dev 4 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev_DevLSB 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogUnit 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev_Dev 0 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_Request 8 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), Request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_Request_CDB 12 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), Request.CDB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_Request_CDBLen 8 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), Request.CDBLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_Request_Timeout 10 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), Request.Timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_Request_Type 9 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), Request.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_buf 88 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_buf_size 80 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info 28 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_CommandStatus 30 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.CommandStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo 36 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info 36 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_ErrorInfo 40 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.ErrorInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Reserved 36 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Type 39 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd 36 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_Reserved 36 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_num 39 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_size 38 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_value 40 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_ResidualCnt 32 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.ResidualCnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_ScsiStatus 28 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.ScsiStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_SenseInfo 44 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.SenseInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_error_info_SenseLen 29 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), error_info.SenseLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__BIG_IOCTL_Command_struct_malloc_size 76 __builtin_offsetof(struct __C(_BIG_IOCTL_Command_struct), malloc_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct__IOCTL_Command_struct 88 sizeof(struct __C(_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct__IOCTL_Command_struct 8 __alignof(struct __C(_IOCTL_Command_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_LogDev 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_LogDev_reserved 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.LogDev.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_LunAddrBytes 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.LunAddrBytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogDev_DevLSB 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target_0__LogUnit 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_PhysDev_Target_0__PeripDev_Dev 4 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.PhysDev.Target[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogDev_DevLSB 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogDev.DevLSB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun_0__LogUnit 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].LogUnit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_LUN_info_SCSI3Lun_0__PeripDev_Dev 0 __builtin_offsetof(struct __C(_IOCTL_Command_struct), LUN_info.SCSI3Lun[0].PeripDev.Dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_Request 8 __builtin_offsetof(struct __C(_IOCTL_Command_struct), Request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_Request_CDB 12 __builtin_offsetof(struct __C(_IOCTL_Command_struct), Request.CDB)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_Request_CDBLen 8 __builtin_offsetof(struct __C(_IOCTL_Command_struct), Request.CDBLen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_Request_Timeout 10 __builtin_offsetof(struct __C(_IOCTL_Command_struct), Request.Timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_Request_Type 9 __builtin_offsetof(struct __C(_IOCTL_Command_struct), Request.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_buf 80 __builtin_offsetof(struct __C(_IOCTL_Command_struct), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_buf_size 76 __builtin_offsetof(struct __C(_IOCTL_Command_struct), buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info 28 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_CommandStatus 30 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.CommandStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo 36 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info 36 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_ErrorInfo 40 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.ErrorInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Reserved 36 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Common_Info_Type 39 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Common_Info.Type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd 36 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_Reserved 36 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.Reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_num 39 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_size 38 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_MoreErrInfo_Invalid_Cmd_offense_value 40 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.MoreErrInfo.Invalid_Cmd.offense_value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_ResidualCnt 32 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.ResidualCnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_ScsiStatus 28 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.ScsiStatus)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_SenseInfo 44 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.SenseInfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG__IOCTL_Command_struct_error_info_SenseLen 29 __builtin_offsetof(struct __C(_IOCTL_Command_struct), error_info.SenseLen)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct___riscv_v_ext_state 48 sizeof(struct __C(__riscv_v_ext_state))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct___riscv_v_ext_state 8 __alignof(struct __C(__riscv_v_ext_state))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_datap 40 __builtin_offsetof(struct __C(__riscv_v_ext_state), datap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_vcsr 24 __builtin_offsetof(struct __C(__riscv_v_ext_state), vcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_vl 8 __builtin_offsetof(struct __C(__riscv_v_ext_state), vl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_vlenb 32 __builtin_offsetof(struct __C(__riscv_v_ext_state), vlenb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_vstart 0 __builtin_offsetof(struct __C(__riscv_v_ext_state), vstart)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___riscv_v_ext_state_vtype 16 __builtin_offsetof(struct __C(__riscv_v_ext_state), vtype)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct___sc_riscv_v_state 48 sizeof(struct __C(__sc_riscv_v_state))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct___sc_riscv_v_state 16 __alignof(struct __C(__sc_riscv_v_state))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state 0 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_datap 40 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.datap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_vcsr 24 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.vcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_vl 8 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.vl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_vlenb 32 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.vlenb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_vstart 0 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.vstart)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sc_riscv_v_state_v_state_vtype 16 __builtin_offsetof(struct __C(__sc_riscv_v_state), v_state.vtype)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct___sysctl_args 80 sizeof(struct __C(__sysctl_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct___sysctl_args 8 __alignof(struct __C(__sysctl_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args___unused 48 __builtin_offsetof(struct __C(__sysctl_args), __unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_name 0 __builtin_offsetof(struct __C(__sysctl_args), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_newlen 40 __builtin_offsetof(struct __C(__sysctl_args), newlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_newval 32 __builtin_offsetof(struct __C(__sysctl_args), newval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_nlen 8 __builtin_offsetof(struct __C(__sysctl_args), nlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_oldlenp 24 __builtin_offsetof(struct __C(__sysctl_args), oldlenp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG___sysctl_args_oldval 16 __builtin_offsetof(struct __C(__sysctl_args), oldval)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_arpt_entry 192 sizeof(struct __C(arpt_entry))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_arpt_entry 8 __alignof(struct __C(arpt_entry))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp 0 __builtin_offsetof(struct __C(arpt_entry), arp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arhln 16 __builtin_offsetof(struct __C(arpt_entry), arp.arhln)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arhln_mask 17 __builtin_offsetof(struct __C(arpt_entry), arp.arhln_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arhrd 86 __builtin_offsetof(struct __C(arpt_entry), arp.arhrd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arhrd_mask 88 __builtin_offsetof(struct __C(arpt_entry), arp.arhrd_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arpop 82 __builtin_offsetof(struct __C(arpt_entry), arp.arpop)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arpop_mask 84 __builtin_offsetof(struct __C(arpt_entry), arp.arpop_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arpro 90 __builtin_offsetof(struct __C(arpt_entry), arp.arpro)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_arpro_mask 92 __builtin_offsetof(struct __C(arpt_entry), arp.arpro_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_flags 158 __builtin_offsetof(struct __C(arpt_entry), arp.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_iniface 94 __builtin_offsetof(struct __C(arpt_entry), arp.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_iniface_mask 126 __builtin_offsetof(struct __C(arpt_entry), arp.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_invflags 160 __builtin_offsetof(struct __C(arpt_entry), arp.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_outiface 110 __builtin_offsetof(struct __C(arpt_entry), arp.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_outiface_mask 142 __builtin_offsetof(struct __C(arpt_entry), arp.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_smsk 8 __builtin_offsetof(struct __C(arpt_entry), arp.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_smsk_s_addr 8 __builtin_offsetof(struct __C(arpt_entry), arp.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_src 0 __builtin_offsetof(struct __C(arpt_entry), arp.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_src_s_addr 0 __builtin_offsetof(struct __C(arpt_entry), arp.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_src_devaddr 18 __builtin_offsetof(struct __C(arpt_entry), arp.src_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_src_devaddr_addr 18 __builtin_offsetof(struct __C(arpt_entry), arp.src_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_src_devaddr_mask 34 __builtin_offsetof(struct __C(arpt_entry), arp.src_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tgt 4 __builtin_offsetof(struct __C(arpt_entry), arp.tgt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tgt_s_addr 4 __builtin_offsetof(struct __C(arpt_entry), arp.tgt.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tgt_devaddr 50 __builtin_offsetof(struct __C(arpt_entry), arp.tgt_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tgt_devaddr_addr 50 __builtin_offsetof(struct __C(arpt_entry), arp.tgt_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tgt_devaddr_mask 66 __builtin_offsetof(struct __C(arpt_entry), arp.tgt_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tmsk 12 __builtin_offsetof(struct __C(arpt_entry), arp.tmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_arp_tmsk_s_addr 12 __builtin_offsetof(struct __C(arpt_entry), arp.tmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_comefrom 168 __builtin_offsetof(struct __C(arpt_entry), comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_counters 176 __builtin_offsetof(struct __C(arpt_entry), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_counters_bcnt 184 __builtin_offsetof(struct __C(arpt_entry), counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_counters_pcnt 176 __builtin_offsetof(struct __C(arpt_entry), counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_elems 192 __builtin_offsetof(struct __C(arpt_entry), elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_next_offset 166 __builtin_offsetof(struct __C(arpt_entry), next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_entry_target_offset 164 __builtin_offsetof(struct __C(arpt_entry), target_offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_arpt_get_entries 40 sizeof(struct __C(arpt_get_entries))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_arpt_get_entries 8 __alignof(struct __C(arpt_get_entries))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable 40 __builtin_offsetof(struct __C(arpt_get_entries), entrytable)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp 40 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arhln 56 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arhln)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arhln_mask 57 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arhln_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arhrd 126 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arhrd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arhrd_mask 128 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arhrd_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arpop 122 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arpop)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arpop_mask 124 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arpop_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arpro 130 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arpro)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_arpro_mask 132 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.arpro_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_flags 198 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_iniface 134 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_iniface_mask 166 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_invflags 200 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_outiface 150 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_outiface_mask 182 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_smsk 48 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_smsk_s_addr 48 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_src 40 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_src_s_addr 40 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_src_devaddr 58 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.src_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_src_devaddr_addr 58 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.src_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_src_devaddr_mask 74 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.src_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tgt 44 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tgt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tgt_s_addr 44 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tgt.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tgt_devaddr 90 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tgt_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tgt_devaddr_addr 90 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tgt_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tgt_devaddr_mask 106 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tgt_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tmsk 52 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__arp_tmsk_s_addr 52 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].arp.tmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__comefrom 208 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__counters 216 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__counters_bcnt 224 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__counters_pcnt 216 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__elems 232 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__next_offset 206 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_entrytable_0__target_offset 204 __builtin_offsetof(struct __C(arpt_get_entries), entrytable[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_name 0 __builtin_offsetof(struct __C(arpt_get_entries), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_get_entries_size 32 __builtin_offsetof(struct __C(arpt_get_entries), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_arpt_replace 80 sizeof(struct __C(arpt_replace))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_arpt_replace 8 __alignof(struct __C(arpt_replace))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_counters 72 __builtin_offsetof(struct __C(arpt_replace), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries 80 __builtin_offsetof(struct __C(arpt_replace), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp 80 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arhln 96 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arhln)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arhln_mask 97 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arhln_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arhrd 166 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arhrd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arhrd_mask 168 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arhrd_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arpop 162 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arpop)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arpop_mask 164 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arpop_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arpro 170 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arpro)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_arpro_mask 172 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.arpro_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_flags 238 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_iniface 174 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_iniface_mask 206 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_invflags 240 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_outiface 190 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_outiface_mask 222 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_smsk 88 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_smsk_s_addr 88 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_src 80 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_src_s_addr 80 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_src_devaddr 98 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.src_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_src_devaddr_addr 98 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.src_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_src_devaddr_mask 114 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.src_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tgt 84 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tgt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tgt_s_addr 84 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tgt.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tgt_devaddr 130 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tgt_devaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tgt_devaddr_addr 130 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tgt_devaddr.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tgt_devaddr_mask 146 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tgt_devaddr.mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tmsk 92 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__arp_tmsk_s_addr 92 __builtin_offsetof(struct __C(arpt_replace), entries[0].arp.tmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__comefrom 248 __builtin_offsetof(struct __C(arpt_replace), entries[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__counters 256 __builtin_offsetof(struct __C(arpt_replace), entries[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__counters_bcnt 264 __builtin_offsetof(struct __C(arpt_replace), entries[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__counters_pcnt 256 __builtin_offsetof(struct __C(arpt_replace), entries[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__elems 272 __builtin_offsetof(struct __C(arpt_replace), entries[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__next_offset 246 __builtin_offsetof(struct __C(arpt_replace), entries[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_entries_0__target_offset 244 __builtin_offsetof(struct __C(arpt_replace), entries[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_hook_entry 44 __builtin_offsetof(struct __C(arpt_replace), hook_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_name 0 __builtin_offsetof(struct __C(arpt_replace), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_num_counters 68 __builtin_offsetof(struct __C(arpt_replace), num_counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_num_entries 36 __builtin_offsetof(struct __C(arpt_replace), num_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_size 40 __builtin_offsetof(struct __C(arpt_replace), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_underflow 56 __builtin_offsetof(struct __C(arpt_replace), underflow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_arpt_replace_valid_hooks 32 __builtin_offsetof(struct __C(arpt_replace), valid_hooks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_atm_iobuf 16 sizeof(struct __C(atm_iobuf))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_atm_iobuf 8 __alignof(struct __C(atm_iobuf))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atm_iobuf_buffer 8 __builtin_offsetof(struct __C(atm_iobuf), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atm_iobuf_length 0 __builtin_offsetof(struct __C(atm_iobuf), length)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_atmif_sioc 16 sizeof(struct __C(atmif_sioc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_atmif_sioc 8 __alignof(struct __C(atmif_sioc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmif_sioc_arg 8 __builtin_offsetof(struct __C(atmif_sioc), arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmif_sioc_length 4 __builtin_offsetof(struct __C(atmif_sioc), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmif_sioc_number 0 __builtin_offsetof(struct __C(atmif_sioc), number)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_atmsvc_msg 252 sizeof(struct __C(atmsvc_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_atmsvc_msg 4 __alignof(struct __C(atmsvc_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_listen_vcc 12 __builtin_offsetof(struct __C(atmsvc_msg), listen_vcc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_listen_vcc__ 12 __builtin_offsetof(struct __C(atmsvc_msg), listen_vcc._)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local 36 __builtin_offsetof(struct __C(atmsvc_msg), local)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_addr 40 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_addr_lij_id 76 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_addr.lij_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_addr_lij_type 73 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_addr.lij_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_addr_prv 40 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_addr.prv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_addr_pub 60 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_addr.pub)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_local_sas_family 36 __builtin_offsetof(struct __C(atmsvc_msg), local.sas_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc 24 __builtin_offsetof(struct __C(atmsvc_msg), pvc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc_sap_addr 28 __builtin_offsetof(struct __C(atmsvc_msg), pvc.sap_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc_sap_addr_itf 28 __builtin_offsetof(struct __C(atmsvc_msg), pvc.sap_addr.itf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc_sap_addr_vci 32 __builtin_offsetof(struct __C(atmsvc_msg), pvc.sap_addr.vci)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc_sap_addr_vpi 30 __builtin_offsetof(struct __C(atmsvc_msg), pvc.sap_addr.vpi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_pvc_sap_family 24 __builtin_offsetof(struct __C(atmsvc_msg), pvc.sap_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos 80 __builtin_offsetof(struct __C(atmsvc_msg), qos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_aal 160 __builtin_offsetof(struct __C(atmsvc_msg), qos.aal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp 120 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_icr 144 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.icr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_max_cdv 136 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.max_cdv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_max_pcr 124 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.max_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_max_sdu 140 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.max_sdu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_min_pcr 132 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.min_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_pcr 128 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_tbe 148 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.tbe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_rxtp_traffic_class 120 __builtin_offsetof(struct __C(atmsvc_msg), qos.rxtp.traffic_class)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp 80 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_icr 104 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.icr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_max_cdv 96 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.max_cdv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_max_pcr 84 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.max_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_max_sdu 100 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.max_sdu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_min_pcr 92 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.min_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_pcr 88 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_tbe 108 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.tbe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_qos_txtp_traffic_class 80 __builtin_offsetof(struct __C(atmsvc_msg), qos.txtp.traffic_class)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_reply 20 __builtin_offsetof(struct __C(atmsvc_msg), reply)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap 164 __builtin_offsetof(struct __C(atmsvc_msg), sap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_bhli 164 __builtin_offsetof(struct __C(atmsvc_msg), sap.bhli)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_bhli_hl_info 166 __builtin_offsetof(struct __C(atmsvc_msg), sap.bhli.hl_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_bhli_hl_length 165 __builtin_offsetof(struct __C(atmsvc_msg), sap.bhli.hl_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_bhli_hl_type 164 __builtin_offsetof(struct __C(atmsvc_msg), sap.bhli.hl_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli 174 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2 175 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2_itu 175 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2.itu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2_itu_mode 175 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2.itu.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2_itu_window 176 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2.itu.window)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2_user 175 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l2_proto 174 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l2_proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_h310 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.h310)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_h310_bw_mpx_cap 180 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.h310.bw_mpx_cap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_h310_fw_mpx_cap 179 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.h310.fw_mpx_cap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_h310_term_type 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.h310.term_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_itu 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.itu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_itu_def_size 179 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.itu.def_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_itu_mode 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.itu.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_itu_window 180 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.itu.window)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_tr9577 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.tr9577)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_tr9577_ipi 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.tr9577.ipi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_tr9577_snap 179 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.tr9577.snap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_user 178 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_sap_blli_0__l3_proto 177 __builtin_offsetof(struct __C(atmsvc_msg), sap.blli[0].l3_proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_session 204 __builtin_offsetof(struct __C(atmsvc_msg), session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc 208 __builtin_offsetof(struct __C(atmsvc_msg), svc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_addr 212 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_addr_lij_id 248 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_addr.lij_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_addr_lij_type 245 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_addr.lij_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_addr_prv 212 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_addr.prv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_addr_pub 232 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_addr.pub)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_svc_sas_family 208 __builtin_offsetof(struct __C(atmsvc_msg), svc.sas_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_type 0 __builtin_offsetof(struct __C(atmsvc_msg), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_vcc 4 __builtin_offsetof(struct __C(atmsvc_msg), vcc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmsvc_msg_vcc__ 4 __builtin_offsetof(struct __C(atmsvc_msg), vcc._)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_atmtcp_control 120 sizeof(struct __C(atmtcp_control))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_atmtcp_control 4 __alignof(struct __C(atmtcp_control))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr 20 __builtin_offsetof(struct __C(atmtcp_control), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr_sap_addr 24 __builtin_offsetof(struct __C(atmtcp_control), addr.sap_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr_sap_addr_itf 24 __builtin_offsetof(struct __C(atmtcp_control), addr.sap_addr.itf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr_sap_addr_vci 28 __builtin_offsetof(struct __C(atmtcp_control), addr.sap_addr.vci)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr_sap_addr_vpi 26 __builtin_offsetof(struct __C(atmtcp_control), addr.sap_addr.vpi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_addr_sap_family 20 __builtin_offsetof(struct __C(atmtcp_control), addr.sap_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_hdr 0 __builtin_offsetof(struct __C(atmtcp_control), hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_hdr_length 4 __builtin_offsetof(struct __C(atmtcp_control), hdr.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_hdr_vci 2 __builtin_offsetof(struct __C(atmtcp_control), hdr.vci)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_hdr_vpi 0 __builtin_offsetof(struct __C(atmtcp_control), hdr.vpi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos 32 __builtin_offsetof(struct __C(atmtcp_control), qos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_aal 112 __builtin_offsetof(struct __C(atmtcp_control), qos.aal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp 72 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_icr 96 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.icr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_max_cdv 88 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.max_cdv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_max_pcr 76 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.max_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_max_sdu 92 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.max_sdu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_min_pcr 84 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.min_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_pcr 80 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_tbe 100 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.tbe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_rxtp_traffic_class 72 __builtin_offsetof(struct __C(atmtcp_control), qos.rxtp.traffic_class)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp 32 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_icr 56 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.icr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_max_cdv 48 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.max_cdv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_max_pcr 36 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.max_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_max_sdu 52 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.max_sdu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_min_pcr 44 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.min_pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_pcr 40 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.pcr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_tbe 60 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.tbe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_qos_txtp_traffic_class 32 __builtin_offsetof(struct __C(atmtcp_control), qos.txtp.traffic_class)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_result 116 __builtin_offsetof(struct __C(atmtcp_control), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_type 8 __builtin_offsetof(struct __C(atmtcp_control), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_vcc 12 __builtin_offsetof(struct __C(atmtcp_control), vcc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_atmtcp_control_vcc__ 12 __builtin_offsetof(struct __C(atmtcp_control), vcc._)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_blk_crypto_generate_key_arg 48 sizeof(struct __C(blk_crypto_generate_key_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_blk_crypto_generate_key_arg 8 __alignof(struct __C(blk_crypto_generate_key_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_generate_key_arg_lt_key_ptr 0 __builtin_offsetof(struct __C(blk_crypto_generate_key_arg), lt_key_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_generate_key_arg_lt_key_size 8 __builtin_offsetof(struct __C(blk_crypto_generate_key_arg), lt_key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_generate_key_arg_reserved 16 __builtin_offsetof(struct __C(blk_crypto_generate_key_arg), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_blk_crypto_import_key_arg 64 sizeof(struct __C(blk_crypto_import_key_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_blk_crypto_import_key_arg 8 __alignof(struct __C(blk_crypto_import_key_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_import_key_arg_lt_key_ptr 16 __builtin_offsetof(struct __C(blk_crypto_import_key_arg), lt_key_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_import_key_arg_lt_key_size 24 __builtin_offsetof(struct __C(blk_crypto_import_key_arg), lt_key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_import_key_arg_raw_key_ptr 0 __builtin_offsetof(struct __C(blk_crypto_import_key_arg), raw_key_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_import_key_arg_raw_key_size 8 __builtin_offsetof(struct __C(blk_crypto_import_key_arg), raw_key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_import_key_arg_reserved 32 __builtin_offsetof(struct __C(blk_crypto_import_key_arg), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_blk_crypto_prepare_key_arg 64 sizeof(struct __C(blk_crypto_prepare_key_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_blk_crypto_prepare_key_arg 8 __alignof(struct __C(blk_crypto_prepare_key_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_prepare_key_arg_eph_key_ptr 16 __builtin_offsetof(struct __C(blk_crypto_prepare_key_arg), eph_key_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_prepare_key_arg_eph_key_size 24 __builtin_offsetof(struct __C(blk_crypto_prepare_key_arg), eph_key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_prepare_key_arg_lt_key_ptr 0 __builtin_offsetof(struct __C(blk_crypto_prepare_key_arg), lt_key_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_prepare_key_arg_lt_key_size 8 __builtin_offsetof(struct __C(blk_crypto_prepare_key_arg), lt_key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blk_crypto_prepare_key_arg_reserved 32 __builtin_offsetof(struct __C(blk_crypto_prepare_key_arg), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_blkpg_ioctl_arg 24 sizeof(struct __C(blkpg_ioctl_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_blkpg_ioctl_arg 8 __alignof(struct __C(blkpg_ioctl_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blkpg_ioctl_arg_data 16 __builtin_offsetof(struct __C(blkpg_ioctl_arg), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blkpg_ioctl_arg_datalen 8 __builtin_offsetof(struct __C(blkpg_ioctl_arg), datalen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blkpg_ioctl_arg_flags 4 __builtin_offsetof(struct __C(blkpg_ioctl_arg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_blkpg_ioctl_arg_op 0 __builtin_offsetof(struct __C(blkpg_ioctl_arg), op)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_bpf_btf_info 32 sizeof(struct __C(bpf_btf_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_bpf_btf_info 8 __alignof(struct __C(bpf_btf_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_btf 0 __builtin_offsetof(struct __C(bpf_btf_info), btf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_btf_size 8 __builtin_offsetof(struct __C(bpf_btf_info), btf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_id 12 __builtin_offsetof(struct __C(bpf_btf_info), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_kernel_btf 28 __builtin_offsetof(struct __C(bpf_btf_info), kernel_btf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_name 16 __builtin_offsetof(struct __C(bpf_btf_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_btf_info_name_len 24 __builtin_offsetof(struct __C(bpf_btf_info), name_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_bpf_link_info 64 sizeof(struct __C(bpf_link_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_bpf_link_info 8 __alignof(struct __C(bpf_link_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_cgroup 16 __builtin_offsetof(struct __C(bpf_link_info), cgroup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_cgroup_attach_type 24 __builtin_offsetof(struct __C(bpf_link_info), cgroup.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_cgroup_cgroup_id 16 __builtin_offsetof(struct __C(bpf_link_info), cgroup.cgroup_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_id 4 __builtin_offsetof(struct __C(bpf_link_info), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter 16 __builtin_offsetof(struct __C(bpf_link_info), iter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_cgroup 32 __builtin_offsetof(struct __C(bpf_link_info), iter.cgroup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_cgroup_cgroup_id 32 __builtin_offsetof(struct __C(bpf_link_info), iter.cgroup.cgroup_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_cgroup_order 40 __builtin_offsetof(struct __C(bpf_link_info), iter.cgroup.order)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_map 28 __builtin_offsetof(struct __C(bpf_link_info), iter.map)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_map_map_id 28 __builtin_offsetof(struct __C(bpf_link_info), iter.map.map_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_target_name 16 __builtin_offsetof(struct __C(bpf_link_info), iter.target_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_target_name_len 24 __builtin_offsetof(struct __C(bpf_link_info), iter.target_name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_task 32 __builtin_offsetof(struct __C(bpf_link_info), iter.task)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_task_pid 36 __builtin_offsetof(struct __C(bpf_link_info), iter.task.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_iter_task_tid 32 __builtin_offsetof(struct __C(bpf_link_info), iter.task.tid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi 16 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi_addrs 16 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi.addrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi_cookies 40 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi.cookies)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi_count 24 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi_flags 28 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_kprobe_multi_missed 32 __builtin_offsetof(struct __C(bpf_link_info), kprobe_multi.missed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netfilter 16 __builtin_offsetof(struct __C(bpf_link_info), netfilter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netfilter_flags 28 __builtin_offsetof(struct __C(bpf_link_info), netfilter.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netfilter_hooknum 20 __builtin_offsetof(struct __C(bpf_link_info), netfilter.hooknum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netfilter_pf 16 __builtin_offsetof(struct __C(bpf_link_info), netfilter.pf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netfilter_priority 24 __builtin_offsetof(struct __C(bpf_link_info), netfilter.priority)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netkit 16 __builtin_offsetof(struct __C(bpf_link_info), netkit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netkit_attach_type 20 __builtin_offsetof(struct __C(bpf_link_info), netkit.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netkit_ifindex 16 __builtin_offsetof(struct __C(bpf_link_info), netkit.ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netns 16 __builtin_offsetof(struct __C(bpf_link_info), netns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netns_attach_type 20 __builtin_offsetof(struct __C(bpf_link_info), netns.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_netns_netns_ino 16 __builtin_offsetof(struct __C(bpf_link_info), netns.netns_ino)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event 16 __builtin_offsetof(struct __C(bpf_link_info), perf_event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_event 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_event_config 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.event.config)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_event_cookie 40 __builtin_offsetof(struct __C(bpf_link_info), perf_event.event.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_event_type 32 __builtin_offsetof(struct __C(bpf_link_info), perf_event.event.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_addr 40 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_cookie 56 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_func_name 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.func_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_missed 48 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.missed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_name_len 32 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_kprobe_offset 36 __builtin_offsetof(struct __C(bpf_link_info), perf_event.kprobe.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_tracepoint 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.tracepoint)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_tracepoint_cookie 40 __builtin_offsetof(struct __C(bpf_link_info), perf_event.tracepoint.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_tracepoint_name_len 32 __builtin_offsetof(struct __C(bpf_link_info), perf_event.tracepoint.name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_tracepoint_tp_name 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.tracepoint.tp_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_type 16 __builtin_offsetof(struct __C(bpf_link_info), perf_event.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe_cookie 40 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe_file_name 24 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe.file_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe_name_len 32 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe.name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe_offset 36 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_perf_event_uprobe_ref_ctr_offset 48 __builtin_offsetof(struct __C(bpf_link_info), perf_event.uprobe.ref_ctr_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_prog_id 8 __builtin_offsetof(struct __C(bpf_link_info), prog_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_raw_tracepoint 16 __builtin_offsetof(struct __C(bpf_link_info), raw_tracepoint)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_raw_tracepoint_tp_name 16 __builtin_offsetof(struct __C(bpf_link_info), raw_tracepoint.tp_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_raw_tracepoint_tp_name_len 24 __builtin_offsetof(struct __C(bpf_link_info), raw_tracepoint.tp_name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_sockmap 16 __builtin_offsetof(struct __C(bpf_link_info), sockmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_sockmap_attach_type 20 __builtin_offsetof(struct __C(bpf_link_info), sockmap.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_sockmap_map_id 16 __builtin_offsetof(struct __C(bpf_link_info), sockmap.map_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_struct_ops 16 __builtin_offsetof(struct __C(bpf_link_info), struct_ops)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_struct_ops_map_id 16 __builtin_offsetof(struct __C(bpf_link_info), struct_ops.map_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tcx 16 __builtin_offsetof(struct __C(bpf_link_info), tcx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tcx_attach_type 20 __builtin_offsetof(struct __C(bpf_link_info), tcx.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tcx_ifindex 16 __builtin_offsetof(struct __C(bpf_link_info), tcx.ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tracing 16 __builtin_offsetof(struct __C(bpf_link_info), tracing)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tracing_attach_type 16 __builtin_offsetof(struct __C(bpf_link_info), tracing.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tracing_target_btf_id 24 __builtin_offsetof(struct __C(bpf_link_info), tracing.target_btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_tracing_target_obj_id 20 __builtin_offsetof(struct __C(bpf_link_info), tracing.target_obj_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_type 0 __builtin_offsetof(struct __C(bpf_link_info), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi 16 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_cookies 40 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.cookies)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_count 52 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_flags 56 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_offsets 24 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_path 16 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_path_size 48 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.path_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_pid 60 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_uprobe_multi_ref_ctr_offsets 32 __builtin_offsetof(struct __C(bpf_link_info), uprobe_multi.ref_ctr_offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_xdp 16 __builtin_offsetof(struct __C(bpf_link_info), xdp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_link_info_xdp_ifindex 16 __builtin_offsetof(struct __C(bpf_link_info), xdp.ifindex)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_bpf_prog_info 232 sizeof(struct __C(bpf_prog_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_bpf_prog_info 8 __alignof(struct __C(bpf_prog_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_attach_btf_id 224 __builtin_offsetof(struct __C(bpf_prog_info), attach_btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_attach_btf_obj_id 220 __builtin_offsetof(struct __C(bpf_prog_info), attach_btf_obj_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_btf_id 128 __builtin_offsetof(struct __C(bpf_prog_info), btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_created_by_uid 48 __builtin_offsetof(struct __C(bpf_prog_info), created_by_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_func_info 136 __builtin_offsetof(struct __C(bpf_prog_info), func_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_func_info_rec_size 132 __builtin_offsetof(struct __C(bpf_prog_info), func_info_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_id 4 __builtin_offsetof(struct __C(bpf_prog_info), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_ifindex 80 __builtin_offsetof(struct __C(bpf_prog_info), ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_func_lens 120 __builtin_offsetof(struct __C(bpf_prog_info), jited_func_lens)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_ksyms 112 __builtin_offsetof(struct __C(bpf_prog_info), jited_ksyms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_line_info 160 __builtin_offsetof(struct __C(bpf_prog_info), jited_line_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_line_info_rec_size 176 __builtin_offsetof(struct __C(bpf_prog_info), jited_line_info_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_prog_insns 24 __builtin_offsetof(struct __C(bpf_prog_info), jited_prog_insns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_jited_prog_len 16 __builtin_offsetof(struct __C(bpf_prog_info), jited_prog_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_line_info 152 __builtin_offsetof(struct __C(bpf_prog_info), line_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_line_info_rec_size 172 __builtin_offsetof(struct __C(bpf_prog_info), line_info_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_load_time 40 __builtin_offsetof(struct __C(bpf_prog_info), load_time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_map_ids 56 __builtin_offsetof(struct __C(bpf_prog_info), map_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_name 64 __builtin_offsetof(struct __C(bpf_prog_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_netns_dev 88 __builtin_offsetof(struct __C(bpf_prog_info), netns_dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_netns_ino 96 __builtin_offsetof(struct __C(bpf_prog_info), netns_ino)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_func_info 144 __builtin_offsetof(struct __C(bpf_prog_info), nr_func_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_jited_func_lens 108 __builtin_offsetof(struct __C(bpf_prog_info), nr_jited_func_lens)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_jited_ksyms 104 __builtin_offsetof(struct __C(bpf_prog_info), nr_jited_ksyms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_jited_line_info 168 __builtin_offsetof(struct __C(bpf_prog_info), nr_jited_line_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_line_info 148 __builtin_offsetof(struct __C(bpf_prog_info), nr_line_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_map_ids 52 __builtin_offsetof(struct __C(bpf_prog_info), nr_map_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_nr_prog_tags 180 __builtin_offsetof(struct __C(bpf_prog_info), nr_prog_tags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_prog_tags 184 __builtin_offsetof(struct __C(bpf_prog_info), prog_tags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_recursion_misses 208 __builtin_offsetof(struct __C(bpf_prog_info), recursion_misses)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_run_cnt 200 __builtin_offsetof(struct __C(bpf_prog_info), run_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_run_time_ns 192 __builtin_offsetof(struct __C(bpf_prog_info), run_time_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_tag 8 __builtin_offsetof(struct __C(bpf_prog_info), tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_type 0 __builtin_offsetof(struct __C(bpf_prog_info), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_verified_insns 216 __builtin_offsetof(struct __C(bpf_prog_info), verified_insns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_xlated_prog_insns 32 __builtin_offsetof(struct __C(bpf_prog_info), xlated_prog_insns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_prog_info_xlated_prog_len 20 __builtin_offsetof(struct __C(bpf_prog_info), xlated_prog_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btf_ptr 16 sizeof(struct __C(btf_ptr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btf_ptr 8 __alignof(struct __C(btf_ptr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btf_ptr_flags 12 __builtin_offsetof(struct __C(btf_ptr), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btf_ptr_ptr 0 __builtin_offsetof(struct __C(btf_ptr), ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btf_ptr_type_id 8 __builtin_offsetof(struct __C(btf_ptr), type_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_encoded_io_args 128 sizeof(struct __C(btrfs_ioctl_encoded_io_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_encoded_io_args 8 __alignof(struct __C(btrfs_ioctl_encoded_io_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_compression 56 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), compression)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_encryption 60 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), encryption)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_flags 24 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_iov 0 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), iov)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_iovcnt 8 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), iovcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_len 32 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_offset 16 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_reserved 64 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_unencoded_len 40 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), unencoded_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_encoded_io_args_unencoded_offset 48 __builtin_offsetof(struct __C(btrfs_ioctl_encoded_io_args), unencoded_offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_ino_path_args 56 sizeof(struct __C(btrfs_ioctl_ino_path_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_ino_path_args 8 __alignof(struct __C(btrfs_ioctl_ino_path_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_ino_path_args_fspath 48 __builtin_offsetof(struct __C(btrfs_ioctl_ino_path_args), fspath)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_ino_path_args_inum 0 __builtin_offsetof(struct __C(btrfs_ioctl_ino_path_args), inum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_ino_path_args_reserved 16 __builtin_offsetof(struct __C(btrfs_ioctl_ino_path_args), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_ino_path_args_size 8 __builtin_offsetof(struct __C(btrfs_ioctl_ino_path_args), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_logical_ino_args 56 sizeof(struct __C(btrfs_ioctl_logical_ino_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_logical_ino_args 8 __alignof(struct __C(btrfs_ioctl_logical_ino_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_logical_ino_args_flags 40 __builtin_offsetof(struct __C(btrfs_ioctl_logical_ino_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_logical_ino_args_inodes 48 __builtin_offsetof(struct __C(btrfs_ioctl_logical_ino_args), inodes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_logical_ino_args_logical 0 __builtin_offsetof(struct __C(btrfs_ioctl_logical_ino_args), logical)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_logical_ino_args_reserved 16 __builtin_offsetof(struct __C(btrfs_ioctl_logical_ino_args), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_logical_ino_args_size 8 __builtin_offsetof(struct __C(btrfs_ioctl_logical_ino_args), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_scrub_args 1024 sizeof(struct __C(btrfs_ioctl_scrub_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_scrub_args 8 __alignof(struct __C(btrfs_ioctl_scrub_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_devid 0 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), devid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_end 16 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_flags 24 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress 32 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_corrected_errors 128 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.corrected_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_csum_discards 96 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.csum_discards)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_csum_errors 72 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.csum_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_data_bytes_scrubbed 48 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.data_bytes_scrubbed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_data_extents_scrubbed 32 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.data_extents_scrubbed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_last_physical 136 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.last_physical)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_malloc_errors 112 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.malloc_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_no_csum 88 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.no_csum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_read_errors 64 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.read_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_super_errors 104 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.super_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_tree_bytes_scrubbed 56 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.tree_bytes_scrubbed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_tree_extents_scrubbed 40 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.tree_extents_scrubbed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_uncorrectable_errors 120 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.uncorrectable_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_unverified_errors 144 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.unverified_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_progress_verify_errors 80 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), progress.verify_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_start 8 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_scrub_args_unused 152 __builtin_offsetof(struct __C(btrfs_ioctl_scrub_args), unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_search_args 4096 sizeof(struct __C(btrfs_ioctl_search_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_search_args 8 __alignof(struct __C(btrfs_ioctl_search_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_buf 104 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key 0 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_max_objectid 16 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.max_objectid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_max_offset 32 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.max_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_max_transid 48 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.max_transid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_max_type 60 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.max_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_min_objectid 8 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.min_objectid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_min_offset 24 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.min_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_min_transid 40 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.min_transid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_min_type 56 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.min_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_nr_items 64 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.nr_items)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_tree_id 0 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.tree_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_unused 68 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_unused1 72 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.unused1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_unused2 80 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_unused3 88 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.unused3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_search_args_key_unused4 96 __builtin_offsetof(struct __C(btrfs_ioctl_search_args), key.unused4)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_send_args 72 sizeof(struct __C(btrfs_ioctl_send_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_send_args 8 __alignof(struct __C(btrfs_ioctl_send_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_clone_sources 16 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), clone_sources)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_clone_sources_count 8 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), clone_sources_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_flags 32 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_parent_root 24 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), parent_root)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_reserved 44 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_send_fd 0 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), send_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_send_args_version 40 __builtin_offsetof(struct __C(btrfs_ioctl_send_args), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_btrfs_ioctl_vol_args_v2 4096 sizeof(struct __C(btrfs_ioctl_vol_args_v2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_btrfs_ioctl_vol_args_v2 8 __alignof(struct __C(btrfs_ioctl_vol_args_v2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_devid 56 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), devid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_fd 0 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_flags 16 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_name 56 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_qgroup_inherit 32 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), qgroup_inherit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_size 24 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_subvolid 56 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), subvolid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_transid 8 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), transid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_btrfs_ioctl_vol_args_v2_unused 24 __builtin_offsetof(struct __C(btrfs_ioctl_vol_args_v2), unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_buffmem_desc 16 sizeof(struct __C(buffmem_desc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_buffmem_desc 8 __alignof(struct __C(buffmem_desc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_buffmem_desc_buffer 0 __builtin_offsetof(struct __C(buffmem_desc), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_buffmem_desc_size 8 __builtin_offsetof(struct __C(buffmem_desc), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_cdrom_generic_command 64 sizeof(struct __C(cdrom_generic_command))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_cdrom_generic_command 8 __alignof(struct __C(cdrom_generic_command))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_buffer 16 __builtin_offsetof(struct __C(cdrom_generic_command), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_buflen 24 __builtin_offsetof(struct __C(cdrom_generic_command), buflen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_cmd 0 __builtin_offsetof(struct __C(cdrom_generic_command), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_data_direction 40 __builtin_offsetof(struct __C(cdrom_generic_command), data_direction)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_quiet 44 __builtin_offsetof(struct __C(cdrom_generic_command), quiet)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_sense 32 __builtin_offsetof(struct __C(cdrom_generic_command), sense)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_stat 28 __builtin_offsetof(struct __C(cdrom_generic_command), stat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_timeout 48 __builtin_offsetof(struct __C(cdrom_generic_command), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_generic_command_unused 56 __builtin_offsetof(struct __C(cdrom_generic_command), unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_cdrom_read 24 sizeof(struct __C(cdrom_read))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_cdrom_read 8 __alignof(struct __C(cdrom_read))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_cdread_bufaddr 8 __builtin_offsetof(struct __C(cdrom_read), cdread_bufaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_cdread_buflen 16 __builtin_offsetof(struct __C(cdrom_read), cdread_buflen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_cdread_lba 0 __builtin_offsetof(struct __C(cdrom_read), cdread_lba)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_cdrom_read_audio 24 sizeof(struct __C(cdrom_read_audio))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_cdrom_read_audio 8 __alignof(struct __C(cdrom_read_audio))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr 0 __builtin_offsetof(struct __C(cdrom_read_audio), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_lba 0 __builtin_offsetof(struct __C(cdrom_read_audio), addr.lba)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_msf 0 __builtin_offsetof(struct __C(cdrom_read_audio), addr.msf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_msf_frame 2 __builtin_offsetof(struct __C(cdrom_read_audio), addr.msf.frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_msf_minute 0 __builtin_offsetof(struct __C(cdrom_read_audio), addr.msf.minute)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_msf_second 1 __builtin_offsetof(struct __C(cdrom_read_audio), addr.msf.second)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_addr_format 4 __builtin_offsetof(struct __C(cdrom_read_audio), addr_format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_buf 16 __builtin_offsetof(struct __C(cdrom_read_audio), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cdrom_read_audio_nframes 8 __builtin_offsetof(struct __C(cdrom_read_audio), nframes)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_changer_element_status 16 sizeof(struct __C(changer_element_status))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_changer_element_status 8 __alignof(struct __C(changer_element_status))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_changer_element_status_ces_data 8 __builtin_offsetof(struct __C(changer_element_status), ces_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_changer_element_status_ces_type 0 __builtin_offsetof(struct __C(changer_element_status), ces_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_clone_args 88 sizeof(struct __C(clone_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_clone_args 8 __alignof(struct __C(clone_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_cgroup 80 __builtin_offsetof(struct __C(clone_args), cgroup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_child_tid 16 __builtin_offsetof(struct __C(clone_args), child_tid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_exit_signal 32 __builtin_offsetof(struct __C(clone_args), exit_signal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_flags 0 __builtin_offsetof(struct __C(clone_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_parent_tid 24 __builtin_offsetof(struct __C(clone_args), parent_tid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_pidfd 8 __builtin_offsetof(struct __C(clone_args), pidfd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_set_tid 64 __builtin_offsetof(struct __C(clone_args), set_tid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_set_tid_size 72 __builtin_offsetof(struct __C(clone_args), set_tid_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_stack 40 __builtin_offsetof(struct __C(clone_args), stack)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_stack_size 48 __builtin_offsetof(struct __C(clone_args), stack_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_clone_args_tls 56 __builtin_offsetof(struct __C(clone_args), tls)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_coda_ioctl_in 56 sizeof(struct __C(coda_ioctl_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_coda_ioctl_in 8 __alignof(struct __C(coda_ioctl_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_VFid 20 __builtin_offsetof(struct __C(coda_ioctl_in), VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_VFid_opaque 20 __builtin_offsetof(struct __C(coda_ioctl_in), VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_cmd 36 __builtin_offsetof(struct __C(coda_ioctl_in), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_data 48 __builtin_offsetof(struct __C(coda_ioctl_in), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih 0 __builtin_offsetof(struct __C(coda_ioctl_in), ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih_opcode 0 __builtin_offsetof(struct __C(coda_ioctl_in), ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih_pgid 12 __builtin_offsetof(struct __C(coda_ioctl_in), ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih_pid 8 __builtin_offsetof(struct __C(coda_ioctl_in), ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih_uid 16 __builtin_offsetof(struct __C(coda_ioctl_in), ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_ih_unique 4 __builtin_offsetof(struct __C(coda_ioctl_in), ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_len 40 __builtin_offsetof(struct __C(coda_ioctl_in), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_in_rwflag 44 __builtin_offsetof(struct __C(coda_ioctl_in), rwflag)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_coda_ioctl_out 24 sizeof(struct __C(coda_ioctl_out))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_coda_ioctl_out 8 __alignof(struct __C(coda_ioctl_out))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_data 16 __builtin_offsetof(struct __C(coda_ioctl_out), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_len 12 __builtin_offsetof(struct __C(coda_ioctl_out), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_oh 0 __builtin_offsetof(struct __C(coda_ioctl_out), oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_oh_opcode 0 __builtin_offsetof(struct __C(coda_ioctl_out), oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_oh_result 8 __builtin_offsetof(struct __C(coda_ioctl_out), oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_ioctl_out_oh_unique 4 __builtin_offsetof(struct __C(coda_ioctl_out), oh.unique)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_coda_open_by_fd_out 24 sizeof(struct __C(coda_open_by_fd_out))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_coda_open_by_fd_out 8 __alignof(struct __C(coda_open_by_fd_out))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_fd 12 __builtin_offsetof(struct __C(coda_open_by_fd_out), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_fh 16 __builtin_offsetof(struct __C(coda_open_by_fd_out), fh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_oh 0 __builtin_offsetof(struct __C(coda_open_by_fd_out), oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_oh_opcode 0 __builtin_offsetof(struct __C(coda_open_by_fd_out), oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_oh_result 8 __builtin_offsetof(struct __C(coda_open_by_fd_out), oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_open_by_fd_out_oh_unique 4 __builtin_offsetof(struct __C(coda_open_by_fd_out), oh.unique)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_coda_readlink_out 24 sizeof(struct __C(coda_readlink_out))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_coda_readlink_out 8 __alignof(struct __C(coda_readlink_out))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_count 12 __builtin_offsetof(struct __C(coda_readlink_out), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_data 16 __builtin_offsetof(struct __C(coda_readlink_out), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_oh 0 __builtin_offsetof(struct __C(coda_readlink_out), oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_oh_opcode 0 __builtin_offsetof(struct __C(coda_readlink_out), oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_oh_result 8 __builtin_offsetof(struct __C(coda_readlink_out), oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_coda_readlink_out_oh_unique 4 __builtin_offsetof(struct __C(coda_readlink_out), oh.unique)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_comedi_chaninfo 48 sizeof(struct __C(comedi_chaninfo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_comedi_chaninfo 8 __alignof(struct __C(comedi_chaninfo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_chaninfo_flaglist 16 __builtin_offsetof(struct __C(comedi_chaninfo), flaglist)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_chaninfo_maxdata_list 8 __builtin_offsetof(struct __C(comedi_chaninfo), maxdata_list)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_chaninfo_rangelist 24 __builtin_offsetof(struct __C(comedi_chaninfo), rangelist)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_chaninfo_subdev 0 __builtin_offsetof(struct __C(comedi_chaninfo), subdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_chaninfo_unused 32 __builtin_offsetof(struct __C(comedi_chaninfo), unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_comedi_cmd 80 sizeof(struct __C(comedi_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_comedi_cmd 8 __alignof(struct __C(comedi_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_chanlist 48 __builtin_offsetof(struct __C(comedi_cmd), chanlist)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_chanlist_len 56 __builtin_offsetof(struct __C(comedi_cmd), chanlist_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_convert_arg 28 __builtin_offsetof(struct __C(comedi_cmd), convert_arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_convert_src 24 __builtin_offsetof(struct __C(comedi_cmd), convert_src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_data 64 __builtin_offsetof(struct __C(comedi_cmd), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_data_len 72 __builtin_offsetof(struct __C(comedi_cmd), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_flags 4 __builtin_offsetof(struct __C(comedi_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_scan_begin_arg 20 __builtin_offsetof(struct __C(comedi_cmd), scan_begin_arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_scan_begin_src 16 __builtin_offsetof(struct __C(comedi_cmd), scan_begin_src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_scan_end_arg 36 __builtin_offsetof(struct __C(comedi_cmd), scan_end_arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_scan_end_src 32 __builtin_offsetof(struct __C(comedi_cmd), scan_end_src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_start_arg 12 __builtin_offsetof(struct __C(comedi_cmd), start_arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_start_src 8 __builtin_offsetof(struct __C(comedi_cmd), start_src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_stop_arg 44 __builtin_offsetof(struct __C(comedi_cmd), stop_arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_stop_src 40 __builtin_offsetof(struct __C(comedi_cmd), stop_src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_cmd_subdev 0 __builtin_offsetof(struct __C(comedi_cmd), subdev)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_comedi_insn 40 sizeof(struct __C(comedi_insn))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_comedi_insn 8 __alignof(struct __C(comedi_insn))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_chanspec 20 __builtin_offsetof(struct __C(comedi_insn), chanspec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_data 8 __builtin_offsetof(struct __C(comedi_insn), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_insn 0 __builtin_offsetof(struct __C(comedi_insn), insn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_n 4 __builtin_offsetof(struct __C(comedi_insn), n)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_subdev 16 __builtin_offsetof(struct __C(comedi_insn), subdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insn_unused 24 __builtin_offsetof(struct __C(comedi_insn), unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_comedi_insnlist 16 sizeof(struct __C(comedi_insnlist))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_comedi_insnlist 8 __alignof(struct __C(comedi_insnlist))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insnlist_insns 8 __builtin_offsetof(struct __C(comedi_insnlist), insns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_insnlist_n_insns 0 __builtin_offsetof(struct __C(comedi_insnlist), n_insns)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_comedi_rangeinfo 16 sizeof(struct __C(comedi_rangeinfo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_comedi_rangeinfo 8 __alignof(struct __C(comedi_rangeinfo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_rangeinfo_range_ptr 8 __builtin_offsetof(struct __C(comedi_rangeinfo), range_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_comedi_rangeinfo_range_type 0 __builtin_offsetof(struct __C(comedi_rangeinfo), range_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_console_font 24 sizeof(struct __C(console_font))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_console_font 8 __alignof(struct __C(console_font))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_charcount 8 __builtin_offsetof(struct __C(console_font), charcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_data 16 __builtin_offsetof(struct __C(console_font), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_height 4 __builtin_offsetof(struct __C(console_font), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_width 0 __builtin_offsetof(struct __C(console_font), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_console_font_op 32 sizeof(struct __C(console_font_op))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_console_font_op 8 __alignof(struct __C(console_font_op))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_charcount 16 __builtin_offsetof(struct __C(console_font_op), charcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_data 24 __builtin_offsetof(struct __C(console_font_op), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_flags 4 __builtin_offsetof(struct __C(console_font_op), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_height 12 __builtin_offsetof(struct __C(console_font_op), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_op 0 __builtin_offsetof(struct __C(console_font_op), op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_console_font_op_width 8 __builtin_offsetof(struct __C(console_font_op), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_consolefontdesc 16 sizeof(struct __C(consolefontdesc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_consolefontdesc 8 __alignof(struct __C(consolefontdesc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_consolefontdesc_charcount 0 __builtin_offsetof(struct __C(consolefontdesc), charcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_consolefontdesc_chardata 8 __builtin_offsetof(struct __C(consolefontdesc), chardata)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_consolefontdesc_charheight 2 __builtin_offsetof(struct __C(consolefontdesc), charheight)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_cxl_send_command 48 sizeof(struct __C(cxl_send_command))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_cxl_send_command 8 __alignof(struct __C(cxl_send_command))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_flags 4 __builtin_offsetof(struct __C(cxl_send_command), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_id 0 __builtin_offsetof(struct __C(cxl_send_command), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_in 16 __builtin_offsetof(struct __C(cxl_send_command), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_in_payload 24 __builtin_offsetof(struct __C(cxl_send_command), in.payload)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_in_rsvd 20 __builtin_offsetof(struct __C(cxl_send_command), in.rsvd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_in_size 16 __builtin_offsetof(struct __C(cxl_send_command), in.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_out 32 __builtin_offsetof(struct __C(cxl_send_command), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_out_payload 40 __builtin_offsetof(struct __C(cxl_send_command), out.payload)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_out_rsvd 36 __builtin_offsetof(struct __C(cxl_send_command), out.rsvd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_out_size 32 __builtin_offsetof(struct __C(cxl_send_command), out.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_raw 8 __builtin_offsetof(struct __C(cxl_send_command), raw)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_raw_opcode 8 __builtin_offsetof(struct __C(cxl_send_command), raw.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_raw_rsvd 10 __builtin_offsetof(struct __C(cxl_send_command), raw.rsvd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_retval 12 __builtin_offsetof(struct __C(cxl_send_command), retval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_cxl_send_command_rsvd 8 __builtin_offsetof(struct __C(cxl_send_command), rsvd)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dlm_lksb 24 sizeof(struct __C(dlm_lksb))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dlm_lksb 8 __alignof(struct __C(dlm_lksb))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lksb_sb_flags 8 __builtin_offsetof(struct __C(dlm_lksb), sb_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lksb_sb_lkid 4 __builtin_offsetof(struct __C(dlm_lksb), sb_lkid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lksb_sb_lvbptr 16 __builtin_offsetof(struct __C(dlm_lksb), sb_lvbptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lksb_sb_status 0 __builtin_offsetof(struct __C(dlm_lksb), sb_status)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dlm_lock_params 104 sizeof(struct __C(dlm_lock_params))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dlm_lock_params 8 __alignof(struct __C(dlm_lock_params))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_bastaddr 56 __builtin_offsetof(struct __C(dlm_lock_params), bastaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_bastparam 48 __builtin_offsetof(struct __C(dlm_lock_params), bastparam)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_castaddr 40 __builtin_offsetof(struct __C(dlm_lock_params), castaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_castparam 32 __builtin_offsetof(struct __C(dlm_lock_params), castparam)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_flags 4 __builtin_offsetof(struct __C(dlm_lock_params), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_lkid 8 __builtin_offsetof(struct __C(dlm_lock_params), lkid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_lksb 64 __builtin_offsetof(struct __C(dlm_lock_params), lksb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_lvb 72 __builtin_offsetof(struct __C(dlm_lock_params), lvb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_mode 0 __builtin_offsetof(struct __C(dlm_lock_params), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_name 104 __builtin_offsetof(struct __C(dlm_lock_params), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_namelen 1 __builtin_offsetof(struct __C(dlm_lock_params), namelen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_parent 12 __builtin_offsetof(struct __C(dlm_lock_params), parent)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_timeout 24 __builtin_offsetof(struct __C(dlm_lock_params), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_unused 2 __builtin_offsetof(struct __C(dlm_lock_params), unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_params_xid 16 __builtin_offsetof(struct __C(dlm_lock_params), xid)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dlm_lock_result 72 sizeof(struct __C(dlm_lock_result))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dlm_lock_result 8 __alignof(struct __C(dlm_lock_result))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_bast_mode 64 __builtin_offsetof(struct __C(dlm_lock_result), bast_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_length 12 __builtin_offsetof(struct __C(dlm_lock_result), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lksb 40 __builtin_offsetof(struct __C(dlm_lock_result), lksb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lksb_sb_flags 48 __builtin_offsetof(struct __C(dlm_lock_result), lksb.sb_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lksb_sb_lkid 44 __builtin_offsetof(struct __C(dlm_lock_result), lksb.sb_lkid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lksb_sb_lvbptr 56 __builtin_offsetof(struct __C(dlm_lock_result), lksb.sb_lvbptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lksb_sb_status 40 __builtin_offsetof(struct __C(dlm_lock_result), lksb.sb_status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_lvb_offset 68 __builtin_offsetof(struct __C(dlm_lock_result), lvb_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_unused 65 __builtin_offsetof(struct __C(dlm_lock_result), unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_user_astaddr 16 __builtin_offsetof(struct __C(dlm_lock_result), user_astaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_user_astparam 24 __builtin_offsetof(struct __C(dlm_lock_result), user_astparam)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_user_lksb 32 __builtin_offsetof(struct __C(dlm_lock_result), user_lksb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_lock_result_version 0 __builtin_offsetof(struct __C(dlm_lock_result), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dlm_write_request 120 sizeof(struct __C(dlm_write_request))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dlm_write_request 8 __alignof(struct __C(dlm_write_request))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_cmd 12 __builtin_offsetof(struct __C(dlm_write_request), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i 16 __builtin_offsetof(struct __C(dlm_write_request), i)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock 16 __builtin_offsetof(struct __C(dlm_write_request), i.lock)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_bastaddr 72 __builtin_offsetof(struct __C(dlm_write_request), i.lock.bastaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_bastparam 64 __builtin_offsetof(struct __C(dlm_write_request), i.lock.bastparam)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_castaddr 56 __builtin_offsetof(struct __C(dlm_write_request), i.lock.castaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_castparam 48 __builtin_offsetof(struct __C(dlm_write_request), i.lock.castparam)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_flags 20 __builtin_offsetof(struct __C(dlm_write_request), i.lock.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_lkid 24 __builtin_offsetof(struct __C(dlm_write_request), i.lock.lkid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_lksb 80 __builtin_offsetof(struct __C(dlm_write_request), i.lock.lksb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_lvb 88 __builtin_offsetof(struct __C(dlm_write_request), i.lock.lvb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_mode 16 __builtin_offsetof(struct __C(dlm_write_request), i.lock.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_name 120 __builtin_offsetof(struct __C(dlm_write_request), i.lock.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_namelen 17 __builtin_offsetof(struct __C(dlm_write_request), i.lock.namelen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_parent 28 __builtin_offsetof(struct __C(dlm_write_request), i.lock.parent)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_timeout 40 __builtin_offsetof(struct __C(dlm_write_request), i.lock.timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_unused 18 __builtin_offsetof(struct __C(dlm_write_request), i.lock.unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lock_xid 32 __builtin_offsetof(struct __C(dlm_write_request), i.lock.xid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lspace 16 __builtin_offsetof(struct __C(dlm_write_request), i.lspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lspace_flags 16 __builtin_offsetof(struct __C(dlm_write_request), i.lspace.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lspace_minor 20 __builtin_offsetof(struct __C(dlm_write_request), i.lspace.minor)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_lspace_name 24 __builtin_offsetof(struct __C(dlm_write_request), i.lspace.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_purge 16 __builtin_offsetof(struct __C(dlm_write_request), i.purge)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_purge_nodeid 16 __builtin_offsetof(struct __C(dlm_write_request), i.purge.nodeid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_i_purge_pid 20 __builtin_offsetof(struct __C(dlm_write_request), i.purge.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_is64bit 13 __builtin_offsetof(struct __C(dlm_write_request), is64bit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_unused 14 __builtin_offsetof(struct __C(dlm_write_request), unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dlm_write_request_version 0 __builtin_offsetof(struct __C(dlm_write_request), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_bo_list_in 24 sizeof(struct __C(drm_amdgpu_bo_list_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_bo_list_in 8 __alignof(struct __C(drm_amdgpu_bo_list_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_info_ptr 16 __builtin_offsetof(struct __C(drm_amdgpu_bo_list_in), bo_info_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_info_size 12 __builtin_offsetof(struct __C(drm_amdgpu_bo_list_in), bo_info_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_number 8 __builtin_offsetof(struct __C(drm_amdgpu_bo_list_in), bo_number)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_list_handle 4 __builtin_offsetof(struct __C(drm_amdgpu_bo_list_in), list_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_operation 0 __builtin_offsetof(struct __C(drm_amdgpu_bo_list_in), operation)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_cs_chunk 16 sizeof(struct __C(drm_amdgpu_cs_chunk))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_cs_chunk 8 __alignof(struct __C(drm_amdgpu_cs_chunk))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_chunk_chunk_data 8 __builtin_offsetof(struct __C(drm_amdgpu_cs_chunk), chunk_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_chunk_chunk_id 0 __builtin_offsetof(struct __C(drm_amdgpu_cs_chunk), chunk_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_chunk_length_dw 4 __builtin_offsetof(struct __C(drm_amdgpu_cs_chunk), length_dw)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_cs_in 24 sizeof(struct __C(drm_amdgpu_cs_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_cs_in 8 __alignof(struct __C(drm_amdgpu_cs_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_bo_list_handle 4 __builtin_offsetof(struct __C(drm_amdgpu_cs_in), bo_list_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_chunks 16 __builtin_offsetof(struct __C(drm_amdgpu_cs_in), chunks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_ctx_id 0 __builtin_offsetof(struct __C(drm_amdgpu_cs_in), ctx_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_flags 12 __builtin_offsetof(struct __C(drm_amdgpu_cs_in), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_num_chunks 8 __builtin_offsetof(struct __C(drm_amdgpu_cs_in), num_chunks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_gem_op 16 sizeof(struct __C(drm_amdgpu_gem_op))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_gem_op 8 __alignof(struct __C(drm_amdgpu_gem_op))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_op_handle 0 __builtin_offsetof(struct __C(drm_amdgpu_gem_op), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_op_op 4 __builtin_offsetof(struct __C(drm_amdgpu_gem_op), op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_op_value 8 __builtin_offsetof(struct __C(drm_amdgpu_gem_op), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_gem_va 64 sizeof(struct __C(drm_amdgpu_gem_va))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_gem_va 8 __alignof(struct __C(drm_amdgpu_gem_va))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va__pad 4 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), _pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_flags 12 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_handle 0 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_input_fence_syncobj_handles 56 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), input_fence_syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_map_size 32 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), map_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_num_syncobj_handles 52 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), num_syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_offset_in_bo 24 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), offset_in_bo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_operation 8 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), operation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_va_address 16 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), va_address)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_vm_timeline_point 40 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), vm_timeline_point)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_gem_va_vm_timeline_syncobj_out 48 __builtin_offsetof(struct __C(drm_amdgpu_gem_va), vm_timeline_syncobj_out)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_info 32 sizeof(struct __C(drm_amdgpu_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_info 8 __alignof(struct __C(drm_amdgpu_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_mode_crtc 16 __builtin_offsetof(struct __C(drm_amdgpu_info), mode_crtc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_mode_crtc__pad 20 __builtin_offsetof(struct __C(drm_amdgpu_info), mode_crtc._pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_mode_crtc_id 16 __builtin_offsetof(struct __C(drm_amdgpu_info), mode_crtc.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query 12 __builtin_offsetof(struct __C(drm_amdgpu_info), query)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_fw 16 __builtin_offsetof(struct __C(drm_amdgpu_info), query_fw)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_fw__pad 28 __builtin_offsetof(struct __C(drm_amdgpu_info), query_fw._pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_fw_fw_type 16 __builtin_offsetof(struct __C(drm_amdgpu_info), query_fw.fw_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_fw_index 24 __builtin_offsetof(struct __C(drm_amdgpu_info), query_fw.index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_fw_ip_instance 20 __builtin_offsetof(struct __C(drm_amdgpu_info), query_fw.ip_instance)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_hw_ip 16 __builtin_offsetof(struct __C(drm_amdgpu_info), query_hw_ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_hw_ip_ip_instance 20 __builtin_offsetof(struct __C(drm_amdgpu_info), query_hw_ip.ip_instance)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_query_hw_ip_type 16 __builtin_offsetof(struct __C(drm_amdgpu_info), query_hw_ip.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_read_mmr_reg 16 __builtin_offsetof(struct __C(drm_amdgpu_info), read_mmr_reg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_read_mmr_reg_count 20 __builtin_offsetof(struct __C(drm_amdgpu_info), read_mmr_reg.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_read_mmr_reg_dword_offset 16 __builtin_offsetof(struct __C(drm_amdgpu_info), read_mmr_reg.dword_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_read_mmr_reg_flags 28 __builtin_offsetof(struct __C(drm_amdgpu_info), read_mmr_reg.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_read_mmr_reg_instance 24 __builtin_offsetof(struct __C(drm_amdgpu_info), read_mmr_reg.instance)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_return_pointer 0 __builtin_offsetof(struct __C(drm_amdgpu_info), return_pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_return_size 8 __builtin_offsetof(struct __C(drm_amdgpu_info), return_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_sensor_info 16 __builtin_offsetof(struct __C(drm_amdgpu_info), sensor_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_sensor_info_type 16 __builtin_offsetof(struct __C(drm_amdgpu_info), sensor_info.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_vbios_info 16 __builtin_offsetof(struct __C(drm_amdgpu_info), vbios_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_vbios_info_offset 20 __builtin_offsetof(struct __C(drm_amdgpu_info), vbios_info.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_vbios_info_type 16 __builtin_offsetof(struct __C(drm_amdgpu_info), vbios_info.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_video_cap 16 __builtin_offsetof(struct __C(drm_amdgpu_info), video_cap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_info_video_cap_type 16 __builtin_offsetof(struct __C(drm_amdgpu_info), video_cap.type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_userq_in 72 sizeof(struct __C(drm_amdgpu_userq_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_userq_in 8 __alignof(struct __C(drm_amdgpu_userq_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_doorbell_handle 12 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), doorbell_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_doorbell_offset 16 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), doorbell_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_flags 20 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_ip_type 8 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), ip_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_mqd 56 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), mqd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_mqd_size 64 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), mqd_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_op 0 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_id 4 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_size 32 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), queue_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_va 24 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), queue_va)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_rptr_va 40 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), rptr_va)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_wptr_va 48 __builtin_offsetof(struct __C(drm_amdgpu_userq_in), wptr_va)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_userq_signal 48 sizeof(struct __C(drm_amdgpu_userq_signal))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_userq_signal 8 __alignof(struct __C(drm_amdgpu_userq_signal))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_bo_read_handles 24 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), bo_read_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_bo_write_handles 32 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), bo_write_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_num_bo_read_handles 40 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), num_bo_read_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_num_bo_write_handles 44 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), num_bo_write_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_num_syncobj_handles 16 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), num_syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_pad 4 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_queue_id 0 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_signal_syncobj_handles 8 __builtin_offsetof(struct __C(drm_amdgpu_userq_signal), syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_userq_wait 72 sizeof(struct __C(drm_amdgpu_userq_wait))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_userq_wait 8 __alignof(struct __C(drm_amdgpu_userq_wait))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_bo_read_handles 32 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), bo_read_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_bo_write_handles 40 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), bo_write_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_num_bo_read_handles 56 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), num_bo_read_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_num_bo_write_handles 60 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), num_bo_write_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_num_fences 50 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), num_fences)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_num_syncobj_handles 52 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), num_syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_num_syncobj_timeline_handles 48 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), num_syncobj_timeline_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_out_fences 64 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), out_fences)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_pad 4 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_syncobj_handles 8 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), syncobj_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_syncobj_timeline_handles 16 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), syncobj_timeline_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_syncobj_timeline_points 24 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), syncobj_timeline_points)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_wait_waitq_id 0 __builtin_offsetof(struct __C(drm_amdgpu_userq_wait), waitq_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_amdgpu_wait_fences_in 24 sizeof(struct __C(drm_amdgpu_wait_fences_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_amdgpu_wait_fences_in 8 __alignof(struct __C(drm_amdgpu_wait_fences_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_fence_count 8 __builtin_offsetof(struct __C(drm_amdgpu_wait_fences_in), fence_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_fences 0 __builtin_offsetof(struct __C(drm_amdgpu_wait_fences_in), fences)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_timeout_ns 16 __builtin_offsetof(struct __C(drm_amdgpu_wait_fences_in), timeout_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_wait_all 12 __builtin_offsetof(struct __C(drm_amdgpu_wait_fences_in), wait_all)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_buf_free 16 sizeof(struct __C(drm_buf_free))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_buf_free 8 __alignof(struct __C(drm_buf_free))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_free_count 0 __builtin_offsetof(struct __C(drm_buf_free), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_free_list 8 __builtin_offsetof(struct __C(drm_buf_free), list)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_buf_info 16 sizeof(struct __C(drm_buf_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_buf_info 8 __alignof(struct __C(drm_buf_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_info_count 0 __builtin_offsetof(struct __C(drm_buf_info), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_info_list 8 __builtin_offsetof(struct __C(drm_buf_info), list)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_buf_map 24 sizeof(struct __C(drm_buf_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_buf_map 8 __alignof(struct __C(drm_buf_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_map_count 0 __builtin_offsetof(struct __C(drm_buf_map), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_map_list 16 __builtin_offsetof(struct __C(drm_buf_map), list)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_map_virtual 8 __builtin_offsetof(struct __C(drm_buf_map), virtual)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_buf_pub 24 sizeof(struct __C(drm_buf_pub))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_buf_pub 8 __alignof(struct __C(drm_buf_pub))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_pub_address 16 __builtin_offsetof(struct __C(drm_buf_pub), address)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_pub_idx 0 __builtin_offsetof(struct __C(drm_buf_pub), idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_pub_total 4 __builtin_offsetof(struct __C(drm_buf_pub), total)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_buf_pub_used 8 __builtin_offsetof(struct __C(drm_buf_pub), used)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_crtc_queue_sequence 24 sizeof(struct __C(drm_crtc_queue_sequence))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_crtc_queue_sequence 8 __alignof(struct __C(drm_crtc_queue_sequence))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_crtc_queue_sequence_crtc_id 0 __builtin_offsetof(struct __C(drm_crtc_queue_sequence), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_crtc_queue_sequence_flags 4 __builtin_offsetof(struct __C(drm_crtc_queue_sequence), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_crtc_queue_sequence_sequence 8 __builtin_offsetof(struct __C(drm_crtc_queue_sequence), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_crtc_queue_sequence_user_data 16 __builtin_offsetof(struct __C(drm_crtc_queue_sequence), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_ctx_priv_map 16 sizeof(struct __C(drm_ctx_priv_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_ctx_priv_map 8 __alignof(struct __C(drm_ctx_priv_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_ctx_priv_map_ctx_id 0 __builtin_offsetof(struct __C(drm_ctx_priv_map), ctx_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_ctx_priv_map_handle 8 __builtin_offsetof(struct __C(drm_ctx_priv_map), handle)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_ctx_res 16 sizeof(struct __C(drm_ctx_res))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_ctx_res 8 __alignof(struct __C(drm_ctx_res))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_ctx_res_contexts 8 __builtin_offsetof(struct __C(drm_ctx_res), contexts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_ctx_res_count 0 __builtin_offsetof(struct __C(drm_ctx_res), count)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_dma 64 sizeof(struct __C(drm_dma))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_dma 8 __alignof(struct __C(drm_dma))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_context 0 __builtin_offsetof(struct __C(drm_dma), context)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_flags 24 __builtin_offsetof(struct __C(drm_dma), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_granted_count 56 __builtin_offsetof(struct __C(drm_dma), granted_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_request_count 28 __builtin_offsetof(struct __C(drm_dma), request_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_request_indices 40 __builtin_offsetof(struct __C(drm_dma), request_indices)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_request_size 32 __builtin_offsetof(struct __C(drm_dma), request_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_request_sizes 48 __builtin_offsetof(struct __C(drm_dma), request_sizes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_send_count 4 __builtin_offsetof(struct __C(drm_dma), send_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_send_indices 8 __builtin_offsetof(struct __C(drm_dma), send_indices)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_dma_send_sizes 16 __builtin_offsetof(struct __C(drm_dma), send_sizes)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_drawable_info 16 sizeof(struct __C(drm_drawable_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_drawable_info 8 __alignof(struct __C(drm_drawable_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_drawable_info_num_rects 0 __builtin_offsetof(struct __C(drm_drawable_info), num_rects)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_drawable_info_rects 8 __builtin_offsetof(struct __C(drm_drawable_info), rects)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_etnaviv_gem_submit 72 sizeof(struct __C(drm_etnaviv_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_etnaviv_gem_submit 8 __alignof(struct __C(drm_etnaviv_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_bos 24 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_exec_state 8 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), exec_state)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_fence 0 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), fence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_fence_fd 52 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), fence_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_flags 48 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_nr_bos 12 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), nr_bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_nr_pmrs 64 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), nr_pmrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_nr_relocs 16 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), nr_relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_pad 68 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_pipe 4 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), pipe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_pmrs 56 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), pmrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_relocs 32 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_stream 40 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), stream)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_submit_stream_size 20 __builtin_offsetof(struct __C(drm_etnaviv_gem_submit), stream_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_etnaviv_gem_userptr 24 sizeof(struct __C(drm_etnaviv_gem_userptr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_etnaviv_gem_userptr 8 __alignof(struct __C(drm_etnaviv_gem_userptr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_userptr_flags 16 __builtin_offsetof(struct __C(drm_etnaviv_gem_userptr), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_userptr_handle 20 __builtin_offsetof(struct __C(drm_etnaviv_gem_userptr), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_userptr_user_ptr 0 __builtin_offsetof(struct __C(drm_etnaviv_gem_userptr), user_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_etnaviv_gem_userptr_user_size 8 __builtin_offsetof(struct __C(drm_etnaviv_gem_userptr), user_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_event_crtc_sequence 32 sizeof(struct __C(drm_event_crtc_sequence))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_event_crtc_sequence 8 __alignof(struct __C(drm_event_crtc_sequence))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_base 0 __builtin_offsetof(struct __C(drm_event_crtc_sequence), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_base_length 4 __builtin_offsetof(struct __C(drm_event_crtc_sequence), base.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_base_type 0 __builtin_offsetof(struct __C(drm_event_crtc_sequence), base.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_sequence 24 __builtin_offsetof(struct __C(drm_event_crtc_sequence), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_time_ns 16 __builtin_offsetof(struct __C(drm_event_crtc_sequence), time_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_crtc_sequence_user_data 8 __builtin_offsetof(struct __C(drm_event_crtc_sequence), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_event_vblank 32 sizeof(struct __C(drm_event_vblank))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_event_vblank 8 __alignof(struct __C(drm_event_vblank))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_base 0 __builtin_offsetof(struct __C(drm_event_vblank), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_base_length 4 __builtin_offsetof(struct __C(drm_event_vblank), base.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_base_type 0 __builtin_offsetof(struct __C(drm_event_vblank), base.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_crtc_id 28 __builtin_offsetof(struct __C(drm_event_vblank), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_sequence 24 __builtin_offsetof(struct __C(drm_event_vblank), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_tv_sec 16 __builtin_offsetof(struct __C(drm_event_vblank), tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_tv_usec 20 __builtin_offsetof(struct __C(drm_event_vblank), tv_usec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_event_vblank_user_data 8 __builtin_offsetof(struct __C(drm_event_vblank), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_exynos_g2d_set_cmdlist 40 sizeof(struct __C(drm_exynos_g2d_set_cmdlist))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_exynos_g2d_set_cmdlist 8 __alignof(struct __C(drm_exynos_g2d_set_cmdlist))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_cmd 0 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_cmd_buf 8 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), cmd_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_cmd_buf_nr 20 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), cmd_buf_nr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_cmd_nr 16 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), cmd_nr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_event_type 24 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), event_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_g2d_set_cmdlist_user_data 32 __builtin_offsetof(struct __C(drm_exynos_g2d_set_cmdlist), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_exynos_ioctl_ipp_commit 32 sizeof(struct __C(drm_exynos_ioctl_ipp_commit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_exynos_ioctl_ipp_commit 8 __alignof(struct __C(drm_exynos_ioctl_ipp_commit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_flags 4 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_ipp_id 0 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), ipp_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_params_ptr 16 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), params_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_params_size 12 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), params_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_reserved 8 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_commit_user_data 24 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_commit), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_exynos_ioctl_ipp_get_caps 24 sizeof(struct __C(drm_exynos_ioctl_ipp_get_caps))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_exynos_ioctl_ipp_get_caps 8 __alignof(struct __C(drm_exynos_ioctl_ipp_get_caps))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_caps_capabilities 4 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_caps), capabilities)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_caps_formats_count 12 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_caps), formats_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_caps_formats_ptr 16 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_caps), formats_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_caps_ipp_id 0 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_caps), ipp_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_caps_reserved 8 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_caps), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_exynos_ioctl_ipp_get_limits 32 sizeof(struct __C(drm_exynos_ioctl_ipp_get_limits))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_exynos_ioctl_ipp_get_limits 8 __alignof(struct __C(drm_exynos_ioctl_ipp_get_limits))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_fourcc 4 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), fourcc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_ipp_id 0 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), ipp_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_limits_count 20 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), limits_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_limits_ptr 24 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), limits_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_modifier 8 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), modifier)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_limits_type 16 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_limits), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_exynos_ioctl_ipp_get_res 16 sizeof(struct __C(drm_exynos_ioctl_ipp_get_res))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_exynos_ioctl_ipp_get_res 8 __alignof(struct __C(drm_exynos_ioctl_ipp_get_res))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_res_count_ipps 0 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_res), count_ipps)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_res_ipp_id_ptr 8 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_res), ipp_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_exynos_ioctl_ipp_get_res_reserved 4 __builtin_offsetof(struct __C(drm_exynos_ioctl_ipp_get_res), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_lima_gem_submit 48 sizeof(struct __C(drm_lima_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_lima_gem_submit 8 __alignof(struct __C(drm_lima_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_bos 16 __builtin_offsetof(struct __C(drm_lima_gem_submit), bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_ctx 0 __builtin_offsetof(struct __C(drm_lima_gem_submit), ctx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_flags 32 __builtin_offsetof(struct __C(drm_lima_gem_submit), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_frame 24 __builtin_offsetof(struct __C(drm_lima_gem_submit), frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_frame_size 12 __builtin_offsetof(struct __C(drm_lima_gem_submit), frame_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_in_sync 40 __builtin_offsetof(struct __C(drm_lima_gem_submit), in_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_nr_bos 8 __builtin_offsetof(struct __C(drm_lima_gem_submit), nr_bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_out_sync 36 __builtin_offsetof(struct __C(drm_lima_gem_submit), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_lima_gem_submit_pipe 4 __builtin_offsetof(struct __C(drm_lima_gem_submit), pipe)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_list 16 sizeof(struct __C(drm_list))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_list 8 __alignof(struct __C(drm_list))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_list_count 0 __builtin_offsetof(struct __C(drm_list), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_list_version 8 __builtin_offsetof(struct __C(drm_list), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_map 40 sizeof(struct __C(drm_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_map 8 __alignof(struct __C(drm_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_flags 20 __builtin_offsetof(struct __C(drm_map), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_handle 24 __builtin_offsetof(struct __C(drm_map), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_mtrr 32 __builtin_offsetof(struct __C(drm_map), mtrr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_offset 0 __builtin_offsetof(struct __C(drm_map), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_size 8 __builtin_offsetof(struct __C(drm_map), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_map_type 16 __builtin_offsetof(struct __C(drm_map), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_atomic 56 sizeof(struct __C(drm_mode_atomic))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_atomic 8 __alignof(struct __C(drm_mode_atomic))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_count_objs 4 __builtin_offsetof(struct __C(drm_mode_atomic), count_objs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_count_props_ptr 16 __builtin_offsetof(struct __C(drm_mode_atomic), count_props_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_flags 0 __builtin_offsetof(struct __C(drm_mode_atomic), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_objs_ptr 8 __builtin_offsetof(struct __C(drm_mode_atomic), objs_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_prop_values_ptr 32 __builtin_offsetof(struct __C(drm_mode_atomic), prop_values_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_props_ptr 24 __builtin_offsetof(struct __C(drm_mode_atomic), props_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_reserved 40 __builtin_offsetof(struct __C(drm_mode_atomic), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_atomic_user_data 48 __builtin_offsetof(struct __C(drm_mode_atomic), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_card_res 64 sizeof(struct __C(drm_mode_card_res))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_card_res 8 __alignof(struct __C(drm_mode_card_res))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_connector_id_ptr 16 __builtin_offsetof(struct __C(drm_mode_card_res), connector_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_count_connectors 40 __builtin_offsetof(struct __C(drm_mode_card_res), count_connectors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_count_crtcs 36 __builtin_offsetof(struct __C(drm_mode_card_res), count_crtcs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_count_encoders 44 __builtin_offsetof(struct __C(drm_mode_card_res), count_encoders)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_count_fbs 32 __builtin_offsetof(struct __C(drm_mode_card_res), count_fbs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_crtc_id_ptr 8 __builtin_offsetof(struct __C(drm_mode_card_res), crtc_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_encoder_id_ptr 24 __builtin_offsetof(struct __C(drm_mode_card_res), encoder_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_fb_id_ptr 0 __builtin_offsetof(struct __C(drm_mode_card_res), fb_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_max_height 60 __builtin_offsetof(struct __C(drm_mode_card_res), max_height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_max_width 52 __builtin_offsetof(struct __C(drm_mode_card_res), max_width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_min_height 56 __builtin_offsetof(struct __C(drm_mode_card_res), min_height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_card_res_min_width 48 __builtin_offsetof(struct __C(drm_mode_card_res), min_width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_create_blob 16 sizeof(struct __C(drm_mode_create_blob))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_create_blob 8 __alignof(struct __C(drm_mode_create_blob))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_blob_blob_id 12 __builtin_offsetof(struct __C(drm_mode_create_blob), blob_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_blob_data 0 __builtin_offsetof(struct __C(drm_mode_create_blob), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_blob_length 8 __builtin_offsetof(struct __C(drm_mode_create_blob), length)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_create_lease 24 sizeof(struct __C(drm_mode_create_lease))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_create_lease 8 __alignof(struct __C(drm_mode_create_lease))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_lease_fd 20 __builtin_offsetof(struct __C(drm_mode_create_lease), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_lease_flags 12 __builtin_offsetof(struct __C(drm_mode_create_lease), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_lease_lessee_id 16 __builtin_offsetof(struct __C(drm_mode_create_lease), lessee_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_lease_object_count 8 __builtin_offsetof(struct __C(drm_mode_create_lease), object_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_create_lease_object_ids 0 __builtin_offsetof(struct __C(drm_mode_create_lease), object_ids)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_crtc 104 sizeof(struct __C(drm_mode_crtc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_crtc 8 __alignof(struct __C(drm_mode_crtc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_count_connectors 8 __builtin_offsetof(struct __C(drm_mode_crtc), count_connectors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_crtc_id 12 __builtin_offsetof(struct __C(drm_mode_crtc), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_fb_id 16 __builtin_offsetof(struct __C(drm_mode_crtc), fb_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_gamma_size 28 __builtin_offsetof(struct __C(drm_mode_crtc), gamma_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode 36 __builtin_offsetof(struct __C(drm_mode_crtc), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_clock 36 __builtin_offsetof(struct __C(drm_mode_crtc), mode.clock)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_flags 64 __builtin_offsetof(struct __C(drm_mode_crtc), mode.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_hdisplay 40 __builtin_offsetof(struct __C(drm_mode_crtc), mode.hdisplay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_hskew 48 __builtin_offsetof(struct __C(drm_mode_crtc), mode.hskew)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_hsync_end 44 __builtin_offsetof(struct __C(drm_mode_crtc), mode.hsync_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_hsync_start 42 __builtin_offsetof(struct __C(drm_mode_crtc), mode.hsync_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_htotal 46 __builtin_offsetof(struct __C(drm_mode_crtc), mode.htotal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_name 72 __builtin_offsetof(struct __C(drm_mode_crtc), mode.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_type 68 __builtin_offsetof(struct __C(drm_mode_crtc), mode.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vdisplay 50 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vdisplay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vrefresh 60 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vrefresh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vscan 58 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vscan)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vsync_end 54 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vsync_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vsync_start 52 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vsync_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_vtotal 56 __builtin_offsetof(struct __C(drm_mode_crtc), mode.vtotal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_mode_valid 32 __builtin_offsetof(struct __C(drm_mode_crtc), mode_valid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_set_connectors_ptr 0 __builtin_offsetof(struct __C(drm_mode_crtc), set_connectors_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_x 20 __builtin_offsetof(struct __C(drm_mode_crtc), x)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_y 24 __builtin_offsetof(struct __C(drm_mode_crtc), y)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_crtc_lut 32 sizeof(struct __C(drm_mode_crtc_lut))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_crtc_lut 8 __alignof(struct __C(drm_mode_crtc_lut))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_lut_blue 24 __builtin_offsetof(struct __C(drm_mode_crtc_lut), blue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_lut_crtc_id 0 __builtin_offsetof(struct __C(drm_mode_crtc_lut), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_lut_gamma_size 4 __builtin_offsetof(struct __C(drm_mode_crtc_lut), gamma_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_lut_green 16 __builtin_offsetof(struct __C(drm_mode_crtc_lut), green)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_lut_red 8 __builtin_offsetof(struct __C(drm_mode_crtc_lut), red)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_crtc_page_flip_target 24 sizeof(struct __C(drm_mode_crtc_page_flip_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_crtc_page_flip_target 8 __alignof(struct __C(drm_mode_crtc_page_flip_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_page_flip_target_crtc_id 0 __builtin_offsetof(struct __C(drm_mode_crtc_page_flip_target), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_page_flip_target_fb_id 4 __builtin_offsetof(struct __C(drm_mode_crtc_page_flip_target), fb_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_page_flip_target_flags 8 __builtin_offsetof(struct __C(drm_mode_crtc_page_flip_target), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_page_flip_target_sequence 12 __builtin_offsetof(struct __C(drm_mode_crtc_page_flip_target), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_crtc_page_flip_target_user_data 16 __builtin_offsetof(struct __C(drm_mode_crtc_page_flip_target), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_fb_dirty_cmd 24 sizeof(struct __C(drm_mode_fb_dirty_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_fb_dirty_cmd 8 __alignof(struct __C(drm_mode_fb_dirty_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_fb_dirty_cmd_clips_ptr 16 __builtin_offsetof(struct __C(drm_mode_fb_dirty_cmd), clips_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_fb_dirty_cmd_color 8 __builtin_offsetof(struct __C(drm_mode_fb_dirty_cmd), color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_fb_dirty_cmd_fb_id 0 __builtin_offsetof(struct __C(drm_mode_fb_dirty_cmd), fb_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_fb_dirty_cmd_flags 4 __builtin_offsetof(struct __C(drm_mode_fb_dirty_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_fb_dirty_cmd_num_clips 12 __builtin_offsetof(struct __C(drm_mode_fb_dirty_cmd), num_clips)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_blob 16 sizeof(struct __C(drm_mode_get_blob))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_blob 8 __alignof(struct __C(drm_mode_get_blob))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_blob_blob_id 0 __builtin_offsetof(struct __C(drm_mode_get_blob), blob_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_blob_data 8 __builtin_offsetof(struct __C(drm_mode_get_blob), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_blob_length 4 __builtin_offsetof(struct __C(drm_mode_get_blob), length)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_connector 80 sizeof(struct __C(drm_mode_get_connector))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_connector 8 __alignof(struct __C(drm_mode_get_connector))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_connection 60 __builtin_offsetof(struct __C(drm_mode_get_connector), connection)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_connector_id 48 __builtin_offsetof(struct __C(drm_mode_get_connector), connector_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_connector_type 52 __builtin_offsetof(struct __C(drm_mode_get_connector), connector_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_connector_type_id 56 __builtin_offsetof(struct __C(drm_mode_get_connector), connector_type_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_count_encoders 40 __builtin_offsetof(struct __C(drm_mode_get_connector), count_encoders)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_count_modes 32 __builtin_offsetof(struct __C(drm_mode_get_connector), count_modes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_count_props 36 __builtin_offsetof(struct __C(drm_mode_get_connector), count_props)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_encoder_id 44 __builtin_offsetof(struct __C(drm_mode_get_connector), encoder_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_encoders_ptr 0 __builtin_offsetof(struct __C(drm_mode_get_connector), encoders_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_mm_height 68 __builtin_offsetof(struct __C(drm_mode_get_connector), mm_height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_mm_width 64 __builtin_offsetof(struct __C(drm_mode_get_connector), mm_width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_modes_ptr 8 __builtin_offsetof(struct __C(drm_mode_get_connector), modes_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_pad 76 __builtin_offsetof(struct __C(drm_mode_get_connector), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_prop_values_ptr 24 __builtin_offsetof(struct __C(drm_mode_get_connector), prop_values_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_props_ptr 16 __builtin_offsetof(struct __C(drm_mode_get_connector), props_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_connector_subpixel 72 __builtin_offsetof(struct __C(drm_mode_get_connector), subpixel)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_lease 16 sizeof(struct __C(drm_mode_get_lease))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_lease 8 __alignof(struct __C(drm_mode_get_lease))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_lease_count_objects 0 __builtin_offsetof(struct __C(drm_mode_get_lease), count_objects)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_lease_objects_ptr 8 __builtin_offsetof(struct __C(drm_mode_get_lease), objects_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_lease_pad 4 __builtin_offsetof(struct __C(drm_mode_get_lease), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_plane 32 sizeof(struct __C(drm_mode_get_plane))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_plane 8 __alignof(struct __C(drm_mode_get_plane))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_count_format_types 20 __builtin_offsetof(struct __C(drm_mode_get_plane), count_format_types)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_crtc_id 4 __builtin_offsetof(struct __C(drm_mode_get_plane), crtc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_fb_id 8 __builtin_offsetof(struct __C(drm_mode_get_plane), fb_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_format_type_ptr 24 __builtin_offsetof(struct __C(drm_mode_get_plane), format_type_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_gamma_size 16 __builtin_offsetof(struct __C(drm_mode_get_plane), gamma_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_plane_id 0 __builtin_offsetof(struct __C(drm_mode_get_plane), plane_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_possible_crtcs 12 __builtin_offsetof(struct __C(drm_mode_get_plane), possible_crtcs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_plane_res 16 sizeof(struct __C(drm_mode_get_plane_res))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_plane_res 8 __alignof(struct __C(drm_mode_get_plane_res))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_res_count_planes 8 __builtin_offsetof(struct __C(drm_mode_get_plane_res), count_planes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_plane_res_plane_id_ptr 0 __builtin_offsetof(struct __C(drm_mode_get_plane_res), plane_id_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_get_property 64 sizeof(struct __C(drm_mode_get_property))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_get_property 8 __alignof(struct __C(drm_mode_get_property))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_count_enum_blobs 60 __builtin_offsetof(struct __C(drm_mode_get_property), count_enum_blobs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_count_values 56 __builtin_offsetof(struct __C(drm_mode_get_property), count_values)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_enum_blob_ptr 8 __builtin_offsetof(struct __C(drm_mode_get_property), enum_blob_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_flags 20 __builtin_offsetof(struct __C(drm_mode_get_property), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_name 24 __builtin_offsetof(struct __C(drm_mode_get_property), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_prop_id 16 __builtin_offsetof(struct __C(drm_mode_get_property), prop_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_get_property_values_ptr 0 __builtin_offsetof(struct __C(drm_mode_get_property), values_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_list_lessees 16 sizeof(struct __C(drm_mode_list_lessees))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_list_lessees 8 __alignof(struct __C(drm_mode_list_lessees))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_list_lessees_count_lessees 0 __builtin_offsetof(struct __C(drm_mode_list_lessees), count_lessees)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_list_lessees_lessees_ptr 8 __builtin_offsetof(struct __C(drm_mode_list_lessees), lessees_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_list_lessees_pad 4 __builtin_offsetof(struct __C(drm_mode_list_lessees), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_mode_obj_get_properties 32 sizeof(struct __C(drm_mode_obj_get_properties))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_mode_obj_get_properties 8 __alignof(struct __C(drm_mode_obj_get_properties))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_obj_get_properties_count_props 16 __builtin_offsetof(struct __C(drm_mode_obj_get_properties), count_props)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_obj_get_properties_obj_id 20 __builtin_offsetof(struct __C(drm_mode_obj_get_properties), obj_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_obj_get_properties_obj_type 24 __builtin_offsetof(struct __C(drm_mode_obj_get_properties), obj_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_obj_get_properties_prop_values_ptr 8 __builtin_offsetof(struct __C(drm_mode_obj_get_properties), prop_values_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_mode_obj_get_properties_props_ptr 0 __builtin_offsetof(struct __C(drm_mode_obj_get_properties), props_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_msm_gem_info 24 sizeof(struct __C(drm_msm_gem_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_msm_gem_info 8 __alignof(struct __C(drm_msm_gem_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_info_handle 0 __builtin_offsetof(struct __C(drm_msm_gem_info), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_info_info 4 __builtin_offsetof(struct __C(drm_msm_gem_info), info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_info_len 16 __builtin_offsetof(struct __C(drm_msm_gem_info), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_info_pad 20 __builtin_offsetof(struct __C(drm_msm_gem_info), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_info_value 8 __builtin_offsetof(struct __C(drm_msm_gem_info), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_msm_gem_submit 72 sizeof(struct __C(drm_msm_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_msm_gem_submit 8 __alignof(struct __C(drm_msm_gem_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_bos 16 __builtin_offsetof(struct __C(drm_msm_gem_submit), bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmds 24 __builtin_offsetof(struct __C(drm_msm_gem_submit), cmds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_fence 4 __builtin_offsetof(struct __C(drm_msm_gem_submit), fence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_fence_fd 32 __builtin_offsetof(struct __C(drm_msm_gem_submit), fence_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_flags 0 __builtin_offsetof(struct __C(drm_msm_gem_submit), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_in_syncobjs 40 __builtin_offsetof(struct __C(drm_msm_gem_submit), in_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_nr_bos 8 __builtin_offsetof(struct __C(drm_msm_gem_submit), nr_bos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_nr_cmds 12 __builtin_offsetof(struct __C(drm_msm_gem_submit), nr_cmds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_nr_in_syncobjs 56 __builtin_offsetof(struct __C(drm_msm_gem_submit), nr_in_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_nr_out_syncobjs 60 __builtin_offsetof(struct __C(drm_msm_gem_submit), nr_out_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_out_syncobjs 48 __builtin_offsetof(struct __C(drm_msm_gem_submit), out_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_pad 68 __builtin_offsetof(struct __C(drm_msm_gem_submit), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_queueid 36 __builtin_offsetof(struct __C(drm_msm_gem_submit), queueid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_syncobj_stride 64 __builtin_offsetof(struct __C(drm_msm_gem_submit), syncobj_stride)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_msm_gem_submit_cmd 32 sizeof(struct __C(drm_msm_gem_submit_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_msm_gem_submit_cmd 8 __alignof(struct __C(drm_msm_gem_submit_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_nr_relocs 20 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), nr_relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_pad 16 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_relocs 24 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_size 12 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_submit_idx 4 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), submit_idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_submit_offset 8 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), submit_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_gem_submit_cmd_type 0 __builtin_offsetof(struct __C(drm_msm_gem_submit_cmd), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_msm_param 24 sizeof(struct __C(drm_msm_param))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_msm_param 8 __alignof(struct __C(drm_msm_param))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_param_len 16 __builtin_offsetof(struct __C(drm_msm_param), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_param_pad 20 __builtin_offsetof(struct __C(drm_msm_param), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_param_param 4 __builtin_offsetof(struct __C(drm_msm_param), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_param_pipe 0 __builtin_offsetof(struct __C(drm_msm_param), pipe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_param_value 8 __builtin_offsetof(struct __C(drm_msm_param), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_msm_submitqueue_query 24 sizeof(struct __C(drm_msm_submitqueue_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_msm_submitqueue_query 8 __alignof(struct __C(drm_msm_submitqueue_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_submitqueue_query_data 0 __builtin_offsetof(struct __C(drm_msm_submitqueue_query), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_submitqueue_query_id 8 __builtin_offsetof(struct __C(drm_msm_submitqueue_query), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_submitqueue_query_len 16 __builtin_offsetof(struct __C(drm_msm_submitqueue_query), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_submitqueue_query_pad 20 __builtin_offsetof(struct __C(drm_msm_submitqueue_query), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_msm_submitqueue_query_param 12 __builtin_offsetof(struct __C(drm_msm_submitqueue_query), param)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panfrost_perfcnt_dump 8 sizeof(struct __C(drm_panfrost_perfcnt_dump))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panfrost_perfcnt_dump 8 __alignof(struct __C(drm_panfrost_perfcnt_dump))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_perfcnt_dump_buf_ptr 0 __builtin_offsetof(struct __C(drm_panfrost_perfcnt_dump), buf_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panfrost_submit 40 sizeof(struct __C(drm_panfrost_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panfrost_submit 8 __alignof(struct __C(drm_panfrost_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_bo_handle_count 32 __builtin_offsetof(struct __C(drm_panfrost_submit), bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_bo_handles 24 __builtin_offsetof(struct __C(drm_panfrost_submit), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_in_sync_count 16 __builtin_offsetof(struct __C(drm_panfrost_submit), in_sync_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_in_syncs 8 __builtin_offsetof(struct __C(drm_panfrost_submit), in_syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_jc 0 __builtin_offsetof(struct __C(drm_panfrost_submit), jc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_out_sync 20 __builtin_offsetof(struct __C(drm_panfrost_submit), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panfrost_submit_requirements 36 __builtin_offsetof(struct __C(drm_panfrost_submit), requirements)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_bo_set_label 16 sizeof(struct __C(drm_panthor_bo_set_label))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_bo_set_label 8 __alignof(struct __C(drm_panthor_bo_set_label))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_bo_set_label_handle 0 __builtin_offsetof(struct __C(drm_panthor_bo_set_label), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_bo_set_label_label 8 __builtin_offsetof(struct __C(drm_panthor_bo_set_label), label)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_bo_set_label_pad 4 __builtin_offsetof(struct __C(drm_panthor_bo_set_label), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_dev_query 16 sizeof(struct __C(drm_panthor_dev_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_dev_query 8 __alignof(struct __C(drm_panthor_dev_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_dev_query_pointer 8 __builtin_offsetof(struct __C(drm_panthor_dev_query), pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_dev_query_size 4 __builtin_offsetof(struct __C(drm_panthor_dev_query), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_dev_query_type 0 __builtin_offsetof(struct __C(drm_panthor_dev_query), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_group_create 56 sizeof(struct __C(drm_panthor_group_create))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_group_create 8 __alignof(struct __C(drm_panthor_group_create))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_compute_core_mask 24 __builtin_offsetof(struct __C(drm_panthor_group_create), compute_core_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_fragment_core_mask 32 __builtin_offsetof(struct __C(drm_panthor_group_create), fragment_core_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_group_handle 52 __builtin_offsetof(struct __C(drm_panthor_group_create), group_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_max_compute_cores 16 __builtin_offsetof(struct __C(drm_panthor_group_create), max_compute_cores)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_max_fragment_cores 17 __builtin_offsetof(struct __C(drm_panthor_group_create), max_fragment_cores)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_max_tiler_cores 18 __builtin_offsetof(struct __C(drm_panthor_group_create), max_tiler_cores)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_pad 20 __builtin_offsetof(struct __C(drm_panthor_group_create), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_priority 19 __builtin_offsetof(struct __C(drm_panthor_group_create), priority)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_queues 0 __builtin_offsetof(struct __C(drm_panthor_group_create), queues)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_queues_array 8 __builtin_offsetof(struct __C(drm_panthor_group_create), queues.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_queues_count 4 __builtin_offsetof(struct __C(drm_panthor_group_create), queues.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_queues_stride 0 __builtin_offsetof(struct __C(drm_panthor_group_create), queues.stride)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_tiler_core_mask 40 __builtin_offsetof(struct __C(drm_panthor_group_create), tiler_core_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_create_vm_id 48 __builtin_offsetof(struct __C(drm_panthor_group_create), vm_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_group_submit 24 sizeof(struct __C(drm_panthor_group_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_group_submit 8 __alignof(struct __C(drm_panthor_group_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_group_handle 0 __builtin_offsetof(struct __C(drm_panthor_group_submit), group_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_pad 4 __builtin_offsetof(struct __C(drm_panthor_group_submit), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_queue_submits 8 __builtin_offsetof(struct __C(drm_panthor_group_submit), queue_submits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_queue_submits_array 16 __builtin_offsetof(struct __C(drm_panthor_group_submit), queue_submits.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_queue_submits_count 12 __builtin_offsetof(struct __C(drm_panthor_group_submit), queue_submits.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_group_submit_queue_submits_stride 8 __builtin_offsetof(struct __C(drm_panthor_group_submit), queue_submits.stride)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_obj_array 16 sizeof(struct __C(drm_panthor_obj_array))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_obj_array 8 __alignof(struct __C(drm_panthor_obj_array))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_obj_array_array 8 __builtin_offsetof(struct __C(drm_panthor_obj_array), array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_obj_array_count 4 __builtin_offsetof(struct __C(drm_panthor_obj_array), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_obj_array_stride 0 __builtin_offsetof(struct __C(drm_panthor_obj_array), stride)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_queue_submit 40 sizeof(struct __C(drm_panthor_queue_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_queue_submit 8 __alignof(struct __C(drm_panthor_queue_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_latest_flush 16 __builtin_offsetof(struct __C(drm_panthor_queue_submit), latest_flush)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_pad 20 __builtin_offsetof(struct __C(drm_panthor_queue_submit), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_queue_index 0 __builtin_offsetof(struct __C(drm_panthor_queue_submit), queue_index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_stream_addr 8 __builtin_offsetof(struct __C(drm_panthor_queue_submit), stream_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_stream_size 4 __builtin_offsetof(struct __C(drm_panthor_queue_submit), stream_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_syncs 24 __builtin_offsetof(struct __C(drm_panthor_queue_submit), syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_syncs_array 32 __builtin_offsetof(struct __C(drm_panthor_queue_submit), syncs.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_syncs_count 28 __builtin_offsetof(struct __C(drm_panthor_queue_submit), syncs.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_queue_submit_syncs_stride 24 __builtin_offsetof(struct __C(drm_panthor_queue_submit), syncs.stride)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_vm_bind 24 sizeof(struct __C(drm_panthor_vm_bind))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_vm_bind 8 __alignof(struct __C(drm_panthor_vm_bind))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_flags 4 __builtin_offsetof(struct __C(drm_panthor_vm_bind), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_ops 8 __builtin_offsetof(struct __C(drm_panthor_vm_bind), ops)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_ops_array 16 __builtin_offsetof(struct __C(drm_panthor_vm_bind), ops.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_ops_count 12 __builtin_offsetof(struct __C(drm_panthor_vm_bind), ops.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_ops_stride 8 __builtin_offsetof(struct __C(drm_panthor_vm_bind), ops.stride)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_vm_id 0 __builtin_offsetof(struct __C(drm_panthor_vm_bind), vm_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_panthor_vm_bind_op 48 sizeof(struct __C(drm_panthor_vm_bind_op))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_panthor_vm_bind_op 8 __alignof(struct __C(drm_panthor_vm_bind_op))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_bo_handle 4 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), bo_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_bo_offset 8 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), bo_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_flags 0 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_size 24 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_syncs 32 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_syncs_array 40 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), syncs.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_syncs_count 36 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), syncs.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_syncs_stride 32 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), syncs.stride)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_panthor_vm_bind_op_va 16 __builtin_offsetof(struct __C(drm_panthor_vm_bind_op), va)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_qxl_command 32 sizeof(struct __C(drm_qxl_command))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_qxl_command 8 __alignof(struct __C(drm_qxl_command))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_command 0 __builtin_offsetof(struct __C(drm_qxl_command), command)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_command_size 20 __builtin_offsetof(struct __C(drm_qxl_command), command_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_pad 28 __builtin_offsetof(struct __C(drm_qxl_command), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_relocs 8 __builtin_offsetof(struct __C(drm_qxl_command), relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_relocs_num 24 __builtin_offsetof(struct __C(drm_qxl_command), relocs_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_command_type 16 __builtin_offsetof(struct __C(drm_qxl_command), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_qxl_execbuffer 16 sizeof(struct __C(drm_qxl_execbuffer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_qxl_execbuffer 8 __alignof(struct __C(drm_qxl_execbuffer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_execbuffer_commands 8 __builtin_offsetof(struct __C(drm_qxl_execbuffer), commands)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_execbuffer_commands_num 4 __builtin_offsetof(struct __C(drm_qxl_execbuffer), commands_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_qxl_execbuffer_flags 0 __builtin_offsetof(struct __C(drm_qxl_execbuffer), flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_clear 32 sizeof(struct __C(drm_radeon_clear))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_clear 8 __alignof(struct __C(drm_radeon_clear))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_clear_color 4 __builtin_offsetof(struct __C(drm_radeon_clear), clear_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_clear_depth 8 __builtin_offsetof(struct __C(drm_radeon_clear), clear_depth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_color_mask 12 __builtin_offsetof(struct __C(drm_radeon_clear), color_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_depth_boxes 24 __builtin_offsetof(struct __C(drm_radeon_clear), depth_boxes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_depth_mask 16 __builtin_offsetof(struct __C(drm_radeon_clear), depth_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_clear_flags 0 __builtin_offsetof(struct __C(drm_radeon_clear), flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_cmd_buffer 32 sizeof(struct __C(drm_radeon_cmd_buffer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_cmd_buffer 8 __alignof(struct __C(drm_radeon_cmd_buffer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_boxes 24 __builtin_offsetof(struct __C(drm_radeon_cmd_buffer), boxes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_buf 8 __builtin_offsetof(struct __C(drm_radeon_cmd_buffer), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_bufsz 0 __builtin_offsetof(struct __C(drm_radeon_cmd_buffer), bufsz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cmd_buffer_nbox 16 __builtin_offsetof(struct __C(drm_radeon_cmd_buffer), nbox)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_cs 32 sizeof(struct __C(drm_radeon_cs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_cs 8 __alignof(struct __C(drm_radeon_cs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_chunks 8 __builtin_offsetof(struct __C(drm_radeon_cs), chunks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_cs_id 4 __builtin_offsetof(struct __C(drm_radeon_cs), cs_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_gart_limit 16 __builtin_offsetof(struct __C(drm_radeon_cs), gart_limit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_num_chunks 0 __builtin_offsetof(struct __C(drm_radeon_cs), num_chunks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_vram_limit 24 __builtin_offsetof(struct __C(drm_radeon_cs), vram_limit)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_cs_chunk 16 sizeof(struct __C(drm_radeon_cs_chunk))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_cs_chunk 8 __alignof(struct __C(drm_radeon_cs_chunk))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_chunk_chunk_data 8 __builtin_offsetof(struct __C(drm_radeon_cs_chunk), chunk_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_chunk_chunk_id 0 __builtin_offsetof(struct __C(drm_radeon_cs_chunk), chunk_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_cs_chunk_length_dw 4 __builtin_offsetof(struct __C(drm_radeon_cs_chunk), length_dw)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_getparam 16 sizeof(struct __C(drm_radeon_getparam))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_getparam 8 __alignof(struct __C(drm_radeon_getparam))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_getparam_param 0 __builtin_offsetof(struct __C(drm_radeon_getparam), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_getparam_value 8 __builtin_offsetof(struct __C(drm_radeon_getparam), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_info 16 sizeof(struct __C(drm_radeon_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_info 8 __alignof(struct __C(drm_radeon_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_info_pad 4 __builtin_offsetof(struct __C(drm_radeon_info), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_info_request 0 __builtin_offsetof(struct __C(drm_radeon_info), request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_info_value 8 __builtin_offsetof(struct __C(drm_radeon_info), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_irq_emit 8 sizeof(struct __C(drm_radeon_irq_emit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_irq_emit 8 __alignof(struct __C(drm_radeon_irq_emit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_irq_emit_irq_seq 0 __builtin_offsetof(struct __C(drm_radeon_irq_emit), irq_seq)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_mem_alloc 24 sizeof(struct __C(drm_radeon_mem_alloc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_mem_alloc 8 __alignof(struct __C(drm_radeon_mem_alloc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_alignment 4 __builtin_offsetof(struct __C(drm_radeon_mem_alloc), alignment)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_region 0 __builtin_offsetof(struct __C(drm_radeon_mem_alloc), region)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_region_offset 16 __builtin_offsetof(struct __C(drm_radeon_mem_alloc), region_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_mem_alloc_size 8 __builtin_offsetof(struct __C(drm_radeon_mem_alloc), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_stipple 8 sizeof(struct __C(drm_radeon_stipple))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_stipple 8 __alignof(struct __C(drm_radeon_stipple))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_stipple_mask 0 __builtin_offsetof(struct __C(drm_radeon_stipple), mask)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_tex_image 24 sizeof(struct __C(drm_radeon_tex_image))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_tex_image 8 __alignof(struct __C(drm_radeon_tex_image))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_data 16 __builtin_offsetof(struct __C(drm_radeon_tex_image), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_height 12 __builtin_offsetof(struct __C(drm_radeon_tex_image), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_width 8 __builtin_offsetof(struct __C(drm_radeon_tex_image), width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_x 0 __builtin_offsetof(struct __C(drm_radeon_tex_image), x)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_tex_image_y 4 __builtin_offsetof(struct __C(drm_radeon_tex_image), y)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_texture 32 sizeof(struct __C(drm_radeon_texture))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_texture 8 __alignof(struct __C(drm_radeon_texture))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_format 8 __builtin_offsetof(struct __C(drm_radeon_texture), format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_height 16 __builtin_offsetof(struct __C(drm_radeon_texture), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_image 24 __builtin_offsetof(struct __C(drm_radeon_texture), image)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_offset 0 __builtin_offsetof(struct __C(drm_radeon_texture), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_pitch 4 __builtin_offsetof(struct __C(drm_radeon_texture), pitch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_texture_width 12 __builtin_offsetof(struct __C(drm_radeon_texture), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_radeon_vertex2 40 sizeof(struct __C(drm_radeon_vertex2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_radeon_vertex2 8 __alignof(struct __C(drm_radeon_vertex2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_discard 4 __builtin_offsetof(struct __C(drm_radeon_vertex2), discard)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_idx 0 __builtin_offsetof(struct __C(drm_radeon_vertex2), idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_nr_prims 24 __builtin_offsetof(struct __C(drm_radeon_vertex2), nr_prims)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_nr_states 8 __builtin_offsetof(struct __C(drm_radeon_vertex2), nr_states)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_prim 32 __builtin_offsetof(struct __C(drm_radeon_vertex2), prim)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_radeon_vertex2_state 16 __builtin_offsetof(struct __C(drm_radeon_vertex2), state)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_set_client_name 16 sizeof(struct __C(drm_set_client_name))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_set_client_name 8 __alignof(struct __C(drm_set_client_name))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_set_client_name_name 8 __builtin_offsetof(struct __C(drm_set_client_name), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_set_client_name_name_len 0 __builtin_offsetof(struct __C(drm_set_client_name), name_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_syncobj_array 16 sizeof(struct __C(drm_syncobj_array))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_syncobj_array 8 __alignof(struct __C(drm_syncobj_array))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_array_count_handles 8 __builtin_offsetof(struct __C(drm_syncobj_array), count_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_array_handles 0 __builtin_offsetof(struct __C(drm_syncobj_array), handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_array_pad 12 __builtin_offsetof(struct __C(drm_syncobj_array), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_syncobj_timeline_array 24 sizeof(struct __C(drm_syncobj_timeline_array))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_syncobj_timeline_array 8 __alignof(struct __C(drm_syncobj_timeline_array))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_array_count_handles 16 __builtin_offsetof(struct __C(drm_syncobj_timeline_array), count_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_array_flags 20 __builtin_offsetof(struct __C(drm_syncobj_timeline_array), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_array_handles 0 __builtin_offsetof(struct __C(drm_syncobj_timeline_array), handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_array_points 8 __builtin_offsetof(struct __C(drm_syncobj_timeline_array), points)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_syncobj_timeline_wait 48 sizeof(struct __C(drm_syncobj_timeline_wait))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_syncobj_timeline_wait 8 __alignof(struct __C(drm_syncobj_timeline_wait))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_count_handles 24 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), count_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_deadline_nsec 40 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), deadline_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_first_signaled 32 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), first_signaled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_flags 28 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_handles 0 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_pad 36 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_points 8 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), points)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_timeline_wait_timeout_nsec 16 __builtin_offsetof(struct __C(drm_syncobj_timeline_wait), timeout_nsec)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_syncobj_wait 40 sizeof(struct __C(drm_syncobj_wait))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_syncobj_wait 8 __alignof(struct __C(drm_syncobj_wait))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_count_handles 16 __builtin_offsetof(struct __C(drm_syncobj_wait), count_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_deadline_nsec 32 __builtin_offsetof(struct __C(drm_syncobj_wait), deadline_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_first_signaled 24 __builtin_offsetof(struct __C(drm_syncobj_wait), first_signaled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_flags 20 __builtin_offsetof(struct __C(drm_syncobj_wait), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_handles 0 __builtin_offsetof(struct __C(drm_syncobj_wait), handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_pad 28 __builtin_offsetof(struct __C(drm_syncobj_wait), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_syncobj_wait_timeout_nsec 8 __builtin_offsetof(struct __C(drm_syncobj_wait), timeout_nsec)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_tegra_channel_submit 64 sizeof(struct __C(drm_tegra_channel_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_tegra_channel_submit 8 __alignof(struct __C(drm_tegra_channel_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_bufs_ptr 16 __builtin_offsetof(struct __C(drm_tegra_channel_submit), bufs_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_cmds_ptr 24 __builtin_offsetof(struct __C(drm_tegra_channel_submit), cmds_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_context 0 __builtin_offsetof(struct __C(drm_tegra_channel_submit), context)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_gather_data_ptr 32 __builtin_offsetof(struct __C(drm_tegra_channel_submit), gather_data_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_gather_data_words 12 __builtin_offsetof(struct __C(drm_tegra_channel_submit), gather_data_words)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_num_bufs 4 __builtin_offsetof(struct __C(drm_tegra_channel_submit), num_bufs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_num_cmds 8 __builtin_offsetof(struct __C(drm_tegra_channel_submit), num_cmds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncobj_in 40 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncobj_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncobj_out 44 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncobj_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncpt 48 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncpt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncpt_flags 52 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncpt.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncpt_id 48 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncpt.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncpt_increments 56 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncpt.increments)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_channel_submit_syncpt_value 60 __builtin_offsetof(struct __C(drm_tegra_channel_submit), syncpt.value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_tegra_submit 88 sizeof(struct __C(drm_tegra_submit))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_tegra_submit 8 __alignof(struct __C(drm_tegra_submit))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_cmdbufs 40 __builtin_offsetof(struct __C(drm_tegra_submit), cmdbufs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_context 0 __builtin_offsetof(struct __C(drm_tegra_submit), context)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_fence 64 __builtin_offsetof(struct __C(drm_tegra_submit), fence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_num_cmdbufs 12 __builtin_offsetof(struct __C(drm_tegra_submit), num_cmdbufs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_num_relocs 16 __builtin_offsetof(struct __C(drm_tegra_submit), num_relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_num_syncpts 8 __builtin_offsetof(struct __C(drm_tegra_submit), num_syncpts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_num_waitchks 20 __builtin_offsetof(struct __C(drm_tegra_submit), num_waitchks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_relocs 48 __builtin_offsetof(struct __C(drm_tegra_submit), relocs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_reserved 68 __builtin_offsetof(struct __C(drm_tegra_submit), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_syncpts 32 __builtin_offsetof(struct __C(drm_tegra_submit), syncpts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_timeout 28 __builtin_offsetof(struct __C(drm_tegra_submit), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_waitchk_mask 24 __builtin_offsetof(struct __C(drm_tegra_submit), waitchk_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_tegra_submit_waitchks 56 __builtin_offsetof(struct __C(drm_tegra_submit), waitchks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_unique 16 sizeof(struct __C(drm_unique))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_unique 8 __alignof(struct __C(drm_unique))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_unique_unique 8 __builtin_offsetof(struct __C(drm_unique), unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_unique_unique_len 0 __builtin_offsetof(struct __C(drm_unique), unique_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_copy_performance_query 56 sizeof(struct __C(drm_v3d_copy_performance_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_copy_performance_query 8 __alignof(struct __C(drm_v3d_copy_performance_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_availability_bit 18 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), availability_bit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_base 0 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_base_id 8 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_base_next 0 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_count 36 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_do_64bit 16 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), do_64bit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_do_partial 17 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), do_partial)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_kperfmon_ids 48 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), kperfmon_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_ncounters 32 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), ncounters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_nperfmons 28 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), nperfmons)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_offset 20 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_pad 19 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_stride 24 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), stride)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_performance_query_syncs 40 __builtin_offsetof(struct __C(drm_v3d_copy_performance_query), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_copy_timestamp_query 48 sizeof(struct __C(drm_v3d_copy_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_copy_timestamp_query 8 __alignof(struct __C(drm_v3d_copy_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_availability_bit 18 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), availability_bit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_base 0 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_base_id 8 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_base_next 0 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_count 28 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_do_64bit 16 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), do_64bit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_do_partial 17 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), do_partial)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_offset 20 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_offsets 32 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_pad 19 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_stride 24 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), stride)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_copy_timestamp_query_syncs 40 __builtin_offsetof(struct __C(drm_v3d_copy_timestamp_query), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_extension 16 sizeof(struct __C(drm_v3d_extension))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_extension 8 __alignof(struct __C(drm_v3d_extension))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_extension_flags 12 __builtin_offsetof(struct __C(drm_v3d_extension), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_extension_id 8 __builtin_offsetof(struct __C(drm_v3d_extension), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_extension_next 0 __builtin_offsetof(struct __C(drm_v3d_extension), next)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_indirect_csd 128 sizeof(struct __C(drm_v3d_indirect_csd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_indirect_csd 8 __alignof(struct __C(drm_v3d_indirect_csd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_base 0 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_base_id 8 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_base_next 0 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_indirect 104 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), indirect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_offset 108 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit 16 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_bo_handle_count 72 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_bo_handles 64 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_cfg 16 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_coef 44 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.coef)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_extensions 88 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_flags 96 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_in_sync 76 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.in_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_out_sync 80 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_pad 100 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_submit_perfmon_id 84 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), submit.perfmon_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_wg_size 112 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), wg_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_indirect_csd_wg_uniform_offsets 116 __builtin_offsetof(struct __C(drm_v3d_indirect_csd), wg_uniform_offsets)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_multi_sync 48 sizeof(struct __C(drm_v3d_multi_sync))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_multi_sync 8 __alignof(struct __C(drm_v3d_multi_sync))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_base 0 __builtin_offsetof(struct __C(drm_v3d_multi_sync), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_multi_sync), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_base_id 8 __builtin_offsetof(struct __C(drm_v3d_multi_sync), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_base_next 0 __builtin_offsetof(struct __C(drm_v3d_multi_sync), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_in_sync_count 32 __builtin_offsetof(struct __C(drm_v3d_multi_sync), in_sync_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_in_syncs 16 __builtin_offsetof(struct __C(drm_v3d_multi_sync), in_syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_out_sync_count 36 __builtin_offsetof(struct __C(drm_v3d_multi_sync), out_sync_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_out_syncs 24 __builtin_offsetof(struct __C(drm_v3d_multi_sync), out_syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_pad 44 __builtin_offsetof(struct __C(drm_v3d_multi_sync), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_multi_sync_wait_stage 40 __builtin_offsetof(struct __C(drm_v3d_multi_sync), wait_stage)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_perfmon_get_values 16 sizeof(struct __C(drm_v3d_perfmon_get_values))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_perfmon_get_values 8 __alignof(struct __C(drm_v3d_perfmon_get_values))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_perfmon_get_values_id 0 __builtin_offsetof(struct __C(drm_v3d_perfmon_get_values), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_perfmon_get_values_pad 4 __builtin_offsetof(struct __C(drm_v3d_perfmon_get_values), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_perfmon_get_values_values_ptr 8 __builtin_offsetof(struct __C(drm_v3d_perfmon_get_values), values_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_reset_performance_query 40 sizeof(struct __C(drm_v3d_reset_performance_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_reset_performance_query 8 __alignof(struct __C(drm_v3d_reset_performance_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_base 0 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_base_id 8 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_base_next 0 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_count 24 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_kperfmon_ids 32 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), kperfmon_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_nperfmons 28 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), nperfmons)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_performance_query_syncs 16 __builtin_offsetof(struct __C(drm_v3d_reset_performance_query), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_reset_timestamp_query 32 sizeof(struct __C(drm_v3d_reset_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_reset_timestamp_query 8 __alignof(struct __C(drm_v3d_reset_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_base 0 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_base_id 8 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_base_next 0 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_count 28 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_offset 24 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_reset_timestamp_query_syncs 16 __builtin_offsetof(struct __C(drm_v3d_reset_timestamp_query), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_submit_cl 72 sizeof(struct __C(drm_v3d_submit_cl))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_submit_cl 8 __alignof(struct __C(drm_v3d_submit_cl))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_bcl_end 4 __builtin_offsetof(struct __C(drm_v3d_submit_cl), bcl_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_bcl_start 0 __builtin_offsetof(struct __C(drm_v3d_submit_cl), bcl_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_bo_handle_count 48 __builtin_offsetof(struct __C(drm_v3d_submit_cl), bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_bo_handles 40 __builtin_offsetof(struct __C(drm_v3d_submit_cl), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_extensions 64 __builtin_offsetof(struct __C(drm_v3d_submit_cl), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_flags 52 __builtin_offsetof(struct __C(drm_v3d_submit_cl), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_in_sync_bcl 16 __builtin_offsetof(struct __C(drm_v3d_submit_cl), in_sync_bcl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_in_sync_rcl 20 __builtin_offsetof(struct __C(drm_v3d_submit_cl), in_sync_rcl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_out_sync 24 __builtin_offsetof(struct __C(drm_v3d_submit_cl), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_pad 60 __builtin_offsetof(struct __C(drm_v3d_submit_cl), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_perfmon_id 56 __builtin_offsetof(struct __C(drm_v3d_submit_cl), perfmon_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_qma 28 __builtin_offsetof(struct __C(drm_v3d_submit_cl), qma)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_qms 32 __builtin_offsetof(struct __C(drm_v3d_submit_cl), qms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_qts 36 __builtin_offsetof(struct __C(drm_v3d_submit_cl), qts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_rcl_end 12 __builtin_offsetof(struct __C(drm_v3d_submit_cl), rcl_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cl_rcl_start 8 __builtin_offsetof(struct __C(drm_v3d_submit_cl), rcl_start)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_submit_cpu 24 sizeof(struct __C(drm_v3d_submit_cpu))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_submit_cpu 8 __alignof(struct __C(drm_v3d_submit_cpu))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cpu_bo_handle_count 8 __builtin_offsetof(struct __C(drm_v3d_submit_cpu), bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cpu_bo_handles 0 __builtin_offsetof(struct __C(drm_v3d_submit_cpu), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cpu_extensions 16 __builtin_offsetof(struct __C(drm_v3d_submit_cpu), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_cpu_flags 12 __builtin_offsetof(struct __C(drm_v3d_submit_cpu), flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_submit_csd 88 sizeof(struct __C(drm_v3d_submit_csd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_submit_csd 8 __alignof(struct __C(drm_v3d_submit_csd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_bo_handle_count 56 __builtin_offsetof(struct __C(drm_v3d_submit_csd), bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_bo_handles 48 __builtin_offsetof(struct __C(drm_v3d_submit_csd), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_cfg 0 __builtin_offsetof(struct __C(drm_v3d_submit_csd), cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_coef 28 __builtin_offsetof(struct __C(drm_v3d_submit_csd), coef)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_extensions 72 __builtin_offsetof(struct __C(drm_v3d_submit_csd), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_flags 80 __builtin_offsetof(struct __C(drm_v3d_submit_csd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_in_sync 60 __builtin_offsetof(struct __C(drm_v3d_submit_csd), in_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_out_sync 64 __builtin_offsetof(struct __C(drm_v3d_submit_csd), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_pad 84 __builtin_offsetof(struct __C(drm_v3d_submit_csd), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_csd_perfmon_id 68 __builtin_offsetof(struct __C(drm_v3d_submit_csd), perfmon_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_submit_tfu 88 sizeof(struct __C(drm_v3d_submit_tfu))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_submit_tfu 8 __alignof(struct __C(drm_v3d_submit_tfu))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_bo_handles 44 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_coef 28 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), coef)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_extensions 72 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_flags 68 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_ica 12 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), ica)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_icfg 0 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), icfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_iia 4 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), iia)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_iis 8 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), iis)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_in_sync 60 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), in_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_ioa 20 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), ioa)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_ios 24 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), ios)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_iua 16 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), iua)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_out_sync 64 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_v71 80 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), v71)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_v71_ioc 80 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), v71.ioc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_submit_tfu_v71_pad 84 __builtin_offsetof(struct __C(drm_v3d_submit_tfu), v71.pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_v3d_timestamp_query 40 sizeof(struct __C(drm_v3d_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_v3d_timestamp_query 8 __alignof(struct __C(drm_v3d_timestamp_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_base 0 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_base_flags 12 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), base.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_base_id 8 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), base.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_base_next 0 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), base.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_count 32 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_offsets 16 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_pad 36 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_v3d_timestamp_query_syncs 24 __builtin_offsetof(struct __C(drm_v3d_timestamp_query), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_vc4_create_shader_bo 24 sizeof(struct __C(drm_vc4_create_shader_bo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_vc4_create_shader_bo 8 __alignof(struct __C(drm_vc4_create_shader_bo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_create_shader_bo_data 8 __builtin_offsetof(struct __C(drm_vc4_create_shader_bo), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_create_shader_bo_flags 4 __builtin_offsetof(struct __C(drm_vc4_create_shader_bo), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_create_shader_bo_handle 16 __builtin_offsetof(struct __C(drm_vc4_create_shader_bo), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_create_shader_bo_pad 20 __builtin_offsetof(struct __C(drm_vc4_create_shader_bo), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_create_shader_bo_size 0 __builtin_offsetof(struct __C(drm_vc4_create_shader_bo), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_vc4_get_hang_state 160 sizeof(struct __C(drm_vc4_get_hang_state))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_vc4_get_hang_state 8 __alignof(struct __C(drm_vc4_get_hang_state))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bo 0 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bo_count 8 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bo_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bpca 52 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bpca)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bpcs 56 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bpcs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bpoa 60 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bpoa)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_bpos 64 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), bpos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct0ca 20 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct0ca)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct0cs 36 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct0cs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct0ea 24 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct0ea)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct0ra0 44 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct0ra0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct1ca 28 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct1ca)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct1cs 40 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct1cs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct1ea 32 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct1ea)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_ct1ra0 48 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), ct1ra0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_dbge 72 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), dbge)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_errstat 92 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), errstat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_fdbgb 80 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), fdbgb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_fdbgo 76 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), fdbgo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_fdbgr 84 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), fdbgr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_fdbgs 88 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), fdbgs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_pad 96 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_start_bin 12 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), start_bin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_start_render 16 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), start_render)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_get_hang_state_vpmbase 68 __builtin_offsetof(struct __C(drm_vc4_get_hang_state), vpmbase)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_vc4_label_bo 16 sizeof(struct __C(drm_vc4_label_bo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_vc4_label_bo 8 __alignof(struct __C(drm_vc4_label_bo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_label_bo_handle 0 __builtin_offsetof(struct __C(drm_vc4_label_bo), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_label_bo_len 4 __builtin_offsetof(struct __C(drm_vc4_label_bo), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_label_bo_name 8 __builtin_offsetof(struct __C(drm_vc4_label_bo), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_vc4_perfmon_get_values 16 sizeof(struct __C(drm_vc4_perfmon_get_values))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_vc4_perfmon_get_values 8 __alignof(struct __C(drm_vc4_perfmon_get_values))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_perfmon_get_values_id 0 __builtin_offsetof(struct __C(drm_vc4_perfmon_get_values), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_perfmon_get_values_values_ptr 8 __builtin_offsetof(struct __C(drm_vc4_perfmon_get_values), values_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_vc4_submit_cl 176 sizeof(struct __C(drm_vc4_submit_cl))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_vc4_submit_cl 8 __alignof(struct __C(drm_vc4_submit_cl))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_bin_cl 0 __builtin_offsetof(struct __C(drm_vc4_submit_cl), bin_cl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_bin_cl_size 32 __builtin_offsetof(struct __C(drm_vc4_submit_cl), bin_cl_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_bo_handle_count 48 __builtin_offsetof(struct __C(drm_vc4_submit_cl), bo_handle_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_bo_handles 24 __builtin_offsetof(struct __C(drm_vc4_submit_cl), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_clear_color 132 __builtin_offsetof(struct __C(drm_vc4_submit_cl), clear_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_clear_s 144 __builtin_offsetof(struct __C(drm_vc4_submit_cl), clear_s)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_clear_z 140 __builtin_offsetof(struct __C(drm_vc4_submit_cl), clear_z)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_read 60 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_read)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_read_bits 68 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_read.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_read_flags 70 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_read.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_read_hindex 60 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_read.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_read_offset 64 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_read.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_write 72 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_write)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_write_bits 80 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_write.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_write_flags 82 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_write.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_write_hindex 72 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_write.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_color_write_offset 76 __builtin_offsetof(struct __C(drm_vc4_submit_cl), color_write.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_flags 148 __builtin_offsetof(struct __C(drm_vc4_submit_cl), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_height 54 __builtin_offsetof(struct __C(drm_vc4_submit_cl), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_in_sync 164 __builtin_offsetof(struct __C(drm_vc4_submit_cl), in_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_max_x_tile 58 __builtin_offsetof(struct __C(drm_vc4_submit_cl), max_x_tile)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_max_y_tile 59 __builtin_offsetof(struct __C(drm_vc4_submit_cl), max_y_tile)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_min_x_tile 56 __builtin_offsetof(struct __C(drm_vc4_submit_cl), min_x_tile)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_min_y_tile 57 __builtin_offsetof(struct __C(drm_vc4_submit_cl), min_y_tile)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_color_write 108 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_color_write)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_color_write_bits 116 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_color_write.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_color_write_flags 118 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_color_write.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_color_write_hindex 108 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_color_write.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_color_write_offset 112 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_color_write.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_zs_write 120 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_zs_write)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_zs_write_bits 128 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_zs_write.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_zs_write_flags 130 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_zs_write.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_zs_write_hindex 120 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_zs_write.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_msaa_zs_write_offset 124 __builtin_offsetof(struct __C(drm_vc4_submit_cl), msaa_zs_write.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_out_sync 168 __builtin_offsetof(struct __C(drm_vc4_submit_cl), out_sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_pad2 172 __builtin_offsetof(struct __C(drm_vc4_submit_cl), pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_perfmonid 160 __builtin_offsetof(struct __C(drm_vc4_submit_cl), perfmonid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_seqno 152 __builtin_offsetof(struct __C(drm_vc4_submit_cl), seqno)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_shader_rec 8 __builtin_offsetof(struct __C(drm_vc4_submit_cl), shader_rec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_shader_rec_count 40 __builtin_offsetof(struct __C(drm_vc4_submit_cl), shader_rec_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_shader_rec_size 36 __builtin_offsetof(struct __C(drm_vc4_submit_cl), shader_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_uniforms 16 __builtin_offsetof(struct __C(drm_vc4_submit_cl), uniforms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_uniforms_size 44 __builtin_offsetof(struct __C(drm_vc4_submit_cl), uniforms_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_width 52 __builtin_offsetof(struct __C(drm_vc4_submit_cl), width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_read 84 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_read)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_read_bits 92 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_read.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_read_flags 94 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_read.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_read_hindex 84 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_read.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_read_offset 88 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_read.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_write 96 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_write)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_write_bits 104 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_write.bits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_write_flags 106 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_write.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_write_hindex 96 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_write.hindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_vc4_submit_cl_zs_write_offset 100 __builtin_offsetof(struct __C(drm_vc4_submit_cl), zs_write.offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_version 64 sizeof(struct __C(drm_version))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_version 8 __alignof(struct __C(drm_version))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_date 40 __builtin_offsetof(struct __C(drm_version), date)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_date_len 32 __builtin_offsetof(struct __C(drm_version), date_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_desc 56 __builtin_offsetof(struct __C(drm_version), desc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_desc_len 48 __builtin_offsetof(struct __C(drm_version), desc_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_name 24 __builtin_offsetof(struct __C(drm_version), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_name_len 16 __builtin_offsetof(struct __C(drm_version), name_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_version_major 0 __builtin_offsetof(struct __C(drm_version), version_major)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_version_minor 4 __builtin_offsetof(struct __C(drm_version), version_minor)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_version_version_patchlevel 8 __builtin_offsetof(struct __C(drm_version), version_patchlevel)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_context_init 16 sizeof(struct __C(drm_virtgpu_context_init))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_context_init 8 __alignof(struct __C(drm_virtgpu_context_init))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_context_init_ctx_set_params 8 __builtin_offsetof(struct __C(drm_virtgpu_context_init), ctx_set_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_context_init_num_params 0 __builtin_offsetof(struct __C(drm_virtgpu_context_init), num_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_context_init_pad 4 __builtin_offsetof(struct __C(drm_virtgpu_context_init), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_context_set_param 16 sizeof(struct __C(drm_virtgpu_context_set_param))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_context_set_param 8 __alignof(struct __C(drm_virtgpu_context_set_param))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_context_set_param_param 0 __builtin_offsetof(struct __C(drm_virtgpu_context_set_param), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_context_set_param_value 8 __builtin_offsetof(struct __C(drm_virtgpu_context_set_param), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_execbuffer 64 sizeof(struct __C(drm_virtgpu_execbuffer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_execbuffer 8 __alignof(struct __C(drm_virtgpu_execbuffer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_bo_handles 16 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_command 8 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), command)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_fence_fd 28 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), fence_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_flags 0 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_in_syncobjs 48 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), in_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_num_bo_handles 24 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), num_bo_handles)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_num_in_syncobjs 40 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), num_in_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_num_out_syncobjs 44 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), num_out_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_out_syncobjs 56 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), out_syncobjs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_ring_idx 32 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), ring_idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_size 4 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_execbuffer_syncobj_stride 36 __builtin_offsetof(struct __C(drm_virtgpu_execbuffer), syncobj_stride)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_get_caps 24 sizeof(struct __C(drm_virtgpu_get_caps))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_get_caps 8 __alignof(struct __C(drm_virtgpu_get_caps))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_get_caps_addr 8 __builtin_offsetof(struct __C(drm_virtgpu_get_caps), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_get_caps_cap_set_id 0 __builtin_offsetof(struct __C(drm_virtgpu_get_caps), cap_set_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_get_caps_cap_set_ver 4 __builtin_offsetof(struct __C(drm_virtgpu_get_caps), cap_set_ver)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_get_caps_pad 20 __builtin_offsetof(struct __C(drm_virtgpu_get_caps), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_get_caps_size 16 __builtin_offsetof(struct __C(drm_virtgpu_get_caps), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_getparam 16 sizeof(struct __C(drm_virtgpu_getparam))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_getparam 8 __alignof(struct __C(drm_virtgpu_getparam))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_getparam_param 0 __builtin_offsetof(struct __C(drm_virtgpu_getparam), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_getparam_value 8 __builtin_offsetof(struct __C(drm_virtgpu_getparam), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_virtgpu_resource_create_blob 48 sizeof(struct __C(drm_virtgpu_resource_create_blob))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_virtgpu_resource_create_blob 8 __alignof(struct __C(drm_virtgpu_resource_create_blob))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_blob_flags 4 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), blob_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_blob_id 40 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), blob_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_blob_mem 0 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), blob_mem)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_bo_handle 8 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), bo_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_cmd 32 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_cmd_size 28 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), cmd_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_pad 24 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_res_handle 12 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), res_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_virtgpu_resource_create_blob_size 16 __builtin_offsetof(struct __C(drm_virtgpu_resource_create_blob), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_wait_vblank_request 16 sizeof(struct __C(drm_wait_vblank_request))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_wait_vblank_request 8 __alignof(struct __C(drm_wait_vblank_request))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_sequence 4 __builtin_offsetof(struct __C(drm_wait_vblank_request), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_signal 8 __builtin_offsetof(struct __C(drm_wait_vblank_request), signal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_type 0 __builtin_offsetof(struct __C(drm_wait_vblank_request), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_device_query 40 sizeof(struct __C(drm_xe_device_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_device_query 8 __alignof(struct __C(drm_xe_device_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_device_query_data 16 __builtin_offsetof(struct __C(drm_xe_device_query), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_device_query_extensions 0 __builtin_offsetof(struct __C(drm_xe_device_query), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_device_query_query 8 __builtin_offsetof(struct __C(drm_xe_device_query), query)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_device_query_reserved 24 __builtin_offsetof(struct __C(drm_xe_device_query), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_device_query_size 12 __builtin_offsetof(struct __C(drm_xe_device_query), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_exec 56 sizeof(struct __C(drm_xe_exec))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_exec 8 __alignof(struct __C(drm_xe_exec))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_address 24 __builtin_offsetof(struct __C(drm_xe_exec), address)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_exec_queue_id 8 __builtin_offsetof(struct __C(drm_xe_exec), exec_queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_extensions 0 __builtin_offsetof(struct __C(drm_xe_exec), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_num_batch_buffer 32 __builtin_offsetof(struct __C(drm_xe_exec), num_batch_buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_num_syncs 12 __builtin_offsetof(struct __C(drm_xe_exec), num_syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_pad 34 __builtin_offsetof(struct __C(drm_xe_exec), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_reserved 40 __builtin_offsetof(struct __C(drm_xe_exec), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_syncs 16 __builtin_offsetof(struct __C(drm_xe_exec), syncs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_exec_queue_create 48 sizeof(struct __C(drm_xe_exec_queue_create))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_exec_queue_create 8 __alignof(struct __C(drm_xe_exec_queue_create))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_exec_queue_id 20 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), exec_queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_extensions 0 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_flags 16 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_instances 24 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), instances)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_num_placements 10 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), num_placements)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_reserved 32 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_vm_id 12 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), vm_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_create_width 8 __builtin_offsetof(struct __C(drm_xe_exec_queue_create), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_exec_queue_get_property 40 sizeof(struct __C(drm_xe_exec_queue_get_property))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_exec_queue_get_property 8 __alignof(struct __C(drm_xe_exec_queue_get_property))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_get_property_exec_queue_id 8 __builtin_offsetof(struct __C(drm_xe_exec_queue_get_property), exec_queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_get_property_extensions 0 __builtin_offsetof(struct __C(drm_xe_exec_queue_get_property), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_get_property_property 12 __builtin_offsetof(struct __C(drm_xe_exec_queue_get_property), property)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_get_property_reserved 24 __builtin_offsetof(struct __C(drm_xe_exec_queue_get_property), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_exec_queue_get_property_value 16 __builtin_offsetof(struct __C(drm_xe_exec_queue_get_property), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_ext_set_property 48 sizeof(struct __C(drm_xe_ext_set_property))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_ext_set_property 8 __alignof(struct __C(drm_xe_ext_set_property))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_base 0 __builtin_offsetof(struct __C(drm_xe_ext_set_property), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_base_name 8 __builtin_offsetof(struct __C(drm_xe_ext_set_property), base.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_base_next_extension 0 __builtin_offsetof(struct __C(drm_xe_ext_set_property), base.next_extension)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_base_pad 12 __builtin_offsetof(struct __C(drm_xe_ext_set_property), base.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_pad 20 __builtin_offsetof(struct __C(drm_xe_ext_set_property), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_property 16 __builtin_offsetof(struct __C(drm_xe_ext_set_property), property)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_ext_set_property_value 24 __builtin_offsetof(struct __C(drm_xe_ext_set_property), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_gem_create 56 sizeof(struct __C(drm_xe_gem_create))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_gem_create 8 __alignof(struct __C(drm_xe_gem_create))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_cpu_caching 32 __builtin_offsetof(struct __C(drm_xe_gem_create), cpu_caching)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_extensions 0 __builtin_offsetof(struct __C(drm_xe_gem_create), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_flags 20 __builtin_offsetof(struct __C(drm_xe_gem_create), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_handle 28 __builtin_offsetof(struct __C(drm_xe_gem_create), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_pad 34 __builtin_offsetof(struct __C(drm_xe_gem_create), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_placement 16 __builtin_offsetof(struct __C(drm_xe_gem_create), placement)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_reserved 40 __builtin_offsetof(struct __C(drm_xe_gem_create), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_size 8 __builtin_offsetof(struct __C(drm_xe_gem_create), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_create_vm_id 24 __builtin_offsetof(struct __C(drm_xe_gem_create), vm_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_gem_mmap_offset 40 sizeof(struct __C(drm_xe_gem_mmap_offset))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_gem_mmap_offset 8 __alignof(struct __C(drm_xe_gem_mmap_offset))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_mmap_offset_extensions 0 __builtin_offsetof(struct __C(drm_xe_gem_mmap_offset), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_mmap_offset_flags 12 __builtin_offsetof(struct __C(drm_xe_gem_mmap_offset), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_mmap_offset_handle 8 __builtin_offsetof(struct __C(drm_xe_gem_mmap_offset), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_mmap_offset_offset 16 __builtin_offsetof(struct __C(drm_xe_gem_mmap_offset), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_gem_mmap_offset_reserved 24 __builtin_offsetof(struct __C(drm_xe_gem_mmap_offset), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_oa_config 56 sizeof(struct __C(drm_xe_oa_config))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_oa_config 8 __alignof(struct __C(drm_xe_oa_config))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_config_extensions 0 __builtin_offsetof(struct __C(drm_xe_oa_config), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_config_n_regs 44 __builtin_offsetof(struct __C(drm_xe_oa_config), n_regs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_config_regs_ptr 48 __builtin_offsetof(struct __C(drm_xe_oa_config), regs_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_config_uuid 8 __builtin_offsetof(struct __C(drm_xe_oa_config), uuid)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_oa_stream_info 40 sizeof(struct __C(drm_xe_oa_stream_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_oa_stream_info 8 __alignof(struct __C(drm_xe_oa_stream_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_stream_info_extensions 0 __builtin_offsetof(struct __C(drm_xe_oa_stream_info), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_stream_info_oa_buf_size 8 __builtin_offsetof(struct __C(drm_xe_oa_stream_info), oa_buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_oa_stream_info_reserved 16 __builtin_offsetof(struct __C(drm_xe_oa_stream_info), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_observation_param 32 sizeof(struct __C(drm_xe_observation_param))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_observation_param 8 __alignof(struct __C(drm_xe_observation_param))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_observation_param_extensions 0 __builtin_offsetof(struct __C(drm_xe_observation_param), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_observation_param_observation_op 16 __builtin_offsetof(struct __C(drm_xe_observation_param), observation_op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_observation_param_observation_type 8 __builtin_offsetof(struct __C(drm_xe_observation_param), observation_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_observation_param_param 24 __builtin_offsetof(struct __C(drm_xe_observation_param), param)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_sync 48 sizeof(struct __C(drm_xe_sync))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_sync 8 __alignof(struct __C(drm_xe_sync))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_sync_extensions 0 __builtin_offsetof(struct __C(drm_xe_sync), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_sync_flags 12 __builtin_offsetof(struct __C(drm_xe_sync), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_sync_reserved 32 __builtin_offsetof(struct __C(drm_xe_sync), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_sync_timeline_value 24 __builtin_offsetof(struct __C(drm_xe_sync), timeline_value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_sync_type 8 __builtin_offsetof(struct __C(drm_xe_sync), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_user_extension 16 sizeof(struct __C(drm_xe_user_extension))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_user_extension 8 __alignof(struct __C(drm_xe_user_extension))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_user_extension_name 8 __builtin_offsetof(struct __C(drm_xe_user_extension), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_user_extension_next_extension 0 __builtin_offsetof(struct __C(drm_xe_user_extension), next_extension)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_user_extension_pad 12 __builtin_offsetof(struct __C(drm_xe_user_extension), pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_vm_bind 136 sizeof(struct __C(drm_xe_vm_bind))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_vm_bind 8 __alignof(struct __C(drm_xe_vm_bind))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind 24 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_addr 56 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_cpu_addr_mirror_offset 40 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.cpu_addr_mirror_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_extensions 24 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_flags 68 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_obj 32 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.obj)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_obj_offset 40 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.obj_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_op 64 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_pad 38 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_pad2 76 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_pat_index 36 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.pat_index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_prefetch_mem_region_instance 72 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.prefetch_mem_region_instance)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_range 48 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.range)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_reserved 80 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_bind_userptr 40 __builtin_offsetof(struct __C(drm_xe_vm_bind), bind.userptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_exec_queue_id 12 __builtin_offsetof(struct __C(drm_xe_vm_bind), exec_queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_extensions 0 __builtin_offsetof(struct __C(drm_xe_vm_bind), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_num_binds 20 __builtin_offsetof(struct __C(drm_xe_vm_bind), num_binds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_num_syncs 108 __builtin_offsetof(struct __C(drm_xe_vm_bind), num_syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_pad 16 __builtin_offsetof(struct __C(drm_xe_vm_bind), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_pad2 104 __builtin_offsetof(struct __C(drm_xe_vm_bind), pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_reserved 120 __builtin_offsetof(struct __C(drm_xe_vm_bind), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_syncs 112 __builtin_offsetof(struct __C(drm_xe_vm_bind), syncs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_vector_of_binds 24 __builtin_offsetof(struct __C(drm_xe_vm_bind), vector_of_binds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_vm_id 8 __builtin_offsetof(struct __C(drm_xe_vm_bind), vm_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_vm_bind_op 80 sizeof(struct __C(drm_xe_vm_bind_op))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_vm_bind_op 8 __alignof(struct __C(drm_xe_vm_bind_op))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_addr 32 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_cpu_addr_mirror_offset 16 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), cpu_addr_mirror_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_extensions 0 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_flags 44 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_obj 8 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), obj)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_obj_offset 16 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), obj_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_op 40 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_pad 14 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_pad2 52 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_pat_index 12 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), pat_index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_prefetch_mem_region_instance 48 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), prefetch_mem_region_instance)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_range 24 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), range)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_reserved 56 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_bind_op_userptr 16 __builtin_offsetof(struct __C(drm_xe_vm_bind_op), userptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_vm_create 32 sizeof(struct __C(drm_xe_vm_create))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_vm_create 8 __alignof(struct __C(drm_xe_vm_create))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_create_extensions 0 __builtin_offsetof(struct __C(drm_xe_vm_create), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_create_flags 8 __builtin_offsetof(struct __C(drm_xe_vm_create), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_create_reserved 16 __builtin_offsetof(struct __C(drm_xe_vm_create), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_vm_create_vm_id 12 __builtin_offsetof(struct __C(drm_xe_vm_create), vm_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_drm_xe_wait_user_fence 72 sizeof(struct __C(drm_xe_wait_user_fence))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_drm_xe_wait_user_fence 8 __alignof(struct __C(drm_xe_wait_user_fence))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_addr 8 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_exec_queue_id 48 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), exec_queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_extensions 0 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), extensions)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_flags 18 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_mask 32 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_op 16 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_pad 20 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_pad2 52 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_reserved 56 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_timeout 40 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_xe_wait_user_fence_value 24 __builtin_offsetof(struct __C(drm_xe_wait_user_fence), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dtv_properties 16 sizeof(struct __C(dtv_properties))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dtv_properties 8 __alignof(struct __C(dtv_properties))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_properties_num 0 __builtin_offsetof(struct __C(dtv_properties), num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_properties_props 8 __builtin_offsetof(struct __C(dtv_properties), props)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_dtv_property 76 sizeof(struct __C(dtv_property))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_dtv_property 1 __alignof(struct __C(dtv_property))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_cmd 0 __builtin_offsetof(struct __C(dtv_property), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_reserved 4 __builtin_offsetof(struct __C(dtv_property), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_result 72 __builtin_offsetof(struct __C(dtv_property), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u 16 __builtin_offsetof(struct __C(dtv_property), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_buffer 16 __builtin_offsetof(struct __C(dtv_property), u.buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_buffer_data 16 __builtin_offsetof(struct __C(dtv_property), u.buffer.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_buffer_len 48 __builtin_offsetof(struct __C(dtv_property), u.buffer.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_buffer_reserved1 52 __builtin_offsetof(struct __C(dtv_property), u.buffer.reserved1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_data 16 __builtin_offsetof(struct __C(dtv_property), u.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st 16 __builtin_offsetof(struct __C(dtv_property), u.st)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st_len 16 __builtin_offsetof(struct __C(dtv_property), u.st.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st_stat 17 __builtin_offsetof(struct __C(dtv_property), u.st.stat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st_stat_0__scale 17 __builtin_offsetof(struct __C(dtv_property), u.st.stat[0].scale)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st_stat_0__svalue 18 __builtin_offsetof(struct __C(dtv_property), u.st.stat[0].svalue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_dtv_property_u_st_stat_0__uvalue 18 __builtin_offsetof(struct __C(dtv_property), u.st.stat[0].uvalue)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_entries 48 sizeof(struct __C(ebt_entries))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_entries 8 __alignof(struct __C(ebt_entries))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_counter_offset 36 __builtin_offsetof(struct __C(ebt_entries), counter_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_data 48 __builtin_offsetof(struct __C(ebt_entries), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_distinguisher 0 __builtin_offsetof(struct __C(ebt_entries), distinguisher)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_name 4 __builtin_offsetof(struct __C(ebt_entries), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_nentries 44 __builtin_offsetof(struct __C(ebt_entries), nentries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entries_policy 40 __builtin_offsetof(struct __C(ebt_entries), policy)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_entry 112 sizeof(struct __C(ebt_entry))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_entry 8 __alignof(struct __C(ebt_entry))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_bitmask 0 __builtin_offsetof(struct __C(ebt_entry), bitmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_destmac 86 __builtin_offsetof(struct __C(ebt_entry), destmac)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_destmsk 92 __builtin_offsetof(struct __C(ebt_entry), destmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_elems 112 __builtin_offsetof(struct __C(ebt_entry), elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_ethproto 8 __builtin_offsetof(struct __C(ebt_entry), ethproto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_in 10 __builtin_offsetof(struct __C(ebt_entry), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_invflags 4 __builtin_offsetof(struct __C(ebt_entry), invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_logical_in 26 __builtin_offsetof(struct __C(ebt_entry), logical_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_logical_out 58 __builtin_offsetof(struct __C(ebt_entry), logical_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_next_offset 108 __builtin_offsetof(struct __C(ebt_entry), next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_offsets 100 __builtin_offsetof(struct __C(ebt_entry), offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_offsets_next_offset 108 __builtin_offsetof(struct __C(ebt_entry), offsets.next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_offsets_target_offset 104 __builtin_offsetof(struct __C(ebt_entry), offsets.target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_offsets_watchers_offset 100 __builtin_offsetof(struct __C(ebt_entry), offsets.watchers_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_out 42 __builtin_offsetof(struct __C(ebt_entry), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_sourcemac 74 __builtin_offsetof(struct __C(ebt_entry), sourcemac)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_sourcemsk 80 __builtin_offsetof(struct __C(ebt_entry), sourcemsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_offset 104 __builtin_offsetof(struct __C(ebt_entry), target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watchers_offset 100 __builtin_offsetof(struct __C(ebt_entry), watchers_offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_entry_match 40 sizeof(struct __C(ebt_entry_match))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_entry_match 8 __alignof(struct __C(ebt_entry_match))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_match_data 40 __builtin_offsetof(struct __C(ebt_entry_match), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_match_match_size 32 __builtin_offsetof(struct __C(ebt_entry_match), match_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_match_u 0 __builtin_offsetof(struct __C(ebt_entry_match), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_match_u_name 0 __builtin_offsetof(struct __C(ebt_entry_match), u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_match_u_revision 31 __builtin_offsetof(struct __C(ebt_entry_match), u.revision)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_entry_target 40 sizeof(struct __C(ebt_entry_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_entry_target 8 __alignof(struct __C(ebt_entry_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_data 40 __builtin_offsetof(struct __C(ebt_entry_target), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_target_size 32 __builtin_offsetof(struct __C(ebt_entry_target), target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_u 0 __builtin_offsetof(struct __C(ebt_entry_target), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_u_name 0 __builtin_offsetof(struct __C(ebt_entry_target), u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_target_u_revision 31 __builtin_offsetof(struct __C(ebt_entry_target), u.revision)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_entry_watcher 40 sizeof(struct __C(ebt_entry_watcher))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_entry_watcher 8 __alignof(struct __C(ebt_entry_watcher))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watcher_data 40 __builtin_offsetof(struct __C(ebt_entry_watcher), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watcher_u 0 __builtin_offsetof(struct __C(ebt_entry_watcher), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watcher_u_name 0 __builtin_offsetof(struct __C(ebt_entry_watcher), u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watcher_u_revision 31 __builtin_offsetof(struct __C(ebt_entry_watcher), u.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_entry_watcher_watcher_size 32 __builtin_offsetof(struct __C(ebt_entry_watcher), watcher_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_replace 120 sizeof(struct __C(ebt_replace))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_replace 8 __alignof(struct __C(ebt_replace))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_counters 104 __builtin_offsetof(struct __C(ebt_replace), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_entries 112 __builtin_offsetof(struct __C(ebt_replace), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_entries_size 40 __builtin_offsetof(struct __C(ebt_replace), entries_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_hook_entry 48 __builtin_offsetof(struct __C(ebt_replace), hook_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_name 0 __builtin_offsetof(struct __C(ebt_replace), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_nentries 36 __builtin_offsetof(struct __C(ebt_replace), nentries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_num_counters 96 __builtin_offsetof(struct __C(ebt_replace), num_counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_valid_hooks 32 __builtin_offsetof(struct __C(ebt_replace), valid_hooks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_replace_kernel 120 sizeof(struct __C(ebt_replace_kernel))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_replace_kernel 8 __alignof(struct __C(ebt_replace_kernel))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_counters 104 __builtin_offsetof(struct __C(ebt_replace_kernel), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_entries 112 __builtin_offsetof(struct __C(ebt_replace_kernel), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_entries_size 40 __builtin_offsetof(struct __C(ebt_replace_kernel), entries_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_hook_entry 48 __builtin_offsetof(struct __C(ebt_replace_kernel), hook_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_name 0 __builtin_offsetof(struct __C(ebt_replace_kernel), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_nentries 36 __builtin_offsetof(struct __C(ebt_replace_kernel), nentries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_num_counters 96 __builtin_offsetof(struct __C(ebt_replace_kernel), num_counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_replace_kernel_valid_hooks 32 __builtin_offsetof(struct __C(ebt_replace_kernel), valid_hooks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ebt_standard_target 48 sizeof(struct __C(ebt_standard_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ebt_standard_target 8 __alignof(struct __C(ebt_standard_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target 0 __builtin_offsetof(struct __C(ebt_standard_target), target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target_data 40 __builtin_offsetof(struct __C(ebt_standard_target), target.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target_target_size 32 __builtin_offsetof(struct __C(ebt_standard_target), target.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target_u 0 __builtin_offsetof(struct __C(ebt_standard_target), target.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target_u_name 0 __builtin_offsetof(struct __C(ebt_standard_target), target.u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_target_u_revision 31 __builtin_offsetof(struct __C(ebt_standard_target), target.u.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ebt_standard_target_verdict 40 __builtin_offsetof(struct __C(ebt_standard_target), verdict)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_epoll_event 16 sizeof(struct __C(epoll_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_epoll_event 8 __alignof(struct __C(epoll_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_epoll_event_data 8 __builtin_offsetof(struct __C(epoll_event), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_epoll_event_events 0 __builtin_offsetof(struct __C(epoll_event), events)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ethtool_tunable 16 sizeof(struct __C(ethtool_tunable))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ethtool_tunable 8 __alignof(struct __C(ethtool_tunable))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ethtool_tunable_cmd 0 __builtin_offsetof(struct __C(ethtool_tunable), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ethtool_tunable_data 16 __builtin_offsetof(struct __C(ethtool_tunable), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ethtool_tunable_id 4 __builtin_offsetof(struct __C(ethtool_tunable), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ethtool_tunable_len 12 __builtin_offsetof(struct __C(ethtool_tunable), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ethtool_tunable_type_id 8 __builtin_offsetof(struct __C(ethtool_tunable), type_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fb_cmap 40 sizeof(struct __C(fb_cmap))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fb_cmap 8 __alignof(struct __C(fb_cmap))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_blue 24 __builtin_offsetof(struct __C(fb_cmap), blue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_green 16 __builtin_offsetof(struct __C(fb_cmap), green)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_len 4 __builtin_offsetof(struct __C(fb_cmap), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_red 8 __builtin_offsetof(struct __C(fb_cmap), red)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_start 0 __builtin_offsetof(struct __C(fb_cmap), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cmap_transp 32 __builtin_offsetof(struct __C(fb_cmap), transp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fb_cursor 104 sizeof(struct __C(fb_cursor))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fb_cursor 8 __alignof(struct __C(fb_cursor))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_enable 2 __builtin_offsetof(struct __C(fb_cursor), enable)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_hot 16 __builtin_offsetof(struct __C(fb_cursor), hot)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_hot_x 16 __builtin_offsetof(struct __C(fb_cursor), hot.x)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_hot_y 18 __builtin_offsetof(struct __C(fb_cursor), hot.y)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image 24 __builtin_offsetof(struct __C(fb_cursor), image)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_bg_color 44 __builtin_offsetof(struct __C(fb_cursor), image.bg_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap 64 __builtin_offsetof(struct __C(fb_cursor), image.cmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_blue 88 __builtin_offsetof(struct __C(fb_cursor), image.cmap.blue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_green 80 __builtin_offsetof(struct __C(fb_cursor), image.cmap.green)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_len 68 __builtin_offsetof(struct __C(fb_cursor), image.cmap.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_red 72 __builtin_offsetof(struct __C(fb_cursor), image.cmap.red)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_start 64 __builtin_offsetof(struct __C(fb_cursor), image.cmap.start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_cmap_transp 96 __builtin_offsetof(struct __C(fb_cursor), image.cmap.transp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_data 56 __builtin_offsetof(struct __C(fb_cursor), image.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_depth 48 __builtin_offsetof(struct __C(fb_cursor), image.depth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_dx 24 __builtin_offsetof(struct __C(fb_cursor), image.dx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_dy 28 __builtin_offsetof(struct __C(fb_cursor), image.dy)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_fg_color 40 __builtin_offsetof(struct __C(fb_cursor), image.fg_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_height 36 __builtin_offsetof(struct __C(fb_cursor), image.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_image_width 32 __builtin_offsetof(struct __C(fb_cursor), image.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_mask 8 __builtin_offsetof(struct __C(fb_cursor), mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_rop 4 __builtin_offsetof(struct __C(fb_cursor), rop)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_cursor_set 0 __builtin_offsetof(struct __C(fb_cursor), set)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fb_image 80 sizeof(struct __C(fb_image))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fb_image 8 __alignof(struct __C(fb_image))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_bg_color 20 __builtin_offsetof(struct __C(fb_image), bg_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap 40 __builtin_offsetof(struct __C(fb_image), cmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_blue 64 __builtin_offsetof(struct __C(fb_image), cmap.blue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_green 56 __builtin_offsetof(struct __C(fb_image), cmap.green)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_len 44 __builtin_offsetof(struct __C(fb_image), cmap.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_red 48 __builtin_offsetof(struct __C(fb_image), cmap.red)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_start 40 __builtin_offsetof(struct __C(fb_image), cmap.start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_cmap_transp 72 __builtin_offsetof(struct __C(fb_image), cmap.transp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_data 32 __builtin_offsetof(struct __C(fb_image), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_depth 24 __builtin_offsetof(struct __C(fb_image), depth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_dx 0 __builtin_offsetof(struct __C(fb_image), dx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_dy 4 __builtin_offsetof(struct __C(fb_image), dy)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_fg_color 16 __builtin_offsetof(struct __C(fb_image), fg_color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_height 12 __builtin_offsetof(struct __C(fb_image), height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fb_image_width 8 __builtin_offsetof(struct __C(fb_image), width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ff_effect 48 sizeof(struct __C(ff_effect))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ff_effect 8 __alignof(struct __C(ff_effect))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_direction 4 __builtin_offsetof(struct __C(ff_effect), direction)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_id 2 __builtin_offsetof(struct __C(ff_effect), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_replay 10 __builtin_offsetof(struct __C(ff_effect), replay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_replay_delay 12 __builtin_offsetof(struct __C(ff_effect), replay.delay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_replay_length 10 __builtin_offsetof(struct __C(ff_effect), replay.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_trigger 6 __builtin_offsetof(struct __C(ff_effect), trigger)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_trigger_button 6 __builtin_offsetof(struct __C(ff_effect), trigger.button)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_trigger_interval 8 __builtin_offsetof(struct __C(ff_effect), trigger.interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_type 0 __builtin_offsetof(struct __C(ff_effect), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u 16 __builtin_offsetof(struct __C(ff_effect), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition 16 __builtin_offsetof(struct __C(ff_effect), u.condition)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__center 26 __builtin_offsetof(struct __C(ff_effect), u.condition[0].center)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__deadband 24 __builtin_offsetof(struct __C(ff_effect), u.condition[0].deadband)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__left_coeff 22 __builtin_offsetof(struct __C(ff_effect), u.condition[0].left_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__left_saturation 18 __builtin_offsetof(struct __C(ff_effect), u.condition[0].left_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__right_coeff 20 __builtin_offsetof(struct __C(ff_effect), u.condition[0].right_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_condition_0__right_saturation 16 __builtin_offsetof(struct __C(ff_effect), u.condition[0].right_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant 16 __builtin_offsetof(struct __C(ff_effect), u.constant)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_envelope 18 __builtin_offsetof(struct __C(ff_effect), u.constant.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_envelope_attack_length 18 __builtin_offsetof(struct __C(ff_effect), u.constant.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_envelope_attack_level 20 __builtin_offsetof(struct __C(ff_effect), u.constant.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_envelope_fade_length 22 __builtin_offsetof(struct __C(ff_effect), u.constant.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_envelope_fade_level 24 __builtin_offsetof(struct __C(ff_effect), u.constant.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_constant_level 16 __builtin_offsetof(struct __C(ff_effect), u.constant.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic 16 __builtin_offsetof(struct __C(ff_effect), u.periodic)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_custom_data 40 __builtin_offsetof(struct __C(ff_effect), u.periodic.custom_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_custom_len 36 __builtin_offsetof(struct __C(ff_effect), u.periodic.custom_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_envelope 26 __builtin_offsetof(struct __C(ff_effect), u.periodic.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_envelope_attack_length 26 __builtin_offsetof(struct __C(ff_effect), u.periodic.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_envelope_attack_level 28 __builtin_offsetof(struct __C(ff_effect), u.periodic.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_envelope_fade_length 30 __builtin_offsetof(struct __C(ff_effect), u.periodic.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_envelope_fade_level 32 __builtin_offsetof(struct __C(ff_effect), u.periodic.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_magnitude 20 __builtin_offsetof(struct __C(ff_effect), u.periodic.magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_offset 22 __builtin_offsetof(struct __C(ff_effect), u.periodic.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_period 18 __builtin_offsetof(struct __C(ff_effect), u.periodic.period)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_phase 24 __builtin_offsetof(struct __C(ff_effect), u.periodic.phase)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_periodic_waveform 16 __builtin_offsetof(struct __C(ff_effect), u.periodic.waveform)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp 16 __builtin_offsetof(struct __C(ff_effect), u.ramp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_end_level 18 __builtin_offsetof(struct __C(ff_effect), u.ramp.end_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_envelope 20 __builtin_offsetof(struct __C(ff_effect), u.ramp.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_envelope_attack_length 20 __builtin_offsetof(struct __C(ff_effect), u.ramp.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_envelope_attack_level 22 __builtin_offsetof(struct __C(ff_effect), u.ramp.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_envelope_fade_length 24 __builtin_offsetof(struct __C(ff_effect), u.ramp.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_envelope_fade_level 26 __builtin_offsetof(struct __C(ff_effect), u.ramp.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_ramp_start_level 16 __builtin_offsetof(struct __C(ff_effect), u.ramp.start_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_rumble 16 __builtin_offsetof(struct __C(ff_effect), u.rumble)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_rumble_strong_magnitude 16 __builtin_offsetof(struct __C(ff_effect), u.rumble.strong_magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_effect_u_rumble_weak_magnitude 18 __builtin_offsetof(struct __C(ff_effect), u.rumble.weak_magnitude)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ff_periodic_effect 32 sizeof(struct __C(ff_periodic_effect))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ff_periodic_effect 8 __alignof(struct __C(ff_periodic_effect))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_custom_data 24 __builtin_offsetof(struct __C(ff_periodic_effect), custom_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_custom_len 20 __builtin_offsetof(struct __C(ff_periodic_effect), custom_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_envelope 10 __builtin_offsetof(struct __C(ff_periodic_effect), envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_envelope_attack_length 10 __builtin_offsetof(struct __C(ff_periodic_effect), envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_envelope_attack_level 12 __builtin_offsetof(struct __C(ff_periodic_effect), envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_envelope_fade_length 14 __builtin_offsetof(struct __C(ff_periodic_effect), envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_envelope_fade_level 16 __builtin_offsetof(struct __C(ff_periodic_effect), envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_magnitude 4 __builtin_offsetof(struct __C(ff_periodic_effect), magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_offset 6 __builtin_offsetof(struct __C(ff_periodic_effect), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_period 2 __builtin_offsetof(struct __C(ff_periodic_effect), period)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_phase 8 __builtin_offsetof(struct __C(ff_periodic_effect), phase)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ff_periodic_effect_waveform 0 __builtin_offsetof(struct __C(ff_periodic_effect), waveform)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_floppy_drive_struct 80 sizeof(struct __C(floppy_drive_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_floppy_drive_struct 8 __alignof(struct __C(floppy_drive_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_bufblocks 72 __builtin_offsetof(struct __C(floppy_drive_struct), bufblocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_dmabuf 64 __builtin_offsetof(struct __C(floppy_drive_struct), dmabuf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_fd_device 52 __builtin_offsetof(struct __C(floppy_drive_struct), fd_device)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_fd_ref 48 __builtin_offsetof(struct __C(floppy_drive_struct), fd_ref)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_first_read_date 24 __builtin_offsetof(struct __C(floppy_drive_struct), first_read_date)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_flags 0 __builtin_offsetof(struct __C(floppy_drive_struct), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_generation 40 __builtin_offsetof(struct __C(floppy_drive_struct), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_keep_data 44 __builtin_offsetof(struct __C(floppy_drive_struct), keep_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_last_checked 56 __builtin_offsetof(struct __C(floppy_drive_struct), last_checked)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_maxblock 36 __builtin_offsetof(struct __C(floppy_drive_struct), maxblock)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_maxtrack 38 __builtin_offsetof(struct __C(floppy_drive_struct), maxtrack)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_probed_format 32 __builtin_offsetof(struct __C(floppy_drive_struct), probed_format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_select_date 16 __builtin_offsetof(struct __C(floppy_drive_struct), select_date)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_spinup_date 8 __builtin_offsetof(struct __C(floppy_drive_struct), spinup_date)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_drive_struct_track 34 __builtin_offsetof(struct __C(floppy_drive_struct), track)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_floppy_raw_cmd 104 sizeof(struct __C(floppy_raw_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_floppy_raw_cmd 8 __alignof(struct __C(floppy_raw_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_buffer_length 48 __builtin_offsetof(struct __C(floppy_raw_cmd), buffer_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_cmd 54 __builtin_offsetof(struct __C(floppy_raw_cmd), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_cmd_count 53 __builtin_offsetof(struct __C(floppy_raw_cmd), cmd_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_data 8 __builtin_offsetof(struct __C(floppy_raw_cmd), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_flags 0 __builtin_offsetof(struct __C(floppy_raw_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_fullcmd 54 __builtin_offsetof(struct __C(floppy_raw_cmd), fullcmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_kernel_data 16 __builtin_offsetof(struct __C(floppy_raw_cmd), kernel_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_length 32 __builtin_offsetof(struct __C(floppy_raw_cmd), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_next 24 __builtin_offsetof(struct __C(floppy_raw_cmd), next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_phys_length 40 __builtin_offsetof(struct __C(floppy_raw_cmd), phys_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_rate 52 __builtin_offsetof(struct __C(floppy_raw_cmd), rate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_reply 71 __builtin_offsetof(struct __C(floppy_raw_cmd), reply)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_reply_count 70 __builtin_offsetof(struct __C(floppy_raw_cmd), reply_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_reserved1 96 __builtin_offsetof(struct __C(floppy_raw_cmd), reserved1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_reserved2 100 __builtin_offsetof(struct __C(floppy_raw_cmd), reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_resultcode 92 __builtin_offsetof(struct __C(floppy_raw_cmd), resultcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_raw_cmd_track 88 __builtin_offsetof(struct __C(floppy_raw_cmd), track)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_floppy_struct 32 sizeof(struct __C(floppy_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_floppy_struct 8 __alignof(struct __C(floppy_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_fmt_gap 23 __builtin_offsetof(struct __C(floppy_struct), fmt_gap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_gap 20 __builtin_offsetof(struct __C(floppy_struct), gap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_head 8 __builtin_offsetof(struct __C(floppy_struct), head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_name 24 __builtin_offsetof(struct __C(floppy_struct), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_rate 21 __builtin_offsetof(struct __C(floppy_struct), rate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_sect 4 __builtin_offsetof(struct __C(floppy_struct), sect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_size 0 __builtin_offsetof(struct __C(floppy_struct), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_spec1 22 __builtin_offsetof(struct __C(floppy_struct), spec1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_stretch 16 __builtin_offsetof(struct __C(floppy_struct), stretch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_floppy_struct_track 12 __builtin_offsetof(struct __C(floppy_struct), track)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fsverity_enable_arg 128 sizeof(struct __C(fsverity_enable_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fsverity_enable_arg 8 __alignof(struct __C(fsverity_enable_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg___reserved1 28 __builtin_offsetof(struct __C(fsverity_enable_arg), __reserved1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg___reserved2 40 __builtin_offsetof(struct __C(fsverity_enable_arg), __reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_block_size 8 __builtin_offsetof(struct __C(fsverity_enable_arg), block_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_hash_algorithm 4 __builtin_offsetof(struct __C(fsverity_enable_arg), hash_algorithm)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_salt_ptr 16 __builtin_offsetof(struct __C(fsverity_enable_arg), salt_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_salt_size 12 __builtin_offsetof(struct __C(fsverity_enable_arg), salt_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_sig_ptr 32 __builtin_offsetof(struct __C(fsverity_enable_arg), sig_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_sig_size 24 __builtin_offsetof(struct __C(fsverity_enable_arg), sig_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_enable_arg_version 0 __builtin_offsetof(struct __C(fsverity_enable_arg), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fsverity_read_metadata_arg 40 sizeof(struct __C(fsverity_read_metadata_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fsverity_read_metadata_arg 8 __alignof(struct __C(fsverity_read_metadata_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_read_metadata_arg___reserved 32 __builtin_offsetof(struct __C(fsverity_read_metadata_arg), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_read_metadata_arg_buf_ptr 24 __builtin_offsetof(struct __C(fsverity_read_metadata_arg), buf_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_read_metadata_arg_length 16 __builtin_offsetof(struct __C(fsverity_read_metadata_arg), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_read_metadata_arg_metadata_type 0 __builtin_offsetof(struct __C(fsverity_read_metadata_arg), metadata_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fsverity_read_metadata_arg_offset 8 __builtin_offsetof(struct __C(fsverity_read_metadata_arg), offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_futex_waitv 24 sizeof(struct __C(futex_waitv))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_futex_waitv 8 __alignof(struct __C(futex_waitv))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_futex_waitv___reserved 20 __builtin_offsetof(struct __C(futex_waitv), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_futex_waitv_flags 16 __builtin_offsetof(struct __C(futex_waitv), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_futex_waitv_uaddr 8 __builtin_offsetof(struct __C(futex_waitv), uaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_futex_waitv_val 0 __builtin_offsetof(struct __C(futex_waitv), val)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_add_descriptor 24 sizeof(struct __C(fw_cdev_add_descriptor))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_add_descriptor 8 __alignof(struct __C(fw_cdev_add_descriptor))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_add_descriptor_data 8 __builtin_offsetof(struct __C(fw_cdev_add_descriptor), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_add_descriptor_handle 20 __builtin_offsetof(struct __C(fw_cdev_add_descriptor), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_add_descriptor_immediate 0 __builtin_offsetof(struct __C(fw_cdev_add_descriptor), immediate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_add_descriptor_key 4 __builtin_offsetof(struct __C(fw_cdev_add_descriptor), key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_add_descriptor_length 16 __builtin_offsetof(struct __C(fw_cdev_add_descriptor), length)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_allocate 32 sizeof(struct __C(fw_cdev_allocate))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_allocate 8 __alignof(struct __C(fw_cdev_allocate))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_closure 8 __builtin_offsetof(struct __C(fw_cdev_allocate), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_handle 20 __builtin_offsetof(struct __C(fw_cdev_allocate), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_length 16 __builtin_offsetof(struct __C(fw_cdev_allocate), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_offset 0 __builtin_offsetof(struct __C(fw_cdev_allocate), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_region_end 24 __builtin_offsetof(struct __C(fw_cdev_allocate), region_end)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_allocate_iso_resource 24 sizeof(struct __C(fw_cdev_allocate_iso_resource))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_allocate_iso_resource 8 __alignof(struct __C(fw_cdev_allocate_iso_resource))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_iso_resource_bandwidth 16 __builtin_offsetof(struct __C(fw_cdev_allocate_iso_resource), bandwidth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_iso_resource_channels 8 __builtin_offsetof(struct __C(fw_cdev_allocate_iso_resource), channels)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_iso_resource_closure 0 __builtin_offsetof(struct __C(fw_cdev_allocate_iso_resource), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_allocate_iso_resource_handle 20 __builtin_offsetof(struct __C(fw_cdev_allocate_iso_resource), handle)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_create_iso_context 32 sizeof(struct __C(fw_cdev_create_iso_context))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_create_iso_context 8 __alignof(struct __C(fw_cdev_create_iso_context))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_channel 8 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_closure 16 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_handle 24 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_header_size 4 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), header_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_speed 12 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), speed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_create_iso_context_type 0 __builtin_offsetof(struct __C(fw_cdev_create_iso_context), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_bus_reset 40 sizeof(struct __C(fw_cdev_event_bus_reset))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_bus_reset 8 __alignof(struct __C(fw_cdev_event_bus_reset))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_bm_node_id 20 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), bm_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_generation 32 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_irm_node_id 24 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), irm_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_local_node_id 16 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), local_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_node_id 12 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_root_node_id 28 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), root_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_type 8 __builtin_offsetof(struct __C(fw_cdev_event_bus_reset), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_common 16 sizeof(struct __C(fw_cdev_event_common))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_common 8 __alignof(struct __C(fw_cdev_event_common))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_common_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_common), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_common_type 8 __builtin_offsetof(struct __C(fw_cdev_event_common), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_iso_interrupt 24 sizeof(struct __C(fw_cdev_event_iso_interrupt))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_iso_interrupt 8 __alignof(struct __C(fw_cdev_event_iso_interrupt))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_cycle 12 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt), cycle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_header 20 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt), header)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_header_length 16 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt), header_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_type 8 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_iso_interrupt_mc 16 sizeof(struct __C(fw_cdev_event_iso_interrupt_mc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_iso_interrupt_mc 8 __alignof(struct __C(fw_cdev_event_iso_interrupt_mc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt_mc), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_completed 12 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt_mc), completed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_type 8 __builtin_offsetof(struct __C(fw_cdev_event_iso_interrupt_mc), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_iso_resource 24 sizeof(struct __C(fw_cdev_event_iso_resource))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_iso_resource 8 __alignof(struct __C(fw_cdev_event_iso_resource))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_bandwidth 20 __builtin_offsetof(struct __C(fw_cdev_event_iso_resource), bandwidth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_channel 16 __builtin_offsetof(struct __C(fw_cdev_event_iso_resource), channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_iso_resource), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_handle 12 __builtin_offsetof(struct __C(fw_cdev_event_iso_resource), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_type 8 __builtin_offsetof(struct __C(fw_cdev_event_iso_resource), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_phy_packet 24 sizeof(struct __C(fw_cdev_event_phy_packet))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_phy_packet 8 __alignof(struct __C(fw_cdev_event_phy_packet))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_data 20 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_length 16 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_rcode 12 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet), rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_type 8 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_phy_packet2 24 sizeof(struct __C(fw_cdev_event_phy_packet2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_phy_packet2 8 __alignof(struct __C(fw_cdev_event_phy_packet2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_data 24 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_length 16 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_rcode 12 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_tstamp 20 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_type 8 __builtin_offsetof(struct __C(fw_cdev_event_phy_packet2), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_request 32 sizeof(struct __C(fw_cdev_event_request))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_request 8 __alignof(struct __C(fw_cdev_event_request))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_request), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_data 32 __builtin_offsetof(struct __C(fw_cdev_event_request), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_handle 24 __builtin_offsetof(struct __C(fw_cdev_event_request), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_length 28 __builtin_offsetof(struct __C(fw_cdev_event_request), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_offset 16 __builtin_offsetof(struct __C(fw_cdev_event_request), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_tcode 12 __builtin_offsetof(struct __C(fw_cdev_event_request), tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_type 8 __builtin_offsetof(struct __C(fw_cdev_event_request), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_request2 48 sizeof(struct __C(fw_cdev_event_request2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_request2 8 __alignof(struct __C(fw_cdev_event_request2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_card 32 __builtin_offsetof(struct __C(fw_cdev_event_request2), card)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_request2), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_data 48 __builtin_offsetof(struct __C(fw_cdev_event_request2), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_destination_node_id 28 __builtin_offsetof(struct __C(fw_cdev_event_request2), destination_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_generation 36 __builtin_offsetof(struct __C(fw_cdev_event_request2), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_handle 40 __builtin_offsetof(struct __C(fw_cdev_event_request2), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_length 44 __builtin_offsetof(struct __C(fw_cdev_event_request2), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_offset 16 __builtin_offsetof(struct __C(fw_cdev_event_request2), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_source_node_id 24 __builtin_offsetof(struct __C(fw_cdev_event_request2), source_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_tcode 12 __builtin_offsetof(struct __C(fw_cdev_event_request2), tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_type 8 __builtin_offsetof(struct __C(fw_cdev_event_request2), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_request3 56 sizeof(struct __C(fw_cdev_event_request3))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_request3 8 __alignof(struct __C(fw_cdev_event_request3))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_card 32 __builtin_offsetof(struct __C(fw_cdev_event_request3), card)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_request3), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_data 56 __builtin_offsetof(struct __C(fw_cdev_event_request3), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_destination_node_id 28 __builtin_offsetof(struct __C(fw_cdev_event_request3), destination_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_generation 36 __builtin_offsetof(struct __C(fw_cdev_event_request3), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_handle 40 __builtin_offsetof(struct __C(fw_cdev_event_request3), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_length 44 __builtin_offsetof(struct __C(fw_cdev_event_request3), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_offset 16 __builtin_offsetof(struct __C(fw_cdev_event_request3), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_padding 52 __builtin_offsetof(struct __C(fw_cdev_event_request3), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_source_node_id 24 __builtin_offsetof(struct __C(fw_cdev_event_request3), source_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_tcode 12 __builtin_offsetof(struct __C(fw_cdev_event_request3), tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_tstamp 48 __builtin_offsetof(struct __C(fw_cdev_event_request3), tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_type 8 __builtin_offsetof(struct __C(fw_cdev_event_request3), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_response 24 sizeof(struct __C(fw_cdev_event_response))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_response 8 __alignof(struct __C(fw_cdev_event_response))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_response), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_data 20 __builtin_offsetof(struct __C(fw_cdev_event_response), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_length 16 __builtin_offsetof(struct __C(fw_cdev_event_response), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_rcode 12 __builtin_offsetof(struct __C(fw_cdev_event_response), rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_type 8 __builtin_offsetof(struct __C(fw_cdev_event_response), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_event_response2 32 sizeof(struct __C(fw_cdev_event_response2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_event_response2 8 __alignof(struct __C(fw_cdev_event_response2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_closure 0 __builtin_offsetof(struct __C(fw_cdev_event_response2), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_data 32 __builtin_offsetof(struct __C(fw_cdev_event_response2), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_length 16 __builtin_offsetof(struct __C(fw_cdev_event_response2), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_padding 28 __builtin_offsetof(struct __C(fw_cdev_event_response2), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_rcode 12 __builtin_offsetof(struct __C(fw_cdev_event_response2), rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_request_tstamp 20 __builtin_offsetof(struct __C(fw_cdev_event_response2), request_tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_response_tstamp 24 __builtin_offsetof(struct __C(fw_cdev_event_response2), response_tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_type 8 __builtin_offsetof(struct __C(fw_cdev_event_response2), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_get_info 40 sizeof(struct __C(fw_cdev_get_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_get_info 8 __alignof(struct __C(fw_cdev_get_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_bus_reset 16 __builtin_offsetof(struct __C(fw_cdev_get_info), bus_reset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_bus_reset_closure 24 __builtin_offsetof(struct __C(fw_cdev_get_info), bus_reset_closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_card 32 __builtin_offsetof(struct __C(fw_cdev_get_info), card)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_rom 8 __builtin_offsetof(struct __C(fw_cdev_get_info), rom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_rom_length 4 __builtin_offsetof(struct __C(fw_cdev_get_info), rom_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_get_info_version 0 __builtin_offsetof(struct __C(fw_cdev_get_info), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_queue_iso 24 sizeof(struct __C(fw_cdev_queue_iso))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_queue_iso 8 __alignof(struct __C(fw_cdev_queue_iso))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_queue_iso_data 8 __builtin_offsetof(struct __C(fw_cdev_queue_iso), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_queue_iso_handle 20 __builtin_offsetof(struct __C(fw_cdev_queue_iso), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_queue_iso_packets 0 __builtin_offsetof(struct __C(fw_cdev_queue_iso), packets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_queue_iso_size 16 __builtin_offsetof(struct __C(fw_cdev_queue_iso), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_receive_phy_packets 8 sizeof(struct __C(fw_cdev_receive_phy_packets))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_receive_phy_packets 8 __alignof(struct __C(fw_cdev_receive_phy_packets))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_receive_phy_packets_closure 0 __builtin_offsetof(struct __C(fw_cdev_receive_phy_packets), closure)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_send_phy_packet 24 sizeof(struct __C(fw_cdev_send_phy_packet))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_send_phy_packet 8 __alignof(struct __C(fw_cdev_send_phy_packet))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_phy_packet_closure 0 __builtin_offsetof(struct __C(fw_cdev_send_phy_packet), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_phy_packet_data 8 __builtin_offsetof(struct __C(fw_cdev_send_phy_packet), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_phy_packet_generation 16 __builtin_offsetof(struct __C(fw_cdev_send_phy_packet), generation)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_send_request 40 sizeof(struct __C(fw_cdev_send_request))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_send_request 8 __alignof(struct __C(fw_cdev_send_request))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_closure 16 __builtin_offsetof(struct __C(fw_cdev_send_request), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_data 24 __builtin_offsetof(struct __C(fw_cdev_send_request), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_generation 32 __builtin_offsetof(struct __C(fw_cdev_send_request), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_length 4 __builtin_offsetof(struct __C(fw_cdev_send_request), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_offset 8 __builtin_offsetof(struct __C(fw_cdev_send_request), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_request_tcode 0 __builtin_offsetof(struct __C(fw_cdev_send_request), tcode)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_send_response 24 sizeof(struct __C(fw_cdev_send_response))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_send_response 8 __alignof(struct __C(fw_cdev_send_response))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_response_data 8 __builtin_offsetof(struct __C(fw_cdev_send_response), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_response_handle 16 __builtin_offsetof(struct __C(fw_cdev_send_response), handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_response_length 4 __builtin_offsetof(struct __C(fw_cdev_send_response), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_response_rcode 0 __builtin_offsetof(struct __C(fw_cdev_send_response), rcode)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_fw_cdev_send_stream_packet 40 sizeof(struct __C(fw_cdev_send_stream_packet))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_fw_cdev_send_stream_packet 8 __alignof(struct __C(fw_cdev_send_stream_packet))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_channel 8 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_closure 16 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_data 24 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_generation 32 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_length 0 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_speed 36 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), speed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_sy 12 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), sy)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_send_stream_packet_tag 4 __builtin_offsetof(struct __C(fw_cdev_send_stream_packet), tag)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_hdsp_firmware 8 sizeof(struct __C(hdsp_firmware))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_hdsp_firmware 8 __alignof(struct __C(hdsp_firmware))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_hdsp_firmware_firmware_data 0 __builtin_offsetof(struct __C(hdsp_firmware), firmware_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_hdspm_mixer_ioctl 8 sizeof(struct __C(hdspm_mixer_ioctl))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_hdspm_mixer_ioctl 8 __alignof(struct __C(hdspm_mixer_ioctl))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_hdspm_mixer_ioctl_mixer 0 __builtin_offsetof(struct __C(hdspm_mixer_ioctl), mixer)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_i2c_msg 16 sizeof(struct __C(i2c_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_i2c_msg 8 __alignof(struct __C(i2c_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_msg_addr 0 __builtin_offsetof(struct __C(i2c_msg), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_msg_buf 8 __builtin_offsetof(struct __C(i2c_msg), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_msg_flags 2 __builtin_offsetof(struct __C(i2c_msg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_msg_len 4 __builtin_offsetof(struct __C(i2c_msg), len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_i2c_rdwr_ioctl_data 16 sizeof(struct __C(i2c_rdwr_ioctl_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_i2c_rdwr_ioctl_data 8 __alignof(struct __C(i2c_rdwr_ioctl_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_rdwr_ioctl_data_msgs 0 __builtin_offsetof(struct __C(i2c_rdwr_ioctl_data), msgs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_rdwr_ioctl_data_nmsgs 8 __builtin_offsetof(struct __C(i2c_rdwr_ioctl_data), nmsgs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_i2c_smbus_ioctl_data 16 sizeof(struct __C(i2c_smbus_ioctl_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_i2c_smbus_ioctl_data 8 __alignof(struct __C(i2c_smbus_ioctl_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_smbus_ioctl_data_command 1 __builtin_offsetof(struct __C(i2c_smbus_ioctl_data), command)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_smbus_ioctl_data_data 8 __builtin_offsetof(struct __C(i2c_smbus_ioctl_data), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_smbus_ioctl_data_read_write 0 __builtin_offsetof(struct __C(i2c_smbus_ioctl_data), read_write)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_i2c_smbus_ioctl_data_size 4 __builtin_offsetof(struct __C(i2c_smbus_ioctl_data), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ide_ioctl_request_s 24 sizeof(struct __C(ide_ioctl_request_s))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ide_ioctl_request_s 8 __alignof(struct __C(ide_ioctl_request_s))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_s_in_buffer 16 __builtin_offsetof(struct __C(ide_ioctl_request_s), in_buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_s_out_buffer 8 __builtin_offsetof(struct __C(ide_ioctl_request_s), out_buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ide_ioctl_request_s_task_request 0 __builtin_offsetof(struct __C(ide_ioctl_request_s), task_request)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_idletimer_tg_info 40 sizeof(struct __C(idletimer_tg_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_idletimer_tg_info 8 __alignof(struct __C(idletimer_tg_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_label 4 __builtin_offsetof(struct __C(idletimer_tg_info), label)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_timeout 0 __builtin_offsetof(struct __C(idletimer_tg_info), timeout)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_idletimer_tg_info_v1 48 sizeof(struct __C(idletimer_tg_info_v1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_idletimer_tg_info_v1 8 __alignof(struct __C(idletimer_tg_info_v1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_v1_label 4 __builtin_offsetof(struct __C(idletimer_tg_info_v1), label)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_v1_send_nl_msg 32 __builtin_offsetof(struct __C(idletimer_tg_info_v1), send_nl_msg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_v1_timeout 0 __builtin_offsetof(struct __C(idletimer_tg_info_v1), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_idletimer_tg_info_v1_timer_type 33 __builtin_offsetof(struct __C(idletimer_tg_info_v1), timer_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_if_settings 16 sizeof(struct __C(if_settings))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_if_settings 8 __alignof(struct __C(if_settings))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_cisco 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.cisco)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_fr 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.fr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_fr_pvc 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.fr_pvc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_fr_pvc_info 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.fr_pvc_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_raw_hdlc 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.raw_hdlc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_sync 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_te1 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.te1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_ifs_ifsu_x25 8 __builtin_offsetof(struct __C(if_settings), ifs_ifsu.x25)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_size 4 __builtin_offsetof(struct __C(if_settings), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_if_settings_type 0 __builtin_offsetof(struct __C(if_settings), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ifconf 16 sizeof(struct __C(ifconf))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ifconf 8 __alignof(struct __C(ifconf))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifconf_ifc_ifcu 8 __builtin_offsetof(struct __C(ifconf), ifc_ifcu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifconf_ifc_ifcu_ifcu_buf 8 __builtin_offsetof(struct __C(ifconf), ifc_ifcu.ifcu_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifconf_ifc_ifcu_ifcu_req 8 __builtin_offsetof(struct __C(ifconf), ifc_ifcu.ifcu_req)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifconf_ifc_len 0 __builtin_offsetof(struct __C(ifconf), ifc_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ifreq 40 sizeof(struct __C(ifreq))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ifreq 8 __alignof(struct __C(ifreq))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifrn 0 __builtin_offsetof(struct __C(ifreq), ifr_ifrn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifrn_ifrn_name 0 __builtin_offsetof(struct __C(ifreq), ifr_ifrn.ifrn_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_addr 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_broadaddr 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_broadaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_data 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_dstaddr 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_dstaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_flags 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_hwaddr 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_hwaddr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_ivalue 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_ivalue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_base_addr 32 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.base_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_dma 35 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.dma)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_irq 34 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.irq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_mem_end 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.mem_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_mem_start 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.mem_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_map_port 36 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_map.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_mtu 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_mtu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_netmask 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_netmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_newname 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_newname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_cisco 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.cisco)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_fr 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.fr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_fr_pvc 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.fr_pvc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_fr_pvc_info 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.fr_pvc_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_raw_hdlc 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.raw_hdlc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_sync 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_te1 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.te1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_ifs_ifsu_x25 24 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.ifs_ifsu.x25)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_size 20 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_settings_type 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_settings.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ifreq_ifr_ifru_ifru_slave 16 __builtin_offsetof(struct __C(ifreq), ifr_ifru.ifru_slave)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_input_mask 16 sizeof(struct __C(input_mask))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_input_mask 8 __alignof(struct __C(input_mask))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_input_mask_codes_ptr 8 __builtin_offsetof(struct __C(input_mask), codes_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_input_mask_codes_size 4 __builtin_offsetof(struct __C(input_mask), codes_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_input_mask_type 0 __builtin_offsetof(struct __C(input_mask), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_cqring_offsets 40 sizeof(struct __C(io_cqring_offsets))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_cqring_offsets 8 __alignof(struct __C(io_cqring_offsets))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_cqes 20 __builtin_offsetof(struct __C(io_cqring_offsets), cqes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_flags 24 __builtin_offsetof(struct __C(io_cqring_offsets), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_head 0 __builtin_offsetof(struct __C(io_cqring_offsets), head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_overflow 16 __builtin_offsetof(struct __C(io_cqring_offsets), overflow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_resv1 28 __builtin_offsetof(struct __C(io_cqring_offsets), resv1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_ring_entries 12 __builtin_offsetof(struct __C(io_cqring_offsets), ring_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_ring_mask 8 __builtin_offsetof(struct __C(io_cqring_offsets), ring_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_tail 4 __builtin_offsetof(struct __C(io_cqring_offsets), tail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_cqring_offsets_user_addr 32 __builtin_offsetof(struct __C(io_cqring_offsets), user_addr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_event 32 sizeof(struct __C(io_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_event 8 __alignof(struct __C(io_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_event_data 0 __builtin_offsetof(struct __C(io_event), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_event_obj 8 __builtin_offsetof(struct __C(io_event), obj)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_event_res 16 __builtin_offsetof(struct __C(io_event), res)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_event_res2 24 __builtin_offsetof(struct __C(io_event), res2)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_sqring_offsets 40 sizeof(struct __C(io_sqring_offsets))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_sqring_offsets 8 __alignof(struct __C(io_sqring_offsets))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_array 24 __builtin_offsetof(struct __C(io_sqring_offsets), array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_dropped 20 __builtin_offsetof(struct __C(io_sqring_offsets), dropped)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_flags 16 __builtin_offsetof(struct __C(io_sqring_offsets), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_head 0 __builtin_offsetof(struct __C(io_sqring_offsets), head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_resv1 28 __builtin_offsetof(struct __C(io_sqring_offsets), resv1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_ring_entries 12 __builtin_offsetof(struct __C(io_sqring_offsets), ring_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_ring_mask 8 __builtin_offsetof(struct __C(io_sqring_offsets), ring_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_tail 4 __builtin_offsetof(struct __C(io_sqring_offsets), tail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_sqring_offsets_user_addr 32 __builtin_offsetof(struct __C(io_sqring_offsets), user_addr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_attr_pi 32 sizeof(struct __C(io_uring_attr_pi))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_attr_pi 8 __alignof(struct __C(io_uring_attr_pi))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_addr 8 __builtin_offsetof(struct __C(io_uring_attr_pi), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_app_tag 2 __builtin_offsetof(struct __C(io_uring_attr_pi), app_tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_flags 0 __builtin_offsetof(struct __C(io_uring_attr_pi), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_len 4 __builtin_offsetof(struct __C(io_uring_attr_pi), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_rsvd 24 __builtin_offsetof(struct __C(io_uring_attr_pi), rsvd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_attr_pi_seed 16 __builtin_offsetof(struct __C(io_uring_attr_pi), seed)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_buf 16 sizeof(struct __C(io_uring_buf))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_buf 8 __alignof(struct __C(io_uring_buf))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_addr 0 __builtin_offsetof(struct __C(io_uring_buf), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_bid 12 __builtin_offsetof(struct __C(io_uring_buf), bid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_len 8 __builtin_offsetof(struct __C(io_uring_buf), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_resv 14 __builtin_offsetof(struct __C(io_uring_buf), resv)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_buf_reg 40 sizeof(struct __C(io_uring_buf_reg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_buf_reg 8 __alignof(struct __C(io_uring_buf_reg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_reg_bgid 12 __builtin_offsetof(struct __C(io_uring_buf_reg), bgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_reg_flags 14 __builtin_offsetof(struct __C(io_uring_buf_reg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_reg_resv 16 __builtin_offsetof(struct __C(io_uring_buf_reg), resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_reg_ring_addr 0 __builtin_offsetof(struct __C(io_uring_buf_reg), ring_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_reg_ring_entries 8 __builtin_offsetof(struct __C(io_uring_buf_reg), ring_entries)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_buf_ring 16 sizeof(struct __C(io_uring_buf_ring))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_buf_ring 8 __alignof(struct __C(io_uring_buf_ring))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_bufs 0 __builtin_offsetof(struct __C(io_uring_buf_ring), bufs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_bufs_0__addr 0 __builtin_offsetof(struct __C(io_uring_buf_ring), bufs[0].addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_bufs_0__bid 12 __builtin_offsetof(struct __C(io_uring_buf_ring), bufs[0].bid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_bufs_0__len 8 __builtin_offsetof(struct __C(io_uring_buf_ring), bufs[0].len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_bufs_0__resv 14 __builtin_offsetof(struct __C(io_uring_buf_ring), bufs[0].resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_buf_ring_tail 14 __builtin_offsetof(struct __C(io_uring_buf_ring), tail)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_cqe 16 sizeof(struct __C(io_uring_cqe))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_cqe 8 __alignof(struct __C(io_uring_cqe))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_cqe_big_cqe 16 __builtin_offsetof(struct __C(io_uring_cqe), big_cqe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_cqe_flags 12 __builtin_offsetof(struct __C(io_uring_cqe), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_cqe_res 8 __builtin_offsetof(struct __C(io_uring_cqe), res)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_cqe_user_data 0 __builtin_offsetof(struct __C(io_uring_cqe), user_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_files_update 16 sizeof(struct __C(io_uring_files_update))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_files_update 8 __alignof(struct __C(io_uring_files_update))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_files_update_fds 8 __builtin_offsetof(struct __C(io_uring_files_update), fds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_files_update_offset 0 __builtin_offsetof(struct __C(io_uring_files_update), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_files_update_resv 4 __builtin_offsetof(struct __C(io_uring_files_update), resv)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_getevents_arg 24 sizeof(struct __C(io_uring_getevents_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_getevents_arg 8 __alignof(struct __C(io_uring_getevents_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_getevents_arg_min_wait_usec 12 __builtin_offsetof(struct __C(io_uring_getevents_arg), min_wait_usec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_getevents_arg_sigmask 0 __builtin_offsetof(struct __C(io_uring_getevents_arg), sigmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_getevents_arg_sigmask_sz 8 __builtin_offsetof(struct __C(io_uring_getevents_arg), sigmask_sz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_getevents_arg_ts 16 __builtin_offsetof(struct __C(io_uring_getevents_arg), ts)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_mem_region_reg 32 sizeof(struct __C(io_uring_mem_region_reg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_mem_region_reg 8 __alignof(struct __C(io_uring_mem_region_reg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_mem_region_reg___resv 16 __builtin_offsetof(struct __C(io_uring_mem_region_reg), __resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_mem_region_reg_flags 8 __builtin_offsetof(struct __C(io_uring_mem_region_reg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_mem_region_reg_region_uptr 0 __builtin_offsetof(struct __C(io_uring_mem_region_reg), region_uptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_params 120 sizeof(struct __C(io_uring_params))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_params 8 __alignof(struct __C(io_uring_params))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_entries 4 __builtin_offsetof(struct __C(io_uring_params), cq_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off 80 __builtin_offsetof(struct __C(io_uring_params), cq_off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_cqes 100 __builtin_offsetof(struct __C(io_uring_params), cq_off.cqes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_flags 104 __builtin_offsetof(struct __C(io_uring_params), cq_off.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_head 80 __builtin_offsetof(struct __C(io_uring_params), cq_off.head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_overflow 96 __builtin_offsetof(struct __C(io_uring_params), cq_off.overflow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_resv1 108 __builtin_offsetof(struct __C(io_uring_params), cq_off.resv1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_ring_entries 92 __builtin_offsetof(struct __C(io_uring_params), cq_off.ring_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_ring_mask 88 __builtin_offsetof(struct __C(io_uring_params), cq_off.ring_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_tail 84 __builtin_offsetof(struct __C(io_uring_params), cq_off.tail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_cq_off_user_addr 112 __builtin_offsetof(struct __C(io_uring_params), cq_off.user_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_features 20 __builtin_offsetof(struct __C(io_uring_params), features)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_flags 8 __builtin_offsetof(struct __C(io_uring_params), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_resv 28 __builtin_offsetof(struct __C(io_uring_params), resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_entries 0 __builtin_offsetof(struct __C(io_uring_params), sq_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off 40 __builtin_offsetof(struct __C(io_uring_params), sq_off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_array 64 __builtin_offsetof(struct __C(io_uring_params), sq_off.array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_dropped 60 __builtin_offsetof(struct __C(io_uring_params), sq_off.dropped)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_flags 56 __builtin_offsetof(struct __C(io_uring_params), sq_off.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_head 40 __builtin_offsetof(struct __C(io_uring_params), sq_off.head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_resv1 68 __builtin_offsetof(struct __C(io_uring_params), sq_off.resv1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_ring_entries 52 __builtin_offsetof(struct __C(io_uring_params), sq_off.ring_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_ring_mask 48 __builtin_offsetof(struct __C(io_uring_params), sq_off.ring_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_tail 44 __builtin_offsetof(struct __C(io_uring_params), sq_off.tail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_off_user_addr 72 __builtin_offsetof(struct __C(io_uring_params), sq_off.user_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_thread_cpu 12 __builtin_offsetof(struct __C(io_uring_params), sq_thread_cpu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_sq_thread_idle 16 __builtin_offsetof(struct __C(io_uring_params), sq_thread_idle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_params_wq_fd 24 __builtin_offsetof(struct __C(io_uring_params), wq_fd)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_reg_wait 64 sizeof(struct __C(io_uring_reg_wait))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_reg_wait 8 __alignof(struct __C(io_uring_reg_wait))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_flags 20 __builtin_offsetof(struct __C(io_uring_reg_wait), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_min_wait_usec 16 __builtin_offsetof(struct __C(io_uring_reg_wait), min_wait_usec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_pad 36 __builtin_offsetof(struct __C(io_uring_reg_wait), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_sigmask 24 __builtin_offsetof(struct __C(io_uring_reg_wait), sigmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_sigmask_sz 32 __builtin_offsetof(struct __C(io_uring_reg_wait), sigmask_sz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_ts 0 __builtin_offsetof(struct __C(io_uring_reg_wait), ts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_ts_tv_nsec 8 __builtin_offsetof(struct __C(io_uring_reg_wait), ts.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_reg_wait_ts_tv_sec 0 __builtin_offsetof(struct __C(io_uring_reg_wait), ts.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_region_desc 64 sizeof(struct __C(io_uring_region_desc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_region_desc 8 __alignof(struct __C(io_uring_region_desc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc___resv 32 __builtin_offsetof(struct __C(io_uring_region_desc), __resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc_flags 16 __builtin_offsetof(struct __C(io_uring_region_desc), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc_id 20 __builtin_offsetof(struct __C(io_uring_region_desc), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc_mmap_offset 24 __builtin_offsetof(struct __C(io_uring_region_desc), mmap_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc_size 8 __builtin_offsetof(struct __C(io_uring_region_desc), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_region_desc_user_addr 0 __builtin_offsetof(struct __C(io_uring_region_desc), user_addr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_rsrc_register 32 sizeof(struct __C(io_uring_rsrc_register))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_rsrc_register 8 __alignof(struct __C(io_uring_rsrc_register))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_register_data 16 __builtin_offsetof(struct __C(io_uring_rsrc_register), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_register_flags 4 __builtin_offsetof(struct __C(io_uring_rsrc_register), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_register_nr 0 __builtin_offsetof(struct __C(io_uring_rsrc_register), nr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_register_resv2 8 __builtin_offsetof(struct __C(io_uring_rsrc_register), resv2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_register_tags 24 __builtin_offsetof(struct __C(io_uring_rsrc_register), tags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_rsrc_update 16 sizeof(struct __C(io_uring_rsrc_update))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_rsrc_update 8 __alignof(struct __C(io_uring_rsrc_update))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update_data 8 __builtin_offsetof(struct __C(io_uring_rsrc_update), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update_offset 0 __builtin_offsetof(struct __C(io_uring_rsrc_update), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update_resv 4 __builtin_offsetof(struct __C(io_uring_rsrc_update), resv)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_rsrc_update2 32 sizeof(struct __C(io_uring_rsrc_update2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_rsrc_update2 8 __alignof(struct __C(io_uring_rsrc_update2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_data 8 __builtin_offsetof(struct __C(io_uring_rsrc_update2), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_nr 24 __builtin_offsetof(struct __C(io_uring_rsrc_update2), nr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_offset 0 __builtin_offsetof(struct __C(io_uring_rsrc_update2), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_resv 4 __builtin_offsetof(struct __C(io_uring_rsrc_update2), resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_resv2 28 __builtin_offsetof(struct __C(io_uring_rsrc_update2), resv2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_rsrc_update2_tags 16 __builtin_offsetof(struct __C(io_uring_rsrc_update2), tags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_sqe 64 sizeof(struct __C(io_uring_sqe))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_sqe 8 __alignof(struct __C(io_uring_sqe))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe___pad1 12 __builtin_offsetof(struct __C(io_uring_sqe), __pad1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe___pad2 56 __builtin_offsetof(struct __C(io_uring_sqe), __pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe___pad3 46 __builtin_offsetof(struct __C(io_uring_sqe), __pad3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe___pad4 45 __builtin_offsetof(struct __C(io_uring_sqe), __pad4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_accept_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), accept_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_addr 16 __builtin_offsetof(struct __C(io_uring_sqe), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_addr2 8 __builtin_offsetof(struct __C(io_uring_sqe), addr2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_addr3 48 __builtin_offsetof(struct __C(io_uring_sqe), addr3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_addr_len 44 __builtin_offsetof(struct __C(io_uring_sqe), addr_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_attr_ptr 48 __builtin_offsetof(struct __C(io_uring_sqe), attr_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_attr_type_mask 56 __builtin_offsetof(struct __C(io_uring_sqe), attr_type_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_buf_group 40 __builtin_offsetof(struct __C(io_uring_sqe), buf_group)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_buf_index 40 __builtin_offsetof(struct __C(io_uring_sqe), buf_index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_cancel_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), cancel_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_cmd 48 __builtin_offsetof(struct __C(io_uring_sqe), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_cmd_op 8 __builtin_offsetof(struct __C(io_uring_sqe), cmd_op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_fadvise_advice 28 __builtin_offsetof(struct __C(io_uring_sqe), fadvise_advice)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_fd 4 __builtin_offsetof(struct __C(io_uring_sqe), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_file_index 44 __builtin_offsetof(struct __C(io_uring_sqe), file_index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_flags 1 __builtin_offsetof(struct __C(io_uring_sqe), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_fsync_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), fsync_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_futex_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), futex_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_hardlink_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), hardlink_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_install_fd_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), install_fd_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_ioprio 2 __builtin_offsetof(struct __C(io_uring_sqe), ioprio)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_len 24 __builtin_offsetof(struct __C(io_uring_sqe), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_level 16 __builtin_offsetof(struct __C(io_uring_sqe), level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_msg_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), msg_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_msg_ring_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), msg_ring_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_nop_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), nop_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_off 8 __builtin_offsetof(struct __C(io_uring_sqe), off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_opcode 0 __builtin_offsetof(struct __C(io_uring_sqe), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_open_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), open_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_optlen 44 __builtin_offsetof(struct __C(io_uring_sqe), optlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_optname 20 __builtin_offsetof(struct __C(io_uring_sqe), optname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_optval 48 __builtin_offsetof(struct __C(io_uring_sqe), optval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_personality 42 __builtin_offsetof(struct __C(io_uring_sqe), personality)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_pipe_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), pipe_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_poll32_events 28 __builtin_offsetof(struct __C(io_uring_sqe), poll32_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_poll_events 28 __builtin_offsetof(struct __C(io_uring_sqe), poll_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_rename_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), rename_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_rw_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), rw_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_splice_fd_in 44 __builtin_offsetof(struct __C(io_uring_sqe), splice_fd_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_splice_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), splice_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_splice_off_in 16 __builtin_offsetof(struct __C(io_uring_sqe), splice_off_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_statx_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), statx_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_sync_range_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), sync_range_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_timeout_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), timeout_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_unlink_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), unlink_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_uring_cmd_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), uring_cmd_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_user_data 32 __builtin_offsetof(struct __C(io_uring_sqe), user_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_waitid_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), waitid_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_write_stream 44 __builtin_offsetof(struct __C(io_uring_sqe), write_stream)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_xattr_flags 28 __builtin_offsetof(struct __C(io_uring_sqe), xattr_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sqe_zcrx_ifq_idx 44 __builtin_offsetof(struct __C(io_uring_sqe), zcrx_ifq_idx)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_sync_cancel_reg 64 sizeof(struct __C(io_uring_sync_cancel_reg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_sync_cancel_reg 8 __alignof(struct __C(io_uring_sync_cancel_reg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_addr 0 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_fd 8 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_flags 12 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_opcode 32 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_pad 33 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_pad2 40 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_timeout 16 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_timeout_tv_nsec 24 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), timeout.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_sync_cancel_reg_timeout_tv_sec 16 __builtin_offsetof(struct __C(io_uring_sync_cancel_reg), timeout.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_zcrx_area_reg 48 sizeof(struct __C(io_uring_zcrx_area_reg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_zcrx_area_reg 8 __alignof(struct __C(io_uring_zcrx_area_reg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg___resv2 32 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), __resv2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg_addr 0 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg_dmabuf_fd 28 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), dmabuf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg_flags 24 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg_len 8 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_area_reg_rq_area_token 16 __builtin_offsetof(struct __C(io_uring_zcrx_area_reg), rq_area_token)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_io_uring_zcrx_ifq_reg 96 sizeof(struct __C(io_uring_zcrx_ifq_reg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_io_uring_zcrx_ifq_reg 8 __alignof(struct __C(io_uring_zcrx_ifq_reg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg___resv 72 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), __resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg___resv2 68 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), __resv2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_area_ptr 16 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), area_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_flags 12 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_if_idx 0 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), if_idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_if_rxq 4 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), if_rxq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets 32 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets___resv 48 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets.__resv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets___resv2 44 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets.__resv2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets_head 32 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets.head)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets_rqes 40 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets.rqes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_offsets_tail 36 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), offsets.tail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_region_ptr 24 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), region_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_rq_entries 8 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), rq_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_io_uring_zcrx_ifq_reg_zcrx_id 64 __builtin_offsetof(struct __C(io_uring_zcrx_ifq_reg), zcrx_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iocb 64 sizeof(struct __C(iocb))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iocb 8 __alignof(struct __C(iocb))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_buf 24 __builtin_offsetof(struct __C(iocb), aio_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_data 0 __builtin_offsetof(struct __C(iocb), aio_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_fildes 20 __builtin_offsetof(struct __C(iocb), aio_fildes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_flags 56 __builtin_offsetof(struct __C(iocb), aio_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_key 8 __builtin_offsetof(struct __C(iocb), aio_key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_lio_opcode 16 __builtin_offsetof(struct __C(iocb), aio_lio_opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_nbytes 32 __builtin_offsetof(struct __C(iocb), aio_nbytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_offset 40 __builtin_offsetof(struct __C(iocb), aio_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_reqprio 18 __builtin_offsetof(struct __C(iocb), aio_reqprio)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_reserved2 48 __builtin_offsetof(struct __C(iocb), aio_reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_resfd 60 __builtin_offsetof(struct __C(iocb), aio_resfd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iocb_aio_rw_flags 12 __builtin_offsetof(struct __C(iocb), aio_rw_flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_hw_info 40 sizeof(struct __C(iommu_hw_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_hw_info 8 __alignof(struct __C(iommu_hw_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info___reserved 29 __builtin_offsetof(struct __C(iommu_hw_info), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_data_len 12 __builtin_offsetof(struct __C(iommu_hw_info), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_data_uptr 16 __builtin_offsetof(struct __C(iommu_hw_info), data_uptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_dev_id 8 __builtin_offsetof(struct __C(iommu_hw_info), dev_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_flags 4 __builtin_offsetof(struct __C(iommu_hw_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_out_capabilities 32 __builtin_offsetof(struct __C(iommu_hw_info), out_capabilities)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_out_data_type 24 __builtin_offsetof(struct __C(iommu_hw_info), out_data_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_out_max_pasid_log2 28 __builtin_offsetof(struct __C(iommu_hw_info), out_max_pasid_log2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hw_info_size 0 __builtin_offsetof(struct __C(iommu_hw_info), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_hwpt_alloc 48 sizeof(struct __C(iommu_hwpt_alloc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_hwpt_alloc 8 __alignof(struct __C(iommu_hwpt_alloc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc___reserved 20 __builtin_offsetof(struct __C(iommu_hwpt_alloc), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc___reserved2 44 __builtin_offsetof(struct __C(iommu_hwpt_alloc), __reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_data_len 28 __builtin_offsetof(struct __C(iommu_hwpt_alloc), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_data_type 24 __builtin_offsetof(struct __C(iommu_hwpt_alloc), data_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_data_uptr 32 __builtin_offsetof(struct __C(iommu_hwpt_alloc), data_uptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_dev_id 8 __builtin_offsetof(struct __C(iommu_hwpt_alloc), dev_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_fault_id 40 __builtin_offsetof(struct __C(iommu_hwpt_alloc), fault_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_flags 4 __builtin_offsetof(struct __C(iommu_hwpt_alloc), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_out_hwpt_id 16 __builtin_offsetof(struct __C(iommu_hwpt_alloc), out_hwpt_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_pt_id 12 __builtin_offsetof(struct __C(iommu_hwpt_alloc), pt_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_alloc_size 0 __builtin_offsetof(struct __C(iommu_hwpt_alloc), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_hwpt_get_dirty_bitmap 48 sizeof(struct __C(iommu_hwpt_get_dirty_bitmap))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_hwpt_get_dirty_bitmap 8 __alignof(struct __C(iommu_hwpt_get_dirty_bitmap))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap___reserved 12 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_data 40 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_flags 8 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_hwpt_id 4 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), hwpt_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_iova 16 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), iova)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_length 24 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_page_size 32 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), page_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_get_dirty_bitmap_size 0 __builtin_offsetof(struct __C(iommu_hwpt_get_dirty_bitmap), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_hwpt_invalidate 32 sizeof(struct __C(iommu_hwpt_invalidate))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_hwpt_invalidate 8 __alignof(struct __C(iommu_hwpt_invalidate))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate___reserved 28 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_data_type 16 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), data_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_data_uptr 8 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), data_uptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_entry_len 20 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), entry_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_entry_num 24 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), entry_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_hwpt_id 4 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), hwpt_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_hwpt_invalidate_size 0 __builtin_offsetof(struct __C(iommu_hwpt_invalidate), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_ioas_allow_iovas 24 sizeof(struct __C(iommu_ioas_allow_iovas))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_ioas_allow_iovas 8 __alignof(struct __C(iommu_ioas_allow_iovas))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_allow_iovas___reserved 12 __builtin_offsetof(struct __C(iommu_ioas_allow_iovas), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_allow_iovas_allowed_iovas 16 __builtin_offsetof(struct __C(iommu_ioas_allow_iovas), allowed_iovas)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_allow_iovas_ioas_id 4 __builtin_offsetof(struct __C(iommu_ioas_allow_iovas), ioas_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_allow_iovas_num_iovas 8 __builtin_offsetof(struct __C(iommu_ioas_allow_iovas), num_iovas)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_allow_iovas_size 0 __builtin_offsetof(struct __C(iommu_ioas_allow_iovas), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_ioas_iova_ranges 32 sizeof(struct __C(iommu_ioas_iova_ranges))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_ioas_iova_ranges 8 __alignof(struct __C(iommu_ioas_iova_ranges))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges___reserved 12 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges_allowed_iovas 16 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), allowed_iovas)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges_ioas_id 4 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), ioas_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges_num_iovas 8 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), num_iovas)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges_out_iova_alignment 24 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), out_iova_alignment)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_iova_ranges_size 0 __builtin_offsetof(struct __C(iommu_ioas_iova_ranges), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iommu_ioas_map 40 sizeof(struct __C(iommu_ioas_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iommu_ioas_map 8 __alignof(struct __C(iommu_ioas_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map___reserved 12 __builtin_offsetof(struct __C(iommu_ioas_map), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_flags 4 __builtin_offsetof(struct __C(iommu_ioas_map), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_ioas_id 8 __builtin_offsetof(struct __C(iommu_ioas_map), ioas_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_iova 32 __builtin_offsetof(struct __C(iommu_ioas_map), iova)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_length 24 __builtin_offsetof(struct __C(iommu_ioas_map), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_size 0 __builtin_offsetof(struct __C(iommu_ioas_map), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iommu_ioas_map_user_va 16 __builtin_offsetof(struct __C(iommu_ioas_map), user_va)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iovec 16 sizeof(struct __C(iovec))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iovec 8 __alignof(struct __C(iovec))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iovec_iov_base 0 __builtin_offsetof(struct __C(iovec), iov_base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iovec_iov_len 8 __builtin_offsetof(struct __C(iovec), iov_len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ip6t_entry 168 sizeof(struct __C(ip6t_entry))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ip6t_entry 8 __alignof(struct __C(ip6t_entry))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_comefrom 144 __builtin_offsetof(struct __C(ip6t_entry), comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_counters 152 __builtin_offsetof(struct __C(ip6t_entry), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_counters_bcnt 160 __builtin_offsetof(struct __C(ip6t_entry), counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_counters_pcnt 152 __builtin_offsetof(struct __C(ip6t_entry), counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_elems 168 __builtin_offsetof(struct __C(ip6t_entry), elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dmsk 48 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dmsk_in6_u 48 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dmsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dmsk_in6_u_u6_addr16 48 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dmsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dmsk_in6_u_u6_addr32 48 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dmsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dmsk_in6_u_u6_addr8 48 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dmsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dst 16 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dst_in6_u 16 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dst.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dst_in6_u_u6_addr16 16 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dst.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dst_in6_u_u6_addr32 16 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dst.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_dst_in6_u_u6_addr8 16 __builtin_offsetof(struct __C(ip6t_entry), ipv6.dst.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_flags 131 __builtin_offsetof(struct __C(ip6t_entry), ipv6.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_iniface 64 __builtin_offsetof(struct __C(ip6t_entry), ipv6.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_iniface_mask 96 __builtin_offsetof(struct __C(ip6t_entry), ipv6.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_invflags 132 __builtin_offsetof(struct __C(ip6t_entry), ipv6.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_outiface 80 __builtin_offsetof(struct __C(ip6t_entry), ipv6.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_outiface_mask 112 __builtin_offsetof(struct __C(ip6t_entry), ipv6.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_proto 128 __builtin_offsetof(struct __C(ip6t_entry), ipv6.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_smsk 32 __builtin_offsetof(struct __C(ip6t_entry), ipv6.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_smsk_in6_u 32 __builtin_offsetof(struct __C(ip6t_entry), ipv6.smsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_smsk_in6_u_u6_addr16 32 __builtin_offsetof(struct __C(ip6t_entry), ipv6.smsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_smsk_in6_u_u6_addr32 32 __builtin_offsetof(struct __C(ip6t_entry), ipv6.smsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_smsk_in6_u_u6_addr8 32 __builtin_offsetof(struct __C(ip6t_entry), ipv6.smsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_src 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_src_in6_u 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6.src.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_src_in6_u_u6_addr16 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6.src.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_src_in6_u_u6_addr32 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6.src.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_src_in6_u_u6_addr8 0 __builtin_offsetof(struct __C(ip6t_entry), ipv6.src.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_ipv6_tos 130 __builtin_offsetof(struct __C(ip6t_entry), ipv6.tos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_next_offset 142 __builtin_offsetof(struct __C(ip6t_entry), next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_nfcache 136 __builtin_offsetof(struct __C(ip6t_entry), nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_entry_target_offset 140 __builtin_offsetof(struct __C(ip6t_entry), target_offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ip6t_error 232 sizeof(struct __C(ip6t_error))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ip6t_error 8 __alignof(struct __C(ip6t_error))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry 0 __builtin_offsetof(struct __C(ip6t_error), entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_comefrom 144 __builtin_offsetof(struct __C(ip6t_error), entry.comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_counters 152 __builtin_offsetof(struct __C(ip6t_error), entry.counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_counters_bcnt 160 __builtin_offsetof(struct __C(ip6t_error), entry.counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_counters_pcnt 152 __builtin_offsetof(struct __C(ip6t_error), entry.counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_elems 168 __builtin_offsetof(struct __C(ip6t_error), entry.elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dmsk 48 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dmsk_in6_u 48 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dmsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dmsk_in6_u_u6_addr16 48 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dmsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dmsk_in6_u_u6_addr32 48 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dmsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dmsk_in6_u_u6_addr8 48 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dmsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dst 16 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dst_in6_u 16 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dst.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dst_in6_u_u6_addr16 16 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dst.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dst_in6_u_u6_addr32 16 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dst.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_dst_in6_u_u6_addr8 16 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.dst.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_flags 131 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_iniface 64 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_iniface_mask 96 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_invflags 132 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_outiface 80 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_outiface_mask 112 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_proto 128 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_smsk 32 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_smsk_in6_u 32 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.smsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_smsk_in6_u_u6_addr16 32 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.smsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_smsk_in6_u_u6_addr32 32 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.smsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_smsk_in6_u_u6_addr8 32 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.smsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_src 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_src_in6_u 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.src.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_src_in6_u_u6_addr16 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.src.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_src_in6_u_u6_addr32 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.src.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_src_in6_u_u6_addr8 0 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.src.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_ipv6_tos 130 __builtin_offsetof(struct __C(ip6t_error), entry.ipv6.tos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_next_offset 142 __builtin_offsetof(struct __C(ip6t_error), entry.next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_nfcache 136 __builtin_offsetof(struct __C(ip6t_error), entry.nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_entry_target_offset 140 __builtin_offsetof(struct __C(ip6t_error), entry.target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target 168 __builtin_offsetof(struct __C(ip6t_error), target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_errorname 200 __builtin_offsetof(struct __C(ip6t_error), target.errorname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target 168 __builtin_offsetof(struct __C(ip6t_error), target.target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_data 200 __builtin_offsetof(struct __C(ip6t_error), target.target.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_kernel 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_kernel_target_size 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u.kernel.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_target_size 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_user 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_user_name 170 __builtin_offsetof(struct __C(ip6t_error), target.target.u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_user_revision 199 __builtin_offsetof(struct __C(ip6t_error), target.target.u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_error_target_target_u_user_target_size 168 __builtin_offsetof(struct __C(ip6t_error), target.target.u.user.target_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ip6t_get_entries 40 sizeof(struct __C(ip6t_get_entries))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ip6t_get_entries 8 __alignof(struct __C(ip6t_get_entries))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__comefrom 184 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__counters 192 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__counters_bcnt 200 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__counters_pcnt 192 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__elems 208 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dmsk 88 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dmsk_in6_u 88 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dmsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dmsk_in6_u_u6_addr16 88 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dmsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dmsk_in6_u_u6_addr32 88 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dmsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dmsk_in6_u_u6_addr8 88 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dmsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dst 56 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dst_in6_u 56 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dst.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dst_in6_u_u6_addr16 56 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dst.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dst_in6_u_u6_addr32 56 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dst.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_dst_in6_u_u6_addr8 56 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.dst.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_flags 171 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_iniface 104 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_iniface_mask 136 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_invflags 172 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_outiface 120 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_outiface_mask 152 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_proto 168 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_smsk 72 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_smsk_in6_u 72 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.smsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_smsk_in6_u_u6_addr16 72 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.smsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_smsk_in6_u_u6_addr32 72 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.smsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_smsk_in6_u_u6_addr8 72 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.smsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_src 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_src_in6_u 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.src.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_src_in6_u_u6_addr16 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.src.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_src_in6_u_u6_addr32 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.src.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_src_in6_u_u6_addr8 40 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.src.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__ipv6_tos 170 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].ipv6.tos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__next_offset 182 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__nfcache 176 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_entrytable_0__target_offset 180 __builtin_offsetof(struct __C(ip6t_get_entries), entrytable[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_name 0 __builtin_offsetof(struct __C(ip6t_get_entries), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_get_entries_size 32 __builtin_offsetof(struct __C(ip6t_get_entries), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ip6t_replace 96 sizeof(struct __C(ip6t_replace))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ip6t_replace 8 __alignof(struct __C(ip6t_replace))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_counters 88 __builtin_offsetof(struct __C(ip6t_replace), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries 96 __builtin_offsetof(struct __C(ip6t_replace), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__comefrom 240 __builtin_offsetof(struct __C(ip6t_replace), entries[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__counters 248 __builtin_offsetof(struct __C(ip6t_replace), entries[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__counters_bcnt 256 __builtin_offsetof(struct __C(ip6t_replace), entries[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__counters_pcnt 248 __builtin_offsetof(struct __C(ip6t_replace), entries[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__elems 264 __builtin_offsetof(struct __C(ip6t_replace), entries[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dmsk 144 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dmsk_in6_u 144 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dmsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dmsk_in6_u_u6_addr16 144 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dmsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dmsk_in6_u_u6_addr32 144 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dmsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dmsk_in6_u_u6_addr8 144 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dmsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dst 112 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dst_in6_u 112 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dst.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dst_in6_u_u6_addr16 112 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dst.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dst_in6_u_u6_addr32 112 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dst.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_dst_in6_u_u6_addr8 112 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.dst.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_flags 227 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_iniface 160 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_iniface_mask 192 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_invflags 228 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_outiface 176 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_outiface_mask 208 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_proto 224 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_smsk 128 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_smsk_in6_u 128 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.smsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_smsk_in6_u_u6_addr16 128 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.smsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_smsk_in6_u_u6_addr32 128 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.smsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_smsk_in6_u_u6_addr8 128 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.smsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_src 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_src_in6_u 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.src.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_src_in6_u_u6_addr16 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.src.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_src_in6_u_u6_addr32 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.src.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_src_in6_u_u6_addr8 96 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.src.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__ipv6_tos 226 __builtin_offsetof(struct __C(ip6t_replace), entries[0].ipv6.tos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__next_offset 238 __builtin_offsetof(struct __C(ip6t_replace), entries[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__nfcache 232 __builtin_offsetof(struct __C(ip6t_replace), entries[0].nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_entries_0__target_offset 236 __builtin_offsetof(struct __C(ip6t_replace), entries[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_hook_entry 44 __builtin_offsetof(struct __C(ip6t_replace), hook_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_name 0 __builtin_offsetof(struct __C(ip6t_replace), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_num_counters 84 __builtin_offsetof(struct __C(ip6t_replace), num_counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_num_entries 36 __builtin_offsetof(struct __C(ip6t_replace), num_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_size 40 __builtin_offsetof(struct __C(ip6t_replace), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_underflow 64 __builtin_offsetof(struct __C(ip6t_replace), underflow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_replace_valid_hooks 32 __builtin_offsetof(struct __C(ip6t_replace), valid_hooks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ip6t_standard 208 sizeof(struct __C(ip6t_standard))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ip6t_standard 8 __alignof(struct __C(ip6t_standard))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry 0 __builtin_offsetof(struct __C(ip6t_standard), entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_comefrom 144 __builtin_offsetof(struct __C(ip6t_standard), entry.comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_counters 152 __builtin_offsetof(struct __C(ip6t_standard), entry.counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_counters_bcnt 160 __builtin_offsetof(struct __C(ip6t_standard), entry.counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_counters_pcnt 152 __builtin_offsetof(struct __C(ip6t_standard), entry.counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_elems 168 __builtin_offsetof(struct __C(ip6t_standard), entry.elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dmsk 48 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dmsk_in6_u 48 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dmsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dmsk_in6_u_u6_addr16 48 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dmsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dmsk_in6_u_u6_addr32 48 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dmsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dmsk_in6_u_u6_addr8 48 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dmsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dst 16 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dst_in6_u 16 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dst.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dst_in6_u_u6_addr16 16 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dst.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dst_in6_u_u6_addr32 16 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dst.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_dst_in6_u_u6_addr8 16 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.dst.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_flags 131 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_iniface 64 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_iniface_mask 96 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_invflags 132 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_outiface 80 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_outiface_mask 112 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_proto 128 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_smsk 32 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_smsk_in6_u 32 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.smsk.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_smsk_in6_u_u6_addr16 32 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.smsk.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_smsk_in6_u_u6_addr32 32 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.smsk.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_smsk_in6_u_u6_addr8 32 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.smsk.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_src 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_src_in6_u 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.src.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_src_in6_u_u6_addr16 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.src.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_src_in6_u_u6_addr32 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.src.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_src_in6_u_u6_addr8 0 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.src.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_ipv6_tos 130 __builtin_offsetof(struct __C(ip6t_standard), entry.ipv6.tos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_next_offset 142 __builtin_offsetof(struct __C(ip6t_standard), entry.next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_nfcache 136 __builtin_offsetof(struct __C(ip6t_standard), entry.nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_entry_target_offset 140 __builtin_offsetof(struct __C(ip6t_standard), entry.target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target 168 __builtin_offsetof(struct __C(ip6t_standard), target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target 168 __builtin_offsetof(struct __C(ip6t_standard), target.target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_data 200 __builtin_offsetof(struct __C(ip6t_standard), target.target.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_kernel 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_kernel_target_size 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.kernel.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_target_size 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_user 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_user_name 170 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_user_revision 199 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_target_u_user_target_size 168 __builtin_offsetof(struct __C(ip6t_standard), target.target.u.user.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ip6t_standard_target_verdict 200 __builtin_offsetof(struct __C(ip6t_standard), target.verdict)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipc_kludge 16 sizeof(struct __C(ipc_kludge))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipc_kludge 8 __alignof(struct __C(ipc_kludge))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipc_kludge_msgp 0 __builtin_offsetof(struct __C(ipc_kludge), msgp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipc_kludge_msgtyp 8 __builtin_offsetof(struct __C(ipc_kludge), msgtyp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipmi_msg 16 sizeof(struct __C(ipmi_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipmi_msg 8 __alignof(struct __C(ipmi_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_msg_cmd 1 __builtin_offsetof(struct __C(ipmi_msg), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_msg_data 8 __builtin_offsetof(struct __C(ipmi_msg), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_msg_data_len 2 __builtin_offsetof(struct __C(ipmi_msg), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_msg_netfn 0 __builtin_offsetof(struct __C(ipmi_msg), netfn)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipmi_recv 48 sizeof(struct __C(ipmi_recv))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipmi_recv 8 __alignof(struct __C(ipmi_recv))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_addr 8 __builtin_offsetof(struct __C(ipmi_recv), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_addr_len 16 __builtin_offsetof(struct __C(ipmi_recv), addr_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msg 32 __builtin_offsetof(struct __C(ipmi_recv), msg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msg_cmd 33 __builtin_offsetof(struct __C(ipmi_recv), msg.cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msg_data 40 __builtin_offsetof(struct __C(ipmi_recv), msg.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msg_data_len 34 __builtin_offsetof(struct __C(ipmi_recv), msg.data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msg_netfn 32 __builtin_offsetof(struct __C(ipmi_recv), msg.netfn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_msgid 24 __builtin_offsetof(struct __C(ipmi_recv), msgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_recv_recv_type 0 __builtin_offsetof(struct __C(ipmi_recv), recv_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipmi_req 40 sizeof(struct __C(ipmi_req))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipmi_req 8 __alignof(struct __C(ipmi_req))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_addr 0 __builtin_offsetof(struct __C(ipmi_req), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_addr_len 8 __builtin_offsetof(struct __C(ipmi_req), addr_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msg 24 __builtin_offsetof(struct __C(ipmi_req), msg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msg_cmd 25 __builtin_offsetof(struct __C(ipmi_req), msg.cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msg_data 32 __builtin_offsetof(struct __C(ipmi_req), msg.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msg_data_len 26 __builtin_offsetof(struct __C(ipmi_req), msg.data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msg_netfn 24 __builtin_offsetof(struct __C(ipmi_req), msg.netfn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_msgid 16 __builtin_offsetof(struct __C(ipmi_req), msgid)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipmi_req_settime 48 sizeof(struct __C(ipmi_req_settime))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipmi_req_settime 8 __alignof(struct __C(ipmi_req_settime))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req 0 __builtin_offsetof(struct __C(ipmi_req_settime), req)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_addr 0 __builtin_offsetof(struct __C(ipmi_req_settime), req.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_addr_len 8 __builtin_offsetof(struct __C(ipmi_req_settime), req.addr_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msg 24 __builtin_offsetof(struct __C(ipmi_req_settime), req.msg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msg_cmd 25 __builtin_offsetof(struct __C(ipmi_req_settime), req.msg.cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msg_data 32 __builtin_offsetof(struct __C(ipmi_req_settime), req.msg.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msg_data_len 26 __builtin_offsetof(struct __C(ipmi_req_settime), req.msg.data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msg_netfn 24 __builtin_offsetof(struct __C(ipmi_req_settime), req.msg.netfn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_req_msgid 16 __builtin_offsetof(struct __C(ipmi_req_settime), req.msgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_retries 40 __builtin_offsetof(struct __C(ipmi_req_settime), retries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipmi_req_settime_retry_time_ms 44 __builtin_offsetof(struct __C(ipmi_req_settime), retry_time_ms)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipt_entry 112 sizeof(struct __C(ipt_entry))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipt_entry 8 __alignof(struct __C(ipt_entry))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_comefrom 92 __builtin_offsetof(struct __C(ipt_entry), comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_counters 96 __builtin_offsetof(struct __C(ipt_entry), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_counters_bcnt 104 __builtin_offsetof(struct __C(ipt_entry), counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_counters_pcnt 96 __builtin_offsetof(struct __C(ipt_entry), counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_elems 112 __builtin_offsetof(struct __C(ipt_entry), elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip 0 __builtin_offsetof(struct __C(ipt_entry), ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_dmsk 12 __builtin_offsetof(struct __C(ipt_entry), ip.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_dmsk_s_addr 12 __builtin_offsetof(struct __C(ipt_entry), ip.dmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_dst 4 __builtin_offsetof(struct __C(ipt_entry), ip.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_dst_s_addr 4 __builtin_offsetof(struct __C(ipt_entry), ip.dst.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_flags 82 __builtin_offsetof(struct __C(ipt_entry), ip.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_iniface 16 __builtin_offsetof(struct __C(ipt_entry), ip.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_iniface_mask 48 __builtin_offsetof(struct __C(ipt_entry), ip.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_invflags 83 __builtin_offsetof(struct __C(ipt_entry), ip.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_outiface 32 __builtin_offsetof(struct __C(ipt_entry), ip.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_outiface_mask 64 __builtin_offsetof(struct __C(ipt_entry), ip.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_proto 80 __builtin_offsetof(struct __C(ipt_entry), ip.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_smsk 8 __builtin_offsetof(struct __C(ipt_entry), ip.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_smsk_s_addr 8 __builtin_offsetof(struct __C(ipt_entry), ip.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_src 0 __builtin_offsetof(struct __C(ipt_entry), ip.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_ip_src_s_addr 0 __builtin_offsetof(struct __C(ipt_entry), ip.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_next_offset 90 __builtin_offsetof(struct __C(ipt_entry), next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_nfcache 84 __builtin_offsetof(struct __C(ipt_entry), nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_entry_target_offset 88 __builtin_offsetof(struct __C(ipt_entry), target_offset)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipt_get_entries 40 sizeof(struct __C(ipt_get_entries))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipt_get_entries 8 __alignof(struct __C(ipt_get_entries))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable 40 __builtin_offsetof(struct __C(ipt_get_entries), entrytable)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__comefrom 132 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__counters 136 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__counters_bcnt 144 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__counters_pcnt 136 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__elems 152 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip 40 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_dmsk 52 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_dmsk_s_addr 52 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.dmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_dst 44 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_dst_s_addr 44 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.dst.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_flags 122 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_iniface 56 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_iniface_mask 88 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_invflags 123 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_outiface 72 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_outiface_mask 104 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_proto 120 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_smsk 48 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_smsk_s_addr 48 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_src 40 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__ip_src_s_addr 40 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].ip.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__next_offset 130 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__nfcache 124 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_entrytable_0__target_offset 128 __builtin_offsetof(struct __C(ipt_get_entries), entrytable[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_name 0 __builtin_offsetof(struct __C(ipt_get_entries), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_get_entries_size 32 __builtin_offsetof(struct __C(ipt_get_entries), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ipt_replace 96 sizeof(struct __C(ipt_replace))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ipt_replace 8 __alignof(struct __C(ipt_replace))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_counters 88 __builtin_offsetof(struct __C(ipt_replace), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries 96 __builtin_offsetof(struct __C(ipt_replace), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__comefrom 188 __builtin_offsetof(struct __C(ipt_replace), entries[0].comefrom)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__counters 192 __builtin_offsetof(struct __C(ipt_replace), entries[0].counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__counters_bcnt 200 __builtin_offsetof(struct __C(ipt_replace), entries[0].counters.bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__counters_pcnt 192 __builtin_offsetof(struct __C(ipt_replace), entries[0].counters.pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__elems 208 __builtin_offsetof(struct __C(ipt_replace), entries[0].elems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip 96 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_dmsk 108 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.dmsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_dmsk_s_addr 108 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.dmsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_dst 100 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_dst_s_addr 100 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.dst.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_flags 178 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_iniface 112 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.iniface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_iniface_mask 144 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.iniface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_invflags 179 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.invflags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_outiface 128 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.outiface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_outiface_mask 160 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.outiface_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_proto 176 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_smsk 104 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.smsk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_smsk_s_addr 104 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.smsk.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_src 96 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__ip_src_s_addr 96 __builtin_offsetof(struct __C(ipt_replace), entries[0].ip.src.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__next_offset 186 __builtin_offsetof(struct __C(ipt_replace), entries[0].next_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__nfcache 180 __builtin_offsetof(struct __C(ipt_replace), entries[0].nfcache)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_entries_0__target_offset 184 __builtin_offsetof(struct __C(ipt_replace), entries[0].target_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_hook_entry 44 __builtin_offsetof(struct __C(ipt_replace), hook_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_name 0 __builtin_offsetof(struct __C(ipt_replace), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_num_counters 84 __builtin_offsetof(struct __C(ipt_replace), num_counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_num_entries 36 __builtin_offsetof(struct __C(ipt_replace), num_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_size 40 __builtin_offsetof(struct __C(ipt_replace), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_underflow 64 __builtin_offsetof(struct __C(ipt_replace), underflow)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ipt_replace_valid_hooks 32 __builtin_offsetof(struct __C(ipt_replace), valid_hooks)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ivtv_dma_frame 64 sizeof(struct __C(ivtv_dma_frame))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ivtv_dma_frame 8 __alignof(struct __C(ivtv_dma_frame))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_dst 40 __builtin_offsetof(struct __C(ivtv_dma_frame), dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_dst_height 52 __builtin_offsetof(struct __C(ivtv_dma_frame), dst.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_dst_left 40 __builtin_offsetof(struct __C(ivtv_dma_frame), dst.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_dst_top 44 __builtin_offsetof(struct __C(ivtv_dma_frame), dst.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_dst_width 48 __builtin_offsetof(struct __C(ivtv_dma_frame), dst.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_pixelformat 4 __builtin_offsetof(struct __C(ivtv_dma_frame), pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src 24 __builtin_offsetof(struct __C(ivtv_dma_frame), src)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_height 36 __builtin_offsetof(struct __C(ivtv_dma_frame), src.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_left 24 __builtin_offsetof(struct __C(ivtv_dma_frame), src.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_top 28 __builtin_offsetof(struct __C(ivtv_dma_frame), src.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_width 32 __builtin_offsetof(struct __C(ivtv_dma_frame), src.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_height 60 __builtin_offsetof(struct __C(ivtv_dma_frame), src_height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_src_width 56 __builtin_offsetof(struct __C(ivtv_dma_frame), src_width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_type 0 __builtin_offsetof(struct __C(ivtv_dma_frame), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_uv_source 16 __builtin_offsetof(struct __C(ivtv_dma_frame), uv_source)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtv_dma_frame_y_source 8 __builtin_offsetof(struct __C(ivtv_dma_frame), y_source)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ivtvfb_dma_frame 24 sizeof(struct __C(ivtvfb_dma_frame))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ivtvfb_dma_frame 8 __alignof(struct __C(ivtvfb_dma_frame))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtvfb_dma_frame_count 16 __builtin_offsetof(struct __C(ivtvfb_dma_frame), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtvfb_dma_frame_dest_offset 8 __builtin_offsetof(struct __C(ivtvfb_dma_frame), dest_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ivtvfb_dma_frame_source 0 __builtin_offsetof(struct __C(ivtvfb_dma_frame), source)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iw_event 24 sizeof(struct __C(iw_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iw_event 8 __alignof(struct __C(iw_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_cmd 2 __builtin_offsetof(struct __C(iw_event), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_len 0 __builtin_offsetof(struct __C(iw_event), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u 8 __builtin_offsetof(struct __C(iw_event), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_addr 8 __builtin_offsetof(struct __C(iw_event), u.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_ap_addr 8 __builtin_offsetof(struct __C(iw_event), u.ap_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_bitrate 8 __builtin_offsetof(struct __C(iw_event), u.bitrate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_bitrate_disabled 13 __builtin_offsetof(struct __C(iw_event), u.bitrate.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_bitrate_fixed 12 __builtin_offsetof(struct __C(iw_event), u.bitrate.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_bitrate_flags 14 __builtin_offsetof(struct __C(iw_event), u.bitrate.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_bitrate_value 8 __builtin_offsetof(struct __C(iw_event), u.bitrate.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_data 8 __builtin_offsetof(struct __C(iw_event), u.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_data_flags 18 __builtin_offsetof(struct __C(iw_event), u.data.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_data_length 16 __builtin_offsetof(struct __C(iw_event), u.data.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_data_pointer 8 __builtin_offsetof(struct __C(iw_event), u.data.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_encoding 8 __builtin_offsetof(struct __C(iw_event), u.encoding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_encoding_flags 18 __builtin_offsetof(struct __C(iw_event), u.encoding.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_encoding_length 16 __builtin_offsetof(struct __C(iw_event), u.encoding.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_encoding_pointer 8 __builtin_offsetof(struct __C(iw_event), u.encoding.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_essid 8 __builtin_offsetof(struct __C(iw_event), u.essid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_essid_flags 18 __builtin_offsetof(struct __C(iw_event), u.essid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_essid_length 16 __builtin_offsetof(struct __C(iw_event), u.essid.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_essid_pointer 8 __builtin_offsetof(struct __C(iw_event), u.essid.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_frag 8 __builtin_offsetof(struct __C(iw_event), u.frag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_frag_disabled 13 __builtin_offsetof(struct __C(iw_event), u.frag.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_frag_fixed 12 __builtin_offsetof(struct __C(iw_event), u.frag.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_frag_flags 14 __builtin_offsetof(struct __C(iw_event), u.frag.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_frag_value 8 __builtin_offsetof(struct __C(iw_event), u.frag.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_freq 8 __builtin_offsetof(struct __C(iw_event), u.freq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_freq_e 12 __builtin_offsetof(struct __C(iw_event), u.freq.e)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_freq_flags 15 __builtin_offsetof(struct __C(iw_event), u.freq.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_freq_i 14 __builtin_offsetof(struct __C(iw_event), u.freq.i)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_freq_m 8 __builtin_offsetof(struct __C(iw_event), u.freq.m)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_mode 8 __builtin_offsetof(struct __C(iw_event), u.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_name 8 __builtin_offsetof(struct __C(iw_event), u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_nwid 8 __builtin_offsetof(struct __C(iw_event), u.nwid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_nwid_disabled 13 __builtin_offsetof(struct __C(iw_event), u.nwid.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_nwid_fixed 12 __builtin_offsetof(struct __C(iw_event), u.nwid.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_nwid_flags 14 __builtin_offsetof(struct __C(iw_event), u.nwid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_nwid_value 8 __builtin_offsetof(struct __C(iw_event), u.nwid.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_param 8 __builtin_offsetof(struct __C(iw_event), u.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_param_disabled 13 __builtin_offsetof(struct __C(iw_event), u.param.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_param_fixed 12 __builtin_offsetof(struct __C(iw_event), u.param.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_param_flags 14 __builtin_offsetof(struct __C(iw_event), u.param.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_param_value 8 __builtin_offsetof(struct __C(iw_event), u.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_power 8 __builtin_offsetof(struct __C(iw_event), u.power)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_power_disabled 13 __builtin_offsetof(struct __C(iw_event), u.power.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_power_fixed 12 __builtin_offsetof(struct __C(iw_event), u.power.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_power_flags 14 __builtin_offsetof(struct __C(iw_event), u.power.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_power_value 8 __builtin_offsetof(struct __C(iw_event), u.power.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_qual 8 __builtin_offsetof(struct __C(iw_event), u.qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_qual_level 9 __builtin_offsetof(struct __C(iw_event), u.qual.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_qual_noise 10 __builtin_offsetof(struct __C(iw_event), u.qual.noise)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_qual_qual 8 __builtin_offsetof(struct __C(iw_event), u.qual.qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_qual_updated 11 __builtin_offsetof(struct __C(iw_event), u.qual.updated)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_retry 8 __builtin_offsetof(struct __C(iw_event), u.retry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_retry_disabled 13 __builtin_offsetof(struct __C(iw_event), u.retry.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_retry_fixed 12 __builtin_offsetof(struct __C(iw_event), u.retry.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_retry_flags 14 __builtin_offsetof(struct __C(iw_event), u.retry.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_retry_value 8 __builtin_offsetof(struct __C(iw_event), u.retry.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_rts 8 __builtin_offsetof(struct __C(iw_event), u.rts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_rts_disabled 13 __builtin_offsetof(struct __C(iw_event), u.rts.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_rts_fixed 12 __builtin_offsetof(struct __C(iw_event), u.rts.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_rts_flags 14 __builtin_offsetof(struct __C(iw_event), u.rts.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_rts_value 8 __builtin_offsetof(struct __C(iw_event), u.rts.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_sens 8 __builtin_offsetof(struct __C(iw_event), u.sens)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_sens_disabled 13 __builtin_offsetof(struct __C(iw_event), u.sens.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_sens_fixed 12 __builtin_offsetof(struct __C(iw_event), u.sens.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_sens_flags 14 __builtin_offsetof(struct __C(iw_event), u.sens.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_sens_value 8 __builtin_offsetof(struct __C(iw_event), u.sens.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_txpower 8 __builtin_offsetof(struct __C(iw_event), u.txpower)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_txpower_disabled 13 __builtin_offsetof(struct __C(iw_event), u.txpower.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_txpower_fixed 12 __builtin_offsetof(struct __C(iw_event), u.txpower.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_txpower_flags 14 __builtin_offsetof(struct __C(iw_event), u.txpower.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_event_u_txpower_value 8 __builtin_offsetof(struct __C(iw_event), u.txpower.value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iw_point 16 sizeof(struct __C(iw_point))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iw_point 8 __alignof(struct __C(iw_point))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_point_flags 10 __builtin_offsetof(struct __C(iw_point), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_point_length 8 __builtin_offsetof(struct __C(iw_point), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iw_point_pointer 0 __builtin_offsetof(struct __C(iw_point), pointer)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_iwreq 32 sizeof(struct __C(iwreq))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_iwreq 8 __alignof(struct __C(iwreq))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_ifr_ifrn 0 __builtin_offsetof(struct __C(iwreq), ifr_ifrn)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_ifr_ifrn_ifrn_name 0 __builtin_offsetof(struct __C(iwreq), ifr_ifrn.ifrn_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u 16 __builtin_offsetof(struct __C(iwreq), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_addr 16 __builtin_offsetof(struct __C(iwreq), u.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_ap_addr 16 __builtin_offsetof(struct __C(iwreq), u.ap_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_bitrate 16 __builtin_offsetof(struct __C(iwreq), u.bitrate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_bitrate_disabled 21 __builtin_offsetof(struct __C(iwreq), u.bitrate.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_bitrate_fixed 20 __builtin_offsetof(struct __C(iwreq), u.bitrate.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_bitrate_flags 22 __builtin_offsetof(struct __C(iwreq), u.bitrate.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_bitrate_value 16 __builtin_offsetof(struct __C(iwreq), u.bitrate.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_data 16 __builtin_offsetof(struct __C(iwreq), u.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_data_flags 26 __builtin_offsetof(struct __C(iwreq), u.data.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_data_length 24 __builtin_offsetof(struct __C(iwreq), u.data.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_data_pointer 16 __builtin_offsetof(struct __C(iwreq), u.data.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_encoding 16 __builtin_offsetof(struct __C(iwreq), u.encoding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_encoding_flags 26 __builtin_offsetof(struct __C(iwreq), u.encoding.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_encoding_length 24 __builtin_offsetof(struct __C(iwreq), u.encoding.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_encoding_pointer 16 __builtin_offsetof(struct __C(iwreq), u.encoding.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_essid 16 __builtin_offsetof(struct __C(iwreq), u.essid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_essid_flags 26 __builtin_offsetof(struct __C(iwreq), u.essid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_essid_length 24 __builtin_offsetof(struct __C(iwreq), u.essid.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_essid_pointer 16 __builtin_offsetof(struct __C(iwreq), u.essid.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_frag 16 __builtin_offsetof(struct __C(iwreq), u.frag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_frag_disabled 21 __builtin_offsetof(struct __C(iwreq), u.frag.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_frag_fixed 20 __builtin_offsetof(struct __C(iwreq), u.frag.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_frag_flags 22 __builtin_offsetof(struct __C(iwreq), u.frag.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_frag_value 16 __builtin_offsetof(struct __C(iwreq), u.frag.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_freq 16 __builtin_offsetof(struct __C(iwreq), u.freq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_freq_e 20 __builtin_offsetof(struct __C(iwreq), u.freq.e)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_freq_flags 23 __builtin_offsetof(struct __C(iwreq), u.freq.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_freq_i 22 __builtin_offsetof(struct __C(iwreq), u.freq.i)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_freq_m 16 __builtin_offsetof(struct __C(iwreq), u.freq.m)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_mode 16 __builtin_offsetof(struct __C(iwreq), u.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_name 16 __builtin_offsetof(struct __C(iwreq), u.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_nwid 16 __builtin_offsetof(struct __C(iwreq), u.nwid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_nwid_disabled 21 __builtin_offsetof(struct __C(iwreq), u.nwid.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_nwid_fixed 20 __builtin_offsetof(struct __C(iwreq), u.nwid.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_nwid_flags 22 __builtin_offsetof(struct __C(iwreq), u.nwid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_nwid_value 16 __builtin_offsetof(struct __C(iwreq), u.nwid.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_param 16 __builtin_offsetof(struct __C(iwreq), u.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_param_disabled 21 __builtin_offsetof(struct __C(iwreq), u.param.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_param_fixed 20 __builtin_offsetof(struct __C(iwreq), u.param.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_param_flags 22 __builtin_offsetof(struct __C(iwreq), u.param.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_param_value 16 __builtin_offsetof(struct __C(iwreq), u.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_power 16 __builtin_offsetof(struct __C(iwreq), u.power)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_power_disabled 21 __builtin_offsetof(struct __C(iwreq), u.power.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_power_fixed 20 __builtin_offsetof(struct __C(iwreq), u.power.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_power_flags 22 __builtin_offsetof(struct __C(iwreq), u.power.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_power_value 16 __builtin_offsetof(struct __C(iwreq), u.power.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_qual 16 __builtin_offsetof(struct __C(iwreq), u.qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_qual_level 17 __builtin_offsetof(struct __C(iwreq), u.qual.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_qual_noise 18 __builtin_offsetof(struct __C(iwreq), u.qual.noise)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_qual_qual 16 __builtin_offsetof(struct __C(iwreq), u.qual.qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_qual_updated 19 __builtin_offsetof(struct __C(iwreq), u.qual.updated)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_retry 16 __builtin_offsetof(struct __C(iwreq), u.retry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_retry_disabled 21 __builtin_offsetof(struct __C(iwreq), u.retry.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_retry_fixed 20 __builtin_offsetof(struct __C(iwreq), u.retry.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_retry_flags 22 __builtin_offsetof(struct __C(iwreq), u.retry.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_retry_value 16 __builtin_offsetof(struct __C(iwreq), u.retry.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_rts 16 __builtin_offsetof(struct __C(iwreq), u.rts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_rts_disabled 21 __builtin_offsetof(struct __C(iwreq), u.rts.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_rts_fixed 20 __builtin_offsetof(struct __C(iwreq), u.rts.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_rts_flags 22 __builtin_offsetof(struct __C(iwreq), u.rts.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_rts_value 16 __builtin_offsetof(struct __C(iwreq), u.rts.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_sens 16 __builtin_offsetof(struct __C(iwreq), u.sens)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_sens_disabled 21 __builtin_offsetof(struct __C(iwreq), u.sens.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_sens_fixed 20 __builtin_offsetof(struct __C(iwreq), u.sens.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_sens_flags 22 __builtin_offsetof(struct __C(iwreq), u.sens.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_sens_value 16 __builtin_offsetof(struct __C(iwreq), u.sens.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_txpower 16 __builtin_offsetof(struct __C(iwreq), u.txpower)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_txpower_disabled 21 __builtin_offsetof(struct __C(iwreq), u.txpower.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_txpower_fixed 20 __builtin_offsetof(struct __C(iwreq), u.txpower.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_txpower_flags 22 __builtin_offsetof(struct __C(iwreq), u.txpower.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_u_txpower_value 16 __builtin_offsetof(struct __C(iwreq), u.txpower.value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_kernel_ipmi_msg 16 sizeof(struct __C(kernel_ipmi_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_kernel_ipmi_msg 8 __alignof(struct __C(kernel_ipmi_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_kernel_ipmi_msg_cmd 1 __builtin_offsetof(struct __C(kernel_ipmi_msg), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_kernel_ipmi_msg_data 8 __builtin_offsetof(struct __C(kernel_ipmi_msg), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_kernel_ipmi_msg_data_len 2 __builtin_offsetof(struct __C(kernel_ipmi_msg), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_kernel_ipmi_msg_netfn 0 __builtin_offsetof(struct __C(kernel_ipmi_msg), netfn)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_keyctl_kdf_params 56 sizeof(struct __C(keyctl_kdf_params))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_keyctl_kdf_params 8 __alignof(struct __C(keyctl_kdf_params))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_keyctl_kdf_params___spare 20 __builtin_offsetof(struct __C(keyctl_kdf_params), __spare)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_keyctl_kdf_params_hashname 0 __builtin_offsetof(struct __C(keyctl_kdf_params), hashname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_keyctl_kdf_params_otherinfo 8 __builtin_offsetof(struct __C(keyctl_kdf_params), otherinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_keyctl_kdf_params_otherinfolen 16 __builtin_offsetof(struct __C(keyctl_kdf_params), otherinfolen)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_media_links_enum 40 sizeof(struct __C(media_links_enum))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_media_links_enum 8 __alignof(struct __C(media_links_enum))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_links_enum_entity 0 __builtin_offsetof(struct __C(media_links_enum), entity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_links_enum_links 16 __builtin_offsetof(struct __C(media_links_enum), links)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_links_enum_pads 8 __builtin_offsetof(struct __C(media_links_enum), pads)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_links_enum_reserved 24 __builtin_offsetof(struct __C(media_links_enum), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_media_v2_topology 72 sizeof(struct __C(media_v2_topology))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_media_v2_topology 1 __alignof(struct __C(media_v2_topology))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_num_entities 8 __builtin_offsetof(struct __C(media_v2_topology), num_entities)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_num_interfaces 24 __builtin_offsetof(struct __C(media_v2_topology), num_interfaces)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_num_links 56 __builtin_offsetof(struct __C(media_v2_topology), num_links)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_num_pads 40 __builtin_offsetof(struct __C(media_v2_topology), num_pads)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_ptr_entities 16 __builtin_offsetof(struct __C(media_v2_topology), ptr_entities)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_ptr_interfaces 32 __builtin_offsetof(struct __C(media_v2_topology), ptr_interfaces)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_ptr_links 64 __builtin_offsetof(struct __C(media_v2_topology), ptr_links)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_ptr_pads 48 __builtin_offsetof(struct __C(media_v2_topology), ptr_pads)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_reserved1 12 __builtin_offsetof(struct __C(media_v2_topology), reserved1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_reserved2 28 __builtin_offsetof(struct __C(media_v2_topology), reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_reserved3 44 __builtin_offsetof(struct __C(media_v2_topology), reserved3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_reserved4 60 __builtin_offsetof(struct __C(media_v2_topology), reserved4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_media_v2_topology_topology_version 0 __builtin_offsetof(struct __C(media_v2_topology), topology_version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mmc_ioc_cmd 72 sizeof(struct __C(mmc_ioc_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mmc_ioc_cmd 8 __alignof(struct __C(mmc_ioc_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd___pad 60 __builtin_offsetof(struct __C(mmc_ioc_cmd), __pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_arg 12 __builtin_offsetof(struct __C(mmc_ioc_cmd), arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_blksz 36 __builtin_offsetof(struct __C(mmc_ioc_cmd), blksz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_blocks 40 __builtin_offsetof(struct __C(mmc_ioc_cmd), blocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_cmd_timeout_ms 56 __builtin_offsetof(struct __C(mmc_ioc_cmd), cmd_timeout_ms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_data_ptr 64 __builtin_offsetof(struct __C(mmc_ioc_cmd), data_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_data_timeout_ns 52 __builtin_offsetof(struct __C(mmc_ioc_cmd), data_timeout_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_flags 32 __builtin_offsetof(struct __C(mmc_ioc_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_is_acmd 4 __builtin_offsetof(struct __C(mmc_ioc_cmd), is_acmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_opcode 8 __builtin_offsetof(struct __C(mmc_ioc_cmd), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_postsleep_max_us 48 __builtin_offsetof(struct __C(mmc_ioc_cmd), postsleep_max_us)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_postsleep_min_us 44 __builtin_offsetof(struct __C(mmc_ioc_cmd), postsleep_min_us)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_response 16 __builtin_offsetof(struct __C(mmc_ioc_cmd), response)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_cmd_write_flag 0 __builtin_offsetof(struct __C(mmc_ioc_cmd), write_flag)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mmc_ioc_multi_cmd 8 sizeof(struct __C(mmc_ioc_multi_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mmc_ioc_multi_cmd 8 __alignof(struct __C(mmc_ioc_multi_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds 8 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0____pad 68 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__arg 20 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].arg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__blksz 44 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].blksz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__blocks 48 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].blocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__cmd_timeout_ms 64 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].cmd_timeout_ms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__data_ptr 72 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].data_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__data_timeout_ns 60 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].data_timeout_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__flags 40 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__is_acmd 12 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].is_acmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__opcode 16 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__postsleep_max_us 56 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].postsleep_max_us)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__postsleep_min_us 52 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].postsleep_min_us)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__response 24 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].response)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_cmds_0__write_flag 8 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), cmds[0].write_flag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mmc_ioc_multi_cmd_num_of_cmds 0 __builtin_offsetof(struct __C(mmc_ioc_multi_cmd), num_of_cmds)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mptcp_full_info 136 sizeof(struct __C(mptcp_full_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mptcp_full_info 8 __alignof(struct __C(mptcp_full_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info 40 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_add_addr_accepted 42 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_add_addr_accepted)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_add_addr_accepted_max 45 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_add_addr_accepted_max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_add_addr_signal 41 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_add_addr_signal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_add_addr_signal_max 44 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_add_addr_signal_max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_bytes_acked 112 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_bytes_acked)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_bytes_received 104 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_bytes_received)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_bytes_retrans 88 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_bytes_retrans)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_bytes_sent 96 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_bytes_sent)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_csum_enabled 82 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_csum_enabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_flags 48 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_last_ack_recv 132 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_last_ack_recv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_last_data_recv 128 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_last_data_recv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_last_data_sent 124 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_last_data_sent)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_local_addr_max 81 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_local_addr_max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_local_addr_used 80 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_local_addr_used)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_rcv_nxt 72 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_rcv_nxt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_retransmits 84 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_retransmits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_snd_una 64 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_snd_una)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_subflows 40 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_subflows)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_subflows_max 43 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_subflows_max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_subflows_total 120 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_subflows_total)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_token 52 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_token)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_mptcpi_write_seq 56 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.mptcpi_write_seq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_mptcp_info_reserved 121 __builtin_offsetof(struct __C(mptcp_full_info), mptcp_info.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_num_subflows 16 __builtin_offsetof(struct __C(mptcp_full_info), num_subflows)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_size_arrays_user 20 __builtin_offsetof(struct __C(mptcp_full_info), size_arrays_user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_size_sfinfo_kernel 8 __builtin_offsetof(struct __C(mptcp_full_info), size_sfinfo_kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_size_sfinfo_user 12 __builtin_offsetof(struct __C(mptcp_full_info), size_sfinfo_user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_size_tcpinfo_kernel 0 __builtin_offsetof(struct __C(mptcp_full_info), size_tcpinfo_kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_size_tcpinfo_user 4 __builtin_offsetof(struct __C(mptcp_full_info), size_tcpinfo_user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_subflow_info 24 __builtin_offsetof(struct __C(mptcp_full_info), subflow_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_full_info_tcp_info 32 __builtin_offsetof(struct __C(mptcp_full_info), tcp_info)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mptcp_subflow_addrs 256 sizeof(struct __C(mptcp_subflow_addrs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mptcp_subflow_addrs 8 __alignof(struct __C(mptcp_subflow_addrs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_addr 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_addr_in6_u 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_addr.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_addr_in6_u_u6_addr16 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_addr.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_addr_in6_u_u6_addr32 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_addr.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_addr_in6_u_u6_addr8 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_addr.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_family 0 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_flowinfo 4 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_flowinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_port 2 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_local_sin6_scope_id 24 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_local.sin6_scope_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_addr 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_addr_in6_u 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_addr.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_addr_in6_u_u6_addr16 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_addr.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_addr_in6_u_u6_addr32 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_addr.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_addr_in6_u_u6_addr8 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_addr.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_family 128 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_flowinfo 132 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_flowinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_port 130 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin6_remote_sin6_scope_id 152 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin6_remote.sin6_scope_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_local___pad 8 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_local.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_local_sin_addr 4 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_local.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_local_sin_addr_s_addr 4 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_local.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_local_sin_family 0 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_local.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_local_sin_port 2 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_local.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_remote___pad 136 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_remote.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_remote_sin_addr 132 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_remote.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_remote_sin_addr_s_addr 132 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_remote.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_remote_sin_family 128 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_remote.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_sin_remote_sin_port 130 __builtin_offsetof(struct __C(mptcp_subflow_addrs), sin_remote.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_ss_local 0 __builtin_offsetof(struct __C(mptcp_subflow_addrs), ss_local)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_addrs_ss_remote 128 __builtin_offsetof(struct __C(mptcp_subflow_addrs), ss_remote)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mptcp_subflow_info 264 sizeof(struct __C(mptcp_subflow_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mptcp_subflow_info 8 __alignof(struct __C(mptcp_subflow_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs 8 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_addr 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_addr_in6_u 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_addr.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_addr_in6_u_u6_addr16 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_addr.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_addr_in6_u_u6_addr32 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_addr.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_addr_in6_u_u6_addr8 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_addr.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_family 8 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_flowinfo 12 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_flowinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_port 10 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_local_sin6_scope_id 32 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_local.sin6_scope_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_addr 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_addr_in6_u 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_addr.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_addr_in6_u_u6_addr16 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_addr.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_addr_in6_u_u6_addr32 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_addr.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_addr_in6_u_u6_addr8 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_addr.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_family 136 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_flowinfo 140 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_flowinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_port 138 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin6_remote_sin6_scope_id 160 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin6_remote.sin6_scope_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_local___pad 16 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_local.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_local_sin_addr 12 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_local.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_local_sin_addr_s_addr 12 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_local.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_local_sin_family 8 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_local.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_local_sin_port 10 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_local.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_remote___pad 144 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_remote.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_remote_sin_addr 140 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_remote.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_remote_sin_addr_s_addr 140 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_remote.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_remote_sin_family 136 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_remote.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_sin_remote_sin_port 138 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.sin_remote.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_ss_local 8 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.ss_local)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_addrs_ss_remote 136 __builtin_offsetof(struct __C(mptcp_subflow_info), addrs.ss_remote)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mptcp_subflow_info_id 0 __builtin_offsetof(struct __C(mptcp_subflow_info), id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_msqid_ds 104 sizeof(struct __C(msqid_ds))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_msqid_ds 8 __alignof(struct __C(msqid_ds))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_cbytes 88 __builtin_offsetof(struct __C(msqid_ds), msg_cbytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_ctime 64 __builtin_offsetof(struct __C(msqid_ds), msg_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_first 32 __builtin_offsetof(struct __C(msqid_ds), msg_first)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_last 40 __builtin_offsetof(struct __C(msqid_ds), msg_last)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_lcbytes 72 __builtin_offsetof(struct __C(msqid_ds), msg_lcbytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_lqbytes 80 __builtin_offsetof(struct __C(msqid_ds), msg_lqbytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_lrpid 100 __builtin_offsetof(struct __C(msqid_ds), msg_lrpid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_lspid 96 __builtin_offsetof(struct __C(msqid_ds), msg_lspid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm 0 __builtin_offsetof(struct __C(msqid_ds), msg_perm)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_cgid 16 __builtin_offsetof(struct __C(msqid_ds), msg_perm.cgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_cuid 12 __builtin_offsetof(struct __C(msqid_ds), msg_perm.cuid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_gid 8 __builtin_offsetof(struct __C(msqid_ds), msg_perm.gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_key 0 __builtin_offsetof(struct __C(msqid_ds), msg_perm.key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_mode 20 __builtin_offsetof(struct __C(msqid_ds), msg_perm.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_seq 24 __builtin_offsetof(struct __C(msqid_ds), msg_perm.seq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_perm_uid 4 __builtin_offsetof(struct __C(msqid_ds), msg_perm.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_qbytes 92 __builtin_offsetof(struct __C(msqid_ds), msg_qbytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_qnum 90 __builtin_offsetof(struct __C(msqid_ds), msg_qnum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_rtime 56 __builtin_offsetof(struct __C(msqid_ds), msg_rtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_msqid_ds_msg_stime 48 __builtin_offsetof(struct __C(msqid_ds), msg_stime)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mtd_oob_buf 16 sizeof(struct __C(mtd_oob_buf))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mtd_oob_buf 8 __alignof(struct __C(mtd_oob_buf))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf_length 4 __builtin_offsetof(struct __C(mtd_oob_buf), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf_ptr 8 __builtin_offsetof(struct __C(mtd_oob_buf), ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf_start 0 __builtin_offsetof(struct __C(mtd_oob_buf), start)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mtd_oob_buf64 24 sizeof(struct __C(mtd_oob_buf64))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mtd_oob_buf64 8 __alignof(struct __C(mtd_oob_buf64))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf64_length 12 __builtin_offsetof(struct __C(mtd_oob_buf64), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf64_pad 8 __builtin_offsetof(struct __C(mtd_oob_buf64), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf64_start 0 __builtin_offsetof(struct __C(mtd_oob_buf64), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_oob_buf64_usr_ptr 16 __builtin_offsetof(struct __C(mtd_oob_buf64), usr_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mtd_read_req 64 sizeof(struct __C(mtd_read_req))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mtd_read_req 8 __alignof(struct __C(mtd_read_req))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_ecc_stats 48 __builtin_offsetof(struct __C(mtd_read_req), ecc_stats)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_ecc_stats_corrected_bitflips 52 __builtin_offsetof(struct __C(mtd_read_req), ecc_stats.corrected_bitflips)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_ecc_stats_max_bitflips 56 __builtin_offsetof(struct __C(mtd_read_req), ecc_stats.max_bitflips)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_ecc_stats_uncorrectable_errors 48 __builtin_offsetof(struct __C(mtd_read_req), ecc_stats.uncorrectable_errors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_len 8 __builtin_offsetof(struct __C(mtd_read_req), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_mode 40 __builtin_offsetof(struct __C(mtd_read_req), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_ooblen 16 __builtin_offsetof(struct __C(mtd_read_req), ooblen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_padding 41 __builtin_offsetof(struct __C(mtd_read_req), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_start 0 __builtin_offsetof(struct __C(mtd_read_req), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_usr_data 24 __builtin_offsetof(struct __C(mtd_read_req), usr_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_read_req_usr_oob 32 __builtin_offsetof(struct __C(mtd_read_req), usr_oob)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_mtd_write_req 48 sizeof(struct __C(mtd_write_req))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_mtd_write_req 8 __alignof(struct __C(mtd_write_req))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_len 8 __builtin_offsetof(struct __C(mtd_write_req), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_mode 40 __builtin_offsetof(struct __C(mtd_write_req), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_ooblen 16 __builtin_offsetof(struct __C(mtd_write_req), ooblen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_padding 41 __builtin_offsetof(struct __C(mtd_write_req), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_start 0 __builtin_offsetof(struct __C(mtd_write_req), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_usr_data 24 __builtin_offsetof(struct __C(mtd_write_req), usr_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_mtd_write_req_usr_oob 32 __builtin_offsetof(struct __C(mtd_write_req), usr_oob)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nfs4_mount_data 120 sizeof(struct __C(nfs4_mount_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nfs4_mount_data 8 __alignof(struct __C(nfs4_mount_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_acdirmax 36 __builtin_offsetof(struct __C(nfs4_mount_data), acdirmax)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_acdirmin 32 __builtin_offsetof(struct __C(nfs4_mount_data), acdirmin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_acregmax 28 __builtin_offsetof(struct __C(nfs4_mount_data), acregmax)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_acregmin 24 __builtin_offsetof(struct __C(nfs4_mount_data), acregmin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_auth_flavourlen 108 __builtin_offsetof(struct __C(nfs4_mount_data), auth_flavourlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_auth_flavours 112 __builtin_offsetof(struct __C(nfs4_mount_data), auth_flavours)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_client_addr 40 __builtin_offsetof(struct __C(nfs4_mount_data), client_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_client_addr_data 48 __builtin_offsetof(struct __C(nfs4_mount_data), client_addr.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_client_addr_len 40 __builtin_offsetof(struct __C(nfs4_mount_data), client_addr.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_flags 4 __builtin_offsetof(struct __C(nfs4_mount_data), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_host_addr 96 __builtin_offsetof(struct __C(nfs4_mount_data), host_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_host_addrlen 88 __builtin_offsetof(struct __C(nfs4_mount_data), host_addrlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_hostname 72 __builtin_offsetof(struct __C(nfs4_mount_data), hostname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_hostname_data 80 __builtin_offsetof(struct __C(nfs4_mount_data), hostname.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_hostname_len 72 __builtin_offsetof(struct __C(nfs4_mount_data), hostname.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_mnt_path 56 __builtin_offsetof(struct __C(nfs4_mount_data), mnt_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_mnt_path_data 64 __builtin_offsetof(struct __C(nfs4_mount_data), mnt_path.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_mnt_path_len 56 __builtin_offsetof(struct __C(nfs4_mount_data), mnt_path.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_proto 104 __builtin_offsetof(struct __C(nfs4_mount_data), proto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_retrans 20 __builtin_offsetof(struct __C(nfs4_mount_data), retrans)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_rsize 8 __builtin_offsetof(struct __C(nfs4_mount_data), rsize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_timeo 16 __builtin_offsetof(struct __C(nfs4_mount_data), timeo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_version 0 __builtin_offsetof(struct __C(nfs4_mount_data), version)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs4_mount_data_wsize 12 __builtin_offsetof(struct __C(nfs4_mount_data), wsize)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nfs_mount_data 688 sizeof(struct __C(nfs_mount_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nfs_mount_data 4 __alignof(struct __C(nfs_mount_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_acdirmax 72 __builtin_offsetof(struct __C(nfs_mount_data), acdirmax)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_acdirmin 68 __builtin_offsetof(struct __C(nfs_mount_data), acdirmin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_acregmax 64 __builtin_offsetof(struct __C(nfs_mount_data), acregmax)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_acregmin 60 __builtin_offsetof(struct __C(nfs_mount_data), acregmin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr 76 __builtin_offsetof(struct __C(nfs_mount_data), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr___pad 84 __builtin_offsetof(struct __C(nfs_mount_data), addr.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr_sin_addr 80 __builtin_offsetof(struct __C(nfs_mount_data), addr.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr_sin_addr_s_addr 80 __builtin_offsetof(struct __C(nfs_mount_data), addr.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr_sin_family 76 __builtin_offsetof(struct __C(nfs_mount_data), addr.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_addr_sin_port 78 __builtin_offsetof(struct __C(nfs_mount_data), addr.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_bsize 352 __builtin_offsetof(struct __C(nfs_mount_data), bsize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_context 428 __builtin_offsetof(struct __C(nfs_mount_data), context)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_fd 4 __builtin_offsetof(struct __C(nfs_mount_data), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_flags 40 __builtin_offsetof(struct __C(nfs_mount_data), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_hostname 92 __builtin_offsetof(struct __C(nfs_mount_data), hostname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_namlen 348 __builtin_offsetof(struct __C(nfs_mount_data), namlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_old_root 8 __builtin_offsetof(struct __C(nfs_mount_data), old_root)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_old_root_data 8 __builtin_offsetof(struct __C(nfs_mount_data), old_root.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_pseudoflavor 424 __builtin_offsetof(struct __C(nfs_mount_data), pseudoflavor)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_retrans 56 __builtin_offsetof(struct __C(nfs_mount_data), retrans)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_root 356 __builtin_offsetof(struct __C(nfs_mount_data), root)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_root_data 358 __builtin_offsetof(struct __C(nfs_mount_data), root.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_root_size 356 __builtin_offsetof(struct __C(nfs_mount_data), root.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_rsize 44 __builtin_offsetof(struct __C(nfs_mount_data), rsize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_timeo 52 __builtin_offsetof(struct __C(nfs_mount_data), timeo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_version 0 __builtin_offsetof(struct __C(nfs_mount_data), version)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_mount_data_wsize 48 __builtin_offsetof(struct __C(nfs_mount_data), wsize)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nfs_string 16 sizeof(struct __C(nfs_string))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nfs_string 8 __alignof(struct __C(nfs_string))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_string_data 8 __builtin_offsetof(struct __C(nfs_string), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nfs_string_len 0 __builtin_offsetof(struct __C(nfs_string), len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nsm_iovec 16 sizeof(struct __C(nsm_iovec))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nsm_iovec 8 __alignof(struct __C(nsm_iovec))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_iovec_addr 0 __builtin_offsetof(struct __C(nsm_iovec), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_iovec_len 8 __builtin_offsetof(struct __C(nsm_iovec), len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nsm_raw 32 sizeof(struct __C(nsm_raw))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nsm_raw 8 __alignof(struct __C(nsm_raw))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_request 0 __builtin_offsetof(struct __C(nsm_raw), request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_request_addr 0 __builtin_offsetof(struct __C(nsm_raw), request.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_request_len 8 __builtin_offsetof(struct __C(nsm_raw), request.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_response 16 __builtin_offsetof(struct __C(nsm_raw), response)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_response_addr 16 __builtin_offsetof(struct __C(nsm_raw), response.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nsm_raw_response_len 24 __builtin_offsetof(struct __C(nsm_raw), response.len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nvme_passthru_cmd 72 sizeof(struct __C(nvme_passthru_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nvme_passthru_cmd 8 __alignof(struct __C(nvme_passthru_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_addr 24 __builtin_offsetof(struct __C(nvme_passthru_cmd), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw10 40 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw11 44 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw12 48 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw12)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw13 52 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw13)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw14 56 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw14)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw15 60 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw15)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw2 8 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_cdw3 12 __builtin_offsetof(struct __C(nvme_passthru_cmd), cdw3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_data_len 36 __builtin_offsetof(struct __C(nvme_passthru_cmd), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_flags 1 __builtin_offsetof(struct __C(nvme_passthru_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_metadata 16 __builtin_offsetof(struct __C(nvme_passthru_cmd), metadata)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_metadata_len 32 __builtin_offsetof(struct __C(nvme_passthru_cmd), metadata_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_nsid 4 __builtin_offsetof(struct __C(nvme_passthru_cmd), nsid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_opcode 0 __builtin_offsetof(struct __C(nvme_passthru_cmd), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_result 68 __builtin_offsetof(struct __C(nvme_passthru_cmd), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_rsvd1 2 __builtin_offsetof(struct __C(nvme_passthru_cmd), rsvd1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd_timeout_ms 64 __builtin_offsetof(struct __C(nvme_passthru_cmd), timeout_ms)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nvme_passthru_cmd64 80 sizeof(struct __C(nvme_passthru_cmd64))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nvme_passthru_cmd64 8 __alignof(struct __C(nvme_passthru_cmd64))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_addr 24 __builtin_offsetof(struct __C(nvme_passthru_cmd64), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw10 40 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw11 44 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw12 48 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw12)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw13 52 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw13)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw14 56 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw14)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw15 60 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw15)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw2 8 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_cdw3 12 __builtin_offsetof(struct __C(nvme_passthru_cmd64), cdw3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_data_len 36 __builtin_offsetof(struct __C(nvme_passthru_cmd64), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_flags 1 __builtin_offsetof(struct __C(nvme_passthru_cmd64), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_metadata 16 __builtin_offsetof(struct __C(nvme_passthru_cmd64), metadata)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_metadata_len 32 __builtin_offsetof(struct __C(nvme_passthru_cmd64), metadata_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_nsid 4 __builtin_offsetof(struct __C(nvme_passthru_cmd64), nsid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_opcode 0 __builtin_offsetof(struct __C(nvme_passthru_cmd64), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_result 72 __builtin_offsetof(struct __C(nvme_passthru_cmd64), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_rsvd1 2 __builtin_offsetof(struct __C(nvme_passthru_cmd64), rsvd1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_rsvd2 68 __builtin_offsetof(struct __C(nvme_passthru_cmd64), rsvd2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_timeout_ms 64 __builtin_offsetof(struct __C(nvme_passthru_cmd64), timeout_ms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_passthru_cmd64_vec_cnt 36 __builtin_offsetof(struct __C(nvme_passthru_cmd64), vec_cnt)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nvme_uring_cmd 72 sizeof(struct __C(nvme_uring_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nvme_uring_cmd 8 __alignof(struct __C(nvme_uring_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_addr 24 __builtin_offsetof(struct __C(nvme_uring_cmd), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw10 40 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw11 44 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw12 48 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw12)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw13 52 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw13)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw14 56 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw14)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw15 60 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw15)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw2 8 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_cdw3 12 __builtin_offsetof(struct __C(nvme_uring_cmd), cdw3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_data_len 36 __builtin_offsetof(struct __C(nvme_uring_cmd), data_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_flags 1 __builtin_offsetof(struct __C(nvme_uring_cmd), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_metadata 16 __builtin_offsetof(struct __C(nvme_uring_cmd), metadata)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_metadata_len 32 __builtin_offsetof(struct __C(nvme_uring_cmd), metadata_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_nsid 4 __builtin_offsetof(struct __C(nvme_uring_cmd), nsid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_opcode 0 __builtin_offsetof(struct __C(nvme_uring_cmd), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_rsvd1 2 __builtin_offsetof(struct __C(nvme_uring_cmd), rsvd1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_rsvd2 68 __builtin_offsetof(struct __C(nvme_uring_cmd), rsvd2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_uring_cmd_timeout_ms 64 __builtin_offsetof(struct __C(nvme_uring_cmd), timeout_ms)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_nvme_user_io 48 sizeof(struct __C(nvme_user_io))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_nvme_user_io 8 __alignof(struct __C(nvme_user_io))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_addr 16 __builtin_offsetof(struct __C(nvme_user_io), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_appmask 42 __builtin_offsetof(struct __C(nvme_user_io), appmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_apptag 40 __builtin_offsetof(struct __C(nvme_user_io), apptag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_control 2 __builtin_offsetof(struct __C(nvme_user_io), control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_dsmgmt 32 __builtin_offsetof(struct __C(nvme_user_io), dsmgmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_flags 1 __builtin_offsetof(struct __C(nvme_user_io), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_metadata 8 __builtin_offsetof(struct __C(nvme_user_io), metadata)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_nblocks 4 __builtin_offsetof(struct __C(nvme_user_io), nblocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_opcode 0 __builtin_offsetof(struct __C(nvme_user_io), opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_reftag 36 __builtin_offsetof(struct __C(nvme_user_io), reftag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_rsvd 6 __builtin_offsetof(struct __C(nvme_user_io), rsvd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_nvme_user_io_slba 24 __builtin_offsetof(struct __C(nvme_user_io), slba)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_omap3isp_ccdc_update_config 56 sizeof(struct __C(omap3isp_ccdc_update_config))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_omap3isp_ccdc_update_config 8 __alignof(struct __C(omap3isp_ccdc_update_config))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_alawip 4 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), alawip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_bclamp 8 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), bclamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_blcomp 16 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), blcomp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_cull 40 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), cull)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_flag 2 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), flag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_fpc 24 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), fpc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_lsc 48 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), lsc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_lsc_cfg 32 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), lsc_cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_ccdc_update_config_update 0 __builtin_offsetof(struct __C(omap3isp_ccdc_update_config), update)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_omap3isp_prev_update_config 112 sizeof(struct __C(omap3isp_prev_update_config))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_omap3isp_prev_update_config 8 __alignof(struct __C(omap3isp_prev_update_config))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_blkadj 56 __builtin_offsetof(struct __C(omap3isp_prev_update_config), blkadj)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_cfa 32 __builtin_offsetof(struct __C(omap3isp_prev_update_config), cfa)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_csc 72 __builtin_offsetof(struct __C(omap3isp_prev_update_config), csc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_csup 40 __builtin_offsetof(struct __C(omap3isp_prev_update_config), csup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_dcor 88 __builtin_offsetof(struct __C(omap3isp_prev_update_config), dcor)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_flag 4 __builtin_offsetof(struct __C(omap3isp_prev_update_config), flag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_gamma 104 __builtin_offsetof(struct __C(omap3isp_prev_update_config), gamma)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_hmed 24 __builtin_offsetof(struct __C(omap3isp_prev_update_config), hmed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_luma 16 __builtin_offsetof(struct __C(omap3isp_prev_update_config), luma)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_nf 96 __builtin_offsetof(struct __C(omap3isp_prev_update_config), nf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_rgb2rgb 64 __builtin_offsetof(struct __C(omap3isp_prev_update_config), rgb2rgb)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_shading_shift 8 __builtin_offsetof(struct __C(omap3isp_prev_update_config), shading_shift)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_update 0 __builtin_offsetof(struct __C(omap3isp_prev_update_config), update)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_wbal 48 __builtin_offsetof(struct __C(omap3isp_prev_update_config), wbal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_prev_update_config_yclimit 80 __builtin_offsetof(struct __C(omap3isp_prev_update_config), yclimit)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_omap3isp_stat_data 40 sizeof(struct __C(omap3isp_stat_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_omap3isp_stat_data 8 __alignof(struct __C(omap3isp_stat_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_buf 16 __builtin_offsetof(struct __C(omap3isp_stat_data), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_buf_size 24 __builtin_offsetof(struct __C(omap3isp_stat_data), buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_config_counter 32 __builtin_offsetof(struct __C(omap3isp_stat_data), config_counter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_cur_frame 30 __builtin_offsetof(struct __C(omap3isp_stat_data), cur_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame 24 __builtin_offsetof(struct __C(omap3isp_stat_data), frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame_buf_size 24 __builtin_offsetof(struct __C(omap3isp_stat_data), frame.buf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame_config_counter 32 __builtin_offsetof(struct __C(omap3isp_stat_data), frame.config_counter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame_cur_frame 30 __builtin_offsetof(struct __C(omap3isp_stat_data), frame.cur_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame_frame_number 28 __builtin_offsetof(struct __C(omap3isp_stat_data), frame.frame_number)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_frame_number 28 __builtin_offsetof(struct __C(omap3isp_stat_data), frame_number)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_ts 0 __builtin_offsetof(struct __C(omap3isp_stat_data), ts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_ts_tv_sec 0 __builtin_offsetof(struct __C(omap3isp_stat_data), ts.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omap3isp_stat_data_ts_tv_usec 8 __builtin_offsetof(struct __C(omap3isp_stat_data), ts.tv_usec)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_omapfb_memory_read 24 sizeof(struct __C(omapfb_memory_read))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_omapfb_memory_read 8 __alignof(struct __C(omapfb_memory_read))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_buffer 16 __builtin_offsetof(struct __C(omapfb_memory_read), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_buffer_size 8 __builtin_offsetof(struct __C(omapfb_memory_read), buffer_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_h 6 __builtin_offsetof(struct __C(omapfb_memory_read), h)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_w 4 __builtin_offsetof(struct __C(omapfb_memory_read), w)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_x 0 __builtin_offsetof(struct __C(omapfb_memory_read), x)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_omapfb_memory_read_y 2 __builtin_offsetof(struct __C(omapfb_memory_read), y)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_opal_discovery 16 sizeof(struct __C(opal_discovery))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_opal_discovery 8 __alignof(struct __C(opal_discovery))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_discovery_data 0 __builtin_offsetof(struct __C(opal_discovery), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_discovery_size 8 __builtin_offsetof(struct __C(opal_discovery), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_opal_read_write_table 312 sizeof(struct __C(opal_read_write_table))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_opal_read_write_table 8 __alignof(struct __C(opal_read_write_table))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_data 264 __builtin_offsetof(struct __C(opal_read_write_table), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_flags 296 __builtin_offsetof(struct __C(opal_read_write_table), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key 0 __builtin_offsetof(struct __C(opal_read_write_table), key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key___align 3 __builtin_offsetof(struct __C(opal_read_write_table), key.__align)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key_key 8 __builtin_offsetof(struct __C(opal_read_write_table), key.key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key_key_len 1 __builtin_offsetof(struct __C(opal_read_write_table), key.key_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key_key_type 2 __builtin_offsetof(struct __C(opal_read_write_table), key.key_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_key_lr 0 __builtin_offsetof(struct __C(opal_read_write_table), key.lr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_offset 280 __builtin_offsetof(struct __C(opal_read_write_table), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_priv 304 __builtin_offsetof(struct __C(opal_read_write_table), priv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_size 288 __builtin_offsetof(struct __C(opal_read_write_table), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_read_write_table_table_uid 272 __builtin_offsetof(struct __C(opal_read_write_table), table_uid)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_opal_shadow_mbr 288 sizeof(struct __C(opal_shadow_mbr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_opal_shadow_mbr 8 __alignof(struct __C(opal_shadow_mbr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_data 264 __builtin_offsetof(struct __C(opal_shadow_mbr), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key 0 __builtin_offsetof(struct __C(opal_shadow_mbr), key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key___align 3 __builtin_offsetof(struct __C(opal_shadow_mbr), key.__align)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key_key 8 __builtin_offsetof(struct __C(opal_shadow_mbr), key.key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key_key_len 1 __builtin_offsetof(struct __C(opal_shadow_mbr), key.key_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key_key_type 2 __builtin_offsetof(struct __C(opal_shadow_mbr), key.key_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_key_lr 0 __builtin_offsetof(struct __C(opal_shadow_mbr), key.lr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_offset 272 __builtin_offsetof(struct __C(opal_shadow_mbr), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_opal_shadow_mbr_size 280 __builtin_offsetof(struct __C(opal_shadow_mbr), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_osd_cmd_s 32 sizeof(struct __C(osd_cmd_s))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_osd_cmd_s 8 __alignof(struct __C(osd_cmd_s))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_cmd 0 __builtin_offsetof(struct __C(osd_cmd_s), cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_color 20 __builtin_offsetof(struct __C(osd_cmd_s), color)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_data 24 __builtin_offsetof(struct __C(osd_cmd_s), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_x0 4 __builtin_offsetof(struct __C(osd_cmd_s), x0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_x1 12 __builtin_offsetof(struct __C(osd_cmd_s), x1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_y0 8 __builtin_offsetof(struct __C(osd_cmd_s), y0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_osd_cmd_s_y1 16 __builtin_offsetof(struct __C(osd_cmd_s), y1)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_pm_scan_arg 96 sizeof(struct __C(pm_scan_arg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_pm_scan_arg 8 __alignof(struct __C(pm_scan_arg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_category_anyof_mask 80 __builtin_offsetof(struct __C(pm_scan_arg), category_anyof_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_category_inverted 64 __builtin_offsetof(struct __C(pm_scan_arg), category_inverted)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_category_mask 72 __builtin_offsetof(struct __C(pm_scan_arg), category_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_end 24 __builtin_offsetof(struct __C(pm_scan_arg), end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_flags 8 __builtin_offsetof(struct __C(pm_scan_arg), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_max_pages 56 __builtin_offsetof(struct __C(pm_scan_arg), max_pages)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_return_mask 88 __builtin_offsetof(struct __C(pm_scan_arg), return_mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_size 0 __builtin_offsetof(struct __C(pm_scan_arg), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_start 16 __builtin_offsetof(struct __C(pm_scan_arg), start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_vec 40 __builtin_offsetof(struct __C(pm_scan_arg), vec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_vec_len 48 __builtin_offsetof(struct __C(pm_scan_arg), vec_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pm_scan_arg_walk_end 32 __builtin_offsetof(struct __C(pm_scan_arg), walk_end)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ppl_header 4088 sizeof(struct __C(ppl_header))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ppl_header 1 __alignof(struct __C(ppl_header))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_checksum 532 __builtin_offsetof(struct __C(ppl_header), checksum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries 536 __builtin_offsetof(struct __C(ppl_header), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_0__checksum 556 __builtin_offsetof(struct __C(ppl_header), entries[0].checksum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_0__data_sector 536 __builtin_offsetof(struct __C(ppl_header), entries[0].data_sector)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_0__data_size 548 __builtin_offsetof(struct __C(ppl_header), entries[0].data_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_0__parity_disk 552 __builtin_offsetof(struct __C(ppl_header), entries[0].parity_disk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_0__pp_size 544 __builtin_offsetof(struct __C(ppl_header), entries[0].pp_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_entries_count 528 __builtin_offsetof(struct __C(ppl_header), entries_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_generation 520 __builtin_offsetof(struct __C(ppl_header), generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_padding 516 __builtin_offsetof(struct __C(ppl_header), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_reserved 0 __builtin_offsetof(struct __C(ppl_header), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppl_header_signature 512 __builtin_offsetof(struct __C(ppl_header), signature)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ppp_option_data 16 sizeof(struct __C(ppp_option_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ppp_option_data 8 __alignof(struct __C(ppp_option_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppp_option_data_length 8 __builtin_offsetof(struct __C(ppp_option_data), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppp_option_data_ptr 0 __builtin_offsetof(struct __C(ppp_option_data), ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ppp_option_data_transmit 12 __builtin_offsetof(struct __C(ppp_option_data), transmit)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_pppol2tp_addr 32 sizeof(struct __C(pppol2tp_addr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_pppol2tp_addr 4 __alignof(struct __C(pppol2tp_addr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr 8 __builtin_offsetof(struct __C(pppol2tp_addr), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr___pad 16 __builtin_offsetof(struct __C(pppol2tp_addr), addr.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr_sin_addr 12 __builtin_offsetof(struct __C(pppol2tp_addr), addr.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr_sin_addr_s_addr 12 __builtin_offsetof(struct __C(pppol2tp_addr), addr.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr_sin_family 8 __builtin_offsetof(struct __C(pppol2tp_addr), addr.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_addr_sin_port 10 __builtin_offsetof(struct __C(pppol2tp_addr), addr.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_d_session 30 __builtin_offsetof(struct __C(pppol2tp_addr), d_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_d_tunnel 28 __builtin_offsetof(struct __C(pppol2tp_addr), d_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_fd 4 __builtin_offsetof(struct __C(pppol2tp_addr), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_pid 0 __builtin_offsetof(struct __C(pppol2tp_addr), pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_s_session 26 __builtin_offsetof(struct __C(pppol2tp_addr), s_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tp_addr_s_tunnel 24 __builtin_offsetof(struct __C(pppol2tp_addr), s_tunnel)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_pppol2tpv3_addr 40 sizeof(struct __C(pppol2tpv3_addr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_pppol2tpv3_addr 4 __alignof(struct __C(pppol2tpv3_addr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr 8 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr___pad 16 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr_sin_addr 12 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr_sin_addr_s_addr 12 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr_sin_family 8 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_addr_sin_port 10 __builtin_offsetof(struct __C(pppol2tpv3_addr), addr.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_d_session 36 __builtin_offsetof(struct __C(pppol2tpv3_addr), d_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_d_tunnel 32 __builtin_offsetof(struct __C(pppol2tpv3_addr), d_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_fd 4 __builtin_offsetof(struct __C(pppol2tpv3_addr), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_pid 0 __builtin_offsetof(struct __C(pppol2tpv3_addr), pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_s_session 28 __builtin_offsetof(struct __C(pppol2tpv3_addr), s_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_pppol2tpv3_addr_s_tunnel 24 __builtin_offsetof(struct __C(pppol2tpv3_addr), s_tunnel)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_prctl_mm_map 104 sizeof(struct __C(prctl_mm_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_prctl_mm_map 8 __alignof(struct __C(prctl_mm_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_arg_end 64 __builtin_offsetof(struct __C(prctl_mm_map), arg_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_arg_start 56 __builtin_offsetof(struct __C(prctl_mm_map), arg_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_auxv 88 __builtin_offsetof(struct __C(prctl_mm_map), auxv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_auxv_size 96 __builtin_offsetof(struct __C(prctl_mm_map), auxv_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_brk 40 __builtin_offsetof(struct __C(prctl_mm_map), brk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_end_code 8 __builtin_offsetof(struct __C(prctl_mm_map), end_code)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_end_data 24 __builtin_offsetof(struct __C(prctl_mm_map), end_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_env_end 80 __builtin_offsetof(struct __C(prctl_mm_map), env_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_env_start 72 __builtin_offsetof(struct __C(prctl_mm_map), env_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_exe_fd 100 __builtin_offsetof(struct __C(prctl_mm_map), exe_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_start_brk 32 __builtin_offsetof(struct __C(prctl_mm_map), start_brk)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_start_code 0 __builtin_offsetof(struct __C(prctl_mm_map), start_code)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_start_data 16 __builtin_offsetof(struct __C(prctl_mm_map), start_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_prctl_mm_map_start_stack 48 __builtin_offsetof(struct __C(prctl_mm_map), start_stack)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_procmap_query 104 sizeof(struct __C(procmap_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_procmap_query 8 __alignof(struct __C(procmap_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_build_id_addr 96 __builtin_offsetof(struct __C(procmap_query), build_id_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_build_id_size 84 __builtin_offsetof(struct __C(procmap_query), build_id_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_dev_major 72 __builtin_offsetof(struct __C(procmap_query), dev_major)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_dev_minor 76 __builtin_offsetof(struct __C(procmap_query), dev_minor)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_inode 64 __builtin_offsetof(struct __C(procmap_query), inode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_query_addr 16 __builtin_offsetof(struct __C(procmap_query), query_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_query_flags 8 __builtin_offsetof(struct __C(procmap_query), query_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_size 0 __builtin_offsetof(struct __C(procmap_query), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_end 32 __builtin_offsetof(struct __C(procmap_query), vma_end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_flags 40 __builtin_offsetof(struct __C(procmap_query), vma_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_name_addr 88 __builtin_offsetof(struct __C(procmap_query), vma_name_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_name_size 80 __builtin_offsetof(struct __C(procmap_query), vma_name_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_offset 56 __builtin_offsetof(struct __C(procmap_query), vma_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_page_size 48 __builtin_offsetof(struct __C(procmap_query), vma_page_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_procmap_query_vma_start 24 __builtin_offsetof(struct __C(procmap_query), vma_start)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ptrace_sud_config 32 sizeof(struct __C(ptrace_sud_config))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ptrace_sud_config 8 __alignof(struct __C(ptrace_sud_config))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ptrace_sud_config_len 24 __builtin_offsetof(struct __C(ptrace_sud_config), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ptrace_sud_config_mode 0 __builtin_offsetof(struct __C(ptrace_sud_config), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ptrace_sud_config_offset 16 __builtin_offsetof(struct __C(ptrace_sud_config), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ptrace_sud_config_selector 8 __builtin_offsetof(struct __C(ptrace_sud_config), selector)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_qaic_attach_slice 32 sizeof(struct __C(qaic_attach_slice))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_qaic_attach_slice 8 __alignof(struct __C(qaic_attach_slice))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_data 24 __builtin_offsetof(struct __C(qaic_attach_slice), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr 0 __builtin_offsetof(struct __C(qaic_attach_slice), hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr_count 0 __builtin_offsetof(struct __C(qaic_attach_slice), hdr.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr_dbc_id 4 __builtin_offsetof(struct __C(qaic_attach_slice), hdr.dbc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr_dir 12 __builtin_offsetof(struct __C(qaic_attach_slice), hdr.dir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr_handle 8 __builtin_offsetof(struct __C(qaic_attach_slice), hdr.handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_attach_slice_hdr_size 16 __builtin_offsetof(struct __C(qaic_attach_slice), hdr.size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_qaic_execute 16 sizeof(struct __C(qaic_execute))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_qaic_execute 8 __alignof(struct __C(qaic_execute))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_execute_data 8 __builtin_offsetof(struct __C(qaic_execute), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_execute_hdr 0 __builtin_offsetof(struct __C(qaic_execute), hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_execute_hdr_count 0 __builtin_offsetof(struct __C(qaic_execute), hdr.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_execute_hdr_dbc_id 4 __builtin_offsetof(struct __C(qaic_execute), hdr.dbc_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_qaic_manage_msg 16 sizeof(struct __C(qaic_manage_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_qaic_manage_msg 8 __alignof(struct __C(qaic_manage_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_manage_msg_count 4 __builtin_offsetof(struct __C(qaic_manage_msg), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_manage_msg_data 8 __builtin_offsetof(struct __C(qaic_manage_msg), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_manage_msg_len 0 __builtin_offsetof(struct __C(qaic_manage_msg), len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_qaic_perf_stats 16 sizeof(struct __C(qaic_perf_stats))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_qaic_perf_stats 8 __alignof(struct __C(qaic_perf_stats))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_perf_stats_data 8 __builtin_offsetof(struct __C(qaic_perf_stats), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_perf_stats_hdr 0 __builtin_offsetof(struct __C(qaic_perf_stats), hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_perf_stats_hdr_count 0 __builtin_offsetof(struct __C(qaic_perf_stats), hdr.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_perf_stats_hdr_dbc_id 4 __builtin_offsetof(struct __C(qaic_perf_stats), hdr.dbc_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_qaic_perf_stats_hdr_pad 2 __builtin_offsetof(struct __C(qaic_perf_stats), hdr.pad)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rio_cm_msg 16 sizeof(struct __C(rio_cm_msg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rio_cm_msg 8 __alignof(struct __C(rio_cm_msg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_cm_msg_ch_num 0 __builtin_offsetof(struct __C(rio_cm_msg), ch_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_cm_msg_msg 8 __builtin_offsetof(struct __C(rio_cm_msg), msg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_cm_msg_rxto 4 __builtin_offsetof(struct __C(rio_cm_msg), rxto)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_cm_msg_size 2 __builtin_offsetof(struct __C(rio_cm_msg), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rio_mport_maint_io 24 sizeof(struct __C(rio_mport_maint_io))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rio_mport_maint_io 8 __alignof(struct __C(rio_mport_maint_io))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_buffer 16 __builtin_offsetof(struct __C(rio_mport_maint_io), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_hopcount 2 __builtin_offsetof(struct __C(rio_mport_maint_io), hopcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_length 12 __builtin_offsetof(struct __C(rio_mport_maint_io), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_offset 8 __builtin_offsetof(struct __C(rio_mport_maint_io), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_pad0 3 __builtin_offsetof(struct __C(rio_mport_maint_io), pad0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_mport_maint_io_rioid 0 __builtin_offsetof(struct __C(rio_mport_maint_io), rioid)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rio_transaction 24 sizeof(struct __C(rio_transaction))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rio_transaction 8 __alignof(struct __C(rio_transaction))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_block 0 __builtin_offsetof(struct __C(rio_transaction), block)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_count 8 __builtin_offsetof(struct __C(rio_transaction), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_dir 18 __builtin_offsetof(struct __C(rio_transaction), dir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_pad0 20 __builtin_offsetof(struct __C(rio_transaction), pad0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_sync 16 __builtin_offsetof(struct __C(rio_transaction), sync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rio_transaction_transfer_mode 12 __builtin_offsetof(struct __C(rio_transaction), transfer_mode)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rkisp1_ext_params_cfg 4400 sizeof(struct __C(rkisp1_ext_params_cfg))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rkisp1_ext_params_cfg 4 __alignof(struct __C(rkisp1_ext_params_cfg))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rkisp1_ext_params_cfg_data 8 __builtin_offsetof(struct __C(rkisp1_ext_params_cfg), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rkisp1_ext_params_cfg_data_size 4 __builtin_offsetof(struct __C(rkisp1_ext_params_cfg), data_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rkisp1_ext_params_cfg_version 0 __builtin_offsetof(struct __C(rkisp1_ext_params_cfg), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_robust_list 8 sizeof(struct __C(robust_list))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_robust_list 8 __alignof(struct __C(robust_list))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_robust_list_next 0 __builtin_offsetof(struct __C(robust_list), next)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_robust_list_head 24 sizeof(struct __C(robust_list_head))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_robust_list_head 8 __alignof(struct __C(robust_list_head))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_robust_list_head_futex_offset 8 __builtin_offsetof(struct __C(robust_list_head), futex_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_robust_list_head_list 0 __builtin_offsetof(struct __C(robust_list_head), list)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_robust_list_head_list_next 0 __builtin_offsetof(struct __C(robust_list_head), list.next)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_robust_list_head_list_op_pending 16 __builtin_offsetof(struct __C(robust_list_head), list_op_pending)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rseq 32 sizeof(struct __C(rseq))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rseq 32 __alignof(struct __C(rseq))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cpu_id 4 __builtin_offsetof(struct __C(rseq), cpu_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cpu_id_start 0 __builtin_offsetof(struct __C(rseq), cpu_id_start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_end 28 __builtin_offsetof(struct __C(rseq), end)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_flags 16 __builtin_offsetof(struct __C(rseq), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_mm_cid 24 __builtin_offsetof(struct __C(rseq), mm_cid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_node_id 20 __builtin_offsetof(struct __C(rseq), node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_rseq_cs 8 __builtin_offsetof(struct __C(rseq), rseq_cs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rseq_cs 32 sizeof(struct __C(rseq_cs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rseq_cs 32 __alignof(struct __C(rseq_cs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cs_abort_ip 24 __builtin_offsetof(struct __C(rseq_cs), abort_ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cs_flags 4 __builtin_offsetof(struct __C(rseq_cs), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cs_post_commit_offset 16 __builtin_offsetof(struct __C(rseq_cs), post_commit_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cs_start_ip 8 __builtin_offsetof(struct __C(rseq_cs), start_ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rseq_cs_version 0 __builtin_offsetof(struct __C(rseq_cs), version)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_rtentry 120 sizeof(struct __C(rtentry))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_rtentry 8 __alignof(struct __C(rtentry))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_dev 88 __builtin_offsetof(struct __C(rtentry), rt_dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_dst 8 __builtin_offsetof(struct __C(rtentry), rt_dst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_flags 56 __builtin_offsetof(struct __C(rtentry), rt_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_gateway 24 __builtin_offsetof(struct __C(rtentry), rt_gateway)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_genmask 40 __builtin_offsetof(struct __C(rtentry), rt_genmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_irtt 112 __builtin_offsetof(struct __C(rtentry), rt_irtt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_metric 80 __builtin_offsetof(struct __C(rtentry), rt_metric)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_mtu 96 __builtin_offsetof(struct __C(rtentry), rt_mtu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_pad1 0 __builtin_offsetof(struct __C(rtentry), rt_pad1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_pad2 58 __builtin_offsetof(struct __C(rtentry), rt_pad2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_pad3 64 __builtin_offsetof(struct __C(rtentry), rt_pad3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_pad4 72 __builtin_offsetof(struct __C(rtentry), rt_pad4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_rtentry_rt_window 104 __builtin_offsetof(struct __C(rtentry), rt_window)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sctp_getaddrs_old 16 sizeof(struct __C(sctp_getaddrs_old))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sctp_getaddrs_old 8 __alignof(struct __C(sctp_getaddrs_old))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sctp_getaddrs_old_addr_num 4 __builtin_offsetof(struct __C(sctp_getaddrs_old), addr_num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sctp_getaddrs_old_addrs 8 __builtin_offsetof(struct __C(sctp_getaddrs_old), addrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sctp_getaddrs_old_assoc_id 0 __builtin_offsetof(struct __C(sctp_getaddrs_old), assoc_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_semid_ds 88 sizeof(struct __C(semid_ds))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_semid_ds 8 __alignof(struct __C(semid_ds))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_base 48 __builtin_offsetof(struct __C(semid_ds), sem_base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_ctime 40 __builtin_offsetof(struct __C(semid_ds), sem_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_nsems 80 __builtin_offsetof(struct __C(semid_ds), sem_nsems)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_otime 32 __builtin_offsetof(struct __C(semid_ds), sem_otime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_pending 56 __builtin_offsetof(struct __C(semid_ds), sem_pending)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_pending_last 64 __builtin_offsetof(struct __C(semid_ds), sem_pending_last)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm 0 __builtin_offsetof(struct __C(semid_ds), sem_perm)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_cgid 16 __builtin_offsetof(struct __C(semid_ds), sem_perm.cgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_cuid 12 __builtin_offsetof(struct __C(semid_ds), sem_perm.cuid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_gid 8 __builtin_offsetof(struct __C(semid_ds), sem_perm.gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_key 0 __builtin_offsetof(struct __C(semid_ds), sem_perm.key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_mode 20 __builtin_offsetof(struct __C(semid_ds), sem_perm.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_seq 24 __builtin_offsetof(struct __C(semid_ds), sem_perm.seq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_sem_perm_uid 4 __builtin_offsetof(struct __C(semid_ds), sem_perm.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semid_ds_undo 72 __builtin_offsetof(struct __C(semid_ds), undo)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sg_io_v4 160 sizeof(struct __C(sg_io_v4))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sg_io_v4 8 __alignof(struct __C(sg_io_v4))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_device_status 116 __builtin_offsetof(struct __C(sg_io_v4), device_status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_din_iovec_count 64 __builtin_offsetof(struct __C(sg_io_v4), din_iovec_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_din_resid 136 __builtin_offsetof(struct __C(sg_io_v4), din_resid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_din_xfer_len 68 __builtin_offsetof(struct __C(sg_io_v4), din_xfer_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_din_xferp 80 __builtin_offsetof(struct __C(sg_io_v4), din_xferp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_dout_iovec_count 56 __builtin_offsetof(struct __C(sg_io_v4), dout_iovec_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_dout_resid 140 __builtin_offsetof(struct __C(sg_io_v4), dout_resid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_dout_xfer_len 60 __builtin_offsetof(struct __C(sg_io_v4), dout_xfer_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_dout_xferp 72 __builtin_offsetof(struct __C(sg_io_v4), dout_xferp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_driver_status 108 __builtin_offsetof(struct __C(sg_io_v4), driver_status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_duration 128 __builtin_offsetof(struct __C(sg_io_v4), duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_flags 92 __builtin_offsetof(struct __C(sg_io_v4), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_generated_tag 144 __builtin_offsetof(struct __C(sg_io_v4), generated_tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_guard 0 __builtin_offsetof(struct __C(sg_io_v4), guard)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_info 124 __builtin_offsetof(struct __C(sg_io_v4), info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_max_response_len 44 __builtin_offsetof(struct __C(sg_io_v4), max_response_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_padding 156 __builtin_offsetof(struct __C(sg_io_v4), padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_protocol 4 __builtin_offsetof(struct __C(sg_io_v4), protocol)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request 16 __builtin_offsetof(struct __C(sg_io_v4), request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request_attr 32 __builtin_offsetof(struct __C(sg_io_v4), request_attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request_extra 40 __builtin_offsetof(struct __C(sg_io_v4), request_extra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request_len 12 __builtin_offsetof(struct __C(sg_io_v4), request_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request_priority 36 __builtin_offsetof(struct __C(sg_io_v4), request_priority)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_request_tag 24 __builtin_offsetof(struct __C(sg_io_v4), request_tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_response 48 __builtin_offsetof(struct __C(sg_io_v4), response)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_response_len 132 __builtin_offsetof(struct __C(sg_io_v4), response_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_retry_delay 120 __builtin_offsetof(struct __C(sg_io_v4), retry_delay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_spare_in 104 __builtin_offsetof(struct __C(sg_io_v4), spare_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_spare_out 152 __builtin_offsetof(struct __C(sg_io_v4), spare_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_subprotocol 8 __builtin_offsetof(struct __C(sg_io_v4), subprotocol)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_timeout 88 __builtin_offsetof(struct __C(sg_io_v4), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_transport_status 112 __builtin_offsetof(struct __C(sg_io_v4), transport_status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sg_io_v4_usr_ptr 96 __builtin_offsetof(struct __C(sg_io_v4), usr_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_shmid_ds 88 sizeof(struct __C(shmid_ds))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_shmid_ds 8 __alignof(struct __C(shmid_ds))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_atime 32 __builtin_offsetof(struct __C(shmid_ds), shm_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_cpid 56 __builtin_offsetof(struct __C(shmid_ds), shm_cpid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_ctime 48 __builtin_offsetof(struct __C(shmid_ds), shm_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_dtime 40 __builtin_offsetof(struct __C(shmid_ds), shm_dtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_lpid 60 __builtin_offsetof(struct __C(shmid_ds), shm_lpid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_nattch 64 __builtin_offsetof(struct __C(shmid_ds), shm_nattch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm 0 __builtin_offsetof(struct __C(shmid_ds), shm_perm)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_cgid 16 __builtin_offsetof(struct __C(shmid_ds), shm_perm.cgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_cuid 12 __builtin_offsetof(struct __C(shmid_ds), shm_perm.cuid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_gid 8 __builtin_offsetof(struct __C(shmid_ds), shm_perm.gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_key 0 __builtin_offsetof(struct __C(shmid_ds), shm_perm.key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_mode 20 __builtin_offsetof(struct __C(shmid_ds), shm_perm.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_seq 24 __builtin_offsetof(struct __C(shmid_ds), shm_perm.seq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_perm_uid 4 __builtin_offsetof(struct __C(shmid_ds), shm_perm.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_segsz 28 __builtin_offsetof(struct __C(shmid_ds), shm_segsz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_unused 66 __builtin_offsetof(struct __C(shmid_ds), shm_unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_unused2 72 __builtin_offsetof(struct __C(shmid_ds), shm_unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_shmid_ds_shm_unused3 80 __builtin_offsetof(struct __C(shmid_ds), shm_unused3)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sigaltstack 24 sizeof(struct __C(sigaltstack))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sigaltstack 8 __alignof(struct __C(sigaltstack))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigaltstack_ss_flags 8 __builtin_offsetof(struct __C(sigaltstack), ss_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigaltstack_ss_size 16 __builtin_offsetof(struct __C(sigaltstack), ss_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigaltstack_ss_sp 0 __builtin_offsetof(struct __C(sigaltstack), ss_sp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sigcontext 784 sizeof(struct __C(sigcontext))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sigcontext 16 __alignof(struct __C(sigcontext))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc 256 __builtin_offsetof(struct __C(sigcontext), sc_extdesc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc___padding 256 __builtin_offsetof(struct __C(sigcontext), sc_extdesc.__padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc_hdr 776 __builtin_offsetof(struct __C(sigcontext), sc_extdesc.hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc_hdr_magic 776 __builtin_offsetof(struct __C(sigcontext), sc_extdesc.hdr.magic)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc_hdr_size 780 __builtin_offsetof(struct __C(sigcontext), sc_extdesc.hdr.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_extdesc_reserved 772 __builtin_offsetof(struct __C(sigcontext), sc_extdesc.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_d 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_d_f 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.d.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_d_fcsr 512 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.d.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_f 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_f_f 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.f.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_f_fcsr 384 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.f.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_q 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.q)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_q_f 256 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.q.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_q_fcsr 768 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.q.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_fpregs_q_reserved 772 __builtin_offsetof(struct __C(sigcontext), sc_fpregs.q.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs 0 __builtin_offsetof(struct __C(sigcontext), sc_regs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a0 80 __builtin_offsetof(struct __C(sigcontext), sc_regs.a0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a1 88 __builtin_offsetof(struct __C(sigcontext), sc_regs.a1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a2 96 __builtin_offsetof(struct __C(sigcontext), sc_regs.a2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a3 104 __builtin_offsetof(struct __C(sigcontext), sc_regs.a3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a4 112 __builtin_offsetof(struct __C(sigcontext), sc_regs.a4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a5 120 __builtin_offsetof(struct __C(sigcontext), sc_regs.a5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a6 128 __builtin_offsetof(struct __C(sigcontext), sc_regs.a6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_a7 136 __builtin_offsetof(struct __C(sigcontext), sc_regs.a7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_gp 24 __builtin_offsetof(struct __C(sigcontext), sc_regs.gp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_pc 0 __builtin_offsetof(struct __C(sigcontext), sc_regs.pc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_ra 8 __builtin_offsetof(struct __C(sigcontext), sc_regs.ra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s0 64 __builtin_offsetof(struct __C(sigcontext), sc_regs.s0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s1 72 __builtin_offsetof(struct __C(sigcontext), sc_regs.s1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s10 208 __builtin_offsetof(struct __C(sigcontext), sc_regs.s10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s11 216 __builtin_offsetof(struct __C(sigcontext), sc_regs.s11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s2 144 __builtin_offsetof(struct __C(sigcontext), sc_regs.s2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s3 152 __builtin_offsetof(struct __C(sigcontext), sc_regs.s3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s4 160 __builtin_offsetof(struct __C(sigcontext), sc_regs.s4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s5 168 __builtin_offsetof(struct __C(sigcontext), sc_regs.s5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s6 176 __builtin_offsetof(struct __C(sigcontext), sc_regs.s6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s7 184 __builtin_offsetof(struct __C(sigcontext), sc_regs.s7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s8 192 __builtin_offsetof(struct __C(sigcontext), sc_regs.s8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_s9 200 __builtin_offsetof(struct __C(sigcontext), sc_regs.s9)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_sp 16 __builtin_offsetof(struct __C(sigcontext), sc_regs.sp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t0 40 __builtin_offsetof(struct __C(sigcontext), sc_regs.t0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t1 48 __builtin_offsetof(struct __C(sigcontext), sc_regs.t1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t2 56 __builtin_offsetof(struct __C(sigcontext), sc_regs.t2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t3 224 __builtin_offsetof(struct __C(sigcontext), sc_regs.t3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t4 232 __builtin_offsetof(struct __C(sigcontext), sc_regs.t4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t5 240 __builtin_offsetof(struct __C(sigcontext), sc_regs.t5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_t6 248 __builtin_offsetof(struct __C(sigcontext), sc_regs.t6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigcontext_sc_regs_tp 32 __builtin_offsetof(struct __C(sigcontext), sc_regs.tp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_ctl_elem_info 272 sizeof(struct __C(snd_ctl_elem_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_ctl_elem_info 8 __alignof(struct __C(snd_ctl_elem_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_access 68 __builtin_offsetof(struct __C(snd_ctl_elem_info), access)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_count 72 __builtin_offsetof(struct __C(snd_ctl_elem_info), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id 0 __builtin_offsetof(struct __C(snd_ctl_elem_info), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_device 8 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.device)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_iface 4 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.iface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_index 60 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_name 16 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_numid 0 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.numid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_id_subdevice 12 __builtin_offsetof(struct __C(snd_ctl_elem_info), id.subdevice)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_owner 76 __builtin_offsetof(struct __C(snd_ctl_elem_info), owner)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_reserved 208 __builtin_offsetof(struct __C(snd_ctl_elem_info), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_type 64 __builtin_offsetof(struct __C(snd_ctl_elem_info), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated_item 84 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated.item)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated_items 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated.items)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated_name 88 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated_names_length 160 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated.names_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_enumerated_names_ptr 152 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.enumerated.names_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer_max 88 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer_min 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer.min)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer_step 96 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer.step)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer64 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer64)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer64_max 88 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer64.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer64_min 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer64.min)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_integer64_step 96 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.integer64.step)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_info_value_reserved 80 __builtin_offsetof(struct __C(snd_ctl_elem_info), value.reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_ctl_elem_list 80 sizeof(struct __C(snd_ctl_elem_list))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_ctl_elem_list 8 __alignof(struct __C(snd_ctl_elem_list))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_count 12 __builtin_offsetof(struct __C(snd_ctl_elem_list), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_offset 0 __builtin_offsetof(struct __C(snd_ctl_elem_list), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_pids 16 __builtin_offsetof(struct __C(snd_ctl_elem_list), pids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_reserved 24 __builtin_offsetof(struct __C(snd_ctl_elem_list), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_space 4 __builtin_offsetof(struct __C(snd_ctl_elem_list), space)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_list_used 8 __builtin_offsetof(struct __C(snd_ctl_elem_list), used)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_ctl_elem_value 1224 sizeof(struct __C(snd_ctl_elem_value))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_ctl_elem_value 8 __alignof(struct __C(snd_ctl_elem_value))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id 0 __builtin_offsetof(struct __C(snd_ctl_elem_value), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_device 8 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.device)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_iface 4 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.iface)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_index 60 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_name 16 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_numid 0 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.numid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_id_subdevice 12 __builtin_offsetof(struct __C(snd_ctl_elem_value), id.subdevice)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_reserved 1096 __builtin_offsetof(struct __C(snd_ctl_elem_value), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_bytes 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_bytes_data 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.bytes.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_bytes_data_ptr 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.bytes.data_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_enumerated 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.enumerated)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_enumerated_item 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.enumerated.item)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_enumerated_item_ptr 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.enumerated.item_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_iec958 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.iec958)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_iec958_dig_subframe 244 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.iec958.dig_subframe)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_iec958_pad 243 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.iec958.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_iec958_status 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.iec958.status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_iec958_subcode 96 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.iec958.subcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer_value 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer_value_ptr 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer.value_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer64 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer64)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer64_value 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer64.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_ctl_elem_value_value_integer64_value_ptr 72 __builtin_offsetof(struct __C(snd_ctl_elem_value), value.integer64.value_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_hwdep_dsp_image 96 sizeof(struct __C(snd_hwdep_dsp_image))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_hwdep_dsp_image 8 __alignof(struct __C(snd_hwdep_dsp_image))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_hwdep_dsp_image_driver_data 88 __builtin_offsetof(struct __C(snd_hwdep_dsp_image), driver_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_hwdep_dsp_image_image 72 __builtin_offsetof(struct __C(snd_hwdep_dsp_image), image)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_hwdep_dsp_image_index 0 __builtin_offsetof(struct __C(snd_hwdep_dsp_image), index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_hwdep_dsp_image_length 80 __builtin_offsetof(struct __C(snd_hwdep_dsp_image), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_hwdep_dsp_image_name 4 __builtin_offsetof(struct __C(snd_hwdep_dsp_image), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_ev_ext 12 sizeof(struct __C(snd_seq_ev_ext))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_ev_ext 1 __alignof(struct __C(snd_seq_ev_ext))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_ext_len 0 __builtin_offsetof(struct __C(snd_seq_ev_ext), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_ext_ptr 4 __builtin_offsetof(struct __C(snd_seq_ev_ext), ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_ev_quote 12 sizeof(struct __C(snd_seq_ev_quote))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_ev_quote 1 __alignof(struct __C(snd_seq_ev_quote))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_quote_event 4 __builtin_offsetof(struct __C(snd_seq_ev_quote), event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_quote_origin 0 __builtin_offsetof(struct __C(snd_seq_ev_quote), origin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_quote_origin_client 0 __builtin_offsetof(struct __C(snd_seq_ev_quote), origin.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_quote_origin_port 1 __builtin_offsetof(struct __C(snd_seq_ev_quote), origin.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ev_quote_value 2 __builtin_offsetof(struct __C(snd_seq_ev_quote), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_event 28 sizeof(struct __C(snd_seq_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_event 4 __alignof(struct __C(snd_seq_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data 16 __builtin_offsetof(struct __C(snd_seq_event), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr 16 __builtin_offsetof(struct __C(snd_seq_event), data.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr_client 16 __builtin_offsetof(struct __C(snd_seq_event), data.addr.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr_port 17 __builtin_offsetof(struct __C(snd_seq_event), data.addr.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect 16 __builtin_offsetof(struct __C(snd_seq_event), data.connect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest 18 __builtin_offsetof(struct __C(snd_seq_event), data.connect.dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest_client 18 __builtin_offsetof(struct __C(snd_seq_event), data.connect.dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest_port 19 __builtin_offsetof(struct __C(snd_seq_event), data.connect.dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender 16 __builtin_offsetof(struct __C(snd_seq_event), data.connect.sender)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender_client 16 __builtin_offsetof(struct __C(snd_seq_event), data.connect.sender.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender_port 17 __builtin_offsetof(struct __C(snd_seq_event), data.connect.sender.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control 16 __builtin_offsetof(struct __C(snd_seq_event), data.control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_channel 16 __builtin_offsetof(struct __C(snd_seq_event), data.control.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_param 20 __builtin_offsetof(struct __C(snd_seq_event), data.control.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused1 17 __builtin_offsetof(struct __C(snd_seq_event), data.control.unused1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused2 18 __builtin_offsetof(struct __C(snd_seq_event), data.control.unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused3 19 __builtin_offsetof(struct __C(snd_seq_event), data.control.unused3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_value 24 __builtin_offsetof(struct __C(snd_seq_event), data.control.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext 16 __builtin_offsetof(struct __C(snd_seq_event), data.ext)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext_len 16 __builtin_offsetof(struct __C(snd_seq_event), data.ext.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext_ptr 20 __builtin_offsetof(struct __C(snd_seq_event), data.ext.ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note 16 __builtin_offsetof(struct __C(snd_seq_event), data.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_channel 16 __builtin_offsetof(struct __C(snd_seq_event), data.note.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_duration 20 __builtin_offsetof(struct __C(snd_seq_event), data.note.duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_note 17 __builtin_offsetof(struct __C(snd_seq_event), data.note.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_off_velocity 19 __builtin_offsetof(struct __C(snd_seq_event), data.note.off_velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_velocity 18 __builtin_offsetof(struct __C(snd_seq_event), data.note.velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue 16 __builtin_offsetof(struct __C(snd_seq_event), data.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_pad 17 __builtin_offsetof(struct __C(snd_seq_event), data.queue.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_d32 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.d32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_d8 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.d8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_position 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.position)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.skew)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew_base 24 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.skew.base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew_value 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.skew.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_tick 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time_tv_nsec 24 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time_tv_sec 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_value 20 __builtin_offsetof(struct __C(snd_seq_event), data.queue.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_queue 16 __builtin_offsetof(struct __C(snd_seq_event), data.queue.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote 16 __builtin_offsetof(struct __C(snd_seq_event), data.quote)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_event 20 __builtin_offsetof(struct __C(snd_seq_event), data.quote.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin 16 __builtin_offsetof(struct __C(snd_seq_event), data.quote.origin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin_client 16 __builtin_offsetof(struct __C(snd_seq_event), data.quote.origin.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin_port 17 __builtin_offsetof(struct __C(snd_seq_event), data.quote.origin.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_value 18 __builtin_offsetof(struct __C(snd_seq_event), data.quote.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw32 16 __builtin_offsetof(struct __C(snd_seq_event), data.raw32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw32_d 16 __builtin_offsetof(struct __C(snd_seq_event), data.raw32.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw8 16 __builtin_offsetof(struct __C(snd_seq_event), data.raw8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw8_d 16 __builtin_offsetof(struct __C(snd_seq_event), data.raw8.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result 16 __builtin_offsetof(struct __C(snd_seq_event), data.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result_event 16 __builtin_offsetof(struct __C(snd_seq_event), data.result.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result_result 20 __builtin_offsetof(struct __C(snd_seq_event), data.result.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time 16 __builtin_offsetof(struct __C(snd_seq_event), data.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_tick 16 __builtin_offsetof(struct __C(snd_seq_event), data.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time 16 __builtin_offsetof(struct __C(snd_seq_event), data.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time_tv_nsec 20 __builtin_offsetof(struct __C(snd_seq_event), data.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time_tv_sec 16 __builtin_offsetof(struct __C(snd_seq_event), data.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify 16 __builtin_offsetof(struct __C(snd_seq_event), data.ump_notify)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify_block 17 __builtin_offsetof(struct __C(snd_seq_event), data.ump_notify.block)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify_client 16 __builtin_offsetof(struct __C(snd_seq_event), data.ump_notify.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_dest 14 __builtin_offsetof(struct __C(snd_seq_event), dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_dest_client 14 __builtin_offsetof(struct __C(snd_seq_event), dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_dest_port 15 __builtin_offsetof(struct __C(snd_seq_event), dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_flags 1 __builtin_offsetof(struct __C(snd_seq_event), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_queue 3 __builtin_offsetof(struct __C(snd_seq_event), queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_source 12 __builtin_offsetof(struct __C(snd_seq_event), source)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_source_client 12 __builtin_offsetof(struct __C(snd_seq_event), source.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_source_port 13 __builtin_offsetof(struct __C(snd_seq_event), source.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_tag 2 __builtin_offsetof(struct __C(snd_seq_event), tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_time 4 __builtin_offsetof(struct __C(snd_seq_event), time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_time_tick 4 __builtin_offsetof(struct __C(snd_seq_event), time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_time_time 4 __builtin_offsetof(struct __C(snd_seq_event), time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_time_time_tv_nsec 8 __builtin_offsetof(struct __C(snd_seq_event), time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_time_time_tv_sec 4 __builtin_offsetof(struct __C(snd_seq_event), time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_type 0 __builtin_offsetof(struct __C(snd_seq_event), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_event_bounce 32 sizeof(struct __C(snd_seq_event_bounce))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_event_bounce 4 __alignof(struct __C(snd_seq_event_bounce))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_err 0 __builtin_offsetof(struct __C(snd_seq_event_bounce), err)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event 4 __builtin_offsetof(struct __C(snd_seq_event_bounce), event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_addr 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_addr_client 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.addr.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_addr_port 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.addr.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_dest 22 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_dest_client 22 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_dest_port 23 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_sender 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.sender)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_sender_client 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.sender.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_connect_sender_port 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.connect.sender.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_channel 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_param 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_unused1 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.unused1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_unused2 22 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_unused3 23 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.unused3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_control_value 28 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.control.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ext 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ext)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ext_len 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ext.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ext_ptr 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ext.ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note_channel 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note_duration 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note.duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note_note 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note_off_velocity 23 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note.off_velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_note_velocity 22 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.note.velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_pad 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_d32 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.d32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_d8 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.d8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_position 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.position)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_skew 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.skew)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_skew_base 28 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.skew.base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_skew_value 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.skew.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_time 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_time_tick 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_time_time 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_time_time_tv_nsec 28 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_time_time_tv_sec 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_param_value 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_queue_queue 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.queue.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote_event 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote_origin 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote.origin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote_origin_client 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote.origin.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote_origin_port 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote.origin.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_quote_value 22 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.quote.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_raw32 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.raw32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_raw32_d 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.raw32.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_raw8 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.raw8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_raw8_d 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.raw8.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_result 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_result_event 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.result.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_result_result 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.result.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_time 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_time_tick 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_time_time 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_time_time_tv_nsec 24 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_time_time_tv_sec 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ump_notify 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ump_notify)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ump_notify_block 21 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ump_notify.block)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_data_ump_notify_client 20 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.data.ump_notify.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_dest 18 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_dest_client 18 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_dest_port 19 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_flags 5 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_queue 7 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_source 16 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.source)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_source_client 16 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.source.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_source_port 17 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.source.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_tag 6 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_time 8 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_time_tick 8 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_time_time 8 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_time_time_tv_nsec 12 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_time_time_tv_sec 8 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_bounce_event_type 4 __builtin_offsetof(struct __C(snd_seq_event_bounce), event.type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_port_info 168 sizeof(struct __C(snd_seq_port_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_port_info 8 __alignof(struct __C(snd_seq_port_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_addr 0 __builtin_offsetof(struct __C(snd_seq_port_info), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_addr_client 0 __builtin_offsetof(struct __C(snd_seq_port_info), addr.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_addr_port 1 __builtin_offsetof(struct __C(snd_seq_port_info), addr.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_capability 68 __builtin_offsetof(struct __C(snd_seq_port_info), capability)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_direction 109 __builtin_offsetof(struct __C(snd_seq_port_info), direction)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_flags 104 __builtin_offsetof(struct __C(snd_seq_port_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_kernel 96 __builtin_offsetof(struct __C(snd_seq_port_info), kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_midi_channels 76 __builtin_offsetof(struct __C(snd_seq_port_info), midi_channels)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_midi_voices 80 __builtin_offsetof(struct __C(snd_seq_port_info), midi_voices)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_name 2 __builtin_offsetof(struct __C(snd_seq_port_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_read_use 88 __builtin_offsetof(struct __C(snd_seq_port_info), read_use)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_reserved 111 __builtin_offsetof(struct __C(snd_seq_port_info), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_synth_voices 84 __builtin_offsetof(struct __C(snd_seq_port_info), synth_voices)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_time_queue 108 __builtin_offsetof(struct __C(snd_seq_port_info), time_queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_type 72 __builtin_offsetof(struct __C(snd_seq_port_info), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_ump_group 110 __builtin_offsetof(struct __C(snd_seq_port_info), ump_group)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_port_info_write_use 92 __builtin_offsetof(struct __C(snd_seq_port_info), write_use)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_seq_ump_event 32 sizeof(struct __C(snd_seq_ump_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_seq_ump_event 4 __alignof(struct __C(snd_seq_ump_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_addr 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_addr_client 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.addr.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_addr_port 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.addr.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_dest 18 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_dest_client 18 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_dest_port 19 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_sender 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.sender)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_sender_client 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.sender.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_connect_sender_port 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.connect.sender.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_channel 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_param 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_unused1 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.unused1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_unused2 18 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_unused3 19 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.unused3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_control_value 24 __builtin_offsetof(struct __C(snd_seq_ump_event), data.control.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ext 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ext)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ext_len 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ext.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ext_ptr 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ext.ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note_channel 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note_duration 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note.duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note_note 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note_off_velocity 19 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note.off_velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_note_velocity 18 __builtin_offsetof(struct __C(snd_seq_ump_event), data.note.velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_pad 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_d32 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.d32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_d8 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.d8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_position 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.position)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_skew 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.skew)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_skew_base 24 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.skew.base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_skew_value 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.skew.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_time 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_time_tick 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_time_time 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_time_time_tv_nsec 24 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_time_time_tv_sec 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_param_value 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_queue_queue 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.queue.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote_event 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote_origin 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote.origin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote_origin_client 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote.origin.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote_origin_port 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote.origin.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_quote_value 18 __builtin_offsetof(struct __C(snd_seq_ump_event), data.quote.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_raw32 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.raw32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_raw32_d 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.raw32.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_raw8 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.raw8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_raw8_d 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.raw8.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_result 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_result_event 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.result.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_result_result 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.result.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_time 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_time_tick 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_time_time 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_time_time_tv_nsec 20 __builtin_offsetof(struct __C(snd_seq_ump_event), data.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_time_time_tv_sec 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ump_notify 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ump_notify)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ump_notify_block 17 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ump_notify.block)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_data_ump_notify_client 16 __builtin_offsetof(struct __C(snd_seq_ump_event), data.ump_notify.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_dest 14 __builtin_offsetof(struct __C(snd_seq_ump_event), dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_dest_client 14 __builtin_offsetof(struct __C(snd_seq_ump_event), dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_dest_port 15 __builtin_offsetof(struct __C(snd_seq_ump_event), dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_flags 1 __builtin_offsetof(struct __C(snd_seq_ump_event), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_queue 3 __builtin_offsetof(struct __C(snd_seq_ump_event), queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_source 12 __builtin_offsetof(struct __C(snd_seq_ump_event), source)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_source_client 12 __builtin_offsetof(struct __C(snd_seq_ump_event), source.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_source_port 13 __builtin_offsetof(struct __C(snd_seq_ump_event), source.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_tag 2 __builtin_offsetof(struct __C(snd_seq_ump_event), tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_time 4 __builtin_offsetof(struct __C(snd_seq_ump_event), time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_time_tick 4 __builtin_offsetof(struct __C(snd_seq_ump_event), time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_time_time 4 __builtin_offsetof(struct __C(snd_seq_ump_event), time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_time_time_tv_nsec 8 __builtin_offsetof(struct __C(snd_seq_ump_event), time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_time_time_tv_sec 4 __builtin_offsetof(struct __C(snd_seq_ump_event), time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_type 0 __builtin_offsetof(struct __C(snd_seq_ump_event), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_ump_event_ump 16 __builtin_offsetof(struct __C(snd_seq_ump_event), ump)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_xferi 24 sizeof(struct __C(snd_xferi))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_xferi 8 __alignof(struct __C(snd_xferi))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xferi_buf 8 __builtin_offsetof(struct __C(snd_xferi), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xferi_frames 16 __builtin_offsetof(struct __C(snd_xferi), frames)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xferi_result 0 __builtin_offsetof(struct __C(snd_xferi), result)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_snd_xfern 24 sizeof(struct __C(snd_xfern))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_snd_xfern 8 __alignof(struct __C(snd_xfern))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xfern_bufs 8 __builtin_offsetof(struct __C(snd_xfern), bufs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xfern_frames 16 __builtin_offsetof(struct __C(snd_xfern), frames)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_xfern_result 0 __builtin_offsetof(struct __C(snd_xfern), result)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sock_fprog 16 sizeof(struct __C(sock_fprog))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sock_fprog 8 __alignof(struct __C(sock_fprog))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sock_fprog_filter 8 __builtin_offsetof(struct __C(sock_fprog), filter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sock_fprog_len 0 __builtin_offsetof(struct __C(sock_fprog), len)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_in 16 sizeof(struct __C(sockaddr_in))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_in 4 __alignof(struct __C(sockaddr_in))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_in___pad 8 __builtin_offsetof(struct __C(sockaddr_in), __pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_in_sin_addr 4 __builtin_offsetof(struct __C(sockaddr_in), sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_in_sin_addr_s_addr 4 __builtin_offsetof(struct __C(sockaddr_in), sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_in_sin_family 0 __builtin_offsetof(struct __C(sockaddr_in), sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_in_sin_port 2 __builtin_offsetof(struct __C(sockaddr_in), sin_port)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_l2tpip 16 sizeof(struct __C(sockaddr_l2tpip))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_l2tpip 4 __alignof(struct __C(sockaddr_l2tpip))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip___pad 12 __builtin_offsetof(struct __C(sockaddr_l2tpip), __pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip_l2tp_addr 4 __builtin_offsetof(struct __C(sockaddr_l2tpip), l2tp_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip_l2tp_addr_s_addr 4 __builtin_offsetof(struct __C(sockaddr_l2tpip), l2tp_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip_l2tp_conn_id 8 __builtin_offsetof(struct __C(sockaddr_l2tpip), l2tp_conn_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip_l2tp_family 0 __builtin_offsetof(struct __C(sockaddr_l2tpip), l2tp_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_l2tpip_l2tp_unused 2 __builtin_offsetof(struct __C(sockaddr_l2tpip), l2tp_unused)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_pn 16 sizeof(struct __C(sockaddr_pn))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_pn 1 __alignof(struct __C(sockaddr_pn))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pn_spn_dev 3 __builtin_offsetof(struct __C(sockaddr_pn), spn_dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pn_spn_family 0 __builtin_offsetof(struct __C(sockaddr_pn), spn_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pn_spn_obj 2 __builtin_offsetof(struct __C(sockaddr_pn), spn_obj)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pn_spn_resource 4 __builtin_offsetof(struct __C(sockaddr_pn), spn_resource)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pn_spn_zero 5 __builtin_offsetof(struct __C(sockaddr_pn), spn_zero)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_pppol2tp 38 sizeof(struct __C(sockaddr_pppol2tp))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_pppol2tp 1 __alignof(struct __C(sockaddr_pppol2tp))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp 6 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr 14 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr___pad 22 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr_sin_addr 18 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr_sin_addr_s_addr 18 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr_sin_family 14 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_addr_sin_port 16 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.addr.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_d_session 36 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.d_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_d_tunnel 34 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.d_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_fd 10 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_pid 6 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_s_session 32 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.s_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_pppol2tp_s_tunnel 30 __builtin_offsetof(struct __C(sockaddr_pppol2tp), pppol2tp.s_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_sa_family 0 __builtin_offsetof(struct __C(sockaddr_pppol2tp), sa_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tp_sa_protocol 2 __builtin_offsetof(struct __C(sockaddr_pppol2tp), sa_protocol)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_pppol2tpv3 46 sizeof(struct __C(sockaddr_pppol2tpv3))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_pppol2tpv3 1 __alignof(struct __C(sockaddr_pppol2tpv3))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp 6 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr 14 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr___pad 22 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr_sin_addr 18 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr_sin_addr_s_addr 18 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr_sin_family 14 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_addr_sin_port 16 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.addr.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_d_session 42 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.d_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_d_tunnel 38 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.d_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_fd 10 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_pid 6 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_s_session 34 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.s_session)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_pppol2tp_s_tunnel 30 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), pppol2tp.s_tunnel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_sa_family 0 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), sa_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_pppol2tpv3_sa_protocol 2 __builtin_offsetof(struct __C(sockaddr_pppol2tpv3), sa_protocol)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_rxrpc 36 sizeof(struct __C(sockaddr_rxrpc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_rxrpc 4 __alignof(struct __C(sockaddr_rxrpc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_srx_family 0 __builtin_offsetof(struct __C(sockaddr_rxrpc), srx_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_srx_service 2 __builtin_offsetof(struct __C(sockaddr_rxrpc), srx_service)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_family 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin___pad 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin.__pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin_sin_addr 12 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin.sin_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin_sin_addr_s_addr 12 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin.sin_addr.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin_sin_family 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin.sin_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin_sin_port 10 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin.sin_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_addr 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_addr_in6_u 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_addr.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_addr_in6_u_u6_addr16 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_addr.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_addr_in6_u_u6_addr32 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_addr.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_addr_in6_u_u6_addr8 16 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_addr.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_family 8 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_flowinfo 12 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_flowinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_port 10 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_sin6_sin6_scope_id 32 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport.sin6.sin6_scope_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_len 6 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_rxrpc_transport_type 4 __builtin_offsetof(struct __C(sockaddr_rxrpc), transport_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sockaddr_vm 16 sizeof(struct __C(sockaddr_vm))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sockaddr_vm 4 __alignof(struct __C(sockaddr_vm))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_cid 8 __builtin_offsetof(struct __C(sockaddr_vm), svm_cid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_family 0 __builtin_offsetof(struct __C(sockaddr_vm), svm_family)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_flags 12 __builtin_offsetof(struct __C(sockaddr_vm), svm_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_port 4 __builtin_offsetof(struct __C(sockaddr_vm), svm_port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_reserved1 2 __builtin_offsetof(struct __C(sockaddr_vm), svm_reserved1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sockaddr_vm_svm_zero 13 __builtin_offsetof(struct __C(sockaddr_vm), svm_zero)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_spi_ioc_transfer 32 sizeof(struct __C(spi_ioc_transfer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_spi_ioc_transfer 8 __alignof(struct __C(spi_ioc_transfer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_bits_per_word 26 __builtin_offsetof(struct __C(spi_ioc_transfer), bits_per_word)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_cs_change 27 __builtin_offsetof(struct __C(spi_ioc_transfer), cs_change)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_delay_usecs 24 __builtin_offsetof(struct __C(spi_ioc_transfer), delay_usecs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_len 16 __builtin_offsetof(struct __C(spi_ioc_transfer), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_pad 31 __builtin_offsetof(struct __C(spi_ioc_transfer), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_rx_buf 8 __builtin_offsetof(struct __C(spi_ioc_transfer), rx_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_rx_nbits 29 __builtin_offsetof(struct __C(spi_ioc_transfer), rx_nbits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_speed_hz 20 __builtin_offsetof(struct __C(spi_ioc_transfer), speed_hz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_tx_buf 0 __builtin_offsetof(struct __C(spi_ioc_transfer), tx_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_tx_nbits 28 __builtin_offsetof(struct __C(spi_ioc_transfer), tx_nbits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_spi_ioc_transfer_word_delay_usecs 30 __builtin_offsetof(struct __C(spi_ioc_transfer), word_delay_usecs)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_sync_file_info 56 sizeof(struct __C(sync_file_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_sync_file_info 8 __alignof(struct __C(sync_file_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_flags 36 __builtin_offsetof(struct __C(sync_file_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_name 0 __builtin_offsetof(struct __C(sync_file_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_num_fences 40 __builtin_offsetof(struct __C(sync_file_info), num_fences)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_pad 44 __builtin_offsetof(struct __C(sync_file_info), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_status 32 __builtin_offsetof(struct __C(sync_file_info), status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sync_file_info_sync_fence_info 48 __builtin_offsetof(struct __C(sync_file_info), sync_fence_info)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_tcp_zerocopy_receive 64 sizeof(struct __C(tcp_zerocopy_receive))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_tcp_zerocopy_receive 8 __alignof(struct __C(tcp_zerocopy_receive))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_address 0 __builtin_offsetof(struct __C(tcp_zerocopy_receive), address)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_copybuf_address 24 __builtin_offsetof(struct __C(tcp_zerocopy_receive), copybuf_address)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_copybuf_len 32 __builtin_offsetof(struct __C(tcp_zerocopy_receive), copybuf_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_err 20 __builtin_offsetof(struct __C(tcp_zerocopy_receive), err)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_flags 36 __builtin_offsetof(struct __C(tcp_zerocopy_receive), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_inq 16 __builtin_offsetof(struct __C(tcp_zerocopy_receive), inq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_length 8 __builtin_offsetof(struct __C(tcp_zerocopy_receive), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_msg_control 40 __builtin_offsetof(struct __C(tcp_zerocopy_receive), msg_control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_msg_controllen 48 __builtin_offsetof(struct __C(tcp_zerocopy_receive), msg_controllen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_msg_flags 56 __builtin_offsetof(struct __C(tcp_zerocopy_receive), msg_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_recv_skip_hint 12 __builtin_offsetof(struct __C(tcp_zerocopy_receive), recv_skip_hint)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tcp_zerocopy_receive_reserved 60 __builtin_offsetof(struct __C(tcp_zerocopy_receive), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_tee_ioctl_buf_data 16 sizeof(struct __C(tee_ioctl_buf_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_tee_ioctl_buf_data 8 __alignof(struct __C(tee_ioctl_buf_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_buf_data_buf_len 8 __builtin_offsetof(struct __C(tee_ioctl_buf_data), buf_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_buf_data_buf_ptr 0 __builtin_offsetof(struct __C(tee_ioctl_buf_data), buf_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_tee_ioctl_shm_register_data 24 sizeof(struct __C(tee_ioctl_shm_register_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_tee_ioctl_shm_register_data 8 __alignof(struct __C(tee_ioctl_shm_register_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_shm_register_data_addr 0 __builtin_offsetof(struct __C(tee_ioctl_shm_register_data), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_shm_register_data_flags 16 __builtin_offsetof(struct __C(tee_ioctl_shm_register_data), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_shm_register_data_id 20 __builtin_offsetof(struct __C(tee_ioctl_shm_register_data), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tee_ioctl_shm_register_data_length 8 __builtin_offsetof(struct __C(tee_ioctl_shm_register_data), length)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_tlv_list_desc 16 sizeof(struct __C(tlv_list_desc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_tlv_list_desc 8 __alignof(struct __C(tlv_list_desc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tlv_list_desc_tlv_ptr 0 __builtin_offsetof(struct __C(tlv_list_desc), tlv_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_tlv_list_desc_tlv_space 8 __builtin_offsetof(struct __C(tlv_list_desc), tlv_space)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ublksrv_ctrl_cmd 32 sizeof(struct __C(ublksrv_ctrl_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ublksrv_ctrl_cmd 8 __alignof(struct __C(ublksrv_ctrl_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_addr 8 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_data 16 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_dev_id 0 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), dev_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_dev_path_len 24 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), dev_path_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_len 6 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_pad 26 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_queue_id 4 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_ctrl_cmd_reserved 28 __builtin_offsetof(struct __C(ublksrv_ctrl_cmd), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ublksrv_io_cmd 16 sizeof(struct __C(ublksrv_io_cmd))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ublksrv_io_cmd 8 __alignof(struct __C(ublksrv_io_cmd))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_cmd_addr 8 __builtin_offsetof(struct __C(ublksrv_io_cmd), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_cmd_q_id 0 __builtin_offsetof(struct __C(ublksrv_io_cmd), q_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_cmd_result 4 __builtin_offsetof(struct __C(ublksrv_io_cmd), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_cmd_tag 2 __builtin_offsetof(struct __C(ublksrv_io_cmd), tag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_cmd_zone_append_lba 8 __builtin_offsetof(struct __C(ublksrv_io_cmd), zone_append_lba)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ublksrv_io_desc 24 sizeof(struct __C(ublksrv_io_desc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ublksrv_io_desc 8 __alignof(struct __C(ublksrv_io_desc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_desc_addr 16 __builtin_offsetof(struct __C(ublksrv_io_desc), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_desc_nr_sectors 4 __builtin_offsetof(struct __C(ublksrv_io_desc), nr_sectors)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_desc_nr_zones 4 __builtin_offsetof(struct __C(ublksrv_io_desc), nr_zones)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_desc_op_flags 0 __builtin_offsetof(struct __C(ublksrv_io_desc), op_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ublksrv_io_desc_start_sector 8 __builtin_offsetof(struct __C(ublksrv_io_desc), start_sector)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_ucontext 960 sizeof(struct __C(ucontext))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_ucontext 16 __alignof(struct __C(ucontext))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext___unused 48 __builtin_offsetof(struct __C(ucontext), __unused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_flags 0 __builtin_offsetof(struct __C(ucontext), uc_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_link 8 __builtin_offsetof(struct __C(ucontext), uc_link)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext 176 __builtin_offsetof(struct __C(ucontext), uc_mcontext)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc___padding 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc.__padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc_hdr 952 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc.hdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc_hdr_magic 952 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc.hdr.magic)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc_hdr_size 956 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc.hdr.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_extdesc_reserved 948 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_extdesc.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_d 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_d_f 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.d.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_d_fcsr 688 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.d.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_f 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_f_f 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.f.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_f_fcsr 560 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.f.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_q 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.q)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_q_f 432 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.q.f)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_q_fcsr 944 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.q.fcsr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_fpregs_q_reserved 948 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_fpregs.q.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs 176 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a0 256 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a1 264 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a2 272 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a3 280 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a4 288 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a5 296 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a6 304 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_a7 312 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.a7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_gp 200 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.gp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_pc 176 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.pc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_ra 184 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.ra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s0 240 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s1 248 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s10 384 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s11 392 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s2 320 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s3 328 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s4 336 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s5 344 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s6 352 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s7 360 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s8 368 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_s9 376 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.s9)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_sp 192 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.sp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t0 216 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t1 224 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t2 232 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t3 400 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t4 408 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t5 416 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_t6 424 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.t6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_mcontext_sc_regs_tp 208 __builtin_offsetof(struct __C(ucontext), uc_mcontext.sc_regs.tp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_sigmask 40 __builtin_offsetof(struct __C(ucontext), uc_sigmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_stack 16 __builtin_offsetof(struct __C(ucontext), uc_stack)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_stack_ss_flags 24 __builtin_offsetof(struct __C(ucontext), uc_stack.ss_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_stack_ss_size 32 __builtin_offsetof(struct __C(ucontext), uc_stack.ss_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_ucontext_uc_stack_ss_sp 16 __builtin_offsetof(struct __C(ucontext), uc_stack.ss_sp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_uinput_ff_upload 104 sizeof(struct __C(uinput_ff_upload))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_uinput_ff_upload 8 __alignof(struct __C(uinput_ff_upload))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect 8 __builtin_offsetof(struct __C(uinput_ff_upload), effect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_direction 12 __builtin_offsetof(struct __C(uinput_ff_upload), effect.direction)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_id 10 __builtin_offsetof(struct __C(uinput_ff_upload), effect.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_replay 18 __builtin_offsetof(struct __C(uinput_ff_upload), effect.replay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_replay_delay 20 __builtin_offsetof(struct __C(uinput_ff_upload), effect.replay.delay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_replay_length 18 __builtin_offsetof(struct __C(uinput_ff_upload), effect.replay.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_trigger 14 __builtin_offsetof(struct __C(uinput_ff_upload), effect.trigger)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_trigger_button 14 __builtin_offsetof(struct __C(uinput_ff_upload), effect.trigger.button)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_trigger_interval 16 __builtin_offsetof(struct __C(uinput_ff_upload), effect.trigger.interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_type 8 __builtin_offsetof(struct __C(uinput_ff_upload), effect.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__center 34 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].center)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__deadband 32 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].deadband)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__left_coeff 30 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].left_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__left_saturation 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].left_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__right_coeff 28 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].right_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_condition_0__right_saturation 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.condition[0].right_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_envelope 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_envelope_attack_length 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_envelope_attack_level 28 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_envelope_fade_length 30 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_envelope_fade_level 32 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_constant_level 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.constant.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_custom_data 48 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.custom_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_custom_len 44 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.custom_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_envelope 34 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_envelope_attack_length 34 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_envelope_attack_level 36 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_envelope_fade_length 38 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_envelope_fade_level 40 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_magnitude 28 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_offset 30 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_period 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.period)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_phase 32 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.phase)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_periodic_waveform 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.periodic.waveform)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_end_level 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.end_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_envelope 28 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_envelope_attack_length 28 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_envelope_attack_level 30 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_envelope_fade_length 32 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_envelope_fade_level 34 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_ramp_start_level 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.ramp.start_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_rumble 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.rumble)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_rumble_strong_magnitude 24 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.rumble.strong_magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_effect_u_rumble_weak_magnitude 26 __builtin_offsetof(struct __C(uinput_ff_upload), effect.u.rumble.weak_magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old 56 __builtin_offsetof(struct __C(uinput_ff_upload), old)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_direction 60 __builtin_offsetof(struct __C(uinput_ff_upload), old.direction)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_id 58 __builtin_offsetof(struct __C(uinput_ff_upload), old.id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_replay 66 __builtin_offsetof(struct __C(uinput_ff_upload), old.replay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_replay_delay 68 __builtin_offsetof(struct __C(uinput_ff_upload), old.replay.delay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_replay_length 66 __builtin_offsetof(struct __C(uinput_ff_upload), old.replay.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_trigger 62 __builtin_offsetof(struct __C(uinput_ff_upload), old.trigger)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_trigger_button 62 __builtin_offsetof(struct __C(uinput_ff_upload), old.trigger.button)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_trigger_interval 64 __builtin_offsetof(struct __C(uinput_ff_upload), old.trigger.interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_type 56 __builtin_offsetof(struct __C(uinput_ff_upload), old.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__center 82 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].center)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__deadband 80 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].deadband)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__left_coeff 78 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].left_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__left_saturation 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].left_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__right_coeff 76 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].right_coeff)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_condition_0__right_saturation 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.condition[0].right_saturation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_envelope 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_envelope_attack_length 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_envelope_attack_level 76 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_envelope_fade_length 78 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_envelope_fade_level 80 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_constant_level 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.constant.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_custom_data 96 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.custom_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_custom_len 92 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.custom_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_envelope 82 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_envelope_attack_length 82 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_envelope_attack_level 84 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_envelope_fade_length 86 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_envelope_fade_level 88 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_magnitude 76 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_offset 78 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_period 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.period)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_phase 80 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.phase)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_periodic_waveform 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.periodic.waveform)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_end_level 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.end_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_envelope 76 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.envelope)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_envelope_attack_length 76 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.envelope.attack_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_envelope_attack_level 78 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.envelope.attack_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_envelope_fade_length 80 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.envelope.fade_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_envelope_fade_level 82 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.envelope.fade_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_ramp_start_level 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.ramp.start_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_rumble 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.rumble)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_rumble_strong_magnitude 72 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.rumble.strong_magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_old_u_rumble_weak_magnitude 74 __builtin_offsetof(struct __C(uinput_ff_upload), old.u.rumble.weak_magnitude)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_request_id 0 __builtin_offsetof(struct __C(uinput_ff_upload), request_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uinput_ff_upload_retval 4 __builtin_offsetof(struct __C(uinput_ff_upload), retval)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_unimapdesc 16 sizeof(struct __C(unimapdesc))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_unimapdesc 8 __alignof(struct __C(unimapdesc))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_unimapdesc_entries 8 __builtin_offsetof(struct __C(unimapdesc), entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_unimapdesc_entry_ct 0 __builtin_offsetof(struct __C(unimapdesc), entry_ct)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbdevfs_bulktransfer 24 sizeof(struct __C(usbdevfs_bulktransfer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbdevfs_bulktransfer 8 __alignof(struct __C(usbdevfs_bulktransfer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_bulktransfer_data 16 __builtin_offsetof(struct __C(usbdevfs_bulktransfer), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_bulktransfer_ep 0 __builtin_offsetof(struct __C(usbdevfs_bulktransfer), ep)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_bulktransfer_len 4 __builtin_offsetof(struct __C(usbdevfs_bulktransfer), len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_bulktransfer_timeout 8 __builtin_offsetof(struct __C(usbdevfs_bulktransfer), timeout)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbdevfs_ctrltransfer 24 sizeof(struct __C(usbdevfs_ctrltransfer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbdevfs_ctrltransfer 8 __alignof(struct __C(usbdevfs_ctrltransfer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_bRequest 1 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), bRequest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_bRequestType 0 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), bRequestType)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_data 16 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_timeout 8 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_wIndex 4 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), wIndex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_wLength 6 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), wLength)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ctrltransfer_wValue 2 __builtin_offsetof(struct __C(usbdevfs_ctrltransfer), wValue)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbdevfs_disconnectsignal 16 sizeof(struct __C(usbdevfs_disconnectsignal))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbdevfs_disconnectsignal 8 __alignof(struct __C(usbdevfs_disconnectsignal))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_disconnectsignal_context 8 __builtin_offsetof(struct __C(usbdevfs_disconnectsignal), context)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_disconnectsignal_signr 0 __builtin_offsetof(struct __C(usbdevfs_disconnectsignal), signr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbdevfs_ioctl 16 sizeof(struct __C(usbdevfs_ioctl))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbdevfs_ioctl 8 __alignof(struct __C(usbdevfs_ioctl))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ioctl_data 8 __builtin_offsetof(struct __C(usbdevfs_ioctl), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ioctl_ifno 0 __builtin_offsetof(struct __C(usbdevfs_ioctl), ifno)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_ioctl_ioctl_code 4 __builtin_offsetof(struct __C(usbdevfs_ioctl), ioctl_code)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbdevfs_urb 56 sizeof(struct __C(usbdevfs_urb))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbdevfs_urb 8 __alignof(struct __C(usbdevfs_urb))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_actual_length 28 __builtin_offsetof(struct __C(usbdevfs_urb), actual_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_buffer 16 __builtin_offsetof(struct __C(usbdevfs_urb), buffer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_buffer_length 24 __builtin_offsetof(struct __C(usbdevfs_urb), buffer_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_endpoint 1 __builtin_offsetof(struct __C(usbdevfs_urb), endpoint)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_error_count 40 __builtin_offsetof(struct __C(usbdevfs_urb), error_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_flags 8 __builtin_offsetof(struct __C(usbdevfs_urb), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_iso_frame_desc 56 __builtin_offsetof(struct __C(usbdevfs_urb), iso_frame_desc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_iso_frame_desc_0__actual_length 60 __builtin_offsetof(struct __C(usbdevfs_urb), iso_frame_desc[0].actual_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_iso_frame_desc_0__length 56 __builtin_offsetof(struct __C(usbdevfs_urb), iso_frame_desc[0].length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_iso_frame_desc_0__status 64 __builtin_offsetof(struct __C(usbdevfs_urb), iso_frame_desc[0].status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_number_of_packets 36 __builtin_offsetof(struct __C(usbdevfs_urb), number_of_packets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_signr 44 __builtin_offsetof(struct __C(usbdevfs_urb), signr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_start_frame 32 __builtin_offsetof(struct __C(usbdevfs_urb), start_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_status 4 __builtin_offsetof(struct __C(usbdevfs_urb), status)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_stream_id 36 __builtin_offsetof(struct __C(usbdevfs_urb), stream_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_type 0 __builtin_offsetof(struct __C(usbdevfs_urb), type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbdevfs_urb_usercontext 48 __builtin_offsetof(struct __C(usbdevfs_urb), usercontext)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbtmc_ctrlrequest 16 sizeof(struct __C(usbtmc_ctrlrequest))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbtmc_ctrlrequest 1 __alignof(struct __C(usbtmc_ctrlrequest))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_data 8 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req 0 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req_bRequest 1 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req.bRequest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req_bRequestType 0 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req.bRequestType)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req_wIndex 4 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req.wIndex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req_wLength 6 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req.wLength)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_ctrlrequest_req_wValue 2 __builtin_offsetof(struct __C(usbtmc_ctrlrequest), req.wValue)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_usbtmc_message 20 sizeof(struct __C(usbtmc_message))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_usbtmc_message 1 __alignof(struct __C(usbtmc_message))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_message_flags 8 __builtin_offsetof(struct __C(usbtmc_message), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_message_message 12 __builtin_offsetof(struct __C(usbtmc_message), message)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_message_transfer_size 0 __builtin_offsetof(struct __C(usbtmc_message), transfer_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_usbtmc_message_transferred 4 __builtin_offsetof(struct __C(usbtmc_message), transferred)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_user_regs_struct 256 sizeof(struct __C(user_regs_struct))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_user_regs_struct 8 __alignof(struct __C(user_regs_struct))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a0 80 __builtin_offsetof(struct __C(user_regs_struct), a0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a1 88 __builtin_offsetof(struct __C(user_regs_struct), a1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a2 96 __builtin_offsetof(struct __C(user_regs_struct), a2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a3 104 __builtin_offsetof(struct __C(user_regs_struct), a3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a4 112 __builtin_offsetof(struct __C(user_regs_struct), a4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a5 120 __builtin_offsetof(struct __C(user_regs_struct), a5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a6 128 __builtin_offsetof(struct __C(user_regs_struct), a6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_a7 136 __builtin_offsetof(struct __C(user_regs_struct), a7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_gp 24 __builtin_offsetof(struct __C(user_regs_struct), gp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_pc 0 __builtin_offsetof(struct __C(user_regs_struct), pc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_ra 8 __builtin_offsetof(struct __C(user_regs_struct), ra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s0 64 __builtin_offsetof(struct __C(user_regs_struct), s0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s1 72 __builtin_offsetof(struct __C(user_regs_struct), s1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s10 208 __builtin_offsetof(struct __C(user_regs_struct), s10)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s11 216 __builtin_offsetof(struct __C(user_regs_struct), s11)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s2 144 __builtin_offsetof(struct __C(user_regs_struct), s2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s3 152 __builtin_offsetof(struct __C(user_regs_struct), s3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s4 160 __builtin_offsetof(struct __C(user_regs_struct), s4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s5 168 __builtin_offsetof(struct __C(user_regs_struct), s5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s6 176 __builtin_offsetof(struct __C(user_regs_struct), s6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s7 184 __builtin_offsetof(struct __C(user_regs_struct), s7)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s8 192 __builtin_offsetof(struct __C(user_regs_struct), s8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_s9 200 __builtin_offsetof(struct __C(user_regs_struct), s9)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_sp 16 __builtin_offsetof(struct __C(user_regs_struct), sp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t0 40 __builtin_offsetof(struct __C(user_regs_struct), t0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t1 48 __builtin_offsetof(struct __C(user_regs_struct), t1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t2 56 __builtin_offsetof(struct __C(user_regs_struct), t2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t3 224 __builtin_offsetof(struct __C(user_regs_struct), t3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t4 232 __builtin_offsetof(struct __C(user_regs_struct), t4)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t5 240 __builtin_offsetof(struct __C(user_regs_struct), t5)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_t6 248 __builtin_offsetof(struct __C(user_regs_struct), t6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_user_regs_struct_tp 32 __builtin_offsetof(struct __C(user_regs_struct), tp)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_uvc_xu_control_mapping 96 sizeof(struct __C(uvc_xu_control_mapping))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_uvc_xu_control_mapping 8 __alignof(struct __C(uvc_xu_control_mapping))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_data_type 60 __builtin_offsetof(struct __C(uvc_xu_control_mapping), data_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_entity 36 __builtin_offsetof(struct __C(uvc_xu_control_mapping), entity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_id 0 __builtin_offsetof(struct __C(uvc_xu_control_mapping), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_menu_count 72 __builtin_offsetof(struct __C(uvc_xu_control_mapping), menu_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_menu_info 64 __builtin_offsetof(struct __C(uvc_xu_control_mapping), menu_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_name 4 __builtin_offsetof(struct __C(uvc_xu_control_mapping), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_offset 54 __builtin_offsetof(struct __C(uvc_xu_control_mapping), offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_reserved 76 __builtin_offsetof(struct __C(uvc_xu_control_mapping), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_selector 52 __builtin_offsetof(struct __C(uvc_xu_control_mapping), selector)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_size 53 __builtin_offsetof(struct __C(uvc_xu_control_mapping), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_mapping_v4l2_type 56 __builtin_offsetof(struct __C(uvc_xu_control_mapping), v4l2_type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_uvc_xu_control_query 16 sizeof(struct __C(uvc_xu_control_query))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_uvc_xu_control_query 8 __alignof(struct __C(uvc_xu_control_query))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_query_data 8 __builtin_offsetof(struct __C(uvc_xu_control_query), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_query_query 2 __builtin_offsetof(struct __C(uvc_xu_control_query), query)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_query_selector 1 __builtin_offsetof(struct __C(uvc_xu_control_query), selector)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_query_size 4 __builtin_offsetof(struct __C(uvc_xu_control_query), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_uvc_xu_control_query_unit 0 __builtin_offsetof(struct __C(uvc_xu_control_query), unit)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_buffer 88 sizeof(struct __C(v4l2_buffer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_buffer 8 __alignof(struct __C(v4l2_buffer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_bytesused 8 __builtin_offsetof(struct __C(v4l2_buffer), bytesused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_field 16 __builtin_offsetof(struct __C(v4l2_buffer), field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_flags 12 __builtin_offsetof(struct __C(v4l2_buffer), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_index 0 __builtin_offsetof(struct __C(v4l2_buffer), index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_length 72 __builtin_offsetof(struct __C(v4l2_buffer), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_m 64 __builtin_offsetof(struct __C(v4l2_buffer), m)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_m_fd 64 __builtin_offsetof(struct __C(v4l2_buffer), m.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_m_offset 64 __builtin_offsetof(struct __C(v4l2_buffer), m.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_m_planes 64 __builtin_offsetof(struct __C(v4l2_buffer), m.planes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_m_userptr 64 __builtin_offsetof(struct __C(v4l2_buffer), m.userptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_memory 60 __builtin_offsetof(struct __C(v4l2_buffer), memory)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_request_fd 80 __builtin_offsetof(struct __C(v4l2_buffer), request_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_reserved 80 __builtin_offsetof(struct __C(v4l2_buffer), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_reserved2 76 __builtin_offsetof(struct __C(v4l2_buffer), reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_sequence 56 __builtin_offsetof(struct __C(v4l2_buffer), sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode 40 __builtin_offsetof(struct __C(v4l2_buffer), timecode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_flags 44 __builtin_offsetof(struct __C(v4l2_buffer), timecode.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_frames 48 __builtin_offsetof(struct __C(v4l2_buffer), timecode.frames)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_hours 51 __builtin_offsetof(struct __C(v4l2_buffer), timecode.hours)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_minutes 50 __builtin_offsetof(struct __C(v4l2_buffer), timecode.minutes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_seconds 49 __builtin_offsetof(struct __C(v4l2_buffer), timecode.seconds)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_type 40 __builtin_offsetof(struct __C(v4l2_buffer), timecode.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timecode_userbits 52 __builtin_offsetof(struct __C(v4l2_buffer), timecode.userbits)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timestamp 24 __builtin_offsetof(struct __C(v4l2_buffer), timestamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timestamp_tv_sec 24 __builtin_offsetof(struct __C(v4l2_buffer), timestamp.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_timestamp_tv_usec 32 __builtin_offsetof(struct __C(v4l2_buffer), timestamp.tv_usec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_buffer_type 4 __builtin_offsetof(struct __C(v4l2_buffer), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_clip 24 sizeof(struct __C(v4l2_clip))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_clip 8 __alignof(struct __C(v4l2_clip))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_c 0 __builtin_offsetof(struct __C(v4l2_clip), c)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_c_height 12 __builtin_offsetof(struct __C(v4l2_clip), c.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_c_left 0 __builtin_offsetof(struct __C(v4l2_clip), c.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_c_top 4 __builtin_offsetof(struct __C(v4l2_clip), c.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_c_width 8 __builtin_offsetof(struct __C(v4l2_clip), c.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_clip_next 16 __builtin_offsetof(struct __C(v4l2_clip), next)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_create_buffers 256 sizeof(struct __C(v4l2_create_buffers))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_create_buffers 8 __alignof(struct __C(v4l2_create_buffers))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_capabilities 224 __builtin_offsetof(struct __C(v4l2_create_buffers), capabilities)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_count 4 __builtin_offsetof(struct __C(v4l2_create_buffers), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_flags 228 __builtin_offsetof(struct __C(v4l2_create_buffers), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format 16 __builtin_offsetof(struct __C(v4l2_create_buffers), format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta_buffersize 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta.buffersize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta_bytesperline 40 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta.bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta_dataformat 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta.dataformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta_height 36 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_meta_width 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.meta.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_bytesperline 40 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_colorspace 48 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.colorspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_field 36 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_flags 56 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_height 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_hsv_enc 60 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.hsv_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_pixelformat 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_priv 52 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.priv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_quantization 64 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.quantization)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_sizeimage 44 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.sizeimage)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_width 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_xfer_func 68 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.xfer_func)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_ycbcr_enc 60 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix.ycbcr_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_colorspace 40 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.colorspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_field 36 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_flags 205 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_height 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_hsv_enc 206 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.hsv_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_num_planes 204 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.num_planes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_pixelformat 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_plane_fmt 44 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.plane_fmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_plane_fmt_0__bytesperline 48 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.plane_fmt[0].bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_plane_fmt_0__reserved 52 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.plane_fmt[0].reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_plane_fmt_0__sizeimage 44 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.plane_fmt[0].sizeimage)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_quantization 207 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.quantization)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_reserved 209 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_width 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_xfer_func 208 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.xfer_func)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_pix_mp_ycbcr_enc 206 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.pix_mp.ycbcr_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_raw_data 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.raw_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sdr 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sdr_buffersize 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sdr.buffersize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sdr_pixelformat 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sdr.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sdr_reserved 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sdr.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sliced 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sliced)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sliced_io_size 124 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sliced.io_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sliced_reserved 128 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sliced.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sliced_service_lines 26 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sliced.service_lines)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_sliced_service_set 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.sliced.service_set)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_count 48 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_flags 56 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_offset 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_reserved 60 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_sample_format 36 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.sample_format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_samples_per_line 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.samples_per_line)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_sampling_rate 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.sampling_rate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_vbi_start 40 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.vbi.start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_bitmap 64 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.bitmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_chromakey 44 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.chromakey)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_clipcount 56 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.clipcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_clips 48 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.clips)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_field 40 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_global_alpha 72 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.global_alpha)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_w 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.w)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_w_height 36 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.w.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_w_left 24 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.w.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_w_top 28 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.w.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_fmt_win_w_width 32 __builtin_offsetof(struct __C(v4l2_create_buffers), format.fmt.win.w.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_format_type 16 __builtin_offsetof(struct __C(v4l2_create_buffers), format.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_index 0 __builtin_offsetof(struct __C(v4l2_create_buffers), index)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_max_num_buffers 232 __builtin_offsetof(struct __C(v4l2_create_buffers), max_num_buffers)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_memory 8 __builtin_offsetof(struct __C(v4l2_create_buffers), memory)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_create_buffers_reserved 236 __builtin_offsetof(struct __C(v4l2_create_buffers), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_edid 40 sizeof(struct __C(v4l2_edid))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_edid 8 __alignof(struct __C(v4l2_edid))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_edid_blocks 8 __builtin_offsetof(struct __C(v4l2_edid), blocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_edid_edid 32 __builtin_offsetof(struct __C(v4l2_edid), edid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_edid_pad 0 __builtin_offsetof(struct __C(v4l2_edid), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_edid_reserved 12 __builtin_offsetof(struct __C(v4l2_edid), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_edid_start_block 4 __builtin_offsetof(struct __C(v4l2_edid), start_block)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_ext_control 20 sizeof(struct __C(v4l2_ext_control))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_ext_control 1 __alignof(struct __C(v4l2_ext_control))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_id 0 __builtin_offsetof(struct __C(v4l2_ext_control), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_area 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_area)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_av1_film_grain 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_av1_film_grain)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_av1_frame 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_av1_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_av1_sequence 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_av1_sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_av1_tile_group_entry 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_av1_tile_group_entry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_fwht_params 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_fwht_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_decode_params 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_decode_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_pps 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_pps)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_pred_weights 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_pred_weights)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_scaling_matrix 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_scaling_matrix)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_slice_params 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_slice_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_h264_sps 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_h264_sps)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hdr10_cll_info 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hdr10_cll_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hdr10_mastering_display 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hdr10_mastering_display)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hevc_decode_params 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hevc_decode_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hevc_pps 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hevc_pps)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hevc_scaling_matrix 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hevc_scaling_matrix)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hevc_slice_params 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hevc_slice_params)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_hevc_sps 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_hevc_sps)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_mpeg2_picture 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_mpeg2_picture)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_mpeg2_quantisation 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_mpeg2_quantisation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_mpeg2_sequence 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_mpeg2_sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_rect 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_rect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_s32 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_s32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_s64 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_s64)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_u16 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_u16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_u32 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_u32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_u8 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_u8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_vp8_frame 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_vp8_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_vp9_compressed_hdr_probs 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_vp9_compressed_hdr_probs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_p_vp9_frame 12 __builtin_offsetof(struct __C(v4l2_ext_control), p_vp9_frame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_ptr 12 __builtin_offsetof(struct __C(v4l2_ext_control), ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_reserved2 8 __builtin_offsetof(struct __C(v4l2_ext_control), reserved2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_size 4 __builtin_offsetof(struct __C(v4l2_ext_control), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_string 12 __builtin_offsetof(struct __C(v4l2_ext_control), string)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_value 12 __builtin_offsetof(struct __C(v4l2_ext_control), value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_control_value64 12 __builtin_offsetof(struct __C(v4l2_ext_control), value64)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_ext_controls 32 sizeof(struct __C(v4l2_ext_controls))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_ext_controls 8 __alignof(struct __C(v4l2_ext_controls))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_controls 24 __builtin_offsetof(struct __C(v4l2_ext_controls), controls)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_count 4 __builtin_offsetof(struct __C(v4l2_ext_controls), count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_error_idx 8 __builtin_offsetof(struct __C(v4l2_ext_controls), error_idx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_request_fd 12 __builtin_offsetof(struct __C(v4l2_ext_controls), request_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_reserved 16 __builtin_offsetof(struct __C(v4l2_ext_controls), reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_ext_controls_which 0 __builtin_offsetof(struct __C(v4l2_ext_controls), which)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_format 208 sizeof(struct __C(v4l2_format))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_format 8 __alignof(struct __C(v4l2_format))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt 8 __builtin_offsetof(struct __C(v4l2_format), fmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta 8 __builtin_offsetof(struct __C(v4l2_format), fmt.meta)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta_buffersize 12 __builtin_offsetof(struct __C(v4l2_format), fmt.meta.buffersize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta_bytesperline 24 __builtin_offsetof(struct __C(v4l2_format), fmt.meta.bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta_dataformat 8 __builtin_offsetof(struct __C(v4l2_format), fmt.meta.dataformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta_height 20 __builtin_offsetof(struct __C(v4l2_format), fmt.meta.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_meta_width 16 __builtin_offsetof(struct __C(v4l2_format), fmt.meta.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix 8 __builtin_offsetof(struct __C(v4l2_format), fmt.pix)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_bytesperline 24 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_colorspace 32 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.colorspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_field 20 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_flags 40 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_height 12 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_hsv_enc 44 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.hsv_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_pixelformat 16 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_priv 36 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.priv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_quantization 48 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.quantization)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_sizeimage 28 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.sizeimage)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_width 8 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_xfer_func 52 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.xfer_func)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_ycbcr_enc 44 __builtin_offsetof(struct __C(v4l2_format), fmt.pix.ycbcr_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp 8 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_colorspace 24 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.colorspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_field 20 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_flags 189 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_height 12 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_hsv_enc 190 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.hsv_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_num_planes 188 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.num_planes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_pixelformat 16 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_plane_fmt 28 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.plane_fmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_plane_fmt_0__bytesperline 32 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.plane_fmt[0].bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_plane_fmt_0__reserved 36 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.plane_fmt[0].reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_plane_fmt_0__sizeimage 28 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.plane_fmt[0].sizeimage)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_quantization 191 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.quantization)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_reserved 193 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_width 8 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_xfer_func 192 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.xfer_func)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_pix_mp_ycbcr_enc 190 __builtin_offsetof(struct __C(v4l2_format), fmt.pix_mp.ycbcr_enc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_raw_data 8 __builtin_offsetof(struct __C(v4l2_format), fmt.raw_data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sdr 8 __builtin_offsetof(struct __C(v4l2_format), fmt.sdr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sdr_buffersize 12 __builtin_offsetof(struct __C(v4l2_format), fmt.sdr.buffersize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sdr_pixelformat 8 __builtin_offsetof(struct __C(v4l2_format), fmt.sdr.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sdr_reserved 16 __builtin_offsetof(struct __C(v4l2_format), fmt.sdr.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sliced 8 __builtin_offsetof(struct __C(v4l2_format), fmt.sliced)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sliced_io_size 108 __builtin_offsetof(struct __C(v4l2_format), fmt.sliced.io_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sliced_reserved 112 __builtin_offsetof(struct __C(v4l2_format), fmt.sliced.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sliced_service_lines 10 __builtin_offsetof(struct __C(v4l2_format), fmt.sliced.service_lines)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_sliced_service_set 8 __builtin_offsetof(struct __C(v4l2_format), fmt.sliced.service_set)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi 8 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_count 32 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_flags 40 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_offset 12 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_reserved 44 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_sample_format 20 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.sample_format)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_samples_per_line 16 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.samples_per_line)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_sampling_rate 8 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.sampling_rate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_vbi_start 24 __builtin_offsetof(struct __C(v4l2_format), fmt.vbi.start)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win 8 __builtin_offsetof(struct __C(v4l2_format), fmt.win)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_bitmap 48 __builtin_offsetof(struct __C(v4l2_format), fmt.win.bitmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_chromakey 28 __builtin_offsetof(struct __C(v4l2_format), fmt.win.chromakey)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_clipcount 40 __builtin_offsetof(struct __C(v4l2_format), fmt.win.clipcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_clips 32 __builtin_offsetof(struct __C(v4l2_format), fmt.win.clips)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_field 24 __builtin_offsetof(struct __C(v4l2_format), fmt.win.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_global_alpha 56 __builtin_offsetof(struct __C(v4l2_format), fmt.win.global_alpha)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_w 8 __builtin_offsetof(struct __C(v4l2_format), fmt.win.w)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_w_height 20 __builtin_offsetof(struct __C(v4l2_format), fmt.win.w.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_w_left 8 __builtin_offsetof(struct __C(v4l2_format), fmt.win.w.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_w_top 12 __builtin_offsetof(struct __C(v4l2_format), fmt.win.w.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_fmt_win_w_width 16 __builtin_offsetof(struct __C(v4l2_format), fmt.win.w.width)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_format_type 0 __builtin_offsetof(struct __C(v4l2_format), type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_framebuffer 48 sizeof(struct __C(v4l2_framebuffer))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_framebuffer 8 __alignof(struct __C(v4l2_framebuffer))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_base 8 __builtin_offsetof(struct __C(v4l2_framebuffer), base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_capability 0 __builtin_offsetof(struct __C(v4l2_framebuffer), capability)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_flags 4 __builtin_offsetof(struct __C(v4l2_framebuffer), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt 16 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_bytesperline 32 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.bytesperline)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_colorspace 40 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.colorspace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_field 28 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_height 20 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_pixelformat 24 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.pixelformat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_priv 44 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.priv)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_sizeimage 36 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.sizeimage)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_framebuffer_fmt_width 16 __builtin_offsetof(struct __C(v4l2_framebuffer), fmt.width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_plane 64 sizeof(struct __C(v4l2_plane))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_plane 8 __alignof(struct __C(v4l2_plane))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_bytesused 0 __builtin_offsetof(struct __C(v4l2_plane), bytesused)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_data_offset 16 __builtin_offsetof(struct __C(v4l2_plane), data_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_length 4 __builtin_offsetof(struct __C(v4l2_plane), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_m 8 __builtin_offsetof(struct __C(v4l2_plane), m)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_m_fd 8 __builtin_offsetof(struct __C(v4l2_plane), m.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_m_mem_offset 8 __builtin_offsetof(struct __C(v4l2_plane), m.mem_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_m_userptr 8 __builtin_offsetof(struct __C(v4l2_plane), m.userptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_plane_reserved 20 __builtin_offsetof(struct __C(v4l2_plane), reserved)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_subdev_routing 64 sizeof(struct __C(v4l2_subdev_routing))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_subdev_routing 8 __alignof(struct __C(v4l2_subdev_routing))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_subdev_routing_len_routes 4 __builtin_offsetof(struct __C(v4l2_subdev_routing), len_routes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_subdev_routing_num_routes 16 __builtin_offsetof(struct __C(v4l2_subdev_routing), num_routes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_subdev_routing_routes 8 __builtin_offsetof(struct __C(v4l2_subdev_routing), routes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_subdev_routing_which 0 __builtin_offsetof(struct __C(v4l2_subdev_routing), which)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_v4l2_window 56 sizeof(struct __C(v4l2_window))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_v4l2_window 8 __alignof(struct __C(v4l2_window))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_bitmap 40 __builtin_offsetof(struct __C(v4l2_window), bitmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_chromakey 20 __builtin_offsetof(struct __C(v4l2_window), chromakey)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_clipcount 32 __builtin_offsetof(struct __C(v4l2_window), clipcount)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_clips 24 __builtin_offsetof(struct __C(v4l2_window), clips)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_field 16 __builtin_offsetof(struct __C(v4l2_window), field)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_global_alpha 48 __builtin_offsetof(struct __C(v4l2_window), global_alpha)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_w 0 __builtin_offsetof(struct __C(v4l2_window), w)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_w_height 12 __builtin_offsetof(struct __C(v4l2_window), w.height)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_w_left 0 __builtin_offsetof(struct __C(v4l2_window), w.left)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_w_top 4 __builtin_offsetof(struct __C(v4l2_window), w.top)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_v4l2_window_w_width 8 __builtin_offsetof(struct __C(v4l2_window), w.width)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vfio_bitmap 24 sizeof(struct __C(vfio_bitmap))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vfio_bitmap 8 __alignof(struct __C(vfio_bitmap))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_bitmap_data 16 __builtin_offsetof(struct __C(vfio_bitmap), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_bitmap_pgsize 0 __builtin_offsetof(struct __C(vfio_bitmap), pgsize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_bitmap_size 8 __builtin_offsetof(struct __C(vfio_bitmap), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vfio_device_feature_dma_logging_control 24 sizeof(struct __C(vfio_device_feature_dma_logging_control))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vfio_device_feature_dma_logging_control 8 __alignof(struct __C(vfio_device_feature_dma_logging_control))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_control___reserved 12 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_control), __reserved)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_control_num_ranges 8 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_control), num_ranges)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_control_page_size 0 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_control), page_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_control_ranges 16 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_control), ranges)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vfio_device_feature_dma_logging_report 32 sizeof(struct __C(vfio_device_feature_dma_logging_report))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vfio_device_feature_dma_logging_report 8 __alignof(struct __C(vfio_device_feature_dma_logging_report))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_report_bitmap 24 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_report), bitmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_report_iova 0 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_report), iova)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_report_length 8 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_report), length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_device_feature_dma_logging_report_page_size 16 __builtin_offsetof(struct __C(vfio_device_feature_dma_logging_report), page_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vfio_iommu_type1_dirty_bitmap_get 40 sizeof(struct __C(vfio_iommu_type1_dirty_bitmap_get))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vfio_iommu_type1_dirty_bitmap_get 8 __alignof(struct __C(vfio_iommu_type1_dirty_bitmap_get))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_bitmap 16 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), bitmap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_bitmap_data 32 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), bitmap.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_bitmap_pgsize 16 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), bitmap.pgsize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_bitmap_size 24 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), bitmap.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_iova 0 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), iova)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dirty_bitmap_get_size 8 __builtin_offsetof(struct __C(vfio_iommu_type1_dirty_bitmap_get), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vfio_iommu_type1_dma_map 32 sizeof(struct __C(vfio_iommu_type1_dma_map))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vfio_iommu_type1_dma_map 8 __alignof(struct __C(vfio_iommu_type1_dma_map))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dma_map_argsz 0 __builtin_offsetof(struct __C(vfio_iommu_type1_dma_map), argsz)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dma_map_flags 4 __builtin_offsetof(struct __C(vfio_iommu_type1_dma_map), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dma_map_iova 16 __builtin_offsetof(struct __C(vfio_iommu_type1_dma_map), iova)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dma_map_size 24 __builtin_offsetof(struct __C(vfio_iommu_type1_dma_map), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vfio_iommu_type1_dma_map_vaddr 8 __builtin_offsetof(struct __C(vfio_iommu_type1_dma_map), vaddr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_video_still_picture 16 sizeof(struct __C(video_still_picture))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_video_still_picture 8 __alignof(struct __C(video_still_picture))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_video_still_picture_iFrame 0 __builtin_offsetof(struct __C(video_still_picture), iFrame)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_video_still_picture_size 8 __builtin_offsetof(struct __C(video_still_picture), size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_vring 32 sizeof(struct __C(vring))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_vring 8 __alignof(struct __C(vring))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vring_avail 16 __builtin_offsetof(struct __C(vring), avail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vring_desc 8 __builtin_offsetof(struct __C(vring), desc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vring_num 0 __builtin_offsetof(struct __C(vring), num)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_vring_used 24 __builtin_offsetof(struct __C(vring), used)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xattr_args 16 sizeof(struct __C(xattr_args))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xattr_args 8 __alignof(struct __C(xattr_args))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xattr_args_flags 12 __builtin_offsetof(struct __C(xattr_args), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xattr_args_size 8 __builtin_offsetof(struct __C(xattr_args), size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xattr_args_value 0 __builtin_offsetof(struct __C(xattr_args), value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xsdfec_ldpc_params 96 sizeof(struct __C(xsdfec_ldpc_params))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xsdfec_ldpc_params 8 __alignof(struct __C(xsdfec_ldpc_params))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_code_id 88 __builtin_offsetof(struct __C(xsdfec_ldpc_params), code_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_k 4 __builtin_offsetof(struct __C(xsdfec_ldpc_params), k)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_la_off 52 __builtin_offsetof(struct __C(xsdfec_ldpc_params), la_off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_la_table 72 __builtin_offsetof(struct __C(xsdfec_ldpc_params), la_table)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_max_schedule 44 __builtin_offsetof(struct __C(xsdfec_ldpc_params), max_schedule)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_n 0 __builtin_offsetof(struct __C(xsdfec_ldpc_params), n)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_nlayers 12 __builtin_offsetof(struct __C(xsdfec_ldpc_params), nlayers)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_nm 24 __builtin_offsetof(struct __C(xsdfec_ldpc_params), nm)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_nmqc 20 __builtin_offsetof(struct __C(xsdfec_ldpc_params), nmqc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_no_final_parity 40 __builtin_offsetof(struct __C(xsdfec_ldpc_params), no_final_parity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_no_packing 32 __builtin_offsetof(struct __C(xsdfec_ldpc_params), no_packing)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_norm_type 28 __builtin_offsetof(struct __C(xsdfec_ldpc_params), norm_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_nqc 16 __builtin_offsetof(struct __C(xsdfec_ldpc_params), nqc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_psize 8 __builtin_offsetof(struct __C(xsdfec_ldpc_params), psize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_qc_off 56 __builtin_offsetof(struct __C(xsdfec_ldpc_params), qc_off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_qc_table 80 __builtin_offsetof(struct __C(xsdfec_ldpc_params), qc_table)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_sc_off 48 __builtin_offsetof(struct __C(xsdfec_ldpc_params), sc_off)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_sc_table 64 __builtin_offsetof(struct __C(xsdfec_ldpc_params), sc_table)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xsdfec_ldpc_params_special_qc 36 __builtin_offsetof(struct __C(xsdfec_ldpc_params), special_qc)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_bpf_info 528 sizeof(struct __C(xt_bpf_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_bpf_info 8 __alignof(struct __C(xt_bpf_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program 4 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program_0__code 4 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program[0].code)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program_0__jf 7 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program[0].jf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program_0__jt 6 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program[0].jt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program_0__k 8 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program[0].k)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_bpf_program_num_elem 0 __builtin_offsetof(struct __C(xt_bpf_info), bpf_program_num_elem)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_bpf_info_v1 528 sizeof(struct __C(xt_bpf_info_v1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_bpf_info_v1 8 __alignof(struct __C(xt_bpf_info_v1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program 8 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program_0__code 8 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program[0].code)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program_0__jf 11 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program[0].jf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program_0__jt 10 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program[0].jt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program_0__k 12 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program[0].k)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_bpf_program_num_elem 2 __builtin_offsetof(struct __C(xt_bpf_info_v1), bpf_program_num_elem)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_fd 4 __builtin_offsetof(struct __C(xt_bpf_info_v1), fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_mode 0 __builtin_offsetof(struct __C(xt_bpf_info_v1), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_bpf_info_v1_path 8 __builtin_offsetof(struct __C(xt_bpf_info_v1), path)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_cgroup_info_v1 4112 sizeof(struct __C(xt_cgroup_info_v1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_cgroup_info_v1 8 __alignof(struct __C(xt_cgroup_info_v1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_classid 4100 __builtin_offsetof(struct __C(xt_cgroup_info_v1), classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_has_classid 1 __builtin_offsetof(struct __C(xt_cgroup_info_v1), has_classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_has_path 0 __builtin_offsetof(struct __C(xt_cgroup_info_v1), has_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_invert_classid 3 __builtin_offsetof(struct __C(xt_cgroup_info_v1), invert_classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_invert_path 2 __builtin_offsetof(struct __C(xt_cgroup_info_v1), invert_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_path 4 __builtin_offsetof(struct __C(xt_cgroup_info_v1), path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v1_priv 4104 __builtin_offsetof(struct __C(xt_cgroup_info_v1), priv)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_cgroup_info_v2 528 sizeof(struct __C(xt_cgroup_info_v2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_cgroup_info_v2 8 __alignof(struct __C(xt_cgroup_info_v2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_classid 4 __builtin_offsetof(struct __C(xt_cgroup_info_v2), classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_has_classid 1 __builtin_offsetof(struct __C(xt_cgroup_info_v2), has_classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_has_path 0 __builtin_offsetof(struct __C(xt_cgroup_info_v2), has_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_invert_classid 3 __builtin_offsetof(struct __C(xt_cgroup_info_v2), invert_classid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_invert_path 2 __builtin_offsetof(struct __C(xt_cgroup_info_v2), invert_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_path 4 __builtin_offsetof(struct __C(xt_cgroup_info_v2), path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_cgroup_info_v2_priv 520 __builtin_offsetof(struct __C(xt_cgroup_info_v2), priv)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_connlimit_info 32 sizeof(struct __C(xt_connlimit_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_connlimit_info 8 __alignof(struct __C(xt_connlimit_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_flags 20 __builtin_offsetof(struct __C(xt_connlimit_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_limit 16 __builtin_offsetof(struct __C(xt_connlimit_info), limit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_all 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.all)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in_s_addr 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in6 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in6_in6_u 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in6.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in6_in6_u_u6_addr16 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in6.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in6_in6_u_u6_addr32 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in6.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_in6_in6_u_u6_addr8 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.in6.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_ip 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_connlimit_info_mask_ip6 0 __builtin_offsetof(struct __C(xt_connlimit_info), mask.ip6)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_counters 16 sizeof(struct __C(xt_counters))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_counters 8 __alignof(struct __C(xt_counters))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_bcnt 8 __builtin_offsetof(struct __C(xt_counters), bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_pcnt 0 __builtin_offsetof(struct __C(xt_counters), pcnt)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_counters_info 40 sizeof(struct __C(xt_counters_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_counters_info 8 __alignof(struct __C(xt_counters_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_info_counters 40 __builtin_offsetof(struct __C(xt_counters_info), counters)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_info_counters_0__bcnt 48 __builtin_offsetof(struct __C(xt_counters_info), counters[0].bcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_info_counters_0__pcnt 40 __builtin_offsetof(struct __C(xt_counters_info), counters[0].pcnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_info_name 0 __builtin_offsetof(struct __C(xt_counters_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_counters_info_num_counters 32 __builtin_offsetof(struct __C(xt_counters_info), num_counters)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_ct_target_info 40 sizeof(struct __C(xt_ct_target_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_ct_target_info 8 __alignof(struct __C(xt_ct_target_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_ct_events 4 __builtin_offsetof(struct __C(xt_ct_target_info), ct_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_exp_events 8 __builtin_offsetof(struct __C(xt_ct_target_info), exp_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_flags 0 __builtin_offsetof(struct __C(xt_ct_target_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_helper 12 __builtin_offsetof(struct __C(xt_ct_target_info), helper)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_zone 2 __builtin_offsetof(struct __C(xt_ct_target_info), zone)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_ct_target_info_v1 72 sizeof(struct __C(xt_ct_target_info_v1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_ct_target_info_v1 8 __alignof(struct __C(xt_ct_target_info_v1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_ct_events 4 __builtin_offsetof(struct __C(xt_ct_target_info_v1), ct_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_exp_events 8 __builtin_offsetof(struct __C(xt_ct_target_info_v1), exp_events)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_flags 0 __builtin_offsetof(struct __C(xt_ct_target_info_v1), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_helper 12 __builtin_offsetof(struct __C(xt_ct_target_info_v1), helper)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_timeout 28 __builtin_offsetof(struct __C(xt_ct_target_info_v1), timeout)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_ct_target_info_v1_zone 2 __builtin_offsetof(struct __C(xt_ct_target_info_v1), zone)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_entry_match 32 sizeof(struct __C(xt_entry_match))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_entry_match 8 __alignof(struct __C(xt_entry_match))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_data 32 __builtin_offsetof(struct __C(xt_entry_match), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u 0 __builtin_offsetof(struct __C(xt_entry_match), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_kernel 0 __builtin_offsetof(struct __C(xt_entry_match), u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_kernel_match_size 0 __builtin_offsetof(struct __C(xt_entry_match), u.kernel.match_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_match_size 0 __builtin_offsetof(struct __C(xt_entry_match), u.match_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_user 0 __builtin_offsetof(struct __C(xt_entry_match), u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_user_match_size 0 __builtin_offsetof(struct __C(xt_entry_match), u.user.match_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_user_name 2 __builtin_offsetof(struct __C(xt_entry_match), u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_match_u_user_revision 31 __builtin_offsetof(struct __C(xt_entry_match), u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_entry_target 32 sizeof(struct __C(xt_entry_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_entry_target 8 __alignof(struct __C(xt_entry_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_data 32 __builtin_offsetof(struct __C(xt_entry_target), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u 0 __builtin_offsetof(struct __C(xt_entry_target), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_kernel 0 __builtin_offsetof(struct __C(xt_entry_target), u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_kernel_target_size 0 __builtin_offsetof(struct __C(xt_entry_target), u.kernel.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_target_size 0 __builtin_offsetof(struct __C(xt_entry_target), u.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_user 0 __builtin_offsetof(struct __C(xt_entry_target), u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_user_name 2 __builtin_offsetof(struct __C(xt_entry_target), u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_user_revision 31 __builtin_offsetof(struct __C(xt_entry_target), u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_entry_target_u_user_target_size 0 __builtin_offsetof(struct __C(xt_entry_target), u.user.target_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_error_target 64 sizeof(struct __C(xt_error_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_error_target 8 __alignof(struct __C(xt_error_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_errorname 32 __builtin_offsetof(struct __C(xt_error_target), errorname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target 0 __builtin_offsetof(struct __C(xt_error_target), target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_data 32 __builtin_offsetof(struct __C(xt_error_target), target.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u 0 __builtin_offsetof(struct __C(xt_error_target), target.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_kernel 0 __builtin_offsetof(struct __C(xt_error_target), target.u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_kernel_target_size 0 __builtin_offsetof(struct __C(xt_error_target), target.u.kernel.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_target_size 0 __builtin_offsetof(struct __C(xt_error_target), target.u.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_user 0 __builtin_offsetof(struct __C(xt_error_target), target.u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_user_name 2 __builtin_offsetof(struct __C(xt_error_target), target.u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_user_revision 31 __builtin_offsetof(struct __C(xt_error_target), target.u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_error_target_target_u_user_target_size 0 __builtin_offsetof(struct __C(xt_error_target), target.u.user.target_size)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_hashlimit_info 64 sizeof(struct __C(xt_hashlimit_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_hashlimit_info 8 __alignof(struct __C(xt_hashlimit_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg 16 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_avg 20 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.avg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_burst 24 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.burst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_expire 40 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.expire)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_gc_interval 36 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.gc_interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_max 32 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_mode 16 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_cfg_size 28 __builtin_offsetof(struct __C(xt_hashlimit_info), cfg.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_hinfo 48 __builtin_offsetof(struct __C(xt_hashlimit_info), hinfo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_name 0 __builtin_offsetof(struct __C(xt_hashlimit_info), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_u 56 __builtin_offsetof(struct __C(xt_hashlimit_info), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_u_master 56 __builtin_offsetof(struct __C(xt_hashlimit_info), u.master)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_info_u_ptr 56 __builtin_offsetof(struct __C(xt_hashlimit_info), u.ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_hashlimit_mtinfo1 56 sizeof(struct __C(xt_hashlimit_mtinfo1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_hashlimit_mtinfo1 8 __alignof(struct __C(xt_hashlimit_mtinfo1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg 16 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_avg 20 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.avg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_burst 24 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.burst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_dstmask 45 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.dstmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_expire 40 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.expire)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_gc_interval 36 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.gc_interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_max 32 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_mode 16 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_size 28 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_cfg_srcmask 44 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), cfg.srcmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo1_name 0 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo1), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_hashlimit_mtinfo2 304 sizeof(struct __C(xt_hashlimit_mtinfo2))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_hashlimit_mtinfo2 8 __alignof(struct __C(xt_hashlimit_mtinfo2))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg 256 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_avg 256 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.avg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_burst 264 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.burst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_dstmask 293 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.dstmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_expire 288 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.expire)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_gc_interval 284 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.gc_interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_max 280 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_mode 272 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_size 276 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_cfg_srcmask 292 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), cfg.srcmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo2_name 0 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo2), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_hashlimit_mtinfo3 312 sizeof(struct __C(xt_hashlimit_mtinfo3))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_hashlimit_mtinfo3 8 __alignof(struct __C(xt_hashlimit_mtinfo3))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg 256 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_avg 256 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.avg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_burst 264 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.burst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_dstmask 297 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.dstmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_expire 288 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.expire)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_gc_interval 284 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.gc_interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_interval 292 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_max 280 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.max)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_mode 272 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_size 276 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_cfg_srcmask 296 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), cfg.srcmask)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_hashlimit_mtinfo3_name 0 __builtin_offsetof(struct __C(xt_hashlimit_mtinfo3), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_led_info 40 sizeof(struct __C(xt_led_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_led_info 8 __alignof(struct __C(xt_led_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_led_info_always_blink 27 __builtin_offsetof(struct __C(xt_led_info), always_blink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_led_info_delay 28 __builtin_offsetof(struct __C(xt_led_info), delay)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_led_info_id 0 __builtin_offsetof(struct __C(xt_led_info), id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_led_info_internal_data 32 __builtin_offsetof(struct __C(xt_led_info), internal_data)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_nfacct_match_info 40 sizeof(struct __C(xt_nfacct_match_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_nfacct_match_info 8 __alignof(struct __C(xt_nfacct_match_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_nfacct_match_info_name 0 __builtin_offsetof(struct __C(xt_nfacct_match_info), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_nfacct_match_info_v1 40 sizeof(struct __C(xt_nfacct_match_info_v1))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_nfacct_match_info_v1 8 __alignof(struct __C(xt_nfacct_match_info_v1))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_nfacct_match_info_v1_name 0 __builtin_offsetof(struct __C(xt_nfacct_match_info_v1), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_quota_info 24 sizeof(struct __C(xt_quota_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_quota_info 8 __alignof(struct __C(xt_quota_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_quota_info_flags 0 __builtin_offsetof(struct __C(xt_quota_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_quota_info_pad 4 __builtin_offsetof(struct __C(xt_quota_info), pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_quota_info_quota 8 __builtin_offsetof(struct __C(xt_quota_info), quota)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_rateest_match_info 72 sizeof(struct __C(xt_rateest_match_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_rateest_match_info 8 __alignof(struct __C(xt_rateest_match_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_bps1 36 __builtin_offsetof(struct __C(xt_rateest_match_info), bps1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_bps2 44 __builtin_offsetof(struct __C(xt_rateest_match_info), bps2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_flags 32 __builtin_offsetof(struct __C(xt_rateest_match_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_mode 34 __builtin_offsetof(struct __C(xt_rateest_match_info), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_name1 0 __builtin_offsetof(struct __C(xt_rateest_match_info), name1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_name2 16 __builtin_offsetof(struct __C(xt_rateest_match_info), name2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_pps1 40 __builtin_offsetof(struct __C(xt_rateest_match_info), pps1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_match_info_pps2 48 __builtin_offsetof(struct __C(xt_rateest_match_info), pps2)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_rateest_target_info 32 sizeof(struct __C(xt_rateest_target_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_rateest_target_info 8 __alignof(struct __C(xt_rateest_target_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_target_info_ewma_log 17 __builtin_offsetof(struct __C(xt_rateest_target_info), ewma_log)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_target_info_interval 16 __builtin_offsetof(struct __C(xt_rateest_target_info), interval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateest_target_info_name 0 __builtin_offsetof(struct __C(xt_rateest_target_info), name)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_rateinfo 40 sizeof(struct __C(xt_rateinfo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_rateinfo 8 __alignof(struct __C(xt_rateinfo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_avg 0 __builtin_offsetof(struct __C(xt_rateinfo), avg)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_burst 4 __builtin_offsetof(struct __C(xt_rateinfo), burst)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_cost 24 __builtin_offsetof(struct __C(xt_rateinfo), cost)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_credit 16 __builtin_offsetof(struct __C(xt_rateinfo), credit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_credit_cap 20 __builtin_offsetof(struct __C(xt_rateinfo), credit_cap)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_rateinfo_prev 8 __builtin_offsetof(struct __C(xt_rateinfo), prev)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_standard_target 40 sizeof(struct __C(xt_standard_target))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_standard_target 8 __alignof(struct __C(xt_standard_target))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target 0 __builtin_offsetof(struct __C(xt_standard_target), target)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_data 32 __builtin_offsetof(struct __C(xt_standard_target), target.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u 0 __builtin_offsetof(struct __C(xt_standard_target), target.u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_kernel 0 __builtin_offsetof(struct __C(xt_standard_target), target.u.kernel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_kernel_target_size 0 __builtin_offsetof(struct __C(xt_standard_target), target.u.kernel.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_target_size 0 __builtin_offsetof(struct __C(xt_standard_target), target.u.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_user 0 __builtin_offsetof(struct __C(xt_standard_target), target.u.user)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_user_name 2 __builtin_offsetof(struct __C(xt_standard_target), target.u.user.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_user_revision 31 __builtin_offsetof(struct __C(xt_standard_target), target.u.user.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_target_u_user_target_size 0 __builtin_offsetof(struct __C(xt_standard_target), target.u.user.target_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_standard_target_verdict 32 __builtin_offsetof(struct __C(xt_standard_target), verdict)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_statistic_info 24 sizeof(struct __C(xt_statistic_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_statistic_info 8 __alignof(struct __C(xt_statistic_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_flags 2 __builtin_offsetof(struct __C(xt_statistic_info), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_mode 0 __builtin_offsetof(struct __C(xt_statistic_info), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u 4 __builtin_offsetof(struct __C(xt_statistic_info), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_nth 4 __builtin_offsetof(struct __C(xt_statistic_info), u.nth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_nth_count 12 __builtin_offsetof(struct __C(xt_statistic_info), u.nth.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_nth_every 4 __builtin_offsetof(struct __C(xt_statistic_info), u.nth.every)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_nth_packet 8 __builtin_offsetof(struct __C(xt_statistic_info), u.nth.packet)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_random 4 __builtin_offsetof(struct __C(xt_statistic_info), u.random)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_statistic_info_u_random_probability 4 __builtin_offsetof(struct __C(xt_statistic_info), u.random.probability)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_string_info 160 sizeof(struct __C(xt_string_info))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_string_info 8 __alignof(struct __C(xt_string_info))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_algo 4 __builtin_offsetof(struct __C(xt_string_info), algo)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_config 152 __builtin_offsetof(struct __C(xt_string_info), config)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_from_offset 0 __builtin_offsetof(struct __C(xt_string_info), from_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_patlen 148 __builtin_offsetof(struct __C(xt_string_info), patlen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_pattern 20 __builtin_offsetof(struct __C(xt_string_info), pattern)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_to_offset 2 __builtin_offsetof(struct __C(xt_string_info), to_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_u 149 __builtin_offsetof(struct __C(xt_string_info), u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_u_v0 149 __builtin_offsetof(struct __C(xt_string_info), u.v0)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_u_v0_invert 149 __builtin_offsetof(struct __C(xt_string_info), u.v0.invert)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_u_v1 149 __builtin_offsetof(struct __C(xt_string_info), u.v1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_string_info_u_v1_flags 149 __builtin_offsetof(struct __C(xt_string_info), u.v1.flags)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_struct_xt_tee_tginfo 40 sizeof(struct __C(xt_tee_tginfo))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_struct_xt_tee_tginfo 8 __alignof(struct __C(xt_tee_tginfo))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_all 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.all)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in_s_addr 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in.s_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in6 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in6_in6_u 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in6.in6_u)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in6_in6_u_u6_addr16 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in6.in6_u.u6_addr16)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in6_in6_u_u6_addr32 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in6.in6_u.u6_addr32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_in6_in6_u_u6_addr8 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.in6.in6_u.u6_addr8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_ip 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.ip)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_gw_ip6 0 __builtin_offsetof(struct __C(xt_tee_tginfo), gw.ip6)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_xt_tee_tginfo_oif 16 __builtin_offsetof(struct __C(xt_tee_tginfo), oif)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_bpf_attr 152 sizeof(union __C(bpf_attr))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_bpf_attr 8 __alignof(union __C(bpf_attr))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_bpf_fd 4 __builtin_offsetof(union __C(bpf_attr), attach_bpf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_btf_id 108 __builtin_offsetof(union __C(bpf_attr), attach_btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_btf_obj_fd 112 __builtin_offsetof(union __C(bpf_attr), attach_btf_obj_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_flags 12 __builtin_offsetof(union __C(bpf_attr), attach_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_prog_fd 112 __builtin_offsetof(union __C(bpf_attr), attach_prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_attach_type 8 __builtin_offsetof(union __C(bpf_attr), attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch 0 __builtin_offsetof(union __C(bpf_attr), batch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_count 32 __builtin_offsetof(union __C(bpf_attr), batch.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_elem_flags 40 __builtin_offsetof(union __C(bpf_attr), batch.elem_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_flags 48 __builtin_offsetof(union __C(bpf_attr), batch.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_in_batch 0 __builtin_offsetof(union __C(bpf_attr), batch.in_batch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_keys 16 __builtin_offsetof(union __C(bpf_attr), batch.keys)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_map_fd 36 __builtin_offsetof(union __C(bpf_attr), batch.map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_out_batch 8 __builtin_offsetof(union __C(bpf_attr), batch.out_batch)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_batch_values 24 __builtin_offsetof(union __C(bpf_attr), batch.values)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_bpf_fd 8 __builtin_offsetof(union __C(bpf_attr), bpf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf 0 __builtin_offsetof(union __C(bpf_attr), btf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_fd 48 __builtin_offsetof(union __C(bpf_attr), btf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_flags 32 __builtin_offsetof(union __C(bpf_attr), btf_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_id 0 __builtin_offsetof(union __C(bpf_attr), btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_key_type_id 52 __builtin_offsetof(union __C(bpf_attr), btf_key_type_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_log_buf 8 __builtin_offsetof(union __C(bpf_attr), btf_log_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_log_level 24 __builtin_offsetof(union __C(bpf_attr), btf_log_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_log_size 20 __builtin_offsetof(union __C(bpf_attr), btf_log_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_log_true_size 28 __builtin_offsetof(union __C(bpf_attr), btf_log_true_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_size 16 __builtin_offsetof(union __C(bpf_attr), btf_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_token_fd 36 __builtin_offsetof(union __C(bpf_attr), btf_token_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_value_type_id 56 __builtin_offsetof(union __C(bpf_attr), btf_value_type_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_btf_vmlinux_value_type_id 60 __builtin_offsetof(union __C(bpf_attr), btf_vmlinux_value_type_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_core_relo_cnt 116 __builtin_offsetof(union __C(bpf_attr), core_relo_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_core_relo_rec_size 136 __builtin_offsetof(union __C(bpf_attr), core_relo_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_core_relos 128 __builtin_offsetof(union __C(bpf_attr), core_relos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_enable_stats 0 __builtin_offsetof(union __C(bpf_attr), enable_stats)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_enable_stats_type 0 __builtin_offsetof(union __C(bpf_attr), enable_stats.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_expected_attach_type 68 __builtin_offsetof(union __C(bpf_attr), expected_attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_expected_revision 24 __builtin_offsetof(union __C(bpf_attr), expected_revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_fd_array 120 __builtin_offsetof(union __C(bpf_attr), fd_array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_fd_array_cnt 148 __builtin_offsetof(union __C(bpf_attr), fd_array_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_fd_by_id_token_fd 12 __builtin_offsetof(union __C(bpf_attr), fd_by_id_token_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_file_flags 12 __builtin_offsetof(union __C(bpf_attr), file_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_flags 24 __builtin_offsetof(union __C(bpf_attr), flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_func_info 80 __builtin_offsetof(union __C(bpf_attr), func_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_func_info_cnt 88 __builtin_offsetof(union __C(bpf_attr), func_info_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_func_info_rec_size 76 __builtin_offsetof(union __C(bpf_attr), func_info_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_info 0 __builtin_offsetof(union __C(bpf_attr), info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_info_bpf_fd 0 __builtin_offsetof(union __C(bpf_attr), info.bpf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_info_info 8 __builtin_offsetof(union __C(bpf_attr), info.info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_info_info_len 4 __builtin_offsetof(union __C(bpf_attr), info.info_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_inner_map_fd 20 __builtin_offsetof(union __C(bpf_attr), inner_map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_insn_cnt 4 __builtin_offsetof(union __C(bpf_attr), insn_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_insns 8 __builtin_offsetof(union __C(bpf_attr), insns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_iter_create 0 __builtin_offsetof(union __C(bpf_attr), iter_create)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_iter_create_flags 4 __builtin_offsetof(union __C(bpf_attr), iter_create.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_iter_create_link_fd 0 __builtin_offsetof(union __C(bpf_attr), iter_create.link_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_kern_version 40 __builtin_offsetof(union __C(bpf_attr), kern_version)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_key 8 __builtin_offsetof(union __C(bpf_attr), key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_key_size 4 __builtin_offsetof(union __C(bpf_attr), key_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_license 16 __builtin_offsetof(union __C(bpf_attr), license)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_line_info 96 __builtin_offsetof(union __C(bpf_attr), line_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_line_info_cnt 104 __builtin_offsetof(union __C(bpf_attr), line_info_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_line_info_rec_size 92 __builtin_offsetof(union __C(bpf_attr), line_info_rec_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create 0 __builtin_offsetof(union __C(bpf_attr), link_create)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_attach_type 8 __builtin_offsetof(union __C(bpf_attr), link_create.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_flags 12 __builtin_offsetof(union __C(bpf_attr), link_create.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_iter_info 16 __builtin_offsetof(union __C(bpf_attr), link_create.iter_info)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_iter_info_len 24 __builtin_offsetof(union __C(bpf_attr), link_create.iter_info_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi 16 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi_addrs 32 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi.addrs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi_cnt 20 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi.cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi_cookies 40 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi.cookies)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi_flags 16 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_kprobe_multi_syms 24 __builtin_offsetof(union __C(bpf_attr), link_create.kprobe_multi.syms)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_map_fd 0 __builtin_offsetof(union __C(bpf_attr), link_create.map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netfilter 16 __builtin_offsetof(union __C(bpf_attr), link_create.netfilter)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netfilter_flags 28 __builtin_offsetof(union __C(bpf_attr), link_create.netfilter.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netfilter_hooknum 20 __builtin_offsetof(union __C(bpf_attr), link_create.netfilter.hooknum)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netfilter_pf 16 __builtin_offsetof(union __C(bpf_attr), link_create.netfilter.pf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netfilter_priority 24 __builtin_offsetof(union __C(bpf_attr), link_create.netfilter.priority)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netkit 16 __builtin_offsetof(union __C(bpf_attr), link_create.netkit)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netkit_expected_revision 24 __builtin_offsetof(union __C(bpf_attr), link_create.netkit.expected_revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netkit_relative_fd 16 __builtin_offsetof(union __C(bpf_attr), link_create.netkit.relative_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_netkit_relative_id 16 __builtin_offsetof(union __C(bpf_attr), link_create.netkit.relative_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_perf_event 16 __builtin_offsetof(union __C(bpf_attr), link_create.perf_event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_perf_event_bpf_cookie 16 __builtin_offsetof(union __C(bpf_attr), link_create.perf_event.bpf_cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_prog_fd 0 __builtin_offsetof(union __C(bpf_attr), link_create.prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_target_btf_id 16 __builtin_offsetof(union __C(bpf_attr), link_create.target_btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_target_fd 4 __builtin_offsetof(union __C(bpf_attr), link_create.target_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_target_ifindex 4 __builtin_offsetof(union __C(bpf_attr), link_create.target_ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tcx 16 __builtin_offsetof(union __C(bpf_attr), link_create.tcx)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tcx_expected_revision 24 __builtin_offsetof(union __C(bpf_attr), link_create.tcx.expected_revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tcx_relative_fd 16 __builtin_offsetof(union __C(bpf_attr), link_create.tcx.relative_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tcx_relative_id 16 __builtin_offsetof(union __C(bpf_attr), link_create.tcx.relative_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tracing 16 __builtin_offsetof(union __C(bpf_attr), link_create.tracing)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tracing_cookie 24 __builtin_offsetof(union __C(bpf_attr), link_create.tracing.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_tracing_target_btf_id 16 __builtin_offsetof(union __C(bpf_attr), link_create.tracing.target_btf_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi 16 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_cnt 48 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_cookies 40 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.cookies)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_flags 52 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_offsets 24 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_path 16 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_pid 56 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_create_uprobe_multi_ref_ctr_offsets 32 __builtin_offsetof(union __C(bpf_attr), link_create.uprobe_multi.ref_ctr_offsets)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_detach 0 __builtin_offsetof(union __C(bpf_attr), link_detach)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_detach_link_fd 0 __builtin_offsetof(union __C(bpf_attr), link_detach.link_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_id 0 __builtin_offsetof(union __C(bpf_attr), link_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update 0 __builtin_offsetof(union __C(bpf_attr), link_update)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_flags 8 __builtin_offsetof(union __C(bpf_attr), link_update.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_link_fd 0 __builtin_offsetof(union __C(bpf_attr), link_update.link_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_new_map_fd 4 __builtin_offsetof(union __C(bpf_attr), link_update.new_map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_new_prog_fd 4 __builtin_offsetof(union __C(bpf_attr), link_update.new_prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_old_map_fd 12 __builtin_offsetof(union __C(bpf_attr), link_update.old_map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_link_update_old_prog_fd 12 __builtin_offsetof(union __C(bpf_attr), link_update.old_prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_log_buf 32 __builtin_offsetof(union __C(bpf_attr), log_buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_log_level 24 __builtin_offsetof(union __C(bpf_attr), log_level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_log_size 28 __builtin_offsetof(union __C(bpf_attr), log_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_log_true_size 140 __builtin_offsetof(union __C(bpf_attr), log_true_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_extra 64 __builtin_offsetof(union __C(bpf_attr), map_extra)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_fd 0 __builtin_offsetof(union __C(bpf_attr), map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_flags 16 __builtin_offsetof(union __C(bpf_attr), map_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_id 0 __builtin_offsetof(union __C(bpf_attr), map_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_ifindex 44 __builtin_offsetof(union __C(bpf_attr), map_ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_name 28 __builtin_offsetof(union __C(bpf_attr), map_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_token_fd 76 __builtin_offsetof(union __C(bpf_attr), map_token_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_map_type 0 __builtin_offsetof(union __C(bpf_attr), map_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_max_entries 12 __builtin_offsetof(union __C(bpf_attr), max_entries)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_next_id 4 __builtin_offsetof(union __C(bpf_attr), next_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_next_key 16 __builtin_offsetof(union __C(bpf_attr), next_key)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_numa_node 24 __builtin_offsetof(union __C(bpf_attr), numa_node)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_open_flags 8 __builtin_offsetof(union __C(bpf_attr), open_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_path_fd 16 __builtin_offsetof(union __C(bpf_attr), path_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_pathname 0 __builtin_offsetof(union __C(bpf_attr), pathname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_bind_map 0 __builtin_offsetof(union __C(bpf_attr), prog_bind_map)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_bind_map_flags 8 __builtin_offsetof(union __C(bpf_attr), prog_bind_map.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_bind_map_map_fd 4 __builtin_offsetof(union __C(bpf_attr), prog_bind_map.map_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_bind_map_prog_fd 0 __builtin_offsetof(union __C(bpf_attr), prog_bind_map.prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_btf_fd 72 __builtin_offsetof(union __C(bpf_attr), prog_btf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_flags 44 __builtin_offsetof(union __C(bpf_attr), prog_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_id 0 __builtin_offsetof(union __C(bpf_attr), prog_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_ifindex 64 __builtin_offsetof(union __C(bpf_attr), prog_ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_name 48 __builtin_offsetof(union __C(bpf_attr), prog_name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_token_fd 144 __builtin_offsetof(union __C(bpf_attr), prog_token_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_prog_type 0 __builtin_offsetof(union __C(bpf_attr), prog_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query 0 __builtin_offsetof(union __C(bpf_attr), query)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_attach_flags 12 __builtin_offsetof(union __C(bpf_attr), query.attach_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_attach_type 4 __builtin_offsetof(union __C(bpf_attr), query.attach_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_count 24 __builtin_offsetof(union __C(bpf_attr), query.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_link_attach_flags 48 __builtin_offsetof(union __C(bpf_attr), query.link_attach_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_link_ids 40 __builtin_offsetof(union __C(bpf_attr), query.link_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_prog_attach_flags 32 __builtin_offsetof(union __C(bpf_attr), query.prog_attach_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_prog_cnt 24 __builtin_offsetof(union __C(bpf_attr), query.prog_cnt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_prog_ids 16 __builtin_offsetof(union __C(bpf_attr), query.prog_ids)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_query_flags 8 __builtin_offsetof(union __C(bpf_attr), query.query_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_revision 56 __builtin_offsetof(union __C(bpf_attr), query.revision)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_target_fd 0 __builtin_offsetof(union __C(bpf_attr), query.target_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_query_target_ifindex 0 __builtin_offsetof(union __C(bpf_attr), query.target_ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_raw_tracepoint 0 __builtin_offsetof(union __C(bpf_attr), raw_tracepoint)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_raw_tracepoint_cookie 16 __builtin_offsetof(union __C(bpf_attr), raw_tracepoint.cookie)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_raw_tracepoint_name 0 __builtin_offsetof(union __C(bpf_attr), raw_tracepoint.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_raw_tracepoint_prog_fd 8 __builtin_offsetof(union __C(bpf_attr), raw_tracepoint.prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_relative_fd 20 __builtin_offsetof(union __C(bpf_attr), relative_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_relative_id 20 __builtin_offsetof(union __C(bpf_attr), relative_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_replace_bpf_fd 16 __builtin_offsetof(union __C(bpf_attr), replace_bpf_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_start_id 0 __builtin_offsetof(union __C(bpf_attr), start_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_target_fd 0 __builtin_offsetof(union __C(bpf_attr), target_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_target_ifindex 0 __builtin_offsetof(union __C(bpf_attr), target_ifindex)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query 0 __builtin_offsetof(union __C(bpf_attr), task_fd_query)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_buf 16 __builtin_offsetof(union __C(bpf_attr), task_fd_query.buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_buf_len 12 __builtin_offsetof(union __C(bpf_attr), task_fd_query.buf_len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_fd 4 __builtin_offsetof(union __C(bpf_attr), task_fd_query.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_fd_type 28 __builtin_offsetof(union __C(bpf_attr), task_fd_query.fd_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_flags 8 __builtin_offsetof(union __C(bpf_attr), task_fd_query.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_pid 0 __builtin_offsetof(union __C(bpf_attr), task_fd_query.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_probe_addr 40 __builtin_offsetof(union __C(bpf_attr), task_fd_query.probe_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_probe_offset 32 __builtin_offsetof(union __C(bpf_attr), task_fd_query.probe_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_task_fd_query_prog_id 24 __builtin_offsetof(union __C(bpf_attr), task_fd_query.prog_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test 0 __builtin_offsetof(union __C(bpf_attr), test)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_batch_size 72 __builtin_offsetof(union __C(bpf_attr), test.batch_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_cpu 68 __builtin_offsetof(union __C(bpf_attr), test.cpu)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_ctx_in 48 __builtin_offsetof(union __C(bpf_attr), test.ctx_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_ctx_out 56 __builtin_offsetof(union __C(bpf_attr), test.ctx_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_ctx_size_in 40 __builtin_offsetof(union __C(bpf_attr), test.ctx_size_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_ctx_size_out 44 __builtin_offsetof(union __C(bpf_attr), test.ctx_size_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_data_in 16 __builtin_offsetof(union __C(bpf_attr), test.data_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_data_out 24 __builtin_offsetof(union __C(bpf_attr), test.data_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_data_size_in 8 __builtin_offsetof(union __C(bpf_attr), test.data_size_in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_data_size_out 12 __builtin_offsetof(union __C(bpf_attr), test.data_size_out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_duration 36 __builtin_offsetof(union __C(bpf_attr), test.duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_flags 64 __builtin_offsetof(union __C(bpf_attr), test.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_prog_fd 0 __builtin_offsetof(union __C(bpf_attr), test.prog_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_repeat 32 __builtin_offsetof(union __C(bpf_attr), test.repeat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_test_retval 4 __builtin_offsetof(union __C(bpf_attr), test.retval)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_token_create 0 __builtin_offsetof(union __C(bpf_attr), token_create)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_token_create_bpffs_fd 4 __builtin_offsetof(union __C(bpf_attr), token_create.bpffs_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_token_create_flags 0 __builtin_offsetof(union __C(bpf_attr), token_create.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_value 16 __builtin_offsetof(union __C(bpf_attr), value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_value_size 8 __builtin_offsetof(union __C(bpf_attr), value_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_bpf_attr_value_type_btf_obj_fd 72 __builtin_offsetof(union __C(bpf_attr), value_type_btf_obj_fd)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_drm_amdgpu_bo_list 24 sizeof(union __C(drm_amdgpu_bo_list))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_drm_amdgpu_bo_list 8 __alignof(union __C(drm_amdgpu_bo_list))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in 0 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_info_ptr 16 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in.bo_info_ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_info_size 12 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in.bo_info_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_bo_number 8 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in.bo_number)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_list_handle 4 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in.list_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_in_operation 0 __builtin_offsetof(union __C(drm_amdgpu_bo_list), in.operation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_out 0 __builtin_offsetof(union __C(drm_amdgpu_bo_list), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_out__pad 4 __builtin_offsetof(union __C(drm_amdgpu_bo_list), out._pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_bo_list_out_list_handle 0 __builtin_offsetof(union __C(drm_amdgpu_bo_list), out.list_handle)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_drm_amdgpu_cs 24 sizeof(union __C(drm_amdgpu_cs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_drm_amdgpu_cs 8 __alignof(union __C(drm_amdgpu_cs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in 0 __builtin_offsetof(union __C(drm_amdgpu_cs), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_bo_list_handle 4 __builtin_offsetof(union __C(drm_amdgpu_cs), in.bo_list_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_chunks 16 __builtin_offsetof(union __C(drm_amdgpu_cs), in.chunks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_ctx_id 0 __builtin_offsetof(union __C(drm_amdgpu_cs), in.ctx_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_flags 12 __builtin_offsetof(union __C(drm_amdgpu_cs), in.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_in_num_chunks 8 __builtin_offsetof(union __C(drm_amdgpu_cs), in.num_chunks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_out 0 __builtin_offsetof(union __C(drm_amdgpu_cs), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_cs_out_handle 0 __builtin_offsetof(union __C(drm_amdgpu_cs), out.handle)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_drm_amdgpu_userq 72 sizeof(union __C(drm_amdgpu_userq))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_drm_amdgpu_userq 8 __alignof(union __C(drm_amdgpu_userq))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in 0 __builtin_offsetof(union __C(drm_amdgpu_userq), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_doorbell_handle 12 __builtin_offsetof(union __C(drm_amdgpu_userq), in.doorbell_handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_doorbell_offset 16 __builtin_offsetof(union __C(drm_amdgpu_userq), in.doorbell_offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_flags 20 __builtin_offsetof(union __C(drm_amdgpu_userq), in.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_ip_type 8 __builtin_offsetof(union __C(drm_amdgpu_userq), in.ip_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_mqd 56 __builtin_offsetof(union __C(drm_amdgpu_userq), in.mqd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_mqd_size 64 __builtin_offsetof(union __C(drm_amdgpu_userq), in.mqd_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_op 0 __builtin_offsetof(union __C(drm_amdgpu_userq), in.op)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_id 4 __builtin_offsetof(union __C(drm_amdgpu_userq), in.queue_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_size 32 __builtin_offsetof(union __C(drm_amdgpu_userq), in.queue_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_queue_va 24 __builtin_offsetof(union __C(drm_amdgpu_userq), in.queue_va)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_rptr_va 40 __builtin_offsetof(union __C(drm_amdgpu_userq), in.rptr_va)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_in_wptr_va 48 __builtin_offsetof(union __C(drm_amdgpu_userq), in.wptr_va)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_out 0 __builtin_offsetof(union __C(drm_amdgpu_userq), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_out__pad 4 __builtin_offsetof(union __C(drm_amdgpu_userq), out._pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_userq_out_queue_id 0 __builtin_offsetof(union __C(drm_amdgpu_userq), out.queue_id)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_drm_amdgpu_wait_fences 24 sizeof(union __C(drm_amdgpu_wait_fences))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_drm_amdgpu_wait_fences 8 __alignof(union __C(drm_amdgpu_wait_fences))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in 0 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_fence_count 8 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), in.fence_count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_fences 0 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), in.fences)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_timeout_ns 16 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), in.timeout_ns)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_in_wait_all 12 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), in.wait_all)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_out 0 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), out)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_out_first_signaled 4 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), out.first_signaled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_amdgpu_wait_fences_out_status 0 __builtin_offsetof(union __C(drm_amdgpu_wait_fences), out.status)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_drm_wait_vblank 24 sizeof(union __C(drm_wait_vblank))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_drm_wait_vblank 8 __alignof(union __C(drm_wait_vblank))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_reply 0 __builtin_offsetof(union __C(drm_wait_vblank), reply)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_reply_sequence 4 __builtin_offsetof(union __C(drm_wait_vblank), reply.sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_reply_tval_sec 8 __builtin_offsetof(union __C(drm_wait_vblank), reply.tval_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_reply_tval_usec 16 __builtin_offsetof(union __C(drm_wait_vblank), reply.tval_usec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_reply_type 0 __builtin_offsetof(union __C(drm_wait_vblank), reply.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request 0 __builtin_offsetof(union __C(drm_wait_vblank), request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_sequence 4 __builtin_offsetof(union __C(drm_wait_vblank), request.sequence)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_signal 8 __builtin_offsetof(union __C(drm_wait_vblank), request.signal)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_drm_wait_vblank_request_type 0 __builtin_offsetof(union __C(drm_wait_vblank), request.type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_fw_cdev_event 56 sizeof(union __C(fw_cdev_event))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_fw_cdev_event 8 __alignof(union __C(fw_cdev_event))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset 0 __builtin_offsetof(union __C(fw_cdev_event), bus_reset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_bm_node_id 20 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.bm_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_closure 0 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_generation 32 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_irm_node_id 24 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.irm_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_local_node_id 16 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.local_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_node_id 12 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_root_node_id 28 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.root_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_bus_reset_type 8 __builtin_offsetof(union __C(fw_cdev_event), bus_reset.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_common 0 __builtin_offsetof(union __C(fw_cdev_event), common)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_common_closure 0 __builtin_offsetof(union __C(fw_cdev_event), common.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_common_type 8 __builtin_offsetof(union __C(fw_cdev_event), common.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt 0 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_closure 0 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_cycle 12 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt.cycle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_header 20 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt.header)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_header_length 16 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt.header_length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_type 8 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc 0 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt_mc)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_closure 0 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt_mc.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_completed 12 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt_mc.completed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_interrupt_mc_type 8 __builtin_offsetof(union __C(fw_cdev_event), iso_interrupt_mc.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource 0 __builtin_offsetof(union __C(fw_cdev_event), iso_resource)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_bandwidth 20 __builtin_offsetof(union __C(fw_cdev_event), iso_resource.bandwidth)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_channel 16 __builtin_offsetof(union __C(fw_cdev_event), iso_resource.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_closure 0 __builtin_offsetof(union __C(fw_cdev_event), iso_resource.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_handle 12 __builtin_offsetof(union __C(fw_cdev_event), iso_resource.handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_iso_resource_type 8 __builtin_offsetof(union __C(fw_cdev_event), iso_resource.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet 0 __builtin_offsetof(union __C(fw_cdev_event), phy_packet)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_closure 0 __builtin_offsetof(union __C(fw_cdev_event), phy_packet.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_data 20 __builtin_offsetof(union __C(fw_cdev_event), phy_packet.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_length 16 __builtin_offsetof(union __C(fw_cdev_event), phy_packet.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_rcode 12 __builtin_offsetof(union __C(fw_cdev_event), phy_packet.rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet_type 8 __builtin_offsetof(union __C(fw_cdev_event), phy_packet.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2 0 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_closure 0 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_data 24 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_length 16 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_rcode 12 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_tstamp 20 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_phy_packet2_type 8 __builtin_offsetof(union __C(fw_cdev_event), phy_packet2.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request 0 __builtin_offsetof(union __C(fw_cdev_event), request)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_closure 0 __builtin_offsetof(union __C(fw_cdev_event), request.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_data 32 __builtin_offsetof(union __C(fw_cdev_event), request.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_handle 24 __builtin_offsetof(union __C(fw_cdev_event), request.handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_length 28 __builtin_offsetof(union __C(fw_cdev_event), request.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_offset 16 __builtin_offsetof(union __C(fw_cdev_event), request.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_tcode 12 __builtin_offsetof(union __C(fw_cdev_event), request.tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request_type 8 __builtin_offsetof(union __C(fw_cdev_event), request.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2 0 __builtin_offsetof(union __C(fw_cdev_event), request2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_card 32 __builtin_offsetof(union __C(fw_cdev_event), request2.card)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_closure 0 __builtin_offsetof(union __C(fw_cdev_event), request2.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_data 48 __builtin_offsetof(union __C(fw_cdev_event), request2.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_destination_node_id 28 __builtin_offsetof(union __C(fw_cdev_event), request2.destination_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_generation 36 __builtin_offsetof(union __C(fw_cdev_event), request2.generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_handle 40 __builtin_offsetof(union __C(fw_cdev_event), request2.handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_length 44 __builtin_offsetof(union __C(fw_cdev_event), request2.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_offset 16 __builtin_offsetof(union __C(fw_cdev_event), request2.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_source_node_id 24 __builtin_offsetof(union __C(fw_cdev_event), request2.source_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_tcode 12 __builtin_offsetof(union __C(fw_cdev_event), request2.tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request2_type 8 __builtin_offsetof(union __C(fw_cdev_event), request2.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3 0 __builtin_offsetof(union __C(fw_cdev_event), request3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_card 32 __builtin_offsetof(union __C(fw_cdev_event), request3.card)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_closure 0 __builtin_offsetof(union __C(fw_cdev_event), request3.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_data 56 __builtin_offsetof(union __C(fw_cdev_event), request3.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_destination_node_id 28 __builtin_offsetof(union __C(fw_cdev_event), request3.destination_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_generation 36 __builtin_offsetof(union __C(fw_cdev_event), request3.generation)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_handle 40 __builtin_offsetof(union __C(fw_cdev_event), request3.handle)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_length 44 __builtin_offsetof(union __C(fw_cdev_event), request3.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_offset 16 __builtin_offsetof(union __C(fw_cdev_event), request3.offset)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_padding 52 __builtin_offsetof(union __C(fw_cdev_event), request3.padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_source_node_id 24 __builtin_offsetof(union __C(fw_cdev_event), request3.source_node_id)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_tcode 12 __builtin_offsetof(union __C(fw_cdev_event), request3.tcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_tstamp 48 __builtin_offsetof(union __C(fw_cdev_event), request3.tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_request3_type 8 __builtin_offsetof(union __C(fw_cdev_event), request3.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response 0 __builtin_offsetof(union __C(fw_cdev_event), response)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_closure 0 __builtin_offsetof(union __C(fw_cdev_event), response.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_data 20 __builtin_offsetof(union __C(fw_cdev_event), response.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_length 16 __builtin_offsetof(union __C(fw_cdev_event), response.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_rcode 12 __builtin_offsetof(union __C(fw_cdev_event), response.rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response_type 8 __builtin_offsetof(union __C(fw_cdev_event), response.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2 0 __builtin_offsetof(union __C(fw_cdev_event), response2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_closure 0 __builtin_offsetof(union __C(fw_cdev_event), response2.closure)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_data 32 __builtin_offsetof(union __C(fw_cdev_event), response2.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_length 16 __builtin_offsetof(union __C(fw_cdev_event), response2.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_padding 28 __builtin_offsetof(union __C(fw_cdev_event), response2.padding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_rcode 12 __builtin_offsetof(union __C(fw_cdev_event), response2.rcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_request_tstamp 20 __builtin_offsetof(union __C(fw_cdev_event), response2.request_tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_response_tstamp 24 __builtin_offsetof(union __C(fw_cdev_event), response2.response_tstamp)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_fw_cdev_event_response2_type 8 __builtin_offsetof(union __C(fw_cdev_event), response2.type)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_inputArgs 192 sizeof(union __C(inputArgs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_inputArgs 8 __alignof(union __C(inputArgs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access 0 __builtin_offsetof(union __C(inputArgs), coda_access)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_access.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_access.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_flags 36 __builtin_offsetof(union __C(inputArgs), coda_access.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih 0 __builtin_offsetof(union __C(inputArgs), coda_access.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_access.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_access.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_access.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_access.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_access.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent 0 __builtin_offsetof(union __C(inputArgs), coda_access_intent)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_access_intent.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_access_intent.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_count 36 __builtin_offsetof(union __C(inputArgs), coda_access_intent.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih 0 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_access_intent.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_pos 40 __builtin_offsetof(union __C(inputArgs), coda_access_intent.pos)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_access_intent_type 44 __builtin_offsetof(union __C(inputArgs), coda_access_intent.type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close 0 __builtin_offsetof(union __C(inputArgs), coda_close)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_close.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_close.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_flags 36 __builtin_offsetof(union __C(inputArgs), coda_close.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih 0 __builtin_offsetof(union __C(inputArgs), coda_close.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_close.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_close.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_close.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_close.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_close_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_close.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create 0 __builtin_offsetof(union __C(inputArgs), coda_create)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_create.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_create.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr 40 __builtin_offsetof(union __C(inputArgs), coda_create.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_atime 88 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_atime_tv_nsec 96 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_atime_tv_sec 88 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_blocksize 80 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_bytes 160 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_ctime 120 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_ctime_tv_nsec 128 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_ctime_tv_sec 120 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_fileid 64 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_filerev 168 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_flags 144 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_gen 136 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_gid 56 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_mode 48 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_mtime 104 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_mtime_tv_nsec 112 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_mtime_tv_sec 104 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_nlink 50 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_rdev 152 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_size 72 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_type 40 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_attr_va_uid 52 __builtin_offsetof(union __C(inputArgs), coda_create.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_excl 176 __builtin_offsetof(union __C(inputArgs), coda_create.excl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih 0 __builtin_offsetof(union __C(inputArgs), coda_create.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_create.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_create.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_create.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_create.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_create.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_mode 180 __builtin_offsetof(union __C(inputArgs), coda_create.mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_create_name 184 __builtin_offsetof(union __C(inputArgs), coda_create.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync 0 __builtin_offsetof(union __C(inputArgs), coda_fsync)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_fsync.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_fsync.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih 0 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_fsync_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_fsync.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr 0 __builtin_offsetof(union __C(inputArgs), coda_getattr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_getattr.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_getattr.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih 0 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_getattr_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_getattr.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl 0 __builtin_offsetof(union __C(inputArgs), coda_ioctl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_ioctl.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_ioctl.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_cmd 36 __builtin_offsetof(union __C(inputArgs), coda_ioctl.cmd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_data 48 __builtin_offsetof(union __C(inputArgs), coda_ioctl.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih 0 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_ioctl.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_len 40 __builtin_offsetof(union __C(inputArgs), coda_ioctl.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_ioctl_rwflag 44 __builtin_offsetof(union __C(inputArgs), coda_ioctl.rwflag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link 0 __builtin_offsetof(union __C(inputArgs), coda_link)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_destFid 36 __builtin_offsetof(union __C(inputArgs), coda_link.destFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_destFid_opaque 36 __builtin_offsetof(union __C(inputArgs), coda_link.destFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih 0 __builtin_offsetof(union __C(inputArgs), coda_link.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_link.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_link.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_link.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_link.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_link.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_sourceFid 20 __builtin_offsetof(union __C(inputArgs), coda_link.sourceFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_sourceFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_link.sourceFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_link_tname 52 __builtin_offsetof(union __C(inputArgs), coda_link.tname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup 0 __builtin_offsetof(union __C(inputArgs), coda_lookup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_lookup.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_lookup.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_flags 40 __builtin_offsetof(union __C(inputArgs), coda_lookup.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih 0 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_lookup.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_lookup_name 36 __builtin_offsetof(union __C(inputArgs), coda_lookup.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir 0 __builtin_offsetof(union __C(inputArgs), coda_mkdir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_mkdir.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_mkdir.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr 40 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_atime 88 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_atime_tv_nsec 96 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_atime_tv_sec 88 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_blocksize 80 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_bytes 160 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_ctime 120 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_ctime_tv_nsec 128 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_ctime_tv_sec 120 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_fileid 64 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_filerev 168 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_flags 144 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_gen 136 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_gid 56 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_mode 48 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_mtime 104 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_mtime_tv_nsec 112 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_mtime_tv_sec 104 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_nlink 50 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_rdev 152 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_size 72 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_type 40 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_attr_va_uid 52 __builtin_offsetof(union __C(inputArgs), coda_mkdir.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih 0 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_mkdir.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_mkdir_name 176 __builtin_offsetof(union __C(inputArgs), coda_mkdir.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open 0 __builtin_offsetof(union __C(inputArgs), coda_open)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_open.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_open.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_flags 36 __builtin_offsetof(union __C(inputArgs), coda_open.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih 0 __builtin_offsetof(union __C(inputArgs), coda_open.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_open.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_open.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_open.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_open.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_open.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_flags 36 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_fd_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_open_by_fd.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_flags 36 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_open_by_path_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_open_by_path.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink 0 __builtin_offsetof(union __C(inputArgs), coda_readlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_readlink.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_readlink.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih 0 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_readlink_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_readlink.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release 0 __builtin_offsetof(union __C(inputArgs), coda_release)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_release.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_release.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_flags 36 __builtin_offsetof(union __C(inputArgs), coda_release.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih 0 __builtin_offsetof(union __C(inputArgs), coda_release.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_release.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_release.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_release.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_release.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_release_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_release.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove 0 __builtin_offsetof(union __C(inputArgs), coda_remove)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_remove.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_remove.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih 0 __builtin_offsetof(union __C(inputArgs), coda_remove.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_remove.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_remove.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_remove.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_remove.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_remove.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_remove_name 36 __builtin_offsetof(union __C(inputArgs), coda_remove.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename 0 __builtin_offsetof(union __C(inputArgs), coda_rename)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_destFid 40 __builtin_offsetof(union __C(inputArgs), coda_rename.destFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_destFid_opaque 40 __builtin_offsetof(union __C(inputArgs), coda_rename.destFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_destname 56 __builtin_offsetof(union __C(inputArgs), coda_rename.destname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih 0 __builtin_offsetof(union __C(inputArgs), coda_rename.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_rename.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_rename.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_rename.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_rename.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_rename.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_sourceFid 20 __builtin_offsetof(union __C(inputArgs), coda_rename.sourceFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_sourceFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_rename.sourceFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rename_srcname 36 __builtin_offsetof(union __C(inputArgs), coda_rename.srcname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir 0 __builtin_offsetof(union __C(inputArgs), coda_rmdir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_rmdir.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_rmdir.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih 0 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_rmdir.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_rmdir_name 36 __builtin_offsetof(union __C(inputArgs), coda_rmdir.name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr 0 __builtin_offsetof(union __C(inputArgs), coda_setattr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_setattr.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_setattr.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr 40 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_atime 88 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_atime_tv_nsec 96 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_atime_tv_sec 88 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_blocksize 80 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_bytes 160 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_ctime 120 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_ctime_tv_nsec 128 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_ctime_tv_sec 120 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_fileid 64 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_filerev 168 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_flags 144 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_gen 136 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_gid 56 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_mode 48 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_mtime 104 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_mtime_tv_nsec 112 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_mtime_tv_sec 104 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_nlink 50 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_rdev 152 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_size 72 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_type 40 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_attr_va_uid 52 __builtin_offsetof(union __C(inputArgs), coda_setattr.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih 0 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_setattr_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_setattr.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs 0 __builtin_offsetof(union __C(inputArgs), coda_statfs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in 0 __builtin_offsetof(union __C(inputArgs), coda_statfs.in)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_statfs.in.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_statfs.in.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in_pid 8 __builtin_offsetof(union __C(inputArgs), coda_statfs.in.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in_uid 16 __builtin_offsetof(union __C(inputArgs), coda_statfs.in.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_statfs_in_unique 4 __builtin_offsetof(union __C(inputArgs), coda_statfs.in.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store 0 __builtin_offsetof(union __C(inputArgs), coda_store)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_store.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_store.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_flags 36 __builtin_offsetof(union __C(inputArgs), coda_store.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih 0 __builtin_offsetof(union __C(inputArgs), coda_store.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_store.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_store.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_store.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_store.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_store_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_store.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink 0 __builtin_offsetof(union __C(inputArgs), coda_symlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_symlink.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_symlink.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr 40 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_atime 88 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_atime_tv_nsec 96 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_atime_tv_sec 88 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_blocksize 80 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_bytes 160 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_ctime 120 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_ctime_tv_nsec 128 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_ctime_tv_sec 120 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_fileid 64 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_filerev 168 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_flags 144 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_gen 136 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_gid 56 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_mode 48 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_mtime 104 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_mtime_tv_nsec 112 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_mtime_tv_sec 104 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_nlink 50 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_rdev 152 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_size 72 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_type 40 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_attr_va_uid 52 __builtin_offsetof(union __C(inputArgs), coda_symlink.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih 0 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_symlink.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_srcname 36 __builtin_offsetof(union __C(inputArgs), coda_symlink.srcname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_symlink_tname 176 __builtin_offsetof(union __C(inputArgs), coda_symlink.tname)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget 0 __builtin_offsetof(union __C(inputArgs), coda_vget)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_VFid 20 __builtin_offsetof(union __C(inputArgs), coda_vget.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_VFid_opaque 20 __builtin_offsetof(union __C(inputArgs), coda_vget.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih 0 __builtin_offsetof(union __C(inputArgs), coda_vget.ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), coda_vget.ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), coda_vget.ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih_pid 8 __builtin_offsetof(union __C(inputArgs), coda_vget.ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih_uid 16 __builtin_offsetof(union __C(inputArgs), coda_vget.ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_coda_vget_ih_unique 4 __builtin_offsetof(union __C(inputArgs), coda_vget.ih.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih 0 __builtin_offsetof(union __C(inputArgs), ih)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih_opcode 0 __builtin_offsetof(union __C(inputArgs), ih.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih_pgid 12 __builtin_offsetof(union __C(inputArgs), ih.pgid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih_pid 8 __builtin_offsetof(union __C(inputArgs), ih.pid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih_uid 16 __builtin_offsetof(union __C(inputArgs), ih.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_inputArgs_ih_unique 4 __builtin_offsetof(union __C(inputArgs), ih.unique)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_iwreq_data 16 sizeof(union __C(iwreq_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_iwreq_data 8 __alignof(union __C(iwreq_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_addr 0 __builtin_offsetof(union __C(iwreq_data), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_ap_addr 0 __builtin_offsetof(union __C(iwreq_data), ap_addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_bitrate 0 __builtin_offsetof(union __C(iwreq_data), bitrate)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_bitrate_disabled 5 __builtin_offsetof(union __C(iwreq_data), bitrate.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_bitrate_fixed 4 __builtin_offsetof(union __C(iwreq_data), bitrate.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_bitrate_flags 6 __builtin_offsetof(union __C(iwreq_data), bitrate.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_bitrate_value 0 __builtin_offsetof(union __C(iwreq_data), bitrate.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_data 0 __builtin_offsetof(union __C(iwreq_data), data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_data_flags 10 __builtin_offsetof(union __C(iwreq_data), data.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_data_length 8 __builtin_offsetof(union __C(iwreq_data), data.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_data_pointer 0 __builtin_offsetof(union __C(iwreq_data), data.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_encoding 0 __builtin_offsetof(union __C(iwreq_data), encoding)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_encoding_flags 10 __builtin_offsetof(union __C(iwreq_data), encoding.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_encoding_length 8 __builtin_offsetof(union __C(iwreq_data), encoding.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_encoding_pointer 0 __builtin_offsetof(union __C(iwreq_data), encoding.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_essid 0 __builtin_offsetof(union __C(iwreq_data), essid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_essid_flags 10 __builtin_offsetof(union __C(iwreq_data), essid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_essid_length 8 __builtin_offsetof(union __C(iwreq_data), essid.length)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_essid_pointer 0 __builtin_offsetof(union __C(iwreq_data), essid.pointer)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_frag 0 __builtin_offsetof(union __C(iwreq_data), frag)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_frag_disabled 5 __builtin_offsetof(union __C(iwreq_data), frag.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_frag_fixed 4 __builtin_offsetof(union __C(iwreq_data), frag.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_frag_flags 6 __builtin_offsetof(union __C(iwreq_data), frag.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_frag_value 0 __builtin_offsetof(union __C(iwreq_data), frag.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_freq 0 __builtin_offsetof(union __C(iwreq_data), freq)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_freq_e 4 __builtin_offsetof(union __C(iwreq_data), freq.e)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_freq_flags 7 __builtin_offsetof(union __C(iwreq_data), freq.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_freq_i 6 __builtin_offsetof(union __C(iwreq_data), freq.i)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_freq_m 0 __builtin_offsetof(union __C(iwreq_data), freq.m)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_mode 0 __builtin_offsetof(union __C(iwreq_data), mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_name 0 __builtin_offsetof(union __C(iwreq_data), name)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_nwid 0 __builtin_offsetof(union __C(iwreq_data), nwid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_nwid_disabled 5 __builtin_offsetof(union __C(iwreq_data), nwid.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_nwid_fixed 4 __builtin_offsetof(union __C(iwreq_data), nwid.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_nwid_flags 6 __builtin_offsetof(union __C(iwreq_data), nwid.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_nwid_value 0 __builtin_offsetof(union __C(iwreq_data), nwid.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_param 0 __builtin_offsetof(union __C(iwreq_data), param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_param_disabled 5 __builtin_offsetof(union __C(iwreq_data), param.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_param_fixed 4 __builtin_offsetof(union __C(iwreq_data), param.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_param_flags 6 __builtin_offsetof(union __C(iwreq_data), param.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_param_value 0 __builtin_offsetof(union __C(iwreq_data), param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_power 0 __builtin_offsetof(union __C(iwreq_data), power)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_power_disabled 5 __builtin_offsetof(union __C(iwreq_data), power.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_power_fixed 4 __builtin_offsetof(union __C(iwreq_data), power.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_power_flags 6 __builtin_offsetof(union __C(iwreq_data), power.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_power_value 0 __builtin_offsetof(union __C(iwreq_data), power.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_qual 0 __builtin_offsetof(union __C(iwreq_data), qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_qual_level 1 __builtin_offsetof(union __C(iwreq_data), qual.level)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_qual_noise 2 __builtin_offsetof(union __C(iwreq_data), qual.noise)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_qual_qual 0 __builtin_offsetof(union __C(iwreq_data), qual.qual)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_qual_updated 3 __builtin_offsetof(union __C(iwreq_data), qual.updated)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_retry 0 __builtin_offsetof(union __C(iwreq_data), retry)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_retry_disabled 5 __builtin_offsetof(union __C(iwreq_data), retry.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_retry_fixed 4 __builtin_offsetof(union __C(iwreq_data), retry.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_retry_flags 6 __builtin_offsetof(union __C(iwreq_data), retry.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_retry_value 0 __builtin_offsetof(union __C(iwreq_data), retry.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_rts 0 __builtin_offsetof(union __C(iwreq_data), rts)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_rts_disabled 5 __builtin_offsetof(union __C(iwreq_data), rts.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_rts_fixed 4 __builtin_offsetof(union __C(iwreq_data), rts.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_rts_flags 6 __builtin_offsetof(union __C(iwreq_data), rts.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_rts_value 0 __builtin_offsetof(union __C(iwreq_data), rts.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_sens 0 __builtin_offsetof(union __C(iwreq_data), sens)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_sens_disabled 5 __builtin_offsetof(union __C(iwreq_data), sens.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_sens_fixed 4 __builtin_offsetof(union __C(iwreq_data), sens.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_sens_flags 6 __builtin_offsetof(union __C(iwreq_data), sens.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_sens_value 0 __builtin_offsetof(union __C(iwreq_data), sens.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_txpower 0 __builtin_offsetof(union __C(iwreq_data), txpower)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_txpower_disabled 5 __builtin_offsetof(union __C(iwreq_data), txpower.disabled)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_txpower_fixed 4 __builtin_offsetof(union __C(iwreq_data), txpower.fixed)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_txpower_flags 6 __builtin_offsetof(union __C(iwreq_data), txpower.flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_iwreq_data_txpower_value 0 __builtin_offsetof(union __C(iwreq_data), txpower.value)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_outputArgs 168 sizeof(union __C(outputArgs))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_outputArgs 8 __alignof(union __C(outputArgs))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create 0 __builtin_offsetof(union __C(outputArgs), coda_create)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_VFid 12 __builtin_offsetof(union __C(outputArgs), coda_create.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_VFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_create.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr 32 __builtin_offsetof(union __C(outputArgs), coda_create.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_atime 80 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_atime_tv_nsec 88 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_atime_tv_sec 80 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_blocksize 72 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_bytes 152 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_ctime 112 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_ctime_tv_nsec 120 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_ctime_tv_sec 112 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_fileid 56 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_filerev 160 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_flags 136 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_gen 128 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_gid 48 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_mode 40 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_mtime 96 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_mtime_tv_nsec 104 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_mtime_tv_sec 96 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_nlink 42 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_rdev 144 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_size 64 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_type 32 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_attr_va_uid 44 __builtin_offsetof(union __C(outputArgs), coda_create.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_oh 0 __builtin_offsetof(union __C(outputArgs), coda_create.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_create.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_create.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_create_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_create.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr 0 __builtin_offsetof(union __C(outputArgs), coda_getattr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr 16 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_atime 64 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_atime_tv_nsec 72 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_atime_tv_sec 64 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_blocksize 56 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_bytes 136 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_ctime 96 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_ctime_tv_nsec 104 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_ctime_tv_sec 96 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_fileid 40 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_filerev 144 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_flags 120 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_gen 112 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_gid 32 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_mode 24 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_mtime 80 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_mtime_tv_nsec 88 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_mtime_tv_sec 80 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_nlink 26 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_rdev 128 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_size 48 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_type 16 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_attr_va_uid 28 __builtin_offsetof(union __C(outputArgs), coda_getattr.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_oh 0 __builtin_offsetof(union __C(outputArgs), coda_getattr.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_getattr.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_getattr.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_getattr_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_getattr.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl 0 __builtin_offsetof(union __C(outputArgs), coda_ioctl)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_data 16 __builtin_offsetof(union __C(outputArgs), coda_ioctl.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_len 12 __builtin_offsetof(union __C(outputArgs), coda_ioctl.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_oh 0 __builtin_offsetof(union __C(outputArgs), coda_ioctl.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_ioctl.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_ioctl.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_ioctl_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_ioctl.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup 0 __builtin_offsetof(union __C(outputArgs), coda_lookup)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_VFid 12 __builtin_offsetof(union __C(outputArgs), coda_lookup.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_VFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_lookup.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_oh 0 __builtin_offsetof(union __C(outputArgs), coda_lookup.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_lookup.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_lookup.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_lookup.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_lookup_vtype 28 __builtin_offsetof(union __C(outputArgs), coda_lookup.vtype)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir 0 __builtin_offsetof(union __C(outputArgs), coda_mkdir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_VFid 12 __builtin_offsetof(union __C(outputArgs), coda_mkdir.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_VFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_mkdir.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr 32 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_atime 80 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_atime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_atime_tv_nsec 88 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_atime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_atime_tv_sec 80 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_atime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_blocksize 72 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_blocksize)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_bytes 152 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_bytes)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_ctime 112 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_ctime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_ctime_tv_nsec 120 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_ctime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_ctime_tv_sec 112 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_ctime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_fileid 56 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_fileid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_filerev 160 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_filerev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_flags 136 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_flags)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_gen 128 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_gen)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_gid 48 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_gid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_mode 40 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_mode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_mtime 96 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_mtime)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_mtime_tv_nsec 104 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_mtime.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_mtime_tv_sec 96 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_mtime.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_nlink 42 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_nlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_rdev 144 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_rdev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_size 64 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_size)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_type 32 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_type)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_attr_va_uid 44 __builtin_offsetof(union __C(outputArgs), coda_mkdir.attr.va_uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_oh 0 __builtin_offsetof(union __C(outputArgs), coda_mkdir.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_mkdir.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_mkdir.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_mkdir_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_mkdir.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open 0 __builtin_offsetof(union __C(outputArgs), coda_open)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_dev 16 __builtin_offsetof(union __C(outputArgs), coda_open.dev)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_inode 24 __builtin_offsetof(union __C(outputArgs), coda_open.inode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_oh 0 __builtin_offsetof(union __C(outputArgs), coda_open.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_open.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_open.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_open.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_fd 12 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.fd)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_fh 16 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.fh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_oh 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_fd_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_open_by_fd.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path_oh 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_path.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_open_by_path.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_open_by_path.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_open_by_path.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_open_by_path_path 12 __builtin_offsetof(union __C(outputArgs), coda_open_by_path.path)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid 0 __builtin_offsetof(union __C(outputArgs), coda_purgefid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_CodaFid 12 __builtin_offsetof(union __C(outputArgs), coda_purgefid.CodaFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_CodaFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_purgefid.CodaFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_oh 0 __builtin_offsetof(union __C(outputArgs), coda_purgefid.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_purgefid.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_purgefid.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgefid_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_purgefid.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser 0 __builtin_offsetof(union __C(outputArgs), coda_purgeuser)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser_oh 0 __builtin_offsetof(union __C(outputArgs), coda_purgeuser.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_purgeuser.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_purgeuser.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_purgeuser.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_purgeuser_uid 12 __builtin_offsetof(union __C(outputArgs), coda_purgeuser.uid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink 0 __builtin_offsetof(union __C(outputArgs), coda_readlink)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_count 12 __builtin_offsetof(union __C(outputArgs), coda_readlink.count)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_data 16 __builtin_offsetof(union __C(outputArgs), coda_readlink.data)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_oh 0 __builtin_offsetof(union __C(outputArgs), coda_readlink.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_readlink.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_readlink.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_readlink_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_readlink.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace 0 __builtin_offsetof(union __C(outputArgs), coda_replace)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_NewFid 12 __builtin_offsetof(union __C(outputArgs), coda_replace.NewFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_NewFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_replace.NewFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_OldFid 28 __builtin_offsetof(union __C(outputArgs), coda_replace.OldFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_OldFid_opaque 28 __builtin_offsetof(union __C(outputArgs), coda_replace.OldFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_oh 0 __builtin_offsetof(union __C(outputArgs), coda_replace.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_replace.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_replace.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_replace_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_replace.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root 0 __builtin_offsetof(union __C(outputArgs), coda_root)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_VFid 12 __builtin_offsetof(union __C(outputArgs), coda_root.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_VFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_root.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_oh 0 __builtin_offsetof(union __C(outputArgs), coda_root.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_root.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_root.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_root_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_root.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs 0 __builtin_offsetof(union __C(outputArgs), coda_statfs)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_oh 0 __builtin_offsetof(union __C(outputArgs), coda_statfs.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_statfs.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_statfs.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_statfs.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat 12 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat_f_bavail 20 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat.f_bavail)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat_f_bfree 16 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat.f_bfree)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat_f_blocks 12 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat.f_blocks)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat_f_ffree 28 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat.f_ffree)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_statfs_stat_f_files 24 __builtin_offsetof(union __C(outputArgs), coda_statfs.stat.f_files)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget 0 __builtin_offsetof(union __C(outputArgs), coda_vget)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_VFid 12 __builtin_offsetof(union __C(outputArgs), coda_vget.VFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_VFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_vget.VFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_oh 0 __builtin_offsetof(union __C(outputArgs), coda_vget.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_vget.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_vget.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_vget.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_vget_vtype 28 __builtin_offsetof(union __C(outputArgs), coda_vget.vtype)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir 0 __builtin_offsetof(union __C(outputArgs), coda_zapdir)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_CodaFid 12 __builtin_offsetof(union __C(outputArgs), coda_zapdir.CodaFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_CodaFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_zapdir.CodaFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_oh 0 __builtin_offsetof(union __C(outputArgs), coda_zapdir.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_zapdir.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_zapdir.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapdir_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_zapdir.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile 0 __builtin_offsetof(union __C(outputArgs), coda_zapfile)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_CodaFid 12 __builtin_offsetof(union __C(outputArgs), coda_zapfile.CodaFid)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_CodaFid_opaque 12 __builtin_offsetof(union __C(outputArgs), coda_zapfile.CodaFid.opaque)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_oh 0 __builtin_offsetof(union __C(outputArgs), coda_zapfile.oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), coda_zapfile.oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_oh_result 8 __builtin_offsetof(union __C(outputArgs), coda_zapfile.oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_coda_zapfile_oh_unique 4 __builtin_offsetof(union __C(outputArgs), coda_zapfile.oh.unique)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_oh 0 __builtin_offsetof(union __C(outputArgs), oh)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_oh_opcode 0 __builtin_offsetof(union __C(outputArgs), oh.opcode)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_oh_result 8 __builtin_offsetof(union __C(outputArgs), oh.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_outputArgs_oh_unique 4 __builtin_offsetof(union __C(outputArgs), oh.unique)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_semun 8 sizeof(union __C(semun))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_semun 8 __alignof(union __C(semun))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semun___buf 0 __builtin_offsetof(union __C(semun), __buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semun___pad 0 __builtin_offsetof(union __C(semun), __pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semun_array 0 __builtin_offsetof(union __C(semun), array)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semun_buf 0 __builtin_offsetof(union __C(semun), buf)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_semun_val 0 __builtin_offsetof(union __C(semun), val)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_sigval 8 sizeof(union __C(sigval))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_sigval 8 __alignof(union __C(sigval))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigval_sival_int 0 __builtin_offsetof(union __C(sigval), sival_int)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_sigval_sival_ptr 0 __builtin_offsetof(union __C(sigval), sival_ptr)"
	#NO_APP
	#APP

	.ascii	"->SIZEOF_union_snd_seq_event_data 12 sizeof(union __C(snd_seq_event_data))"
	#NO_APP
	#APP

	.ascii	"->ALIGNOF_union_snd_seq_event_data 4 __alignof(union __C(snd_seq_event_data))"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr 0 __builtin_offsetof(union __C(snd_seq_event_data), addr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr_client 0 __builtin_offsetof(union __C(snd_seq_event_data), addr.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_addr_port 1 __builtin_offsetof(union __C(snd_seq_event_data), addr.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect 0 __builtin_offsetof(union __C(snd_seq_event_data), connect)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest 2 __builtin_offsetof(union __C(snd_seq_event_data), connect.dest)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest_client 2 __builtin_offsetof(union __C(snd_seq_event_data), connect.dest.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_dest_port 3 __builtin_offsetof(union __C(snd_seq_event_data), connect.dest.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender 0 __builtin_offsetof(union __C(snd_seq_event_data), connect.sender)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender_client 0 __builtin_offsetof(union __C(snd_seq_event_data), connect.sender.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_connect_sender_port 1 __builtin_offsetof(union __C(snd_seq_event_data), connect.sender.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control 0 __builtin_offsetof(union __C(snd_seq_event_data), control)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_channel 0 __builtin_offsetof(union __C(snd_seq_event_data), control.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_param 4 __builtin_offsetof(union __C(snd_seq_event_data), control.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused1 1 __builtin_offsetof(union __C(snd_seq_event_data), control.unused1)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused2 2 __builtin_offsetof(union __C(snd_seq_event_data), control.unused2)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_unused3 3 __builtin_offsetof(union __C(snd_seq_event_data), control.unused3)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_control_value 8 __builtin_offsetof(union __C(snd_seq_event_data), control.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext 0 __builtin_offsetof(union __C(snd_seq_event_data), ext)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext_len 0 __builtin_offsetof(union __C(snd_seq_event_data), ext.len)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ext_ptr 4 __builtin_offsetof(union __C(snd_seq_event_data), ext.ptr)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note 0 __builtin_offsetof(union __C(snd_seq_event_data), note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_channel 0 __builtin_offsetof(union __C(snd_seq_event_data), note.channel)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_duration 4 __builtin_offsetof(union __C(snd_seq_event_data), note.duration)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_note 1 __builtin_offsetof(union __C(snd_seq_event_data), note.note)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_off_velocity 3 __builtin_offsetof(union __C(snd_seq_event_data), note.off_velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_note_velocity 2 __builtin_offsetof(union __C(snd_seq_event_data), note.velocity)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue 0 __builtin_offsetof(union __C(snd_seq_event_data), queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_pad 1 __builtin_offsetof(union __C(snd_seq_event_data), queue.pad)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_d32 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.d32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_d8 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.d8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_position 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.position)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.skew)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew_base 8 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.skew.base)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_skew_value 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.skew.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_tick 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time_tv_nsec 8 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_time_time_tv_sec 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_param_value 4 __builtin_offsetof(union __C(snd_seq_event_data), queue.param.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_queue_queue 0 __builtin_offsetof(union __C(snd_seq_event_data), queue.queue)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote 0 __builtin_offsetof(union __C(snd_seq_event_data), quote)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_event 4 __builtin_offsetof(union __C(snd_seq_event_data), quote.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin 0 __builtin_offsetof(union __C(snd_seq_event_data), quote.origin)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin_client 0 __builtin_offsetof(union __C(snd_seq_event_data), quote.origin.client)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_origin_port 1 __builtin_offsetof(union __C(snd_seq_event_data), quote.origin.port)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_quote_value 2 __builtin_offsetof(union __C(snd_seq_event_data), quote.value)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw32 0 __builtin_offsetof(union __C(snd_seq_event_data), raw32)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw32_d 0 __builtin_offsetof(union __C(snd_seq_event_data), raw32.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw8 0 __builtin_offsetof(union __C(snd_seq_event_data), raw8)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_raw8_d 0 __builtin_offsetof(union __C(snd_seq_event_data), raw8.d)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result 0 __builtin_offsetof(union __C(snd_seq_event_data), result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result_event 0 __builtin_offsetof(union __C(snd_seq_event_data), result.event)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_result_result 4 __builtin_offsetof(union __C(snd_seq_event_data), result.result)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time 0 __builtin_offsetof(union __C(snd_seq_event_data), time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_tick 0 __builtin_offsetof(union __C(snd_seq_event_data), time.tick)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time 0 __builtin_offsetof(union __C(snd_seq_event_data), time.time)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time_tv_nsec 4 __builtin_offsetof(union __C(snd_seq_event_data), time.time.tv_nsec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_time_time_tv_sec 0 __builtin_offsetof(union __C(snd_seq_event_data), time.time.tv_sec)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify 0 __builtin_offsetof(union __C(snd_seq_event_data), ump_notify)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify_block 1 __builtin_offsetof(union __C(snd_seq_event_data), ump_notify.block)"
	#NO_APP
	#APP

	.ascii	"->OFFSETOF_TAG_snd_seq_event_data_ump_notify_client 0 __builtin_offsetof(union __C(snd_seq_event_data), ump_notify.client)"
	#NO_APP
	ld	ra, 8(sp)                       # 8-byte Folded Reload
	ld	s0, 0(sp)                       # 8-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	asm_offsets, .Lfunc_end0-asm_offsets
                                        # -- End function
	.ident	"clang version 18.0.0 (ssh://git@gitlab.codasip.com/cheri/software/bakewell/cherillvm.git c6c0d5f86de3d5e25ca52f191fc003df301ad541)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
