#
# Copyright (c) 2021, Nordic Semiconductor ASA
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of Nordic Semiconductor ASA nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
#


#add_library(nrf-802154-platform STATIC EXCLUDE_FROM_ALL)
add_library(nrf-802154-platform)

target_compile_definitions(nrf-802154-platform
    PUBLIC
        -DNRF52840_XXAA
)

target_include_directories(nrf-802154-platform
    PUBLIC
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52840/config
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/cmsis
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/experimental_section_vars
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/log
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/strerror
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/util
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/clock
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/common
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/power
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/systick
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/usbd
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/dependencies/legacy
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/hal
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/drivers
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/drivers/include
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/mdk
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/soc
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/softdevice/s140/headers
        ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/softdevice/s140/headers/nrf52
	${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/mpsl/include

)

target_link_libraries(nrf-802154-platform
  PRIVATE
     nrf-802154-driver-interface
     ot-config
)

target_sources(nrf-802154-platform
  PRIVATE
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/gpiote/nrf_802154_gpiote_none.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/gpiote/nrf_802154_gpiote_crit_sect.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/clock/nrf_802154_clock.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/clock/nrf_802154_clock_mpsl.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/lp_timer/nrf_802154_lp_timer.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/lp_timer/nrf_802154_lp_timer_none.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/hp_timer/nrf_802154_hp_timer.c
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/sdk-nrfxlib/nrf_802154/sl/platform/irq/nrf_802154_irq_baremetal.c
    tick.c
)

