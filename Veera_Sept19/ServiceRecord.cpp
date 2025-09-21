#include "ServiceRecord.h"
#include <iostream>
#include <string>
#include <stdexcept>

//default
ServiceRecord::ServiceRecord(): date_(""), mileage_(0), description_(""){}

//parameterized
ServiceRecord::ServiceRecord(const std::string &date, int mileage, const std::string &description): date_(date), mileage_(mileage), description_(description){
    if(mileage < 0){
        throw std::invalid_argument("mileage must be >= 0");
    }
}

//copy
ServiceRecord::ServiceRecord(const ServiceRecord &other): date_(other.date_), mileage_(other.mileage_), description_(other.description_){}

//assignment operator
ServiceRecord& ServiceRecord::operator = (const ServiceRecord &other){
    if(this != &other){
        date_ = other.date_;
        mileage_ = other.mileage_;
        description_ = other.description_;
    }
    return *this;
}

//getters
const std::string& ServiceRecord::getDate() const {
    return date_;
}
const int ServiceRecord::getMileage() const{
    return mileage_;
}
const std::string& ServiceRecord::getDescription() const {
    return description_;
}

//utility
void ServiceRecord::print() const {
    std::cout<<"Date: "<<date_<<", Mileage: "<<mileage_<<", Description: "<<description_<<std::endl;
}