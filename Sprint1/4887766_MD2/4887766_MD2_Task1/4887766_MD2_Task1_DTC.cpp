#include <iostream>
#include <string>
#include <ctime>
#include "4887766_MD2_Task1_DTC.h"

//constructors
DTC::DTC(): m_code(""), m_description(""), m_active(false), m_occurrenceCount(0), m_lastOccurrenceTime(0), m_severityLevel(Severity::INFO), m_confirmed(false), m_pending(false), m_milOn(false), m_system(""), m_origin("") {};  //default

DTC::DTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_): m_code(code_), m_description(description_), m_active(active_), m_occurrenceCount(occurrenceCount_), m_lastOccurrenceTime(lastOccurrenceTime_), m_severityLevel(severityLevel_), m_confirmed(confirmed_), m_pending(pending_), m_milOn(milOn_), m_system(system_), m_origin(origin_) {};  //parameterized

DTC::DTC(DTC &other){
    m_code = other.m_code;
    m_description = other.m_description;
    m_active = other.m_active;
    m_occurrenceCount = other.m_occurrenceCount;
    m_lastOccurrenceTime = other.m_lastOccurrenceTime;
    m_severityLevel = other.m_severityLevel;
    m_confirmed = other.m_confirmed;
    m_pending = other.m_pending;
    m_milOn = other.m_milOn;
    m_system = other.m_system;
    m_origin = other.m_origin;
}  //copy

//getters
std::string DTC::getCode(){ return m_code; }
std::string DTC::getDescription() { return m_description; }
bool DTC::getActive() { return m_active; }
int DTC::getOccurrenceCount() { return m_occurrenceCount;}
time_t DTC::getLastOccurrenceTime() { return m_lastOccurrenceTime; }
Severity DTC::getSeverityLevel() { return m_severityLevel; }
bool DTC::getConfirmed() { return m_confirmed; }
bool DTC::getPending() { return m_pending; }
bool DTC::getMilOn() { return m_milOn; }
std::string DTC::getSystem() { return m_system; }
std::string DTC::getOrigin() { return m_origin; }

//setters
void DTC::setCode(std::string code_) { m_code = code_;}
void DTC::setDescription(std::string description_) { m_description = description_; }
void DTC::setActive(bool active_) { m_active = active_; }
void DTC::setOccurrenceCount(int occurrenceCount_) { m_occurrenceCount = occurrenceCount_; }
void DTC::setLastOccurrenceTime(time_t lastOccurrenceTime_) { m_lastOccurrenceTime = lastOccurrenceTime_; }
void DTC::setSeverityLevel(Severity severityLevel_) { m_severityLevel = severityLevel_; }
void DTC::setConfirmed(bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(bool pending_){ m_pending = pending_; }
void DTC::setMilOn(bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(std::string system_) { m_system = system_; }
void DTC::setOrigin(std::string origin_) { m_origin = origin_; }

void DTC::activate(){
    m_active = true;
}

void DTC::deactivate(){
    m_active = false;
}

void DTC::incrementOccurrence(){
    m_occurrenceCount++;
}

std::string severityToString(Severity s) {
    switch (s) {
        case Severity::INFO: return "INFO";
        case Severity::WARN: return "WARN";
        case Severity::CRIT: return "CRIT";
        default: return "UNKNOWN";
    }
}


void DTC::printDTCInfo(){
    std::cout<<"Code: "<<m_code<<"\n"
             <<"Description: "<<m_description<<"\n"
             <<"Active: "<<m_active<<"\n"
             <<"Occurence: "<<m_occurrenceCount<<"\n"
             <<"Last Occurrence Time: "<<m_lastOccurrenceTime<<"\n"
             <<"Severity: "<<severityToString(m_severityLevel)<<"\n"
             <<"Confirmed: "<<m_confirmed<<"\n"
             <<"Pending: "<<m_pending<<"\n"
             <<"MIL: "<<m_milOn<<"\n"
             <<"System: "<<m_system<<"\n"
             <<"Origin: "<<m_system<<"\n";
}

void DTC::toggleMIL(){
    m_milOn ? false : true;
}

void DTC::markConfirmed(){
    m_confirmed =true;
    m_pending = false;
}

