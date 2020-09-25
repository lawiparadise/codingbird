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

    for (int i = 0; i < h; i++) {
      for (int j = 0 ; j < h - i ; j++) {
        Serial.print(" ");
      }
      for (int k = 0; k < i + 1; k++) {
        Serial.print("*");
      }
      Serial.println();
    }

    Serial.println();
  }
}
