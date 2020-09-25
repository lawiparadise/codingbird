boolean SW = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  if (digitalRead(12) == HIGH) {
    SW = !SW;
    while (digitalRead(12));
    delay(50);
  }
  if (SW) {
    int val = analogRead(A1) / 4;
    analogWrite(13, val);
  } else {
    analogWrite(13, 10);
  }
}
