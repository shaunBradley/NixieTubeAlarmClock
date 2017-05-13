#ifndef TIME_H
#define TIME_H
#include "Arduino.h"

// stored in 24 hour time
struct Time
{
  public:
    Time();
    Time(uint8_t hour, uint8_t minute, uint8_t second);
    Time(const Time& objToCopy);
    ~Time();
    bool operator==(const Time& other);
    Time& operator ++();
    Time& operator--();
    void SetTime(uint8_t hour, uint8_t minute, uint8_t second);
    uint8_t GetHour24();
    uint8_t GetHour12();
    uint8_t GetMinute();
    uint8_t GetSecond();
  private:
    uint8_t m_hour, m_minute, m_second;
};
#endif
