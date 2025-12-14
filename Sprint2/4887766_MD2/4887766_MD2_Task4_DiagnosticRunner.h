#ifndef DIAGNOSTIC_RUNNER_H
#define DIAGNOSTIC_RUNNER_H
#include "4887766_MD2_Task4_DiagnosticTask.h"
#include "4887766_MD2_Task4_ECUDiagnostic.h"
#include "4887766_MD2_Task4_SensorDiagnostic.h"
#include <vector>
#include <utility>
#include <memory>

class DiagnosticRunner
{
private:
    std::vector<std::unique_ptr<DiagnosticTask>> diagnostics;

public:
    // default constructor
    DiagnosticRunner() = default;

    void addTask(std::unique_ptr<DiagnosticTask> d)
    {
        diagnostics.push_back(std::move(d));
    }

    std::string severityToString(Severity s)
    {
        switch (s)
        {
        case Severity::INFO:
            return "INFO";
        case Severity::WARNING:
            return "WARNING";
        case Severity::CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
        }
    }

    std::vector<std::pair<std::string, std::string>> executeAll()
    {
        std::vector<std::pair<std::string, std::string>> result;
        for (auto &d : diagnostics)
        {
            if (d->run())
            {
                std::string str = dynamic_cast<ECUDiagnostic *>(d.get()) != nullptr ? "ECU OK" : "Sensor OK";
                result.emplace_back(str, severityToString(d->getSeverity()));
            }else{
                std::string str = dynamic_cast<ECUDiagnostic *>(d.get()) != nullptr ? "ECU FAIL" : "Sensor FAIL";
                result.emplace_back(str, severityToString(d->getSeverity()));
            }
        }
        return result;
    }
};

#endif