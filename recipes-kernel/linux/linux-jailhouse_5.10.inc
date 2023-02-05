#
# Jailhouse, a Linux-based partitioning hypervisor
#
# Copyright (c) Siemens AG, 2018-2021
#
# Authors:
#  Jan Kiszka <jan.kiszka@siemens.com>
#
# SPDX-License-Identifier: MIT
#

require recipes-kernel/linux/linux-custom.inc

KERNEL_DEFCONFIG ?= "${DISTRO_ARCH}_defconfig_5.10"

SRC_URI += " \
    git://github.com/KurtZou/linux-jailhouse-enabling-5.10;protocol=https;branch=kurt-dev-PURETEST \
    file://0001-ARM-dts-orange-pi-zero-Adjust-wifi-settings.patch \
    file://0001-pwrseq_simple-Workaround-for-missing-device-tree-ent.patch \
    file://0012-arm64-dts-Add-support-for-Avnet-Ultra96-rev2-board.patch \
    file://0001-Revert-arm64-dts-xilinx-Remove-dtsi-for-fixed-clock.patch \
    file://0002-Revert-arm64-dts-xilinx-Add-the-clock-nodes-for-zynq.patch \
    file://${KERNEL_DEFCONFIG}"

S = "${WORKDIR}/git"

KBUILD_DEPENDS += "liblz4-tool"
