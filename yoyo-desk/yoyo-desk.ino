

//Yoyo desk by Jenny Madorsky (Huge Inc)

#include <EEPROM.h>

int goUp = 7;
int goDown = 8;
long yoyoTime = 5000;
long stayUp = 8000;
long stayDown = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(goUp, OUTPUT);
  pinMode(goDown, OUTPUT);
}

void loop() {
  if (EEPROM.read(0)==true){
    delay(stayUp);
    digitalWrite(goDown, HIGH);
    delay(yoyoTime);
    digitalWrite(goDown, LOW);
    EEPROM.write(0, false);
    delay(stayDown);
    digitalWrite(goUp, HIGH);
    delay(yoyoTime);
    digitalWrite(goUp, LOW);
    EEPROM.write(0, true);
  }
  else {
    digitalWrite(goUp, HIGH);
    delay(yoyoTime);
    digitalWrite(goUp, LOW);
    EEPROM.write(0, true);
  }
}
