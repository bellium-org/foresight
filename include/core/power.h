/**
 * @file power.h
 * @brief Power Management / Sleep Mode 
 *
 * Deals the decision making behind the systems power down mode. 
 * This uses a watchdog interrupt to wake up the system in a given time interval.
 * This time interval is dynamic and changes based on the ADC value measured from the energy storage (Super Capacitor / Battery)
 *
 * @author Nathan Nguyen 
 * @date 05/10/24
 */

#ifndef POWER_H
#define POWER_H

#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <stdio.h>

#include "adc.h"

/*  TODO: Fix the dynamic sleep wakeup
    Currently goes into sleep mode

    Must measure power consumption

*/

// #define VOLTAGE_THRESHOLD 4.0f
// #define MIN_SLEEP_TIME WDTO_1S
// #define MAX_SLEEP_TIME WDTO_8S

// volatile uint8_t current_sleep_time = WDTO_1S;

// void Sleep_Init() {
//     set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Put into power down mode with
//     wdt enabled sleep_enable(); wdt_enable(current_sleep_time); WDTCSR |= (1
//     << WDIE);
// }

// void Sleep_Enable() {
//     sleep_mode();
//     sleep_disable();
//     wdt_reset();
// }

// void Sleep_UpdateTimer(float voltage) {
//     if (voltage >= VOLTAGE_THRESHOLD) {
//         current_sleep_time = WDTO_1S;
//     } else {
//         float percentage = voltage / VOLTAGE_THRESHOLD;

//         if (percentage < 0.25) {
//             current_sleep_time = WDTO_8S;
//         } else if (percentage < 0.5) {
//             current_sleep_time = WDTO_4S;
//         } else if (percentage < 0.75) {
//             current_sleep_time = WDTO_2S;
//         } else {
//             current_sleep_time = WDTO_1S;
//         }
//     }

//     wdt_enable(current_sleep_time);
// }

// ISR(WDT_vect) {
//     /* On Wakeup Please Check Voltage Levels */
//     float capacitor_voltage = ADC_ReadVoltage(ADC2_PIN);
//     Sleep_UpdateTimer(capacitor_voltage);
// }

#endif  // POWER_H