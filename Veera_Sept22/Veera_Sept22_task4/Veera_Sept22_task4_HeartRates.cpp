#include<string>
#include<iostream>
#include "Veera_Sept22_task4_HeartRates.h"

//constructor initialization
HeartRates::HeartRates(std::string fName, std::string lName, int day, int month, int year){
    setFirstName(fName);
    setLastName(lName);
    setDay(day);
    setMonth(month);
    setYear(year);
}

//setters
void HeartRates::setFirstName(const std::string fName){
    firstName = fName;
}
void HeartRates::setLastName(const std::string lName){
    lastName = lName;
}
void HeartRates::setDay(int day){
    dobDay = day;
}
void HeartRates::setMonth(int month){
    dobMonth = month;
}
void HeartRates::setYear(int year){
    dobYear = year;
}

//getters
std::string HeartRates::getFirstName() const { return firstName; }
std::string HeartRates::getLastName() const { return lastName; }
int HeartRates::getDay() const { return dobDay; }
int HeartRates::getMonth() const { return dobMonth; }
int HeartRates::getYear() const { return dobYear; }

//age calculation
int HeartRates::getAge(){
    int currentDay;
    int currentMonth;
    int currentYear;
    std::cout<<"Enter current day(1-31): ";
    std::cin>>currentDay;
    std::cout<<"Enter current Month(1-12): ";
    std::cin>>currentMonth;
    std::cout<<"Enter current Year: ";
    std::cin>>currentYear;
    int age = currentYear - getYear();
    if((getMonth()-currentMonth)<0 && (getDay()-currentDay)<0){
        return age;
    }else{
        return age-1;
    }
}

//MaximumHeartRate calculation
int HeartRates::getMaximumHeartRate(int age){
    return 220-age;
}

//TargetHeartRate calculation
void HeartRates::getTargetHeartRate(int maxHeartRate, double lower, double upper){
   lower = maxHeartRate * 0.50;
   upper = maxHeartRate * 0.85; 
}
