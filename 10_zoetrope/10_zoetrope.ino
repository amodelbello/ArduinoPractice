const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void printState() {
  Serial.print("\nonOffSwitchState: ");
  Serial.print(onOffSwitchState);

  Serial.print("\npreviousOnOffSwitchState: ");
  Serial.print(previousOnOffSwitchState);

  Serial.print("\ndirectionSwitchState: ");
  Serial.print(directionSwitchState);

  Serial.print("\npreviousDirectionSwitchState: ");
  Serial.print(previousDirectionSwitchState);

  Serial.print("\nmotorEnabled: ");
  Serial.print(motorEnabled);

  Serial.print("\nmotorSpeed: ");
  Serial.print(motorSpeed);

  Serial.print("\nmotorDirection: ");
  Serial.print(motorDirection);

  Serial.print("\nanalogRead(potPin): ");
  Serial.print(analogRead(potPin));
  
  Serial.println("");
}

void setup() {
    Serial.begin(9600);
    printState();
    
    pinMode(directionSwitchPin, INPUT);
    pinMode(onOffSwitchStateSwitchPin, INPUT);
    pinMode(controlPin1, INPUT);
    pinMode(controlPin2, INPUT);
    pinMode(enablePin, INPUT);
    digitalWrite(enablePin, LOW);
}

void loop() {
    onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
    delay(1);
    directionSwitchState = digitalRead(directionSwitchPin);
    motorSpeed = analogRead(potPin) / 4;

    if (onOffSwitchState != previousOnOffSwitchState) {
        printState();
        if (onOffSwitchState == HIGH) {
            motorEnabled = !motorEnabled;
        }
    }

    if (directionSwitchState != previousDirectionSwitchState) {
        printState();
        if (directionSwitchState == HIGH) {
            motorDirection = !motorDirection;
        }
    }

    if (motorDirection == 1) {
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);

    } else {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
    }

    if (motorEnabled == 1) {
      analogWrite(enablePin, motorSpeed);

    } else {
      analogWrite(enablePin, 0);
    }

    previousDirectionSwitchState = directionSwitchState;
    previousOnOffSwitchState = onOffSwitchState;
}
