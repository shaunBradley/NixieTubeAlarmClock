#include "Time.h"
#include "Arduino.h"

Time::Time()
{
  this->m_hour = 0;
  this->m_minute = 0;
  this->m_second = 0;
}

Time::Time(ushort hour, ushort minute, ushort second)
{
    this->SetTime(hour, minute, second);
}

void Time::SetTime(ushort hour, ushort minute, ushort second)
{
  if (hour < 24){this->m_hour = hour;}
  if (minute < 60){this->m_minute = minute;}  
  if (second < 60){this->m_second = second;}
}

bool Time::operator==(const Time& other)
{
  if
  (
    this->m_hour == other.m_hour &&
    this->m_minute == other.m_minute &&
    this->m_second == other.m_second 
  )
  {return true;}
  else {return false;}
}

Time::Time(const Time& objToCopy)
{
  this->m_hour = objToCopy.m_hour;
  this->m_minute = objToCopy.m_minute;
  this->m_second = objToCopy.m_second;
}

Time::~Time()
{
  // nothing created with 'new'
}

ushort Time::GetHour()
{
  return this->m_hour;
}

ushort Time::GetMinute()
{
  return this->m_minute;
}

ushort Time::GetSecond()
{
  return this->m_second;
}

