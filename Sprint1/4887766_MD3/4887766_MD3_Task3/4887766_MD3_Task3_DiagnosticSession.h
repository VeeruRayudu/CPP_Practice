#ifndef DIAGNOSTICSESSION_H
#define DIAGNOSTICSESSION_H
#include "4887766_MD3_Task3_DTC.h"

class DiagnosticSession{
    private:
    DTC m_dtc;
    std::string m_technicianName;
    std::string m_sessionID;
    static const int MAX_COUNT = 5;
    DTC m_array[MAX_COUNT];
    int m_count=0;

    public:
    DiagnosticSession(std::string technicianName_, std::string sessionID_);

    //member functions
    void logDTC(const DTC& dtc);
    void summarizeSession() const;
};

#endif