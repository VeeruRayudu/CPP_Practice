#include <iostream>
#include "4887766_MD3_Task1_DTC.h"

int main(){
    DTC dtcParam("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");

    if(isSevere(dtcParam)){
        std::cout<<"DTC param1 severity is critical"<<std::endl;
    }else{
        std::cout<<"DTC param1 severity: "<<severityToString(dtcParam.getSeverityLevel())<<"\n";
    }
    

    DTC::DTCDiagnostics dtcDiag;
    dtcDiag.reportStatus(dtcParam);

    resetDTC(dtcParam);
    dtcParam.printDTCInfo();

    DTC dtcParam2("U1000", "Comm Bus Fault", true, 5, std::time(nullptr) - 60, Severity::WARN, false, true, false, "Network", "Gateway");

    if(isSevere(dtcParam2)){
        std::cout<<"DTC param1 severity is critical"<<std::endl;
    }else{
        std::cout<<"DTC param1 severity: "<<severityToString(dtcParam2.getSeverityLevel())<<"\n";
    }
    dtcDiag.reportStatus(dtcParam2);

    std::cout<<"Total number of instances: "<<DTC::getDTCCount()<<std::endl;


}