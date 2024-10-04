/**
 * @file led.h
 * @brief Simple LED Blink Program
 *
 * This simple header only file interacts with LED on the
 *
 * @author Nathan Nguyen
 * @date 04/10/24
 */

#ifndef LED_H
#define LED_H

#include <avr/io.h>

// ***********************************************************************************************
#define BLINK_DELAY_MS 1000

#define LED_PIN PB5
#define LED_PORT PORTB
#define LED_DDR DDRB

// ***********************************************************************************************
void LED_Init(void) { LED_DDR |= (1 << LED_PIN); }

void LED_Toggle(void) { LED_PORT ^= (1 << LED_PIN); }

#endif  // LED_H