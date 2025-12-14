#ifndef ENVIRONMENTALDTC_H
#define ENVIRONMENTALDTC_H
#include "4887766_MD4_Task4_DTC.h"

class EnvironmentalDTC : virtual public DTC
{
protected:
    float m_ambientTemperature;
    float m_altitude;
    float m_humidity;

public:
    EnvironmentalDTC(float ambientTemperature_, float altitude_, float humidity_);
    void printEnvironmentData();
};

#endif