#ifndef TELEMETRYPACKET_H
#define TELEMETRYPACKET_H

#include <iostream>
#include <string>
#include <utility>
#include <cstdint>

enum class Level { OK, WARN, CRITICAL };

class TelemetryPacket {
private:
    int m_id{};
    std::string m_tag{};
    std::uint64_t m_timestamp{};
    double m_temperature{};
    double m_pressure{};
    Level m_level{Level::OK};
    std::size_t m_payloadSize{0};

public:
    TelemetryPacket() = default;
    TelemetryPacket(int id, std::string tag, std::uint64_t timestamp);

    TelemetryPacket(const TelemetryPacket&) = delete;
    TelemetryPacket& operator=(const TelemetryPacket&) = delete;

    TelemetryPacket(TelemetryPacket&&) noexcept;
    TelemetryPacket& operator=(TelemetryPacket&&) noexcept;

    double getTemperature() const;
    Level getLevel() const;

    void setReadings(double temp, double pres);
    void setLevel(Level&& lvl);
    void setLevel(const Level&) = delete;

    void print() const;
};

// Logger functions
void logByValue(TelemetryPacket p);
void logByRef(const TelemetryPacket& p);
void logByRRef(TelemetryPacket&& p);
void logByPtr(const TelemetryPacket* p);

// Filter function
template <typename Predicate>
size_t filterCritical(TelemetryPacket arr[], size_t n, TelemetryPacket out[], size_t outCap, Predicate predicate) {
    std::size_t count = 0;
    for (size_t i = 0; i < n && count < outCap; ++i) {
        if (predicate(arr[i])) {
            out[count++] = std::move(arr[i]);
        }
    }
    return count;
}

#endif // TELEMETRYPACKET_H