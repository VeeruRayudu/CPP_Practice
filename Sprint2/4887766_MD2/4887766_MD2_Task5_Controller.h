#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "4887766_MD2_Task5_Enum.h"
#include "4887766_MD2_Task5_TelemetryProvider.h"
#include <string>

class Controller{
    protected:
    std::string m_name;
    TelemetryLevel m_level;

    public:
    //deleted default constructor
    Controller() = delete;
    
    Controller(std::string name, TelemetryLevel level) : m_name(name), m_level(level) {}

    virtual ~Controller() = default;

    //pure virtual function
    virtual std::string operate(TelemetryProvider* provider) = 0;

    //getter
    TelemetryLevel getTelemertyLevel() const { return m_level; }
};  

#endif