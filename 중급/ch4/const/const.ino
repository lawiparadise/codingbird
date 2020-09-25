#define LED 13
const int BTN = 12;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  if (digitalRead(BTN) == HIGH) {
    Serial.print(true);
    Serial.print(HIGH);
    Serial.println(OUTPUT);
    digitalWrite(LED, 1);
  } else {
    Serial.print(false);
    Serial.print(LOW);
    Serial.println(INPUT);
    digitalWrite(LED, 0);
  }
}
