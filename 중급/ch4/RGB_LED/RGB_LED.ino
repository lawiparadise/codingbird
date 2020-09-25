#include <Adafruit_DotStar.h>
Adafruit_DotStar GRB = Adafruit_DotStar(2);

void setup() {
  GRB.begin();
}

void loop() {
  for (int i = 0 ; i < 255 ; i++) {
    GRB.setPixelColor(0, i, 0, 0);
    GRB.show();
    delay(10);
  }
}
