#include<iostream>
#include<string>
#include "Veera_Sept22_task5_HealthProfile.h"

int main(){
    
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    int height;
    int weight;
    std::cout<<"Enter First Name:";
    std::cin>>firstName;
    std::cout<<"Enter Last Name: ";
    std::cin>>lastName;
    std::cout<<"Enter your gender: ";
    std::cin>>gender;
    std::cout<<"Enter Birth Day(1-31): ";
    std::cin>>birthDay;
    std::cout<<"Enter Birth Month(1-12): ";
    std::cin>>birthMonth;
    std::cout<<"Enter Birth Year: ";
    std::cin>>birthYear;
    std::cout<<"Enter height(inches): ";
    std::cin>>height;
    std::cout<<"Enter weight(pounds): ";
    std::cin>>weight;

    HealthProfile person(firstName, lastName, gender, birthDay, birthMonth, birthYear, height, weight);

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

    double BMI = person.getBMI(age);
    std::cout<<"Body Mass Index (BMI): "<<BMI<<std::endl;

    std::cout<<" BMI VALUES"<<std::endl;
    std::cout<<"Underweight: less than 18.5\n  Normal: between 18.5 and 24.9\n Overweight: between 25 and 29.9\n  Obese: 30 or greater"<<std::endl;


}