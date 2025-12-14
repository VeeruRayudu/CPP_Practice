#include <iostream>
#include <string>
#include "4887766_MD1_Task3_DTC.h"

int main(){

    DTC dtcDefault; //default

    DTC dtcParam("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01"); //parameterized

    //modify attributes of default
    dtcDefault.setCode("P0420");
    dtcDefault.setDescription("Catalyst System Efficiency Below Threshold");
    dtcDefault.setSystem("Exhaust");
    dtcDefault.setOrigin("ECU_02");
    dtcDefault.setOccurrenceCount(2);
    dtcDefault.setLastOccurrenceTime(std::time(nullptr) - 4000);
    dtcDefault.setSeverityLevel(Severity::WARN);
    dtcDefault.setMilOn(false);

    std::cout<<"Risk score of default object: "<<dtcDefault.computeRiskScore()<<"\t"<<dtcDefault.recommendAction();
    std::cout<<"Risk score of parameterized object: "<<dtcDefault.computeRiskScore()<<"\t"<<dtcDefault.recommendAction();

    DTC dtcParamDup("P0301", "", false, 10, (std::time(nullptr) - 100), Severity::WARN, false, true, false, "Engine", "");

    DTC dtcEdge("EX_EDGE", "", false, -5, (std::time(nullptr) + 100000), Severity::INFO, false, false, false, "", "");

    





}