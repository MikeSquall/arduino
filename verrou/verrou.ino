#include <Servo.h>

Servo myServo;

const int piezzo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("C'est ouvert !");
}

void loop() {
  if(!locked){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("C'est fermé !");
      delay(1000);
    }

    if(locked){
      knockVal = analogRead(piezzo);
      if(numberOfKnocks < 3 && knockVal > 0){
        if(checkForKnock(knockVal)){
           numberOfKnocks++;
        }
        Serial.print(3-numberOfKnocks);
        Serial.println(" coups restants");
      }

      if(numberOfKnocks >= 3){
        locked = false;
        myServo.write(0);
        delay(20);
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        Serial.println("C'est ouvert !");
      }
    }
  }
}

  boolean checkForKnock(int value){
    if(value > quietKnock && value < loudKnock){
      digitalWrite(yellowLed, HIGH);
      delay(50);
      digitalWrite(yellowLed, LOW);
      Serial.println("OK");
      Serial.println(value);
      return true;
    } else {
      Serial.println("KO");
      Serial.println(value);
      return false;
    }
  }
