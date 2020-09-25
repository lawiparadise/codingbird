char rabbit[3][7] = {
  {' ', '/', ')', ' ', '/', ')'},
  {40, 45, 95, 45, 42, 41},
  "(>O< )",
};

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (digitalRead(12) == HIGH) {
    for (int i = 0 ; i < 3 ; i++) {
      for (int j = 0 ; j < 7 ; j++) {
        Serial.print(rabbit[i][j]);
      }
      Serial.println();
    }
    while (digitalRead(12));
    delay(50);
  }
}
