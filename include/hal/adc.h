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

#include <stdint.h>
#include "config.h"

#define ADC_REF_VOLTAGE (5.0f)
#define ADC_RESOLUTION (1024U)
#define ADC_VOLT(X) ((X) * (ADC_REF_VOLTAGE / ADC_RESOLUTION))

/* Pin Channels */
typedef enum {
  ADC0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5,
  ADC6,
  ADC7,
  ADC8_TEMPERATURE,
  ADC_1V1 = 0b1110,
  ADC_GND,
} adc_channel_t;

void ADC_Init(void);
void ADC_Enable(adc_channel_t channel);
void ADC_Disable(adc_channel_t channel);
void ADC_SelectChannel(adc_channel_t channel);
uint16_t ADC_Convert(void);
float ADC_ReadVoltage(adc_channel_t channel);

#endif  // ADC_H