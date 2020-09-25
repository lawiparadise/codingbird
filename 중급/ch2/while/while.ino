void setup() {
  Serial.begin(9600);
}

void loop() {
  int cnt = 0;

  while (cnt < 3) {
    Serial.println("under 3 forever");
  }

  while (cnt < 3) {
    cnt = 5;
    Serial.println(cnt);
  }

  while (true) {
    Serial.println("while once");
    break;
    Serial.println("fail");
  }

  while (true) {
    Serial.println("continue forever");
    continue;
    Serial.println("fail");
  }

  do {
    Serial.println("do once");
  } while (false);

  delay(3000);
}
