void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if(Serial.available()){
    char val = Serial.read();
    Serial.println(val);
    if(val == 'a'){
      Serial.println("LED ON");
      digitalWrite(13, HIGH); 
    } else{
      Serial.println("LED OFF");
      digitalWrite(13, LOW); 
    }
  }
}
