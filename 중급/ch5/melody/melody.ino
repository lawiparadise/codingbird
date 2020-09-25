#include <TimerThree.h>

const int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523,
};

void setup() {
}

void loop() {
  for (int i = 0 ; i < 8 ; i++) {
    Timer3.initialize(1000000 / melody[i]);
    Timer3.pwm(5, 10);
    delay(500);
  }
}
