#include "4887766_MD4_Task1_Refactored_Vehicle.h"

namespace {
    std::string toString(Status status) {
        switch (status) {
            case Status::OK: return "OK";
            case Status::WARN: return "WARN";
            case Status::FAIL: return "FAIL";
            default: return "UNKNOWN";
        }
    }
}

Vehicle::Vehicle(int id, std::string model, double temperature, double voltage, Status status)
    : m_id(id), m_model(std::move(model)), m_temperature(temperature), m_voltage(voltage), m_status(status) {}

void Vehicle::updateTemperature(double temp) {
    m_temperature = temp;
}

void Vehicle::updateVoltage(double volt) {
    m_voltage = volt;
}

void Vehicle::setStatus(Status&& status) {
    m_status = std::move(status);
}

void Vehicle::print() const {
    std::cout << "Vehicle ID: " << m_id << "\n"
              << "Vehicle Model: " << m_model << "\n"
              << "Temperature: " << m_temperature << "\n"
              << "Voltage: " << m_voltage << "\n"
              << "Status: " << toString(m_status) << "\n\n";
}

void logVehicleByValue(Vehicle v) {
    std::cout << "\nCall By Value:\n";
    v.print();
}

void logVehicleByRef(Vehicle& v) {
    std::cout << "\nCall By Lvalue Reference:\n";
    v.print();
}

void logVehicleByRRef(Vehicle&& v) {
    std::cout << "\nCall By Rvalue Reference:\n";
    v.print();
}

void logVehicleByPtr(Vehicle* v) {
    std::cout << "\nCall By Pointer:\n";
    if (v) {
        v->print();
    } else {
        std::cout << "Null pointer vehicle.\n";
    }
}