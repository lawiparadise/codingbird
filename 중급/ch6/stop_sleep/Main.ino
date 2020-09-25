void setup() {
  initMPU();
  Serial.begin(115200);
  calibrateSensor();
  past = millis();
  GRB.begin();
  Timer3.initialize(1000000 / 260);
}

void loop() {
  getADC();
  getDT();
  getAngle();
  if (angleFiY > 30) {
    if (now - alertTime > 100) {
      alert(10, 30);
      if (now - alertTime > 400) {
        alert(0, 0);
        alertTime = now;
      }
    } else {
      alert(0, 0);
    }
  } else {
    alert(0, 0);
  }
}
