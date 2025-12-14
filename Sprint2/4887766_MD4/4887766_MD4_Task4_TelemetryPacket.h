#ifndef TELEMETRYPACKET_H
#define TELEMETRYPACKET_H
#include <iostream>
#include <string>
#include <utility>
#include <cstdint>

enum class Level {OK, WARN, CRITICAL};

class TelemetryPacket{
    private:
    int m_id{};
    std::string m_tag{};
    std::uint64_t m_timestamp{};
    double m_temperature{};
    double m_pressure{};
    Level m_level{Level::OK};
    std::size_t m_payloadSize{0};    //in-class initialization

    public:
    //default constructor
    TelemetryPacket() = default;

    //member-list constructor
    TelemetryPacket(int id_, std::string tag_, std::uint64_t timestamp_);

    //deleted copy constructor
    TelemetryPacket(const TelemetryPacket&) = delete;
    //deleted copy assignment
    TelemetryPacket& operator=(const TelemetryPacket&) = delete;

    //move constructor
    TelemetryPacket(TelemetryPacket&&) noexcept;
    //move assignment
    TelemetryPacket& operator=(TelemetryPacket&&) noexcept;

    //getters
    double getTemperature() const { return m_temperature; }
    Level getLevel() const { return m_level; }

    //setter for readings
    void setReadings(double temp, double pres);

    //rvalue ref setter for level
    void setLevel(Level&& lvl);
    //deleted lvalue overload
    void setLevel(const Level&) = delete;

    //display 
    void print() const;

};

//global helper functions

//loggers
void logByValue(TelemetryPacket p);
void logByRef(const TelemetryPacket& p);
void logByRRef(TelemetryPacket&& p);
void logByPtr(const TelemetryPacket* p);

//filter critical
template <typename Predicate>
size_t filterCritical(TelemetryPacket arr[], size_t n, TelemetryPacket out[], size_t outCap, Predicate predicate){
    std::size_t count = 0;
    for(int i=0; i<n && count < outCap; i++){
        if(predicate(arr[i])){
            out[count++] = std::move(arr[i]);
        }
    }
    return count;
}


#endif