#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <ctime>
#include "4887766_MD2_Task2_DTC.h"

int main() {
    // Object instantiation using smart pointers
    auto dtcA = std::make_unique<DTC>();
    auto dtcB = std::make_unique<DTC>("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");
    auto dtcC = std::make_unique<DTC>(*dtcB);  // Copy constructor

    // Modify dtcA
    dtcA->setCode("P0101");
    dtcA->setDescription("Mass Air flow sensor fault");
    dtcA->setOccurrenceCount(1);
    dtcA->setMilOn(false);
    dtcA->incrementOccurrence();
    dtcA->toggleMIL();

    // Confirm dtcB
    dtcB->markConfirmed();

    // Create array of smart pointers
    constexpr int N = 6;
    std::array<std::unique_ptr<DTC>, N> dtcArray;

    dtcArray[0] = std::move(dtcA);
    dtcArray[1] = std::move(dtcB);
    dtcArray[2] = nullptr;
    dtcArray[3] = std::move(dtcC);
    dtcArray[4] = std::make_unique<DTC>("P0420", "Catalyst Efficiency Below Threshold", false, 2, std::time(nullptr) - 4000, Severity::WARN, false, false, false, "Exhaust", "ECU_02");
    dtcArray[5] = nullptr;

    std::cout << "Displaying all DTCs:\n";
    //displayAllDTCs(dtcArray.data(), N);  // Assuming displayAllDTCs still expects raw pointers

    // Replace dtcArray[4] with a new DTC
    dtcArray[4] = std::make_unique<DTC>("P0301", "", false, 10, std::time(nullptr) - 100, Severity::WARN, false, true, false, "Engine", "");

    // No need for manual deletion; smart pointers handle cleanup
    return 0;
}