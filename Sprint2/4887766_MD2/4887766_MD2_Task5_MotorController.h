#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H
#include "4887766_MD2_Task5_Controller.h"
#include <sstream>

class MotorController final : public Controller
{
private:
    int m_rpmLimit;

public:
    // contructors with delegation
    MotorController(std::string name, int rpmLimit) : MotorController(name, rpmLimit, TelemetryLevel::BASIC) {}

    MotorController(std::string name, int rpmLimit, TelemetryLevel level) : Controller(name, level), m_rpmLimit(rpmLimit) {}

    std::string operate(TelemetryProvider *provider) override
    {
        std::ostringstream oss;
        if (provider == nullptr)
        {
            oss << "Motor: " << Controller::m_name << " Running RPM Limit: " << m_rpmLimit << "No Telemetry" << std::endl;
        }
        std::string src = provider->getSourceName();
        TelemetryLevel provLevel = TelemetryLevel::NONE;
        if (src.find("EXT") != std::string::npos)
        {
            provLevel = TelemetryLevel::EXTENDED;
        }
        else if (src.find("BAS") != std::string::npos)
        {
            provLevel = TelemetryLevel::BASIC;
        }
        if (!hasLevel(provLevel, Controller::getTelemertyLevel()))
        {
            oss << "Motor: " << Controller::m_name << " Running RPM Limit: " << m_rpmLimit << "No Telemetry" << std::endl;
        }
        oss << "Motor: " << Controller::m_name << " Running RPM Limit: " << m_rpmLimit << " Telemetry From: " << provider->getSourceName() << std::endl;
        return oss.str();
    }
};

#endif