#ifndef TIME_H
#define TIME_H
#include "Arduino.h"

typedef unsigned short ushort;

// stored in 24 hour time
struct Time
{
  public:
    Time();
    Time(ushort hour, ushort minute, ushort second);
    Time(const Time& objToCopy);
    ~Time();
    bool operator==(const Time& other);
    void SetTime(ushort hour, ushort minute, ushort second);
    ushort GetHour();
    ushort GetMinute();
    ushort GetSecond();
  private:
    ushort m_hour, m_minute, m_second;
};
#endif
