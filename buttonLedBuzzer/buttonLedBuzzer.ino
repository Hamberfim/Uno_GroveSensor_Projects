/***************************************************************
* Name         : Button Led Buzzer
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
// a simple actuator to alter states where the button rebounds on its own after released

#define button 4  // define the connected button to D4
#define BUZZER 5 // define the connected BUZZER to D5
#define LED 6  // define the connected LED to D6

// initial state of the variable for reading the status of the push button
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // baud rate
  // initialize the push button pin as an input device
  pinMode(button, INPUT);
  //initialize the buzzer as an output device
  pinMode(BUZZER, OUTPUT);
  // initialized the LED as an output device
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the push button value
  button_state = digitalRead(button);

  // check the state of the reading
  if (button_state == HIGH ) {
    Serial.println("Button Pressed!");
    tone(BUZZER, 95);
    digitalWrite(LED, HIGH);
    delay(50);
  } else {
    noTone(BUZZER);
    digitalWrite(LED, LOW);
    delay(50);
  }

}
