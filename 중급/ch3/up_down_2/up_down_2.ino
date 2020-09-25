void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  randomSeed(analogRead(5));
  delay(3000);
}

void loop() {
  int val = random(1, 51);
  int cnt = 0;
  Serial.println("Guess number 1~50");

  while (true) {
    if (digitalRead(12) == HIGH) {
      while (digitalRead(12) == HIGH);
      delay(50);
      Serial.print(++cnt); Serial.print(" : ");

      int num = analogRead(A1);
      num = map(num, 0, 1023, 1, 51);
      Serial.println(num);

      if (num > val) {
        Serial.println("down");
      } else if (num < val) {
        Serial.println("up");
      } else {
        if (cnt >= 5) {
          Serial.println("You Lose..");
        } else {
          Serial.println("You Win!!");
        }
        Serial.print("Your count : ");
        Serial.println(cnt);
        Serial.println();
        delay(2000);
        break;
      }
      
    }
  }

}
