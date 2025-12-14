#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

enum class State { UNCALIBRATED, CALIBRATED, ERROR };

class Sensor {
private:
    int m_id{};
    std::string m_type{};
    float m_gain{};
    float m_offset{};
    State m_state{State::UNCALIBRATED};

public:
    Sensor() = default;
    Sensor(int id, std::string type, float gain, float offset, State state);
    Sensor(const Sensor&) = delete;

    void applyCalibration(float gain, float offset);

    void setState(State&& state);
    void setState(const State&) = delete;

    void print() const;

    float getGain() const;
    State getState() const;
};

#endif // SENSOR_H