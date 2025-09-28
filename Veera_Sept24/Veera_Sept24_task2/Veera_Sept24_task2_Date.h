#ifndef DATE_H
#define DATE_H


class Date {
    public:
    Date( int = 1, int = 1, int = 2000 ); //Default constructor 
    
    void setDate(int, int, int);
    void nextDay();
    void print();
private:
    int month;  
    int day;
    int year;

    bool isLeapYear(int);
    int daysInMonth(int, int);
}; 

#endif