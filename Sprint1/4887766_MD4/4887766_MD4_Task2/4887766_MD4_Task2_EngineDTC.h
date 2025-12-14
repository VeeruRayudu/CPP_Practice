#ifndef ENGINEDTC_H
#define ENGINEDTC_H
#include <iostream>

class EngineDTC
{
protected:
    int m_rpmAtFault;
    float m_coolantTemp;

public:
    EngineDTC(int rpmAtFault_, float coolantTemp_);

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