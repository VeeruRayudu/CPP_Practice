#include <iostream>
#include "4887766_MD4_Task2_EnvironmentalData.h"

EnvironmentalData::EnvironmentalData(float ambientTemperature_, float altitude_, float humidity_): m_ambientTemperature(ambientTemperature_), m_altitude(altitude_), m_humidity(humidity_) {};

void EnvironmentalData::printEnvironmentData(){
    std::cout<<"Ambient Temperature: "<<m_ambientTemperature<<"\n"
             <<"Altitude: "<<m_altitude<<"\n"
             <<"Humidity: "<<m_humidity<<"\n"<<std::endl;
}