// Grove Sensor - a simple actuator to alter states where the button rebounds on its own after released

#define button 4  // define the connected button to D4

// initial state of the variable for reading the status of the push button
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // baud rate
  // initialize the push button pin as an input device
  pinMode(button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the push button value
  button_state = digitalRead(button);

  // check the state of the reading
  if (button_state == HIGH) {
    Serial.println("Button Pressed!");
  }

  delay(50);

}
