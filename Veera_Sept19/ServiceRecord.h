#ifndef SERVICERECORD_H
#define SERVICERECORD_H

#include<string>

class ServiceRecord{
    private:
    std::string date_;
    int mileage_;
    std::string description_;

    public:
    //constructors
    ServiceRecord();
    ServiceRecord(const std::string &date, int mileage, const std::string &description);

    //copy_control
    ServiceRecord(const ServiceRecord &other);
    ServiceRecord &operator = (const ServiceRecord &other);

    //getters
    const std::string& getDate() const;
    const int getMileage() const;
    const std::string& getDescription() const;

    //utility
    void print() const;

};





#endif