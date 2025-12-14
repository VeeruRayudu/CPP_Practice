#ifndef DTC_H
#define DTC_H
#include <string>
#include <ctime>

enum class Severity {
    INFO = 0,
    WARN = 1, 
    CRIT = 2
};

class DTC{
    private:
    std::string m_code;
    std::string m_description;
    bool m_active;
    int m_occurrenceCount;
    std::time_t m_lastOccurrenceTime;
    Severity m_severityLevel;
    bool m_confirmed;
    bool m_pending;
    bool m_milOn;
    std::string m_system;
    std::string m_origin;

    public:
    //constructors
    DTC(); //default

    DTC(std::string code_, std::string description_,bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_);  //parameterized

    DTC(DTC &other);   //copy

    //getters
    std::string getCode();
    std::string getDescription();
    bool getActive();
    int getOccurrenceCount();
    time_t getLastOccurrenceTime();
    Severity getSeverityLevel();
    bool getConfirmed();
    bool getPending();
    bool getMilOn();
    std::string getSystem();
    std::string getOrigin();

    //setters
    void setCode(std::string code_);
    void setDescription(std::string description_);
    void setActive(bool active_);
    void setOccurrenceCount(int occurrenceCount_);
    void setLastOccurrenceTime(time_t lastOccurrenceTime_);
    void setSeverityLevel(Severity severityLevel_);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(std::string system_);
    void setOrigin(std::string origin_);

    //utility Methods
    void activate();
    void deactivate();
    void incrementOccurrence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();
};

void displayAllDTCs(const DTC** array, int size);

#endif //DTC_H