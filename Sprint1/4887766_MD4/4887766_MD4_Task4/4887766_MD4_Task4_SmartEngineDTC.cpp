#include <iostream>
#include "4887766_MD4_Task4_SmartEngineDTC.h"

SmartEngineDTC::SmartEngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_, float ambientTemperature_, float altitude_, float humidity_, std::string faultContextNote_) : DTC(code_, description_, active_, occurrenceCount_, lastOccurrenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_), EngineDTC(rpmAtFault_, coolantTemp_), EnvironmentalDTC(ambientTemperature_, altitude_, humidity_), m_faultContextNote(faultContextNote_) {};

void SmartEngineDTC::printSmartDTCInfo()
{
    printDTCInfo();
    printEngineDTCInfo();
    printEnvironmentData();
}

bool SmartEngineDTC::isHighRiskFault(){
    return (m_coolantTemp > 120.0f && m_ambientTemperature > 35.0f) ? true : false;
}