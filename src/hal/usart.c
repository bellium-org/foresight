/**
 * @file usart.cpp
 * @brief USART implementation to be able to print to serial port.
 *
 * USART for Atmega328pb
 *
 * @author Nasar Eddaoui, Nathan Nguyen (edited 06/10/24)
 * @link https://github.com/Nasar165/ATMEGA328-UART/blob/main/src/usart.h
 * @date 13/04/21
 */

/*  TODO: Fix PCB / Schematic

    Currently using pin PD0 amd PD1 for LoRa Radio but we need it for Tx and Rx,
   especially for debugging.

*/

#include "usart.h"

#include <avr/io.h>
#include <util/delay.h>

FILE usart_stdout;

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
  loop_until_bit_is_set(UCSR0A, RXC0);
  return UDR0;
}

int USART_Transmit(char c, FILE *stream) {
  if (c == '\n') USART_Transmit('\r', stream);
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}