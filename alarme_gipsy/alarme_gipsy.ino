const int ledPin = 5; // LED output
const int sensorPin = 2; // Motion sensor input
const int speakerPin = 6; // Speaker output
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

const int NOTE_A6  = 1760;
const int NOTE_AS6 = 1865;
const int NOTE_B6  = 1976;
const int NOTE_E6  = 1319;
const int NOTE_G6  = 1568;
const int NOTE_C7  = 2093;
const int NOTE_D7  = 2349;
const int NOTE_E7  = 2637;
const int NOTE_F7  = 2794;
const int NOTE_G7  = 3136;
const int NOTE_A7  = 3520;
const int NOTE_C   = 16;
const int NOTE_F   = 22;

void playSong() {
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_G7, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_G7, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_F, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_G7, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, NOTE_C, 100);
  digitalWrite(ledPin, LOW);
  delay(150);
}

void loop() {
  val = digitalRead(sensorPin);

  Serial.print(val);

  // If motion is detected
  if (val == HIGH) {
    playSong();
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}
