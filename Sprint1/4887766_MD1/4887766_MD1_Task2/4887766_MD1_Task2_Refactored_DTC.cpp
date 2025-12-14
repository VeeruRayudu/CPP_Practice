#include <iostream>
#include <string>
#include <ctime>
#include "4887766_MD1_Task2_Refactored_DTC.h"

// Default constructor
DTC::DTC()
    : code(""), description(""), active(false), occurrenceCount(0),
      lastOccurrenceTime(0), severityLevel(Severity::INFO),
      confirmed(false), pending(false), milOn(false),
      system(""), origin("") {}

// Parameterized constructor
DTC::DTC(const std::string& code, const std::string& description, bool active,
         int occurrenceCount, time_t lastOccurrenceTime, Severity severityLevel,
         bool confirmed, bool pending, bool milOn,
         const std::string& system, const std::string& origin)
    : code(code), description(description), active(active),
      occurrenceCount(occurrenceCount), lastOccurrenceTime(lastOccurrenceTime),
      severityLevel(severityLevel), confirmed(confirmed),
      pending(pending), milOn(milOn), system(system), origin(origin) {}

// Copy constructor
DTC::DTC(const DTC& other)
    : code(other.code), description(other.description), active(other.active),
      occurrenceCount(other.occurrenceCount), lastOccurrenceTime(other.lastOccurrenceTime),
      severityLevel(other.severityLevel), confirmed(other.confirmed),
      pending(other.pending), milOn(other.milOn),
      system(other.system), origin(other.origin) {}

// Getters
std::string DTC::getCode() const { return code; }
std::string DTC::getDescription() const { return description; }
bool DTC::isActive() const { return active; }
int DTC::getOccurrenceCount() const { return occurrenceCount; }
time_t DTC::getLastOccurrenceTime() const { return lastOccurrenceTime; }
Severity DTC::getSeverityLevel() const { return severityLevel; }
bool DTC::isConfirmed() const { return confirmed; }
bool DTC::isPending() const { return pending; }
bool DTC::isMilOn() const { return milOn; }
std::string DTC::getSystem() const { return system; }
std::string DTC::getOrigin() const { return origin; }

// Setters
void DTC::setCode(const std::string& value) { code = value; }
void DTC::setDescription(const std::string& value) { description = value; }
void DTC::setActive(bool value) { active = value; }
void DTC::setOccurrenceCount(int value) { occurrenceCount = value; }
void DTC::setLastOccurrenceTime(time_t value) { lastOccurrenceTime = value; }
void DTC::setSeverityLevel(Severity value) { severityLevel = value; }
void DTC::setConfirmed(bool value) { confirmed = value; }
void DTC::setPending(bool value) { pending = value; }
void DTC::setMilOn(bool value) { milOn = value; }
void DTC::setSystem(const std::string& value) { system = value; }
void DTC::setOrigin(const std::string& value) { origin = value; }

// Utility methods
void DTC::activate() { active = true; }
void DTC::deactivate() { active = false; }
void DTC::incrementOccurrence() { ++occurrenceCount; }

void DTC::toggleMIL() {
    milOn = !milOn;
}

void DTC::markConfirmed() {
    confirmed = true;
    pending = false;
}

std::string severityToString(Severity s) {
    switch (s) {
        case Severity::INFO: return "INFO";
        case Severity::WARN: return "WARN";
        case Severity::CRIT: return "CRIT";
        default: return "UNKNOWN";
    }
}

void DTC::printDTCInfo() const {
    std::cout << "Code: " << code << "\n"
              << "Description: " << description << "\n"
              << "Active: " << std::boolalpha << active << "\n"
              << "Occurrence Count: " << occurrenceCount << "\n"
              << "Last Occurrence Time: " << lastOccurrenceTime << "\n"
              << "Severity: " << severityToString(severityLevel) << "\n"
              << "Confirmed: " << std::boolalpha << confirmed << "\n"
              << "Pending: " << std::boolalpha << pending << "\n"
              << "MIL: " << std::boolalpha << milOn << "\n"
              << "System: " << system << "\n"
              << "Origin: " << origin << "\n";
}