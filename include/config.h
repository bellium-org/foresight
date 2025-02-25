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

#define BAUD_RATE 115200

typedef enum {
  STATE_COLLECT,   
  STATE_PROCESS, 
  STATE_TRANSMIT,  
  STATE_IDLE      
} SystemState;

#endif  // CONFIG_H