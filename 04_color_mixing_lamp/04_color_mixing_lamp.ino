const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int red = 0;
int green = 0;
int blue = 0;

int rSensorVal = 0;
int gSensorVal = 0;
int bSensorVal = 0;

String highest(int red, int green, int blue) {
  if (red > green && red > blue) {
    return "red";
  }
  if (green > red && green > blue) {
    return "green";
  }
  if (blue > red && blue > green) {
    return "blue";
  }
  return "blue";
}

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  rSensorVal = analogRead(redSensorPin);
  delay(5);
  gSensorVal = analogRead(greenSensorPin);
  delay(5);
  bSensorVal = analogRead(blueSensorPin);
  delay(5);

  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(rSensorVal);
  Serial.print("\t green: ");
  Serial.print(gSensorVal);
  Serial.print("\t blue: ");
  Serial.print(bSensorVal);
  Serial.print("\n");


  String color = highest(rSensorVal, gSensorVal, bSensorVal);
  int value = 120;
  
  red = color == "red" ? value : 0;
  green = color == "green" ? value : 0;
  blue = color == "blue" ? value : 0;
  
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);

  delay(1000);
}
