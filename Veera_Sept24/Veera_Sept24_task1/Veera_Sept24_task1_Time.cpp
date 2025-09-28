#include <iostream>
#include <iomanip>
#include "Veera_Sept24_task1_Time.h"

ModifiedTime::ModifiedTime(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

void ModifiedTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void ModifiedTime::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

void ModifiedTime::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0; // validate minute
}

// set second value
void ModifiedTime::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0; // validate second
}

int ModifiedTime::getHour()
{
    return hour;
}
int ModifiedTime::getMinute()
{
    return minute;
}

int ModifiedTime::getSecond()
{
    return second;
}

void ModifiedTime::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":" << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
}

void ModifiedTime::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

void ModifiedTime::tick()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
}
