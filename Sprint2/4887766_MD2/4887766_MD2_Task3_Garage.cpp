#include "4887766_MD2_Task3_Garage.h"

// static member
int Garage::vehicleCount = 0;

// constructor
Garage::Garage(std::string location_) : m_location(location_) {}

// add vehicle
void Garage::addVehicle(FleetVehicle &v)
{
    vehicleCount++;
    vehicles.emplace_back(v);
}

// getter
int Garage::getVehicleCount() const { return vehicleCount; }