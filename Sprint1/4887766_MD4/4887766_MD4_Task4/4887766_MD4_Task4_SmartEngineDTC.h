#ifndef SMARTENGINEDTC_H
#define SMARTENGINEDTC_H
#include "4887766_MD4_Task4_EngineDTC.h"
#include "4887766_MD4_Task4_EnvironmentalDTC.h"

class SmartEngineDTC: public EngineDTC, public EnvironmentalDTC{
    private:
    std::string m_faultContextNote;

    public:
    SmartEngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_, float ambientTemperature_, float altitude_, float humidity_, std::string faultContextNote_);

    void printSmartDTCInfo();

    bool isHighRiskFault();
};

#endif