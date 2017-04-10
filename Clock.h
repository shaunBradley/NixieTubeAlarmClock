#ifndef CLOCK_H
#define CLOCK_H
#include "Time.h"
#include "Dictonary.h"

class Clock
{
  public:
    Clock(const Time& t);
    virtual ~Clock();
    virtual void Update();
    void AddAlarm(const char* id, Time& t);
    void RemoveAlarm(const char* id);
    void ClearAllAlarms();
    Clock& operator =(const Clock& objToCopy);
  protected:
    Time* m_currentTime;
    Dictonary<const char*, Time*>* m_alarms;
};

#endif
