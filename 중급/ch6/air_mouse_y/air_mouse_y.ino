#include<Wire.h>
#include<Mouse.h>

#define MPU_ADDR 0x68
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  initMPU();
  Serial.begin(115200);
  Mouse.begin();
}

void loop() {
  getADC();
  Serial.print("AcY="); Serial.println(AcX);
  if (AcY < -8000) {
    Mouse.move(-5, 0, 0);
  } else if (AcY > 8000) {
    Mouse.move(5, 0, 0);
  }
  if (AcX < -4000) {
    Mouse.move(0, AcX / 800 + 5, 0);
  } else if (AcX > 4000) {
    Mouse.move(0, AcX / 800 - 5, 0);
  }
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
