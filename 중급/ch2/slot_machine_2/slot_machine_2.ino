int cnt = 0;
int num[4] = {0,};

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  randomSeed(analogRead(5));
}

void loop() {
  saveNumber();
  printNumber();
  printResult();
}

void saveNumber() {
  if (digitalRead(12) == HIGH) {
    while (digitalRead(12) == HIGH);
    cnt++;
    if (cnt > 3)cnt = 0;
    num[cnt] = random(1, 10);
    delay(50);
  }
}

void printNumber() {
  if (cnt == 0) {
    Serial.print(random(10));
    Serial.print(random(10));
    Serial.print(random(10));
  } else if (cnt == 1) {
    Serial.print(num[1]);
    Serial.print(random(10));
    Serial.print(random(10));
  } else if (cnt == 2) {
    Serial.print(num[1]);
    Serial.print(num[2]);
    Serial.print(random(10));
  } else if (cnt == 3) {
    Serial.print(num[1]);
    Serial.print(num[2]);
    Serial.print(num[3]);
  }
  Serial.println();
}

void printResult() {
  if (cnt == 3) {
    if (num[1] == 7 && num[2] == 7 && num[3] == 7) {
      Serial.println("!!!!! JACKPOT !!!!!");
    } else {
      Serial.println("... NEXT TIME ...");
    }
  }
}
