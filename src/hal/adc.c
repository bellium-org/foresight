/**
 * @file adc.cpp
 * @brief Analog to digital converter for the MCU
 *
 * Need this for two tasks:
 *  - 1: Measure voltage across energy source (super capacitor / battery)
 * (System Board)
 *  - 2: Measure the magnetic field strength using an op amp (Energy Harvester
 * Board)
 *
 * @author Nathan Nguyen
 * @date 05/10/24
 */

#include "adc.h"

#include <avr/interrupt.h>
#include <avr/io.h>

void ADC_Init(void) {
  ADMUX |= 0b01 << REFS0;
  ADCSRA |= 1 << ADEN | 1 << ADIE | 0b111 << ADPS0;
}

void ADC_Enable(adc_channel_t pin) { DIDR0 |= 1 << pin; }

void ADC_Disable(adc_channel_t pin) { DIDR0 &= ~(1 << pin); }

void ADC_Select(adc_channel_t pin) {
  ADMUX &= 0xF0;
  ADMUX |= pin;
}

uint16_t ADC_Convert(void) {
  ADCSRA |= (1 << ADSC);

  while (ADCSRA & (1 << ADSC)) {
  }

  uint16_t result = ADC;

  return result;
}

float ADC_ReadVoltage(adc_channel_t pin) {
  ADC_Select(pin);
  uint16_t raw_value = ADC_Convert();
  return ADC_VOLT(raw_value);
}