unsigned long preTime = 0;
unsigned long curTime = 0;
int num = 0;
boolean SW = false;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  changeSW();
  if (SW) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}

void changeSW() {
  if (digitalRead(12) == HIGH) {
    SW = !SW;
    while (digitalRead(12) == HIGH) {
      Serial.println("버튼 눌림");
    }
    delay(50);
  }
}
