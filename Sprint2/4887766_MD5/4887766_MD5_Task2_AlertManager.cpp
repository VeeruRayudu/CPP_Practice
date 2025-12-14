#include "4887766_MD5_Task2_AlertManager.h"

// // constructor
// AlertManager::AlertManager(std::vector<std::function<void(std::string, double)>> handlers_) : m_handlers(handlers_) {}

// dispatch handlers
void AlertManager::dispatch(std::string label, double value)
{
    for (auto &trigger : m_handlers)
    {
        trigger(label, value);
    }
}

// free function to log alert
void logAlert(std::string label, double value)
{
    std::cout << "\n[Free function] Label: " << label << " triggered at Value: " << value << std::endl;
}

// bound function
void Logger::record(std::string label, double value)
{
    std::cout << "\n[Logger member function] Label: " << label << " triggered at Value: " << value << std::endl;
}

// functor
void AlertFunctor::operator()(std::string label, double value)
{
    std::cout << "\n[Functor funtion] Label: " << label << " triggered at Value: " << value << std::endl;
}