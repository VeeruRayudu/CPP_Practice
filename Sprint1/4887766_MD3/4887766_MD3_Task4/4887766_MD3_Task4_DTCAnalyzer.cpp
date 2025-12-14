#include <iostream>
#include "4887766_MD3_Task4_DTCAnalyzer.h"

DTCAnalyzer::DTCAnalyzer(const std::string &id_, const std::string &org_) : m_analyzerID(id_), m_organization(org_) {};

void DTCAnalyzer::addDTC(DTC *dtc)
{
    if (m_dtcCount <= MAX_COUNT)
    {
        m_array[m_dtcCount] = dtc;
        ++m_dtcCount;
    }
}

void DTCAnalyzer::reviewCriticalFaults() const
{
    for (int i = 0; i < m_dtcCount; i++)
    {
        if (m_array[i]->getSeverityLevel() == Severity::WARN)
        {
            m_array[i]->printDTCInfo();
            std::cout<<"\n";
        }
    }
}

void DTCAnalyzer::reportSummary() const
{
    int reviewed = 0;
    for (int i = 0; i < m_dtcCount; i++)
    {
        if (m_array[i]->getSeverityLevel() == Severity::WARN)
        {
            ++reviewed;
        }
        m_array[i]->printDTCInfo();
        std::cout << "\n";
    }
    std::cout << "Total DTCs reviewed: " << reviewed << std::endl;
}