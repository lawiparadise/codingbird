#include <TimerThree.h>

boolean SW = false;

void blinkLED() {
  SW = !SW;
  digitalWrite(13, SW);
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Timer3.initialize(3000000); //1000000us = 1s
  Timer3.attachInterrupt(blinkLED);
  Timer3.pwm(5, 10);
}

void loop() {
  Serial.println("5초마다 실행될 문구");
  delay(5000);
}
