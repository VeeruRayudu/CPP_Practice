#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle{
    private:
    std::string m_model;
    int m_year;

    public:
    //parameterized constructor
    Vehicle(std::string model_, int year_);

    //default 
    Vehicle();

    //display
    void show() const;
};

#endif