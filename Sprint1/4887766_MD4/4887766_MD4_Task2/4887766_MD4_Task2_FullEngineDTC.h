#ifndef FULLENGINEDTC_H
#define FULLENGINEDTC_H
#include "4887766_MD4_Task2_EnvironmentalData.h"
#include "4887766_MD4_Task2_EngineDTC.h"
#include "4887766_MD4_Task2_DTC.h"
#include <string>

class FullEngineDTC: public EngineDTC, public EnvironmentalData{
    private:
    DTC m_dtc;
    std::string m_testConditionNote;

    public:
    FullEngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_, float ambientTemperature_, float altitude_, float humidity_, std::string testConditionNote_);

    DTC& getDTC();

    void printFullDTCReport();
};
#endif