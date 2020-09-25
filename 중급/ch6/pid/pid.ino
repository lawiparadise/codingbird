double Kp = 5.0;
double Ki = 3.0;
double Kd = 0.1;

double error = 0;
double errorPrevious = 0;

double desiredAngle = 0;
double currentAngle = 0;
double resultAngle = 0;

double PTerm, ITerm, DTerm, PIDTerm;

double angularVel = 0;
double dt = 0.01;

void writeAngle(double term) {
  angularVel += desiredAngle * 0.1 + term * 0.9;
  angularVel *= 0.95;
  resultAngle += angularVel * dt;
}

double getAngle() {
  return resultAngle;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 목표 각도 받아오기
  desiredAngle = analogRead(A1) / 10;

  // 현재 각도 계산하기
  currentAngle = getAngle();

  // 에러 계산
  errorPrevious = error;
  error = desiredAngle - currentAngle;

  // PID 제어
  PTerm = Kp * error;
  ITerm += Ki * error * dt;
  DTerm = Kd * (error - errorPrevious) / dt;

  PIDTerm = PTerm + ITerm + DTerm;

  // 적용
  writeAngle(PIDTerm);

  // 목표 각도, 현재 각도 보여주기
  Serial.print(desiredAngle);
  Serial.print(" ");
  Serial.println(currentAngle);
  delay(10);
}
