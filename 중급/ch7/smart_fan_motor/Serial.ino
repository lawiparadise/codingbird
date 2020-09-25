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
  if ( rcSerial[3] > 125) SW = true;
  else if (rcSerial[3] < 20) SW = false;
}
