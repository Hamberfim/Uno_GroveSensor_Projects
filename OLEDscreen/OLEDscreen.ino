/***************************************************************
* Name         : OLEDscreen on the Grove Sensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : This module is an Organic Light-Emitting Diode(OLED, monochrome) 128×64dot matrix display 
*                that connects with the Grove 4pin I2C Interface and can be used for visual outputs.
*                It uses an organic, carbon based material so that when electricity is applied to this material, it emits light.
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include "Arduino_SensorKit.h"

void setup() {
  // put your setup code here, to run once:
  // init the devices
  Oled.begin();
  // Set the rotation of the screen
  Oled.setFlipMode(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  int random_value = analogRead(A0);          //read value from A0
  Oled.setFont(u8x8_font_chroma48medium8_r);  // set the font to use
  Oled.setCursor(0, 33);                      // Set the Placement Coordinates
  Oled.print("Analog Value:");               // print a label to screen
  Oled.print(random_value);                   // Print the Values to screen
  Oled.refreshDisplay();                      // Update the Display
  delay(3000);
  // Oled.clearDisplay();

  // end of file
}
