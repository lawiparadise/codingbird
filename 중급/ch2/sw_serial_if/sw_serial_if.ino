char lock = 'y';

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop() {
  if (Serial.available()) {
    lock = Serial.read();
  }
  if (lock == 'n' && digitalRead(12) == HIGH) {
    Serial.println("door open");
  } else{
    Serial.println("door close");
  }
}
