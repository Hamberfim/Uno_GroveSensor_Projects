/***************************************************************
* Name         : TempHumiditySensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : This module is used for recording local environmental data. It uses the DHT20 sensor (short for Digital, Humidity, Temperature), 
*               which can retrieve values in both analog and digital format. Using digital in here.
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#define DHTPIN 3  // By default its connected to pin D3, it can be changed, define it before the #include of the library
#include "Arduino_SensorKit.h"

//uncomment line below if using DHT20
#define Environment Environment_I2C

void setup() {
  //uncomment line below if using DHT20
  Wire.begin();
  Serial.begin(9600);
  Environment.begin();
}

void loop() {
  Serial.println("\n====== DATA ======");

  float tempC = Environment.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(tempC);  //print temperature
  Serial.println(" C");

  // Converting the temperature to fehrenheit using the formula fahrenheit = (celsius * 1.8) + 32
  float tempF = (tempC * 1.8) + 32;
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println("F");

  Serial.print("Humidity = ");
  Serial.print(Environment.readHumidity());  //print humidity
  Serial.println("%");
  delay(5000);
}