#include <iostream>
#include "4887766_MD4_Task3_BrakeDTC.h"

BrakeDTC::BrakeDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, float brakePressure_, bool absEngaged_): DTC(code_, description_, active_, occurrenceCount_, lastOccurrenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_), m_brakePressure(brakePressure_), m_absEngaged(absEngaged_) {};

void BrakeDTC::printBrakeDTCInfo(){
    this->printDTCInfo();
    std::cout<<"Brake Pressure: "<<m_brakePressure<<"\n"
             <<"ABS Engaged: "<<m_absEngaged<<std::endl;
}

bool BrakeDTC::isABSFailure(){
    return (m_absEngaged == true) ? true : false;
}