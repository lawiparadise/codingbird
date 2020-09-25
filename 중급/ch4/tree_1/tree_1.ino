void setup() {
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  Serial.println("insert height of tree");
  while (!Serial.available());
  if (Serial.available()) {
    int h = Serial.read() - '0';
    Serial.println(h);

  }
}
