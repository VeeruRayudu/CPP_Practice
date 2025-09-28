#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime{
    public:
    DateAndTime(int=1, int=1, int=2000, int=0, int=0, int=0);

    //date func
    void setDate(int, int, int);
    void nextDay();

    //time func
    void setTime(int, int, int);
    void tick();

    void printUniversal();
    void printStandard();

    private:
    int month;
    int day;
    int year;
    int hour;
    int minute;
    int second;

    bool isLeapYear(int);
    int daysInMonth(int, int);
};
#endif
