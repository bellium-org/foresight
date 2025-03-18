#ifndef ADXL362_SENSOR_H
#define ADXL362_SENSOR_H

#include <Arduino.h>
#include <SPI1.h>

#define ADXL362_CS_PIN PIN_PE2

// SPI Start Byte
#define ADXL362_WRITE_REG 0x0A
#define ADXL362_READ_REG 0x0B
#define ADXL362_READ_FIFO 0x0D

// Device Identification
#define ADXL362_DEVID_AD 0x00
#define ADXL362_DEVID_MST 0x01
#define ADXL362_PARTID 0x02
#define ADXL362_REVID 0x03

// Data Registers
#define ADXL362_XDATA 0x08
#define ADXL362_YDATA 0x09
#define ADXL362_ZDATA 0x0A 

// Status Register
#define ADXL362_STATUS 0x0B 

// Burst Read Data Registers
#define ADXL362_XDATA_L 0x0E 
#define ADXL362_XDATA_H 0x0F
#define ADXL362_YDATA_L 0x10 
#define ADXL362_YDATA_H 0x11 
#define ADXL362_ZDATA_L 0x12 
#define ADXL362_ZDATA_H 0x13

// Soft Reset
#define ADXL362_SOFT_RESET 0x1F
#define ADXL362_FILTER_CTL 0x2C

// Power Control
#define ADXL362_POWER_CTL 0x2D

// Self-Test
#define ADXL362_SELF_TEST 0x2E

class ADXL362
{
public:
    ADXL362();

    bool initialise(int16_t chipSelectPin = ADXL362_CS_PIN);
    void startMeasurement();

    // 8-bit resolution
    int8_t getX();
    int8_t getY();
    int8_t getZ();
    void getXYZ(int8_t &x, int8_t &y, int8_t &z);

    byte readRegister(byte regAddress);
    void writeRegister(byte regAddress, byte regValue);

    // 12-bit resolution
    int16_t getX16();
    int16_t getY16();
    int16_t getZ16();
    void getXYZ16(int16_t &x, int16_t &y, int16_t &z);

    int16_t readRegister16(byte regAddress);
    void writeRegister16(byte regAddress, int16_t value);
};

#endif