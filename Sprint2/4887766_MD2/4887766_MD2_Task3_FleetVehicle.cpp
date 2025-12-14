#include "4887766_MD2_Task3_FleetVehicle.h"

// constructors initialization
FleetVehicle::FleetVehicle(std::string id_, int horsePower) : FleetVehicle(id_, Engine(horsePower)) {}

FleetVehicle::FleetVehicle(std::string id_, Engine e) : m_id(id_), engine(e) {}

std::string toString(VehicleState s)
{
    switch (s)
    {
    case VehicleState::INTRANSIT:
        return "INTRANSIT";
    case VehicleState::MAINTENANCE:
        return "MAINTENANCE";
    case VehicleState::PARKED:
        return "PARKED";
    default: return "UNKNOWN";
        break;
    }
}

std::string FleetVehicle::status()
{
    std::ostringstream oss;
    oss << "\nID: " << m_id << ", State: " << toString(m_state) << ", HP: " << engine.getHorsePower() << std::endl;
    return oss.str();
}

// setter
void FleetVehicle::setState(VehicleState st)
{
    m_state = st;
}

// getter
int FleetVehicle::getHP() const { return engine.getHorsePower(); }