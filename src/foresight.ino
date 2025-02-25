#include <adc.h>
#include <config.h>
#include <Arduino.h>

void setup() {
    Serial.begin(BAUD_RATE);
    initialiseADC();
    Serial.println("System initialised");
}

void loop() {
    float energyVoltage = readVoltage();
    Serial.print("Energy Source Voltage: ");
    Serial.print(energyVoltage);
    Serial.println(" V");

    delay(1000);  // Wait for 1 second before taking another reading
}