#include <iostream>
#include "4887766_MD4_Task4_EnvironmentalDTC.h"

EnvironmentalDTC::EnvironmentalDTC(float ambientTemperature_, float altitude_, float humidity_): m_ambientTemperature(ambientTemperature_), m_altitude(altitude_), m_humidity(humidity_) {};

void EnvironmentalDTC::printEnvironmentData(){
    std::cout<<"Ambient Temperature: "<<m_ambientTemperature<<"\n"
             <<"Altitude: "<<m_altitude<<"\n"
             <<"Humidity: "<<m_humidity<<"\n"<<std::endl;
}

