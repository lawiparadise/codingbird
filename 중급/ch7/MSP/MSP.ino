int cnt = 0;
int inBuf[11] = {0, };

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  while (Serial1.available()) {
    int data = Serial1.read();
    if (data == '$')cnt = 0;
    else cnt++;
    if (cnt < 11) inBuf[cnt] = data;
    else break;
  }
  if (inBuf[4] == 149) {
    for (int i = 0 ; i < 3 ; i++) {
      Serial.print((char)inBuf[i]); Serial.print(", ");
    }
    for (int i = 3 ; i < 11 ; i++) {
      Serial.print(inBuf[i]); Serial.print(", ");
    }
    Serial.println();
  }
}
