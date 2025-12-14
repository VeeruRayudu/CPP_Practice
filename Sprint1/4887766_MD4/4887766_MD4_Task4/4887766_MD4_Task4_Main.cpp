#include <iostream>
#include "4887766_MD4_Task4_SmartEngineDTC.h"

int main(){
    SmartEngineDTC seDTC("P0500", "Vehicle Speed Sensor Malfunction", true, 6, 1628888000, Severity::CRIT, true, false, true, "Engine", "ECU_ENG_MAIN", 4100, 133.5, 39.2, 110.0, 82.0, "Occured during peak summer traffic congestion");

    seDTC.printSmartDTCInfo();
    std::cout<<"\nIs high risk?"<<(seDTC.isHighRiskFault()?"true":"false")<<"\n";
    std::cout<<"Is Overheated?"<<(seDTC.isOverheated()?"true":"false")<<"\n";

    return 0;
}