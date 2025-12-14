#include <iostream>
#include <string>
#include "4887766_MD4_Task2_FullEngineDTC.h"

int main(){
    FullEngineDTC fed("P0420", "Catalyst System Efficiency Below Threshold", true, 5, 1628258800, Severity::WARN, true, false, true, "Engine", "ECU_02", 2200, 128.5, 38.0, 125.3, 78.0, "Detected during uphill highway climb");

    fed.getDTC().setMilOn(false);

    fed.getDTC().activate();
    fed.getDTC().incrementOccurrence();
    fed.getDTC().markConfirmed();
    fed.getDTC().toggleMIL();

    fed.printFullDTCReport();

}