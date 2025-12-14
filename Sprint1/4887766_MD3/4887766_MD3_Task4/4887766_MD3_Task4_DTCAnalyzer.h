#ifndef DTCANALYZER_H
#define DTCANALYZER_H
#include "4887766_MD3_Task4_DTC.h"

class DTCAnalyzer{
    private:
    DTC* dtc;
    std::string m_analyzerID;
    std::string m_organization;
    static const int MAX_COUNT = 5;
    DTC* m_array[MAX_COUNT];
    int m_dtcCount = 0;

    public:
    DTCAnalyzer(const std::string& id_, const std::string& org_);
    
    void addDTC(DTC* dtc);
    void reviewCriticalFaults() const;
    void reportSummary() const;

};

#endif