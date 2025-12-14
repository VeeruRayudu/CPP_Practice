#ifndef SENSOR_READING_H
#define SENSOR_READING_H
#include <iostream>
#include <string>
#include <variant>

class SensorReading{
    private:
    std::string m_sensorName;
    std::variant<int, float, std::string> m_value;

    public:
    //constructor
    SensorReading() = default;

    //parameterized constructor
    SensorReading(const std::string& name, const std::variant<int, float, std::string>& val);

    //destructor
    ~SensorReading();

    //defaulted move and copy operations
    SensorReading(const SensorReading&) = default;
    SensorReading& operator=(const SensorReading&) = default;
    SensorReading(SensorReading&&) = default;
    SensorReading& operator=(SensorReading&&) = default;

    //getters
    std::string getName() const;
    std::string getValueAsString() const;
    const std::variant<int, float, std::string>& getVariant() const;

    //updating value
    void updateValue(const std::variant<int, float, std::string>& newVal);
};

//free functions
void printSensorReading(const SensorReading& reading);

#endif