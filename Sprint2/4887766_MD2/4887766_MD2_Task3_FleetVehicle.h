#ifndef FLEET_VEHICLE_H
#define FLEETVEHICLE_H
#include "4887766_MD2_Task3_Engine.h"
#include <iostream>
#include <sstream>

class FleetVehicle
{
private:
    std::string m_id;
    VehicleState m_state = VehicleState::PARKED;
    Engine engine;

    public:
    //deleted default constructor
    FleetVehicle() = delete;

    FleetVehicle(std::string id_, int horsePower);

    FleetVehicle(std::string id_, Engine e);

    std::string status();

    //setter
    void setState(VehicleState st);

    //getter
    int getHP() const;
};

#endif