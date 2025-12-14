#include <iostream>
#include "4887766_MD2_Task3_DTC.h"

int main()
{

    std::cout << "DTC instances at start: " << DTC::getDTCCount() << std::endl;

    DTC dtcStaticDefault;
    DTC dtcStaticParam("P0301", "Cylinder 1 Misfire Detected", true, 3, std::time(nullptr) - 1200, Severity::CRIT, true, false, true, "Engine", "ECU_01");
    DTC dtcStaticCopy(dtcStaticParam);
    std::cout << "DTC instances after static creation: " << DTC::getDTCCount() << std::endl;

    dtcStaticDefault.setSeverityLevel(2);
    dtcStaticDefault.getSeverityLevel();
    dtcStaticDefault.setSeverityLevel("Warn");
    dtcStaticDefault.getSeverityLevel();

    dtcStaticDefault.markActive();
    dtcStaticDefault.getActive();
    dtcStaticDefault.markActive(false);
    dtcStaticDefault.getActive();

    DTC *pA = new DTC();
    pA->setCode("P0101");
    pA->setDescription("Mass Air flow sensor fault");
    pA->setOccurrenceCount(1);
    pA->setMilOn(false);
    pA->incrementOccurrence();
    pA->toggleMIL();
    pA->printDTCInfo();

    DTC *pB = new DTC("P0420", "Catalyst Efficiency Below Threshold", false, 2, std::time(nullptr) - 4000, Severity::WARN, false, false, false, "Exhaust", "ECU_02");

    DTC *pC = new DTC(*pB);

    constexpr int N = 6;
    DTC *dtcArray[N] = {
        pA, pB, nullptr, pC, new DTC("U1000", "Comm Bus Fault", true, 5, std::time(nullptr) - 60, Severity::WARN, false, true, false, "Network", "Gateway"), nullptr};

    std::cout << "DTC instances after dynamic creation: " << DTC::getDTCCount() << std::endl;
    displayAllDTCs(dtcArray, N);

    dtcArray[4]->setSeverityLevel("Crit");
    dtcArray[4]->markActive();
    dtcArray[4]->printDTCInfo();

    for (int i = 0; i < N; i++)
    {
        if (dtcArray[i] != nullptr)
        {
            delete dtcArray[i];
            dtcArray[i] = nullptr;
        }
    }
    std::cout << "DTC instances after cleanup: " << DTC::getDTCCount() << std::endl;

    {
        DTC temp("P0501", "Speed Sensor Fault", true, 1, time(0), Severity::WARN, true, false, false, "Chassis", "ECU_04");
        std::cout << "Inside Nested scope: " << DTC::getDTCCount() << std::endl;
    }

    std::cout << "After leaving scope: " << DTC::getDTCCount() << std::endl;

    return 0;
}