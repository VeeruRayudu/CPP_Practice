#ifndef DTC_H
#define DTC_H

#include <string>
#include <ctime>

enum class Severity {
    INFO = 0,
    WARN = 1,
    CRIT = 2
};

class DTC {
private:
    std::string code;
    std::string description;
    bool active;
    int occurrenceCount;
    std::time_t lastOccurrenceTime;
    Severity severityLevel;
    bool confirmed;
    bool pending;
    bool milOn;
    std::string system;
    std::string origin;

public:
    // Constructors
    DTC();  // Default
    DTC(const std::string& code, const std::string& description, bool active,
        int occurrenceCount, std::time_t lastOccurrenceTime, Severity severityLevel,
        bool confirmed, bool pending, bool milOn,
        const std::string& system, const std::string& origin);  // Parameterized
    DTC(const DTC& other);  // Copy

    // Getters
    std::string getCode() const;
    std::string getDescription() const;
    bool isActive() const;
    int getOccurrenceCount() const;
    std::time_t getLastOccurrenceTime() const;
    Severity getSeverityLevel() const;
    bool isConfirmed() const;
    bool isPending() const;
    bool isMilOn() const;
    std::string getSystem() const;
    std::string getOrigin() const;

    // Setters
    void setCode(const std::string& value);
    void setDescription(const std::string& value);
    void setActive(bool value);
    void setOccurrenceCount(int value);
    void setLastOccurrenceTime(std::time_t value);
    void setSeverityLevel(Severity value);
    void setConfirmed(bool value);
    void setPending(bool value);
    void setMilOn(bool value);
    void setSystem(const std::string& value);
    void setOrigin(const std::string& value);

    // Utility Methods
    void activate();
    void deactivate();
    void incrementOccurrence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();
};

#endif // DTC_H