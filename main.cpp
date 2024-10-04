/**
 * @file main.cpp
 * @brief The entry to my code base
 *
 * @author Nathan Nguyen
 *
 * @date 05/10/24
 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "adc.h"
#include "config.h"
#include "power.h"
#include "usart.h"

int main(void) {
  USART_Init();

  ADC_Init();
  ADC_Enable(ADC2_PIN);

  printf("Setup Complete\n");

  Sleep_Init();

  while (1) {
    float battery_voltage = ADC_ReadVoltage(ADC2_PIN);
    
    if (battery_voltage >= VOLTAGE_THRESHOLD) {
      printf("Battery voltage above threshold. Staying awake.\n");
      _delay_ms(1000);
    } else {
      printf("Entering sleep mode...\n");
      Sleep_Enable();
    }
  }
  return 0;
}