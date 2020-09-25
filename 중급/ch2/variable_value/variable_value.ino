int ledPin = 13;
int buttonPin = 12;
int buttonState = 0;
int val;
int cnt = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(12);
  cnt = cnt + buttonState;
  val = cnt;
  Serial.print("value : ");
  Serial.println(val);
}
