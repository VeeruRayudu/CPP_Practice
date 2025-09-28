#ifndef TIME_H
#define TIME_H

class ModifiedTime
{
public:
    ModifiedTime(int = 0, int = 0, int = 0);

    // set functions
    bool setTime(int, int, int);
    bool setHour(int);
    bool setMinute(int);
    bool setSecond(int);

    // get functions
    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandard();

private:
    int hour;   // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second;
};
#endif