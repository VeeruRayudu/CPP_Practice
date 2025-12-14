#ifndef TELEMETRY_PROVIDER_H
#define TELEMETRY_PROVIDER_H
#include <iostream>

class TelemetryProvider{
    private:
    std::string m_source;

    public:
    //constructor
    TelemetryProvider(std::string source_): m_source(source_) {}

    //deleted copy
    TelemetryProvider(const TelemetryProvider&) = delete;
    TelemetryProvider& operator=(const TelemetryProvider&) = delete;

    //deleted move
    TelemetryProvider(TelemetryProvider&&) = default;
    TelemetryProvider& operator=(TelemetryProvider&&) = default;

    //getter
    std::string getSourceName() const { return m_source; }
};

#endif