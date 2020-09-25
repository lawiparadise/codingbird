void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  int val = analogRead(A1) / 4;
  Serial.println(val);

  analogWrite(13, val);
}
