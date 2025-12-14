#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

enum class SensorType {
    TEMPERATURE,
    PRESSURE,
    SPEED
};

// Converts SensorType enum to string
[[nodiscard]] std::string toString(const SensorType type);

class Sensor {
private:
    SensorType m_type;

public:
    explicit Sensor(SensorType type);

    void showSensor() const;
};

#endif // SENSOR_H