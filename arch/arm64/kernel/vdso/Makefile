# SPDX-License-Identifier: GPL-2.0
#
# Building a vDSO image for AArch64.
#
# Author: Will Deacon <will.deacon@arm.com>
# Heavily based on the vDSO Makefiles for other archs.
#

# Include the generic Makefile to check the built vdso.
include $(srctree)/lib/vdso/Makefile.include

obj-vdso := vgettimeofday.o note.o sigreturn.o vgetrandom.o vgetrandom-chacha.o

# Build rules
targets := $(obj-vdso) vdso.so vdso.so.dbg

btildflags-$(CONFIG_ARM64_BTI_KERNEL) += -z force-bti

# -Bsymbolic has been added for consistency with arm, the compat vDSO and
# potential future proofing if we end up with internal calls to the exported
# routines, as x86 does (see 6f121e548f83 ("x86, vdso: Reimplement vdso.so
# preparation in build-time C")).
ldflags-y := -shared -soname=linux-vdso.so.1 \
	     -Bsymbolic --build-id=sha1 -n $(btildflags-y)

ifdef CONFIG_LD_ORPHAN_WARN
  ldflags-y += --orphan-handling=$(CONFIG_LD_ORPHAN_WARN_LEVEL)
endif

ldflags-y += -T

ccflags-y := -fno-common -fno-builtin -fno-stack-protector -ffixed-x18
ccflags-y += -DDISABLE_BRANCH_PROFILING -DBUILD_VDSO

# When building for PCuABI, this Makefile will be called twice: first to build
# the regular arm64 vDSO, and second to build the purecap vDSO. We must change
# certain variables/flags depending on which vDSO we are building.
ifdef BUILD_PURECAP_VDSO
  # Specify building for purecap
  PURECAP_FLAGS := -mabi=purecap
  # Remove this flag as capability registers are not considered
  # as general purpose registers by the compiler.
  REMOVE_FLAGS := -mgeneral-regs-only
  ccflags-y += $(PURECAP_FLAGS)
  asflags-y := $(PURECAP_FLAGS)
  ccflags-remove-y := $(REMOVE_FLAGS)
  asflags-remove-y := $(REMOVE_FLAGS)

  # We want the purecap vDSO in its own directory (kernel/vdso/purecap)
  targets := $(addprefix purecap/, $(targets))
  output-dir := $(obj)/purecap
  # Put the offsets for the purecap vDSO into their own header file
  offsets := include/generated/vdso-purecap-offsets.h
else
  output-dir := $(obj)
  offsets := include/generated/vdso-offsets.h
endif

# -Wmissing-prototypes and -Wmissing-declarations are removed from
# the CFLAGS to make possible to build the kernel with CONFIG_WERROR enabled.
CC_FLAGS_REMOVE_VDSO := $(CC_FLAGS_FTRACE) -Os $(CC_FLAGS_SCS) \
			$(RANDSTRUCT_CFLAGS) $(KSTACK_ERASE_CFLAGS) \
			$(GCC_PLUGINS_CFLAGS) \
			$(CC_FLAGS_LTO) $(CC_FLAGS_CFI) \
			-Wmissing-prototypes -Wmissing-declarations

CC_FLAGS_ADD_VDSO := -O2 -mcmodel=tiny -fasynchronous-unwind-tables

CFLAGS_REMOVE_vgettimeofday.o = $(CC_FLAGS_REMOVE_VDSO)
CFLAGS_REMOVE_purecap/vgettimeofday.o = $(CFLAGS_REMOVE_vgettimeofday.o)
CFLAGS_REMOVE_vgetrandom.o = $(CC_FLAGS_REMOVE_VDSO)
CFLAGS_REMOVE_purecap/vgetrandom.o = $(CFLAGS_REMOVE_vgetrandom.o) -O2

CFLAGS_vgettimeofday.o = $(CC_FLAGS_ADD_VDSO)
CFLAGS_vgetrandom.o = $(CC_FLAGS_ADD_VDSO)

ifneq ($(c-gettimeofday-y),)
  CFLAGS_vgettimeofday.o += -include $(c-gettimeofday-y)
endif

ifneq ($(c-getrandom-y),)
  CFLAGS_vgetrandom.o += -include $(c-getrandom-y)
endif

CFLAGS_purecap/vgettimeofday.o = $(CFLAGS_vgettimeofday.o)
CFLAGS_purecap/vgetrandom.o = $(CFLAGS_vgetrandom.o) -O1

targets += vdso.lds
CPPFLAGS_vdso.lds += -P -C -U$(ARCH)

obj-vdso := $(addprefix $(output-dir)/, $(obj-vdso))

#Make the purecap directory under vdso/
$(output-dir):
ifdef BUILD_PURECAP_VDSO
	@mkdir -p $(output-dir)
endif

# Explicit build rules are required for .o files when building for purecap,
# as the path to the output directory for built objects no longer matches
# the path to the source files.
ifdef BUILD_PURECAP_VDSO
$(output-dir)/%.o: $(srctree)/$(src)/%.c FORCE | $(output-dir)
	$(call if_changed_rule,cc_o_c)

$(output-dir)/%.o: $(srctree)/$(src)/%.S FORCE | $(output-dir)
	$(call if_changed_rule,as_o_S)
endif

# Link rule for the .so file, .lds has to be first
$(output-dir)/vdso.so.dbg: $(obj)/vdso.lds $(obj-vdso) FORCE
	$(call if_changed,vdsold_and_vdso_check)

# Strip rule for the .so file
$(output-dir)/%.so: OBJCOPYFLAGS := -S
$(output-dir)/%.so: $(output-dir)/%.so.dbg FORCE
	$(call if_changed,objcopy)

# Generate VDSO offsets using helper script
gen-vdsosym := $(src)/gen_vdso_offsets.sh
quiet_cmd_vdsosym = VDSOSYM $@
      cmd_vdsosym = $(NM) $< | $(gen-vdsosym) | LC_ALL=C sort > $@

$(offsets): $(output-dir)/vdso.so.dbg FORCE
	$(call if_changed,vdsosym)

# Actual build commands
quiet_cmd_vdsold_and_vdso_check = LD      $@
# FIXCHERI: Disable vdso checking for now.
#     cmd_vdsold_and_vdso_check = $(cmd_ld); $(cmd_vdso_check)
      cmd_vdsold_and_vdso_check = $(cmd_ld)
