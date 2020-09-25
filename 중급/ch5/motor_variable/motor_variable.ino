void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() {
  int val = analogRead(A1);
  Serial.println(val);
  analogWrite(6, val / 100);
}
