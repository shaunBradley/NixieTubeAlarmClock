#ifndef CLOCK_H
#define CLOCK_H

struct TimeID
{
  public:
    TimeID(Time&);
    Time* t;
    const char* id;
}

class Clock
{
  public:
    Clock(Time t);
    void Update();
    void AddAlarm();
    void RemoveAlarm();
  protected:
    Time* m_currentTime;
    std::map<char*, Time*> alarms[];
};

#endif
