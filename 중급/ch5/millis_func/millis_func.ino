unsigned long preTime = 0;
unsigned long curTime = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (myTimer(1000)) {
    Serial.println("1초마다 실행됩니다.");
  }
}

boolean myTimer(int waitTime) {
  curTime = millis();
  if (curTime - preTime >= waitTime) {
    preTime = curTime;
    return true;
  }
  return false;
}
