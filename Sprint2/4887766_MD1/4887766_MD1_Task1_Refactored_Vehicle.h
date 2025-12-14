#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    std::string m_vin;
    int m_year;

public:
    explicit Vehicle(const std::string& vin, int year);
    virtual ~Vehicle() = default;

    virtual void displayInfo() const;
    virtual void runDiagnostics() const;
};

// Derived class: Car
class Car : public Vehicle {
private:
    int m_numDoors;

public:
    Car(const std::string& vin, int year, int numDoors);
    void displayInfo() const override;
    void runDiagnostics() const override;
};

// Derived class: Truck
class Truck : public Vehicle {
private:
    double m_payloadCapacity;

public:
    Truck(const std::string& vin, int year, double payloadCapacity);
    void displayInfo() const override;
    void runDiagnostics() const override;
};

// Derived class: ElectricCar
class ElectricCar : public Vehicle {
private:
    double m_batteryHealth;

public:
    ElectricCar(const std::string& vin, int year, double batteryHealth);
    void displayInfo() const override;
    void runDiagnostics() const final override;
};

#endif // VEHICLE_H