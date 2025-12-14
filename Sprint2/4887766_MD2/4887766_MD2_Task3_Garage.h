#ifndef GARAGE_H
#define GARAGE_H
#include "4887766_MD2_Task3_FleetVehicle.h"
#include <iostream>
#include <vector>

class Garage{
    private:
    std::string m_location;
    std::vector<FleetVehicle> vehicles;
    static int vehicleCount;

    public:
    //constructor
    Garage(std::string location_);

    //add vehicle 
    void addVehicle(FleetVehicle& v);

    //getter
    int getVehicleCount() const;
};

#endif