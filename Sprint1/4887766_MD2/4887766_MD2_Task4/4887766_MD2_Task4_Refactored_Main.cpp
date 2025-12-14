#include <iostream>
#include <ctime>
#include "4887766_MD2_Task4_DTC.h"

int main() {
    // Create a const DTC object
    const DTC dtcParam(
        "P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600,
        Severity::CRIT, true, false, true, "Engine", "ECU_01"
    );

    dtcParam.printDTCInfo();
    // dtcParam.activate(); // Not allowed: non-const method on const object

    // Create another const DTC object
    const DTC dtc(
        "P0420", "Catalyst Efficiency Below Threshold", false, 2,
        std::time(nullptr) - 4000, Severity::WARN,
        false, false, false, "Exhaust", "ECU_02"
    );

    const DTC* dtcPtr = &dtc;
    dtcPtr->printDTCInfo();
    // dtcPtr->setActive(true); // Not allowed: modifying const object

    dtcPtr = &dtcParam; // Allowed: pointer reassignment

    std::cout << "Total Number of Objects created: "
              << DTC::getDTCCount() << std::endl;

    return 0;
}