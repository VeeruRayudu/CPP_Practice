#include "4887766_MD4_Task4_TelemetryPacket.h"

 //member-list constructor
TelemetryPacket::TelemetryPacket(int id_, std::string tag_, std::uint64_t timestamp_) : m_id(id_), m_tag(tag_), m_timestamp(timestamp_) {}

//move constructor
TelemetryPacket::TelemetryPacket(TelemetryPacket&& other) noexcept : m_id(other.m_id), m_tag(std::move(other.m_tag)), m_timestamp(other.m_timestamp), m_temperature(other.m_temperature), m_pressure(other.m_pressure), m_level(other.m_level), m_payloadSize(other.m_payloadSize) {
    //moved-from state
    other.m_id = -1;
    other.m_tag = "";
    other.m_timestamp = 0;
    other.m_temperature = 0;
    other.m_pressure = 0;
    other.m_level = Level::OK;
    other.m_payloadSize = 0;
}
//move assignment
TelemetryPacket& TelemetryPacket::operator=(TelemetryPacket&& other) noexcept{
    if(this != &other){
        m_id = other.m_id;
        m_tag = std::move(other.m_tag);
        m_timestamp = other.m_timestamp;
        m_temperature = other.m_temperature;
        m_pressure = other.m_pressure;
        m_level = other.m_level;
        m_payloadSize = other.m_payloadSize;

        //moved-from state
        other.m_id = -1;
        other.m_tag = "";
        other.m_timestamp = 0;
        other.m_temperature = 0;
        other.m_pressure = 0;
        other.m_level = Level::OK;
        other.m_payloadSize = 0;
    }
    return *this;
}

//setter for readings
void TelemetryPacket::setReadings(double temp, double pres){
    m_temperature = temp;
    m_pressure = pres;
}

//rvalue ref setter for level
void TelemetryPacket::setLevel(Level&& lvl){
    m_level = std::move(lvl);
}

static std::string toString(Level l){
    switch (l)
    {
    case Level::CRITICAL : return "CRITICAL";
    case Level::OK : return "OK";
    case Level::WARN : return "WARN";
    default: return "UNKNOWN";
    }
}

//display 
void TelemetryPacket::print() const{
    std::cout<<"\nPacket ID: "<<m_id<<"\n"
             <<"Tag: "<<m_tag<<"\n"
             <<"Timestamp: "<<m_timestamp<<"\n"
             <<"Temperature: "<<m_temperature<<"\n"
             <<"Pressure: "<<m_pressure<<"\n"
             <<"Level: "<<toString(m_level)<<"\n";
}

//global helper functions
void logByValue(TelemetryPacket p){
    std::cout<<"\nCall By Value\n"<<std::endl;
    p.print();
}
void logByRef(const TelemetryPacket& p){
    std::cout<<"\nCall By Reference\n"<<std::endl;
    p.print();
}
void logByRRef(TelemetryPacket&& p){
    std::cout<<"\nCall By rValue reference\n"<<std::endl;
    p.print();
}
void logByPtr(const TelemetryPacket* p){
    std::cout<<"\nCall By Pointer\n"<<std::endl;
    p->print();
}

