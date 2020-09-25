void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A1);
  Serial.println(val);
  delay(100);
}
