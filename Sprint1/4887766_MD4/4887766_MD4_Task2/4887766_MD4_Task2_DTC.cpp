#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include "4887766_MD4_Task2_DTC.h"

int DTC::dtcCount = 0;

// constructors
DTC::DTC() : m_code(""), m_description(""), m_active(false), m_occurrenceCount(0), m_lastOccurrenceTime(0), m_severityLevel(Severity::INFO), m_confirmed(false), m_pending(false), m_milOn(false), m_system(""), m_origin("")
{
    dtcCount++;
}; // default

DTC::DTC(std::string code_, std::string description_, bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_) : m_code(code_), m_description(description_), m_active(active_), m_occurrenceCount(occurrenceCount_), m_lastOccurrenceTime(lastOccurrenceTime_), m_severityLevel(severityLevel_), m_confirmed(confirmed_), m_pending(pending_), m_milOn(milOn_), m_system(system_), m_origin(origin_)
{
    dtcCount++;
}; // parameterized

DTC::DTC(DTC &other)
{
    dtcCount++;
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
} // copy

DTC::~DTC()
{
    std::cout << "DTC destructor called..." << std::endl;
}
// getters
std::string DTC::getCode() { return m_code; }
std::string DTC::getDescription() { return m_description; }
bool DTC::getActive() { return m_active; }
int DTC::getOccurrenceCount() { return m_occurrenceCount; }
time_t DTC::getLastOccurrenceTime() { return m_lastOccurrenceTime; }
Severity DTC::getSeverityLevel() { return m_severityLevel; }
bool DTC::getConfirmed() { return m_confirmed; }
bool DTC::getPending() { return m_pending; }
bool DTC::getMilOn() { return m_milOn; }
std::string DTC::getSystem() { return m_system; }
std::string DTC::getOrigin() { return m_origin; }

// setters
void DTC::setCode(const std::string &code_) { m_code = code_; }
void DTC::setDescription(const std::string &description_) { m_description = description_; }
void DTC::setActive(bool active_) { m_active = active_; }
void DTC::setOccurrenceCount(int occurrenceCount_) { m_occurrenceCount = occurrenceCount_; }
void DTC::setLastOccurrenceTime(time_t lastOccurrenceTime_) { m_lastOccurrenceTime = lastOccurrenceTime_; }
void DTC::setSeverityLevel(Severity severityLevel_)
{
    int sevVal = static_cast<int>(severityLevel_);
    if (sevVal >= 0 && sevVal <= MAX_SEVERITY)
    {
        m_severityLevel = severityLevel_;
    }
    else
    {
        m_severityLevel = Severity::INFO;
    }
}

void DTC::setSeverityLevel(int level)
{
    if (level == static_cast<int>(Severity::INFO))
    {
        m_severityLevel = Severity::INFO;
    }
    else if (level == static_cast<int>(Severity::WARN))
    {
        m_severityLevel = Severity::WARN;
    }
    else if (level == static_cast<int>(Severity::CRIT))
    {
        m_severityLevel = Severity::CRIT;
    }
    else
    {
        m_severityLevel = Severity::INFO;
    }
}

void DTC::setSeverityLevel(const std::string &name)
{
    std::string name_ = name;
    std::transform(name_.begin(), name_.end(), name_.begin(), ::tolower);
    if (name_ == "info")
    {
        m_severityLevel = Severity::INFO;
    }
    else if (name_ == "warn")
    {
        m_severityLevel = Severity::WARN;
    }
    else if (name_ == "crit" || name_ == "critical")
    {
        m_severityLevel = Severity::CRIT;
    }
    else
    {
        m_severityLevel = Severity::INFO;
    }
}

void DTC::setConfirmed(bool confirmed_) { m_confirmed = confirmed_; }
void DTC::setPending(bool pending_) { m_pending = pending_; }
void DTC::setMilOn(bool milOn_) { m_milOn = milOn_; }
void DTC::setSystem(const std::string &system_) { m_system = system_; }
void DTC::setOrigin(const std::string &origin_) { m_origin = origin_; }

void DTC::activate()
{
    m_active = true;
}

void DTC::deactivate()
{
    m_active = false;
}

void DTC::incrementOccurrence()
{
    m_occurrenceCount++;
}

std::string severityToString(Severity s)
{
    switch (s)
    {
    case Severity::INFO:
        return "INFO";
    case Severity::WARN:
        return "WARN";
    case Severity::CRIT:
        return "CRIT";
    default:
        return "UNKNOWN";
    }
}

int DTC::getDTCCount()
{
    return dtcCount;
}

