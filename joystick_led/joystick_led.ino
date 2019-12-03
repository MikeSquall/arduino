// constantes
const int VRx = 0;
const int VRy = 1;
const int SW  = 2;

// Variables de lecture
int calX, calY, calSW, rawX, rawY, rawSW, redLed, blueLed, yellowLed, greenLed;

void setup(){
// Initialisation du port série
Serial.begin(9600);

// Calibration de la valeur (0, 0) du joystick
calX = analogRead(VRx);
calY = analogRead(VRy);
calSW = analogRead(SW);

// init du pin de sortie pour les led
redLed = 8;
blueLed = 10;
yellowLed = 5;
greenLed = 9;
pinMode(redLed, OUTPUT);
pinMode(blueLed, OUTPUT);
pinMode(yellowLed, OUTPUT);
pinMode(greenLed, OUTPUT);
}

// loop()
void loop(){
// Mesure des valeurs en X et Y
rawX = analogRead(VRx)- calX;
rawY = analogRead(VRy)- calY;
rawSW = analogRead(SW)- calSW;

if(rawX > 10){
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
} else if(rawX < -10){
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
} else if(rawY > 10){
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}  else if(rawY < -10){
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);
}  else {
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}  
/*
Serial.print("rawX : ");
Serial.println(rawX);
Serial.print("rawY : ");
Serial.println(rawY);
delay(1000);// Temps de pause entre lecture
*/

delay(10);
}
