#include <iostream>
#include "4887766_MD3_Task3_DiagnosticSession.h"

DiagnosticSession::DiagnosticSession(std::string technicianName_, std::string sessionID_): m_technicianName(technicianName_), m_sessionID(sessionID_) {};

void DiagnosticSession::logDTC(const DTC& dtc){
    if(m_count <= MAX_COUNT){
        m_array[m_count] = dtc;
        ++m_count;
    }
}

void DiagnosticSession::summarizeSession() const {
    std::cout<<"Technician Name: "<<m_technicianName<<", Session ID: "<<m_sessionID<<"\n";
    for(int i=0; i<m_count; i++){
        m_array[i].printDTCInfo();
        std::cout<<"\n";
    }
}