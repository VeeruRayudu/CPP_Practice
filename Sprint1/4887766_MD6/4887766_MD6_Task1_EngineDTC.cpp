#include <iostream>
#include "4887766_MD6_Task1_EngineDTC.h"

EngineDTC::EngineDTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_, int rpmAtFault_, float coolantTemp_) : DTC(code_, description_, active_, occurrenceCount_, lastOccurrenceTime_, severityLevel_, confirmed_, pending_, milOn_, system_, origin_), m_rpmAtFault(rpmAtFault_), m_coolantTemp(coolantTemp_) {};

int EngineDTC::getRpmAtFault() const { return m_rpmAtFault; }
float EngineDTC::getCoolantTemp() const { return m_coolantTemp; }

void EngineDTC::setRpmAtFault(int rpmAtFault_) { m_rpmAtFault = rpmAtFault_; }
void EngineDTC::setCoolantTemp(float coolantTemp_) { m_coolantTemp = coolantTemp_; }

void EngineDTC::printEngineDTCInfo()
{
    this->printDTCInfo();
    std::cout << "Rpm At Fault: " << m_rpmAtFault << "\n"
              << "Coolant Temperature: " << m_coolantTemp << "C" << "\n"
              << std::endl;
}

bool EngineDTC::isOverheated()
{
    return (m_coolantTemp > 120.0f) ? true : false;
}