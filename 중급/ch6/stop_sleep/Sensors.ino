void getAngle() {
  angleAcY = atan(-AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2)));
  angleAcY *= RADIAN_TO_DEGREE;

  double angleTmp = (GyY - baseGyY) * dt;
  angleTmp /= DEGREE_PER_SECOND;
  angleGyY += angleTmp;

  angleTmp = angleFiY + angleTmp;
  angleFiY = ALPHA * angleTmp + (1.0 - ALPHA) * angleAcY;
  Serial.println(angleFiY);
}

void calibrateSensor() {
  double sumAcX = 0, sumAcY = 0, sumAcZ = 0;
  double sumGyX = 0, sumGyY = 0, sumGyZ = 0;
  getADC();
  for (int i = 0; i < 10 ; i++) {
    getADC();
    sumAcX += AcX; sumAcY += AcY; sumAcZ += AcZ;
    sumGyX += GyX; sumGyY += GyY; sumGyZ += GyZ;
    delay(100);
  }
  baseAcX = sumAcX / 10;
  baseAcY = sumAcY / 10;
  baseAcZ = sumAcZ / 10;
  baseGyX = sumGyX / 10;
  baseGyY = sumGyY / 10;
  baseGyZ = sumGyZ / 10;
}

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
