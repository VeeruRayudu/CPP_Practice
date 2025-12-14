#include "4887766_MD1_Task1_Vehicle.h"

//base class constructor
Vehicle::Vehicle(std::string vin_, int year_): m_vin(vin_), m_year(year_) {};

void Vehicle::runDiagnostics()const{
    std::cout<<"Running generic Diagnostics."<<std::endl;
}

void Vehicle::displayInfo() const{
    std::cout<<"Vehicle identification number: "<<m_vin<<"\n"
             <<"Manufacturing year: "<<m_year<<std::endl;
}

//car class constructor
Car::Car(std::string vin_, int year_, int numDoors_) : Vehicle(vin_, year_), m_numDoors(numDoors_) {};

void Car::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"Number of doors: "<<m_numDoors<<std::endl;
}

void Car::runDiagnostics() const {
    std::cout<<"Running car diagnostics."<<std::endl;
}

//Truck class constructor
Truck::Truck(std::string vin_, int year_, double payloadCapacity_) : Vehicle(vin_, year_), m_payloadCapacity(payloadCapacity_) {};

void Truck::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"Payload Capacity: "<<m_payloadCapacity<<std::endl;
}

void Truck::runDiagnostics() const {
    std::cout<<"Running truck diagnostics."<<std::endl;
}

//ElectricCar class constructor
ElectricCar::ElectricCar(std::string vin_, int year_, double batteryHealth_) : Vehicle(vin_, year_), m_batteryHealth(batteryHealth_) {};

void ElectricCar::displayInfo() const{
    Vehicle::displayInfo();
    std::cout<<"Battery Health: "<<m_batteryHealth<<std::endl;
}

void ElectricCar::runDiagnostics() const {
    std::cout<<"Running electric car diagnostics."<<std::endl;
}