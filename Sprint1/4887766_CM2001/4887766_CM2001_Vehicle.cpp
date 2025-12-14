#include "4887766_CM2001_Vehicle.h"

double Vehicle::s_averageFuelPrice = 0.0;

//constructor
Vehicle::Vehicle(std::string vehicleID_, std::string fuelType_, double fuelEfficiency_) : m_vehicleID(vehicleID_), m_fuelType(fuelType_), m_fuelEfficiency(fuelEfficiency_), m_totalDistanceTravelled(0.0), m_totalFuelConsumed(0.0) {};

void Vehicle::trackFuelConsumption(double fuelConsumed_, double distanceTravelled_){
    m_totalDistanceTravelled += distanceTravelled_;
    m_totalFuelConsumed += fuelConsumed_;
    m_fuelEfficiency = m_totalDistanceTravelled/m_totalFuelConsumed;
}

double Vehicle::calculateFuelEconomy() const{
    return m_totalDistanceTravelled/m_totalFuelConsumed;
}

void Vehicle::displayVehicleInfo(){
    std::cout<<"Vehicle ID: "<<m_vehicleID<<"\n"
             <<"Fuel Type: "<<m_fuelType<<"\n"
             <<"Fuel Efficiency: "<<m_fuelEfficiency<<"\n"
             <<"Total Distance Travelled: "<<m_totalDistanceTravelled<<"\n"
             <<"Total fuel consumed: "<<m_totalFuelConsumed<<"\n";
}

void Vehicle::updateAverageFuelPrice(double newPrice){
    s_averageFuelPrice = newPrice;
}

double Vehicle::calculateTotalFuelCost(double distanceToTravel){
    return (distanceToTravel/m_fuelEfficiency)*s_averageFuelPrice;
}

