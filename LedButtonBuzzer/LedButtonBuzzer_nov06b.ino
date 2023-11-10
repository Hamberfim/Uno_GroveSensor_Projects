// Red LED, Button and Buzzer - Arduino Sensor Kit with Arduino Uno R3
// Author: Hamberfim

// define connection to digital pins
#define button 4  // connect to pin D4
#define BUZZER 5  // connect to pin D5
#define LED 6  // connect to pin D6

// instantiate an integer variable to hold the value of the pushbutton status
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  // set Serial data rate
  Serial.begin(9600);

  // initialize the buzzer pin as OUTPUT
  pinMode(BUZZER, OUTPUT);

  // initialized the pushbutton pin as INPUT
  pinMode(button, INPUT);
  
  // initialize the LED pin as OUTPUT
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state value of the pushbutton
  button_state = digitalRead(button);

  // logic - check the value
  if(button_state == HIGH) {
      Serial.println("Button Activated!");  // send output to serial console
      tone(BUZZER, 80);  // to the voltage to somewhat high to make a sound
      digitalWrite(LED, HIGH);  // set output to high(on)
      delay(50);
    } else {
      noTone(BUZZER);  // set the voltage low to turn off sound
      digitalWrite(LED, LOW);  // set output to low(off)
      delay(50);
    }
}
