#include <VL53L0X.h>
#include <Adafruit_DotStar.h>
#include <Wire.h>

VL53L0X sensor;
Adafruit_DotStar GRB = Adafruit_DotStar(2);

int rangeCnt = 0;
boolean SW = false;
boolean thumbOut = true;

const int MPU_ADDR = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int16_t startTmp;
int16_t diffTmp;

int cnt = 0;
int inBuf[11] = {0, };
int rcSerial[8] = {125, 125, 125, 125, 125, 125, 125, 125};
