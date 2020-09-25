unsigned long preTime = 0;
unsigned long curTime = 0;
int num = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    num = Serial.read() - '0';
    preTime = millis();
  }
  if (num && myTimer(num * 1000)) {
    Serial.print(num);
    Serial.println("초마다 실행됩니다.");
    digitalWrite(13, HIGH);
    delay(20);
    digitalWrite(13, LOW);
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
