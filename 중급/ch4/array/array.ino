int prime[5] = {2, 3, 5, 7, 11};
int two = prime[0];
float root[4] = {1.414, 1.732, 2.000, 2.236};
float r5 = root[3];
char ch[5] = {'h', 'e', 'l', 'l', 'o'};
char e = ch[1];
char str[6] = "world";
char d = str[4];
char asc[5] = {65, 83, 67, 73, 73};
char S = asc[1];
int rc[2][3] = {
  {1, 2, 3},
  {4, 5, 6}
};
int six = rc[1][2];

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop() {
  if (digitalRead(12)) printVariable();
  else printArray();
}

void printVariable() {
  Serial.print("two : ");
  Serial.print(two);
  Serial.print(", r5 : ");
  Serial.print(r5, 3);
  Serial.print(", e : ");
  Serial.print(e);
  Serial.print(", d : ");
  Serial.print(d);
  Serial.print(", S : ");
  Serial.print(S);
  Serial.print(", six : ");
  Serial.println(six);
}

void printArray() {
  Serial.print("prime : ");
  for (int i = 0; i < 5; i++) Serial.print(prime[i]);
  Serial.print(", root : ");
  for (int i = 0; i < 4; i++) Serial.print(root[i], 3);
  Serial.print(", ch : ");
  for (int i = 0; i < 5; i++) Serial.print(ch[i]);
  Serial.print(", str : ");
  for (int i = 0; i < 6; i++) Serial.print(str[i]);
  Serial.print(", asc : ");
  for (int i = 0; i < 5; i++) Serial.print(asc[i]);
  Serial.print(", rc : ");
  for (int i = 0 ; i < 2 ; i++)
    for (int j = 0 ; j < 3 ; j++)
      Serial.print(rc[i][j]);
  Serial.println();
}
