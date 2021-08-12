#
#  Copyright (c) 2020, The OpenThread Authors.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#

set(COMMON_INCLUDES
    ${PROJECT_SOURCE_DIR}/openthread/include
    ${PROJECT_SOURCE_DIR}/openthread/src
    ${PROJECT_SOURCE_DIR}/openthread/src/core
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/include
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/include/platform
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/src
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/src/fal
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/src/mac_features
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/driver/src/mac_features/ack_generator
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/serialization/include/host
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/serialization/include/platform
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/serialization/include/serialization
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/serialization/spinel_base
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/serialization/src/include
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/sl/include
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/sl/include/platform
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/sl/include/rsch
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/sl/include/timer
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor//sdk-nrfxlib/nrf_802154/sl/sl_opensource/include
)

set(EXAMPLE_INCLUDES
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/cmsis
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/experimental_section_vars
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/log
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/strerror
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/components/libraries/util
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/dependencies/legacy
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/drivers/clock
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/hal
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/drivers
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/drivers/include
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/mdk
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/nrfx/soc
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/softdevice/s140/headers
    ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/softdevice/s140/headers/nrf52
)

set(COMMON_FLAG
    -DSPIS_ENABLED=1
    -DSPIS0_ENABLED=1
    -DNRFX_SPIS_ENABLED=1
    -DNRFX_SPIS0_ENABLED=1
    -DCONFIG_GPIO_AS_PINRESET
    -DENABLE_FEM=1
    -DUSE_APP_CONFIG=1
)

set(COMMON_SOURCES
    components/libraries/util/app_util_platform.c
    drivers/clock/nrf_drv_clock.c
    components/libraries/util/app_error.c
    components/libraries/util/app_error_handler_gcc.c
    nrfx/drivers/src/nrfx_clock.c
    nrfx/drivers/src/nrfx_nvmc.c
    nrfx/drivers/src/nrfx_power.c
    nrfx/drivers/src/nrfx_spis.c
    nrfx/drivers/src/nrfx_systick.c
    nrfx/soc/nrfx_atomic.c
)

set(USB_SOURCES
    nrfx/drivers/src/nrfx_usbd.c
)

