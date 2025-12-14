#ifndef SENSOR_DIAGNOSTIC_H
#define SENSOR_DIAGNOSTIC_H
#include "4887766_MD2_Task4_DiagnosticTask.h"

class SensorDiagnostic: public DiagnosticTask{
    private:
    int m_sensorID;

    public:
    //constructor
    SensorDiagnostic(int id_): m_sensorID(id_) {}

    //run override
    bool run() const override final{
        if((m_sensorID % 2) == 0){
            return true;
        }else{
            return false;
        }
    }

    //severity accessor override
    Severity getSeverity() const override final{
        if(run()){
            return Severity::INFO;
        }else{
            return Severity::WARNING;
        }
    }
};

#endif