#include "Sensor.h"

namespace {
    std::string toString(State s) {
        switch (s) {
            case State::CALIBRATED: return "CALIBRATED";
            case State::UNCALIBRATED: return "UNCALIBRATED";
            case State::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
}

Sensor::Sensor(int id, std::string type, float gain, float offset, State state)
    : m_id(id), m_type(std::move(type)), m_gain(gain), m_offset(offset), m_state(state) {}

void Sensor::applyCalibration(float gain, float offset) {
    m_gain = gain;
    m_offset = offset;
}

void Sensor::setState(State&& state) {
    m_state = std::move(state);
}

void Sensor::print() const {
    std::cout << "\nSensor ID: " << m_id << "\n"
              << "Sensor Type: " << m_type << "\n"
              << "Gain: " << m_gain << "\n"
              << "Offset: " << m_offset << "\n"
              << "State: " << toString(m_state) << "\n";
}

float Sensor::getGain() const {
    return m_gain;
}

State Sensor::getState() const {
    return m_state;
}