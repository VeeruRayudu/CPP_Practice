#include "4887766_MD4_Task1_Vehicle.h"

// constructor initialization
Vehicle::Vehicle(int id_, std::string model_, double temperature_, double voltage_, Status status_) : m_id(id_), m_model(model_), m_temperature(temperature_), m_voltage(voltage_), m_status(status_) {}

void Vehicle::updateTemperature(double temp)
{
    m_temperature = temp;
}

void Vehicle::updateVoltage(double volt)
{
    m_voltage = volt;
}

void Vehicle::setStatus(Status &&ref)
{
    m_status = std::move(ref);
}

static std::string toString(Status stat)
{
    switch (stat)
    {
    case Status::FAIL:
        return "FAIL";
    case Status::OK:
        return "OK";
    case Status::WARN:
        return "WARN";
    default:
        return "UNKNOWN";
    }
}

void Vehicle::print() const
{
    std::cout << "Vehicle ID: " << m_id << std::endl;
    std::cout << "Vehicle Model: " << m_model << std::endl;
    std::cout << "Temperature: " << m_temperature << std::endl;
    std::cout << "Voltage: " << m_voltage << std::endl;
    std::cout << "Status: " << toString(m_status) << std::endl;
    std::cout << "\n";
};

void logVehicleByValue(Vehicle v)
{
    std::cout << "\nCall By Value:\n";
    v.print();
}

void logVehicleByRef(Vehicle &v)
{
    std::cout << "\nCall By Lvalue Reference:\n";
    v.print();
}

void logVehicleByRRef(Vehicle &&v)
{
    std::cout << "\nCall By Rvalue Reference:\n";
    v.print();
}

void logVehicleByPtr(Vehicle *v)
{
    std::cout << "\nCall By Pointer:\n";
    if (v)
    {
        v->print();
    }
    else
    {
        std::cout << "Null pointer vehicle.\n";
    }
}