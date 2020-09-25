void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.read() - '0';
    Serial.println(val);

    Serial.println(
      val == 7 ? "lucky" : "happy"
    );

    if (val % 2 == 1) {
      Serial.println("odd");
    } else {
      Serial.println("even");
    }

    if (val == 9) {
      Serial.print("9x9=");
      val *= val;
      Serial.println(val);
    }

  }
}
