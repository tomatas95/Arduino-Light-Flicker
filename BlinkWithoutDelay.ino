

const int ledPin1 = 13; 
const int ledPin2 = 3;
const byte interruptPin = 2;

volatile byte state = LOW;

int ledStateBlue = 0; 
int ledStateGreen = 1;


unsigned long previousMillisBlue = 0;
unsigned long previousMillisGreen = 0; 

const long ledPin1Interval = 1000; 
const long ledPin2Interval = 50;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisBlue >= ledPin1Interval) {
    previousMillisBlue = currentMillis;

    if (ledStateBlue == 0) {
      ledStateBlue = 1;
    } else {
      ledStateBlue = 0;
    }

    digitalWrite(ledPin1, ledStateBlue);
  }
  if (currentMillis - previousMillisGreen >= ledPin2Interval) {
    previousMillisGreen = currentMillis;

    if (ledStateGreen == 0) {
      ledStateGreen = 1;
    } else {
      ledStateGreen = 0;
    }

    digitalWrite(ledPin2, ledStateGreen);
  }
}
void blink() {
  state = !state;
}
