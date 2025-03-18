#include <Arduino.h>
#include <SPI.h>

#include <adc.h>
#include <adxl362.h>
#include <config.h>
#include <rfm95.h>

ADXL362 adxl;
RFM95 lora(NSS0, DIO0);

int16_t x, y, z; // Note: In mg. Converion to g = / 1000 

void setup() {
    Serial.begin(BAUD_RATE);

    initialiseADC();
    
    pinMode(DEVICE_SW, OUTPUT);
    digitalWrite(DEVICE_SW, HIGH);
    Serial.println("Device Switch ON");

    if (!lora.initialise(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }

    if (!adxl.initialise()) {
        Serial.println("Starting Accelerometer failed!");
        while (1);
    }

    adxl.startMeasurement();
    Serial.println("System Initialised");
}

void loop() {
    // float energyVoltage = readVoltage();
    
    // String voltageStr = String(energyVoltage, 2);
    // lora.sendPacket("Energy Source Voltage: " + voltageStr + " V");
    // delay(5000); 

    adxl.getXYZ16(x, y, z);
    String packet = String(x) + "," + String(y) + "," + String(z);
    Serial.println(packet);
    lora.sendPacket(packet); 
    delay(1000);
}   
