#define RADIUS 3
#define DIAMETER 4
#define HEIGHT 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("area : ");
  Serial.print(RADIUS * RADIUS * PI);

  Serial.print(", volume : ");
  int rad = DIAMETER / 2;
  float val = rad * rad * PI * HEIGHT;
  Serial.println(val);
}
