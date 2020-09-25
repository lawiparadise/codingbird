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
  setTimer();
  if (num && myTimer(num * 1000)) {
    SW = false;
    num = 0;
  }
  if (SW) {
    digitalWrite(13, HIGH);
    analogWrite(6, analogRead(A1) / 100);
  } else {
    digitalWrite(13, LOW);
    analogWrite(6, 0);
  }
}

void setTimer() {
  if (Serial.available()) {
    num = Serial.read() - '0';
    preTime = millis();
  }
}

boolean myTimer(int waitTime) {
  curTime = millis();
  if (curTime - preTime >= waitTime) {
    preTime = curTime;
    return true;
  }
  return false;
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
