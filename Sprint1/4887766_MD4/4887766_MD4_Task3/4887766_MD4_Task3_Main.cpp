#include <iostream>
#include <string>
#include "4887766_MD4_Task3_EngineDTC.h"
#include "4887766_MD4_Task3_BrakeDTC.h"
#include "4887766_MD4_Task3_ADASDTC.h"

int main(){
    EngineDTC eDtc("P0115", "Engine Coolant Temperature Sensor Circuit", true, 2, 1625280000, Severity::WARN, true, false, false, "Engine", "ECU_ENG", 1850, 102.4);

    BrakeDTC bDtc("C1234", "Wheel Speed Sensor Rear Left Input Missing", true, 4, 1625300000, Severity::CRIT, true, false, true, "Brakes", "ECU_BRK", 2.8, true);

    ADASDTC adasDtc("B1005", "Radar Sensor Misalignment", true, 1, 1625400000, Severity::WARN, false, true, true, "ADAS", "ECU_ADAS", "Radar", 0.62);

    eDtc.setConfirmed(true);
    bDtc.setMilOn(true);
    adasDtc.setPending(false);

    eDtc.activate();
    bDtc.incrementOccurrence();
    adasDtc.markConfirmed();

    std::cout<<"\n------ENGINE DTC REPORT---------\n";
    eDtc.printEngineDTCInfo();
    std::cout<<"Overheated?"<<(eDtc.isOverheated() ? "Yes" : "No")<<"\n";

    std::cout<<"\n------Brake DTC REPORT---------\n";
    bDtc.printBrakeDTCInfo();
    std::cout<<"ABS Failure?"<<(bDtc.isABSFailure() ? "Yes" : "No")<<"\n";

    std::cout<<"\n------ADAS DTC REPORT---------\n";
    adasDtc.printADASDTCInfo();
    std::cout<<"Sensor fault likely?"<<(adasDtc.isSensorFaultLikely() ? "Yes" : "No")<<"\n";

    return 0;
}