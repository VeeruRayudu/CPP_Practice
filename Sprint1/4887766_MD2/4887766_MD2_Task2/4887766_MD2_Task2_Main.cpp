#include <iostream>
#include <string>
#include "4887766_MD2_Task2_DTC.h"

int main(){

    //object instantiation
    DTC* dtcA = new DTC();
    DTC* dtcB = new DTC("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");
    DTC* dtcC = new DTC(*dtcB);

    dtcA->setCode("P0101");
    dtcA->setDescription("Mass Air flow sensor fault");
    dtcA->setOccurrenceCount(1);
    dtcA->setMilOn(false);

    dtcA->incrementOccurrence();
    dtcA->toggleMIL();
    dtcB->markConfirmed();

    constexpr int N = 6;
    DTC* dtcArray[N];
    dtcArray[0] = dtcA;
    dtcArray[1] = dtcB;
    dtcArray[2] = nullptr;
    dtcArray[3] = dtcC;
    dtcArray[4] = new DTC("P0420", "Catalyst Efficiency Below Threshold", false, 2, std::time(nullptr)-4000, Severity::WARN, false, false, false, "Exhaust", "ECU_02");
    dtcArray[5] = nullptr;
    std::cout<<"Displaying all DTCs:"<<"\n";
    displayAllDTCs(dtcArray, N);

    delete dtcArray[4];
    dtcArray[4] = nullptr;
    dtcArray[4] = new DTC("P0301", "", false, 10, (std::time(nullptr) - 100), Severity::WARN, false, true, false, "Engine", "");
    for(int i=0; i<N; i++){
        if(dtcArray[i] != nullptr){
            delete dtcArray[i];
            dtcArray[i] = nullptr;
        }
    }

    
    return 0;
}