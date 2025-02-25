#include <adc.h>

void initialiseADC() {
    analogReference(REFERENCE_VOLTAGE);
    Serial.print("ADC Initialised with resolution: ");
    Serial.println(ADC_RESOLUTION);
}

float readVoltage() {
    int adc = analogRead(PIN_PC2);
    delay(100);
    float voltage = (adc / 1023.0) * REFERENCE_VOLTAGE;
    return voltage;
}

float readMagneticField() {
    int adc = analogRead(PIN_PC3);
    delay(100);
    float voltage = (adc / 1023.0) * REFERENCE_VOLTAGE;
    
    // TODO (Nathan): Convert measured voltage to magnetic field strength

    float magnetic_field = voltage;
    return magnetic_field;
}