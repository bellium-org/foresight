/**
 * @file config.h
 * @brief Configuration file for the project
 *
 * This file contains various configuration macros and definitions
 * used throughout the project.
 *
 * @author Nathan Nguyen
 * @date 05/10/24
 */

#ifndef CONFIG_H
#define CONFIG_H

// **********************************************************************
/* CPU Clock Frequency */
#define F_CPU 16000000UL

/* Baud Rate */
#define BAUD_RATE 9600

// *********************************************************************
/* System States */
typedef enum {
  STATE_COLLECT,   // Collecting vibration data from accelerometer
  STATE_PROCESS,   // Processing and analysing the collected data
  STATE_TRANSMIT,  // Transmitting results via LoRa
  STATE_IDLE       // Sleep state when low power
} SystemState;

#endif  // CONFIG_H