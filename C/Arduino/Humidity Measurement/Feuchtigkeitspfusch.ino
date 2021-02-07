/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#include <stdio.h>

using namespace std;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  Serial1.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  int temp = analogRead(A4);
  int humidity = analogRead(A5);
  char tempa[4];
  char humidc[3];
  
  //int humid = (0.8 +(1.25/40)*humidity); //nur für konstante Temperatur
  float humid = (100* humidity/1024);
  if (humid < 0)
   { humid = 0;}
  float Tempvalue = (5*100 * temp/1024); 
 // String
  String(Tempvalue).toCharArray(tempa,3);
  String(humid).toCharArray(humidc,3);
  Serial.println(String(temp));
  Serial.println();
  Serial1.write(254);                 // wait for a second
  Serial1.write(128);
  Serial1.write("                ");
  Serial1.write("                ");
  Serial1.write(254);                 // wait for a second
  Serial1.write(128);
  Serial1.write("Temperatur :");
  Serial1.write(tempa);
  Serial1.write(" C");
  Serial1.write("Feuchte :");
  Serial1.write(humidc);
  Serial1.write(" %");
  
  
  delay(1000);
 
}
