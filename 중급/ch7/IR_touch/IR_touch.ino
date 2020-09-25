#include <VL53L0X.h>
#include <Adafruit_DotStar.h>
#include <Wire.h>

VL53L0X sensor;
Adafruit_DotStar GRB = Adafruit_DotStar(2);

int rangeCnt = 0;
boolean SW = false;
boolean thumbOut = true;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  initIR();
  GRB.begin();
}

void loop() {
  int range = sensor.readRangeSingleMillimeters();

  if (range < 50) {
    rangeCnt++;
    if (rangeCnt > 10) {
      rangeCnt = 0;
      if (thumbOut) {
        SW = !SW;
        thumbOut = false;
      }
    }
  } else {
    thumbOut = true;
  }

  if (SW) GRB.setPixelColor(0, 0, 50, 0);
  else GRB.setPixelColor(0, 0, 0, 0);
  GRB.show();
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
