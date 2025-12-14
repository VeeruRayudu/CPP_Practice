#ifndef ECU_H
#define ECU_H
#include "4887766_MD1_Task2_Sensor.h"
#include "4887766_MD1_Task2_Actuator.h"

class ECU{
    private:
    Sensor sensor;
    Actuator* actuator;

    public:
    //constructor
    ECU(SensorType type_s);

    void connectActuator(Actuator* act);
    void showStatus() const;
};

#endif