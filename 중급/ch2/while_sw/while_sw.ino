int cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop() {
  if (digitalRead(12) == HIGH) {
    cnt = cnt + 1;
    
    while (digitalRead(12) == HIGH) {
      Serial.println("wait for switch off");
    }
    delay(50);

    Serial.print("cnt : ");
    Serial.println(cnt);
  }
}
