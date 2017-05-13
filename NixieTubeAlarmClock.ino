#include "Arduino.h"
#include "Time.h"
#include "NixieClock.h"

Time t1(12, 50, 0);
NixieClock nixie(t1, 7, 5, 6);

void Tick()
{
  nixie.Tick();
}
  
void setup() 
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(8), Tick, RISING);
}
void loop()
{
  nixie.Update();
  nixie.Tick();
}
/*
     SN74HC595 #1
      ----------
 ----| 1     16 |----
 ----| 2      5 |----
 ----| 3     14 |----
 ----| 4     13 |----
 ----| 5     12 |----
 ----| 6     11 |----
 ----| 7     10 |----
 ----| 8      9 |----
      ----------
     SN74HC595 #2
      ----------
 ----| 1     16 |----
 ----| 2      5 |----
 ----| 3     14 |----
 ----| 4     13 |----
 ----| 5     12 |----
 ----| 6     11 |----
 ----| 7     10 |----
 ----| 8      9 |----
      ----------
      
*/

