#include "Arduino.h"
#include "Time.h"

Time* t1 = new Time(23, 45, 34);
Time* t2 = new Time();
  
void setup() 
{
  // test
  Serial.begin(9600);
  t2->SetTime(23, 45, 34);
  Serial.println(*t1 == *t2 ? "y":"n");
}
void loop()
{
}

