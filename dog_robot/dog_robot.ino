#include <NewPing.h>
#include <Servo.h>

Servo servoFront, servoBack;
NewPing sonar(2,4,200);

char front[] = {60,100,100,100,100,60,60,60};
int distance = 0,
    distanceMin = 10;


void setup() {
  servoFront.attach(6);
  servoBack.attach(8);
}

void loop() {
  distance = 0;

  while(distance == 0){
    distance = farAway();
  }

  if (distance > distanceMin){
    moveOn();
  }
}

void moveOn() {
  for(int i=0; i<4; i++){
    servoFront.write(front[2*i]);
    servoBack.write(front[(2*i)+1]);
    delay(250);
  }
}

int farAway(){
  delay(70);
  unsigned int ultrasound = sonar.ping();
  int cm = ultrasound/US_ROUNDTRIP_CM;

  return cm;
}

