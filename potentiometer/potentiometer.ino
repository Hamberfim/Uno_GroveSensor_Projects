/***************************************************************
* Name         : Potententiometer on the Grove Sensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : angle sensor is used to provide a variable 10k ohms resistance to alter the states. Read as an analog value between 0-1023 and a linear rotation of 300 degrees
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                The module can be used to turn on and off a light, as well as change the frequency of a blinking light.
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include "Arduino_SensorKit.h"

// define connection objects
#define LED 6


// global variables
int potentiometer = A0;  // assign to pin A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // init pin
  pinMode(potentiometer, INPUT);  // set pin mode to input
  pinMode(LED, OUTPUT);           //Sets the pinMode to Output

  delay(1000);  // wait for initialization to complete
}

void loop() {
  // put your main code here, to run repeatedly:
  // read potentiometer value from connected pin A0
  int pSensorValue = analogRead(potentiometer);

  // map the read values down-scale to 0-100 to mimic zero to 100 percent.
  byte mappedValue = map(pSensorValue, 0, 1023, 100, 0);  // 100 first so the turn is clockwise to increase the value

  // blink frequency
  digitalWrite(LED, HIGH);
  delay(mappedValue);
  digitalWrite(LED, LOW);
  delay(mappedValue);

  // output to serial monitor
  Serial.print("Potentiometer value: ");
  Serial.println(mappedValue);
  delay(500);  // deley .5 sec before reading potentiometer again.

  // end of file
}
