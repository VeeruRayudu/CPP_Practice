#include <iostream>
#include <iomanip>
#include "Veera_Sept24_task4_ModifiedTime.h"

ModifiedTime::ModifiedTime(int hr, int min, int sec)
{
    if(!setTime(hr, min, sec)){
        hour = minute = second = 0;
    }
}

bool ModifiedTime::setTime(int h, int m, int s)
{
    return setHour(h) && setMinute(m) && setSecond(s);
}

bool ModifiedTime::setHour(int h)
{
    if(h >= 0 && h < 24){
        hour = h;
        return true;
    }
    return false;
}

bool ModifiedTime::setMinute(int m)
{
    if(m >= 0 && m < 60){
        minute = m;
        return true;
    }
    return false;
}

bool ModifiedTime::setSecond(int s)
{
    if(s >= 0 && s < 60){
        second = s;
        return true;
    }
    return false;
}

int ModifiedTime::getHour(){
    return hour;
}
int ModifiedTime::getMinute(){
    return minute;
}

int ModifiedTime::getSecond(){
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