#ifndef NIXIECLOCK_H
#define NIXIECLOCK_H
#include "Clock.h"

class NixieClock final : public Clock
{
  public: 
    NixieClock(const Time& t, const byte latchPin, const byte dataPin, const byte clockPin);
    ~NixieClock();
    void Update() override;
    void Test();
  private:
    void ShiftOut(uint8_t number, uint8_t tube);
    void Clear(int holdMicroseconds);
    byte m_latchPin, m_dataPin, m_clockPin;
    const byte tube_1 = 0b100000;
    const byte tube_2 = 0b010000;
    const byte tube_3 = 0b001000;
    const byte tube_4 = 0b000100;
    const byte tube_5 = 0b000010;
    const byte tube_6 = 0b000001;
};

#endif
