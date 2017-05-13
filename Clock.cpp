#include "Arduino.h"
#include "Clock.h"

Clock::Clock(const Time& t)
{
  this->m_currentTime = new Time(t);
}

Clock::~Clock()
{
  // nothing created with 'new'
}

void Clock::Tick()
{
  (*this->m_currentTime)++;
}

void Clock::AddAlarm(const char* id, Time& t)
{
  
}

void Clock::RemoveAlarm(const char* id)
{
  
}

void Clock::ClearAllAlarms()
{
  
}
