/***************************************************************
* Name         : BarameterSensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : The Bosch BMP280 high-precision and low-power digital barometer sensor measures temperature and 
*                atmospheric pressure accurately and is used in weather stations for forecasting and applications to collect sensitive data of the environment.
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include "Arduino_SensorKit.h"

// define connection objects

// global variables

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Pressure.begin();

  delay(1000);  // wait for initialization setup to complete
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("\n========== INCOMING DATA ==========");
  // temperatures
  float tempC = Pressure.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("C");

  // Converting the temperature to fehrenheit using the formula fahrenheit = (celsius * 1.8) + 32
  float tempF = (tempC * 1.8) + 32;
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println("F");

  // atmospheric pressure
  Serial.print("Pressure: ");
  Serial.print(Pressure.readPressure());
  Serial.println("Pa");

  // altitude
  Serial.print("Altitude: ");
  Serial.print(Pressure.readAltitude());
  Serial.println("m");

  delay(5000);

  // end of file
}
