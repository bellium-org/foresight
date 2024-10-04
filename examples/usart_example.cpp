/**
 * @file usart_example.cpp
 * @brief An example of using the usart driver / header
 *
 * @author Nathan Nguyen
 *
 * @date 05/10/24
 */

#include <stdio.h>
#include <util/delay.h>

#include "config.h"
#include "usart.h"

int main(void) {
  USART_Init();

  int i = 1;
  while (1) {
    printf("Hello usart %d %s %p 0x%x\n", 32, "Hello it's me", &i, 255);
    _delay_ms(100);
  }
  return 0;
}