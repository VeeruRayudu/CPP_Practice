#include <iostream>
#include <string>
#include "4887766_MD4_Task2_FullEngineDTC.h"

FullEngineDTC::FullEngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_, float ambientTemperature_, float altitude_, float humidity_, std::string testConditionNote_): m_dtc(code_, description_, active_, occurrenceCount_, lastOccurrenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_), EngineDTC(rpmAtFault_, coolantTemp_), EnvironmentalData(ambientTemperature_, altitude_, humidity_), m_testConditionNote(testConditionNote_) {};

DTC& FullEngineDTC::getDTC(){
    return m_dtc;
}

void FullEngineDTC::printFullDTCReport(){
    m_dtc.printDTCInfo();
    printEngineDTCInfo();
    printEnvironmentData();
    std::cout<<"Test Condition Note: "<<m_testConditionNote<<"\n"<<std::endl;
}