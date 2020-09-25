char en[] = "abcdefghijklmnopqrstuvwxyz";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(en[7]);
  Serial.print(en[4]);
  Serial.print(en[11]);
  Serial.print(en[11]);
  Serial.print(en[14]);
  Serial.print(" ");
  Serial.print(en[22]);
  Serial.print(en[14]);
  Serial.print(en[17]);
  Serial.print(en[11]);
  Serial.println(en[3]);
}
