#include "4887766_MD1_Task2_Sensor.h"

std::string toString(SensorType t){
    switch (t)
    {
    case SensorType::PRESSURE: return "PRESSURE";
    case SensorType::SPEED: return "SPEED";
    case SensorType::TEMPERATURE: return "Temperature";
    default: return "UNKNOWN";
}
}

//constructor initialization
Sensor::Sensor(SensorType type): m_type(type){};

//display
void Sensor::showSensor() const {
    std::cout<<"Sensor type: "<<toString(m_type)<<"\n";
}