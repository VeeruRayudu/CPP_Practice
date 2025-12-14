#include <iostream>
#include <string>
#include <ctime>
#include "4887766_MD1_Task4_DTC.h"

void dynamicAllocationDemo() {
    DTC* dtcPtr = new DTC;

    dtcPtr->setCode("P0201");
    dtcPtr->setDescription("Injector 1 Circuit Malfunction");
    dtcPtr->setActive(true);
    dtcPtr->setSeverityLevel(Severity::WARN);

    dtcPtr->incrementOccurrence();
    dtcPtr->toggleMIL();

    std::cout << "\nDynamic Allocation Demo:\n";
    dtcPtr->printDTCInfo();

    delete dtcPtr;
    dtcPtr = nullptr;  // Prevents dangling pointer
}

void leakDemo() {
    DTC* dtc1 = new DTC;
    DTC* dtc2 = new DTC;

    dtc1->setCode("P0302");
    dtc2->setCode("P0303");

    delete dtc1;
    // dtc2 is not deleted — memory leak occurs
    std::cout << "\nLeak Demo: dtc2 not deleted (intentional leak)\n";
}

void leakFix() {
    DTC* dtc1 = new DTC;
    DTC* dtc2 = new DTC;

    dtc1->setCode("P0302");
    dtc2->setCode("P0303");

    delete dtc1;
    delete dtc2;

    dtc1 = nullptr;
    dtc2 = nullptr;

    std::cout << "\nLeak Fix: both objects deleted and pointers nulled\n";
}

void danglingPointerDemo() {
    DTC* dtcPtr = new DTC;
    dtcPtr->setCode("P0401");

    std::cout << "\nDangling Pointer Demo:\n";
    delete dtcPtr;

    dtcPtr = nullptr;

    if (dtcPtr) {
        dtcPtr->printDTCInfo();  // Will not run
    } else {
        std::cout << "Pointer is null — safe from undefined behavior\n";
    }
}

int main() {
    DTC dtc1;
    DTC dtc2("P0301", "Cylinder 1 Misfire Detected", true, 3,
             1625247600, Severity::CRIT, true, false, true,
             "Engine", "ECU_01");

    dtc1.setCode("P0101");
    dtc1.setDescription("Mass Air Flow Sensor Fault");

    dtc1.incrementOccurrence();
    dtc2.incrementOccurrence();

    dtc2.toggleMIL();
    dtc2.markConfirmed();

    std::cout << "First Object:\n";
    dtc1.printDTCInfo();

    std::cout << "\nSecond Object:\n";
    dtc2.printDTCInfo();

    dynamicAllocationDemo();
    leakDemo();
    leakFix();
    danglingPointerDemo();

    return 0;
}