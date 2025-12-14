#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>

enum class SensorType {TEMPERATURE, PRESSURE, SPEED};

//enum to string 
std::string toString(SensorType t);

class Sensor{
    private:
    SensorType m_type;

    public:
    //constructor
    Sensor(SensorType type);

    //display
    void showSensor() const;
};

#endif