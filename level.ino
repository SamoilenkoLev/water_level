int lowLevelPin = 8;
int hightLevelPin = 9;
int ledPin = 7;

boolean lowLevel;
boolean hightLevel;
boolean nasos = false;

int nasosTimer = 0;
int loop_delay = 1;
int nasos_delay = 10;
int nasosMaxTime = 600;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(lowLevelPin, INPUT);
  pinMode(hightLevelPin, INPUT);
}

void set_nasos(bool value){
    nasos = value;
    digitalWrite(ledPin, value);
    if(value){
      nasosTimer = nasos_delay;
    } else {
      nasosTimer = 0;
    }
    Serial.print("Switch nasos: ");
    Serial.println(value);

    Serial.print("delay: ");
    Serial.println(nasos_delay);
    delay(nasos_delay * 1000);
}

void loop() {
  lowLevel = not digitalRead(lowLevelPin);
  Serial.print("Low value is:  ");
  Serial.println(lowLevel);

  hightLevel = not digitalRead(hightLevelPin);
  Serial.print("Hight value is: ");
  Serial.println(hightLevel);

  if(lowLevel and hightLevel and not nasos){
    set_nasos(true);
  }

  if(not lowLevel and nasos){
    set_nasos(false);
  }

  if(nasos){
    nasosTimer += loop_delay;
    if(nasosTimer > nasosMaxTime){
      set_nasos(false);
    }
  }

 Serial.print("Nasos work, sec: ");
 Serial.println(nasosTimer);
 delay(loop_delay * 1000);
}
