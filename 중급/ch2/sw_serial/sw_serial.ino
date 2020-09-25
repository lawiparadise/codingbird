void setup(){
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop(){
  if(digitalRead(12) == HIGH){
    Serial.println("원하는 문구 적기");
  }
}