void DTC::printDTCInfo() const
{
    std::cout << "Code: " << m_code << "\n"
              << "Description: " << m_description << "\n"
              << "Active: " << m_active << "\n"
              << "Occurence: " << m_occurrenceCount << "\n"
              << "Last Occurrence Time: " << m_lastOccurrenceTime << "\n"
              << "Severity: " << severityToString(m_severityLevel) << "\n"
              << "Confirmed: " << m_confirmed << "\n"
              << "Pending: " << m_pending << "\n"
              << "MIL: " << m_milOn << "\n"
              << "System: " << m_system << "\n"
              << "Origin: " << m_system << "\n";
}

void DTC::toggleMIL()
{
    m_milOn ? false : true;
}

void DTC::markConfirmed()
{
    m_confirmed = true;
    m_pending = false;
}

void DTC::markActive(bool active_)
{
    m_active = active_;
}

bool isSevere(const DTC &dtc)
{
    if (dtc.m_severityLevel == Severity::CRIT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void resetDTC(DTC &dtc)
{
    dtc.m_code = "";
    dtc.m_description = "";
    dtc.m_active = false;
    dtc.m_occurrenceCount = 0;
    dtc.m_lastOccurrenceTime = 0;
    dtc.m_severityLevel = Severity::INFO;
    dtc.m_confirmed = false;
    dtc.m_pending = false;
    dtc.m_milOn = false;
    dtc.m_system = "";
    dtc.m_origin = "";
}

void DTC::DTCDiagnostics::reportStatus(const DTC &dtc)
{
    std::cout << "DTC code: " << dtc.m_code << ", System name: " << dtc.m_system << ", Severity Level: " << severityToString(dtc.m_severityLevel) << ", MIL Status: " << dtc.m_milOn << std::endl;
}

bool DTC::operator==(const DTC &other)
{
    if (this->m_code == other.m_code && this->m_system == other.m_system)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DTC::operator!=(const DTC &other)
{
    if (this->m_code != other.m_code || this->m_system != other.m_system)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DTC &DTC::operator++()
{
    ++m_occurrenceCount;
    return *this;
}

DTC DTC::operator++(int)
{
    DTC temp = *this;
    ++m_occurrenceCount;
    return temp;
}

std::ostream &operator<<(std::ostream &os, const DTC &other)
{
    os << "Code: " << other.m_code << "\n"
       << "Description: " << other.m_description << "\n"
       << "Active: " << other.m_active << "\n"
       << "Occurence: " << other.m_occurrenceCount << "\n"
       << "Last Occurrence Time: " << other.m_lastOccurrenceTime << "\n"
       << "Severity: " << severityToString(other.m_severityLevel) << "\n"
       << "Confirmed: " << other.m_confirmed << "\n"
       << "Pending: " << other.m_pending << "\n"
       << "MIL: " << other.m_milOn << "\n"
       << "System: " << other.m_system << "\n"
       << "Origin: " << other.m_origin << "\n"
       << std::endl;

    return os;
}

DTC &DTC::operator=(const DTC &other)
{
    if (this == &other)
    {
        return *this;
    }
    this->m_code = other.m_code;
    this->m_description = other.m_description;
    this->m_active = other.m_active;
    this->m_occurrenceCount = other.m_occurrenceCount;
    this->m_lastOccurrenceTime = other.m_lastOccurrenceTime;
    this->m_severityLevel = other.m_severityLevel;
    this->m_confirmed = other.m_confirmed;
    this->m_pending = other.m_pending;
    this->m_milOn = other.m_milOn;
    this->m_system = other.m_system;
    this->m_origin = other.m_origin;

    return *this;
}

bool DTC::operator>(const DTC &other)
{
    int dtc1 = static_cast<int>(this->m_severityLevel);
    int dtc2 = static_cast<int>(other.m_severityLevel);
    if (dtc1 > dtc2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DTC::operator<(const DTC &other)
{
    int dtc1 = static_cast<int>(this->m_severityLevel);
    int dtc2 = static_cast<int>(other.m_severityLevel);
    if (dtc1 < dtc2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DTC::operator()()
{
    this->printDTCInfo();
}

std::string &DTC::operator[](const std::string &key)
{
    std::string key_ = key;
    std::transform(key_.begin(), key_.end(), key_.begin(), ::tolower);
    if (key_ == "code")
    {
        return m_code;
    }
    if (key_ == "system")
    {
        return m_system;
    }
    throw std::invalid_argument("Invalid key: " + key);
}

bool DTC::operator!()
{
    if (this->m_active == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void displayAllDTCs(DTC **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] != nullptr)
        {
            array[i]->printDTCInfo();
        }
    }
}
