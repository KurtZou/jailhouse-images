#
# Jailhouse, a Linux-based partitioning hypervisor
#
# Copyright (c) Siemens AG, 2018-2020
#
# Authors:
#  Jan Kiszka <jan.kiszka@siemens.com>
#
# SPDX-License-Identifier: MIT
#

require u-boot-${PV}.inc

SRC_URI += "file://0001-adding-d-t3-defconfig.patch"
SRC_URI += "file://dragonresource-t3-rules"

U_BOOT_CONFIG = "dragonresource-t3_defconfig"
U_BOOT_BIN = "u-boot-sunxi-with-spl.bin"

DEBIAN_BUILD_DEPENDS += ", libssl-dev, swig:native, python3-dev:native"

do_prepare_build_append() {
    cp ${WORKDIR}/dragonresource-t3-rules ${S}/debian/rules
}
