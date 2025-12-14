#ifndef ECU_DIAGNOSTIC_H
#define ECU_DIAGNOSTIC_H
#include "4887766_MD2_Task4_DiagnosticTask.h"

class ECUDiagnostic: public DiagnosticTask{
    private:
    std::string m_moduleName;

    public:
    //constructor
    ECUDiagnostic(std::string module_): m_moduleName(module_) {}

    //run override
    bool run() const override {
        if((m_moduleName.length() % 2) == 0){
            return true;
        }else{
            return false;
        }
    }

    Severity getSeverity() const override{
        return Severity::CRITICAL;
    }
};

#endif