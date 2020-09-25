unsigned long preTime = 0;
unsigned long curTime = 0;
const int MY_DELAY_TIME = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  curTime = millis();
  if (curTime - preTime >= MY_DELAY_TIME) {
    preTime = curTime;
    Serial.print("Time is gone ");
    Serial.println(curTime / 1000);
  }
}
