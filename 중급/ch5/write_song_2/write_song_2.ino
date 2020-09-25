#include <TimerThree.h>

const int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523,
};

const int LEN2 = 2000;
const int LEN_DOT2 = 3000;
const int LEN4 = 1000;
const int LEN_DOT4 = 1500;
const int LEN8 = 500;
const int LEN_DOT8 = 750;
const int LEN16 = 250;
const int LEN_DOT16 = 375;

void setup() {

}

void loop() {
  hitNote(melody[5], LEN_DOT8);
  hitNote(melody[4], LEN16);
  hitNote(melody[3], LEN8);
  hitNote(melody[4], LEN8);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN4);
  
  hitNote(melody[4], LEN8);
  hitNote(melody[4], LEN8);
  hitNote(melody[4], LEN4);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN4);
  
  hitNote(melody[5], LEN_DOT8);
  hitNote(melody[4], LEN16);
  hitNote(melody[3], LEN8);
  hitNote(melody[4], LEN8);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN8);
  hitNote(melody[5], LEN4);
  
  hitNote(melody[4], LEN8);
  hitNote(melody[4], LEN8);
  hitNote(melody[5], LEN_DOT8);
  hitNote(melody[4], LEN16);
  hitNote(melody[3], LEN2);
}

void hitNote(int note, int len) {
  Timer3.initialize(1000000 / note);
  Timer3.pwm(5, 10);
  delay(len);
}
