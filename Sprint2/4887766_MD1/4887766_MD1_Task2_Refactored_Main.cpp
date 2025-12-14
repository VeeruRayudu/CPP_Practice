#include "4887766_MD1_Task2_ECU.h"

int main() {
    ECU ecu(SensorType::TEMPERATURE);

    std::cout << "\nInitial ECU Status:\n";
    ecu.showStatus();

    Actuator actuator(ActuatorType::MOTOR);
    ecu.connectActuator(&actuator);

    std::cout << "\nUpdated ECU Status:\n";
    ecu.showStatus();

    std::cout << std::endl;
    return 0;
}