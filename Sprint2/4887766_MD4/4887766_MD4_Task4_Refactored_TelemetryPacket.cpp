#include "TelemetryPacket.h"

namespace {
    std::string toString(Level level) {
        switch (level) {
            case Level::OK: return "OK";
            case Level::WARN: return "WARN";
            case Level::CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }
}

TelemetryPacket::TelemetryPacket(int id, std::string tag, std::uint64_t timestamp)
    : m_id(id), m_tag(std::move(tag)), m_timestamp(timestamp) {}

TelemetryPacket::TelemetryPacket(TelemetryPacket&& other) noexcept
    : m_id(other.m_id),
      m_tag(std::move(other.m_tag)),
      m_timestamp(other.m_timestamp),
      m_temperature(other.m_temperature),
      m_pressure(other.m_pressure),
      m_level(other.m_level),
      m_payloadSize(other.m_payloadSize) {
    other = TelemetryPacket{};
}

TelemetryPacket& TelemetryPacket::operator=(TelemetryPacket&& other) noexcept {
    if (this != &other) {
        m_id = other.m_id;
        m_tag = std::move(other.m_tag);
        m_timestamp = other.m_timestamp;
        m_temperature = other.m_temperature;
        m_pressure = other.m_pressure;
        m_level = other.m_level;
        m_payloadSize = other.m_payloadSize;
        other = TelemetryPacket{};
    }
    return *this;
}

double TelemetryPacket::getTemperature() const {
    return m_temperature;
}

Level TelemetryPacket::getLevel() const {
    return m_level;
}

void TelemetryPacket::setReadings(double temp, double pres) {
    m_temperature = temp;
    m_pressure = pres;
}

void TelemetryPacket::setLevel(Level&& lvl) {
    m_level = std::move(lvl);
}

void TelemetryPacket::print() const {
    std::cout << "\nPacket ID: " << m_id
              << "\nTag: " << m_tag
              << "\nTimestamp: " << m_timestamp
              << "\nTemperature: " << m_temperature
              << "\nPressure: " << m_pressure
              << "\nLevel: " << toString(m_level) << "\n";
}

void logByValue(TelemetryPacket p) {
    std::cout << "\nCall By Value\n";
    p.print();
}

void logByRef(const TelemetryPacket& p) {
    std::cout << "\nCall By Reference\n";
    p.print();
}

void logByRRef(TelemetryPacket&& p) {
    std::cout << "\nCall By Rvalue Reference\n";
    p.print();
}

void logByPtr(const TelemetryPacket* p) {
    std::cout << "\nCall By Pointer\n";
    if (p) p->print();
    else std::cout << "Null pointer.\n";
}