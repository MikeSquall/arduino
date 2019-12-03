#include <SoftwareSerial.h>

int greenLed = 5;
int redLed = 3;
SoftwareSerial hc06(12,10);


void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
  hc06.begin(9600);
  Serial.println("Serials started");
  
  digitalWrite(greenLed, HIGH);
  delay(500);
  digitalWrite(greenLed, LOW);
  Serial.println("green led tested !");
  digitalWrite(redLed, HIGH);
  delay(500);
  digitalWrite(redLed, LOW);
  Serial.println("red led tested !");
  
  Serial.println("Setup done !");
}

void loop() {
  while(hc06.available() == 0); // waiting for commands
    char input_signal = hc06.read(); // command
    Serial.print("input_signal: ");
    Serial.println(input_signal);
    switch(input_signal) {
      case 'a':
        greenOn();
        break;
      case 'b':
        redOn();
        break;
      default:
        Serial.println("Error: incorrect input_signal");
        displayError();
        break;
    }
}

void redOn() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}


void greenOn() {
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);
}

void displayError() {
  for (int i=0; i < 10; i++) {
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
  } 
}
