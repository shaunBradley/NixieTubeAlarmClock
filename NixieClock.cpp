#include "Arduino.h"
#include "NixieClock.h"

NixieClock::NixieClock(const Time& t, const byte latchPin, const byte dataPin, const byte clockPin) : Clock(t)
{
  this->m_clockPin = clockPin;
  this->m_dataPin = dataPin;
  this->m_latchPin = latchPin;
}

NixieClock& NixieClock::operator =(const NixieClock& objToCopy)
{
  
}