if(NRF_PLATFORM STREQUAL "nrf52811")
    add_library(nordicsemi-nrf52811-sdk)
    target_compile_definitions(nordicsemi-nrf52811-sdk
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52811_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -D__HEAP_SIZE=0
            -D__STACK_SIZE=2048
    )
    target_include_directories(nordicsemi-nrf52811-sdk
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52811
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52811/config
    )
    set_property(SOURCE nrfx/mdk/gcc_startup_nrf52811.S PROPERTY LANGUAGE C)
    target_sources(nordicsemi-nrf52811-sdk
        PRIVATE
            ${COMMON_SOURCES}
            nrfx/mdk/gcc_startup_nrf52811.S
            nrfx/mdk/system_nrf52811.c
    )
    target_link_libraries(nordicsemi-nrf52811-sdk PRIVATE ot-config)

    add_library(nordicsemi-nrf52811-radio-driver)
    target_compile_definitions(nordicsemi-nrf52811-radio-driver
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52811_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -D__HEAP_SIZE=0
            -D__STACK_SIZE=2048
            -DRAAL_SINGLE_PHY=1
    )
    target_include_directories(nordicsemi-nrf52811-radio-driver
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${OT_PUBLIC_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52811
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52811/config
    )
    target_sources(nordicsemi-nrf52811-radio-driver
        PRIVATE
	empty.c
    )
    target_link_libraries(nordicsemi-nrf52811-radio-driver PRIVATE ot-config nrf-802154-driver nrf-802154-sl)
elseif(NRF_PLATFORM STREQUAL "nrf52833")
    add_library(nordicsemi-nrf52833-sdk)
    target_compile_definitions(nordicsemi-nrf52833-sdk
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52833_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
    )
    target_include_directories(nordicsemi-nrf52833-sdk
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52833
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52833/config
    )
    set_property(SOURCE nrfx/mdk/gcc_startup_nrf52833.S PROPERTY LANGUAGE C)
    target_sources(nordicsemi-nrf52833-sdk
        PRIVATE
            ${COMMON_SOURCES}
            ${USB_SOURCES}
            nrfx/mdk/gcc_startup_nrf52833.S
            nrfx/mdk/system_nrf52833.c
    )
    target_link_libraries(nordicsemi-nrf52833-sdk PRIVATE ot-config nrf-802154-driver nrf-802154-sl)

    add_library(nordicsemi-nrf52833-radio-driver)
    target_compile_definitions(nordicsemi-nrf52833-radio-driver
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52833_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -DRAAL_SINGLE_PHY=1
    )
    target_include_directories(nordicsemi-nrf52833-radio-driver
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${OT_PUBLIC_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52833
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52833/config
    )
    target_sources(nordicsemi-nrf52833-radio-driver
        PRIVATE
	empty.c
    )
    target_link_libraries(nordicsemi-nrf52833-radio-driver PRIVATE ot-config nrf-802154-driver nrf-802154-sl)

    add_library(nordicsemi-nrf52833-radio-driver-softdevice)
    target_compile_definitions(nordicsemi-nrf52833-radio-driver-softdevice
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52833_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -DRAAL_SINGLE_PHY=1
            -DSOFTDEVICE_PRESENT
            -DS140
            -DRAAL_SOFTDEVICE=1
    )
    target_include_directories(nordicsemi-nrf52833-radio-driver-softdevice
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${OT_PUBLIC_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52833
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52833/config
    )
    target_sources(nordicsemi-nrf52833-radio-driver-softdevice
        PRIVATE
	empty.c
    )
    target_link_libraries(nordicsemi-nrf52833-radio-driver-softdevice PRIVATE ot-config nrf-802154-driver nrf-802154-sl)
elseif(NRF_PLATFORM STREQUAL "nrf52840")
    add_library(nordicsemi-nrf52840-sdk)
    target_compile_definitions(nordicsemi-nrf52840-sdk
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52840_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
    )
    target_include_directories(nordicsemi-nrf52840-sdk
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52840/
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52840/config
    )
    set_property(SOURCE nrfx/mdk/gcc_startup_nrf52840.S PROPERTY LANGUAGE C)
    target_sources(nordicsemi-nrf52840-sdk
        PRIVATE
            ${COMMON_SOURCES}
            ${USB_SOURCES}
	    nrfx/mdk/gcc_startup_nrf52840.S
            nrfx/mdk/system_nrf52840.c
    )
    target_link_libraries(nordicsemi-nrf52840-sdk PRIVATE ot-config)

    add_library(nordicsemi-nrf52840-radio-driver)
    target_compile_definitions(nordicsemi-nrf52840-radio-driver
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52840_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -DRAAL_SINGLE_PHY=1
    )
    target_include_directories(nordicsemi-nrf52840-radio-driver
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${OT_PUBLIC_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52840/
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52840/config
    )
    target_sources(nordicsemi-nrf52840-radio-driver
        PRIVATE
	empty.c
    )
    target_link_libraries(nordicsemi-nrf52840-radio-driver PRIVATE ot-config nrf-802154-driver nrf-802154-sl)

    add_library(nordicsemi-nrf52840-radio-driver-softdevice)
    target_compile_definitions(nordicsemi-nrf52840-radio-driver-softdevice
        PRIVATE
            ${COMMON_FLAG}
            -DNRF52840_XXAA
            -DNRF_802154_PROJECT_CONFIG=\"platform-config.h\"
            -DRAAL_SINGLE_PHY=1
            -DSOFTDEVICE_PRESENT
            -DS140
            -DRAAL_SOFTDEVICE=1
    )
    target_include_directories(nordicsemi-nrf52840-radio-driver-softdevice
        PUBLIC
            ${COMMON_INCLUDES}
            ${EXAMPLE_INCLUDES}
            ${OT_PUBLIC_INCLUDES}
            ${PROJECT_SOURCE_DIR}/src/nrf52840/
            ${PROJECT_SOURCE_DIR}/third_party/NordicSemiconductor/config/nrf52840/config
    )
    target_sources(nordicsemi-nrf52840-radio-driver-softdevice
        PRIVATE
	empty.c
    )
    target_link_libraries(nordicsemi-nrf52840-radio-driver-softdevice PRIVATE ot-config nrf-802154-driver nrf-802154-sl nrf-802154-platform)
else()
    message(FATAL_ERROR "Platform unknown: ${NRF_PLATFORM}")
endif()

add_library(nordicsemi-mbedtls INTERFACE)

target_link_libraries(nordicsemi-mbedtls
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedcrypto_shared.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedtls_tls_vanilla.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedtls_x509_vanilla.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedcrypto_cc3xx.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libnrf_cc310_platform_0.9.4.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedcrypto_oberon.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedtls_base_vanilla.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedcrypto_cc3xx.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedtls_base_vanilla.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libmbedcrypto_shared.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/nrf_security/lib/libnrf_cc310_platform_0.9.4.a
)

add_subdirectory(sdk-nrfxlib)
add_subdirectory(sdk-nrfxlib/nrf_802154)
add_subdirectory(sdk-nrfxlib/nrf_802154/sl/platform)
