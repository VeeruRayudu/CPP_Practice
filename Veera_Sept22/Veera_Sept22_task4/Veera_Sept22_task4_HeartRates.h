#ifndef HEARTRATES_H
#define HEARTRATES_H
#include<string>

class HeartRates{
    private:
    std::string firstName;
    std::string lastName;
    int dobDay;
    int dobMonth;
    int dobYear;

    public:
    //constructor
    HeartRates(std::string fName, std::string lName, int day, int month, int year);

    //setters
    void setFirstName(const std::string fName);
    void setLastName(const std::string lName);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    //getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    int getAge();

    int getMaximumHeartRate(int age);

    void getTargetHeartRate(int maxHeartRate, double lower, double upper);
};

#endif