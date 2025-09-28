#include<iostream>
#include<string>
#include "Veera_Sept22_task5_HealthProfile.h"

//constructor initialization
HealthProfile::HealthProfile(std::string fName, std::string lName, std::string gender_, int day, int month, int year, int height_, int weight_){
    setFirstName(fName);
    setLastName(lName);
    setGender(gender_);
    setDay(day);
    setMonth(month);
    setYear(year);
    setHeight(height_);
    setWeight(weight_);
}

//setters
void HealthProfile::setFirstName(const std::string fName){
    firstName = fName;
}
void HealthProfile::setLastName(const std::string lName){
    lastName = lName;
}
void HealthProfile::setGender(const std::string gender_){
    gender = gender_;
}
void HealthProfile::setDay(int day){
    dobDay = day;
}
void HealthProfile::setMonth(int month){
    dobMonth = month;
}
void HealthProfile::setYear(int year){
    dobYear = year;
}
void HealthProfile::setHeight(int height_){
    height = height_;
}
void HealthProfile::setWeight(int weight_){
    weight = weight_;
}



//getters
std::string HealthProfile::getFirstName() const { return firstName; }
std::string HealthProfile::getLastName() const { return lastName; }
std::string HealthProfile::getGender() const { return gender; }
int HealthProfile::getDay() const { return dobDay; }
int HealthProfile::getMonth() const { return dobMonth; }
int HealthProfile::getYear() const { return dobYear; }
int HealthProfile::getHeight() const { return height; }
int HealthProfile::getWeight() const { return weight; }


//age calculation
int HealthProfile::getAge(){
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
int HealthProfile::getMaximumHeartRate(int age){
    return 220-age;
}

//TargetHeartRate calculation
void HealthProfile::getTargetHeartRate(int maxHeartRate, double lower, double upper){
   lower = maxHeartRate * 0.50;
   upper = maxHeartRate * 0.85; 
}

//BMI calculation
double HealthProfile::getBMI(int age){
    return (getWeight() * 703) / (getHeight() * getHeight());
}