#include <iostream>
#include "4887766_MD4_Task2_EngineDTC.h"

EngineDTC::EngineDTC(int rpmAtFault_, float coolantTemp_) :  m_rpmAtFault(rpmAtFault_), m_coolantTemp(coolantTemp_) {};

int EngineDTC::getRpmAtFault() const { return m_rpmAtFault; }
float EngineDTC::getCoolantTemp() const { return m_coolantTemp; }

void EngineDTC::setRpmAtFault(int rpmAtFault_) { m_rpmAtFault = rpmAtFault_; }
void EngineDTC::setCoolantTemp(float coolantTemp_) { m_coolantTemp = coolantTemp_; }

void EngineDTC::printEngineDTCInfo()
{
    // this->m_dtc.printDTCInfo();
    std::cout << "Rpm At Fault: " << m_rpmAtFault << "\n"
              << "Coolant Temperature: " << m_coolantTemp << "C" << "\n"
              << std::endl;
}

bool EngineDTC::isOverheated()
{
    return (m_coolantTemp > 120.0f) ? true : false;
}