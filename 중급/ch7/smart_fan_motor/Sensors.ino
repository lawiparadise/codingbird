void initMPU() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void getADC() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();
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
