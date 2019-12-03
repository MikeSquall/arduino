int pinBouton, pinLed;
void setup()
{
    Serial.begin(9600);
    pinBouton=12;
    pinLed = 10;
    pinMode(pinBouton,INPUT);
    pinMode(pinLed, OUTPUT);
}
void loop()
{
    boolean etatBouton=digitalRead(pinBouton);
    if(etatBouton == 1){
      digitalWrite(pinLed, HIGH);
    } else {
      digitalWrite(pinLed, LOW);
    }
    Serial.println(etatBouton);
}
