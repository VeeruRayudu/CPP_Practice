#include "4887766_MD1_Task2_ECU.h"

// Constructor
ECU::ECU(SensorType type_s)
    : sensor(type_s), actuator(nullptr) {}

// Connects an actuator to the ECU
void ECU::connectActuator(Actuator* act) {
    actuator = act;
}

// Displays the current status of the ECU
void ECU::showStatus() const {
    sensor.showSensor();

    if (actuator == nullptr) {
        std::cout << "No actuator connected." << std::endl;
    } else {
        actuator->showActuator();
    }
}