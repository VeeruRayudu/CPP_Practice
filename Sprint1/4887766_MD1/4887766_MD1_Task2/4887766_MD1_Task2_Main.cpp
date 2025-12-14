#include<iostream>
#include<string>
#include<ctime>
#include "4887766_MD1_Task2_DTC.h"

int main(){
    DTC dtc1;
    DTC dtc2("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");
    
    dtc1.setCode("P0101");
    dtc1.setDescription("Mass Air flow sensor fault");

    dtc1.incrementOccurrence();
    dtc2.incrementOccurrence();

    dtc2.toggleMIL();
    dtc2.markConfirmed();

    std::cout<<"First Object: "<<"\n";
    dtc1.printDTCInfo();
    std::cout<<"second Object: "<<"\n";
    dtc2.printDTCInfo();
}