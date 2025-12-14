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

    const int MAX_SEVERITY = static_cast<int>(Severity::CRIT);
    static int dtcCount;

    public:
    //constructors
    DTC(); //default

    DTC(std::string code_, std::string description_,bool active_, int occurrenceCount_, time_t lastOccurrenceTime_, Severity severityLevel_, bool confirmed_, bool pending_, bool milOn_, std::string system_, std::string origin_);  //parameterized

    DTC(DTC &other);   //copy

    ~DTC();

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
    void setCode(const std::string& code_);
    void setDescription(const std::string& description_);
    void setActive(bool active_);
    void setOccurrenceCount(int occurrenceCount_);
    void setLastOccurrenceTime(time_t lastOccurrenceTime_);
    void setSeverityLevel(Severity severityLevel_);
    void setSeverityLevel(int level);
    void setSeverityLevel(const std::string& name);
    void setConfirmed(bool confirmed_);
    void setPending(bool pending_);
    void setMilOn(bool milOn_);
    void setSystem(const std::string& system_);
    void setOrigin(const std::string& origin_);

    static int getDTCCount();

    //utility Methods
    void activate();
    void deactivate();
    void incrementOccurrence();
    void printDTCInfo() const;
    void toggleMIL();
    void markConfirmed();
    void markActive(bool m_active = true);

    //friend functions
    friend bool isSevere(const DTC& dtc);
    friend void resetDTC(DTC& dtc);

    class DTCDiagnostics{
        public:
        void reportStatus(const DTC& dtc);
    };
    friend class DTCDiagnostics;

    bool operator==(const DTC &other);
    bool operator!=(const DTC &other);
    DTC& operator++();
    DTC operator++(int);
    friend std::ostream& operator<<(std::ostream& os, const DTC& other);
    DTC& operator=(const DTC &other);
    bool operator>(const DTC &other);
    bool operator<(const DTC &other);
    void operator()();
    std::string& operator[](const std::string& key);
    bool operator!();

    
};

std::string severityToString(Severity s);
void displayAllDTCs(const DTC** array, int size);


#endif //DTC_H