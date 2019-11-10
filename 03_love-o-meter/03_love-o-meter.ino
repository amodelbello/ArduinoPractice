
const int sensorPin = A5;
float baselineTemp = 1.1;

float getVoltageFromSensor(int sensorVal) {
  float voltage = (sensorVal / 1024.0) * 5.0;
  return voltage;
}

float getTempFromSensor(int sensorVal) { 
  float voltage = getVoltageFromSensor(sensorVal);
  float temperature = (voltage - .5) * 100;
  return temperature;
}
  

  
void setup() {
  Serial.begin(9600); // open a serial port

  float sensorVal = analogRead(sensorPin);
  baselineTemp = getTempFromSensor(sensorVal);
  Serial.print("sv: ");
  Serial.print(sensorVal);
  Serial.print("bl: ");
  Serial.print(baselineTemp);
  
  for(int pinNumber = 2; pinNumber <= 4; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  Serial.print("bl: ");
  Serial.print(baselineTemp);
  int sensorVal = analogRead(sensorPin);
  Serial.print(" Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = getVoltageFromSensor(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = getTempFromSensor(sensorVal);
  Serial.print(", degrees C: ");
  Serial.print(temperature);

  if(temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  Serial.print("\n");
  delay(1000);
}
