#include <VL53L0X.h>
#include <Wire.h>

VL53L0X sensor;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  initIR();
}

void loop() {
  int range = sensor.readRangeSingleMillimeters();
  if (range > 0 && range < 2500)
    Serial.println(range);
}

void initIR() {
  sensor.init();
  sensor.setTimeout(500);
  sensor.setSignalRateLimit(0.1);
  sensor.setVcselPulsePeriod(
    VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(
    VL53L0X::VcselPeriodFinalRange, 14);
}
