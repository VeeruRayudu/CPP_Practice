#include <iostream>
#include "4887766_MD4_Task1_EngineDTC.h"

int main(){
    EngineDTC engineDTC("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600,  Severity::CRIT, true, false, true, "Engine", "ECU_01" ,3800, 95.2);

    engineDTC.setPending(true);
    engineDTC.setMilOn(false);
    engineDTC.setCoolantTemp(150.0);

    engineDTC.incrementOccurrence();
    engineDTC.toggleMIL();
    engineDTC.markConfirmed();

    engineDTC.printDTCInfo();
    if(engineDTC.isOverheated()){
        std::cout<<"\nEngine is Overheated Temperature greater than 120C!\n"<<std::endl;
    }else{
        std::cout<<"\nEngine is not overheated..\n"<<std::endl;
    }
}