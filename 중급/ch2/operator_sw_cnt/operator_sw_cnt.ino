int cnt = 0;
boolean val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  int s = digitalRead(12);
  if (s) {
    cnt++;
    if (cnt >= 5000) {
      val = !val;
      cnt = 0;
      digitalWrite(13, val);
      while(digitalRead(12));
    }
  } else {
    cnt = 0;
  }
  
  Serial.println(cnt);
}
