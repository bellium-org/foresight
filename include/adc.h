/**
 * @file adc.h
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

/*  RESEARCH (Pg. 300)
    https://ww1.microchip.com/downloads/en/DeviceDoc/40001906A.pdf

    Using Task 1: PC2, Task 2: PC3

    PC2 = ADC2 = 0010
    PC3 = ADC3 = 0011

    <avr/iom328.h> Shows all ports and pins
*/

#ifndef ADC_H
#define ADC_H

#include <avr/interrupt.h>
#include <avr/io.h>

#include "config.h"

// ***********************************************************************************************
#define ADC_VOLT(x) (x * (5.0 / 1024.0))

// ***********************************************************************************************
enum {
  ADC0_PIN,
  ADC1_PIN,
  ADC2_PIN,
  ADC3_PIN,
  ADC4_PIN,
  ADC5_PIN,
  ADC6_PIN,
  ADC7_PIN,
  ADC8_TEMPERATURE,
  ADC_1V1 = 0b1110,
  ADC_GND,
};

// ***********************************************************************************************
void ADC_Init(void) {
  ADMUX |= 0b01 << REFS0;
  ADCSRA |= 1 << ADEN | 1 << ADIE | 0b111 << ADPS0;
}

void ADC_Enable(uint8_t pin) { DIDR0 |= 1 << pin; }

void ADC_Disable(uint8_t pin) { DIDR0 &= ~(1 << pin); }

void ADC_Select(uint8_t source) {
  ADMUX &= 0xF0;
  ADMUX |= source;
}

uint16_t ADC_Convert(void) {
  ADCSRA |= (1 << ADSC);

  while (ADCSRA & (1 << ADSC)) {
  }

  uint16_t result = ADC;

  return result;
}

float ADC_ReadVoltage(uint8_t pin) {
  ADC_Select(pin);
  uint16_t raw_value = ADC_Convert();
  return ADC_VOLT(raw_value);
}

#endif  // ADC_H