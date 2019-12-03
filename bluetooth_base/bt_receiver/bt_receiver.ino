#include <SoftwareSerial.h>

int ledPin = 5;
SoftwareSerial hc06(12,10);

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);    //  baud rate 9600 for the serial Bluetooth communication
  Serial.println("Setup done !");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  Serial.println("led tested !");
}
void loop() {
  while(Serial.available() == 0); // waiting for commands
    char c = Serial.read(); // command
    Serial.print("char: ");
    Serial.println(c);
    switch (c) {
        case 'z':
            blinkLED(1);
            break;
        case 's':
            blinkLED(2);
            break;
        case 'q':
            blinkLED(3);
            break;
        case 'd':
            blinkLED(4);
            break;
        default:
            break;
    }
}
void blinkLED(int inputVal) {
  for (int i=0; i< inputVal; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  Serial.println("led blinked !");
}
