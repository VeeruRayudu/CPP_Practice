#ifndef DATE_H
#define DATE_H
#include <cstdint>

class Date{
    private:
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;
    static const unsigned int m_monthsPerYear = 12;
    
    public:
    //constructors
    Date(); //default
    Date(unsigned int day_, unsigned int month_, unsigned int year_);       //parameterized
    ~Date();

    //utility functions
    int checkDay(int testday);
    bool checkMaxDays(int month_, int day_);
    void print();
};

#endif