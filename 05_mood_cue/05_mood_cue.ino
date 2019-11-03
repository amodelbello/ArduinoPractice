#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potVal;
int angle;

int roundToNum(int n, int toNum) {
  return (n / toNum + (n % toNum > 2)) * toNum;
}

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  potVal = roundToNum(analogRead(potPin), 10);
  Serial.print("potval: ");
  Serial.print(potVal);

  int rawAngle = map(potVal, 0, 1030, 0, 179);
//  angle = roundToNum(rawAngle, 10);
//  angle = angle <= 10 ? 0 : angle;
//  angle = angle >= 170 ? 179 : angle;

  angle = rawAngle;
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
