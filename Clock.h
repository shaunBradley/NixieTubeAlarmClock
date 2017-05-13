#ifndef CLOCK_H
#define CLOCK_H
#include "Time.h"

class Clock
{
  public:
    Clock(const Time& t);
    virtual ~Clock();
    virtual void Update();
    void Tick();
    void AddAlarm(const char* id, Time& t);
    void RemoveAlarm(const char* id);
    void ClearAllAlarms();
  protected:
    Time* m_currentTime;
    
};

#endif
