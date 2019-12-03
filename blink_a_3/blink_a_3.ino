int pinLedRed = 7 ;
int pinLedGreen = 8 ;
int pinLedBlue = 13 ;
int temps ;

void setup() 
{  
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedBlue, OUTPUT);
  temps = 1000 ;
}

void loop() 
{
  for(int i = 0 ; i < 5 ; i++){
    digitalWrite(pinLedRed, HIGH);
    digitalWrite(pinLedGreen, HIGH);
    digitalWrite(pinLedBlue, HIGH);
    delay(temps);
    digitalWrite(pinLedRed, LOW);
    digitalWrite(pinLedGreen, LOW);
    digitalWrite(pinLedBlue, LOW);
    delay(temps);
    digitalWrite(pinLedRed, HIGH);
    digitalWrite(pinLedGreen, HIGH);
    digitalWrite(pinLedBlue, HIGH);
    delay(temps);
    digitalWrite(pinLedBlue, LOW);
    delay(temps);
    digitalWrite(pinLedBlue, HIGH);
    digitalWrite(pinLedGreen, LOW);
    delay(temps);
    digitalWrite(pinLedGreen, HIGH);
    digitalWrite(pinLedRed, LOW);
    delay(temps);

    temps = temps - 200 ;
  }
  temps = 1000 ;
}
