#include "4887766_MD1_Task2_ECU.h"

//constructor initialization
ECU::ECU(SensorType type_s): sensor(type_s), actuator(nullptr){};

void ECU::connectActuator(Actuator* act){
    actuator = act;
}

void ECU::showStatus() const{
    sensor.showSensor();
    if(actuator == nullptr){
        std::cout<<"No actuator connected"<<"\n";
    }else{
        actuator->showActuator();
    }
}