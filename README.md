# Foresight: Transformer Monitoring System

## Overview
A maintenance free power transformer monitoring system that performs vibration analysis to predict transformer abnormalities.

## Table of Contents

- [Features](#features)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Task Checklist](#task-checklist)

## Features

- Self-sustaining using an energy harvester stored into a super capacitor.
- Two adcs to measure voltage across super capacitor and magnetic field strength
- Variable sleep mode, where system wakes up, through a watchdog interrupt, if the adc measures enough voltage across the super capacitor. If there isn't enough energy available, the watchdog timer time will be dynamically set dependent on the measured voltage.
- LoRa transceiver, used only to transmit data and diagnostics.
- Accelerometer to measure transformer vibrations.
- NMOS fet to turn off power to the lora transceiver and accelerometer when not required.

### Hardware Setup
- [Foresight Processing Board](https://github.com/bellium-org/foresight-processing)


## Software Setup

1. Install [PlatformIO](https://platformio.org/) and configure your IDE.
2. Clone this repository.
3. Install any required libraries as specified in the `platformio.ini` file. 
4. Upload the firmware to the ATmega328PB using the USBasp programmer and ICSP.

## Task Checklist

Here’s a list of tasks that need to be completed for this project:

- [x] Design the Schematic and PCB
- [x] Populate the PCB
- [x] Flash bootloader onto ATmega328pb chip
- [x] Setup uart to be able to connect via serial.
- [x] Measure the voltage and magnetic field strength from the adc.
- [ ] Write the low power sleep mode and wakeup protocol
- [X] Control the NMOS switch
- [X] Interface with the LoRa transceiver (RFM95W)
- [X] Transmit data packets using the LoRa interface
- [ ] Interface with the accelerometer (ADXL362)
- [ ] Read dummy data from the accelerometer
- [ ] Combine the entire system 
- [ ] Test in the lab on a small transformer
- [ ] Test in the field on a real transformer

## Authors
- Nathan Nguyen