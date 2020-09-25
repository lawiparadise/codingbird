#include<Wire.h>
#include <TimerThree.h>
#include <Adafruit_DotStar.h>

#define MPU_ADDR 0x68

Adafruit_DotStar GRB = Adafruit_DotStar(2);

unsigned long alertTime = 0;

int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
double angleAcX, angleAcY, angleAcZ;
double angleGyX, angleGyY, angleGyZ;
double angleFiX, angleFiY, angleFiZ;

const double RADIAN_TO_DEGREE = 180 / 3.14159;
const double DEGREE_PER_SECOND = 32767 / 250;
const double ALPHA = 1 / (1 + 0.004);

unsigned long now = 0;
unsigned long past = 0;
double dt = 0;

double baseAcX, baseAcY, baseAcZ;
double baseGyX, baseGyY, baseGyZ;

void getDT() {
  now = millis();
  dt = (now - past) / 1000.0;
  past = now;
}
