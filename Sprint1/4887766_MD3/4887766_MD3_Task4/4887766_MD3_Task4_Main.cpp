#include <iostream>
#include "4887766_MD3_Task4_DTCAnalyzer.h"

int main(){
    DTC* dtcPtr1 = new DTC("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600,  Severity::CRIT, true, false, true, "Engine", "ECU_01");

    DTC* dtcPtr2 = new DTC("U1000", "Comm Bus Fault", true, 5, std::time(nullptr) - 60,  Severity::WARN, false, true, false, "Network", "Gateway");

    DTCAnalyzer dtcAnalyzer("ANZ001", "AutoTech Diagnostics");

    dtcAnalyzer.addDTC(dtcPtr1);
    dtcAnalyzer.addDTC(dtcPtr2);

    dtcAnalyzer.reviewCriticalFaults();
    dtcAnalyzer.reportSummary();
}