#include<iostream>
#include<string>
#include "Veera_Sept22_task4_HeartRates.h"

int main(){
    
    std::string firstName;
    std::string lastName;
    int birthDay;
    int birthMonth;
    int birthYear;
    std::cout<<"Enter First Name:";
    std::cin>>firstName;
    std::cout<<"Enter Last Name: ";
    std::cin>>lastName;
    std::cout<<"Enter Birth Day(1-31): ";
    std::cin>>birthDay;
    std::cout<<"Enter Birth Month(1-12): ";
    std::cin>>birthMonth;
    std::cout<<"Enter Birth Year: ";
    std::cin>>birthYear;

    HeartRates person(firstName, lastName, birthDay, birthMonth, birthYear);

    std::cout<<"\n-------Personal Information-----------\n";
    std::cout<<"Name: "<<person.getFirstName()<<" "<<person.getLastName()<<std::endl;
    std::cout<<"Date of Birth: "<<person.getDay()<<"/"<<person.getMonth()<<"/"<<person.getYear()<<std::endl;

    int age = person.getAge();
    std::cout<<"Age: "<<age<<" years."<<std::endl;

    int maxHeartRate = person.getMaximumHeartRate(age);
    std::cout<<"Maximum Heart Rate: "<<maxHeartRate<<"bpm"<<std::endl;

    double lower, upper;
    person.getTargetHeartRate(maxHeartRate, lower, upper);
    std::cout<<"Target Heart Rate Range: "<<lower<<" - "<<upper<<"bpm"<<std::endl;

}