#include <Adafruit_DotStar.h>
Adafruit_DotStar GRB = Adafruit_DotStar(2);

#define MAX 860 // 4.2v 1023 * 4.2 / 5
#define MIN 675 // 3.3v 1023 * 3.3 / 5

void setup() {
  GRB.begin();
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A3);
  int v = checkBat(val);
  setGRB(v);
  Serial.print(v);
  Serial.println(" %");
}

void setGRB(int v) {
  if (v < 40) {
    GRB.setPixelColor(0, 0, 100, 0);
  } else if (v > 40 && v < 80) {
    GRB.setPixelColor(0, 50, 50, 0);
  } else {
    GRB.setPixelColor(0, 100, 0, 0);
  }
  GRB.show();
}

int checkBat(int val) {
  int v = ((val - MIN) * 100) / (MAX - MIN);
  if (v > 100) v = 100;
  if (v < 0 ) v = 0;
  return v;
}
