int notes[] = {262, 330, 392, 523};
int thirteen = 13;

void setup() {
  pinMode(thirteen, OUTPUT);
  digitalWrite(thirteen, HIGH);
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  if (keyVal >= 2)
    digitalWrite(thirteen, HIGH);

  
  if(keyVal > 1010) {
    tone(8, notes[3]);
  
  } else if(keyVal >= 900 && keyVal <= 1010) {
    tone(8, notes[2]);
  
  } else if(keyVal >= 490 && keyVal <= 515) {
    tone(8, notes[1]);
    
  } else if(keyVal >= 2 && keyVal <= 10) {
    tone(8, notes[0]);
  
  } else {
    digitalWrite(thirteen, LOW);
    noTone(8);
  }
  
  delay(100);
}
