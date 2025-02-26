#include <Arduino.h>
#include <SPI.h>

#include <adc.h>
#include <config.h>
#include <rfm95.h>

RFM95 lora(NSS0, DIO0);

void setup() {
    Serial.begin(BAUD_RATE);

    initialiseADC();
    
    pinMode(DEVICE_SW, OUTPUT);
    digitalWrite(DEVICE_SW, HIGH);
    Serial.println("Device Switch ON");

    if (!lora.initialiseRFM95(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }

    Serial.println("System Initialised");
}

void loop() {
    float energyVoltage = readVoltage();
    
    String voltageStr = String(energyVoltage, 2);
    lora.sendPacket("Energy Source Voltage: " + voltageStr + " V");
    delay(5000); 
}
