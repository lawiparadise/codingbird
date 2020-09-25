int cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int val = analogRead(A1);
  if (digitalRead(12) == HIGH && val > 500) {
    analogWrite(6, 10);
  } else {
    analogWrite(6, 0);
  }
}
