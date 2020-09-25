void blinkRGBLED() {
  if (SW) GRB.setPixelColor(0, 0, 50, 0);
  else GRB.setPixelColor(0, 0, 0, 0);

  diffTmp = Tmp - startTmp;
  diffTmp = constrain(diffTmp, -200, 200);
  if (diffTmp > 0)
    GRB.setPixelColor(1, 0, abs(diffTmp) / 2, 0);
  if (diffTmp < 0)
    GRB.setPixelColor(1, 0, 0, abs(diffTmp) / 2);

  GRB.show();
}
