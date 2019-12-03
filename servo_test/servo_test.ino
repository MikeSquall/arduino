 /* Inclut la lib Servo pour manipuler le servomoteur */
#include <Servo.h>

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;

void setup() {
    
  // Attache le servomoteur à la broche D8
  monServomoteur.attach(8);
}

void loop() {

  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 60; position++) {
    monServomoteur.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 60; position >= 0; position--) {
    monServomoteur.write(position);
    delay(15);
  }
}
