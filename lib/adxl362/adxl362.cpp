#include <adxl362.h>

int16_t csPin = ADXL362_CS_PIN;

ADXL362::ADXL362() {}

bool ADXL362::initialise(int16_t chipSelectPin)
{
    csPin = chipSelectPin;
    pinMode(csPin, OUTPUT);
    SPI1.begin();
    SPI1.setDataMode(SPI_MODE0); // SPI Mode 0 (CPHA = 0, CPOL = 0)
    delay(1000);

    writeRegister(ADXL362_SOFT_RESET, 0x52);
    delay(10); // Latency of 0.5 ms needed after soft reset

    byte device_id = readRegister(ADXL362_DEVID_AD);
    Serial.println(device_id);
    if (device_id != 0xAD)
    {
        Serial.println("Device ID Incorrect");
        return false;
    }

    return true;
}

void ADXL362::startMeasurement()
{
    byte regValue = readRegister(ADXL362_POWER_CTL);
    regValue |= 0x02;
    writeRegister(ADXL362_POWER_CTL, regValue);
    delay(10);
}

int8_t ADXL362::getX()
{
    return readRegister(ADXL362_XDATA);
}

int8_t ADXL362::getY()
{
    return readRegister(ADXL362_YDATA);
}

int8_t ADXL362::getZ()
{
    return readRegister(ADXL362_ZDATA);
}

void ADXL362::getXYZ(int8_t &x, int8_t &y, int8_t &z)
{
    // Burst SPI read: reading all sensor data in one transaction ensures all data is time-correlated.
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_READ_REG); // Read instruction
    SPI1.transfer(ADXL362_XDATA);  // Start at XDATA register

    x = SPI1.transfer(0x00);
    y = SPI1.transfer(0x00);
    z = SPI1.transfer(0x00);
    digitalWrite(csPin, HIGH);
}


int16_t ADXL362::getX16()
{
    return readRegister16(ADXL362_XDATA_L);
}

int16_t ADXL362::getY16()
{
    return readRegister16(ADXL362_YDATA_L);
}

int16_t ADXL362::getZ16()
{
    return readRegister16(ADXL362_ZDATA_L);
}

void ADXL362::getXYZ16(int16_t &x, int16_t &y, int16_t &z)
{
    // Burst SPI read: reading all sensor data in one transaction ensures all data is time-correlated.
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_READ_REG); 
    SPI1.transfer(ADXL362_XDATA_L);

    x = SPI1.transfer(0x00);
    x |= (SPI1.transfer(0x00) << 8);

    y = SPI1.transfer(0x00);
    y |= (SPI1.transfer(0x00) << 8);

    z = SPI1.transfer(0x00);
    z |= (SPI1.transfer(0x00) << 8);

    digitalWrite(csPin, HIGH);
}

/* Low-Level SPI Register Functions */
byte ADXL362::readRegister(byte regAddress)
{
    byte regValue = 0;
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_READ_REG);
    SPI1.transfer(regAddress);
    regValue = SPI1.transfer(0x00);
    digitalWrite(csPin, HIGH);
    return regValue;
}

void ADXL362::writeRegister(byte regAddress, byte regValue)
{
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_WRITE_REG);
    SPI1.transfer(regAddress);
    SPI1.transfer(regValue);
    digitalWrite(csPin, HIGH);
}

int16_t ADXL362::readRegister16(byte regAddress)
{
    int16_t value = 0;
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_READ_REG);
    SPI1.transfer(regAddress);
    value = SPI1.transfer(0x00);
    value |= (SPI1.transfer(0x00) << 8);
    digitalWrite(csPin, HIGH);
    return value;
}

void ADXL362::writeRegister16(byte regAddress, int16_t value)
{
    byte valueLSB = value & 0xFF;
    byte valueMSB = (value >> 8) & 0xFF;
    digitalWrite(csPin, LOW);
    SPI1.transfer(ADXL362_WRITE_REG);
    SPI1.transfer(regAddress);
    SPI1.transfer(valueLSB);
    SPI1.transfer(valueMSB);
    digitalWrite(csPin, HIGH);
}
