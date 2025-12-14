#ifndef BRAKE_CONTROLLER_H
#define BRAKE_CONTROLLER_H
#include "4887766_MD2_Task5_Controller.h"
#include <sstream>

class BrakeController: public Controller{
    private:
    double m_maxForce;

    public:
    //constructor
    BrakeController(std::string name, double maxForce, TelemetryLevel level) : Controller(name, level), m_maxForce(maxForce) {}

    //override operate
    std::string operate(TelemetryProvider* provider) override{
        std::ostringstream oss;
        if(provider == nullptr){
            oss<<"Brake: "<<Controller::m_name<<" FAIL No Telemetry"<<std::endl;
        }else{
            oss<<"Motor: "<<Controller::m_name<<" OK"<<" Telemetry From: "<<provider->getSourceName()<<std::endl;
        }
        return oss.str();
    }
};

#endif