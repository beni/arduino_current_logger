#include <Wire.h>
#include <Adafruit_INA219.h>

// http://www.adafruit.com/products/904
// http://learn.adafruit.com/adafruit-ina219-current-sensor-breakout/overview

Adafruit_INA219 ina219;

void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  ina219.begin();
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Shunt: "); Serial.print(shuntvoltage); Serial.print("mV, ");
  Serial.print("Load: "); Serial.print(loadvoltage); Serial.print("V, ");
  Serial.print("Current: "); Serial.print(current_mA); Serial.print("mA");
  Serial.println("");
  delay(10000);
}
