#include <iostream>
#include <string>
#include "4887766_MD1_Task1_Refactored_FleetVehicle.h"

// Default constructor
FleetVehicle::FleetVehicle()
    : vehicleID(0), fuelLevel(50.0f), distanceTravelled(0.0),
      status('A'), isAvailable(true), driverName("Unassigned") {}

// Parameterized constructor
FleetVehicle::FleetVehicle(int vehicleID, float fuelLevel, double distanceTravelled,
                           char status, bool isAvailable, const std::string& driverName)
    : vehicleID(vehicleID), fuelLevel(fuelLevel), distanceTravelled(distanceTravelled),
      status(status), isAvailable(isAvailable), driverName(driverName) {}

// Destructor
FleetVehicle::~FleetVehicle() {
    std::cout << "Destructor called for Vehicle ID: " << vehicleID << std::endl;
}

// Getters
int FleetVehicle::getVehicleID() const { return vehicleID; }
float FleetVehicle::getFuelLevel() const { return fuelLevel; }
double FleetVehicle::getDistanceTravelled() const { return distanceTravelled; }
char FleetVehicle::getStatus() const { return status; }
bool FleetVehicle::getIsAvailable() const { return isAvailable; }
std::string FleetVehicle::getDriverName() const { return driverName; }

// Setters
void FleetVehicle::setVehicleID(int id) { vehicleID = id; }
void FleetVehicle::setFuelLevel(float level) { fuelLevel = level; }
void FleetVehicle::setDistanceTravelled(double distance) { distanceTravelled = distance; }
void FleetVehicle::setStatus(char s) { status = s; }
void FleetVehicle::setIsAvailable(bool available) { isAvailable = available; }
void FleetVehicle::setDriverName(const std::string& name) { driverName = name; }

// Update vehicle status based on fuel and availability
void FleetVehicle::updateStatus() {
    status = (fuelLevel < 10.0f || !isAvailable) ? 'I' : 'A';
}

// Display vehicle information
void FleetVehicle::displayInfo() const {
    std::cout << "Vehicle ID: " << vehicleID
              << ", Fuel Level: " << fuelLevel
              << ", Distance Travelled: " << distanceTravelled
              << ", Status: " << status
              << ", Is Available: " << std::boolalpha << isAvailable
              << ", Driver Name: " << driverName << std::endl;
}

// Assign a driver to a vehicle
void assignDriver(FleetVehicle& vehicle, const std::string& name) {
    vehicle.setDriverName(name);
    std::cout << "Driver " << vehicle.getDriverName()
              << " has been assigned to vehicle ID " << vehicle.getVehicleID() << std::endl;
}

// Refuel a vehicle
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount) {
    if (fuelAmount <= 0.0f) {
        std::cout << "Fuel amount should be greater than zero." << std::endl;
        return;
    }

    float newLevel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.setFuelLevel(newLevel);

    std::cout << "Vehicle ID: " << vehicle.getVehicleID()
              << " refueled. New fuel level: " << newLevel << std::endl;
}