#include <Servo.h>

//const int pinLed = 8; 
Servo serv1; 

void setup() // Fonction d’initialisation de la carte
{
  //pinMode(pinLed, OUTPUT); // Definir pinLed comme une sortie
  Serial.begin(9600); // Demarrer la liaison a 9600bauds
  serv1.attach(10);
}

void loop() // Fonction principale, elle se répète (s’exécute) à l'infini
{
   while (Serial.available() == 0); // Attendre de recevoir des caracteres
   // char c = Serial.read(); // Lire les caracteres recus et les stocker dans c
   // if(c =='1') // Si c = 1
   // {
   //   digitalWrite(pinLed, HIGH); // Fermer le pinLed
   // }
   // if(c == '0') // Si c = 0
   // {
   //   digitalWrite(pinLed, LOW); // Ouvrir le pinLed
   // }
   // delay(500); // Attendre une demi seconde
   int angle = Serial.parseInt();
   serv1.write(angle);
}
