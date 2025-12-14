#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>

enum class State {UNCALIBRATED, CALIBRATED, ERROR};

class Sensor{
    private:
    int m_id;
    std::string m_type;
    float m_gain;
    float m_offset;
    State m_state;

    public:
    //constructor
    Sensor();
    Sensor(int id_, std::string type_, float gain_, float offset_, State state_);
    Sensor(const Sensor&) = delete;

    //update calibration params
    void applyCalibration(float gain, float offset);

    //state setter
    void setState(State&& ref);
    void setstate(const State&) = delete;

    //display
    void print() const;

    //getter
    float getGain() const;
    State getState() const;
};

#endif