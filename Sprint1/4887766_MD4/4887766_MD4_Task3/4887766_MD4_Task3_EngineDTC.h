#ifndef ENGINEDTC_H
#define ENGINEDTC_H
#include <iostream>
#include "4887766_MD4_Task3_DTC.h"

class EngineDTC : public DTC
{
private:
    int m_rpmAtFault;
    float m_coolantTemp;

public:
    EngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_);

    // getters
    int getRpmAtFault() const;
    float getCoolantTemp() const;
    // setters
    void setRpmAtFault(int rpmAtFault_);
    void setCoolantTemp(float coolantTemp_);

    void printEngineDTCInfo();
    bool isOverheated();
};

#endif