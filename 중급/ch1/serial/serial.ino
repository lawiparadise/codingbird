void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    Serial.println("Arduino : Hi, I'm Arduino");
    
    Serial.print("You : ");
    Serial.println((char)Serial.read());
  }
}
