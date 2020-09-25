#include <VL53L0X.h>
#include <Adafruit_DotStar.h>
#include <Wire.h>

VL53L0X sensor;
Adafruit_DotStar GRB = Adafruit_DotStar(2);

int rangeCnt = 0;
boolean SW = false;
boolean thumbOut = true;
