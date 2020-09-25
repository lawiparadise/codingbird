int cnt = 0;
int inBuf[11] = {0, };
int rcSerial[8] = {0, };

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  serialCom();
  if (rcSerial[3] > 150) {
    digitalWrite(13, HIGH);
  } else if (rcSerial[3] < 100) {
    digitalWrite(13, LOW);
  }
}

void serialCom() {
  while (Serial1.available()) {
    int data = Serial1.read();
    if (data == '$')cnt = 0;
    else cnt++;
    if (cnt < 11) inBuf[cnt] = data;
    else break;
  }
  evaluateCommand();
}

void evaluateCommand() {
  if (inBuf[4] == 149) {
    for (int i = 0 ; i < 5; i++) {
      rcSerial[i] = inBuf[i + 5];
    }
  }
}
