void writeMotors() {
  if (SW) {
    if (rcSerial[3] > 125) {
      if (throttleCnt < 200) throttleCnt++;
    } else if (rcSerial[3] < 125) {
      if (throttleCnt > 0) throttleCnt--;
    }
    analogWrite(5, throttleCnt / 8);
    analogWrite(6, throttleCnt / 8);
  } else {
    analogWrite(5, 0);
    analogWrite(6, 0);
    throttleCnt = 0;
  }
}
