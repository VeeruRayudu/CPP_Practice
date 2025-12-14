#include "4887766_MD1_Task2_Sensor.h"

// Converts SensorType enum to string
std::string toString(const SensorType type) {
    switch (type) {
        case SensorType::PRESSURE:    return "Pressure";
        case SensorType::SPEED:       return "Speed";
        case SensorType::TEMPERATURE: return "Temperature";
        default:                      return "Unknown";
    }
}

// Constructor
Sensor::Sensor(SensorType type)
    : m_type(type) {}

// Display sensor type
void Sensor::showSensor() const {
    std::cout << "Sensor type: " << toString(m_type) << std::endl;
}