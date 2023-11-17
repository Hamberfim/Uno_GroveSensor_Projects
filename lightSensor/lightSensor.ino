/***************************************************************
* Name         : Light Sensor on the Grove Sensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : The light sensor is an analog component with values ranging between 0-1023 and a linear rotation of 300 degrees
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                The module is used to measure light intensity and can be used to detect movement, track the movement of the sun and trigger automatic lighting.
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include "Arduino_SensorKit.h"

// define connection objects

// global variables
int lightSensor = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(1000);  // wait for setup intialization to complete
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the raw value form the light sensor
  int rawLight = analogRead(lightSensor);

  // map the raw light sensor values 0-1023 down to 0-100 to represent 0 - 100%
  int light = map(rawLight, 0, 160, 0, 100);  // tighening scale to maiximize reading

  // output to serial monitor
  Serial.print("Light Level: ");
  Serial.println(light);

  delay(500); // add a delay to only read and print every 1 second

  // end of file
}
