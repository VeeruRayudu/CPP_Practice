#include "4887766_MD1_Task1_Refactored_Vehicle.h"

// ─── Vehicle Base Class ───────────────────────────────────────────────

Vehicle::Vehicle(const std::string& vin, int year)
    : m_vin(vin), m_year(year) {}

void Vehicle::displayInfo() const {
    std::cout << "Vehicle identification number: " << m_vin << "\n"
              << "Manufacturing year: " << m_year << std::endl;
}

void Vehicle::runDiagnostics() const {
    std::cout << "Running generic diagnostics." << std::endl;
}

// ─── Car Class ────────────────────────────────────────────────────────

Car::Car(const std::string& vin, int year, int numDoors)
    : Vehicle(vin, year), m_numDoors(numDoors) {}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Number of doors: " << m_numDoors << std::endl;
}

void Car::runDiagnostics() const {
    std::cout << "Running car diagnostics." << std::endl;
}

// ─── Truck Class ──────────────────────────────────────────────────────

Truck::Truck(const std::string& vin, int year, double payloadCapacity)
    : Vehicle(vin, year), m_payloadCapacity(payloadCapacity) {}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Payload capacity: " << m_payloadCapacity << std::endl;
}

void Truck::runDiagnostics() const {
    std::cout << "Running truck diagnostics." << std::endl;
}

// ─── ElectricCar Class ────────────────────────────────────────────────

ElectricCar::ElectricCar(const std::string& vin, int year, double batteryHealth)
    : Vehicle(vin, year), m_batteryHealth(batteryHealth) {}

void ElectricCar::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Battery health: " << m_batteryHealth << std::endl;
}

void ElectricCar::runDiagnostics() const {
    std::cout << "Running electric car diagnostics." << std::endl;
}