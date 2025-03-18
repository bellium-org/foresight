/**
 * @file config.h
 * @brief Configuration file for the project
 *
 * This file contains various configuration macros and definitions
 * used throughout the project.
 *
 * @author Nathan Nguyen
 * @date 26/02/25
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define BAUD_RATE 115200

/* NMOS Switch */
#define DEVICE_SW PIN_PE0

/* LoRa Transceiver */
#define DIO0 PIN_PD0
#define SCK0 PIN_PB5
#define MISO0 PIN_PB4
#define MOSI0 PIN_PB3
#define NSS0 PIN_PB2

/* Accelerometer */
#define SCK1 PIN_PC1
#define MISO1 PIN_PC0
#define MOSI1 PIN_PE3
#define NSS1 PIN_PE2

#endif  // CONFIG_H