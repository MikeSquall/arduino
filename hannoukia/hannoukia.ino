int candles = 0,
    temps,
    pinShamash = 10,
    pinLed1 = 9,
    pinLed2 = 2,
    pinLed3 = 3,
    pinLed4 = 4,
    pinLed5 = 5,
    pinLed6 = 6,
    pinLed7 = 7,
    pinLed8 = 8,
    pinButton = 12;


void setup() 
{  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  pinMode(pinLed7, OUTPUT);
  pinMode(pinLed8, OUTPUT);
  pinMode(pinShamash, OUTPUT);
  pinMode(pinButton, INPUT);
  temps = 1000;
  digitalWrite(pinShamash, HIGH);
  for(int i=0; i<9; i++){
    digitalWrite(i, LOW);
  }
  Serial.begin(9600);
}

void loop() 
{
  boolean button_state = digitalRead(pinButton);
  if (button_state == HIGH){
    candles++;
    delay(temps);
  }
  if (candles > 8){
    candles = 0;
  }
  switch (candles) {
      case 0:
          for(int i=0; i<10; i++){
              digitalWrite(i, LOW);
              delay(100);
          }
        break;
      case 1:
        digitalWrite(pinLed1, HIGH);
        break;
      case 2:
        digitalWrite(pinLed2, HIGH);
        break;
      case 3:
        digitalWrite(pinLed3, HIGH);
        break;
      case 4:
        digitalWrite(pinLed4, HIGH);
        break;
      case 5:
        digitalWrite(pinLed5, HIGH);
        break;
      case 6:
        digitalWrite(pinLed6, HIGH);
        break;
      case 7:
        digitalWrite(pinLed7, HIGH);
        break;
      case 8:
        digitalWrite(pinLed8, HIGH);
        break;
  }
  Serial.println(button_state);
  Serial.println(candles);
}

