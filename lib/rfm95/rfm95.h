/**
 * @file rfm95.h
 * @brief Responsible for communication to the RFM95 LoRa transceiver module
 * 
 * PINS Connected:
 * - DIO0  PIN_PD0
 * - SCK0  PIN_PB5
 * - MISO0 PIN_PB4
 * - MOSI0 PIN_PB3
 * - NSS0  PIN_PB2
 *
 * @author Nathan Nguyen
 * @date 26/02/25
*/

#ifndef RFM95_H
#define RFM95_H

#include <SPI.h>
#include <LoRa.h>

#define FREQUENCY 915E6 // 915 MHz
#define VERSION 0x12

class RFM95 {
public:
    /**
     * @brief Initialise the select and interrupt pins
     */
    RFM95(int nss, int dio0);

    /**
     * @brief Initialise the LoRa protocol and ensure the device 
     * is correct by comparing the expected version byte. 
     * 
     * @param frequency Transmit frequency in Hertz
     * 
     * @return (bool) If successfully initialised return true else false.
     */
    bool initialise(long frequency);

    /**
     * @brief Send a string packet
     * 
     * @param message The string that is needed to be sent over the air
     */
    void sendPacket(const String &message);

    /**
     * @brief Read the register of the device. 
     * This is mainly used for internal checks. 
     * 
     * @return (uint8_t) The byte from the register
     */
    uint8_t readRegister(uint8_t addr);

    /**
     * @brief Check to ensure the connected device is in fact the RFM95 module. 
     * 
     * @return (bool) If correct version return true else false.
     */
    bool checkVersion(uint8_t expected_version);

private:
    int _nss;
    int _dio0;
};

#endif
