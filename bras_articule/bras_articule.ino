#include <Servo.h>

Servo serv1,
      serv2;
int posMoteur = 0;


void setup() {
  serv1.attach(2); // servo 1 sur pin 2
  serv2.attach(4); // servo 2 sur pin 4
}

void loop() {
  for(posMoteur = 0; posMoteur <= 120; posMoteur++){
    serv1.write(posMoteur);
    serv2.write(posMoteur);
    delay(10);
  }
  for(posMoteur = 90; posMoteur >= 0; posMoteur--){
    serv1.write(posMoteur);
    serv2.write(posMoteur);
    delay(10);
  }
}
