#include "4887766_MD6_Task1_EngineDTC.h"
#include <stdexcept>

class EmptyCodeException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "DTC code cannot be empty";
    }
};

class InvalidTimestampException: public std::exception{
    public:
    const char* what() const noexcept override{
        return "Timestamp must be a valid non-negative UNIX time";
    }
};

int main()
{
    EngineDTC eDtc(" ", "Cylinder 1 Misfire Detected", true, 3, -1, Severity::CRIT, true, false, true, "Engine", "ECU_01", 3800, 95.2);

    eDtc.setActive(false);
    eDtc.setConfirmed(true);

    eDtc.incrementOccurrence();
    eDtc.toggleMIL();
    eDtc.markConfirmed();

    eDtc.printDTCInfo();

    try
    {
        if (eDtc.getCode() == "" || eDtc.getCode() == " ")
        {
            throw EmptyCodeException();
        }
    }catch(const EmptyCodeException& e){
        std::cout<<e.what()<<std::endl;
    }

    try{
        if(eDtc.getLastOccurrenceTime() < 0){
            throw InvalidTimestampException();
        }
    }catch(const InvalidTimestampException& e){
        std::cout<<e.what()<<std::endl;
    }
}