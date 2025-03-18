#include <rfm95.h>

RFM95::RFM95(int nss, int dio0) {
    _nss = nss;
    _dio0 = dio0;
}

bool RFM95::initialise(long frequency) {
    pinMode(_nss, OUTPUT);
    pinMode(_dio0, INPUT);

    digitalWrite(_nss, HIGH);

    SPI.begin();

    if (!LoRa.begin(frequency)) {
        Serial.println("LoRa initialisation failed!");
        return false;
    }

    if (!checkVersion(VERSION)) {
        Serial.println("LoRa board detected has a different version number!");
        return false;
    }

    return true;
}

void RFM95::sendPacket(const String &message) {
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    // Serial.print("Sent packet: ");
    // Serial.println(message);
}

uint8_t RFM95::readRegister(uint8_t addr) {
    digitalWrite(_nss, LOW);
    SPI.transfer(addr & 0x7F);
    uint8_t value = SPI.transfer(0x00);
    digitalWrite(_nss, HIGH);
    return value;
}

bool RFM95::checkVersion(uint8_t expected_version) {
    uint8_t version = this->readRegister(0x42);
    Serial.print("LoRa Chip Version: 0x");
    Serial.println(version, HEX);

    if (version == expected_version) {
        Serial.println("RFM95W detected!");
        return true;
    } else {
        Serial.println("RFM95W not detected! Check wiring.");
        return false;
    }
}
