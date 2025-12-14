#ifndef AUTOMOTIVE_SUBSYSTEM_H
#define AUTOMOTIVE_SUBSYSTEM_H
#include "4887766_MD2_Task5_TelemetryProvider.h"
#include "4887766_MD2_Task5_Controller.h"
#include <vector>
#include <memory>

class AutomotiveSubsystem
{
private:
    std::vector<std::unique_ptr<Controller>> controllers;
    std::vector<TelemetryProvider *> providers;

public:
    // default constructor
    AutomotiveSubsystem() = default;

    // deleted copy
    AutomotiveSubsystem(const AutomotiveSubsystem &) = delete;
    AutomotiveSubsystem &operator=(const AutomotiveSubsystem &) = delete;

    void addController(std::unique_ptr<Controller> controller)
    {
        controllers.push_back(std::move(controller));
    }

    void addTelemetry(TelemetryProvider *provider)
    {
        providers.push_back(provider);
    }

    // infer provider level from source string
    static TelemetryLevel inferLevel(const std::string &src)
    {
        if (src.find("EXT") != std::string::npos)
            return TelemetryLevel::EXTENDED;
        if (src.find("BAS") != std::string::npos)
            return TelemetryLevel::BASIC;
        return TelemetryLevel::NONE;
    }

    std::vector<std::string> runAll()
    {
        std::vector<std::string> results;

        for (auto &controller : controllers)
        {
            TelemetryProvider *chosen = nullptr;

            for (auto *provider : providers)
            {
                std::string src = provider->getSourceName();
                TelemetryLevel providerLevel = TelemetryLevel::NONE;

                if (src.find("EXT") != std::string::npos)
                    providerLevel = TelemetryLevel::EXTENDED;
                else if (src.find("BAS") != std::string::npos)
                    providerLevel = TelemetryLevel::BASIC;

                // Choose first provider that matches telemetry level
                if (hasLevel(providerLevel, controller->getTelemertyLevel()))
                {
                    chosen = provider;
                    break;
                }
            }

            // Always run the controller, even if chosen is nullptr
            results.push_back(controller->operate(chosen));
        }

        return results;
    }
};

#endif