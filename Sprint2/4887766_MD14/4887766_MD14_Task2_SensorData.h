#ifndef SENSOR_DATA
#define SENSOR_DATA
#include <iostream>
#include <string>
#include <variant>

class SensorData{
    private:
    std::string m_sensorID;
    std::variant<int, float, std::string> m_reading;

    public:
    //constructor
    SensorData() = default;

    //parameterized constructor
    SensorData(const std::string& id, const std::variant<int, float, std::string>& reading);

    //destructor
    ~SensorData();

    //defaulted move and copy operations
    SensorData(const SensorData&) = default;
    SensorData& operator=(const SensorData&) = default;
    SensorData(SensorData&&) = default;
    SensorData& operator=(SensorData&&) = default;

    //getters
    std::string getId() const;
    bool isInt() const;
    bool isFloat() const;
    bool isString() const;
    void processReading() const;
    std::string getType() const;
    const std::variant<int, float, std::string>& getVariant() const;
};

//free function
void displaySensorInfo(const SensorData& data);

#endif