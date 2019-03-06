int lowLevelPin = 8;
int lowLevelValue = 0;
int hightLevelPin = 9;
int hightLevelValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(lowLevelPin, INPUT);
  pinMode(hightLevelPin, INPUT);
}

void loop() {
  lowLevelValue = digitalRead(lowLevelPin);
  Serial.print("Low value is:  ");
  Serial.println(lowLevelValue);

  hightLevelValue = digitalRead(hightLevelPin);
  Serial.print("Hight value is: ");
  Serial.println(hightLevelValue);
 
  delay(1000);
}
