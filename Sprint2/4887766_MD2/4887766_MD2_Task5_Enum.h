#ifndef ENUM_H
#define ENUM_H

enum class TelemetryLevel {NONE = 0, BASIC = 1, EXTENDED = 2};

TelemetryLevel operator|(TelemetryLevel a, TelemetryLevel b){
    return static_cast<TelemetryLevel>(static_cast<int>(a) | static_cast<int>(b));
}

bool hasLevel(TelemetryLevel provider, TelemetryLevel controller){
    TelemetryLevel mask = provider | controller;
    return mask == TelemetryLevel::NONE || mask == TelemetryLevel::BASIC || mask == TelemetryLevel::EXTENDED;
}

#endif