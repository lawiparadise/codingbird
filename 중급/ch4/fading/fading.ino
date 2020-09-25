void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  for (int i = 0 ; i <= 255 ; i += 5) {
    Serial.println(i);
    analogWrite(13, i);
    delay(30);
  }
  for (int i = 255 ; i >= 0 ; i -= 5) {
    Serial.println(i);
    analogWrite(13, i);
    delay(30);
  }
}
