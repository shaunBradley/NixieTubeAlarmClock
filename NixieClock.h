#ifndef NIXIECLOCK_H
#define NIXIECLOCK_H
#include "Clock.h"

class NixieClock final : public Clock
{
  public: 
    NixieClock(const Time& t, const byte latchPin, const byte dataPin, const byte clockPin);// : Clock(t);
    NixieClock& operator =(const NixieClock& objToCopy);
    ~NixieClock();
  private:
    byte m_latchPin, m_dataPin, m_clockPin;
};

#endif
