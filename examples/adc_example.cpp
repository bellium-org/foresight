/**
 * @file adc_example.cpp
 * @brief Example usage of the ADC functions
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
#include "usart.h"

int main(void) {
  uint16_t adc2_value = 0;
  uint16_t adc3_value = 0;

  USART_Init();

  ADC_Init();
  ADC_Enable(ADC2_PIN);
  ADC_Enable(ADC3_PIN);

  printf("Setup Complete \n");

  while (1) {
    float adc2 = ADC_ReadVoltage(ADC2_PIN);
    float adc3 = ADC_ReadVoltage(ADC3_PIN);

    printf("Voltage: %.2f V\n", adc2);
    printf("Voltage: %.2f V\n\n", adc3);

    _delay_ms(1000);
  }
  return 0;
}