int pinBouton;
int pinLedV, pinLedR ;

void setup()
{
    Serial.begin(9600);
    pinBouton=2;
    pinMode(pinBouton,INPUT);
    pinLedV = 6 ;
    pinMode(pinLedV, OUTPUT);
    pinLedR = 4 ;
    pinMode(pinLedR, OUTPUT) ;

    digitalWrite(pinLedR, LOW);
    digitalWrite(pinLedV, LOW);
}
void loop()
{
    boolean etatBouton=digitalRead(pinBouton);
    Serial.println(etatBouton);
    if(etatBouton == 0){
      digitalWrite(pinLedR, HIGH);
      digitalWrite(pinLedV, LOW);
    } else {
      digitalWrite(pinLedR, LOW);
      digitalWrite(pinLedV, HIGH);
    }
}
