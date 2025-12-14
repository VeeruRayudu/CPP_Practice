#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H
#include <iostream>
#include <functional>
#include <vector>
#include <memory>

class AlertManager{
    public:
    std::vector<std::function<void(std::string, double)>> m_handlers;
    // //constructor
    // AlertManager(std::vector<std::function<void(std::string, double)>> handlers_);
    void dispatch(std::string label, double value);
};

//free function to log alert
void logAlert(std::string, double);

class Logger{
    public:
    void record(std::string, double);
};

struct AlertFunctor{
    void operator()(std::string, double);
};

#endif