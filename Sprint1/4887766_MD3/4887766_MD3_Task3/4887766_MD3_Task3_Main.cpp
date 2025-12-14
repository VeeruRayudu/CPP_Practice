#include <iostream>
#include "4887766_MD3_Task3_DiagnosticSession.h"
#include "4887766_MD3_Task3_DTC.h"

int main(){
    DTC dtc1("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600,  Severity::CRIT, true, false, true, "Engine", "ECU_01");

    DTC dtc2("U1000", "Comm Bus Fault", true, 5, std::time(nullptr) - 60,  Severity::WARN, false, true, false, "Network", "Gateway");

    DiagnosticSession ds1("John Joshi", "SESSION_001");
    ds1.logDTC(dtc1);
    ds1.logDTC(dtc2);

    ds1.summarizeSession();

}
