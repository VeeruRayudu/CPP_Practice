#include <iostream>
#include <memory>
#include <array>
#include "4887766_MD2_Task1_DTC.h"

int main() {
    std::array<std::unique_ptr<DTC>, 3> dtcArray = {
        std::make_unique<DTC>("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01"),
        std::make_unique<DTC>("P0420", "Catalyst System Efficiency Below Threshold", false, 1, 1625248600, Severity::WARN, false, true, false, "Exhaust", "ECU_02"),
        std::make_unique<DTC>("P0171", "System Too Lean (Bank1)", true, 2, 1625249600, Severity::INFO, true, false, true, "Fuel", "ECU_03")
    };

    int index = 1;
    for (const auto& dtc : dtcArray) {
        dtc->incrementOccurrence();
        dtc->toggleMIL();
        dtc->activate();
        dtc->markConfirmed();

        std::cout << "Object " << index++ << " Details\n";
        dtc->printDTCInfo();
    }

    // No need for manual deletion; unique_ptr handles cleanup automatically.
    return 0;
}