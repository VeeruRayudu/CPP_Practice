#include "4887766_MD2_Task1_Vehicle.h"

// parameterized
Vehicle::Vehicle(std::string vin_, VehicleType type_) : m_vin(vin_), m_type(type_) {}

std::string Vehicle::getVIN() const noexcept
{
    return m_vin;
}

VehicleType Vehicle::getType() const noexcept
{
    return m_type;
}

Car::Car(std::string vin_, int seatCount_) : Vehicle(vin_, VehicleType::CAR), m_seatCount(seatCount_) {}

// virtual function override
std::string Car::description() const
{
    std::ostringstream oss;
    oss << "\nCar VIN: " << m_vin << ", Number of seats: " << m_seatCount << std::endl;
    return oss.str();
}

Truck::Truck(std::string vin_, double payload_) : Vehicle(vin_, VehicleType::CAR), m_payloadTons(payload_) {}

// virtual function override
std::string Truck::description() const
{
    std::ostringstream oss;
    oss << "\nTruck VIN: " << m_vin << ", Payload: " << m_payloadTons << std::endl;
    return oss.str();
}

void printVehicleInfo(const Vehicle *v)
{
    if (v != nullptr)
    {
        std::cout << v->description() << std::endl;
    }
    else
    {
        std::cout << "\nNo vehicle" << std::endl;
    }
}

