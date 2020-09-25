void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A1);

  Serial.print("Arduino : ");
  if(val > 614){
    Serial.println("I think HIGH");
  } else if(val < 614 && val > 307){
    Serial.println("I don't know");
  } else{
    Serial.println("I think LOW");
  }
}
