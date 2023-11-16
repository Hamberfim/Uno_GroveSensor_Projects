/***************************************************************
* Name         : Sound Sensor
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : The sound sensor vibrations whcih case a plate in the sensor to bend back and forth which causes a change in voltage that can be measured
*                !!! BOARD SHOULD BE SET TO 5V FOR CORRECT VALUES !!!
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries

// global variables
int soundSensor = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int soundValue = 0;
  for (byte i = 0; i < 32; i++) {
    soundValue += analogRead(soundSensor);
  }

  // bitshift operations
  soundValue >>= 5;
  Serial.println(soundValue);  // output sensor value

  //if a value higher than 500 is registered, we will print the following
  //this is done so that we can clearly see if the threshold is met
  if (soundValue > 250) {
    Serial.println("         ||        ");
    Serial.println("       ||||||      ");
    Serial.println("     |||||||||     ");
    Serial.println("   |||||||||||||   ");
    Serial.println(" ||||||||||||||||| ");
    Serial.println("   |||||||||||||   ");
    Serial.println("     |||||||||     ");
    Serial.println("       ||||||      ");
    Serial.println("         ||        ");
  }
  delay(50);  //a shorter delay between readings

  // end of file
}
