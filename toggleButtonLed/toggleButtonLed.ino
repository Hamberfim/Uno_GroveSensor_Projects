/***************************************************************
* Name         : toggle Led
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : a simple actuator to alter states where the button rebounds on its own after released
*                      Input : ?
*                      Output: ?  
***************************************************************/
// libraries


// defined items
#define button 4  // define the connected button to D4
#define LED 6     // define the connected LED to D6

// global variables
// initial state of the variable for reading the status of the push button and debounce the push button
int ledState = HIGH;        // the current state of the output pin
int button_state = 0;       // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

/* time measured in milliseconds as a 'unsigned long' datatype, would quickly become a bigger number than can be stored in an int. */
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // baud rate
  // initialize the push button pin as an input device
  pinMode(button, INPUT_PULLUP);
  // initialized the LED as an output device
  pinMode(LED, OUTPUT);

  // set initial LED state
  digitalWrite(LED, ledState);

  delay(1000);  // what for initialization to complete;
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the push button value
  int reading = digitalRead(button);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }


  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != button_state) {
      button_state = reading;

      // only toggle the LED if the new button state is HIGH
      if (button_state == HIGH) {
        ledState = !ledState;
        Serial.println("Button Pressed!");
      }
    }
  }

  // set the LED:
  digitalWrite(LED, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  // end of file
}
