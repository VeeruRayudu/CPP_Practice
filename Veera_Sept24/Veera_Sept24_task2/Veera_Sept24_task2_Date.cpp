#include <iostream>
#include "Veera_Sept24_task2_Date.h"

// Date constructor (should do range checking)
Date::Date( int m, int d, int y )
{
   setDate(m, d, y);
} // end constructor Date

void Date::setDate(int m, int d, int y){
    year = (y>=1) ? y : 2000;
    month = (m>=1 && m<=12) ? m : 1;

    int maxDay = daysInMonth(month, year);
    day = (d>=1 && d<=maxDay) ? d : 1;
}

bool Date::isLeapYear(int y){
    return (y % 400 == 0) || (y%4 == 0 && y%100 != 0);
}

int Date::daysInMonth(int m, int y){
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return (isLeapYear(y) ? 29 : 28);
    
    default:
        return 31;
    }
}

 // print Date in the format mm/dd/yyyy
 void Date::print() 
{ 
  std::cout << month << '/' << day << '/' << year; 
} 

void Date::nextDay(){
    day++;
    if(day > daysInMonth(month, year)){
        day = 1;
        month++;
        if(month > 12){
            month = 1;
            year++;
        }
    }
}