/***************************************************************
* Name         : AccelerometerSensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : This module is known as the digital triaxial accelerometer and measures movement in the x, y and the z axes. 
*                The module attaches to the board through the I2C pin and with this module, you can easily add motion monitoring to your design.
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include "Arduino_SensorKit.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Accelerometer.begin();

  delay(1000);  // wait for initialization of setup
}

void loop() {
  // put your main code here, to run repeatedly:
  // the 3 axis
  Serial.print("xTilt: ");
  Serial.print(Accelerometer.readX());  // Read the X Value
  Serial.print("  ");
  Serial.print("yTilt: ");
  Serial.print(Accelerometer.readY());  // Read the Y Value
  Serial.print("  ");
  Serial.print("zTilt: ");
  Serial.println(Accelerometer.readZ());  // Read the Z Value

  delay(500);
}
