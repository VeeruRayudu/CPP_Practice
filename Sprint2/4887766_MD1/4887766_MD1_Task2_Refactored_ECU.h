#ifndef ECU_H
#define ECU_H

#include "4887766_MD1_Task2_Sensor.h"
#include "4887766_MD1_Task2_Actuator.h"

class ECU {
private:
    Sensor sensor;
    Actuator* actuator; // Assumes external ownership

public:
    explicit ECU(SensorType sensorType);

    void connectActuator(Actuator* act);
    void showStatus() const;
};

#endif // ECU_H