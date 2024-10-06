/**
 * @file usart.h
 * @brief USART interface to be able to print to serial port.
 *
 * USART for Atmega328pb
 *
 * @author Nasar Eddaoui, Nathan Nguyen (edited 05/10/24)
 * @link https://github.com/Nasar165/ATMEGA328-UART/blob/main/src/usart.h
 * @date 13/04/21
 */

/*  TODO: Fix PCB / Schematic

    Currently using pin PD0 amd PD1 for LoRa Radio but we need it for Tx and Rx,
   especially for debugging.

*/

#ifndef USART_H
#define USART_H

#include <stdio.h>

#include "config.h"

// ***********************************************************************************************
#define UBRR ((F_CPU / (BAUD_RATE * 16UL)) - 1)

/* USART Configuration */
#define USART_MODE_ASYNC (0 << UMSEL01) | (0 << UMSEL00)
#define USART_PARITY_NONE (0 << UPM01) | (0 << UPM00)
#define USART_STOP_BITS_1 (0 << USBS0)
#define USART_DATA_BITS_8 (1 << UCSZ01) | (1 << UCSZ00)

#define USART_CONFIG \
  (USART_MODE_ASYNC | USART_PARITY_NONE | USART_STOP_BITS_1 | USART_DATA_BITS_8)

// ***********************************************************************************************

void USART_Init(void);
char USART_Recieve(void);
int USART_Transmit(char, FILE*);

#endif  // USART_H