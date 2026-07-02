
# LINUX-CHERI

#######################################################################

THIS BRANCH IS NO LONGER MAINTAINED

Switch to codaip-riscv-7.1

To migrate rebase your codasip-riscv-6.18 based changes onto this
commit and then cherry pick onto codasip-risv-7.1.

#######################################################################

This repository contains a version of the Linux Kernel with CHERI support
for riscv. It is based on the upstream Linux Kernel and the CHERI
modifications made by the ARM morello project
[https://git.morello-project.org/morello/kernel/linux].

The CHERI enabled RISCV kernel uses the CHERI enabled purecap
UABI and the kernel itself runs in capbility mode, too. Support
for legacy non-CHERI aware userland programs is incomplete and
broken at the moment.

The code is under continued active development and the history
is not as clean as it could be. Please expect rebases and history
re-writes.

## Building

You will need a version of LLVM that supports at least Version 0.9.5
of the riscv CHERI specification. Make sure that this compiler is
in your path before other versions of clang.

```
$ PATH=/path/to/cherillvm:$PATH
$ git checkout codasip-cheri-riscv
$ make LLVM=1 ARCH=riscv HOSTCC=/usr/bin/gcc qemu_riscv64cheripc_defconfig
$ make LLVM=1 ARCH=riscv HOSTCC=/usr/bin/gcc all
```

