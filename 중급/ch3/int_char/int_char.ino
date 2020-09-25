void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.println(Serial.read());
  
    char a1 = 'a';
    char a2 = 97;
    int a3 = 'a';
    int a4 = 97;

    Serial.print("a1 : ");
    Serial.print(a1);
    Serial.print(", a2 : ");
    Serial.print(a2);
    Serial.print(", a3 : ");
    Serial.print(a3);
    Serial.print(", a4 : ");
    Serial.print(a4);
    Serial.println();
  }
}
