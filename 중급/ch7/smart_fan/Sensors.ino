void initIR() {
  sensor.init();
  sensor.setTimeout(500);
  sensor.setSignalRateLimit(0.1);
  sensor.setVcselPulsePeriod(
    VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(
    VL53L0X::VcselPeriodFinalRange, 14);
}

void evaluateIR() {
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
}
