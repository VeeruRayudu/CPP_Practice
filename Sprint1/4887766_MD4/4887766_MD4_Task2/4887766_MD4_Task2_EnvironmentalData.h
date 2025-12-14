#ifndef ENVIRONMENTALDATA_H
#define ENVIRONMENTALDATA_H

class EnvironmentalData{
    protected:
    float m_ambientTemperature;
    float m_altitude;
    float m_humidity;

    public:
    EnvironmentalData(float ambientTemperature_, float altitude_, float humidity_);
    void printEnvironmentData();
};

#endif