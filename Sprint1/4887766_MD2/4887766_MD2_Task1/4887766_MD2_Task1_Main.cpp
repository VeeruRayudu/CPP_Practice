#include <iostream>
#include "4887766_MD2_Task1_DTC.h"

int main(){
    DTC** dtcArray = new DTC*[3];

    dtcArray[0] = new DTC("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");

    dtcArray[1] = new DTC("P0420", "Catalyst System Efficiency Below Threshold", false, 1, 1625248600, Severity::WARN, false, true, false, "Exhaust", "ECU_02");

    dtcArray[2] = new DTC("P0171", "System Too Lean (Bank1)", true, 2, 1625249600, Severity::INFO, true, false, true, "Fuel", "ECU_03");

    for(int i=0; i<3; i++){
        dtcArray[i]->incrementOccurrence();
        dtcArray[i]->toggleMIL();
        dtcArray[i]->activate();
        dtcArray[i]->markConfirmed();

        std::cout<<"Object "<<i+1<<" Details"<<"\n";
        dtcArray[i]->printDTCInfo();
    }

    for(int i=0; i<3; i++){
        delete dtcArray[i];
        dtcArray[i] = nullptr;
    }

    delete[] dtcArray;
    dtcArray = nullptr;

    return 0;
}