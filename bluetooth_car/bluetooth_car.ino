int pin1Motor1 = 12,
    pin2Motor1 = 8,
    pinPMotor1 = 11,
    pin1Motor2 = 2,
    pin2Motor2 = 4,
    pinPMotor2 = 5;

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
    while(Serial.available() == 0); // waiting for commands
    char c = Serial.read(); // command
    switch (c) {
        case 'z':
            moveOn();
            break;
        case 's':
            moveBack();
            break;
        case 'q':
            turnLeft();
            break;
        case 'd':
            turnRight();
            break;
        default:
            stop();
            break;
  }
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
    //Serial.println("----->> Move on ");
}

void moveBack(){
    dirMotor(1,0,100);
    dirMotor(2,0,100);
    delay(1000);
    dirMotor(1,-1,100);
    dirMotor(2,-1,100);
    delay(1000);
    //Serial.println("----->> Move back ");
}

void turnRight(){
    // delay(100);
    // dirMotor(1,-1,100);
    // dirMotor(2,0,0);
    // delay(100);
    dirMotor(1,1,50);
    dirMotor(2,-1,50);
    //delay(200);
    //Serial.println("----->> Turn right ");
}

void turnLeft(){
    // delay(100);
    // dirMotor(1,0,0);
    // dirMotor(2,-1,100);
    // delay(100);
    dirMotor(1,-1,50);
    dirMotor(2,1,50);
    //delay(200);
    //Serial.println("----->> Turn left ");
}

void stop(){
    dirMotor(1,0,0);
    dirMotor(2,0,0);
}
