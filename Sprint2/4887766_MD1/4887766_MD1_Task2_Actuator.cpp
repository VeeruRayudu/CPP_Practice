#include "4887766_MD1_Task2_Actuator.h"

//constructor initialization
Actuator::Actuator(ActuatorType type): m_type(type){};

std::string Actuator::toString(ActuatorType t) const{
    switch (t)
    {
    case ActuatorType::DISPLAY : return "DISPLAY";
    case ActuatorType::MOTOR : return "MOTOR";
    case ActuatorType::VALVE: return "VALVE";
    default: return "UNKNOWN";
}
}

//display
void Actuator::showActuator() const {
    std::cout<<"Actuator type: "<<toString(m_type)<<"\n";
}