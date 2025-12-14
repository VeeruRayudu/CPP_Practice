#include "4887766_MD14_Task2_SensorData.h"

// parameterized constructor
SensorData::SensorData(const std::string &id, const std::variant<int, float, std::string> &reading) : m_sensorID(id), m_reading(reading) {}

// destructor
SensorData::~SensorData() {}

// getters
std::string SensorData::getId() const { return m_sensorID; }
bool SensorData::isInt() const{
    return std::holds_alternative<int>(m_reading);
}
bool SensorData::isFloat() const{
    return std::holds_alternative<float>(m_reading);
}
bool SensorData::isString() const{
    return std::holds_alternative<std::string>(m_reading);
}
void SensorData::processReading() const{
    std::visit([](auto&& arg){
        std::cout<<"Reading is: "<<arg<<std::endl;
    }, m_reading);
}

const std::variant<int, float, std::string> &SensorData::getVariant() const
{
    return m_reading;
}

std::string SensorData::getType() const {
    if(isInt()){
        return std::string("int");
    }
    if(isFloat()){
        return std::string("float");
    }
    if(isString()){
        return std::string("string");
    }
    return std::string("Invalid");
}

// free functions
void displaySensorInfo(const SensorData &reading)
{
    std::cout << "Sensor ID: " << reading.getId() << ", Type: "<<reading.getType()<< "\n";
}