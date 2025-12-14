#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    std::string m_model;
    int m_year;

public:
    Vehicle(); // Default constructor
    explicit Vehicle(const std::string& model, int year); // Parameterized constructor

    void show() const;
};

#endif // VEHICLE_H