#include <SoftwareSerial.h>

int pinLed = 5;
SoftwareSerial hc06(12,10);


void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  hc06.begin(9600);
  
  digitalWrite(pinLed, HIGH);
  delay(500);
  digitalWrite(pinLed, LOW);
  Serial.println("led tested !");
  Serial.println("Setup done !");
}

void loop() {
  if(hc06.available() == 0) {
    Serial.println("hc06.available() == 0");
  } else {
    Serial.print("hc06.available() == ");
    Serial.println(hc06.available());
  }
  while(hc06.available() == 0); // waiting for commands
    char c = hc06.read(); // command
    Serial.print("c : ");
    Serial.println(c);
    switch (c) {
        case 'z':
            moveOn();
            break;
        case 's':
            moveBack();
            break;
        case 'q':
            turnLeft();
            break;
        case 'd':
            turnRight();
            break;
        default:
            stop();
            break;
  }
}

void blinkLED(int inputVal) {
  for (int i=0; i< inputVal; i++) {
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
    Serial.println("led blinked !");
    delay(500);
  }
}

void moveOn(){
    blinkLED(1);
    Serial.println("----->> Move on ");
}

void moveBack(){
    blinkLED(2);
    Serial.println("----->> Move back ");
}

void turnRight(){
    blinkLED(3);
    Serial.println("----->> Turn right ");
}

void turnLeft(){
    blinkLED(4);
    Serial.println("----->> Turn left ");
}

void stop(){
    blinkLED(0);
    Serial.println("----->> Stop ");
}
