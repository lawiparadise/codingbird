void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial1.begin(115200);
  initIR();
  GRB.begin();
}

void loop() {
  evaluateIR();
  blinkRGBLED();
}
