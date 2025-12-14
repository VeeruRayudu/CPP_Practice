#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <climits>
#include "4887766_MD1_Task3_DTC.h"

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
std::string DTC::getCode() const { return m_code; }
std::string DTC::getDescription() const { return m_description; }
bool DTC::getActive() const { return m_active; }
int DTC::getOccurrenceCount() const { return m_occurrenceCount;}
time_t DTC::getLastOccurrenceTime() const { return m_lastOccurrenceTime; }
Severity DTC::getSeverityLevel() const const { return m_severityLevel; }
bool DTC::getConfirmed() const { return m_confirmed; }
bool DTC::getPending() const { return m_pending; }
bool DTC::getMilOn() const { return m_milOn; }
std::string DTC::getSystem() const { return m_system; }
std::string DTC::getOrigin() const { return m_origin; }

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

double DTC::computeRiskScore() const{
    Severity severe = getSeverityLevel();
    time_t lastTime = getLastOccurrenceTime();
    bool mil = getMilOn();

    //severity component
    double severityComponent;
    switch (severe)
    {
    case Severity::INFO: severityComponent = 10.0; break;
    case Severity::WARN: severityComponent = 40.0; break;
    case Severity::CRIT: severityComponent = 80.0; break;
    default: severityComponent = 10.0; break;
    }

    //occurence component
    double occurrenceComponent;
    int count = std::max(0, getOccurrenceCount());
    occurrenceComponent = (count*5.0 <= 50.0) ? count*5.0 : 50.0;

    //age component
    double ageComponent;
    time_t timeNow = std::time(nullptr);

    if(lastTime > 0 && lastTime <= timeNow){
        double ageSeconds = timeNow - lastTime;
        if(ageSeconds <= 3600){
            ageComponent = 20.0;
        }else if(ageComponent < 30*24*3600){
            double fraction = (ageSeconds - 3600)/(30*24*3600 - 3600);
            ageComponent = 20.0 * (1-fraction);
        }else{
            ageComponent = 0.0;
        }
    }else{
        ageComponent = 0.0;
    }

    //MIL multiplier
    double milMultiplier;
    milMultiplier = (mil) ? 1.25 : 1.0;

    //final score
    double score = (severityComponent + occurrenceComponent + ageComponent) * milMultiplier;

    return std::clamp(score, 0.0, 100.0);
}

std::string DTC::recommendAction() const{
    double score = computeRiskScore();
    bool confirmed = getConfirmed();
    bool mil = getMilOn();
    
    if(confirmed && score > 75.0){
        return "Immediate attention: isolate system and stop if unsafe.";
    }else if(confirmed && score > 30.0){
        return "Schedule urgent repair.";
    }else if(mil && score > 30.0){
        return "Drive restricted: visit service soon.";
    }else if(score > 20.0){
        return "Monitor: record and re-evaluate.";
    }else{
        return "Informational: no immediate action.";
    }

}

bool DTC::mergeIfSameCode(const DTC &other){
    if(getCode() == other.getCode() && getSystem() == other.getSystem()){

        int sum = this->getOccurrenceCount() + other.getOccurrenceCount();
        if(sum < 0 || sum > __INT32_MAX__){
            sum = __INT32_MAX__;
        }
        setOccurrenceCount(sum);

        time_t occurrenceTime = std::max(this->getLastOccurrenceTime(), other.getLastOccurrenceTime());
        if(occurrenceTime >= 0){
        setLastOccurrenceTime(occurrenceTime);
        }

        bool confirmed = (this->getConfirmed() || other.getConfirmed());
        setConfirmed(confirmed);

        bool pending = (this->getPending() || other.getPending());
        setPending(pending);

        bool milOn = (this->getMilOn() || other.getMilOn());
        setMilOn(milOn);

        if(this->getOrigin().empty() && !other.getOrigin().empty()){
            setOrigin(other.getOrigin());
        }

        if(this->getDescription().empty() && !other.getDescription().empty()){
            setDescription(other.getDescription());
        }

        if(this->getActive() == true || other.getActive() == true){
            setActive(true);
        }
        return true;
    }else{
        return false;
    }
}