#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle{
    private:
    std::string m_vehicleID;
    std::string m_fuelType;
    double m_fuelEfficiency;
    double m_totalDistanceTravelled;
    double m_totalFuelConsumed;
    static double s_averageFuelPrice;

    public:
    Vehicle(std::string vehicleID_, std::string fuelType_, double fuelEfficiency_);
    void trackFuelConsumption(double fuelConsumed_, double distanceTravelled_);
    double calculateFuelEconomy() const;
    void displayVehicleInfo();
    void updateAverageFuelPrice(double newPrice);
    double calculateTotalFuelCost(double distanceToTravel);

};

#endif
