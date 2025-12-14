#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle{
    protected:
    std::string m_vin;
    int m_year;

    public:
    //constructor
    Vehicle(std::string vin_, int year_);

    //destructor
    virtual ~Vehicle() = default;

    //display function
    virtual void displayInfo() const;

    virtual void runDiagnostics() const;
};

class Car: public Vehicle{
    private:
    int m_numDoors;

    public:
    Car(std::string vin_, int year_, int numDoors_);
    void displayInfo() const override;
    void runDiagnostics() const override;
};

class Truck: public Vehicle{
    private:
    double m_payloadCapacity;

    public:
    Truck(std::string vin_, int year_, double payloadCapacity_);
    void displayInfo() const override;
    void runDiagnostics() const override;
};

class ElectricCar: public Vehicle{
    private:
    double m_batteryHealth;

    public:
    ElectricCar(std::string vin_, int year_, double batteryHealth_);
    void displayInfo() const override;
    void runDiagnostics() const final override;
};

#endif