/***************************************************************
* Name         : Button LED on the Grove Sensor
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
int button_state = 0;       // the current reading from the input pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // baud rate
  // initialize the push button pin as an input device
  pinMode(button, INPUT_PULLUP);
  // initialized the LED as an output device
  pinMode(LED, OUTPUT);

  delay(1000);  // what for initialization to complete;
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the push button value
  button_state = digitalRead(button);

  // check the state of the reading
  if (button_state == HIGH) {
    Serial.println("Button Pressed!");
    digitalWrite(LED, HIGH);
    delay(50);
  } else {
    digitalWrite(LED, LOW);
    delay(50);
  }

  // end of file
}
