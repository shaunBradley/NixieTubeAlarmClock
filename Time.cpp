#include "Time.h"
#include "Arduino.h"

Time::Time()
{
  this->m_hour = 0;
  this->m_minute = 0;
  this->m_second = 0;
}

Time::Time(uint8_t hour, uint8_t minute, uint8_t second)
{
    this->SetTime(hour, minute, second);
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

void Time::SetTime(uint8_t hour, uint8_t minute, uint8_t second)
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

Time& Time::operator ++()
{
   if(this->m_second >= 59)
   {
      this->m_second = 0;
      if(this->m_minute >= 59)
      {
        this->m_minute = 0;
        if(this->m_hour >= 23)
        {
          this->m_hour = 0;
        }
        else
        {
          this->m_hour++;
        }
      }
      else
      {
        this->m_minute++;
      }
   }
   else
   {
     this->m_second++;
   }
   return *this;
}

Time& Time::operator--()
{
   if(this->m_second <= 0)
   {
      this->m_second = 59;
      if(this->m_minute <= 0)
      {
        this->m_minute = 59;
        if(this->m_hour <= 0)
        {
          this->m_hour = 23;
        }
        else
        {
          this->m_hour--;
        }
      }
      else
      {
        this->m_minute--;
      }
   }
   else
   {
     this->m_second--;
   }
   return *this;
}

uint8_t Time::GetHour24()
{
  return this->m_hour;
}

uint8_t Time::GetHour12()
{
  if(this->m_hour > 12){return this->m_hour - 12; }
  else{ return this->m_hour;}
}

uint8_t Time::GetMinute()
{
  return this->m_minute;
}

uint8_t Time::GetSecond()
{
  return this->m_second;
}

