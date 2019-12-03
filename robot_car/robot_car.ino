#include <NewPing.h>

int pin1Motor1 = 12,
	pin2Motor1 = 8,
	pinPMotor1 = 11,
	pin1Motor2 = 2,
	pin2Motor2 = 4,
	pinPMotor2 = 5,
	TRIG_PIN = 10,
	ECHO_PIN = 9,
	DIST_MAX = 200,
	i = 90,
	current_dist = 0,
	cm;

NewPing sonar(TRIG_PIN, ECHO_PIN, 200);

void setup() {
  pinMode(pin1Motor1, OUTPUT);
  pinMode(pin2Motor1, OUTPUT);
  pinMode(pinPMotor1, OUTPUT);
  pinMode(pin1Motor2, OUTPUT);
  pinMode(pin2Motor2, OUTPUT);
  pinMode(pinPMotor2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  current_dist = readDistance();
  if(current_dist >= 20){
  	moveOn();
  } else {
  	moveBack();
  	turnRight();
  }
  delay(300);
}

void dirMotor(int motor, int direction, int percentage){
	int pin1, state1, pin2, state2, pinP, power;

	if(motor == 1){
		pin1 = pin1Motor1;
		pin2 = pin2Motor1;
		pinP = pinPMotor1;
	} else {
		pin1 = pin1Motor2;
		pin2 = pin2Motor2;
		pinP = pinPMotor2;
	}

	if(direction == 1){
		state1 = 1;
		state2 = 0;
	} else if(direction == -1){
		state1 = 0;
		state2 = 1;
	} else {
		state1 = 0;
		state2 = 0;
	}
    power = map(percentage, 0, 100, 0, 255);
    analogWrite(pinP, power);
    digitalWrite(pin1, state1);
    digitalWrite(pin2, state2);
}

void moveOn(){
    dirMotor(1,1,100);
    dirMotor(2,1,100);
    Serial.println("----->> Move on ");
}

void moveBack(){
    dirMotor(1,0,100);
    dirMotor(2,0,100);
    delay(1000);
    dirMotor(1,-1,100);
    dirMotor(2,-1,100);
    delay(1000);
    Serial.println("----->> Move back ");
}

void turnRight(){
    delay(100);
    dirMotor(1,-1,100);
    dirMotor(2,0,0);
    delay(100);
    dirMotor(1,-1,100);
    dirMotor(2,1,50);
    delay(200);
    Serial.println("----->> Turn right ");
}

int readDistance(){
    delay(70);
    unsigned int ultrasound = sonar.ping();
    cm = ultrasound / US_ROUNDTRIP_CM;
    if(cm == 0){
        readDistance();
    } else {
        return cm;
    }
}

