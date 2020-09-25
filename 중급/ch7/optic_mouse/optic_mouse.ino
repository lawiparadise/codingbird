#include "Bitcraze_PMW3901.h"
#include<Mouse.h>

Bitcraze_PMW3901 flow(20);

int16_t deltaX, deltaY;

void setup() {
  Serial.begin(9600);
  if (!flow.begin()) {
    Serial.println("connection fail");
    while (1);
  }
  Mouse.begin();
}

void loop() {
  flow.readMotionCount(&deltaX, &deltaY);

  Serial.print(-deltaX);
  Serial.print(",");
  Serial.print(deltaY);
  Serial.println();

  Mouse.move(-deltaX, -deltaY, 0);
}
