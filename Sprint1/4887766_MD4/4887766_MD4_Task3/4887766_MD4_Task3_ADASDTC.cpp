#include <iostream>
#include <string>
#include "4887766_MD4_Task3_ADASDTC.h"

ADASDTC::ADASDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, std::string sensorType_, float confidenceScore_): DTC(code_, description_, active_, occurrenceCount_, lastOccurrenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_), m_sensorType(sensorType_), m_confidenceScore(confidenceScore_) {};

void ADASDTC::printADASDTCInfo(){
    this->printDTCInfo();
    std::cout<<"Sensor Type: "<<m_sensorType<<"\n"
             <<"Confidence Score: "<<m_confidenceScore<<std::endl;
}

bool ADASDTC::isSensorFaultLikely(){
    return m_confidenceScore < 0.5f;
}