#include "4887766_MD14_Task1_SensorReading.h"

// parameterized constructor
SensorReading::SensorReading(const std::string &name, const std::variant<int, float, std::string> &val) : m_sensorName(name), m_value(val) {}

// destructor
SensorReading::~SensorReading(){}

// getters
std::string SensorReading::getName() const {return m_sensorName;}

std::string SensorReading::getValueAsString() const {
    return std::visit([](auto&& arg){
        using T = std::decay_t<decltype(arg)>;

        if constexpr (std::is_same_v<T, std::string>){
            return arg;
        }else{
            return std::to_string(arg);
        }
    }, m_value);
}

const std::variant<int, float, std::string>& SensorReading::getVariant() const{
    return m_value;
}

// updating value
void SensorReading::updateValue(const std::variant<int, float, std::string> &newVal){
    m_value = newVal;
}

// free functions
void printSensorReading(const SensorReading &reading){
    std::cout<<"Sensor: "<<reading.getName()<<", Value: "<<reading.getValueAsString();
    std::cout<<"\n";
}