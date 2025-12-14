#include "4887766_MD4_Task2_Sensor.h"

//constructor initialization
Sensor::Sensor() {}
Sensor::Sensor(int id_, std::string type_, float gain_, float offset_, State state_) : m_id(id_), m_type(type_), m_gain(gain_), m_offset(offset_), m_state(state_) {}

//update calibration params
void Sensor::applyCalibration(float gain, float offset){
    m_gain = gain;
    m_offset = offset;
}

//state setter
void Sensor::setState(State&& ref){
    m_state = std::move(ref);
}

static std::string toString(State s){
    switch (s)
    {
    case State::CALIBRATED : return "CALIBRATED";
    case State::UNCALIBRATED : return "UNCALIBRATED";
    case State::ERROR : return "ERROR";
    default: return "UNKNOWN";
    }
}

//display
void Sensor::print() const{
    std::cout<<"\nSensor ID: "<<m_id<<std::endl;
    std::cout<<"Sensor Type: "<<m_type<<std::endl;
    std::cout<<"Gain: "<<m_gain<<std::endl;
    std::cout<<"Offset: "<<m_offset<<std::endl;
    std::cout<<"State: "<<toString(m_state)<<std::endl;
}

//getter
float Sensor::getGain() const{
    return m_gain;
}
State Sensor::getState() const{
    return m_state;
}