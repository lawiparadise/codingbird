void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial1.begin(115200);
  initIR();
  GRB.begin();
  initMPU();
  delay(100);
  getADC();
  startTmp = Tmp;
}

void loop() {
  evaluateIR();
  getADC();
  blinkRGBLED();
  Serial.println(diffTmp);
}
