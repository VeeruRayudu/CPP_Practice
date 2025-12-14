#ifndef BRAKEDTC_H
#define BRAKEDTC_H
#include "4887766_MD4_Task3_DTC.h"

class BrakeDTC: public DTC{
    private:
    float m_brakePressure;
    bool m_absEngaged;

    public:
    BrakeDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, float brakePressure_, bool absEngaged_);
    void printBrakeDTCInfo();
    bool isABSFailure();
};

#endif