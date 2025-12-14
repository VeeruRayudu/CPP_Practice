#include <iostream>
#include <stdexcept>
#include "4887766_CM1001_Date.h"

// constructors
Date::Date() : m_day(0), m_month(0), m_year(0) {};                                                                       // default
Date::Date(unsigned int day_, unsigned int month_, unsigned int year_) : m_day(day_), m_month(month_), m_year(year_) {}; // parameterized

Date::~Date(){};

bool Date::checkMaxDays(int month_, int day_)
{
    if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
    {
        return day_<=30;
    }else if(month_ == 2){
        return false;
    }else{
        return day_ <= 31;
    }
}

int Date::checkDay(int testday)
{
    bool isLeap = (m_year % 4 == 0);
    if(m_month == 2){
        if((isLeap && testday<=29) || (!isLeap && testday <= 28)){
            return testday;
        }else{
            throw std::invalid_argument("Invalid day for February");
        }
    }else{
        if(checkMaxDays(m_month, testday)){
            return testday;
        }else{
            throw std::invalid_argument("Invalid day for given month");
        }
    }
    return 0;
}

void Date::print(){
    std::cout<<m_day<<"-"<<m_month<<"-"<<m_year<<"\n";
}
