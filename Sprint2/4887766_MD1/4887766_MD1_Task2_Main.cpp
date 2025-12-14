#include "4887766_MD1_Task2_ECU.h"

int main(){
    ECU ecu(SensorType::TEMPERATURE);
    ecu.showStatus();
    Actuator act(ActuatorType::MOTOR);
    ecu.connectActuator(&act);
    ecu.showStatus();

    return 0;
}