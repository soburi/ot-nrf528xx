/**
 * configuration for ms88sf2pi board https://github.com/soburi/ms88sf2pi_board
 * Use -imacros option to including. such like
 *
 * CFLAGS="-imacros `pwd`/ms88sf2pi_config.h" ./script/build nrf52840 SPI_trans_NCP
 */

#pragma once
#define UART_HWFC_ENABLED 0
#define UART_PIN_TX 9
#define UART_PIN_RX 10
#define SPIS_PIN_MOSI 24
#define SPIS_PIN_MISO 22
#define SPIS_PIN_SCK 20
#define SPIS_PIN_CSN 13
#define SPIS_PIN_HOST_IRQ 15
