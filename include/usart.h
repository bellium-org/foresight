/**
 * @file usart.h
 * @brief USART interface to be able print to serial port.
 *
 * USART for Atmega328p
 *
 * @author Nasar Eddaoui, Nathan Nguyen (edited 05/10/24)
 * @link https://github.com/Nasar165/ATMEGA328-UART/blob/main/src/usart.h
 * @date 13/04/21
 */

#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

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
extern FILE usart_stdout;

void USART_Init(void) {
  // Set Baud rate
  UBRR0H = (UBRR >> 8);
  UBRR0L = UBRR;

  UCSR0C = USART_CONFIG;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  fdev_setup_stream(&usart_stdout, USART_Transmit, NULL, _FDEV_SETUP_WRITE);
  stdout = &usart_stdout;
}

char USART_Recieve(void) {
  // Wait for the Buffer to fill
  loop_until_bit_is_set(UCSR0A, RXC0);
  return UDR0;
}

int USART_Transmit(char c, FILE *stream) {
  if (c == '\n') USART_Transmit('\r', stream);
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

#endif  // USART_H