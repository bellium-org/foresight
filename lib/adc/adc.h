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
*/

#ifndef ADC_H
#define ADC_H

#define ADC_RESOLUTION 10 // Bits
#define REFERENCE_VOLTAGE 3.3F

#include <Arduino.h>

/**
 * @brief Initialises the ADC system.
 * Configures ADC settings for energy source and magnetic field strength measurements.
 */
void initialiseADC();

/**
 * @brief Reads the voltage of the energy source.
 * 
 * @return float - The voltage at the energy source.
 */
float readVoltage();

/**
 * @brief Reads the magnetic field strength.
 * 
 * @return float - The magnetic field strength.
 */
float readMagneticField(); // TODO (Nathan): May need a op-amp to level shift to be able to read micro voltage levels for conversions.

#endif
