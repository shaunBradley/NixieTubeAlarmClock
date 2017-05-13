#include "Arduino.h"
#include "NixieClock.h"
#define clearTime 2500


NixieClock::NixieClock(const Time& t, const byte latchPin, const byte dataPin, const byte clockPin) : Clock(t)
{
  this->m_clockPin = clockPin;
  this->m_dataPin = dataPin;
  this->m_latchPin = latchPin;
}

NixieClock::~NixieClock()
{
  // nothing created with 'new'
}

void NixieClock::Update()
{    
    ShiftOut(this->m_currentTime->GetHour12()/10, this->tube_1);
    Clear(clearTime);
    ShiftOut(this->m_currentTime->GetHour12()%10, this->tube_2); 
    Clear(clearTime);
    ShiftOut(this->m_currentTime->GetMinute()/10, this->tube_3);
    Clear(clearTime);
    ShiftOut(this->m_currentTime->GetMinute()%10, this->tube_4);
    Clear(clearTime);
    ShiftOut(this->m_currentTime->GetSecond()/10, this->tube_5);
    Clear(clearTime);
    ShiftOut(this->m_currentTime->GetSecond()%10, this->tube_6);
    Clear(clearTime);
}

void NixieClock::Test()
{
  
}

void NixieClock::Clear(int holdMicroseconds)
{
    delayMicroseconds(holdMicroseconds);
}

void NixieClock::ShiftOut(uint8_t number, uint8_t tube)
{
   uint16_t value = ((1 << (15 - number)) | (tube));
   
   digitalWrite(7, LOW);
   for (uint16_t i = 0; i < 16; i++) 
   {
       digitalWrite(5, !!(value & (1 << i)));
       // only needs rising edge
       digitalWrite(6, HIGH);
       digitalWrite(6, LOW);            
   }
   digitalWrite(7, HIGH);
}
