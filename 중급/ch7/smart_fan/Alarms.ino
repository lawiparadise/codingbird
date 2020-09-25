void blinkRGBLED() {
  if (SW) GRB.setPixelColor(0, 0, 50, 0);
  else GRB.setPixelColor(0, 0, 0, 0);
  GRB.show();
}
