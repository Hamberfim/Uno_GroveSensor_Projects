// Red LED, Button and Buzzer - Arduino Sensor Kit with Arduino Uno R3
// Author: Hamberfim

// define connection to digital pins
#define button 4  // connect to pin D4
#define BUZZER 5  // connect to pin D5
#define LED 6  // connect to pin D6

// instantiate an integer variable for reading the pushbutton status
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize the buzzer pin as OUTPUT
  pinMode(BUZZER, OUTPUT);

  // initialize the LED pin as OUTPUT
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(BUZZER, 80);  // to the voltage to somewhat high to make a sound
  digitalWrite(LED, HIGH);  // set output to high(on)
  delay(250);

  noTone(BUZZER);  // set the voltage low to turn off sound
  digitalWrite(LED, LOW);  // set output to low(off)
  delay(125);

}
