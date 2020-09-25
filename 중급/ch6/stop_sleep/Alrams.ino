void hitNote(int val) {
  val = constrain(val, 0, 10);
  Timer3.pwm(5, val);
}

void alert(int val, int r) {
  hitNote(val);
  r = constrain(r, 0, 100);
  GRB.setPixelColor(0, 0, r, 0);
  GRB.show();
}
