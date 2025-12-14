#include "4887766_MD1_Task2_Actuator.h"

// Converts ActuatorType enum to string
std::string toString(const ActuatorType type) {
    switch (type) {
        case ActuatorType::DISPLAY: return "Display";
        case ActuatorType::MOTOR:   return "Motor";
        case ActuatorType::VALVE:   return "Valve";
        default:                    return "Unknown";
    }
}

// Constructor
Actuator::Actuator(ActuatorType type)
    : m_type(type) {}

// Display actuator type
void Actuator::showActuator() const {
    std::cout << "Actuator type: " << toString(m_type) << std::endl;
}