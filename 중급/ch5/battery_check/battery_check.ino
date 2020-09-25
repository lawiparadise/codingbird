#define MAX 860 // 4.2v 1023 * 4.2 / 5
#define MIN 675 // 3.3v 1023 * 3.3 / 5

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A3);
  int v = checkBat(val);
  Serial.print(v);
  Serial.println(" %");
}

int checkBat(int val) {
  int v = ((val - MIN) * 100) / (MAX - MIN);
  if (v > 100) v = 100;
  if (v < 0 ) v = 0;
  return v;
}
