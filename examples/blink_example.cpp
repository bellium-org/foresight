/**
 * @file blink_example.cpp
 * @brief The hello world of embedded systems (Blink LED)
 *
 * @author Nathan Nguyen
 *
 * @date 05/10/24
 */

#include <util/delay.h>

#include "config.h"

int main(void) {
  LED_Init();

  while (1) {
    LED_Toggle();
    _delay_ms(BLINK_DELAY_MS);
  }
}
