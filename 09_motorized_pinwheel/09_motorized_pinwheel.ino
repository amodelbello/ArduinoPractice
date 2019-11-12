const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup() {
  Serial.begin(9600); // open a serial port
  Serial.print("Right?");
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }
}
