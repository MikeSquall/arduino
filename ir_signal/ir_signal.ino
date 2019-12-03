#include <IRremote.h>

int IRpin = 11,
    pinLed = 8,
    remote = -1,
    state = 0;

IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    if (irrecv.decode(&results)){
        val = results.value;
        Serial.println(val, DEC);
        Serial.println(state);
        irrecv.resume();
    }

    if (val == remote){
      if (state == 0){
        digitalWrite(pinLed, HIGH);
        state = 1;
      }
      else{
        digitalWrite(pinLed, LOW);
        state = 0;
      }
    }
}
