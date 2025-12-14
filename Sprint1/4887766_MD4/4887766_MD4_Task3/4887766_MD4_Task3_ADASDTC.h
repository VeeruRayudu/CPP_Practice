#ifndef ADASDTC_H
#define ADASDTC_H
#include <string>
#include "4887766_MD4_Task3_DTC.h"

class ADASDTC: public DTC{
    private:
    std::string m_sensorType;
    float m_confidenceScore;

    public:
    ADASDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, std::string sensorType_, float confidenceScore_);
    void printADASDTCInfo();
    bool isSensorFaultLikely();
};

#endif