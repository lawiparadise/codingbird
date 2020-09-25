void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();

    if (val > '4' && val < '8') {
      Serial.println("A");
    } else if (val < '3' || val > '8') {
      Serial.println("B");
    } else if (val == '3' || val == '4') {
      Serial.println("C");
    } else if (val != '0' && val != '8') {
      Serial.println("D");
    } else {
      Serial.println("E");
    }

  }
}
