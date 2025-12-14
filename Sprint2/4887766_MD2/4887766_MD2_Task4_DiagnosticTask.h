#ifndef DIAGNOSTIC_TASK_H
#define DIAGNOSTIC_TASK_H
#include <iostream>

enum class Severity{ INFO, WARNING, CRITICAL};

class DiagnosticTask{
    public:
    //defaulted constructor and destructor
    DiagnosticTask() = default;

    virtual ~DiagnosticTask(){}

    //pure virtual functions
    virtual bool run() const = 0;
    virtual Severity getSeverity() const = 0;
};

#endif