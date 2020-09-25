#include <Adafruit_DotStar.h>
Adafruit_DotStar GRB = Adafruit_DotStar(2);

void setup() {
  GRB.begin();
}

void loop() {
  GRB.setPixelColor(0, 100, 0, 0);
  GRB.setPixelColor(1, 0, 100, 0);
  GRB.show();
  delay(1000);

  GRB.setPixelColor(0, 50, 50, 0);
  GRB.setPixelColor(1, 100, 0, 0);
  GRB.show();
  delay(1000);

  GRB.setPixelColor(0, 0, 100, 0);
  GRB.setPixelColor(1, 50, 50, 0);
  GRB.show();
  delay(1000);
}
