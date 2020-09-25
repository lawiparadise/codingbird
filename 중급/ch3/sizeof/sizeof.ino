void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("boolean : ");
  Serial.print(sizeof(boolean));

  Serial.print(", char : ");
  Serial.print(sizeof(char));

  Serial.print(", int : ");
  Serial.print(sizeof(int));

  Serial.print(", long : ");
  Serial.print(sizeof(long));

  Serial.print(", float : ");
  Serial.print(sizeof(float));
  Serial.println();
}
